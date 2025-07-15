PTP_WAIT CreateThreadpoolWait(
    [in] PTP_WAIT_CALLBACK pfnwa,
    [in, out, optional] PVOID pv,
    [in, optional] PTP_CALLBACK_ENVIRON pcbe
);

void WaitForThreadpoolTimerCallbacks(
    [in, out] PTP_TIMER pti,
    [in] BOOL fCancelPendingCallbacks
);

BOOL TrySubmitThreadpoolCallback(
    [in] PTP_SIMPLE_CALLBACK pfns,
    [in, out, optional] PVOID pv,
    [in, optional] PTP_CALLBACK_ENVIRON pcbe
);

PTP_IO CreateThreadpoolIo(
    [in] HANDLE fl,
    [in] PTP_WIN32_IO_CALLBACK pfnio,
    [in, out, optional] PVOID pv,
    [in, optional] PTP_CALLBACK_ENVIRON pcbe
);

PTP_WORK CreateThreadpoolWork(
    [in] PTP_WORK_CALLBACK pfnwk,
    [in, out, optional] PVOID pv,
    [in, optional] PTP_CALLBACK_ENVIRON pcbe
);

void CloseThreadpoolWork(
    [in, out] PTP_WORK pwk
);

BOOL SetThreadpoolThreadMinimum(
    [in, out] PTP_POOL ptpp,
    [in] DWORD cthrdMic
);

BOOL SetThreadpoolWaitEx(
    [in, out] PTP_WAIT pwa,
    [in, optional] HANDLE h,
    [in, optional] PFILETIME pftTimeout,
    PVOID Reserved
);

void StartThreadpoolIo(
    [in, out] PTP_IO pio
);

void ReleaseMutexWhenCallbackReturns(
    [in, out] PTP_CALLBACK_INSTANCE pci,
    [in] HANDLE mut
);

void WaitForThreadpoolIoCallbacks(
    [in, out] PTP_IO pio,
    [in] BOOL fCancelPendingCallbacks
);

void CloseThreadpoolWait(
    [in, out] PTP_WAIT pwa
);

void DisassociateCurrentThreadFromCallback(
    [in, out] PTP_CALLBACK_INSTANCE pci
);

void CloseThreadpool(
    [in, out] PTP_POOL ptpp
);

void CloseThreadpoolCleanupGroup(
    [in, out] PTP_CLEANUP_GROUP ptpcg
);

void WaitForThreadpoolWaitCallbacks(
    [in, out] PTP_WAIT pwa,
    [in] BOOL fCancelPendingCallbacks
);

void FreeLibraryWhenCallbackReturns(
    [in, out] PTP_CALLBACK_INSTANCE pci,
    [in] HMODULE mod
);

void CloseThreadpoolIo(
    [in, out] PTP_IO pio
);

void LeaveCriticalSectionWhenCallbackReturns(
    [in, out] PTP_CALLBACK_INSTANCE pci,
    [in, out] PCRITICAL_SECTION pcs
);

PTP_CLEANUP_GROUP CreateThreadpoolCleanupGroup();

BOOL CallbackMayRunLong(
    [in, out] PTP_CALLBACK_INSTANCE pci
);

void WaitForThreadpoolWorkCallbacks(
    [in, out] PTP_WORK pwk,
    [in] BOOL fCancelPendingCallbacks
);

void CancelThreadpoolIo(
    [in, out] PTP_IO pio
);

void SetThreadpoolWait(
    [in, out] PTP_WAIT pwa,
    [in, optional] HANDLE h,
    [in, optional] PFILETIME pftTimeout
);

void CloseThreadpoolCleanupGroupMembers(
    [in, out] PTP_CLEANUP_GROUP ptpcg,
    [in] BOOL fCancelPendingCallbacks,
    [in, out, optional] PVOID pvCleanupContext
);

void SubmitThreadpoolWork(
    [in, out] PTP_WORK pwk
);

PTP_TIMER CreateThreadpoolTimer(
    [in] PTP_TIMER_CALLBACK pfnti,
    [in, out, optional] PVOID pv,
    [in, optional] PTP_CALLBACK_ENVIRON pcbe
);

void SetEventWhenCallbackReturns(
    [in, out] PTP_CALLBACK_INSTANCE pci,
    [in] HANDLE evt
);

BOOL QueryThreadpoolStackInformation(
    [in] PTP_POOL ptpp,
    [out] PTP_POOL_STACK_INFORMATION ptpsi
);

void ReleaseSemaphoreWhenCallbackReturns(
    [in, out] PTP_CALLBACK_INSTANCE pci,
    [in] HANDLE sem,
    [in] DWORD crel
);

PTP_POOL CreateThreadpool(
    PVOID reserved
);

void CloseThreadpoolTimer(
    [in, out] PTP_TIMER pti
);

void SetThreadpoolThreadMaximum(
    [in, out] PTP_POOL ptpp,
    [in] DWORD cthrdMost
);

BOOL SetThreadpoolStackInformation(
    [in, out] PTP_POOL ptpp,
    [in] PTP_POOL_STACK_INFORMATION ptpsi
);

void SetThreadpoolTimer(
    [in, out] PTP_TIMER pti,
    [in, optional] PFILETIME pftDueTime,
    [in] DWORD msPeriod,
    [in] DWORD msWindowLength
);

BOOL SetThreadpoolTimerEx(
    [in, out] PTP_TIMER pti,
    [in, optional] PFILETIME pftDueTime,
    [in] DWORD msPeriod,
    [in, optional] DWORD msWindowLength
);

BOOL IsThreadpoolTimerSet(
    [in, out] PTP_TIMER pti
);

