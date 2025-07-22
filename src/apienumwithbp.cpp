#include "headers\apienumwithbp.h"
#include <algorithm>
#include <sstream>

std::map<std::string, std::vector<std::string>> functionSignatures;
extern void WriteApiCall(const std::wstring& apiCall);

std::wstring StringToWString(const std::string& str) {
    return std::wstring(str.begin(), str.end());
}

std::string WstringToString(const std::wstring& wstr) {
    return std::string(wstr.begin(), wstr.end());
}

ApiEnumWithBp::ApiEnumWithBp() : hProcess(NULL), processId(0), breakpointsReady(false) {
    LogMessage(L"Initializing API tracer...");
    
    rootProcessId = 0;
    trackedProcesses.clear();
    processBreakpoints.clear();
    
    InitializeTracedFunctions();
    LogMessage(L"API tracer initialization complete");
    
    LogVerbose(L"API tracer constructor completed - this should appear in files");
}

ApiEnumWithBp::~ApiEnumWithBp() {
    if (hProcess) {
        LogVerbose(L"Cleaning up breakpoints and closing process handle");
        CleanupBreakpoints();
        CloseHandle(hProcess);
    }
    
    for (auto& [pid, processInfo] : trackedProcesses) {
        if (processInfo.hProcess && processInfo.hProcess != hProcess) {
            CloseHandle(processInfo.hProcess);
        }
    }
    
    LogVerbose(L"API tracer destroyed");
}

bool ApiEnumWithBp::LoadConfiguration(const std::string& configPath, Config& config) {
    std::ifstream file(configPath);
    if (!file.is_open()) {
        LogError(L"Failed to open config file: " + StringToWString(configPath));
        return false;
    }
    
    LogVerbose(L"Loading configuration from: " + StringToWString(configPath));
    
    config.fileToDllMap.clear();
    config.filesToProcess.clear();
    config.ignoredFunctions.clear();
    
    std::string line;
    std::string currentSection;
    int lineNumber = 0;
    
    while (std::getline(file, line)) {
        lineNumber++;
        
        line.erase(0, line.find_first_not_of(" \t\r\n"));
        line.erase(line.find_last_not_of(" \t\r\n") + 1);
        
        if (line.empty() || line[0] == '#' || line[0] == ';') {
            continue;
        }
        
        if (line == "[file_to_dll]") {
            currentSection = "file_to_dll";
            LogVerbose(L"Found [file_to_dll] section");
            continue;
        } else if (line == "[files_to_process]") {
            currentSection = "files_to_process";
            LogVerbose(L"Found [files_to_process] section");
            continue;
        } else if (line == "[ignored_functions]") {
            currentSection = "ignored_functions";
            LogVerbose(L"Found [ignored_functions] section");
            continue;
        }
        
        if (currentSection == "file_to_dll") {
            size_t equalPos = line.find('=');
            if (equalPos != std::string::npos) {
                std::string fileName = line.substr(0, equalPos);
                std::string dllName = line.substr(equalPos + 1);
                
                fileName.erase(0, fileName.find_first_not_of(" \t"));
                fileName.erase(fileName.find_last_not_of(" \t") + 1);
                dllName.erase(0, dllName.find_first_not_of(" \t"));
                dllName.erase(dllName.find_last_not_of(" \t") + 1);
                
                config.fileToDllMap[fileName] = dllName;
                LogVerbose(L"Mapped: " + StringToWString(fileName) + L" -> " + StringToWString(dllName));
            } else {
                LogError(L"Invalid mapping syntax at line " + std::to_wstring(lineNumber) + L": " + StringToWString(line));
            }
        } else if (currentSection == "files_to_process") {
            config.filesToProcess.push_back(line);
            LogVerbose(L"Added file to process: " + StringToWString(line));
        } else if (currentSection == "ignored_functions") {
            config.ignoredFunctions.insert(line);
            LogVerbose(L"Added ignored function: " + StringToWString(line));
        } else if (!currentSection.empty()) {
            LogError(L"Unknown content outside sections at line " + std::to_wstring(lineNumber) + L": " + StringToWString(line));
        }
    }
    
    file.close();
    
    LogMessage(L"Configuration loaded: " + std::to_wstring(config.fileToDllMap.size()) + 
               L" mappings, " + std::to_wstring(config.filesToProcess.size()) + L" files to process, " +
               std::to_wstring(config.ignoredFunctions.size()) + L" ignored functions");
    
    return true;
}

std::string ApiEnumWithBp::ExtractFunctionName(const std::string& line) {
    size_t pos = line.find('(');
    if (pos == std::string::npos) return "";
    
    std::string before = line.substr(0, pos);
    size_t space = before.rfind(' ');
    if (space == std::string::npos) return "";
    
    std::string func_name = before.substr(space + 1);
    if (func_name.length() > 1 && func_name[0] == 'Z' && func_name[1] == 'w') {
        func_name[0] = 'N';
        func_name[1] = 't';
    }
    return func_name;
}

int ApiEnumWithBp::CountFunctionParams(const std::string& functionDecl) {
    size_t start = functionDecl.find('(');
    size_t end = functionDecl.rfind(')');
    if (start == std::string::npos || end == std::string::npos) return 0;
    
    std::string params = functionDecl.substr(start + 1, end - start - 1);
    
    params.erase(0, params.find_first_not_of(" \t\n\r"));
    params.erase(params.find_last_not_of(" \t\n\r") + 1);
    
    if (params.empty() || params == "void") return 0;
    
    std::vector<std::string> paramList;
    std::string current;
    int bracketDepth = 0;
    
    for (char c : params) {
        if (c == '[') {
            bracketDepth++;
        } else if (c == ']') {
            bracketDepth--;
        } else if (c == ',' && bracketDepth == 0) {
            if (!current.empty()) {
                paramList.push_back(current);
                current.clear();
            }
            continue;
        }
        current += c;
    }
    if (!current.empty()) {
        paramList.push_back(current);
    }
    
    int validParams = 0;
    for (const std::string& param : paramList) {
        std::string cleanParam = param;
        
        size_t bracketStart = 0;
        while ((bracketStart = cleanParam.find('[', bracketStart)) != std::string::npos) {
            size_t bracketEnd = cleanParam.find(']', bracketStart);
            if (bracketEnd != std::string::npos) {
                cleanParam.erase(bracketStart, bracketEnd - bracketStart + 1);
            } else {
                break;
            }
        }
        
        std::regex annotationRegex(R"((__\w+_?|_\w+_))");
        cleanParam = std::regex_replace(cleanParam, annotationRegex, "");
        
        cleanParam.erase(0, cleanParam.find_first_not_of(" \t\n\r"));
        cleanParam.erase(cleanParam.find_last_not_of(" \t\n\r") + 1);
        
        if (!cleanParam.empty() && cleanParam != "void") {
            validParams++;
        }
    }
    
    return validParams;
}

void ApiEnumWithBp::InitializeTracedFunctions() {
    LogMessage(L"Initializing traced functions...");
    tracedFunctions.clear();
    
    Config config;
    std::string configPath = WstringToString(g_config.dll_headers_dir) + "\\argus.config";
    
    if (!LoadConfiguration(configPath, config)) {
        LogError(L"Failed to load configuration from: " + StringToWString(configPath));
        LogError(L"Cannot continue without valid configuration file");
        return;
    }
    
    ignoredFunctions = config.ignoredFunctions;
    LogMessage(L"Loaded " + std::to_wstring(ignoredFunctions.size()) + L" ignored functions from configuration");
    
    requiredDlls.clear();
    
    for (const std::string& fileName : config.filesToProcess) {
        auto it = config.fileToDllMap.find(fileName);
        if (it != config.fileToDllMap.end()) {
            requiredDlls.insert(it->second);
        } else {
            LogError(L"No DLL mapping found for " + StringToWString(fileName));
        }
    }
    
    if (requiredDlls.empty()) {
        LogError(L"No required DLLs found in configuration");
        return;
    }
    
    std::wstring dllList;
    for (const auto& dll : requiredDlls) {
        if (!dllList.empty()) dllList += L", ";
        dllList += StringToWString(dll);
    }
    LogMessage(L"Required DLLs: " + dllList);
    
    for (const std::string& fileName : config.filesToProcess) {
        std::string filePath = WstringToString(g_config.dll_headers_dir) + "\\" + fileName;
        std::ifstream file(filePath);
        
        if (!file.is_open()) {
            LogError(L"Could not open " + StringToWString(fileName) + L" at " + StringToWString(filePath));
            continue;
        }
        
        LogVerbose(L"Processing file: " + StringToWString(fileName));
        
        std::string dllName = "unknown";
        auto it = config.fileToDllMap.find(fileName);
        if (it != config.fileToDllMap.end()) {
            dllName = it->second;
        }
        
        std::string line;
        int functionsFound = 0;
        
        while (std::getline(file, line)) {
            if (line.empty() || line[0] == '/' || line[0] == '*') continue;
            
            if (line.find('(') != std::string::npos) {
                std::string fullFunction = line;
                
                if (line.find(");") == std::string::npos) {
                    std::string nextLine;
                    while (std::getline(file, nextLine) && nextLine.find(");") == std::string::npos) {
                        fullFunction += " " + nextLine;
                    }
                    if (!nextLine.empty()) {
                        fullFunction += " " + nextLine;
                    }
                }
                
                std::string funcName = ExtractFunctionName(fullFunction);
                if (!funcName.empty() && !IsFunctionIgnored(funcName)) {
                    DWORD paramCount = CountFunctionParams(fullFunction);
                    tracedFunctions.push_back({funcName, dllName, paramCount});
                    functionsFound++;
                }
            }
        }
        file.close();
        
        LogMessage(L"Loaded " + std::to_wstring(functionsFound) + L" functions from " + 
                   StringToWString(fileName) + L" (" + StringToWString(dllName) + L")");
    }
    
    LogMessage(L"Total functions loaded: " + std::to_wstring(tracedFunctions.size()));
}

bool ApiEnumWithBp::IsFunctionIgnored(const std::string& functionName) {
    return ignoredFunctions.find(functionName) != ignoredFunctions.end();
}

void ApiEnumWithBp::AddIgnoredFunction(const std::string& functionName) {
    ignoredFunctions.insert(functionName);
    LogVerbose(L"Added function to ignore list: " + StringToWString(functionName));
}

void ApiEnumWithBp::PrintIgnoredFunctions() const {
    LogMessage(L"Ignored functions (" + std::to_wstring(ignoredFunctions.size()) + L"):");
    for (const auto& func : ignoredFunctions) {
        LogMessage(L"  - " + StringToWString(func));
    }
}

bool ApiEnumWithBp::CreateAndAttachProcess(const std::wstring& executablePath, const std::wstring& executableCmd) {
    LogMessage(L"Creating and attaching to process: " + executablePath);
    
    STARTUPINFOW si = { sizeof(si) };
    PROCESS_INFORMATION pi = { 0 };
    
    DWORD creationFlags = 0;
    if (g_config.trace_level == -1) {
        creationFlags = DEBUG_ONLY_THIS_PROCESS;
        LogMessage(L"Child process tracing disabled (trace_level = -1)");
    } else {
        creationFlags = DEBUG_PROCESS;
        if (g_config.trace_level == 0) {
            LogMessage(L"Unlimited child process tracing enabled (trace_level = 0)");
        } else {
            LogMessage(L"Limited child process tracing enabled (trace_level = " + std::to_wstring(g_config.trace_level) + L")");
        }
    }
    
    if (!CreateProcessW(
        executablePath.c_str(),
        const_cast<LPWSTR>(executableCmd.c_str()),
        NULL,
        NULL,
        FALSE,
        creationFlags,
        NULL,
        NULL,
        &si,
        &pi)) {
        LogError(L"Failed to create process. Error: " + std::to_wstring(GetLastError()));
        return false;
    }

    LogVerbose(L"Sleeping for " + std::to_wstring(g_config.sleep_time) + L"ms");
    Sleep(g_config.sleep_time);
    
    hProcess = pi.hProcess;
    processId = pi.dwProcessId;
    rootProcessId = pi.dwProcessId;
    g_current_pid = pi.dwProcessId;
    CloseHandle(pi.hThread);
    
    ProcessInfo rootInfo;
    rootInfo.hProcess = hProcess;
    rootInfo.parentProcessId = 0;
    rootInfo.depth = 0;
    rootInfo.breakpointsReady = false;
    trackedProcesses[processId] = rootInfo;
    
    LogMessage(L"Successfully created and attached to root process " + std::to_wstring(processId));
    return true;
}

bool ApiEnumWithBp::AttachToProcess(DWORD pid) {
    LogMessage(L"Attaching to existing process " + std::to_wstring(pid));
    processId = pid;
    rootProcessId = pid;
    g_current_pid = pid;
    
    if (!DebugActiveProcess(pid)) {
        LogError(L"Failed to attach to process " + std::to_wstring(pid) + 
                L". Error: " + std::to_wstring(GetLastError()));
        return false;
    }
    
    hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
    if (!hProcess) {
        LogError(L"Failed to open process handle. Error: " + std::to_wstring(GetLastError()));
        DebugActiveProcessStop(pid);
        return false;
    }
    
    ProcessInfo rootInfo;
    rootInfo.hProcess = hProcess;
    rootInfo.parentProcessId = 0;
    rootInfo.depth = 0;
    rootInfo.breakpointsReady = false;
    trackedProcesses[processId] = rootInfo;
    
    LogMessage(L"Successfully attached to root process " + std::to_wstring(pid));
    
    SuspendProcessThreads();
    
    LogMessage(L"Discovering loaded modules...");
    
    if (!FindAndSetupModules()) {
        LogError(L"Failed to find required modules in target process");
        ResumeProcessThreads();
        CloseHandle(hProcess);
        hProcess = NULL;
        DebugActiveProcessStop(pid);
        return false;
    }
    
    if (!SetupBreakpoints()) {
        LogError(L"Failed to set up breakpoints");
        ResumeProcessThreads();
        CloseHandle(hProcess);
        hProcess = NULL;
        DebugActiveProcessStop(pid);
        return false;
    }
    
    LogVerbose(L"Sleeping for " + std::to_wstring(g_config.sleep_time) + L"ms");
    Sleep(g_config.sleep_time);

    ResumeProcessThreads();
    
    LogMessage(L"Breakpoints successfully set up for attached process");
    return true;
}

void ApiEnumWithBp::SuspendProcessThreads() {
    LogVerbose(L"Suspending process threads...");
    
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);
    if (hSnapshot == INVALID_HANDLE_VALUE) {
        LogError(L"Failed to create thread snapshot. Error: " + std::to_wstring(GetLastError()));
        return;
    }
    
    THREADENTRY32 te32;
    te32.dwSize = sizeof(THREADENTRY32);
    
    if (Thread32First(hSnapshot, &te32)) {
        do {
            if (te32.th32OwnerProcessID == processId) {
                HANDLE hThread = OpenThread(THREAD_SUSPEND_RESUME, FALSE, te32.th32ThreadID);
                if (hThread) {
                    DWORD suspendCount = SuspendThread(hThread);
                    if (suspendCount != (DWORD)-1) {
                        suspendedThreads.push_back(te32.th32ThreadID);
                    } else {
                        LogError(L"Failed to suspend thread " + std::to_wstring(te32.th32ThreadID) + 
                                L". Error: " + std::to_wstring(GetLastError()));
                    }
                    CloseHandle(hThread);
                }
            }
        } while (Thread32Next(hSnapshot, &te32));
    }
    
    CloseHandle(hSnapshot);
    LogMessage(L"Suspended " + std::to_wstring(suspendedThreads.size()) + L" threads");
}

void ApiEnumWithBp::ResumeProcessThreads() {
    LogVerbose(L"Resuming process threads...");
    
    int errorCount = 0;
    for (DWORD threadId : suspendedThreads) {
        HANDLE hThread = OpenThread(THREAD_SUSPEND_RESUME, FALSE, threadId);
        if (hThread) {
            DWORD suspendCount = ResumeThread(hThread);
            if (suspendCount == (DWORD)-1) {
                LogError(L"Failed to resume thread " + std::to_wstring(threadId) + 
                        L". Error: " + std::to_wstring(GetLastError()));
                errorCount++;
            }
            CloseHandle(hThread);
        }
    }
    
    suspendedThreads.clear();
    if (errorCount > 0) {
        LogError(L"Failed to resume " + std::to_wstring(errorCount) + L" threads");
    } else {
        LogMessage(L"All threads resumed successfully");
    }
}

bool ApiEnumWithBp::FindAndSetupModules() {
    HMODULE modules[1024];
    DWORD cbNeeded;
    
    if (!EnumProcessModules(hProcess, modules, sizeof(modules), &cbNeeded)) {
        LogError(L"Failed to enumerate process modules. Error: " + std::to_wstring(GetLastError()));
        return false;
    }
    
    LogVerbose(L"Enumerating " + std::to_wstring(cbNeeded / sizeof(HMODULE)) + L" loaded modules");
    
    moduleHandles.clear();
    
    for (const auto& dllName : requiredDlls) {
        moduleHandles[dllName] = NULL;
    }
    
    for (DWORD i = 0; i < (cbNeeded / sizeof(HMODULE)); i++) {
        wchar_t moduleName[MAX_PATH];
        if (GetModuleBaseNameW(hProcess, modules[i], moduleName, MAX_PATH)) {
            std::wstring moduleNameW(moduleName);
            std::string moduleNameA = WstringToString(moduleNameW);
            
            std::transform(moduleNameA.begin(), moduleNameA.end(), moduleNameA.begin(), ::tolower);
            
            for (const auto& dllName : requiredDlls) {
                std::string dllWithExt = dllName + ".dll";
                if (moduleNameA == dllWithExt) {
                    moduleHandles[dllName] = modules[i];
                    LogVerbose(L"Found " + StringToWString(dllName) + L" at: 0x" + 
                              std::to_wstring(reinterpret_cast<uintptr_t>(modules[i])));
                    break;
                }
            }
        }
    }
    
    bool allFound = true;
    for (const auto& pair : moduleHandles) {
        if (pair.second == NULL) {
            LogError(L"Missing required module: " + StringToWString(pair.first));
            allFound = false;
        }
    }
    
    if (allFound) {
        LogMessage(L"All required modules found successfully");
    }
    
    return allFound;
}

bool ApiEnumWithBp::WaitForModulesAndSetupBreakpoints() {
    LogMessage(L"Waiting for modules to load...");
    
    for (int attempt = 0; attempt < 20; attempt++) {
        Sleep(200);
        
        if (FindAndSetupModules()) {
            LogMessage(L"Found required modules on attempt " + std::to_wstring(attempt + 1));
            return SetupBreakpoints();
        }
        
        if (attempt % 5 == 0) {
            LogVerbose(L"Still waiting for modules... (attempt " + std::to_wstring(attempt + 1) + L")");
        }
    }
    
    LogError(L"Failed to find required modules after 20 attempts");
    return false;
}

bool ApiEnumWithBp::SetupBreakpoints() {
    if (breakpointsReady) return true;
    
    LogMessage(L"Setting up breakpoints for " + std::to_wstring(tracedFunctions.size()) + L" functions...");
    
    int successCount = 0;
    int failCount = 0;
    
    std::set<std::string> modulesBeingProcessed;
    
    for (const auto& func : tracedFunctions) {
        modulesBeingProcessed.insert(func.module);
        
        if (SetBreakpointOnFunction(func)) {
            successCount++;
        } else {
            failCount++;
            LogVerbose(L"Failed to set breakpoint for " + StringToWString(func.name));
        }
    }
    
    for (const auto& moduleName : modulesBeingProcessed) {
        if (moduleHandles.find(moduleName) != moduleHandles.end() && 
            moduleHandles[moduleName] != NULL) {
            processedModules.insert(moduleName);
            LogVerbose(L"Marked module " + StringToWString(moduleName) + L" as initially processed");
        }
    }
    
    LogMessage(L"Breakpoint setup complete: " + std::to_wstring(successCount) + 
               L" successful, " + std::to_wstring(failCount) + L" failed");
    
    if (failCount > 0) {
        LogError(L"Failed to set " + std::to_wstring(failCount) + L" breakpoints");
    }
    
    breakpointsReady = (successCount > 0);
    return breakpointsReady;
}

bool ApiEnumWithBp::SetBreakpointOnFunction(const ApiFunction& func) {
    auto moduleIt = moduleHandles.find(func.module);
    if (moduleIt == moduleHandles.end() || moduleIt->second == NULL) {
        LogVerbose(L"Module " + StringToWString(func.module) + L" not found for function " + 
                   StringToWString(func.name));
        return false;
    }
    
    HMODULE targetModule = moduleIt->second;
    
    std::wstring dllNameW = StringToWString(func.module + ".dll");
    HMODULE localModule = GetModuleHandleW(dllNameW.c_str());
    if (!localModule) {
        localModule = LoadLibraryW(dllNameW.c_str());
        if (!localModule) {
            LogVerbose(L"Failed to load local module " + dllNameW + L" for function " + 
                       StringToWString(func.name) + L". Error: " + std::to_wstring(GetLastError()));
            return false;
        }
        LogVerbose(L"Loaded local module " + dllNameW + L" for address calculation");
    }
    
    FARPROC localAddr = GetProcAddress(localModule, func.name.c_str());
    if (!localAddr) {
        LogVerbose(L"Function " + StringToWString(func.name) + L" not found in local " + dllNameW);
        return false;
    }
    
    uintptr_t offset = reinterpret_cast<uintptr_t>(localAddr) - 
                      reinterpret_cast<uintptr_t>(localModule);
    PVOID targetAddr = reinterpret_cast<PVOID>(
        reinterpret_cast<uintptr_t>(targetModule) + offset);
    
    if (breakpoints.find(targetAddr) != breakpoints.end()) {
        LogVerbose(L"Breakpoint already exists for " + StringToWString(func.name));
        return true;
    }
    
    BYTE originalByte;
    SIZE_T bytesRead;
    if (!ReadProcessMemory(hProcess, targetAddr, &originalByte, 1, &bytesRead) || bytesRead != 1) {
        LogVerbose(L"Failed to read memory for function " + StringToWString(func.name) + 
                   L" at address 0x" + std::to_wstring(reinterpret_cast<uintptr_t>(targetAddr)));
        return false;
    }
    
    if (originalByte == 0xCC) {
        LogVerbose(L"Breakpoint already exists at address for function " + StringToWString(func.name));
        return false;
    }
    
    BYTE breakpointByte = 0xCC;
    SIZE_T bytesWritten;
    if (!WriteProcessMemory(hProcess, targetAddr, &breakpointByte, 1, &bytesWritten) || bytesWritten != 1) {
        LogVerbose(L"Failed to write breakpoint for function " + StringToWString(func.name) + 
                   L" at address 0x" + std::to_wstring(reinterpret_cast<uintptr_t>(targetAddr)) + 
                   L". Error: " + std::to_wstring(GetLastError()));
        return false;
    }
    
    Breakpoint bp;
    bp.address = targetAddr;
    bp.originalByte = originalByte;
    bp.functionName = func.name;
    bp.isActive = true;
    bp.isSet = true;
    
    breakpoints[targetAddr] = bp;
    
    LogVerbose(L"Set breakpoint for " + StringToWString(func.name) + 
               L" (" + StringToWString(func.module) + L") at address 0x" + 
               std::to_wstring(reinterpret_cast<uintptr_t>(targetAddr)));
    
    return true;
}

void ApiEnumWithBp::CheckForNewModulesAndSetBreakpoints() {
    LogVerbose(L"Checking for newly loaded modules in main process...");
    
    HMODULE modules[1024];
    DWORD cbNeeded;
    
    if (!EnumProcessModules(hProcess, modules, sizeof(modules), &cbNeeded)) {
        return;
    }
    
    std::map<std::string, HMODULE> currentModules;
    
    for (DWORD i = 0; i < (cbNeeded / sizeof(HMODULE)); i++) {
        wchar_t moduleName[MAX_PATH];
        if (GetModuleBaseNameW(hProcess, modules[i], moduleName, MAX_PATH)) {
            std::string moduleNameA = WstringToString(moduleName);
            std::transform(moduleNameA.begin(), moduleNameA.end(), moduleNameA.begin(), ::tolower);
            
            for (const auto& dllName : requiredDlls) {
                std::string dllWithExt = dllName + ".dll";
                if (moduleNameA == dllWithExt) {
                    currentModules[dllName] = modules[i];
                    break;
                }
            }
        }
    }
    
    int newBreakpoints = 0;
    for (const auto& [dllName, moduleHandle] : currentModules) {
        if (processedModules.find(dllName) != processedModules.end()) {
            continue;
        }
        
        bool isNewModule = (moduleHandles.find(dllName) == moduleHandles.end() || 
                           moduleHandles[dllName] == NULL);
        
        if (isNewModule) {
            LogMessage(L"Found newly loaded required module: " + StringToWString(dllName));
            moduleHandles[dllName] = moduleHandle;
            
            for (const auto& func : tracedFunctions) {
                if (func.module == dllName) {
                    if (SetBreakpointOnFunction(func)) {
                        newBreakpoints++;
                    }
                }
            }
            
            processedModules.insert(dllName);
            LogVerbose(L"Marked module " + StringToWString(dllName) + L" as processed");
        }
    }
    
    if (newBreakpoints > 0) {
        LogMessage(L"Set " + std::to_wstring(newBreakpoints) + L" new breakpoints for newly loaded modules");
    }
}

std::wstring ApiEnumWithBp::GetProcessHierarchyString(DWORD pid) {
    if (pid == rootProcessId) {
        return L"[ROOT:" + std::to_wstring(pid) + L"]";
    }
    
    auto it = trackedProcesses.find(pid);
    if (it != trackedProcesses.end()) {
        std::vector<DWORD> chain;
        DWORD currentPid = pid;
        
        while (currentPid != 0 && currentPid != rootProcessId) {
            auto currentIt = trackedProcesses.find(currentPid);
            if (currentIt != trackedProcesses.end()) {
                chain.push_back(currentPid);
                currentPid = currentIt->second.parentProcessId;
            } else {
                break;
            }
        }
        
        std::wstring hierarchy = L"[ROOT:" + std::to_wstring(rootProcessId) + L"]";
        
        for (int i = static_cast<int>(chain.size()) - 1; i >= 0; i--) {
            hierarchy += L"->[CHILD:" + std::to_wstring(chain[i]) + L"]";
        }
        
        return hierarchy;
    }
    
    return L"[UNKNOWN:" + std::to_wstring(pid) + L"]";
}

void ApiEnumWithBp::SetupChildProcess(DWORD childPid, DWORD parentPid) {
    if (g_config.trace_level == -1) {
        LogMessage(L"Ignoring child process " + std::to_wstring(childPid) + L" (child tracing disabled)");
        return;
    }
    
    int depth = 1;
    auto parentIt = trackedProcesses.find(parentPid);
    if (parentIt != trackedProcesses.end()) {
        depth = parentIt->second.depth + 1;
    }
    
    if (g_config.trace_level > 0 && depth > g_config.trace_level) {
        LogMessage(L"Ignoring child process " + std::to_wstring(childPid) + 
                  L" at depth " + std::to_wstring(depth) + 
                  L" (exceeds trace_level limit of " + std::to_wstring(g_config.trace_level) + L")");
        return;
    }
    
    LogMessage(L"Setting up child process " + std::to_wstring(childPid) + 
              L" (parent: " + std::to_wstring(parentPid) + 
              L", depth: " + std::to_wstring(depth) + L")");
    
    HANDLE hChildProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, childPid);
    if (!hChildProcess) {
        LogError(L"Failed to open child process handle. Error: " + std::to_wstring(GetLastError()));
        return;
    }
    
    ProcessInfo childInfo;
    childInfo.hProcess = hChildProcess;
    childInfo.parentProcessId = parentPid;
    childInfo.depth = depth;
    childInfo.breakpointsReady = false;
    
    trackedProcesses[childPid] = childInfo;
    
    LogMessage(L"Child process " + std::to_wstring(childPid) + L" added at depth " + std::to_wstring(depth));
}

bool ApiEnumWithBp::SetupModulesForProcess(DWORD pid) {
    auto processIt = trackedProcesses.find(pid);
    if (processIt == trackedProcesses.end()) {
        return false;
    }
    
    HANDLE hTargetProcess = processIt->second.hProcess;
    
    HMODULE modules[1024];
    DWORD cbNeeded;
    
    if (!EnumProcessModules(hTargetProcess, modules, sizeof(modules), &cbNeeded)) {
        return false;
    }
    
    LogVerbose(L"Enumerating modules for child process " + std::to_wstring(pid));
    
    processIt->second.moduleHandles.clear();
    
    for (const auto& dllName : requiredDlls) {
        processIt->second.moduleHandles[dllName] = NULL;
    }
    
    for (DWORD i = 0; i < (cbNeeded / sizeof(HMODULE)); i++) {
        wchar_t moduleName[MAX_PATH];
        if (GetModuleBaseNameW(hTargetProcess, modules[i], moduleName, MAX_PATH)) {
            std::wstring moduleNameW(moduleName);
            std::string moduleNameA = WstringToString(moduleNameW);
            
            std::transform(moduleNameA.begin(), moduleNameA.end(), moduleNameA.begin(), ::tolower);
            
            for (const auto& dllName : requiredDlls) {
                std::string dllWithExt = dllName + ".dll";
                if (moduleNameA == dllWithExt) {
                    processIt->second.moduleHandles[dllName] = modules[i];
                    LogVerbose(L"Found " + StringToWString(dllName) + L" in child process " + std::to_wstring(pid));
                    break;
                }
            }
        }
    }
    
    bool allFound = true;
    for (const auto& pair : processIt->second.moduleHandles) {
        if (pair.second == NULL) {
            allFound = false;
            break;
        }
    }
    
    return allFound;
}

bool ApiEnumWithBp::SetupBreakpointsForProcess(DWORD pid) {
    auto processIt = trackedProcesses.find(pid);
    if (processIt == trackedProcesses.end() || processIt->second.breakpointsReady) {
        return processIt != trackedProcesses.end() && processIt->second.breakpointsReady;
    }
    
    LogMessage(L"Setting up breakpoints for child process " + std::to_wstring(pid));
    
    int successCount = 0;
    int failCount = 0;
    
    if (processedModulesPerProcess.find(pid) == processedModulesPerProcess.end()) {
        processedModulesPerProcess[pid] = std::set<std::string>();
    }
    
    std::set<std::string> modulesBeingProcessed;
    
    for (const auto& func : tracedFunctions) {
        modulesBeingProcessed.insert(func.module);
        
        if (SetBreakpointOnFunctionForProcess(func, pid)) {
            successCount++;
        } else {
            failCount++;
        }
    }
    
    for (const auto& moduleName : modulesBeingProcessed) {
        if (processIt->second.moduleHandles.find(moduleName) != processIt->second.moduleHandles.end() && 
            processIt->second.moduleHandles[moduleName] != NULL) {
            processedModulesPerProcess[pid].insert(moduleName);
            LogVerbose(L"Marked module " + StringToWString(moduleName) + 
                      L" as initially processed for process " + std::to_wstring(pid));
        }
    }
    
    LogMessage(L"Breakpoint setup complete for process " + std::to_wstring(pid) + L": " + 
               std::to_wstring(successCount) + L" successful, " + std::to_wstring(failCount) + L" failed");
    
    processIt->second.breakpointsReady = (successCount > 0);
    return processIt->second.breakpointsReady;
}

bool ApiEnumWithBp::SetBreakpointOnFunctionForProcess(const ApiFunction& func, DWORD pid) {
    auto processIt = trackedProcesses.find(pid);
    if (processIt == trackedProcesses.end()) {
        return false;
    }
    
    auto moduleIt = processIt->second.moduleHandles.find(func.module);
    if (moduleIt == processIt->second.moduleHandles.end() || moduleIt->second == NULL) {
        return false;
    }
    
    HMODULE targetModule = moduleIt->second;
    
    std::wstring dllNameW = StringToWString(func.module + ".dll");
    HMODULE localModule = GetModuleHandleW(dllNameW.c_str());
    if (!localModule) {
        return false;
    }
    
    FARPROC localAddr = GetProcAddress(localModule, func.name.c_str());
    if (!localAddr) {
        return false;
    }
    
    uintptr_t offset = reinterpret_cast<uintptr_t>(localAddr) - 
                      reinterpret_cast<uintptr_t>(localModule);
    PVOID targetAddr = reinterpret_cast<PVOID>(
        reinterpret_cast<uintptr_t>(targetModule) + offset);
    
    BreakpointKey bpKey = {pid, targetAddr};
    
    if (processBreakpoints.find(bpKey) != processBreakpoints.end()) {
        return true;
    }
    
    BYTE originalByte;
    SIZE_T bytesRead;
    if (!ReadProcessMemory(processIt->second.hProcess, targetAddr, &originalByte, 1, &bytesRead) || bytesRead != 1) {
        return false;
    }
    
    if (originalByte == 0xCC) {
        return false;
    }
    
    BYTE breakpointByte = 0xCC;
    SIZE_T bytesWritten;
    if (!WriteProcessMemory(processIt->second.hProcess, targetAddr, &breakpointByte, 1, &bytesWritten) || bytesWritten != 1) {
        return false;
    }
    
    Breakpoint bp;
    bp.address = targetAddr;
    bp.originalByte = originalByte;
    bp.functionName = func.name;
    bp.isActive = true;
    bp.isSet = true;
    bp.processId = pid;
    
    processBreakpoints[bpKey] = bp;
    
    return true;
}

void ApiEnumWithBp::CheckForNewModulesAndSetBreakpointsForProcess(DWORD pid) {
    auto processIt = trackedProcesses.find(pid);
    if (processIt == trackedProcesses.end()) return;
    
    LogVerbose(L"Checking for newly loaded modules in child process " + std::to_wstring(pid));
    
    HANDLE hTargetProcess = processIt->second.hProcess;
    
    HMODULE modules[1024];
    DWORD cbNeeded;
    
    if (!EnumProcessModules(hTargetProcess, modules, sizeof(modules), &cbNeeded)) {
        return;
    }
    
    std::map<std::string, HMODULE> currentModules;
    
    for (DWORD i = 0; i < (cbNeeded / sizeof(HMODULE)); i++) {
        wchar_t moduleName[MAX_PATH];
        if (GetModuleBaseNameW(hTargetProcess, modules[i], moduleName, MAX_PATH)) {
            std::string moduleNameA = WstringToString(moduleName);
            std::transform(moduleNameA.begin(), moduleNameA.end(), moduleNameA.begin(), ::tolower);
            
            for (const auto& dllName : requiredDlls) {
                std::string dllWithExt = dllName + ".dll";
                if (moduleNameA == dllWithExt) {
                    currentModules[dllName] = modules[i];
                    break;
                }
            }
        }
    }
    
    if (processedModulesPerProcess.find(pid) == processedModulesPerProcess.end()) {
        processedModulesPerProcess[pid] = std::set<std::string>();
    }
    
    int newBreakpoints = 0;
    for (const auto& [dllName, moduleHandle] : currentModules) {
        if (processedModulesPerProcess[pid].find(dllName) != processedModulesPerProcess[pid].end()) {
            continue;
        }
        
        bool isNewModule = (processIt->second.moduleHandles.find(dllName) == processIt->second.moduleHandles.end() || 
                           processIt->second.moduleHandles[dllName] == NULL);
        
        if (isNewModule) {
            LogMessage(L"Found newly loaded required module " + StringToWString(dllName) + 
                      L" in child process " + std::to_wstring(pid));
            processIt->second.moduleHandles[dllName] = moduleHandle;
            
            for (const auto& func : tracedFunctions) {
                if (func.module == dllName) {
                    if (SetBreakpointOnFunctionForProcess(func, pid)) {
                        newBreakpoints++;
                    }
                }
            }
            
            processedModulesPerProcess[pid].insert(dllName);
            LogVerbose(L"Marked module " + StringToWString(dllName) + 
                      L" as processed for process " + std::to_wstring(pid));
        }
    }
    
    if (newBreakpoints > 0) {
        LogMessage(L"Set " + std::to_wstring(newBreakpoints) + 
                  L" new breakpoints for newly loaded modules in process " + std::to_wstring(pid));
    }
}

void ApiEnumWithBp::HandleBreakpoint(const DEBUG_EVENT& debugEvent) {
    PVOID exceptionAddr = debugEvent.u.Exception.ExceptionRecord.ExceptionAddress;
    DWORD pid = debugEvent.dwProcessId;
    
    if (pid != processId) {
        BreakpointKey bpKey = {pid, exceptionAddr};
        auto it = processBreakpoints.find(bpKey);
        if (it != processBreakpoints.end()) {
            if (IsFunctionIgnored(it->second.functionName)) {
                RestoreOriginalByteForProcess(exceptionAddr, pid);
                return;
            }
            
            HANDLE hThread = OpenThread(THREAD_GET_CONTEXT | THREAD_SET_CONTEXT, FALSE, 
                                       debugEvent.dwThreadId);
            if (hThread) {
                CONTEXT context;
                context.ContextFlags = CONTEXT_FULL;
                if (GetThreadContext(hThread, &context)) {
                    LogApiCallForProcess(it->second.functionName, &context, debugEvent.dwThreadId, pid);
                    
                    RestoreOriginalByteForProcess(exceptionAddr, pid);
                    
#ifdef _WIN64
                    context.Rip = reinterpret_cast<DWORD64>(exceptionAddr);
#else
                    context.Eip = reinterpret_cast<DWORD>(exceptionAddr);
#endif
                    context.EFlags |= 0x100;
                    SetThreadContext(hThread, &context);
                }
                CloseHandle(hThread);
            }
        }
        return;
    }
    
    auto it = breakpoints.find(exceptionAddr);
    if (it == breakpoints.end()) {
        return;
    }
    
    if (IsFunctionIgnored(it->second.functionName)) {
        RestoreOriginalByte(exceptionAddr);
        
        HANDLE hThread = OpenThread(THREAD_GET_CONTEXT | THREAD_SET_CONTEXT, FALSE, 
                                   debugEvent.dwThreadId);
        if (hThread) {
            CONTEXT context;
            context.ContextFlags = CONTEXT_FULL;
            if (GetThreadContext(hThread, &context)) {
#ifdef _WIN64
                context.Rip = reinterpret_cast<DWORD64>(exceptionAddr);
#else
                context.Eip = reinterpret_cast<DWORD>(exceptionAddr);
#endif
                context.EFlags |= 0x100;
                SetThreadContext(hThread, &context);
            }
            CloseHandle(hThread);
        }
        return;
    }
    
    HANDLE hThread = OpenThread(THREAD_GET_CONTEXT | THREAD_SET_CONTEXT, FALSE, 
                               debugEvent.dwThreadId);
    if (!hThread) return;
    
    CONTEXT context;
    context.ContextFlags = CONTEXT_FULL;
    if (!GetThreadContext(hThread, &context)) {
        CloseHandle(hThread);
        return;
    }
    
    LogApiCall(it->second.functionName, &context, debugEvent.dwThreadId);
    
    RestoreOriginalByte(exceptionAddr);
    
#ifdef _WIN64
    context.Rip = reinterpret_cast<DWORD64>(exceptionAddr);
#else
    context.Eip = reinterpret_cast<DWORD>(exceptionAddr);
#endif
    context.EFlags |= 0x100;
    
    SetThreadContext(hThread, &context);
    CloseHandle(hThread);
}

void ApiEnumWithBp::HandleSingleStep(const DEBUG_EVENT& debugEvent) {
    HANDLE hThread = OpenThread(THREAD_GET_CONTEXT, FALSE, debugEvent.dwThreadId);
    if (!hThread) return;
    
    CONTEXT context;
    context.ContextFlags = CONTEXT_FULL;
    if (GetThreadContext(hThread, &context)) {
#ifdef _WIN64
        PVOID prevAddr = reinterpret_cast<PVOID>(context.Rip - 1);
#else
        PVOID prevAddr = reinterpret_cast<PVOID>(context.Eip - 1);
#endif
        
        DWORD pid = debugEvent.dwProcessId;
        
        if (pid == processId && breakpoints.find(prevAddr) != breakpoints.end()) {
            RestoreBreakpoint(prevAddr);
        }
        else {
            BreakpointKey bpKey = {pid, prevAddr};
            if (processBreakpoints.find(bpKey) != processBreakpoints.end()) {
                RestoreBreakpointForProcess(prevAddr, pid);
            }
        }
    }
    
    CloseHandle(hThread);
}

void ApiEnumWithBp::LogApiCall(const std::string& functionName, PCONTEXT context, DWORD threadId) {
    LogApiCallForProcess(functionName, context, threadId, processId);
}

void ApiEnumWithBp::LogApiCallForProcess(const std::string& functionName, PCONTEXT context, DWORD threadId, DWORD pid) {
    g_api_call_count++;
    
    auto sigIt = functionSignatures.find(functionName);
    bool hasSignature = (sigIt != functionSignatures.end());
    
    if (!hasSignature && functionName.substr(0, 2) == "Nt") {
        std::string zwFunctionName = "Zw" + functionName.substr(2);
        auto zwSigIt = functionSignatures.find(zwFunctionName);
        if (zwSigIt != functionSignatures.end()) {
            sigIt = zwSigIt;
            hasSignature = true;
        }
    }
    
    int paramCount = 4;
    for (const auto& func : tracedFunctions) {
        if (func.name == functionName) {
            paramCount = func.paramCount;
            break;
        }
    }
    
    LogGenericParamsWithNamesForProcess(context, paramCount, hasSignature ? sigIt->second : std::vector<std::string>(), functionName, threadId, pid);
}

void ApiEnumWithBp::LogGenericParamsWithNames(PCONTEXT context, int paramCount, const std::vector<std::string>& paramNames, const std::string& functionName, DWORD threadId) {
    LogGenericParamsWithNamesForProcess(context, paramCount, paramNames, functionName, threadId, processId);
}

void ApiEnumWithBp::LogGenericParamsWithNamesForProcess(PCONTEXT context, int paramCount, const std::vector<std::string>& paramNames, const std::string& functionName, DWORD threadId, DWORD pid) {
    std::wostringstream apiCall;
    
    std::wstring processHierarchy = GetProcessHierarchyString(pid);
    
    apiCall << processHierarchy << L" [TID:" << std::setw(4) << threadId << L"] " 
            << StringToWString(functionName) << L"(";
    
    HANDLE hTargetProcess = hProcess;
    if (pid != processId) {
        auto processIt = trackedProcesses.find(pid);
        if (processIt != trackedProcesses.end()) {
            hTargetProcess = processIt->second.hProcess;
        }
    }
    
#ifdef _WIN64
    DWORD64 params[] = { context->Rcx, context->Rdx, context->R8, context->R9 };
    int maxParams = (paramCount < 4) ? paramCount : 4;
    
    for (int i = 0; i < maxParams; i++) {
        if (i > 0) apiCall << L", ";
        
        std::string paramName;
        if (i < static_cast<int>(paramNames.size()) && !paramNames[i].empty()) {
            paramName = paramNames[i];
        } else {
            paramName = "param" + std::to_string(i);
        }
        
        apiCall << StringToWString(paramName) << L"=0x" << std::hex << params[i] << std::dec;
    }
    
    for (int i = 4; i < paramCount && i < static_cast<int>(paramNames.size()); i++) {
        DWORD64 stackParam;
        SIZE_T bytesRead;
        PVOID stackAddr = reinterpret_cast<PVOID>(context->Rsp + 32 + (i - 4) * 8);
        if (ReadProcessMemory(hTargetProcess, stackAddr, &stackParam, sizeof(stackParam), &bytesRead)) {
            if (i > 0) apiCall << L", ";
            
            std::string paramName;
            if (i < static_cast<int>(paramNames.size()) && !paramNames[i].empty()) {
                paramName = paramNames[i];
            } else {
                paramName = "param" + std::to_string(i);
            }
            
            apiCall << StringToWString(paramName) << L"=0x" << std::hex << stackParam << std::dec;
        }
    }
#else
    DWORD esp = context->Esp;
    
    for (int i = 0; i < paramCount; i++) {
        DWORD param;
        SIZE_T bytesRead;
        if (ReadProcessMemory(hTargetProcess, reinterpret_cast<PVOID>(esp + 4 + (i * 4)), 
                            &param, sizeof(param), &bytesRead)) {
            if (i > 0) apiCall << L", ";
            
            std::string paramName;
            if (i < static_cast<int>(paramNames.size()) && !paramNames[i].empty()) {
                paramName = paramNames[i];
            } else {
                paramName = "param" + std::to_string(i);
            }
            
            apiCall << StringToWString(paramName) << L"=0x" << std::hex << param << std::dec;
        }
    }
#endif
    
    apiCall << L")" << std::endl;
    
    WriteApiCall(apiCall.str());
}

void ApiEnumWithBp::RestoreOriginalByte(PVOID address) {
    auto it = breakpoints.find(address);
    if (it != breakpoints.end() && it->second.isSet) {
        SIZE_T bytesWritten;
        WriteProcessMemory(hProcess, address, &it->second.originalByte, 1, &bytesWritten);
    }
}

void ApiEnumWithBp::RestoreOriginalByteForProcess(PVOID address, DWORD pid) {
    BreakpointKey bpKey = {pid, address};
    auto it = processBreakpoints.find(bpKey);
    if (it != processBreakpoints.end() && it->second.isSet) {
        auto processIt = trackedProcesses.find(pid);
        if (processIt != trackedProcesses.end()) {
            SIZE_T bytesWritten;
            WriteProcessMemory(processIt->second.hProcess, address, &it->second.originalByte, 1, &bytesWritten);
        }
    }
}

void ApiEnumWithBp::RestoreBreakpoint(PVOID address) {
    auto it = breakpoints.find(address);
    if (it != breakpoints.end() && it->second.isSet) {
        BYTE breakpointByte = 0xCC;
        SIZE_T bytesWritten;
        WriteProcessMemory(hProcess, address, &breakpointByte, 1, &bytesWritten);
    }
}

void ApiEnumWithBp::RestoreBreakpointForProcess(PVOID address, DWORD pid) {
    BreakpointKey bpKey = {pid, address};
    auto it = processBreakpoints.find(bpKey);
    if (it != processBreakpoints.end() && it->second.isSet) {
        auto processIt = trackedProcesses.find(pid);
        if (processIt != trackedProcesses.end()) {
            BYTE breakpointByte = 0xCC;
            SIZE_T bytesWritten;
            WriteProcessMemory(processIt->second.hProcess, address, &breakpointByte, 1, &bytesWritten);
        }
    }
}

void ApiEnumWithBp::CleanupBreakpoints() {
    LogVerbose(L"Cleaning up " + std::to_wstring(breakpoints.size()) + L" main process breakpoints");
    
    int restoredCount = 0;
    for (auto& bp : breakpoints) {
        if (bp.second.isSet) {
            RestoreOriginalByte(bp.first);
            restoredCount++;
        }
    }
    
    breakpoints.clear();
    
    LogVerbose(L"Cleaning up " + std::to_wstring(processBreakpoints.size()) + L" child process breakpoints");
    
    int childRestoredCount = 0;
    for (auto& bp : processBreakpoints) {
        if (bp.second.isSet) {
            RestoreOriginalByteForProcess(bp.first.address, bp.first.processId);
            childRestoredCount++;
        }
    }
    
    processBreakpoints.clear();
    
    LogVerbose(L"Restored " + std::to_wstring(restoredCount) + L" main process breakpoints and " + 
               std::to_wstring(childRestoredCount) + L" child process breakpoints");
}

bool ApiEnumWithBp::ShouldTraceProcess(DWORD pid, int depth) const {
    if (pid == rootProcessId) {
        return true;
    }
    
    if (g_config.trace_level == -1) {
        return false;
    }
    
    if (g_config.trace_level == 0) {
        return true;
    }
    
    return depth <= g_config.trace_level;
}

void ApiEnumWithBp::DebugTraceLevel() const {
    LogMessage(L"DEBUG: Current trace_level = " + std::to_wstring(g_config.trace_level));
    
    if (g_config.trace_level == -1) {
        LogMessage(L"DEBUG: Child tracing should be DISABLED");
    } else if (g_config.trace_level == 0) {
        LogMessage(L"DEBUG: Child tracing should be UNLIMITED");
    } else {
        LogMessage(L"DEBUG: Child tracing should be LIMITED to depth " + std::to_wstring(g_config.trace_level));
    }
}

void ApiEnumWithBp::StartTracing() {
    LogMessage(L"Starting API tracing...");
    
    if (g_config.trace_level == -1) {
        LogMessage(L"Child process tracing: DISABLED");
    } else if (g_config.trace_level == 0) {
        LogMessage(L"Child process tracing: UNLIMITED depth");
    } else {
        LogMessage(L"Child process tracing: LIMITED to depth " + std::to_wstring(g_config.trace_level));
    }
    
    g_tracing_active = true;
    
    DEBUG_EVENT debugEvent;
    bool continueDebugging = true;
    bool modulesChecked = false;
    std::map<DWORD, bool> childModulesChecked;
    std::map<DWORD, int> dllLoadCounts;
    
    while (continueDebugging) {
        if (!WaitForDebugEvent(&debugEvent, INFINITE)) {
            LogError(L"WaitForDebugEvent failed. Error: " + std::to_wstring(GetLastError()));
            break;
        }
        
        DWORD continueStatus = DBG_CONTINUE;
        DWORD currentPid = debugEvent.dwProcessId;
        
        switch (debugEvent.dwDebugEventCode) {
            case CREATE_PROCESS_DEBUG_EVENT:
                if (currentPid == rootProcessId) {
                    LogMessage(L"Root process created");
                } else {
                    if (g_config.trace_level == -1) {
                        LogMessage(L"Child process created but IGNORED: " + std::to_wstring(currentPid) + L" (child tracing disabled)");
                    } else {
                        LogMessage(L"Child process created: " + std::to_wstring(currentPid));
                        
                        DWORD parentPid = rootProcessId;
                        for (const auto& [pid, info] : trackedProcesses) {
                            if (pid != currentPid && info.depth < 5) {
                                parentPid = pid;
                            }
                        }
                        
                        SetupChildProcess(currentPid, parentPid);
                    }
                }
                CloseHandle(debugEvent.u.CreateProcessInfo.hFile);
                break;
            case EXCEPTION_DEBUG_EVENT:
                if (currentPid == processId ||
                    (g_config.trace_level != -1 && trackedProcesses.find(currentPid) != trackedProcesses.end())) {
                
                    if (debugEvent.u.Exception.ExceptionRecord.ExceptionCode == EXCEPTION_BREAKPOINT) {
                        if (debugEvent.u.Exception.dwFirstChance) {
                            if (currentPid == processId && !modulesChecked) {
                                LogMessage(L"Entry point hit for main process - setting up modules and breakpoints");
                                modulesChecked = true;
                                
                                Sleep(100);
                                
                                if (WaitForModulesAndSetupBreakpoints()) {
                                    LogMessage(L"SUCCESS: Main process setup completed");
                                } else {
                                    LogError(L"FAILED: Main process setup failed");
                                }
                            }
                            else if (currentPid != processId && !childModulesChecked[currentPid]) {
                                LogMessage(L"Entry point hit for main process - setting up modules and breakpoints");
                                modulesChecked = true;
                                
                                Sleep(100);
                                
                                if (WaitForModulesAndSetupBreakpoints()) {
                                    LogMessage(L"SUCCESS: Main process setup completed");
                                } else {
                                    LogError(L"FAILED: Main process setup failed");
                                }
                            }
                            else if (currentPid != processId && !childModulesChecked[currentPid]) {
                                LogMessage(L"Entry point hit for child process " + std::to_wstring(currentPid) + L" - setting up modules and breakpoints");
                                childModulesChecked[currentPid] = true;
                                
                                Sleep(100);
                                
                                if (SetupModulesForProcess(currentPid)) {
                                    LogMessage(L"Found required modules for child process " + std::to_wstring(currentPid));
                                    if (SetupBreakpointsForProcess(currentPid)) {
                                        LogMessage(L"SUCCESS: Child process " + std::to_wstring(currentPid) + L" setup completed");
                                    } else {
                                        LogError(L"FAILED: Child process " + std::to_wstring(currentPid) + L" breakpoint setup failed");
                                    }
                                } else {
                                    LogError(L"FAILED: Child process " + std::to_wstring(currentPid) + L" module setup failed");
                                }
                            }
                            else {
                                HandleBreakpoint(debugEvent);
                            }
                        } else {
                            continueStatus = DBG_EXCEPTION_NOT_HANDLED;
                        }
                    } else if (debugEvent.u.Exception.ExceptionRecord.ExceptionCode == EXCEPTION_SINGLE_STEP) {
                        HandleSingleStep(debugEvent);
                    } else {
                        continueStatus = DBG_EXCEPTION_NOT_HANDLED;
                    }
                } else {
                    continueStatus = DBG_EXCEPTION_NOT_HANDLED;
                }
                break;
            case LOAD_DLL_DEBUG_EVENT:
                if (currentPid == processId ||
                    (g_config.trace_level != -1 && trackedProcesses.find(currentPid) != trackedProcesses.end())) {
                
                    dllLoadCounts[currentPid]++;
                    
                    std::wstring dllName = L"<unknown>";
                    if (debugEvent.u.LoadDll.lpImageName) {
                        HANDLE hTargetProcess = (currentPid == processId) ? hProcess : 
                                            (trackedProcesses.find(currentPid) != trackedProcesses.end() ? 
                                                trackedProcesses[currentPid].hProcess : NULL);
                        
                        if (hTargetProcess) {
                            DWORD_PTR namePtr = 0;
                            SIZE_T bytesRead;
                            
                            if (ReadProcessMemory(hTargetProcess, debugEvent.u.LoadDll.lpImageName, 
                                                &namePtr, sizeof(namePtr), &bytesRead) && namePtr != 0) {
                                
                                if (debugEvent.u.LoadDll.fUnicode) {
                                    wchar_t dllPath[MAX_PATH] = {0};
                                    if (ReadProcessMemory(hTargetProcess, (LPCVOID)namePtr, 
                                                        dllPath, sizeof(dllPath) - sizeof(wchar_t), &bytesRead)) {
                                        dllName = dllPath;
                                        
                                        size_t lastSlash = dllName.find_last_of(L"\\");
                                        if (lastSlash != std::wstring::npos) {
                                            dllName = dllName.substr(lastSlash + 1);
                                        }
                                    }
                                } else {
                                    char dllPathA[MAX_PATH] = {0};
                                    if (ReadProcessMemory(hTargetProcess, (LPCVOID)namePtr, 
                                                        dllPathA, sizeof(dllPathA) - 1, &bytesRead)) {
                                        std::string dllNameA = dllPathA;
                                        
                                        size_t lastSlash = dllNameA.find_last_of("\\");
                                        if (lastSlash != std::string::npos) {
                                            dllNameA = dllNameA.substr(lastSlash + 1);
                                        }
                                        
                                        dllName = StringToWString(dllNameA);
                                    }
                                }
                            }
                        }
                    }
                    
                    if (dllName == L"<unknown>" && debugEvent.u.LoadDll.lpBaseOfDll) {
                        HANDLE hTargetProcess = (currentPid == processId) ? hProcess : 
                                            (trackedProcesses.find(currentPid) != trackedProcesses.end() ? 
                                                trackedProcesses[currentPid].hProcess : NULL);
                        
                        if (hTargetProcess) {
                            wchar_t moduleFileName[MAX_PATH];
                            if (GetModuleBaseNameW(hTargetProcess, (HMODULE)debugEvent.u.LoadDll.lpBaseOfDll, 
                                                moduleFileName, MAX_PATH)) {
                                dllName = moduleFileName;
                            }
                        }
                    }
                    
                    LogVerbose(L"DLL loaded in process " + std::to_wstring(currentPid) +
                            L" (count: " + std::to_wstring(dllLoadCounts[currentPid]) + 
                            L"): " + dllName);
                
                    if (currentPid == processId && modulesChecked && breakpointsReady) {
                        CheckForNewModulesAndSetBreakpoints();
                    } else if (currentPid != processId &&
                                trackedProcesses.find(currentPid) != trackedProcesses.end() &&
                                childModulesChecked[currentPid] && 
                                trackedProcesses[currentPid].breakpointsReady) {
                        CheckForNewModulesAndSetBreakpointsForProcess(currentPid);
                    }
                } else {
                    LogVerbose(L"DLL loaded in untracked process " + std::to_wstring(currentPid) + L" (ignored)");
                }
                
                CloseHandle(debugEvent.u.LoadDll.hFile);
                break;
            case EXIT_PROCESS_DEBUG_EVENT:
                if (currentPid == processId) {
                    LogMessage(L"Root process exited with code: " + std::to_wstring(debugEvent.u.ExitProcess.dwExitCode));
                    continueDebugging = false;
                } else if (trackedProcesses.find(currentPid) != trackedProcesses.end()) {
                    LogMessage(L"Child process " + std::to_wstring(currentPid) + 
                              L" exited with code: " + std::to_wstring(debugEvent.u.ExitProcess.dwExitCode));
                    
                    auto processIt = trackedProcesses.find(currentPid);
                    if (processIt != trackedProcesses.end()) {
                        auto bpIt = processBreakpoints.begin();
                        while (bpIt != processBreakpoints.end()) {
                            if (bpIt->first.processId == currentPid) {
                                bpIt = processBreakpoints.erase(bpIt);
                            } else {
                                ++bpIt;
                            }
                        }
                        
                        if (processIt->second.hProcess && processIt->second.hProcess != hProcess) {
                            CloseHandle(processIt->second.hProcess);
                        }
                        trackedProcesses.erase(processIt);
                    }
                } else {
                    LogVerbose(L"Untracked process " + std::to_wstring(currentPid) + L" exited (ignored)");
                }
                break;
                
            default:
                break;
        }
        
        ContinueDebugEvent(debugEvent.dwProcessId, debugEvent.dwThreadId, continueStatus);
        
        // Check for timeout
        if (IsTimeoutReached()) {
            LogMessage(L"Timeout reached, stopping trace");
            break;
        }
    }
    
    g_tracing_active = false;
    LogMessage(L"Tracing completed");
    PrintStatistics();
}