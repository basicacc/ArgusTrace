HANDLE CreateRemoteThread(
    [in] HANDLE hProcess,
    [in] LPSECURITY_ATTRIBUTES lpThreadAttributes,
    [in] SIZE_T dwStackSize,
    [in] LPTHREAD_START_ROUTINE lpStartAddress,
    [in] LPVOID lpParameter,
    [in] DWORD dwCreationFlags,
    [out] LPDWORD lpThreadId
);

BOOL CreateProcessAsUserW(
    [in, optional] HANDLE hToken,
    [in, optional] LPCWSTR lpApplicationName,
    [in, out, optional] LPWSTR lpCommandLine,
    [in, optional] LPSECURITY_ATTRIBUTES lpProcessAttributes,
    [in, optional] LPSECURITY_ATTRIBUTES lpThreadAttributes,
    [in] BOOL bInheritHandles,
    [in] DWORD dwCreationFlags,
    [in, optional] LPVOID lpEnvironment,
    [in, optional] LPCWSTR lpCurrentDirectory,
    [in] LPSTARTUPINFOW lpStartupInfo,
    [out] LPPROCESS_INFORMATION lpProcessInformation
);

DWORD ResumeThread(
    [in] HANDLE hThread
);

BOOL InitializeProcThreadAttributeList(
    [out, optional] LPPROC_THREAD_ATTRIBUTE_LIST lpAttributeList,
    [in] DWORD dwAttributeCount,
    DWORD dwFlags,
    [in, out] PSIZE_T lpSize
);

BOOL GetProcessShutdownParameters(
    [out] LPDWORD lpdwLevel,
    [out] LPDWORD lpdwFlags
);

BOOL GetProcessPriorityBoost(
    [in] HANDLE hProcess,
    [out] PBOOL pDisablePriorityBoost
);

BOOL SetThreadPriority(
    [in] HANDLE hThread,
    [in] int nPriority
);

HANDLE GetCurrentThreadToken();

DWORD GetThreadId(
    [in] HANDLE Thread
);

BOOL GetThreadSelectedCpuSetMasks(
    HANDLE Thread,
    PGROUP_AFFINITY CpuSetMasks,
    USHORT CpuSetMaskCount,
    PUSHORT RequiredMaskCount
);

BOOL SetProcessMitigationPolicy(
    [in] PROCESS_MITIGATION_POLICY MitigationPolicy,
    [in] PVOID lpBuffer,
    [in] SIZE_T dwLength
);

BOOL SetProcessDynamicEnforcedCetCompatibleRanges(
    HANDLE Process,
    USHORT NumberOfRanges,
    PPROCESS_DYNAMIC_ENFORCED_ADDRESS_RANGE Ranges
);

BOOL OpenThreadToken(
    [in] HANDLE ThreadHandle,
    [in] DWORD DesiredAccess,
    [in] BOOL OpenAsSelf,
    [out] PHANDLE TokenHandle
);

HRESULT GetMachineTypeAttributes(
    USHORT Machine,
    MACHINE_ATTRIBUTES *MachineTypeAttributes
);

DWORD TlsAlloc();

HANDLE CreateRemoteThreadEx(
    [in] HANDLE hProcess,
    [in, optional] LPSECURITY_ATTRIBUTES lpThreadAttributes,
    [in] SIZE_T dwStackSize,
    [in] LPTHREAD_START_ROUTINE lpStartAddress,
    [in, optional] LPVOID lpParameter,
    [in] DWORD dwCreationFlags,
    [in, optional] LPPROC_THREAD_ATTRIBUTE_LIST lpAttributeList,
    [out, optional] LPDWORD lpThreadId
);

DWORD GetCurrentProcessorNumber();

BOOL SetThreadStackGuarantee(
    [in, out] PULONG StackSizeInBytes
);

void FlushProcessWriteBuffers();

DWORD SetThreadIdealProcessor(
    [in] HANDLE hThread,
    [in] DWORD dwIdealProcessor
);

BOOL QueryProtectedPolicy(
    [in] LPCGUID PolicyGuid,
    [out] PULONG_PTR PolicyValue
);

void ExitThread(
    [in] DWORD dwExitCode
);

BOOL TerminateProcess(
    [in] HANDLE hProcess,
    [in] UINT uExitCode
);

BOOL GetExitCodeProcess(
    [in] HANDLE hProcess,
    [out] LPDWORD lpExitCode
);

BOOL SetProcessInformation(
    [in] HANDLE hProcess,
    [in] PROCESS_INFORMATION_CLASS ProcessInformationClass,
    LPVOID ProcessInformation,
    [in] DWORD ProcessInformationSize
);

void GetCurrentThreadStackLimits(
    [out] PULONG_PTR LowLimit,
    [out] PULONG_PTR HighLimit
);

HANDLE OpenProcess(
    [in] DWORD dwDesiredAccess,
    [in] BOOL bInheritHandle,
    [in] DWORD dwProcessId
);

BOOL CreateProcessAsUserA(
    [in, optional] HANDLE hToken,
    [in, optional] LPCSTR lpApplicationName,
    [in, out, optional] LPSTR lpCommandLine,
    [in, optional] LPSECURITY_ATTRIBUTES lpProcessAttributes,
    [in, optional] LPSECURITY_ATTRIBUTES lpThreadAttributes,
    [in] BOOL bInheritHandles,
    [in] DWORD dwCreationFlags,
    [in, optional] LPVOID lpEnvironment,
    [in, optional] LPCSTR lpCurrentDirectory,
    [in] LPSTARTUPINFOA lpStartupInfo,
    [out] LPPROCESS_INFORMATION lpProcessInformation
);

void ExitProcess(
    [in] UINT uExitCode
);

BOOL SetProcessPriorityBoost(
    [in] HANDLE hProcess,
    [in] BOOL bDisablePriorityBoost
);

BOOL GetSystemTimes(
    [out, optional] PFILETIME lpIdleTime,
    [out, optional] PFILETIME lpKernelTime,
    [out, optional] PFILETIME lpUserTime
);

void GetStartupInfoW(
    [out] LPSTARTUPINFOW lpStartupInfo
);

BOOL IsProcessCritical(
    [in] HANDLE hProcess,
    [out] PBOOL Critical
);

BOOL ProcessIdToSessionId(
    [in] DWORD dwProcessId,
    [out] DWORD *pSessionId
);

HANDLE CreateThread(
    [in, optional] LPSECURITY_ATTRIBUTES lpThreadAttributes,
    [in] SIZE_T dwStackSize,
    [in] LPTHREAD_START_ROUTINE lpStartAddress,
    [in, optional] __drv_aliasesMem LPVOID lpParameter,
    [in] DWORD dwCreationFlags,
    [out, optional] LPDWORD lpThreadId
);

BOOL SetThreadInformation(
    [in] HANDLE hThread,
    [in] THREAD_INFORMATION_CLASS ThreadInformationClass,
    LPVOID ThreadInformation,
    [in] DWORD ThreadInformationSize
);

HANDLE GetCurrentProcess();

BOOL CreateProcessW(
    [in, optional] LPCWSTR lpApplicationName,
    [in, out, optional] LPWSTR lpCommandLine,
    [in, optional] LPSECURITY_ATTRIBUTES lpProcessAttributes,
    [in, optional] LPSECURITY_ATTRIBUTES lpThreadAttributes,
    [in] BOOL bInheritHandles,
    [in] DWORD dwCreationFlags,
    [in, optional] LPVOID lpEnvironment,
    [in, optional] LPCWSTR lpCurrentDirectory,
    [in] LPSTARTUPINFOW lpStartupInfo,
    [out] LPPROCESS_INFORMATION lpProcessInformation
);

BOOL QueryProcessAffinityUpdateMode(
    [in] HANDLE hProcess,
    [out, optional] LPDWORD lpdwFlags
);

BOOL QueueUserAPC2(
    PAPCFUNC ApcRoutine,
    HANDLE Thread,
    ULONG_PTR Data,
    QUEUE_USER_APC_FLAGS Flags
);

BOOL SetThreadContext(
    [in] HANDLE hThread,
    [in] const CONTEXT *lpContext
);

DWORD GetProcessId(
    [in] HANDLE Process
);

DWORD GetProcessVersion(
    [in] DWORD ProcessId
);

BOOL GetProcessDefaultCpuSetMasks(
    HANDLE Process,
    PGROUP_AFFINITY CpuSetMasks,
    USHORT CpuSetMaskCount,
    PUSHORT RequiredMaskCount
);

BOOL SetThreadIdealProcessorEx(
    [in] HANDLE hThread,
    [in] PPROCESSOR_NUMBER lpIdealProcessor,
    [out, optional] PPROCESSOR_NUMBER lpPreviousIdealProcessor
);

void GetCurrentProcessorNumberEx(
    [out] PPROCESSOR_NUMBER ProcNumber
);

BOOL GetProcessMitigationPolicy(
    [in] HANDLE hProcess,
    [in] PROCESS_MITIGATION_POLICY MitigationPolicy,
    [out] PVOID lpBuffer,
    [in] SIZE_T dwLength
);

HRESULT SetThreadDescription(
    [in] HANDLE hThread,
    [in] PCWSTR lpThreadDescription
);

BOOL TlsSetValue(
    [in] DWORD dwTlsIndex,
    [in, optional] LPVOID lpTlsValue
);

BOOL CreateProcessA(
    [in, optional] LPCSTR lpApplicationName,
    [in, out, optional] LPSTR lpCommandLine,
    [in, optional] LPSECURITY_ATTRIBUTES lpProcessAttributes,
    [in, optional] LPSECURITY_ATTRIBUTES lpThreadAttributes,
    [in] BOOL bInheritHandles,
    [in] DWORD dwCreationFlags,
    [in, optional] LPVOID lpEnvironment,
    [in, optional] LPCSTR lpCurrentDirectory,
    [in] LPSTARTUPINFOA lpStartupInfo,
    [out] LPPROCESS_INFORMATION lpProcessInformation
);

LPVOID TlsGetValue2(
    [in] DWORD dwTlsIndex
);

BOOL SetProcessDefaultCpuSetMasks(
    HANDLE Process,
    PGROUP_AFFINITY CpuSetMasks,
    USHORT CpuSetMaskCount
);

BOOL TlsFree(
    [in] DWORD dwTlsIndex
);

HRESULT GetThreadDescription(
    [in] HANDLE hThread,
    [out] PWSTR *ppszThreadDescription
);

BOOL GetThreadIOPendingFlag(
    [in] HANDLE hThread,
    [in, out] PBOOL lpIOIsPending
);

DWORD GetProcessIdOfThread(
    [in] HANDLE Thread
);

BOOL GetSystemCpuSetInformation(
    PSYSTEM_CPU_SET_INFORMATION Information,
    ULONG BufferLength,
    PULONG ReturnedLength,
    HANDLE Process,
    ULONG Flags
);

BOOL SetPriorityClass(
    [in] HANDLE hProcess,
    [in] DWORD dwPriorityClass
);

BOOL OpenProcessToken(
    [in] HANDLE ProcessHandle,
    [in] DWORD DesiredAccess,
    [out] PHANDLE TokenHandle
);

BOOL GetThreadTimes(
    [in] HANDLE hThread,
    [out] LPFILETIME lpCreationTime,
    [out] LPFILETIME lpExitTime,
    [out] LPFILETIME lpKernelTime,
    [out] LPFILETIME lpUserTime
);

BOOL UpdateProcThreadAttribute(
    [in, out] LPPROC_THREAD_ATTRIBUTE_LIST lpAttributeList,
    [in] DWORD dwFlags,
    [in] DWORD_PTR Attribute,
    [in] PVOID lpValue,
    [in] SIZE_T cbSize,
    [out, optional] PVOID lpPreviousValue,
    [in, optional] PSIZE_T lpReturnSize
);

BOOL SetThreadSelectedCpuSets(
    HANDLE Thread,
    const ULONG *CpuSetIds,
    ULONG CpuSetIdCount
);

BOOL GetExitCodeThread(
    [in] HANDLE hThread,
    [out] LPDWORD lpExitCode
);

DWORD GetCurrentProcessId();

BOOL FlushInstructionCache(
    [in] HANDLE hProcess,
    [in] LPCVOID lpBaseAddress,
    [in] SIZE_T dwSize
);

BOOL GetThreadIdealProcessorEx(
    [in] HANDLE hThread,
    [out] PPROCESSOR_NUMBER lpIdealProcessor
);

BOOL SwitchToThread();

HANDLE OpenThread(
    [in] DWORD dwDesiredAccess,
    [in] BOOL bInheritHandle,
    [in] DWORD dwThreadId
);

BOOL SetThreadToken(
    [in, optional] PHANDLE Thread,
    [in, optional] HANDLE Token
);

BOOL SetThreadSelectedCpuSetMasks(
    HANDLE Thread,
    PGROUP_AFFINITY CpuSetMasks,
    USHORT CpuSetMaskCount
);

BOOL GetThreadInformation(
    [in] HANDLE hThread,
    [in] THREAD_INFORMATION_CLASS ThreadInformationClass,
    LPVOID ThreadInformation,
    [in] DWORD ThreadInformationSize
);

HANDLE GetCurrentProcessToken();

BOOL GetProcessTimes(
    [in] HANDLE hProcess,
    [out] LPFILETIME lpCreationTime,
    [out] LPFILETIME lpExitTime,
    [out] LPFILETIME lpKernelTime,
    [out] LPFILETIME lpUserTime
);

HANDLE GetCurrentThreadEffectiveToken();

BOOL SetProcessDefaultCpuSets(
    HANDLE Process,
    const ULONG *CpuSetIds,
    ULONG CpuSetIdCount
);

BOOL GetProcessHandleCount(
    [in] HANDLE hProcess,
    [in, out] PDWORD pdwHandleCount
);

BOOL IsProcessorFeaturePresent(
    [in] DWORD ProcessorFeature
);

BOOL SetThreadPriorityBoost(
    [in] HANDLE hThread,
    [in] BOOL bDisablePriorityBoost
);

DWORD GetPriorityClass(
    [in] HANDLE hProcess
);

BOOL GetThreadSelectedCpuSets(
    HANDLE Thread,
    PULONG CpuSetIds,
    ULONG CpuSetIdCount,
    PULONG RequiredIdCount
);

BOOL SetProcessShutdownParameters(
    [in] DWORD dwLevel,
    [in] DWORD dwFlags
);

BOOL GetProcessInformation(
    [in] HANDLE hProcess,
    [in] PROCESS_INFORMATION_CLASS ProcessInformationClass,
    LPVOID ProcessInformation,
    [in] DWORD ProcessInformationSize
);

DWORD SuspendThread(
    [in] HANDLE hThread
);

BOOL GetProcessDefaultCpuSets(
    HANDLE Process,
    PULONG CpuSetIds,
    ULONG CpuSetIdCount,
    PULONG RequiredIdCount
);

int GetThreadPriority(
    [in] HANDLE hThread
);

BOOL SetProcessAffinityUpdateMode(
    [in] HANDLE hProcess,
    [in] DWORD dwFlags
);

DWORD GetCurrentThreadId();

void DeleteProcThreadAttributeList(
    [in, out] LPPROC_THREAD_ATTRIBUTE_LIST lpAttributeList
);

BOOL TerminateThread(
    [in, out] HANDLE hThread,
    [in] DWORD dwExitCode
);

BOOL SetProcessDynamicEHContinuationTargets(
    HANDLE Process,
    USHORT NumberOfTargets,
    PPROCESS_DYNAMIC_EH_CONTINUATION_TARGET Targets
);

HANDLE GetCurrentThread();

BOOL SetProtectedPolicy(
    [in] LPCGUID PolicyGuid,
    [in] ULONG_PTR PolicyValue,
    [out] PULONG_PTR OldPolicyValue
);

LPVOID TlsGetValue(
    [in] DWORD dwTlsIndex
);

DWORD QueueUserAPC(
    [in] PAPCFUNC pfnAPC,
    [in] HANDLE hThread,
    [in] ULONG_PTR dwData
);

BOOL GetThreadPriorityBoost(
    [in] HANDLE hThread,
    [out] PBOOL pDisablePriorityBoost
);

BOOL GetThreadContext(
    [in] HANDLE hThread,
    [in, out] LPCONTEXT lpContext
);

