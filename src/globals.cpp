#include <windows.h>
#include <iostream>
#include <filesystem>
#include <sstream>
#include <cstdarg>
#include <map>
#include "headers/globals.h"

// Just the globals we need that aren't already elsewhere
TracerConfig g_config;
unsigned long g_api_call_count = 0;
unsigned long g_current_pid = 0;
bool g_tracing_active = false;

// Keep these internal to this file
static unsigned long g_start_time = 0;
static void* g_log_file_handle = (void*)INVALID_HANDLE_VALUE;
static void* g_output_file_handle = (void*)INVALID_HANDLE_VALUE;

// TracerConfig methods
bool TracerConfig::IsValid() const {
    if (choice < 1 || choice > 3) return false;
    
    if (choice == 1 || choice == 2) {
        if (attach_mode) {
            return pid > 0;
        } else {
            return !executable_path.empty() && std::filesystem::exists(executable_path);
        }
    }
    
    return true;
}

std::wstring TracerConfig::ToString() const {
    std::wostringstream oss;
    oss << L"TracerConfig:\n";
    oss << L"  Choice: " << choice << L"\n";
    oss << L"  Executable: " << executable_path << L"\n";
    oss << L"  PID: " << pid << L"\n";
    oss << L"  Attach Mode: " << (attach_mode ? L"Yes" : L"No") << L"\n";
    oss << L"  Verbose: " << (verbose ? L"Yes" : L"No") << L"\n";
    return oss.str();
}

void TracerConfig::Reset() {
    *this = TracerConfig();
}

TracerConfig GetDefaultConfig() {
    TracerConfig config;
    config.choice = 0;
    config.verbose = false;
    config.trace_level = DEFAULT_TRACE_LEVEL;
    config.timeout_ms = 0;
    config.max_calls = 0;
    config.filter_system_calls = true;
    config.save_raw_trace = true;
    config.analyze_automatically = true;
    return config;
}

bool InitializeGlobals() {
    g_start_time = GetTickCount();
    g_config = GetDefaultConfig();
    return true;
}

void CleanupGlobals() {
    CloseLogFile();
    CloseOutputFile();
    g_tracing_active = false;
    g_api_call_count = 0;
}

void UpdateLegacyGlobals(const TracerConfig& config) {
    // For backward compatibility with existing code
    // You can set your existing global variables here if needed
}

std::wstring FormatMessage(const wchar_t* format, ...) {
    va_list args;
    va_start(args, format);
    
    int size = _vscwprintf(format, args) + 1;
    std::vector<wchar_t> buffer(size);
    vswprintf_s(buffer.data(), size, format, args);
    
    va_end(args);
    return std::wstring(buffer.data());
}

void LogError(const std::wstring& error) {
    std::wstring timestamp = GetTimestamp();
    std::wstring formatted_error = L"[" + timestamp + L"] ERROR: " + error + L"\n";
    std::wcerr << formatted_error;
}

void LogMessage(const std::wstring& message, int level) {
    if (IS_SILENT() || level > TRACE_LEVEL()) return;
    
    std::wstring timestamp = GetTimestamp();
    std::wstring formatted_message = L"[" + timestamp + L"] " + message + L"\n";
    std::wcout << formatted_message;
}

void LogVerbose(const std::wstring& message) {
    if (IS_VERBOSE()) {
        LogMessage(L"[VERBOSE] " + message, 2);
    }
}

bool OpenLogFile(const std::wstring& filename) {
    CloseLogFile();
    g_log_file_handle = CreateFileW(filename.c_str(), GENERIC_WRITE, FILE_SHARE_READ, nullptr, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);
    return g_log_file_handle != (void*)INVALID_HANDLE_VALUE;
}

bool OpenOutputFile(const std::wstring& filename) {
    CloseOutputFile();
    g_output_file_handle = CreateFileW(filename.c_str(), GENERIC_WRITE, FILE_SHARE_READ, nullptr, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);
    return g_output_file_handle != (void*)INVALID_HANDLE_VALUE;
}

void CloseLogFile() {
    if (g_log_file_handle != (void*)INVALID_HANDLE_VALUE) {
        CloseHandle(g_log_file_handle);
        g_log_file_handle = (void*)INVALID_HANDLE_VALUE;
    }
}

void CloseOutputFile() {
    if (g_output_file_handle != (void*)INVALID_HANDLE_VALUE) {
        CloseHandle(g_output_file_handle);
        g_output_file_handle = (void*)INVALID_HANDLE_VALUE;
    }
}

void FlushAllFiles() {
    if (g_log_file_handle != (void*)INVALID_HANDLE_VALUE) {
        FlushFileBuffers(g_log_file_handle);
    }
    if (g_output_file_handle != (void*)INVALID_HANDLE_VALUE) {
        FlushFileBuffers(g_output_file_handle);
    }
}

bool ValidatePid(unsigned long pid) {
    if (pid == 0) return false;
    HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION, FALSE, pid);
    if (hProcess == nullptr) return false;
    
    DWORD exitCode;
    bool running = GetExitCodeProcess(hProcess, &exitCode) && exitCode == STILL_ACTIVE;
    CloseHandle(hProcess);
    return running;
}

bool ValidateDllHeadersDir(const std::wstring& path) {
    return !path.empty() && std::filesystem::exists(path) && std::filesystem::is_directory(path);
}

bool ValidateOutputPath(const std::wstring& path) {
    if (path.empty()) return false;
    auto parent_path = std::filesystem::path(path).parent_path();
    return parent_path.empty() || std::filesystem::exists(parent_path);
}

unsigned long GetElapsedTime() {
    return GetTickCount() - g_start_time;
}

std::wstring GetTimestamp() {
    SYSTEMTIME st;
    GetLocalTime(&st);
    
    wchar_t buffer[32];
    swprintf_s(buffer, L"%02d:%02d:%02d.%03d", st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);
    return std::wstring(buffer);
}

bool IsTimeoutReached() {
    return g_config.timeout_ms > 0 && GetElapsedTime() >= g_config.timeout_ms;
}

void PrintStatistics() {
    if (IS_SILENT()) return;
    
    std::wcout << L"\n=== TRACING STATISTICS ===\n";
    std::wcout << L"Total API calls: " << g_api_call_count << L"\n";
    std::wcout << L"Elapsed time: " << GetElapsedTime() << L" ms\n";
}