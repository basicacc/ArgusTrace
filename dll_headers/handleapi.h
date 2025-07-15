BOOL GetHandleInformation(
    [in] HANDLE hObject,
    [out] LPDWORD lpdwFlags
);

BOOL SetHandleInformation(
    [in] HANDLE hObject,
    [in] DWORD dwMask,
    [in] DWORD dwFlags
);

BOOL CompareObjectHandles(
    [in] HANDLE hFirstObjectHandle,
    [in] HANDLE hSecondObjectHandle
);

BOOL CloseHandle(
    [in] HANDLE hObject
);

BOOL DuplicateHandle(
    [in] HANDLE hSourceProcessHandle,
    [in] HANDLE hSourceHandle,
    [in] HANDLE hTargetProcessHandle,
    [out] LPHANDLE lpTargetHandle,
    [in] DWORD dwDesiredAccess,
    [in] BOOL bInheritHandle,
    [in] DWORD dwOptions
);

