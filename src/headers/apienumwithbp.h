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

#pragma comment(lib, "psapi.lib")

#include "globals.h"
#include "structs.h"
#include "functions.h"

// External declaration for the global variable
extern std::map<std::string, std::vector<std::string>> functionSignatures;

class ApiEnumWithBp {
private:
    HANDLE hProcess;
    DWORD processId;
    HMODULE hNtdll;
    HMODULE hKernel32;
    std::map<PVOID, Breakpoint> breakpoints;
    std::vector<ApiFunction> tracedFunctions;
    std::set<std::string> ignoredFunctions;
    bool breakpointsReady;
    
    // Private helper methods
    std::string ExtractFunctionName(const std::string& line);
    int CountFunctionParams(const std::string& functionDecl);
    void InitializeTracedFunctions();
    void InitializeIgnoredFunctions();
    bool IsFunctionIgnored(const std::string& functionName);
    void RestoreOriginalByte(PVOID address);
    void RestoreBreakpoint(PVOID address);
    void LogApiCall(const std::string& functionName, PCONTEXT context, DWORD threadId);
    void LogWriteConsoleWWithNames(PCONTEXT context, const std::vector<std::string>& paramNames);
    void LogCreateFileWWithNames(PCONTEXT context, const std::vector<std::string>& paramNames);
    void LogGenericParamsWithNames(PCONTEXT context, int paramCount, const std::vector<std::string>& paramNames);

public:
    ApiEnumWithBp();
    ~ApiEnumWithBp();
    
    // Main interface methods
    bool CreateAndAttachProcess(const std::wstring& executablePath);
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
    HANDLE GetProcessHandle() const { return hProcess; }
    bool AreBreakpointsReady() const { return breakpointsReady; }
    size_t GetTracedFunctionCount() const { return tracedFunctions.size(); }
    size_t GetActiveBreakpointCount() const { return breakpoints.size(); }
    size_t GetIgnoredFunctionCount() const { return ignoredFunctions.size(); }
    
    // Configuration methods
    void AddIgnoredFunction(const std::string& functionName);
    void PrintIgnoredFunctions() const;
};