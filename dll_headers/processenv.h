LPCH GetEnvironmentStrings();

LPWSTR GetCommandLineW();

DWORD GetEnvironmentVariableW(
    [in, optional] LPCWSTR lpName,
    [out, optional] LPWSTR lpBuffer,
    [in] DWORD nSize
);

DWORD SearchPathW(
    [in, optional] LPCWSTR lpPath,
    [in] LPCWSTR lpFileName,
    [in, optional] LPCWSTR lpExtension,
    [in] DWORD nBufferLength,
    [out] LPWSTR lpBuffer,
    [out, optional] LPWSTR *lpFilePart
);

BOOL SetEnvironmentVariableW(
    [in] LPCWSTR lpName,
    [in, optional] LPCWSTR lpValue
);

BOOL NeedCurrentDirectoryForExePathW(
    [in] LPCWSTR ExeName
);

BOOL SetEnvironmentStringsW(
    LPWCH NewEnvironment
);

BOOL SetEnvironmentVariableA(
    [in] LPCSTR lpName,
    [in, optional] LPCSTR lpValue
);

DWORD ExpandEnvironmentStringsW(
    [in] LPCWSTR lpSrc,
    [out, optional] LPWSTR lpDst,
    [in] DWORD nSize
);

DWORD ExpandEnvironmentStringsA(
    [in] LPCSTR lpSrc,
    [out, optional] LPSTR lpDst,
    [in] DWORD nSize
);

DWORD SearchPathA(
    [in, optional] LPCSTR lpPath,
    [in] LPCSTR lpFileName,
    [in, optional] LPCSTR lpExtension,
    [in] DWORD nBufferLength,
    [out] LPSTR lpBuffer,
    [out, optional] LPSTR *lpFilePart
);

BOOL NeedCurrentDirectoryForExePathA(
    [in] LPCSTR ExeName
);

DWORD GetEnvironmentVariableA(
    [in, optional] LPCSTR lpName,
    [out, optional] LPSTR lpBuffer,
    [in] DWORD nSize
);

LPWCH GetEnvironmentStringsW();

BOOL FreeEnvironmentStringsA(
    LPCH penv
);

LPSTR GetCommandLineA();

BOOL FreeEnvironmentStringsW(
    LPWCH penv
);

BOOL SetStdHandleEx(
    DWORD nStdHandle,
    HANDLE hHandle,
    PHANDLE phPrevValue
);

