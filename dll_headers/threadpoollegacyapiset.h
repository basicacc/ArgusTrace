BOOL QueueUserWorkItem(
    [in] LPTHREAD_START_ROUTINE Function,
    [in, optional] PVOID Context,
    [in] ULONG Flags
);

BOOL UnregisterWaitEx(
    [in] HANDLE WaitHandle,
    [in, optional] HANDLE CompletionEvent
);

BOOL DeleteTimerQueue(
    HANDLE TimerQueue
);

HANDLE CreateTimerQueue();

BOOL DeleteTimerQueueTimer(
    [in, optional] HANDLE TimerQueue,
    [in] HANDLE Timer,
    [in, optional] HANDLE CompletionEvent
);

BOOL CreateTimerQueueTimer(
    [out] PHANDLE phNewTimer,
    [in, optional] HANDLE TimerQueue,
    [in] WAITORTIMERCALLBACK Callback,
    [in, optional] PVOID Parameter,
    [in] DWORD DueTime,
    [in] DWORD Period,
    [in] ULONG Flags
);

BOOL ChangeTimerQueueTimer(
    [in, optional] HANDLE TimerQueue,
    [in, out] HANDLE Timer,
    [in] ULONG DueTime,
    [in] ULONG Period
);

BOOL DeleteTimerQueueEx(
    [in] HANDLE TimerQueue,
    [in, optional] HANDLE CompletionEvent
);

