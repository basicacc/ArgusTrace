DWORD GetDeviceDriverBaseNameA(
    [in] LPVOID ImageBase,
    LPSTR lpFilename,
    [in] DWORD nSize
);

BOOL EnumPageFilesA(
    [out] PENUM_PAGE_FILE_CALLBACKA pCallBackRoutine,
    [in] LPVOID pContext
);

DWORD GetModuleFileNameExA(
    [in] HANDLE hProcess,
    [in, optional] HMODULE hModule,
    [out] LPSTR lpFilename,
    [in] DWORD nSize
);

BOOL GetPerformanceInfo(
    [out] PPERFORMANCE_INFORMATION pPerformanceInformation,
    [in] DWORD cb
);

DWORD GetDeviceDriverFileNameW(
    [in] LPVOID ImageBase,
    [out] LPWSTR lpFilename,
    [in] DWORD nSize
);

BOOL EnumProcessModules(
    [in] HANDLE hProcess,
    [out] HMODULE *lphModule,
    [in] DWORD cb,
    [out] LPDWORD lpcbNeeded
);

DWORD GetProcessImageFileNameA(
    [in] HANDLE hProcess,
    [out] LPSTR lpImageFileName,
    [in] DWORD nSize
);

BOOL InitializeProcessForWsWatch(
    [in] HANDLE hProcess
);

BOOL QueryWorkingSetEx(
    [in] HANDLE hProcess,
    [in, out] PVOID pv,
    [in] DWORD cb
);

BOOL EnumPageFilesW(
    [out] PENUM_PAGE_FILE_CALLBACKW pCallBackRoutine,
    [in] LPVOID pContext
);

BOOL GetWsChangesEx(
    [in] HANDLE hProcess,
    [out] PPSAPI_WS_WATCH_INFORMATION_EX lpWatchInfoEx,
    [in, out] PDWORD cb
);

DWORD GetDeviceDriverBaseNameW(
    [in] LPVOID ImageBase,
    [out] LPWSTR lpBaseName,
    [in] DWORD nSize
);

BOOL EnumProcesses(
    [out] DWORD *lpidProcess,
    [in] DWORD cb,
    [out] LPDWORD lpcbNeeded
);

DWORD GetMappedFileNameW(
    [in] HANDLE hProcess,
    [in] LPVOID lpv,
    [out] LPWSTR lpFilename,
    [in] DWORD nSize
);

BOOL EnumDeviceDrivers(
    [out] LPVOID *lpImageBase,
    [in] DWORD cb,
    [out] LPDWORD lpcbNeeded
);

BOOL QueryWorkingSet(
    [in] HANDLE hProcess,
    [out] PVOID pv,
    [in] DWORD cb
);

BOOL GetModuleInformation(
    [in] HANDLE hProcess,
    [in] HMODULE hModule,
    [out] LPMODULEINFO lpmodinfo,
    [in] DWORD cb
);

DWORD GetProcessImageFileNameW(
    [in] HANDLE hProcess,
    [out] LPWSTR lpImageFileName,
    [in] DWORD nSize
);

DWORD GetModuleBaseNameA(
    [in] HANDLE hProcess,
    [in, optional] HMODULE hModule,
    [out] LPSTR lpBaseName,
    [in] DWORD nSize
);

BOOL EnumProcessModulesEx(
    [in] HANDLE hProcess,
    [out] HMODULE *lphModule,
    [in] DWORD cb,
    [out] LPDWORD lpcbNeeded,
    [in] DWORD dwFilterFlag
);

BOOL EmptyWorkingSet(
    [in] HANDLE hProcess
);

BOOL GetProcessMemoryInfo(
    [in] HANDLE Process,
    [out] PPROCESS_MEMORY_COUNTERS ppsmemCounters,
    [in] DWORD cb
);

DWORD GetModuleFileNameExW(
    [in] HANDLE hProcess,
    [in, optional] HMODULE hModule,
    [out] LPWSTR lpFilename,
    [in] DWORD nSize
);

DWORD GetModuleBaseNameW(
    [in] HANDLE hProcess,
    [in, optional] HMODULE hModule,
    [out] LPWSTR lpBaseName,
    [in] DWORD nSize
);

DWORD GetDeviceDriverFileNameA(
    [in] LPVOID ImageBase,
    [out] LPSTR lpFilename,
    [in] DWORD nSize
);

DWORD GetMappedFileNameA(
    [in] HANDLE hProcess,
    [in] LPVOID lpv,
    [out] LPSTR lpFilename,
    [in] DWORD nSize
);

BOOL GetWsChanges(
    [in] HANDLE hProcess,
    [out] PPSAPI_WS_WATCH_INFORMATION lpWatchInfo,
    [in] DWORD cb
);

