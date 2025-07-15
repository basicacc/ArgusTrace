// cl.exe /std:c++20 /DUNICODE /D_UNICODE /EHsc src\main.cpp src\apienumwithbp.cpp src\load_signatures.cpp src\globals.cpp /Fe:tracer64.exe
// cl.exe /std:c++20 /DUNICODE /D_UNICODE /EHsc src\main.cpp src\apienumwithbp.cpp src\load_signatures.cpp src\globals.cpp /Fe:tracer32.exe
#include <windows.h>
#include <iostream>
#include <string>
#include <filesystem>
#include <sstream>
#include <fstream>
#include <vector>
#include "headers\apienumwithbp.h"
#include "headers\globals.h"

// Function to display help information
void ShowHelp(const wchar_t* program_name) {
    std::wcout << L"==================== API TRACER HELP ====================\n";
    std::wcout << L"Usage: " << program_name << L" [OPTIONS] [EXECUTABLE] [ARGS...]\n\n";
    
    std::wcout << L"OPTIONS:\n";
    std::wcout << L"  -c, --choice <1|2|3>     Tracing method (1=breakpoints, 2=dynamorio, 3=other)\n";
    std::wcout << L"  -p, --pid <PID>          Attach to existing process ID\n";
    std::wcout << L"  -d, --dll-dir <PATH>     Directory containing DLL headers\n";
    std::wcout << L"  -o, --output <FILE>      Output file for API calls\n";
    std::wcout << L"  -l, --log <FILE>         Log file for verbose output\n";
    std::wcout << L"  -v, --verbose            Enable verbose output\n";
    std::wcout << L"  -s, --silent             Suppress all output except errors\n";
    std::wcout << L"  -r, --real-time          Show API calls in real-time\n";
    std::wcout << L"  -t, --timeout <MS>       Auto-terminate after N milliseconds\n";
    std::wcout << L"  -m, --max-calls <N>      Stop after N API calls\n";
    std::wcout << L"  --ignore-dll <DLL>       Ignore specific DLL (can be used multiple times)\n";
    std::wcout << L"  --focus-dll <DLL>        Only trace specific DLL (can be used multiple times)\n";
    std::wcout << L"  --ignore-api <API>       Ignore specific API (can be used multiple times)\n";
    std::wcout << L"  --focus-api <API>        Only trace specific API (can be used multiple times)\n";
    std::wcout << L"  --no-system-filter       Don't filter common system calls\n";
    std::wcout << L"  --trace-level <1-5>      Set trace verbosity level\n";
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
    std::wcout << L"    " << program_name << L" -c 1 -p 1234 -d dll_headers --verbose\n";
    std::wcout << L"    " << program_name << L" -c 1 --focus-dll kernel32.dll --real-time notepad.exe\n\n";
    
    std::wcout << L"  DynamoRIO tracing:\n";
    std::wcout << L"    " << program_name << L" -c 2 calc.exe\n";
    std::wcout << L"    " << program_name << L" -c 2 -t 30000 -m 1000 app.exe arg1 arg2\n\n";
    
    std::wcout << L"  Advanced filtering:\n";
    std::wcout << L"    " << program_name << L" -c 1 --ignore-dll ntdll.dll --ignore-api GetTickCount notepad.exe\n";
    std::wcout << L"    " << program_name << L" -c 1 --focus-api CreateFile --focus-api WriteFile notepad.exe\n";
}

// Function to parse command line arguments and populate global config
bool ParseArguments(int argc, wchar_t* argv[]) {
    // Reset config to defaults
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
        else if (arg == L"-s" || arg == L"--silent") {
            g_config.silent = true;
        }
        else if (arg == L"-r" || arg == L"--real-time") {
            g_config.real_time = true;
        }
        else if (arg == L"-t" || arg == L"--timeout") {
            if (i + 1 < argc) {
                g_config.timeout_ms = _wtoi(argv[++i]);
                if (g_config.timeout_ms == 0) {
                    LogError(L"Invalid timeout value");
                    return false;
                }
            } else {
                LogError(L"--timeout requires a value in milliseconds");
                return false;
            }
        }
        else if (arg == L"-m" || arg == L"--max-calls") {
            if (i + 1 < argc) {
                g_config.max_calls = _wtoi(argv[++i]);
                if (g_config.max_calls == 0) {
                    LogError(L"Invalid max-calls value");
                    return false;
                }
            } else {
                LogError(L"--max-calls requires a value");
                return false;
            }
        }
        else if (arg == L"--ignore-dll") {
            if (i + 1 < argc) {
                g_config.ignore_dlls.push_back(argv[++i]);
            } else {
                LogError(L"--ignore-dll requires a DLL name");
                return false;
            }
        }
        else if (arg == L"--focus-dll") {
            if (i + 1 < argc) {
                g_config.focus_dlls.push_back(argv[++i]);
            } else {
                LogError(L"--focus-dll requires a DLL name");
                return false;
            }
        }
        else if (arg == L"--ignore-api") {
            if (i + 1 < argc) {
                g_config.ignore_apis.push_back(argv[++i]);
            } else {
                LogError(L"--ignore-api requires an API name");
                return false;
            }
        }
        else if (arg == L"--focus-api") {
            if (i + 1 < argc) {
                g_config.focus_apis.push_back(argv[++i]);
            } else {
                LogError(L"--focus-api requires an API name");
                return false;
            }
        }
        else if (arg == L"--no-system-filter") {
            g_config.filter_system_calls = false;
        }
        else if (arg == L"--trace-level") {
            if (i + 1 < argc) {
                g_config.trace_level = _wtoi(argv[++i]);
                if (g_config.trace_level < 1 || g_config.trace_level > 5) {
                    LogError(L"Trace level must be between 1 and 5");
                    return false;
                }
            } else {
                LogError(L"--trace-level requires a value (1-5)");
                return false;
            }
        }
        else if (arg == L"-h" || arg == L"--help") {
            g_config.help = true;
            return true;
        }
        else if (arg.length() > 0 && arg[0] == L'-') {
            LogError(FormatMessage(L"Unknown option '%s'", arg.c_str()));
            return false;
        }
        else {
            // First non-option argument is the executable (unless we're attaching)
            if (g_config.executable_path.empty() && !g_config.attach_mode) {
                g_config.executable_path = arg;
            } else {
                // Additional arguments for the target process
                g_config.extra_args.push_back(arg);
            }
        }
    }
    
    return true;
}

// Function to run breakpoint tracing using global config
bool RunBreakpointTracing() {
    ApiEnumWithBp tracer;
    
    LOG_IF_VERBOSE(L"Starting breakpoint tracing configuration...");
    
    if (IS_VERBOSE()) {
        std::wcout << L"\n=== BREAKPOINT TRACING CONFIGURATION ===\n";
        std::wcout << g_config.ToString() << L"\n";
    }
    
    // Print ignored functions for debugging
    if (IS_VERBOSE()) {
        tracer.PrintIgnoredFunctions();
        std::wcout << L"\n";
    }
    
    bool success = false;
    
    // Load signatures if directory provided
    if (!g_config.dll_headers_dir.empty()) {
        // Convert wstring to string properly
        int size_needed = WideCharToMultiByte(CP_UTF8, 0, g_config.dll_headers_dir.c_str(), -1, nullptr, 0, nullptr, nullptr);
        std::string headersDir(size_needed - 1, 0);
        WideCharToMultiByte(CP_UTF8, 0, g_config.dll_headers_dir.c_str(), -1, &headersDir[0], size_needed, nullptr, nullptr);
        
        LoadSignatures(headersDir);
        LOG_IF_VERBOSE(FormatMessage(L"Loaded signatures from: %s", g_config.dll_headers_dir.c_str()));
    }
    
    // Open output file if specified
    if (!g_config.output_file.empty()) {
        if (!OpenOutputFile(g_config.output_file)) {
            LogError(FormatMessage(L"Failed to open output file: %s", g_config.output_file.c_str()));
            return false;
        }
        LOG_IF_VERBOSE(FormatMessage(L"Opened output file: %s", g_config.output_file.c_str()));
    }
    
    // Store current PID for tracking
    if (g_config.attach_mode) {
        g_current_pid = g_config.pid;
        success = tracer.AttachToProcess(g_config.pid);
    } else {
        success = tracer.CreateAndAttachProcess(g_config.executable_path.c_str());
        // Get PID from tracer if available
    }
    
    if (!success) {
        LogError(L"Failed to attach to process");
        return false;
    }
    
    // Set tracing active
    g_tracing_active = true;
    
    LogMessage(FormatMessage(L"Starting API tracing (with %lu functions ignored)...", 
                            tracer.GetIgnoredFunctionCount()));
    
    // Start the actual tracing
    tracer.StartTracing();
    
    // Print final statistics
    PrintStatistics();
    
    return true;
}

// Function to run DynamoRIO tracer using global config
bool RunDynamoRIOTracer() {
    LOG_IF_VERBOSE(L"Starting DynamoRIO tracing...");
    
    // Check if DynamoRIO tracer wrapper exists
    if (!std::filesystem::exists("tracer_dynamorio.bat")) {
        LogMessage(L"DynamoRIO tracer not found. Building it now...");
        
        // Run the build script with option 2 (DynamoRIO only)
        int result = _wsystem(L"echo 2 | build_tracer.bat");
        if (result != 0) {
            LogError(L"Build failed. Please run build_tracer.bat manually.");
            return false;
        }
        
        if (!std::filesystem::exists("tracer_dynamorio.bat")) {
            LogError(L"Build completed but tracer_dynamorio.bat not found.");
            return false;
        }
    }
    
    // Check if instruction analyzer exists
    if (!std::filesystem::exists("instruction_analyzer.exe")) {
        LogMessage(L"Instruction analyzer not found. Building it now...");
        
        int result = _wsystem(L"g++ src\\instruction_analyzer.cpp -O2 -o instruction_analyzer.exe");
        if (result != 0) {
            LogError(L"Failed to build instruction analyzer.");
            return false;
        }
        
        LOG_IF_VERBOSE(L"Instruction analyzer built successfully.");
    }
    
    // Build command using the wrapper
    std::wostringstream command;
    command << L"tracer_dynamorio.bat \"" << g_config.executable_path << L"\"";
    
    // Add any additional arguments
    for (const auto& arg : g_config.extra_args) {
        command << L" \"" << arg << L"\"";
    }
    
    std::wstring full_command = command.str();
    
    LOG_IF_VERBOSE(FormatMessage(L"DynamoRIO command: %s", full_command.c_str()));
    
    LogMessage(L"\n=== STEP 1: DynamoRIO Instruction Tracing ===");
    LogMessage(FormatMessage(L"Command: %s", full_command.c_str()));
    LogMessage(L"This will generate:");
    LogMessage(L"  - instructions.log (raw instruction trace)");
    LogMessage(L"  - all_modules_functions.log (module exports)");
    
    // Set tracing active
    g_tracing_active = true;
    
    // Execute the DynamoRIO tracing
    int trace_result = _wsystem(full_command.c_str());
    
    CHECK_TIMEOUT();
    
    if (trace_result != 0) {
        LogError(FormatMessage(L"DynamoRIO tracing failed with exit code: %d", trace_result));
        return false;
    }
    
    LogMessage(L"\n=== STEP 2: Analyzing Instruction Trace ===");
    
    // Check if the required files were created
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
    
    // Run the instruction analyzer
    int analyze_result = _wsystem(L"instruction_analyzer.exe");
    
    if (analyze_result == 0) {
        LogMessage(L"\n=== ANALYSIS COMPLETE ===");
        
        if (std::filesystem::exists("api_calls_detected.log")) {
            auto api_size = std::filesystem::file_size("api_calls_detected.log");
            LogMessage(L"✓ API calls analysis completed successfully!");
            LogMessage(FormatMessage(L"✓ Results saved to: api_calls_detected.log (%llu bytes)", api_size));
            
            // Try to give a quick summary
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
        
        // Print statistics
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

// Interactive mode (original behavior)
int InteractiveMode() {
    std::wcout << L"==================== API TRACER ====================\n";
    std::wcout << L"Choose tracing method:\n";
    std::wcout << L"1) API tracing using breakpoints\n";
    std::wcout << L"2) Advanced instruction tracing using DynamoRIO + Auto Analysis\n";
    std::wcout << L"3) Other tracing method (not implemented yet)\n";
    std::wcout << L"I choose: ";
   
    std::wstring choice;
    std::wcin >> choice;
   
    g_config.choice = _wtoi(choice.c_str());
    
    if (g_config.choice == 1) {
        std::wcout << L"Usage: tracer.exe <executable_path> [dll_headers_dir] [pid]\n";
        std::wcout << L"Examples:\n";
        std::wcout << L"  tracer.exe C:\\Windows\\System32\\notepad.exe\n";
        std::wcout << L"  tracer.exe C:\\Windows\\System32\\notepad.exe dll_headers\n";
        std::wcout << L"  tracer.exe - dll_headers 1234  (attach to existing PID)\n";
        return 1; // Indicate need for more parameters
        
    } else if (g_config.choice == 2) {
        std::wcout << L"Usage for DynamoRIO tracing + Auto Analysis:\n";
        std::wcout << L"  tracer.exe <executable_path> [args...]\n";
        std::wcout << L"\nThis will automatically:\n";
        std::wcout << L"  1. Run DynamoRIO instruction tracing\n";
        std::wcout << L"  2. Analyze the results to find API calls\n";
        std::wcout << L"  3. Generate filtered output\n";
        return 1; // Indicate need for more parameters
        
    } else if (g_config.choice == 3) {
        std::wcout << L"Other tracing methods not implemented yet.\n";
        return 1;
    } else {
        std::wcout << L"Invalid choice. Please select 1, 2, or 3.\n";
        return 1;
    }
}

int wmain(int argc, wchar_t* argv[]) {
    // Initialize global system
    if (!InitializeGlobals()) {
        std::wcerr << L"Failed to initialize global system\n";
        return 1;
    }
    
    // Parse command line arguments
    if (!ParseArguments(argc, argv)) {
        std::wcerr << L"\nUse --help for usage information.\n";
        CleanupGlobals();
        return 1;
    }
    
    // Show help if requested
    if (g_config.help) {
        ShowHelp(argv[0]);
        CleanupGlobals();
        return 0;
    }
    
    // Update legacy globals for backward compatibility
    UpdateLegacyGlobals(g_config);
    
    // Open log file if specified
    if (!g_config.log_file.empty()) {
        if (!OpenLogFile(g_config.log_file)) {
            LogError(FormatMessage(L"Failed to open log file: %s", g_config.log_file.c_str()));
            CleanupGlobals();
            return 1;
        }
        LOG_IF_VERBOSE(FormatMessage(L"Opened log file: %s", g_config.log_file.c_str()));
    }
    
    // If no choice specified, run in interactive mode
    if (g_config.choice == 0) {
        int result = InteractiveMode();
        CleanupGlobals();
        return result;
    }
    
    // Validate configuration
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
    
    // Execute based on choice
    switch (g_config.choice) {
        case 1:
            success = RunBreakpointTracing();
            break;
            
        case 2:
            success = RunDynamoRIOTracer();
            break;
            
        case 3:
            LogError(L"Other tracing methods not implemented yet.");
            break;
            
        default:
            LogError(FormatMessage(L"Invalid choice: %d", g_config.choice));
            break;
    }
    
    // Cleanup and exit
    g_tracing_active = false;
    FlushAllFiles();
    CleanupGlobals();
    
    return success ? 0 : 1;
}