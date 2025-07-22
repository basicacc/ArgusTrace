#pragma once
#include <windows.h>
#include <winternl.h>
#include <psapi.h>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <iomanip>
#include <fstream>
#include <regex>
#include <algorithm>
#include <tlhelp32.h>
#pragma comment(lib, "psapi.lib")
#include "globals.h"
#include "structs.h"
#include "functions.h"

// External declaration for the global variable
extern std::map<std::string, std::vector<std::string>> functionSignatures;

class ApiEnumWithBp {
private:
    // Configuration structure
    struct Config {
        std::map<std::string, std::string> fileToDllMap;
        std::vector<std::string> filesToProcess;
        std::set<std::string> ignoredFunctions;
    };

    // Structure to uniquely identify breakpoints across processes
    struct BreakpointKey {
        DWORD processId;
        PVOID address;
        
        bool operator<(const BreakpointKey& other) const {
            if (processId != other.processId) {
                return processId < other.processId;
            }
            return address < other.address;
        }
    };

    // Enhanced Breakpoint structure with process ID
    struct Breakpoint {
        PVOID address;
        BYTE originalByte;
        std::string functionName;
        bool isActive;
        bool isSet;
        DWORD processId;  // Track which process this breakpoint belongs to (used for child processes)
        
        Breakpoint() : address(NULL), originalByte(0), isActive(false), isSet(false), processId(0) {}
    };

    // Structure to track information about each process
    struct ProcessInfo {
        HANDLE hProcess;
        DWORD parentProcessId;
        int depth;  // How deep in the process tree (0 = root)
        bool breakpointsReady;
        std::map<std::string, HMODULE> moduleHandles;
        std::vector<DWORD> suspendedThreads;
        
        ProcessInfo() : hProcess(NULL), parentProcessId(0), depth(0), breakpointsReady(false) {}
    };

    // Legacy members (for backward compatibility with root process)
    HANDLE hProcess;
    DWORD processId;
    bool breakpointsReady;
    std::map<std::string, HMODULE> moduleHandles;  // For main process
    std::map<PVOID, Breakpoint> breakpoints;       // For main process
    std::vector<DWORD> suspendedThreads;           // For main process

    // Child process tracking
    DWORD rootProcessId;  // The original root process ID
    std::map<DWORD, ProcessInfo> trackedProcesses;  // Map of PID to process info
    std::map<BreakpointKey, Breakpoint> processBreakpoints;  // Breakpoints indexed by process + address

    // Shared data across all processes
    std::set<std::string> requiredDlls;
    std::vector<ApiFunction> tracedFunctions;
    std::set<std::string> ignoredFunctions;

    // Process hierarchy and logging helpers
    std::wstring GetProcessHierarchyString(DWORD pid);

    std::set<std::string> processedModules;  // For main process
    std::map<DWORD, std::set<std::string>> processedModulesPerProcess;  // For child processes
    
    // Child process management
    void SetupChildProcess(DWORD childPid, DWORD parentPid);
    bool SetupModulesForProcess(DWORD pid);
    bool SetupBreakpointsForProcess(DWORD pid);
    bool SetBreakpointOnFunctionForProcess(const ApiFunction& func, DWORD pid);

    // Helper functions for thread management
    void SuspendProcessThreads();
    void ResumeProcessThreads();
   
    // Configuration loading
    bool LoadConfiguration(const std::string& configPath, Config& config);
   
    // Private helper methods
    std::string ExtractFunctionName(const std::string& line);
    int CountFunctionParams(const std::string& functionDecl);
    void InitializeTracedFunctions();
    void InitializeIgnoredFunctions();
    bool IsFunctionIgnored(const std::string& functionName);
    
    // Breakpoint management (main process)
    void RestoreOriginalByte(PVOID address);
    void RestoreBreakpoint(PVOID address);
    
    // Breakpoint management (child processes)
    void RestoreOriginalByteForProcess(PVOID address, DWORD pid);
    void RestoreBreakpointForProcess(PVOID address, DWORD pid);
    
    // API call logging (main process)
    void LogApiCall(const std::string& functionName, PCONTEXT context, DWORD threadId);
    void LogGenericParamsWithNames(PCONTEXT context, int paramCount, const std::vector<std::string>& paramNames, 
                                   const std::string& functionName, DWORD threadId);
    
    // API call logging (child processes)
    void LogApiCallForProcess(const std::string& functionName, PCONTEXT context, DWORD threadId, DWORD pid);
    void LogGenericParamsWithNamesForProcess(PCONTEXT context, int paramCount, const std::vector<std::string>& paramNames, 
                                             const std::string& functionName, DWORD threadId, DWORD pid);

    bool ShouldTraceProcess(DWORD pid, int depth) const;
    void DebugTraceLevel() const;

    void CheckForNewModulesAndSetBreakpoints();
    void CheckForNewModulesAndSetBreakpointsForProcess(DWORD pid);
   
public:
    ApiEnumWithBp();
    ~ApiEnumWithBp();
   
    // Main interface methods
    bool CreateAndAttachProcess(const std::wstring& executablePath, const std::wstring& executableArgs);
    bool AttachToProcess(DWORD pid);
    bool WaitForModulesAndSetupBreakpoints();
    bool FindAndSetupModules();
    bool SetupBreakpoints();
    bool SetBreakpointOnFunction(const ApiFunction& func);
   
    // Event handling
    void HandleBreakpoint(const DEBUG_EVENT& debugEvent);
    void HandleSingleStep(const DEBUG_EVENT& debugEvent);
    void StartTracing();
    void CleanupBreakpoints();
   
    // Getter methods for inspection
    DWORD GetProcessId() const { return processId; }
    DWORD GetRootProcessId() const { return rootProcessId; }
    HANDLE GetProcessHandle() const { return hProcess; }
    bool AreBreakpointsReady() const { return breakpointsReady; }
    size_t GetTracedFunctionCount() const { return tracedFunctions.size(); }
    size_t GetActiveBreakpointCount() const { return processBreakpoints.size(); }
    size_t GetIgnoredFunctionCount() const { return ignoredFunctions.size(); }
    size_t GetTrackedProcessCount() const { return trackedProcesses.size(); }
    
    // Process-specific getter methods
    bool IsProcessTracked(DWORD pid) const { return trackedProcesses.find(pid) != trackedProcesses.end(); }
    HANDLE GetProcessHandle(DWORD pid) const;
    bool AreBreakpointsReady(DWORD pid) const;
    int GetProcessDepth(DWORD pid) const;
    DWORD GetParentProcessId(DWORD pid) const;
   
    // Configuration methods
    void AddIgnoredFunction(const std::string& functionName);
    void PrintIgnoredFunctions() const;
    
    // Process information methods
    void PrintTrackedProcesses() const;
    std::vector<DWORD> GetTrackedProcessIds() const;
    std::vector<DWORD> GetChildProcessIds(DWORD parentPid) const;
};