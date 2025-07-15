BOOL SetWaitableTimerEx(
    [in] HANDLE hTimer,
    [in] const LARGE_INTEGER *lpDueTime,
    [in] LONG lPeriod,
    [in] PTIMERAPCROUTINE pfnCompletionRoutine,
    [in] LPVOID lpArgToCompletionRoutine,
    [in] PREASON_CONTEXT WakeContext,
    [in] ULONG TolerableDelay
);

BOOL SetWaitableTimer(
    [in] HANDLE hTimer,
    [in] const LARGE_INTEGER *lpDueTime,
    [in] LONG lPeriod,
    [in, optional] PTIMERAPCROUTINE pfnCompletionRoutine,
    [in, optional] LPVOID lpArgToCompletionRoutine,
    [in] BOOL fResume
);

DWORD WaitForSingleObjectEx(
    [in] HANDLE hHandle,
    [in] DWORD dwMilliseconds,
    [in] BOOL bAlertable
);

BOOL InitializeCriticalSectionEx(
    [out] LPCRITICAL_SECTION lpCriticalSection,
    [in] DWORD dwSpinCount,
    [in] DWORD Flags
);

HANDLE CreateEventA(
    [in, optional] LPSECURITY_ATTRIBUTES lpEventAttributes,
    [in] BOOL bManualReset,
    [in] BOOL bInitialState,
    [in, optional] LPCSTR lpName
);

HANDLE CreateEventW(
    [in, optional] LPSECURITY_ATTRIBUTES lpEventAttributes,
    [in] BOOL bManualReset,
    [in] BOOL bInitialState,
    [in, optional] LPCWSTR lpName
);

void AcquireSRWLockShared(
    [in, out] PSRWLOCK SRWLock
);

BOOL InitOnceExecuteOnce(
    [in, out] PINIT_ONCE InitOnce,
    [in] PINIT_ONCE_FN InitFn,
    [in, optional] PVOID Parameter,
    [in, out, optional] LPVOID *Context
);

BOOLEAN TryAcquireSRWLockShared(
    [in, out] PSRWLOCK SRWLock
);

HANDLE CreateSemaphoreExW(
    [in, optional] LPSECURITY_ATTRIBUTES lpSemaphoreAttributes,
    [in] LONG lInitialCount,
    [in] LONG lMaximumCount,
    [in, optional] LPCWSTR lpName,
    DWORD dwFlags,
    [in] DWORD dwDesiredAccess
);

BOOL InitOnceBeginInitialize(
    [in, out] LPINIT_ONCE lpInitOnce,
    [in] DWORD dwFlags,
    [out] PBOOL fPending,
    [out, optional] LPVOID *lpContext
);

DWORD SetCriticalSectionSpinCount(
    [in, out] LPCRITICAL_SECTION lpCriticalSection,
    [in] DWORD dwSpinCount
);

HANDLE OpenEventA(
    [in] DWORD dwDesiredAccess,
    [in] BOOL bInheritHandle,
    [in] LPCSTR lpName
);

void WakeAllConditionVariable(
    [in, out] PCONDITION_VARIABLE ConditionVariable
);

HANDLE OpenWaitableTimerW(
    [in] DWORD dwDesiredAccess,
    [in] BOOL bInheritHandle,
    [in] LPCWSTR lpTimerName
);

HANDLE OpenSemaphoreW(
    [in] DWORD dwDesiredAccess,
    [in] BOOL bInheritHandle,
    [in] LPCWSTR lpName
);

void Sleep(
    [in] DWORD dwMilliseconds
);

void LeaveCriticalSection(
    [in, out] LPCRITICAL_SECTION lpCriticalSection
);

BOOL SleepConditionVariableSRW(
    [in, out] PCONDITION_VARIABLE ConditionVariable,
    [in, out] PSRWLOCK SRWLock,
    [in] DWORD dwMilliseconds,
    [in] ULONG Flags
);

void WakeByAddressSingle(
    [in] PVOID Address
);

BOOL InitializeSynchronizationBarrier(
    [out] LPSYNCHRONIZATION_BARRIER lpBarrier,
    [in] LONG lTotalThreads,
    [in] LONG lSpinCount
);

void InitializeConditionVariable(
    [out] PCONDITION_VARIABLE ConditionVariable
);

HANDLE CreateWaitableTimerExW(
    [in, optional] LPSECURITY_ATTRIBUTES lpTimerAttributes,
    [in, optional] LPCWSTR lpTimerName,
    [in] DWORD dwFlags,
    [in] DWORD dwDesiredAccess
);

void EnterCriticalSection(
    [in, out] LPCRITICAL_SECTION lpCriticalSection
);

DWORD SleepEx(
    [in] DWORD dwMilliseconds,
    [in] BOOL bAlertable
);

void AcquireSRWLockExclusive(
    [in, out] PSRWLOCK SRWLock
);

BOOL ResetEvent(
    [in] HANDLE hEvent
);

DWORD WaitForMultipleObjectsEx(
    [in] DWORD nCount,
    [in] const HANDLE *lpHandles,
    [in] BOOL bWaitAll,
    [in] DWORD dwMilliseconds,
    [in] BOOL bAlertable
);

BOOL InitOnceComplete(
    [in, out] LPINIT_ONCE lpInitOnce,
    [in] DWORD dwFlags,
    [in, optional] LPVOID lpContext
);

HANDLE CreateEventExW(
    [in, optional] LPSECURITY_ATTRIBUTES lpEventAttributes,
    [in, optional] LPCWSTR lpName,
    [in] DWORD dwFlags,
    [in] DWORD dwDesiredAccess
);

DWORD WaitForSingleObject(
    [in] HANDLE hHandle,
    [in] DWORD dwMilliseconds
);

HANDLE CreateMutexExA(
    [in, optional] LPSECURITY_ATTRIBUTES lpMutexAttributes,
    [in, optional] LPCSTR lpName,
    [in] DWORD dwFlags,
    [in] DWORD dwDesiredAccess
);

BOOL InitializeCriticalSectionAndSpinCount(
    [out] LPCRITICAL_SECTION lpCriticalSection,
    [in] DWORD dwSpinCount
);

BOOLEAN TryAcquireSRWLockExclusive(
    [in, out] PSRWLOCK SRWLock
);

HANDLE CreateMutexW(
    [in, optional] LPSECURITY_ATTRIBUTES lpMutexAttributes,
    [in] BOOL bInitialOwner,
    [in, optional] LPCWSTR lpName
);

DWORD SignalObjectAndWait(
    [in] HANDLE hObjectToSignal,
    [in] HANDLE hObjectToWaitOn,
    [in] DWORD dwMilliseconds,
    [in] BOOL bAlertable
);

BOOL DeleteSynchronizationBarrier(
    [in, out] LPSYNCHRONIZATION_BARRIER lpBarrier
);

BOOL SleepConditionVariableCS(
    [in, out] PCONDITION_VARIABLE ConditionVariable,
    [in, out] PCRITICAL_SECTION CriticalSection,
    [in] DWORD dwMilliseconds
);

HANDLE CreateWaitableTimerW(
    [in, optional] LPSECURITY_ATTRIBUTES lpTimerAttributes,
    [in] BOOL bManualReset,
    [in, optional] LPCWSTR lpTimerName
);

HANDLE OpenEventW(
    [in] DWORD dwDesiredAccess,
    [in] BOOL bInheritHandle,
    [in] LPCWSTR lpName
);

void ReleaseSRWLockExclusive(
    [in, out] PSRWLOCK SRWLock
);

DWORD WaitForMultipleObjects(
    [in] DWORD nCount,
    [in] const HANDLE *lpHandles,
    [in] BOOL bWaitAll,
    [in] DWORD dwMilliseconds
);

HANDLE CreateMutexExW(
    [in, optional] LPSECURITY_ATTRIBUTES lpMutexAttributes,
    [in, optional] LPCWSTR lpName,
    [in] DWORD dwFlags,
    [in] DWORD dwDesiredAccess
);

HANDLE OpenMutexW(
    [in] DWORD dwDesiredAccess,
    [in] BOOL bInheritHandle,
    [in] LPCWSTR lpName
);

HANDLE CreateSemaphoreW(
    [in, optional] LPSECURITY_ATTRIBUTES lpSemaphoreAttributes,
    [in] LONG lInitialCount,
    [in] LONG lMaximumCount,
    [in, optional] LPCWSTR lpName
);

BOOL CancelWaitableTimer(
    [in] HANDLE hTimer
);

BOOL TryEnterCriticalSection(
    [in, out] LPCRITICAL_SECTION lpCriticalSection
);

HANDLE CreateMutexA(
    [in, optional] LPSECURITY_ATTRIBUTES lpMutexAttributes,
    [in] BOOL bInitialOwner,
    [in, optional] LPCSTR lpName
);

void WakeByAddressAll(
    [in] PVOID Address
);

HANDLE CreateEventExA(
    [in, optional] LPSECURITY_ATTRIBUTES lpEventAttributes,
    [in, optional] LPCSTR lpName,
    [in] DWORD dwFlags,
    [in] DWORD dwDesiredAccess
);

void WakeConditionVariable(
    [in, out] PCONDITION_VARIABLE ConditionVariable
);

BOOL EnterSynchronizationBarrier(
    [in, out] LPSYNCHRONIZATION_BARRIER lpBarrier,
    [in] DWORD dwFlags
);

BOOL SetEvent(
    [in] HANDLE hEvent
);

BOOL ReleaseMutex(
    [in] HANDLE hMutex
);

void DeleteCriticalSection(
    [in, out] LPCRITICAL_SECTION lpCriticalSection
);

void InitializeCriticalSection(
    [out] LPCRITICAL_SECTION lpCriticalSection
);

void ReleaseSRWLockShared(
    [in, out] PSRWLOCK SRWLock
);

void InitializeSRWLock(
    [out] PSRWLOCK SRWLock
);

BOOL ReleaseSemaphore(
    [in] HANDLE hSemaphore,
    [in] LONG lReleaseCount,
    [out, optional] LPLONG lpPreviousCount
);

BOOL WaitOnAddress(
    [in] volatile VOID *Address,
    [in] PVOID CompareAddress,
    [in] SIZE_T AddressSize,
    [in, optional] DWORD dwMilliseconds
);

