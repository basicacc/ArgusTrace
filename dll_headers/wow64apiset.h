UINT GetSystemWow64DirectoryW(
    [out] LPWSTR lpBuffer,
    [in] UINT uSize
);

UINT GetSystemWow64DirectoryA(
    [out] LPSTR lpBuffer,
    [in] UINT uSize
);

BOOL Wow64DisableWow64FsRedirection(
    [out] PVOID *OldValue
);

BOOL IsWow64Process(
    [in] HANDLE hProcess,
    [out] PBOOL Wow64Process
);

BOOL Wow64SetThreadContext(
    [in] HANDLE hThread,
    [in] const WOW64_CONTEXT *lpContext
);

DWORD Wow64SuspendThread(
    HANDLE hThread
);

BOOLEAN Wow64EnableWow64FsRedirection(
    BOOLEAN Wow64FsEnableRedirection
);

USHORT Wow64SetThreadDefaultGuestMachine(
    USHORT Machine
);

UINT GetSystemWow64Directory2A(
    [out] LPSTR lpBuffer,
    [in] UINT uSize,
    [in] WORD ImageFileMachineType
);

BOOL Wow64RevertWow64FsRedirection(
    [in] PVOID OlValue
);

UINT GetSystemWow64Directory2W(
    [out] LPWSTR lpBuffer,
    [in] UINT uSize,
    [in] WORD ImageFileMachineType
);

HRESULT IsWow64GuestMachineSupported(
    [in] USHORT WowGuestMachine,
    [out] BOOL *MachineIsSupported
);

BOOL Wow64GetThreadContext(
    [in] HANDLE hThread,
    [in, out] PWOW64_CONTEXT lpContext
);

BOOL IsWow64Process2(
    [in] HANDLE hProcess,
    [out] USHORT *pProcessMachine,
    [out, optional] USHORT *pNativeMachine
);

