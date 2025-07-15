#ifndef GLOBALS_H
#define GLOBALS_H

#include <string>
#include <vector>

struct TracerConfig {
    int choice = 0;
    std::wstring executable_path;
    std::wstring dll_headers_dir;
    unsigned long pid = 0;
    bool attach_mode = false;
    bool verbose = false;
    bool help = false;
    std::wstring output_file;
    std::wstring log_file;
    int trace_level = 1;
    bool silent = false;
    std::vector<std::wstring> extra_args;
    std::vector<std::wstring> ignore_dlls;
    std::vector<std::wstring> focus_dlls;
    std::vector<std::wstring> ignore_apis;
    std::vector<std::wstring> focus_apis;
    unsigned long timeout_ms = 0;
    unsigned long max_calls = 0;
    bool real_time = false;
    bool filter_system_calls = true;
    bool filter_duplicates = false;
    bool show_return_values = false;
    bool show_call_stack = false;
    bool save_raw_trace = true;
    bool analyze_automatically = true;
    std::wstring dynamorio_options;
    bool hook_child_processes = false;
    bool detailed_parameters = false;
    
    bool IsValid() const;
    std::wstring ToString() const;
    void Reset();
};

// globals that main.cpp needs
extern TracerConfig g_config;

// functions that main.cpp needs
TracerConfig GetDefaultConfig();
bool InitializeGlobals();
void CleanupGlobals();
void UpdateLegacyGlobals(const TracerConfig& config);
std::wstring FormatMessage(const wchar_t* format, ...);
void LogError(const std::wstring& error);
void LogMessage(const std::wstring& message, int level = 1);
void LogVerbose(const std::wstring& message);
bool OpenLogFile(const std::wstring& filename);
bool OpenOutputFile(const std::wstring& filename);
void CloseLogFile();
void CloseOutputFile();
void FlushAllFiles();
bool ValidatePid(unsigned long pid);
bool ValidateDllHeadersDir(const std::wstring& path);
bool ValidateOutputPath(const std::wstring& path);
bool IsTimeoutReached();
void PrintStatistics();
std::wstring GetTimestamp();
unsigned long GetElapsedTime();

// macros
#define IS_VERBOSE() (g_config.verbose)
#define IS_SILENT() (g_config.silent)
#define TRACE_LEVEL() (g_config.trace_level)
#define LOG_IF_VERBOSE(msg) do { if (IS_VERBOSE()) LogVerbose(msg); } while(0)

#define CHECK_TIMEOUT() do { \
    if (g_config.timeout_ms > 0 && IsTimeoutReached()) { \
        LogMessage(L"Timeout reached, stopping trace..."); \
        return false; \
    } \
} while(0)

#define CHECK_MAX_CALLS() do { \
    if (g_config.max_calls > 0 && g_api_call_count >= g_config.max_calls) { \
        LogMessage(FormatMessage(L"Maximum API calls (%lu) reached, stopping trace...", g_config.max_calls)); \
        return false; \
    } \
} while(0)

// Constants
const wchar_t* const DEFAULT_LOG_FILE = L"tracer.log";
const wchar_t* const DEFAULT_OUTPUT_FILE = L"api_trace.txt";
const int DEFAULT_TRACE_LEVEL = 1;

// Some globals that main.cpp and other files need
extern unsigned long g_api_call_count;
extern unsigned long g_current_pid;
extern bool g_tracing_active;

extern std::map<std::string, std::vector<std::string>> functionSignatures;

#endif