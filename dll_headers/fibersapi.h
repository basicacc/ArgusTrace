BOOL IsThreadAFiber();

BOOL FlsFree(
    [in] DWORD dwFlsIndex
);

PVOID FlsGetValue(
    [in] DWORD dwFlsIndex
);

DWORD FlsAlloc(
    [in] PFLS_CALLBACK_FUNCTION lpCallback
);

BOOL FlsSetValue(
    [in] DWORD dwFlsIndex,
    [in, optional] PVOID lpFlsData
);

