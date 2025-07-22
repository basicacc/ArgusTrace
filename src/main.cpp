#include <windows.h>
#include <iostream>
#include <string>
#include <filesystem>
#include <sstream>
#include <fstream>
#include <vector>
#include "headers\apienumwithbp.h"
#include "headers\globals.h"

void ShowHelp(const wchar_t* program_name) {
    std::wcout << L"==================== API TRACER HELP ====================\n";
    std::wcout << L"Usage: " << program_name << L" [OPTIONS] [EXECUTABLE] [ARGS...]\n\n";
    
    std::wcout << L"OPTIONS:\n";
    std::wcout << L"  -c, --choice <1|2|3>     Tracing method (1=breakpoints, 2=dynamorio, 3=other)\n";
    std::wcout << L"  -f, --file <FILE>        Executable file to be traced\n";
    std::wcout << L"  -a, --args \"args\"      Arguments to execute the file with\n";
    std::wcout << L"  -p, --pid <PID>          Attach to existing process ID\n";
    std::wcout << L"  -t, --trace <0-...>      depth of trace for child processes (0 means unlimited), no childtrace, if not set\n";
    std::wcout << L"  -s, --sleep <MS>         Sleep after creating process\n";
    std::wcout << L"  -d, --dll-dir <PATH>     Directory containing DLL headers\n";
    std::wcout << L"  -o, --output <FILE>      Output file for API calls\n";
    std::wcout << L"  -l, --log <FILE>         Log file for verbose output\n";
    std::wcout << L"  -v, --verbose            Enable verbose output\n";
    std::wcout << L"  -h, --help               Show this help message\n\n";
    
    std::wcout << L"TRACING METHODS:\n";
    std::wcout << L"  1 - API tracing using breakpoints\n";
    std::wcout << L"  2 - Advanced instruction tracing using DynamoRIO + Auto Analysis\n";
    std::wcout << L"  3 - Other tracing method (not implemented yet)\n\n";
    
    std::wcout << L"EXAMPLES:\n";
    std::wcout << L"  Interactive mode:\n";
    std::wcout << L"    " << program_name << L"\n\n";
    
    std::wcout << L"  Breakpoint tracing:\n";
    std::wcout << L"    " << program_name << L" -c 1 notepad.exe\n";
    std::wcout << L"    " << program_name << L" -c 1 -d dll_headers -o api_trace.txt notepad.exe\n";
    std::wcout << L"    " << program_name << L" -c 1 -p 1234 -d dll_headers --verbose\n\n";
    
    std::wcout << L"  DynamoRIO tracing:\n";
    std::wcout << L"    " << program_name << L" -c 2 calc.exe\n";
    std::wcout << L"    " << program_name << L" -c 2 -t 30000 -m 1000 app.exe arg1 arg2\n\n";
}

bool ParseArguments(int argc, wchar_t* argv[]) {
    g_config = GetDefaultConfig();
    
    for (int i = 1; i < argc; i++) {
        std::wstring arg(argv[i]);
        
        if (arg == L"-c" || arg == L"--choice") {
            if (i + 1 < argc) {
                g_config.choice = _wtoi(argv[++i]);
                if (g_config.choice < 1 || g_config.choice > 3) {
                    LogError(FormatMessage(L"Invalid choice '%d'. Must be 1, 2, or 3.", g_config.choice));
                    return false;
                }
            } else {
                LogError(L"--choice requires a value (1, 2, or 3)");
                return false;
            }
        }
        else if (arg == L"-f" || arg == L"--file") {
            if (i+1 < argc){
                g_config.executable_path = argv[++i];
            }
        }
        else if (arg == L"-a" || arg == L"--args") {
            if (i + 1 < argc) {
                i++;
                std::wstring argStr = argv[i]; 
                
                if (argStr.front() == L'"' && argStr.back() != L'"') {
                    while (i + 1 < argc) {
                        i++;
                        argStr += L" " + std::wstring(argv[i]);
                        if (argv[i][wcslen(argv[i]) - 1] == L'"') {
                            break;
                        }
                    }
                }
                
                if (argStr.size() >= 2 && argStr.front() == L'"' && argStr.back() == L'"') {
                    argStr = argStr.substr(1, argStr.size() - 2);
                }
                g_config.extra_args = argStr;
            }
        }
        else if (arg == L"-p" || arg == L"--pid") {
            if (i + 1 < argc) {
                g_config.pid = _wtoi(argv[++i]);
                g_config.attach_mode = true;
                if (!ValidatePid(g_config.pid)) {
                    LogError(FormatMessage(L"Invalid or non-existent PID '%lu'", g_config.pid));
                    return false;
                }
            } else {
                LogError(L"--pid requires a process ID");
                return false;
            }
        }
        else if (arg == L"-t" || arg == L"--trace"){
            if (i + 1 < argc){
                g_config.trace_level = _wtoi(argv[++i]);
            }
        }
        else if (arg == L"-s" || arg == L"--sleep"){
            if (i+1 < argc){
                g_config.sleep_time = _wtoi(argv[++i]);
            }
        }
        else if (arg == L"-d" || arg == L"--dll-dir") {
            if (i + 1 < argc) {
                g_config.dll_headers_dir = argv[++i];
                if (!ValidateDllHeadersDir(g_config.dll_headers_dir)) {
                    LogError(FormatMessage(L"DLL headers directory '%s' does not exist", g_config.dll_headers_dir.c_str()));
                    return false;
                }
            } else {
                LogError(L"--dll-dir requires a directory path");
                return false;
            }
        }
        else if (arg == L"-o" || arg == L"--output") {
            if (i + 1 < argc) {
                g_config.output_file = argv[++i];
                if (!ValidateOutputPath(g_config.output_file)) {
                    LogError(FormatMessage(L"Invalid output path '%s'", g_config.output_file.c_str()));
                    return false;
                }
            } else {
                LogError(L"--output requires a file path");
                return false;
            }
        }
        else if (arg == L"-l" || arg == L"--log") {
            if (i + 1 < argc) {
                g_config.log_file = argv[++i];
                if (!ValidateOutputPath(g_config.log_file)) {
                    LogError(FormatMessage(L"Invalid log file path '%s'", g_config.log_file.c_str()));
                    return false;
                }
            } else {
                LogError(L"--log requires a file path");
                return false;
            }
        }
        else if (arg == L"-v" || arg == L"--verbose") {
            g_config.verbose = true;
        }
        else if (arg == L"-h" || arg == L"--help") {
            g_config.help = true;
            return true;
        }
        else if (arg.length() > 0 && arg[0] == L'-') {
            LogError(FormatMessage(L"Unknown option '%s'", arg.c_str()));
            return false;
        }
    }
    
    return true;
}

bool RunBreakpointTracing() {
    ApiEnumWithBp tracer;
    
    if (IS_VERBOSE()) {
        std::wcout << L"\n=== BREAKPOINT TRACING CONFIGURATION ===\n";
        std::wcout << g_config.ToString() << L"\n";
        tracer.PrintIgnoredFunctions();
        std::wcout << L"\n";
    }
    
    bool success = false;
    
    if (!g_config.dll_headers_dir.empty()) {
        int size_needed = WideCharToMultiByte(CP_UTF8, 0, g_config.dll_headers_dir.c_str(), -1, nullptr, 0, nullptr, nullptr);
        std::string headersDir(size_needed - 1, 0);
        WideCharToMultiByte(CP_UTF8, 0, g_config.dll_headers_dir.c_str(), -1, &headersDir[0], size_needed, nullptr, nullptr);
        
        LoadSignatures(headersDir);
        LOG_IF_VERBOSE(FormatMessage(L"Loaded signatures from: %s", g_config.dll_headers_dir.c_str()));
    }
    
    if (!g_config.output_file.empty()) {
        if (!OpenOutputFile(g_config.output_file)) {
            LogError(FormatMessage(L"Failed to open output file: %s", g_config.output_file.c_str()));
            return false;
        }
        LOG_IF_VERBOSE(FormatMessage(L"Opened output file: %s", g_config.output_file.c_str()));
    }
    
    if (g_config.attach_mode) {
        g_current_pid = g_config.pid;
        success = tracer.AttachToProcess(g_config.pid);
    } else {
        std::wstring executableCmd = g_config.executable_path + L" " + g_config.extra_args;
        success = tracer.CreateAndAttachProcess(g_config.executable_path.c_str(), executableCmd.c_str());
    }
    
    if (!success) {
        LogError(L"Failed to attach to process");
        return false;
    }
    
    g_tracing_active = true;
    
    LogMessage(FormatMessage(L"Starting API tracing (with %lu functions ignored)...", 
                            tracer.GetIgnoredFunctionCount()));
    
    tracer.StartTracing();
    
    return true;
}

bool RunDynamoRIOTracer(wchar_t* argv[]) {
    LOG_IF_VERBOSE(L"Starting DynamoRIO tracing...");
    
    std::filesystem::path exePath(argv[0]);
    exePath = exePath.parent_path();
    std::filesystem::path batPath = exePath / L"tracer_dynamorio.bat";

    if (!std::filesystem::exists(batPath)) {
        LogMessage(L"DynamoRIO tracer not found.");
        return false;
    }
    
    std::filesystem::path analyzerpath = exePath / "instruction_analyzer.exe";
    if (!std::filesystem::exists(analyzerpath)) {
        LogError(L"Failed to find instruction analyzer.");
        return false;
    }
    
    std::wostringstream command;
    command << batPath.wstring() << L" \"" << g_config.executable_path << L"\"";
    command << L" \"" << g_config.extra_args << L"\"";
    
    std::wstring full_command = command.str();
    
    LOG_IF_VERBOSE(FormatMessage(L"DynamoRIO command: %s", full_command.c_str()));
    
    LogMessage(L"\n=== STEP 1: DynamoRIO Instruction Tracing ===");
    LogMessage(FormatMessage(L"Command: %s", full_command.c_str()));
    LogMessage(L"This will generate:");
    LogMessage(L"  - instructions.log (raw instruction trace)");
    LogMessage(L"  - all_modules_functions.log (module exports)");
    
    g_tracing_active = true;
    
    int trace_result = _wsystem(full_command.c_str());
    
    CHECK_TIMEOUT();
    
    if (trace_result != 0) {
        LogError(FormatMessage(L"DynamoRIO tracing failed with exit code: %d", trace_result));
        return false;
    }
    
    LogMessage(L"\n=== STEP 2: Analyzing Instruction Trace ===");
    
    if (!std::filesystem::exists("instructions.log")) {
        LogError(L"instructions.log not found after tracing!");
        return false;
    }
    
    if (!std::filesystem::exists("all_modules_functions.log")) {
        LogError(L"all_modules_functions.log not found after tracing!");
        return false;
    }
    
    auto instr_size = std::filesystem::file_size("instructions.log");
    auto modules_size = std::filesystem::file_size("all_modules_functions.log");
    
    LogMessage(L"DynamoRIO tracing completed successfully!");
    LogMessage(FormatMessage(L"  - instructions.log: %llu bytes", instr_size));
    LogMessage(FormatMessage(L"  - all_modules_functions.log: %llu bytes", modules_size));
    
    LogMessage(L"Starting automatic analysis...");
    
    std::wostringstream analyzerpathcmd;
    std::wstring analyzercommand;
    analyzerpathcmd << analyzerpath.wstring();
    analyzercommand = analyzerpathcmd.str();

    int analyze_result = _wsystem(analyzercommand.c_str());
    
    if (analyze_result == 0) {
        LogMessage(L"\n=== ANALYSIS COMPLETE ===");
        
        if (std::filesystem::exists("api_calls_detected.log")) {
            auto api_size = std::filesystem::file_size("api_calls_detected.log");
            LogMessage(L"✓ API calls analysis completed successfully!");
            LogMessage(FormatMessage(L"✓ Results saved to: api_calls_detected.log (%llu bytes)", api_size));
            
            std::ifstream api_file("api_calls_detected.log");
            if (api_file.is_open()) {
                std::string line;
                int api_count = 0;
                while (std::getline(api_file, line)) {
                    if (line.find("=== API CALL DETECTED ===") != std::string::npos) {
                        api_count++;
                        g_api_call_count++;
                    }
                }
                api_file.close();
                LogMessage(FormatMessage(L"✓ Detected %d API calls from exe to DLLs", api_count));
            }
        } else {
            LogMessage(L"Warning: api_calls_detected.log not created");
        }
        
        LogMessage(L"\n=== FINAL RESULTS ===");
        LogMessage(L"Raw data files:");
        LogMessage(L"  - instructions.log (all instructions)");
        LogMessage(L"  - all_modules_functions.log (function exports)");
        LogMessage(L"Analyzed results:");
        LogMessage(L"  - api_calls_detected.log (filtered API calls)");
        
        PrintStatistics();
        
        return true;
    } else {
        LogError(FormatMessage(L"Instruction analysis failed with exit code: %d", analyze_result));
        LogMessage(L"However, raw trace files are available:");
        LogMessage(L"  - instructions.log");
        LogMessage(L"  - all_modules_functions.log");
        LogMessage(L"You can manually run: instruction_analyzer.exe");
        return false;
    }
}

int InteractiveMode(wchar_t* argv[]) {
    std::wcout << L"==================== API TRACER ====================\n";
    std::wcout << L"Choose tracing method:\n";
    std::wcout << L"1) API tracing using breakpoints\n";
    std::wcout << L"2) Advanced instruction tracing using DynamoRIO + Auto Analysis\n";
    std::wcout << L"I choose: ";
   
    bool success = false;

    std::wstring choice;
    std::wcin >> choice;
   
    g_config.choice = _wtoi(choice.c_str());
    
    if (g_config.choice == 1) {
        success = RunBreakpointTracing();
        
    } else if (g_config.choice == 2) {
        success = RunDynamoRIOTracer(argv);
        
    } else {
        std::wcout << L"Invalid choice. Please select 1 or 2.\n";
        return 1;
    }

    g_tracing_active = false;
    FlushAllFiles();
    CleanupGlobals();
    
    return success ? 0 : 1;
}

int wmain(int argc, wchar_t* argv[]) {
    if (!InitializeGlobals()) {
        std::wcerr << L"Failed to initialize global system\n";
        return 1;
    }
    
    if (!ParseArguments(argc, argv)) {
        std::wcerr << L"\nUse --help for usage information.\n";
        CleanupGlobals();
        return 1;
    }
    
    if (g_config.help) {
        ShowHelp(argv[0]);
        CleanupGlobals();
        return 0;
    }
    
    if (!g_config.log_file.empty()) {
        if (!OpenLogFile(g_config.log_file)) {
            LogError(FormatMessage(L"Failed to open log file: %s", g_config.log_file.c_str()));
            CleanupGlobals();
            return 1;
        }
        LOG_IF_VERBOSE(FormatMessage(L"Opened log file: %s", g_config.log_file.c_str()));
    }
    
    if (g_config.choice == 0) {
        int result = InteractiveMode(argv);
        CleanupGlobals();
        return result;
    }
    
    if (!g_config.IsValid()) {
        LogError(L"Invalid configuration");
        if (IS_VERBOSE()) {
            std::wcerr << g_config.ToString();
        }
        std::wcerr << L"\nUse --help for usage information.\n";
        CleanupGlobals();
        return 1;
    }
    
    LOG_IF_VERBOSE(L"Configuration validated successfully");
    LOG_IF_VERBOSE(g_config.ToString());
    
    bool success = false;
    
    switch (g_config.choice) {
        case 1:
            success = RunBreakpointTracing();
            break;
            
        case 2:
            success = RunDynamoRIOTracer(argv);
            break;
            
        case 3:
            LogError(L"Other tracing methods not implemented yet.");
            break;
            
        default:
            LogError(FormatMessage(L"Invalid choice: %d", g_config.choice));
            break;
    }
    
    g_tracing_active = false;
    FlushAllFiles();
    CleanupGlobals();
    
    return success ? 0 : 1;
}