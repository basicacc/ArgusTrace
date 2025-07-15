void DebugBreak();

void OutputDebugStringW(
    [in, optional] LPCWSTR lpOutputString
);

BOOL WaitForDebugEvent(
    [out] LPDEBUG_EVENT lpDebugEvent,
    [in] DWORD dwMilliseconds
);

BOOL ContinueDebugEvent(
    [in] DWORD dwProcessId,
    [in] DWORD dwThreadId,
    [in] DWORD dwContinueStatus
);

void OutputDebugStringA(
    [in, optional] LPCSTR lpOutputString
);

BOOL CheckRemoteDebuggerPresent(
    [in] HANDLE hProcess,
    [in, out] PBOOL pbDebuggerPresent
);

BOOL DebugActiveProcess(
    [in] DWORD dwProcessId
);

BOOL WaitForDebugEventEx(
    [out] LPDEBUG_EVENT lpDebugEvent,
    [in] DWORD dwMilliseconds
);

BOOL DebugActiveProcessStop(
    [in] DWORD dwProcessId
);

BOOL IsDebuggerPresent();

