BOOL FreeResource(
    [in] HGLOBAL hResData
);

BOOL GetModuleHandleExW(
    [in] DWORD dwFlags,
    [in, optional] LPCWSTR lpModuleName,
    [out] HMODULE *phModule
);

BOOL SetDefaultDllDirectories(
    [in] DWORD DirectoryFlags
);

HMODULE LoadLibraryExW(
    [in] LPCWSTR lpLibFileName,
    HANDLE hFile,
    [in] DWORD dwFlags
);

void FreeLibraryAndExitThread(
    [in] HMODULE hLibModule,
    [in] DWORD dwExitCode
);

HMODULE GetModuleHandleW(
    [in, optional] LPCWSTR lpModuleName
);

LPVOID LockResource(
    [in] HGLOBAL hResData
);

BOOL EnumResourceNamesExW(
    [in, optional] HMODULE hModule,
    LPCWSTR lpType,
    [in] ENUMRESNAMEPROCW lpEnumFunc,
    [in] LONG_PTR lParam,
    [in] DWORD dwFlags,
    [in] LANGID LangId
);

BOOL RemoveDllDirectory(
    [in] DLL_DIRECTORY_COOKIE Cookie
);

BOOL GetModuleHandleExA(
    [in] DWORD dwFlags,
    [in, optional] LPCSTR lpModuleName,
    [out] HMODULE *phModule
);

BOOL EnumResourceLanguagesExW(
    [in] HMODULE hModule,
    [in] LPCWSTR lpType,
    [in] LPCWSTR lpName,
    [in] ENUMRESLANGPROCW lpEnumFunc,
    [in] LONG_PTR lParam,
    [in] DWORD dwFlags,
    [in] LANGID LangId
);

HGLOBAL LoadResource(
    [in, optional] HMODULE hModule,
    [in] HRSRC hResInfo
);

BOOL EnumResourceTypesExW(
    [in, optional] HMODULE hModule,
    [in] ENUMRESTYPEPROCW lpEnumFunc,
    [in] LONG_PTR lParam,
    [in] DWORD dwFlags,
    [in] LANGID LangId
);

DWORD GetModuleFileNameA(
    [in, optional] HMODULE hModule,
    [out] LPSTR lpFilename,
    [in] DWORD nSize
);

HMODULE LoadLibraryA(
    [in] LPCSTR lpLibFileName
);

HMODULE LoadLibraryW(
    [in] LPCWSTR lpLibFileName
);

HRSRC FindResourceExW(
    [in, optional] HMODULE hModule,
    [in] LPCWSTR lpType,
    [in] LPCWSTR lpName,
    [in] WORD wLanguage
);

BOOL DisableThreadLibraryCalls(
    [in] HMODULE hLibModule
);

BOOL EnumResourceNamesA(
    [in, optional] HMODULE hModule,
    [in] LPCSTR lpType,
    [in] ENUMRESNAMEPROCA lpEnumFunc,
    [in] LONG_PTR lParam
);

FARPROC GetProcAddress(
    [in] HMODULE hModule,
    [in] LPCSTR lpProcName
);

BOOL EnumResourceLanguagesExA(
    [in] HMODULE hModule,
    [in] LPCSTR lpType,
    [in] LPCSTR lpName,
    [in] ENUMRESLANGPROCA lpEnumFunc,
    [in] LONG_PTR lParam,
    [in] DWORD dwFlags,
    [in] LANGID LangId
);

BOOL EnumResourceTypesExA(
    [in, optional] HMODULE hModule,
    [in] ENUMRESTYPEPROCA lpEnumFunc,
    [in] LONG_PTR lParam,
    [in] DWORD dwFlags,
    [in] LANGID LangId
);

DLL_DIRECTORY_COOKIE AddDllDirectory(
    [in] PCWSTR NewDirectory
);

HMODULE LoadLibraryExA(
    [in] LPCSTR lpLibFileName,
    HANDLE hFile,
    [in] DWORD dwFlags
);

DWORD SizeofResource(
    [in, optional] HMODULE hModule,
    [in] HRSRC hResInfo
);

int FindStringOrdinal(
    [in] DWORD dwFindStringOrdinalFlags,
    [in] LPCWSTR lpStringSource,
    [in] int cchSource,
    [in] LPCWSTR lpStringValue,
    [in] int cchValue,
    [in] BOOL bIgnoreCase
);

HRSRC FindResourceW(
    [in, optional] HMODULE hModule,
    [in] LPCWSTR lpName,
    [in] LPCWSTR lpType
);

BOOL EnumResourceNamesW(
    [in, optional] HMODULE hModule,
    [in] LPCWSTR lpType,
    [in] ENUMRESNAMEPROCW lpEnumFunc,
    [in] LONG_PTR lParam
);

HMODULE GetModuleHandleA(
    [in, optional] LPCSTR lpModuleName
);

DWORD GetModuleFileNameW(
    [in, optional] HMODULE hModule,
    [out] LPWSTR lpFilename,
    [in] DWORD nSize
);

BOOL FreeLibrary(
    [in] HMODULE hLibModule
);

BOOL EnumResourceNamesExA(
    [in, optional] HMODULE hModule,
    LPCSTR lpType,
    [in] ENUMRESNAMEPROCA lpEnumFunc,
    [in] LONG_PTR lParam,
    [in] DWORD dwFlags,
    [in] LANGID LangId
);

