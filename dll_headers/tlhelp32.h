BOOL Module32Next(
    [in] HANDLE hSnapshot,
    [out] LPMODULEENTRY32 lpme
);

BOOL Module32NextW(
    [in] HANDLE hSnapshot,
    [out] LPMODULEENTRY32W lpme
);

BOOL Module32FirstW(
    [in] HANDLE hSnapshot,
    [in, out] LPMODULEENTRY32W lpme
);

BOOL Heap32Next(
    [out] LPHEAPENTRY32 lphe
);

BOOL Module32First(
    [in] HANDLE hSnapshot,
    [in, out] LPMODULEENTRY32 lpme
);

BOOL Process32NextW(
    [in] HANDLE hSnapshot,
    [out] LPPROCESSENTRY32W lppe
);

BOOL Thread32First(
    [in] HANDLE hSnapshot,
    [in, out] LPTHREADENTRY32 lpte
);

BOOL Toolhelp32ReadProcessMemory(
    [in] DWORD th32ProcessID,
    [in] LPCVOID lpBaseAddress,
    [out] LPVOID lpBuffer,
    [in] SIZE_T cbRead,
    [out] SIZE_T *lpNumberOfBytesRead
);

BOOL Process32First(
    [in] HANDLE hSnapshot,
    [in, out] LPPROCESSENTRY32 lppe
);

BOOL Process32Next(
    [in] HANDLE hSnapshot,
    [out] LPPROCESSENTRY32 lppe
);

BOOL Thread32Next(
    [in] HANDLE hSnapshot,
    [out] LPTHREADENTRY32 lpte
);

BOOL Heap32First(
    [in, out] LPHEAPENTRY32 lphe,
    [in] DWORD th32ProcessID,
    [in] ULONG_PTR th32HeapID
);

BOOL Heap32ListNext(
    [in] HANDLE hSnapshot,
    [out] LPHEAPLIST32 lphl
);

HANDLE CreateToolhelp32Snapshot(
    [in] DWORD dwFlags,
    [in] DWORD th32ProcessID
);

BOOL Heap32ListFirst(
    [in] HANDLE hSnapshot,
    [in, out] LPHEAPLIST32 lphl
);

BOOL Process32FirstW(
    [in] HANDLE hSnapshot,
    [in, out] LPPROCESSENTRY32W lppe
);

