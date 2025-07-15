#include "headers\apienumwithbp.h"
#include <algorithm>

// Global variable definition
std::map<std::string, std::vector<std::string>> functionSignatures;

// Helper function to convert string to wstring
std::wstring StringToWString(const std::string& str) {
    return std::wstring(str.begin(), str.end());
}

void ApiEnumWithBp::InitializeIgnoredFunctions() {
    ignoredFunctions.clear();
    
    // Functions we don't want to log because they're too noisy
    ignoredFunctions.insert("RtlCompareMemoryUlong");
    
    std::wcout << L"Initialized " << ignoredFunctions.size() << L" ignored functions" << std::endl;
}

bool ApiEnumWithBp::IsFunctionIgnored(const std::string& functionName) {
    return ignoredFunctions.find(functionName) != ignoredFunctions.end();
}

void ApiEnumWithBp::AddIgnoredFunction(const std::string& functionName) {
    ignoredFunctions.insert(functionName);
}

void ApiEnumWithBp::PrintIgnoredFunctions() const {
    std::wcout << L"Ignored functions (" << ignoredFunctions.size() << L"):" << std::endl;
    for (const auto& func : ignoredFunctions) {
        std::wcout << L"  - " << StringToWString(func) << std::endl;
    }
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
    
    // Trim whitespace
    params.erase(0, params.find_first_not_of(" \t\n\r"));
    params.erase(params.find_last_not_of(" \t\n\r") + 1);
    
    if (params.empty() || params == "void") return 0;
    
    // Split by commas but respect brackets
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
    
    // Count valid parameters
    int validParams = 0;
    for (const std::string& param : paramList) {
        std::string cleanParam = param;
        
        // Remove all [annotations] like [in], [out], [in,optional], etc.
        size_t bracketStart = 0;
        while ((bracketStart = cleanParam.find('[', bracketStart)) != std::string::npos) {
            size_t bracketEnd = cleanParam.find(']', bracketStart);
            if (bracketEnd != std::string::npos) {
                cleanParam.erase(bracketStart, bracketEnd - bracketStart + 1);
            } else {
                break;
            }
        }
        
        // Remove __in, __out, _In_, _Out_, etc.
        std::regex annotationRegex(R"((__\w+_?|_\w+_))");
        cleanParam = std::regex_replace(cleanParam, annotationRegex, "");
        
        // Trim again
        cleanParam.erase(0, cleanParam.find_first_not_of(" \t\n\r"));
        cleanParam.erase(cleanParam.find_last_not_of(" \t\n\r") + 1);
        
        // If there's still content after removing annotations, it's a valid parameter
        if (!cleanParam.empty() && cleanParam != "void") {
            validParams++;
        }
    }
    
    return validParams;
}

void ApiEnumWithBp::InitializeTracedFunctions() {
    tracedFunctions.clear();
    
    // Map header files to their corresponding DLLs
    std::map<std::string, std::string> fileToDllMap = {
        {"ntifs.h", "ntdll"},
        {"winternl.h", "ntdll"},
        {"ntstatus.h", "ntdll"},
        {"ntdef.h", "ntdll"},
        {"fileapi.h", "kernel32"},
        {"processthreadsapi.h", "kernel32"},
        {"memoryapi.h", "kernel32"},
        {"handleapi.h", "kernel32"},
        {"libloaderapi.h", "kernel32"},
        {"debugapi.h", "kernel32"},
        {"consoleapi.h", "kernel32"},
        {"winbase.h", "kernel32"},
        {"synchapi.h", "kernel32"},
        {"namedpipeapi.h", "kernel32"},
        {"wow64apiset.h", "kernel32"},
        {"winuser.h", "user32"},
        {"winreg.h", "advapi32"},
        {"winsvc.h", "advapi32"}
    };
    
    // Hardcoded list of files to process
    std::vector<std::string> filesToProcess = {
        "consoleapi.h",
        "fileapi.h",
        "ntifs.h"
    };
    
    for (const std::string& fileName : filesToProcess) {
        std::string filePath = "dll_headers\\" + fileName;
        std::ifstream file(filePath);
        
        if (!file.is_open()) {
            std::wcout << L"Warning: Could not open " << StringToWString(fileName) << std::endl;
            continue;
        }
        
        // Get the DLL name from the mapping
        std::string dllName = "unknown";
        auto it = fileToDllMap.find(fileName);
        if (it != fileToDllMap.end()) {
            dllName = it->second;
        }
        
        std::string line;
        int functionsFound = 0;
        
        while (std::getline(file, line)) {
            // Skip empty lines and comments
            if (line.empty() || line[0] == '/' || line[0] == '*') continue;
            
            // Look for function declarations
            if (line.find('(') != std::string::npos) {
                std::string fullFunction = line;
                
                // If function doesn't end on same line, collect more lines
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
                    
                    std::wcout << L"Found: " << StringToWString(funcName) << L" with " 
                              << paramCount << L" parameters" << std::endl;
                } else if (!funcName.empty()) {
                    std::wcout << L"Ignored: " << StringToWString(funcName) 
                              << L" (in ignore list)" << std::endl;
                }
            }
        }
        file.close();
        
        std::wcout << L"Loaded " << functionsFound << L" functions from " 
                  << StringToWString(fileName) << L" (" << StringToWString(dllName) 
                  << L")" << std::endl;
    }
    
    std::wcout << L"Total: " << tracedFunctions.size() << L" functions loaded" << std::endl;
}

ApiEnumWithBp::ApiEnumWithBp() : hProcess(NULL), processId(0), hNtdll(NULL), hKernel32(NULL), breakpointsReady(false) {
    InitializeIgnoredFunctions();
    InitializeTracedFunctions();
}

ApiEnumWithBp::~ApiEnumWithBp() {
    if (hProcess) {
        CleanupBreakpoints();
        CloseHandle(hProcess);
    }
}

bool ApiEnumWithBp::CreateAndAttachProcess(const std::wstring& executablePath) {
    STARTUPINFOW si = { sizeof(si) };
    PROCESS_INFORMATION pi = { 0 };
    
    if (!CreateProcessW(
        executablePath.c_str(),
        NULL,
        NULL,
        NULL,
        FALSE,
        DEBUG_ONLY_THIS_PROCESS,
        NULL,
        NULL,
        &si,
        &pi)) {
        std::wcerr << L"Failed to create process. Error: " << GetLastError() << std::endl;
        return false;
    }
    
    hProcess = pi.hProcess;
    processId = pi.dwProcessId;
    CloseHandle(pi.hThread);
    
    std::wcout << L"Created and attached to process " << processId << std::endl;
    return true;
}

bool ApiEnumWithBp::AttachToProcess(DWORD pid) {
    processId = pid;
    
    if (!DebugActiveProcess(pid)) {
        std::wcerr << L"Failed to attach to process " << pid << L". Error: " << GetLastError() << std::endl;
        return false;
    }
    
    hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
    if (!hProcess) {
        std::wcerr << L"Failed to open process handle. Error: " << GetLastError() << std::endl;
        DebugActiveProcessStop(pid);
        return false;
    }
    
    std::wcout << L"Successfully attached to process " << pid << std::endl;
    return true;
}

bool ApiEnumWithBp::WaitForModulesAndSetupBreakpoints() {
    std::wcout << L"Waiting for modules to load..." << std::endl;
    
    for (int attempt = 0; attempt < 20; attempt++) {
        Sleep(200);
        
        if (FindAndSetupModules()) {
            std::wcout << L"Found required modules on attempt " << (attempt + 1) << std::endl;
            return SetupBreakpoints();
        }
        
        if (attempt % 5 == 0) {
            std::wcout << L"Still waiting for modules... (attempt " << (attempt + 1) << L")" << std::endl;
        }
    }
    
    std::wcerr << L"Failed to find required modules after 20 attempts" << std::endl;
    return false;
}

bool ApiEnumWithBp::FindAndSetupModules() {
    HMODULE modules[1024];
    DWORD cbNeeded;
    
    if (!EnumProcessModules(hProcess, modules, sizeof(modules), &cbNeeded)) {
        return false;
    }
    
    hNtdll = NULL;
    hKernel32 = NULL;
    
    for (DWORD i = 0; i < (cbNeeded / sizeof(HMODULE)); i++) {
        wchar_t moduleName[MAX_PATH];
        if (GetModuleBaseNameW(hProcess, modules[i], moduleName, MAX_PATH)) {
            if (_wcsicmp(moduleName, L"ntdll.dll") == 0) {
                hNtdll = modules[i];
                std::wcout << L"Found NTDLL at: 0x" << std::hex 
                          << reinterpret_cast<uintptr_t>(hNtdll) << std::dec << std::endl;
            } else if (_wcsicmp(moduleName, L"kernel32.dll") == 0) {
                hKernel32 = modules[i];
                std::wcout << L"Found KERNEL32 at: 0x" << std::hex 
                          << reinterpret_cast<uintptr_t>(hKernel32) << std::dec << std::endl;
            }
        }
    }
    
    return (hNtdll != NULL && hKernel32 != NULL);
}

bool ApiEnumWithBp::SetupBreakpoints() {
    if (breakpointsReady) return true;
    
    int successCount = 0;
    int failCount = 0;
    
    std::wcout << L"Setting up breakpoints..." << std::endl;
    
    for (const auto& func : tracedFunctions) {
        if (SetBreakpointOnFunction(func)) {
            successCount++;
        } else {
            failCount++;
            std::wcout << L"Failed to set breakpoint for " << StringToWString(func.name) << std::endl;
        }
    }
    
    std::wcout << L"Breakpoint setup complete: " << successCount 
              << L" successful, " << failCount << L" failed" << std::endl;
    
    breakpointsReady = (successCount > 0);
    return breakpointsReady;
}

bool ApiEnumWithBp::SetBreakpointOnFunction(const ApiFunction& func) {
    HMODULE localModule = NULL;
    HMODULE targetModule = NULL;
    
    if (func.module == "ntdll") {
        localModule = GetModuleHandleW(L"ntdll.dll");
        targetModule = hNtdll;
    } else if (func.module == "kernel32") {
        localModule = GetModuleHandleW(L"kernel32.dll");
        targetModule = hKernel32;
    }
    
    if (!localModule || !targetModule) {
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
    
    if (breakpoints.find(targetAddr) != breakpoints.end()) {
        return true;
    }
    
    BYTE originalByte;
    SIZE_T bytesRead;
    if (!ReadProcessMemory(hProcess, targetAddr, &originalByte, 1, &bytesRead) || bytesRead != 1) {
        return false;
    }
    
    if (originalByte == 0xCC) {
        return false;
    }
    
    BYTE breakpointByte = 0xCC;
    SIZE_T bytesWritten;
    if (!WriteProcessMemory(hProcess, targetAddr, &breakpointByte, 1, &bytesWritten) || bytesWritten != 1) {
        return false;
    }
    
    Breakpoint bp;
    bp.address = targetAddr;
    bp.originalByte = originalByte;
    bp.functionName = func.name;
    bp.isActive = true;
    bp.isSet = true;
    
    breakpoints[targetAddr] = bp;
    
    std::wcout << L"Set breakpoint for " << StringToWString(func.name) 
              << L" at 0x" << std::hex << reinterpret_cast<uintptr_t>(targetAddr) 
              << std::dec << std::endl;
    
    return true;
}

void ApiEnumWithBp::HandleBreakpoint(const DEBUG_EVENT& debugEvent) {
    PVOID exceptionAddr = debugEvent.u.Exception.ExceptionRecord.ExceptionAddress;
    
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
        
        if (breakpoints.find(prevAddr) != breakpoints.end()) {
            RestoreBreakpoint(prevAddr);
        }
    }
    
    CloseHandle(hThread);
}

void ApiEnumWithBp::LogApiCall(const std::string& functionName, PCONTEXT context, DWORD threadId) {
    std::wcout << L"[TID:" << std::setw(4) << threadId << L"] " 
              << StringToWString(functionName) << L"(";
    
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
    
    if (functionName == "WriteConsoleW") {
        LogWriteConsoleWWithNames(context, hasSignature ? sigIt->second : std::vector<std::string>());
    } else if (functionName == "CreateFileW") {
        LogCreateFileWWithNames(context, hasSignature ? sigIt->second : std::vector<std::string>());
    } else {
        int paramCount = 4;
        for (const auto& func : tracedFunctions) {
            if (func.name == functionName) {
                paramCount = func.paramCount;
                break;
            }
        }
        
        LogGenericParamsWithNames(context, paramCount, hasSignature ? sigIt->second : std::vector<std::string>());
    }
}

void ApiEnumWithBp::LogWriteConsoleWWithNames(PCONTEXT context, const std::vector<std::string>& paramNames) {
#ifdef _WIN64
    HANDLE hConsole = reinterpret_cast<HANDLE>(context->Rcx);
    LPCWSTR lpBuffer = reinterpret_cast<LPCWSTR>(context->Rdx);
    DWORD nCharsToWrite = static_cast<DWORD>(context->R8);
#else
    DWORD esp = context->Esp;
    HANDLE hConsole;
    LPCWSTR lpBuffer;
    DWORD nCharsToWrite;
    SIZE_T bytesRead;
    
    ReadProcessMemory(hProcess, reinterpret_cast<PVOID>(esp + 4), &hConsole, sizeof(hConsole), &bytesRead);
    ReadProcessMemory(hProcess, reinterpret_cast<PVOID>(esp + 8), &lpBuffer, sizeof(lpBuffer), &bytesRead);
    ReadProcessMemory(hProcess, reinterpret_cast<PVOID>(esp + 12), &nCharsToWrite, sizeof(nCharsToWrite), &bytesRead);
#endif
    
    std::string consoleName = (paramNames.size() > 0) ? paramNames[0] : "hConsoleOutput";
    std::string bufferName = (paramNames.size() > 1) ? paramNames[1] : "lpBuffer";
    std::string countName = (paramNames.size() > 2) ? paramNames[2] : "nNumberOfCharsToWrite";
    
    std::wcout << StringToWString(consoleName) << L"=0x" << std::hex 
              << reinterpret_cast<uintptr_t>(hConsole) << L", " 
              << StringToWString(countName) << L"=" << std::dec << nCharsToWrite;
    
    if (lpBuffer && nCharsToWrite > 0 && nCharsToWrite < 512) {
        std::vector<wchar_t> buffer(nCharsToWrite + 1, 0);
        SIZE_T bytesRead;
        
        if (ReadProcessMemory(hProcess, const_cast<LPWSTR>(lpBuffer), 
                            buffer.data(), nCharsToWrite * sizeof(wchar_t), &bytesRead)) {
            
            std::wstring text(buffer.data(), nCharsToWrite);
            if (text.length() > 50) {
                text = text.substr(0, 50) + L"...";
            }
            
            for (auto& ch : text) {
                if (ch < 32 || ch > 126) ch = L'?';
            }
            
            std::wcout << L", " << StringToWString(bufferName) << L"=\"" << text << L"\"";
        }
    }
    
    std::wcout << L")" << std::endl;
}

void ApiEnumWithBp::LogCreateFileWWithNames(PCONTEXT context, const std::vector<std::string>& paramNames) {
#ifdef _WIN64
    LPCWSTR lpFileName = reinterpret_cast<LPCWSTR>(context->Rcx);
    DWORD dwDesiredAccess = static_cast<DWORD>(context->Rdx);
#else
    DWORD esp = context->Esp;
    LPCWSTR lpFileName;
    DWORD dwDesiredAccess;
    SIZE_T bytesRead;
    
    ReadProcessMemory(hProcess, reinterpret_cast<PVOID>(esp + 4), &lpFileName, sizeof(lpFileName), &bytesRead);
    ReadProcessMemory(hProcess, reinterpret_cast<PVOID>(esp + 8), &dwDesiredAccess, sizeof(dwDesiredAccess), &bytesRead);
#endif
    
    std::string fileNameParam = (paramNames.size() > 0) ? paramNames[0] : "lpFileName";
    std::string accessParam = (paramNames.size() > 1) ? paramNames[1] : "dwDesiredAccess";
    
    std::wcout << StringToWString(accessParam) << L"=0x" << std::hex << dwDesiredAccess << std::dec;
    
    if (lpFileName) {
        wchar_t filename[MAX_PATH] = {0};
        SIZE_T bytesRead;
        
        if (ReadProcessMemory(hProcess, const_cast<LPWSTR>(lpFileName), 
                            filename, sizeof(filename) - sizeof(wchar_t), &bytesRead)) {
            std::wcout << L", " << StringToWString(fileNameParam) << L"=\"" << filename << L"\"";
        }
    }
    
    std::wcout << L")" << std::endl;
}

void ApiEnumWithBp::LogGenericParamsWithNames(PCONTEXT context, int paramCount, const std::vector<std::string>& paramNames) {
#ifdef _WIN64
    DWORD64 params[] = { context->Rcx, context->Rdx, context->R8, context->R9 };
    int maxParams = (paramCount < 4) ? paramCount : 4;  // no std::min, just a basic comparison
    
    for (int i = 0; i < maxParams; i++) {
        if (i > 0) std::wcout << L", ";
        
        std::string paramName;
        if (i < static_cast<int>(paramNames.size()) && !paramNames[i].empty()) {
            paramName = paramNames[i];
        } else {
            paramName = "param" + std::to_string(i);
        }
        
        std::wcout << StringToWString(paramName) << L"=0x" << std::hex << params[i] << std::dec;
    }
    
    for (int i = 4; i < paramCount && i < static_cast<int>(paramNames.size()); i++) {
        DWORD64 stackParam;
        SIZE_T bytesRead;
        PVOID stackAddr = reinterpret_cast<PVOID>(context->Rsp + 32 + (i - 4) * 8);
        if (ReadProcessMemory(hProcess, stackAddr, &stackParam, sizeof(stackParam), &bytesRead)) {
            if (i > 0) std::wcout << L", ";
            
            std::string paramName;
            if (i < static_cast<int>(paramNames.size()) && !paramNames[i].empty()) {
                paramName = paramNames[i];
            } else {
                paramName = "param" + std::to_string(i);
            }
            
            std::wcout << StringToWString(paramName) << L"=0x" << std::hex << stackParam << std::dec;
        }
    }
#else
    DWORD esp = context->Esp;
    
    for (int i = 0; i < paramCount; i++) {
        DWORD param;
        SIZE_T bytesRead;
        if (ReadProcessMemory(hProcess, reinterpret_cast<PVOID>(esp + 4 + (i * 4)), 
                            &param, sizeof(param), &bytesRead)) {
            if (i > 0) std::wcout << L", ";
            
            std::string paramName;
            if (i < static_cast<int>(paramNames.size()) && !paramNames[i].empty()) {
                paramName = paramNames[i];
            } else {
                paramName = "param" + std::to_string(i);
            }
            
            std::wcout << StringToWString(paramName) << L"=0x" << std::hex << param << std::dec;
        }
    }
#endif
    
    std::wcout << L")" << std::endl;
}

void ApiEnumWithBp::RestoreOriginalByte(PVOID address) {
    auto it = breakpoints.find(address);
    if (it != breakpoints.end() && it->second.isSet) {
        SIZE_T bytesWritten;
        WriteProcessMemory(hProcess, address, &it->second.originalByte, 1, &bytesWritten);
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

void ApiEnumWithBp::StartTracing() {
    std::wcout << L"Starting API tracing..." << std::endl;
    
    DEBUG_EVENT debugEvent;
    bool continueDebugging = true;
    bool modulesChecked = false;
    
    while (continueDebugging) {
        if (!WaitForDebugEvent(&debugEvent, INFINITE)) {
            std::wcerr << L"WaitForDebugEvent failed. Error: " << GetLastError() << std::endl;
            break;
        }
        
        DWORD continueStatus = DBG_CONTINUE;
        
        switch (debugEvent.dwDebugEventCode) {
            case CREATE_PROCESS_DEBUG_EVENT:
                std::wcout << L"Process created." << std::endl;
                CloseHandle(debugEvent.u.CreateProcessInfo.hFile);
                break;
                
            case LOAD_DLL_DEBUG_EVENT:
                if (!breakpointsReady && !modulesChecked) {
                    static int dllLoadCount = 0;
                    dllLoadCount++;
                    if (dllLoadCount >= 3) {
                        modulesChecked = true;
                        WaitForModulesAndSetupBreakpoints();
                    }
                }
                CloseHandle(debugEvent.u.LoadDll.hFile);
                break;
                
            case EXCEPTION_DEBUG_EVENT:
                if (debugEvent.u.Exception.ExceptionRecord.ExceptionCode == EXCEPTION_BREAKPOINT) {
                    if (debugEvent.u.Exception.dwFirstChance) {
                        HandleBreakpoint(debugEvent);
                    } else {
                        continueStatus = DBG_EXCEPTION_NOT_HANDLED;
                    }
                } else if (debugEvent.u.Exception.ExceptionRecord.ExceptionCode == EXCEPTION_SINGLE_STEP) {
                    HandleSingleStep(debugEvent);
                } else {
                    continueStatus = DBG_EXCEPTION_NOT_HANDLED;
                }
                break;
                
            case EXIT_PROCESS_DEBUG_EVENT:
                std::wcout << L"Process exited with code: " 
                          << debugEvent.u.ExitProcess.dwExitCode << std::endl;
                continueDebugging = false;
                break;
        }
        
        ContinueDebugEvent(debugEvent.dwProcessId, debugEvent.dwThreadId, continueStatus);
    }
    
    std::wcout << L"Tracing completed." << std::endl;
}

void ApiEnumWithBp::CleanupBreakpoints() {
    for (auto& bp : breakpoints) {
        if (bp.second.isSet) {
            RestoreOriginalByte(bp.first);
        }
    }
    breakpoints.clear();
}