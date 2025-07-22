#ifndef GLOBALS_H
#define GLOBALS_H
#include <string>
#include <vector>

struct TracerConfig {
    int choice = 0;
    std::wstring executable_path;
    std::wstring extra_args;
    unsigned long sleep_time = 0;
    std::wstring dll_headers_dir;
    unsigned long pid = 0;
    bool attach_mode = false;
    bool verbose = false;
    bool help = false;
    std::wstring output_file;
    std::wstring log_file;
    int trace_level = -1;
    unsigned long timeout_ms = 0;
    bool filter_system_calls = true;
    std::wstring dynamorio_options;
    bool hook_child_processes = false;
   
    bool IsValid() const;
    std::wstring ToString() const;
    void Reset();
};

extern TracerConfig g_config;
extern unsigned long g_api_call_count;
extern unsigned long g_current_pid;
extern bool g_tracing_active;
extern std::map<std::string, std::vector<std::string>> functionSignatures;

TracerConfig GetDefaultConfig();
bool InitializeGlobals();
void CleanupGlobals();
std::wstring FormatMessage(const wchar_t* format, ...);
void WriteApiCall(const std::wstring& apiCall);
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

#define IS_VERBOSE() (g_config.verbose)
#define LOG_IF_VERBOSE(msg) do { if (IS_VERBOSE()) LogVerbose(msg); } while(0)
#define CHECK_TIMEOUT() do { \
    if (g_config.timeout_ms > 0 && IsTimeoutReached()) { \
        LogMessage(L"Timeout reached, stopping trace..."); \
        return false; \
    } \
} while(0)

const int DEFAULT_TRACE_LEVEL = -1;

#endif