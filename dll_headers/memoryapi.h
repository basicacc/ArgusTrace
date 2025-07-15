BOOL UnregisterBadMemoryNotification(
    [in] PVOID RegistrationHandle
);

HANDLE OpenFileMappingW(
    [in] DWORD dwDesiredAccess,
    [in] BOOL bInheritHandle,
    [in] LPCWSTR lpName
);

PVOID VirtualAlloc2FromApp(
    [in, optional] HANDLE Process,
    [in, optional] PVOID BaseAddress,
    [in] SIZE_T Size,
    [in] ULONG AllocationType,
    [in] ULONG PageProtection,
    [in, out, optional] MEM_EXTENDED_PARAMETER *ExtendedParameters,
    [in] ULONG ParameterCount
);

BOOL AllocateUserPhysicalPages2(
    [in] HANDLE ObjectHandle,
    [in,out] PULONG_PTR NumberOfPages,
    [out] PULONG_PTR PageArray,
    [in,out] PMEM_EXTENDED_PARAMETER ExtendedParameters,
    [in] ULONG ExtendedParameterCount
);

HANDLE CreateFileMappingFromApp(
    [in] HANDLE hFile,
    [in, optional] PSECURITY_ATTRIBUTES SecurityAttributes,
    [in] ULONG PageProtection,
    [in] ULONG64 MaximumSize,
    [in, optional] PCWSTR Name
);

LPVOID VirtualAllocEx(
    [in] HANDLE hProcess,
    [in, optional] LPVOID lpAddress,
    [in] SIZE_T dwSize,
    [in] DWORD flAllocationType,
    [in] DWORD flProtect
);

PVOID MapViewOfFile3(
    [in] HANDLE FileMapping,
    [in] HANDLE Process,
    [in, optional] PVOID BaseAddress,
    [in] ULONG64 Offset,
    [in] SIZE_T ViewSize,
    [in] ULONG AllocationType,
    [in] ULONG PageProtection,
    [in, out, optional] MEM_EXTENDED_PARAMETER *ExtendedParameters,
    [in] ULONG ParameterCount
);

BOOL UnmapViewOfFileEx(
    [in] PVOID BaseAddress,
    [in] ULONG UnmapFlags
);

HANDLE OpenFileMappingFromApp(
    [in] ULONG DesiredAccess,
    [in] BOOL InheritHandle,
    [in] PCWSTR Name
);

SIZE_T VirtualQueryEx(
    [in] HANDLE hProcess,
    [in, optional] LPCVOID lpAddress,
    [out] PMEMORY_BASIC_INFORMATION lpBuffer,
    [in] SIZE_T dwLength
);

BOOL WriteProcessMemory(
    [in] HANDLE hProcess,
    [in] LPVOID lpBaseAddress,
    [in] LPCVOID lpBuffer,
    [in] SIZE_T nSize,
    [out] SIZE_T *lpNumberOfBytesWritten
);

LPVOID VirtualAlloc(
    [in, optional] LPVOID lpAddress,
    [in] SIZE_T dwSize,
    [in] DWORD flAllocationType,
    [in] DWORD flProtect
);

PVOID MapViewOfFile2(
    [in] HANDLE FileMappingHandle,
    [in] HANDLE ProcessHandle,
    [in] ULONG64 Offset,
    [in, optional] PVOID BaseAddress,
    [in] SIZE_T ViewSize,
    [in] ULONG AllocationType,
    [in] ULONG PageProtection
);

HANDLE CreateFileMappingW(
    [in] HANDLE hFile,
    [in, optional] LPSECURITY_ATTRIBUTES lpFileMappingAttributes,
    [in] DWORD flProtect,
    [in] DWORD dwMaximumSizeHigh,
    [in] DWORD dwMaximumSizeLow,
    [in, optional] LPCWSTR lpName
);

HANDLE CreateFileMappingNumaW(
    [in] HANDLE hFile,
    [in, optional] LPSECURITY_ATTRIBUTES lpFileMappingAttributes,
    [in] DWORD flProtect,
    [in] DWORD dwMaximumSizeHigh,
    [in] DWORD dwMaximumSizeLow,
    [in, optional] LPCWSTR lpName,
    [in] DWORD nndPreferred
);

DWORD DiscardVirtualMemory(
    [in] PVOID VirtualAddress,
    [in] SIZE_T Size
);

UINT ResetWriteWatch(
    [in] LPVOID lpBaseAddress,
    [in] SIZE_T dwRegionSize
);

BOOL SetProcessValidCallTargets(
    [in] HANDLE hProcess,
    [in] PVOID VirtualAddress,
    [in] SIZE_T RegionSize,
    [in] ULONG NumberOfOffsets,
    [in, out] PCFG_CALL_TARGET_INFO OffsetInformation
);

BOOL VirtualProtectFromApp(
    [in] PVOID Address,
    [in] SIZE_T Size,
    [in] ULONG NewProtection,
    [out] PULONG OldProtection
);

BOOL MapUserPhysicalPages(
    [in] PVOID VirtualAddress,
    [in] ULONG_PTR NumberOfPages,
    [in] PULONG_PTR PageArray
);

UINT GetWriteWatch(
    [in] DWORD dwFlags,
    [in] PVOID lpBaseAddress,
    [in] SIZE_T dwRegionSize,
    [out] PVOID *lpAddresses,
    [in, out] ULONG_PTR *lpdwCount,
    [out] LPDWORD lpdwGranularity
);

PVOID MapViewOfFileFromApp(
    [in] HANDLE hFileMappingObject,
    [in] ULONG DesiredAccess,
    [in] ULONG64 FileOffset,
    [in] SIZE_T NumberOfBytesToMap
);

DWORD OfferVirtualMemory(
    [in] PVOID VirtualAddress,
    [in] SIZE_T Size,
    [in] OFFER_PRIORITY Priority
);

BOOL SetProcessWorkingSetSizeEx(
    [in] HANDLE hProcess,
    [in] SIZE_T dwMinimumWorkingSetSize,
    [in] SIZE_T dwMaximumWorkingSetSize,
    [in] DWORD Flags
);

BOOL GetSystemFileCacheSize(
    [out] PSIZE_T lpMinimumFileCacheSize,
    [out] PSIZE_T lpMaximumFileCacheSize,
    [out] PDWORD lpFlags
);

LPVOID MapViewOfFile(
    [in] HANDLE hFileMappingObject,
    [in] DWORD dwDesiredAccess,
    [in] DWORD dwFileOffsetHigh,
    [in] DWORD dwFileOffsetLow,
    [in] SIZE_T dwNumberOfBytesToMap
);

PVOID MapViewOfFile3FromApp(
    [in] HANDLE FileMapping,
    [in] HANDLE Process,
    [in, optional] PVOID BaseAddress,
    [in] ULONG64 Offset,
    [in] SIZE_T ViewSize,
    [in] ULONG AllocationType,
    [in] ULONG PageProtection,
    [in, out, optional] MEM_EXTENDED_PARAMETER *ExtendedParameters,
    [in] ULONG ParameterCount
);

PVOID MapViewOfFileNuma2(
    [in] HANDLE FileMappingHandle,
    [in] HANDLE ProcessHandle,
    [in] ULONG64 Offset,
    [in, optional] PVOID BaseAddress,
    [in] SIZE_T ViewSize,
    [in] ULONG AllocationType,
    [in] ULONG PageProtection,
    [in] ULONG PreferredNode
);

BOOL AllocateUserPhysicalPages(
    [in] HANDLE hProcess,
    [in, out] PULONG_PTR NumberOfPages,
    [out] PULONG_PTR PageArray
);

PVOID VirtualAllocFromApp(
    [in, optional] PVOID BaseAddress,
    [in] SIZE_T Size,
    [in] ULONG AllocationType,
    [in] ULONG Protection
);

SIZE_T GetLargePageMinimum();

LPVOID VirtualAllocExNuma(
    [in] HANDLE hProcess,
    [in, optional] LPVOID lpAddress,
    [in] SIZE_T dwSize,
    [in] DWORD flAllocationType,
    [in] DWORD flProtect,
    [in] DWORD nndPreferred
);

BOOL VirtualLock(
    [in] LPVOID lpAddress,
    [in] SIZE_T dwSize
);

HANDLE CreateMemoryResourceNotification(
    [in] MEMORY_RESOURCE_NOTIFICATION_TYPE NotificationType
);

BOOL UnmapViewOfFile2(
    [in] HANDLE Process,
    [in] PVOID BaseAddress,
    [in] ULONG UnmapFlags
);

BOOL AllocateUserPhysicalPagesNuma(
    [in] HANDLE hProcess,
    [in, out] PULONG_PTR NumberOfPages,
    [out] PULONG_PTR PageArray,
    [in] DWORD nndPreferred
);

HANDLE CreateFileMapping2(
    HANDLE File,
    SECURITY_ATTRIBUTES *SecurityAttributes,
    ULONG DesiredAccess,
    ULONG PageProtection,
    ULONG AllocationAttributes,
    ULONG64 MaximumSize,
    PCWSTR Name,
    MEM_EXTENDED_PARAMETER *ExtendedParameters,
    ULONG ParameterCount
);

BOOL FlushViewOfFile(
    [in] LPCVOID lpBaseAddress,
    [in] SIZE_T dwNumberOfBytesToFlush
);

BOOL FreeUserPhysicalPages(
    [in] HANDLE hProcess,
    [in, out] PULONG_PTR NumberOfPages,
    [in] PULONG_PTR PageArray
);

BOOL QueryVirtualMemoryInformation(
    [in] HANDLE Process,
    [in] const VOID *VirtualAddress,
    [in] WIN32_MEMORY_INFORMATION_CLASS MemoryInformationClass,
    [out] PVOID MemoryInformation,
    [in] SIZE_T MemoryInformationSize,
    [out, optional] PSIZE_T ReturnSize
);

PVOID RegisterBadMemoryNotification(
    [in] PBAD_MEMORY_CALLBACK_ROUTINE Callback
);

BOOL VirtualProtect(
    [in] LPVOID lpAddress,
    [in] SIZE_T dwSize,
    [in] DWORD flNewProtect,
    [out] PDWORD lpflOldProtect
);

BOOL SetSystemFileCacheSize(
    [in] SIZE_T MinimumFileCacheSize,
    [in] SIZE_T MaximumFileCacheSize,
    [in] DWORD Flags
);

BOOL GetProcessWorkingSetSizeEx(
    [in] HANDLE hProcess,
    [out] PSIZE_T lpMinimumWorkingSetSize,
    [out] PSIZE_T lpMaximumWorkingSetSize,
    [out] PDWORD Flags
);

BOOL UnmapViewOfFile(
    [in] LPCVOID lpBaseAddress
);

DWORD ReclaimVirtualMemory(
    [in] void const *VirtualAddress,
    [in] SIZE_T Size
);

BOOL PrefetchVirtualMemory(
    [in] HANDLE hProcess,
    [in] ULONG_PTR NumberOfEntries,
    [in] PWIN32_MEMORY_RANGE_ENTRY VirtualAddresses,
    [in] ULONG Flags
);

BOOL VirtualProtectEx(
    [in] HANDLE hProcess,
    [in] LPVOID lpAddress,
    [in] SIZE_T dwSize,
    [in] DWORD flNewProtect,
    [out] PDWORD lpflOldProtect
);

BOOL GetMemoryErrorHandlingCapabilities(
    [out] PULONG Capabilities
);

BOOL ReadProcessMemory(
    [in] HANDLE hProcess,
    [in] LPCVOID lpBaseAddress,
    [out] LPVOID lpBuffer,
    [in] SIZE_T nSize,
    [out] SIZE_T *lpNumberOfBytesRead
);

SIZE_T VirtualQuery(
    [in, optional] LPCVOID lpAddress,
    [out] PMEMORY_BASIC_INFORMATION lpBuffer,
    [in] SIZE_T dwLength
);

BOOL VirtualFree(
    [in] LPVOID lpAddress,
    [in] SIZE_T dwSize,
    [in] DWORD dwFreeType
);

BOOL GetProcessWorkingSetSize(
    [in] HANDLE hProcess,
    [out] PSIZE_T lpMinimumWorkingSetSize,
    [out] PSIZE_T lpMaximumWorkingSetSize
);

LPVOID MapViewOfFileEx(
    [in] HANDLE hFileMappingObject,
    [in] DWORD dwDesiredAccess,
    [in] DWORD dwFileOffsetHigh,
    [in] DWORD dwFileOffsetLow,
    [in] SIZE_T dwNumberOfBytesToMap,
    [in, optional] LPVOID lpBaseAddress
);

BOOL QueryMemoryResourceNotification(
    [in] HANDLE ResourceNotificationHandle,
    [out] PBOOL ResourceState
);

BOOL VirtualUnlock(
    [in] LPVOID lpAddress,
    [in] SIZE_T dwSize
);

BOOL SetProcessWorkingSetSize(
    [in] HANDLE hProcess,
    [in] SIZE_T dwMinimumWorkingSetSize,
    [in] SIZE_T dwMaximumWorkingSetSize
);

BOOL VirtualFreeEx(
    [in] HANDLE hProcess,
    [in] LPVOID lpAddress,
    [in] SIZE_T dwSize,
    [in] DWORD dwFreeType
);

PVOID VirtualAlloc2(
    [in, optional] HANDLE Process,
    [in, optional] PVOID BaseAddress,
    [in] SIZE_T Size,
    [in] ULONG AllocationType,
    [in] ULONG PageProtection,
    [in, out, optional] MEM_EXTENDED_PARAMETER *ExtendedParameters,
    [in] ULONG ParameterCount
);

