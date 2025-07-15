LONG UnhandledExceptionFilter(
    [in] _EXCEPTION_POINTERS *ExceptionInfo
);

_Post_equals_last_error_ DWORD GetLastError();

void FatalAppExitA(
    [in] UINT uAction,
    [in] LPCSTR lpMessageText
);

void RestoreLastError(
    DWORD dwErrCode
);

void SetLastError(
    [in] DWORD dwErrCode
);

BOOL SetThreadErrorMode(
    [in] DWORD dwNewMode,
    [out] LPDWORD lpOldMode
);

PVOID AddVectoredContinueHandler(
    ULONG First,
    PVECTORED_EXCEPTION_HANDLER Handler
);

LPTOP_LEVEL_EXCEPTION_FILTER SetUnhandledExceptionFilter(
    [in] LPTOP_LEVEL_EXCEPTION_FILTER lpTopLevelExceptionFilter
);

ULONG RemoveVectoredContinueHandler(
    PVOID Handle
);

PVOID AddVectoredExceptionHandler(
    ULONG First,
    PVECTORED_EXCEPTION_HANDLER Handler
);

DWORD GetThreadErrorMode();

UINT GetErrorMode();

void RaiseFailFastException(
    [in, optional] PEXCEPTION_RECORD pExceptionRecord,
    [in, optional] PCONTEXT pContextRecord,
    [in] DWORD dwFlags
);

UINT SetErrorMode(
    [in] UINT uMode
);

void RaiseException(
    [in] DWORD dwExceptionCode,
    [in] DWORD dwExceptionFlags,
    [in] DWORD nNumberOfArguments,
    [in] const ULONG_PTR *lpArguments
);

ULONG RemoveVectoredExceptionHandler(
    PVOID Handle
);

void FatalAppExitW(
    [in] UINT uAction,
    [in] LPCWSTR lpMessageText
);

