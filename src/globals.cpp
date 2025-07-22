#include <windows.h>
#include <iostream>
#include <filesystem>
#include <sstream>
#include <cstdarg>
#include <map>
#include "headers/globals.h"

TracerConfig g_config;
unsigned long g_api_call_count = 0;
unsigned long g_current_pid = 0;
bool g_tracing_active = false;

static unsigned long g_start_time = 0;
static HANDLE g_log_file_handle = INVALID_HANDLE_VALUE;
static HANDLE g_output_file_handle = INVALID_HANDLE_VALUE;

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

std::wstring FormatMessage(const wchar_t* format, ...) {
    va_list args;
    va_start(args, format);
   
    int size = _vscwprintf(format, args) + 1;
    std::vector<wchar_t> buffer(size);
    vswprintf_s(buffer.data(), size, format, args);
   
    va_end(args);
    return std::wstring(buffer.data());
}

void WriteToFile(HANDLE fileHandle, const std::wstring& message) {
    if (fileHandle != INVALID_HANDLE_VALUE) {
        int utf8Size = WideCharToMultiByte(CP_UTF8, 0, message.c_str(), -1, nullptr, 0, nullptr, nullptr);
        if (utf8Size > 0) {
            std::vector<char> utf8Buffer(utf8Size);
            WideCharToMultiByte(CP_UTF8, 0, message.c_str(), -1, utf8Buffer.data(), utf8Size, nullptr, nullptr);
           
            DWORD bytesWritten;
            WriteFile(fileHandle, utf8Buffer.data(), utf8Size - 1, &bytesWritten, nullptr);
            FlushFileBuffers(fileHandle);
        }
    }
}

void LogError(const std::wstring& error) {
    std::wstring timestamp = GetTimestamp();
    std::wstring formatted_error = L"[" + timestamp + L"] ERROR: " + error + L"\n";
   
    std::wcerr << formatted_error;
    WriteToFile(g_log_file_handle, formatted_error);
}

void LogMessage(const std::wstring& message, int level) {
    if (!IS_VERBOSE()) return;
   
    std::wstring timestamp = GetTimestamp();
    std::wstring formatted_message = L"[" + timestamp + L"] " + message + L"\n";
   
    std::wcout << formatted_message;
    WriteToFile(g_log_file_handle, formatted_message);
}

void LogVerbose(const std::wstring& message) {
    if (IS_VERBOSE()) {
        std::wstring timestamp = GetTimestamp();
        std::wstring formatted_message = L"[" + timestamp + L"] [VERBOSE] " + message + L"\n";
       
        std::wcout << formatted_message;
        WriteToFile(g_log_file_handle, formatted_message);
        WriteToFile(g_output_file_handle, formatted_message);
    }
}

void WriteApiCall(const std::wstring& apiCall) {
    std::wcout << apiCall;
    WriteToFile(g_output_file_handle, apiCall);
}

bool OpenLogFile(const std::wstring& filename) {
    CloseLogFile();
    g_log_file_handle = CreateFileW(filename.c_str(), GENERIC_WRITE, FILE_SHARE_READ, nullptr, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);
    bool success = g_log_file_handle != INVALID_HANDLE_VALUE;
   
    if (success) {
        std::wstring header = L"=== API TRACER LOG FILE ===\n";
        header += L"Started at: " + GetTimestamp() + L"\n\n";
        WriteToFile(g_log_file_handle, header);
    }
   
    return success;
}

void CloseLogFile() {
    if (g_log_file_handle != INVALID_HANDLE_VALUE) {
        std::wstring footer = L"\n=== LOG FILE CLOSED ===\n";
        footer += L"Ended at: " + GetTimestamp() + L"\n";
        footer += L"Total API calls: " + std::to_wstring(g_api_call_count) + L"\n";
        WriteToFile(g_log_file_handle, footer);
       
        CloseHandle(g_log_file_handle);
        g_log_file_handle = INVALID_HANDLE_VALUE;
    }
}

bool OpenOutputFile(const std::wstring& filename) {
    CloseOutputFile();
    g_output_file_handle = CreateFileW(filename.c_str(), GENERIC_WRITE, FILE_SHARE_READ, nullptr, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);
    bool success = g_output_file_handle != INVALID_HANDLE_VALUE;
   
    if (success) {
        std::wstring header = L"=== API TRACER OUTPUT ===\n";
        header += L"Started at: " + GetTimestamp() + L"\n";
        header += L"Process ID: " + std::to_wstring(g_current_pid) + L"\n\n";
        WriteToFile(g_output_file_handle, header);
    }
   
    return success;
}

void CloseOutputFile() {
    if (g_output_file_handle != INVALID_HANDLE_VALUE) {
        std::wstring footer = L"\n=== OUTPUT FILE CLOSED ===\n";
        footer += L"Ended at: " + GetTimestamp() + L"\n";
        footer += L"Total API calls: " + std::to_wstring(g_api_call_count) + L"\n";
        WriteToFile(g_output_file_handle, footer);
       
        CloseHandle(g_output_file_handle);
        g_output_file_handle = INVALID_HANDLE_VALUE;
    }
}

void FlushAllFiles() {
    if (g_log_file_handle != INVALID_HANDLE_VALUE) {
        FlushFileBuffers(g_log_file_handle);
    }
    if (g_output_file_handle != INVALID_HANDLE_VALUE) {
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
    if (!IS_VERBOSE()) return;
   
    std::wstring stats = L"\n=== TRACING STATISTICS ===\n";
    stats += L"Total API calls: " + std::to_wstring(g_api_call_count) + L"\n";
    stats += L"Elapsed time: " + std::to_wstring(GetElapsedTime()) + L" ms\n";
   
    std::wcout << stats;
    WriteToFile(g_log_file_handle, stats);
}