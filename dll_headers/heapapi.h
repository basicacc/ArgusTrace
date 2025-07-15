DWORD GetProcessHeaps(
    [in] DWORD NumberOfHeaps,
    [out] PHANDLE ProcessHeaps
);

BOOL HeapSetInformation(
    [in, optional] HANDLE HeapHandle,
    [in] HEAP_INFORMATION_CLASS HeapInformationClass,
    [in] PVOID HeapInformation,
    [in] SIZE_T HeapInformationLength
);

HANDLE HeapCreate(
    [in] DWORD flOptions,
    [in] SIZE_T dwInitialSize,
    [in] SIZE_T dwMaximumSize
);

BOOL HeapSummary(
    [in] HANDLE hHeap,
    [in] DWORD dwFlags,
    [in, out] LPHEAP_SUMMARY lpSummary
);

BOOL HeapQueryInformation(
    [in, optional] HANDLE HeapHandle,
    [in] HEAP_INFORMATION_CLASS HeapInformationClass,
    [out] PVOID HeapInformation,
    [in] SIZE_T HeapInformationLength,
    [out, optional] PSIZE_T ReturnLength
);

BOOL HeapValidate(
    [in] HANDLE hHeap,
    [in] DWORD dwFlags,
    [in, optional] LPCVOID lpMem
);

HANDLE GetProcessHeap();

SIZE_T HeapSize(
    [in] HANDLE hHeap,
    [in] DWORD dwFlags,
    [in] LPCVOID lpMem
);

SIZE_T HeapCompact(
    [in] HANDLE hHeap,
    [in] DWORD dwFlags
);

BOOL HeapWalk(
    [in] HANDLE hHeap,
    [in, out] LPPROCESS_HEAP_ENTRY lpEntry
);

BOOL HeapFree(
    [in] HANDLE hHeap,
    [in] DWORD dwFlags,
    [in] _Frees_ptr_opt_ LPVOID lpMem
);

BOOL HeapDestroy(
    [in] HANDLE hHeap
);

BOOL HeapUnlock(
    [in] HANDLE hHeap
);

BOOL HeapLock(
    [in] HANDLE hHeap
);

DECLSPEC_ALLOCATOR LPVOID HeapAlloc(
    [in] HANDLE hHeap,
    [in] DWORD dwFlags,
    [in] SIZE_T dwBytes
);

DECLSPEC_ALLOCATOR LPVOID HeapReAlloc(
    [in] HANDLE hHeap,
    [in] DWORD dwFlags,
    [in] _Frees_ptr_opt_ LPVOID lpMem,
    [in] SIZE_T dwBytes
);

