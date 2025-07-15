HICON DuplicateIcon(
    [in] HINSTANCE hInst,
    [in] HICON hIcon
);

SHSTDAPI SHQueryUserNotificationState(
    [out] QUERY_USER_NOTIFICATION_STATE *pquns
);

INT ShellAboutW(
    [in, optional] HWND hWnd,
    [in] LPCWSTR szApp,
    [in, optional] LPCWSTR szOtherStuff,
    [in, optional] HICON hIcon
);

HICON ExtractAssociatedIconW(
    [in] HINSTANCE hInst,
    [in, out] LPWSTR pszIconPath,
    [in, out] WORD *piIcon
);

void NetAddr_DisplayErrorTip(
    [in] hwnd
);

INT ShellAboutA(
    [in, optional] HWND hWnd,
    [in] LPCSTR szApp,
    [in, optional] LPCSTR szOtherStuff,
    [in, optional] HICON hIcon
);

void DragAcceptFiles(
    HWND hWnd,
    BOOL fAccept
);

int SHFileOperationW(
    [in, out] LPSHFILEOPSTRUCTW lpFileOp
);

HRESULT SHGetDriveMedia(
    [in] PCWSTR pszDrive,
    [out] DWORD *pdwMediaContent
);

HINSTANCE FindExecutableW(
    [in] LPCWSTR lpFile,
    [in, optional] LPCWSTR lpDirectory,
    [out] LPWSTR lpResult
);

SHSTDAPI SHLoadNonloadedIconOverlayIdentifiers();

HICON ExtractAssociatedIconExW(
    [in] HINSTANCE hInst,
    [in, out] LPWSTR pszIconPath,
    [in, out] WORD *piIconIndex,
    [in, out] WORD *piIconId
);

DWORD_PTR SHGetFileInfoA(
    [in] LPCSTR pszPath,
    DWORD dwFileAttributes,
    [in, out] SHFILEINFOA *psfi,
    UINT cbFileInfo,
    UINT uFlags
);

void NetAddr_GetAllowType(
    [in] hwnd
);

BOOL Shell_NotifyIconW(
    [in] DWORD dwMessage,
    [in] PNOTIFYICONDATAW lpData
);

BOOL DragQueryPoint(
    [in] HDROP hDrop,
    [out] POINT *ppt
);

SHSTDAPI SHEvaluateSystemCommandTemplate(
    [in] PCWSTR pszCmdTemplate,
    [out] PWSTR *ppszApplication,
    [out, optional] PWSTR *ppszCommandLine,
    [out, optional] PWSTR *ppszParameters
);

BOOL InitNetworkAddressControl();

UINT ExtractIconExW(
    [in] LPCWSTR lpszFile,
    [in] int nIconIndex,
    [out] HICON *phiconLarge,
    [out] HICON *phiconSmall,
    UINT nIcons
);

BOOL SHCreateProcessAsUserW(
    [in, out] PSHCREATEPROCESSINFOW pscpi
);

DWORD_PTR SHGetFileInfoW(
    [in] LPCWSTR pszPath,
    DWORD dwFileAttributes,
    [in, out] SHFILEINFOW *psfi,
    UINT cbFileInfo,
    UINT uFlags
);

HINSTANCE ShellExecuteA(
    [in, optional] HWND hwnd,
    [in, optional] LPCSTR lpOperation,
    [in] LPCSTR lpFile,
    [in, optional] LPCSTR lpParameters,
    [in, optional] LPCSTR lpDirectory,
    [in] INT nShowCmd
);

SHSTDAPI SHGetImageList(
    [in] int iImageList,
    [in] REFIID riid,
    [out] void **ppvObj
);

int ShellMessageBoxW(
    [in] HINSTANCE hAppInst,
    [in] HWND hWnd,
    [in] LPCWSTR lpcText,
    [in] LPCWSTR lpcTitle,
    [in] UINT fuStyle,
    ...
);

void SHFreeNameMappings(
    [in, optional] HANDLE hNameMappings
);

BOOL SHGetNewLinkInfoA(
    [in] LPCSTR pszLinkTo,
    [in] LPCSTR pszDir,
    [out] LPSTR pszName,
    [out] BOOL *pfMustCopy,
    [in] UINT uFlags
);

SHSTDAPI SHQueryRecycleBinW(
    [in, optional] LPCWSTR pszRootPath,
    [in, out] LPSHQUERYRBINFO pSHQueryRBInfo
);

HRESULT SHEnumerateUnreadMailAccountsA(
    [in, optional] HKEY hKeyUser,
    DWORD dwIndex,
    [out] LPSTR pszMailAddress,
    int cchMailAddress
);

SHSTDAPI AssocCreateForClasses(
    [in] const ASSOCIATIONELEMENT *rgClasses,
    [in] ULONG cClasses,
    [in] REFIID riid,
    [out] void **ppv
);

void NetAddr_SetAllowType(
    [in] hwnd,
    [in] addrMask
);

int SHFileOperationA(
    [in, out] LPSHFILEOPSTRUCTA lpFileOp
);

BOOL SHGetDiskFreeSpaceExW(
    [in] LPCWSTR pszDirectoryName,
    [out, optional] ULARGE_INTEGER *pulFreeBytesAvailableToCaller,
    [out, optional] ULARGE_INTEGER *pulTotalNumberOfBytes,
    [out, optional] ULARGE_INTEGER *pulTotalNumberOfFreeBytes
);

HICON ExtractIconA(
    [in] HINSTANCE hInst,
    [in] LPCSTR pszExeFileName,
    UINT nIconIndex
);

HRESULT SHGetUnreadMailCountW(
    [in, optional] HKEY hKeyUser,
    [in, optional] LPCWSTR pszMailAddress,
    [out, optional] DWORD *pdwCount,
    [out, optional] FILETIME *pFileTime,
    [out, optional] LPWSTR pszShellExecuteCommand,
    int cchShellExecuteCommand
);

BOOL SHInvokePrinterCommandW(
    [in, optional] HWND hwnd,
    UINT uAction,
    [in] LPCWSTR lpBuf1,
    [in, optional] LPCWSTR lpBuf2,
    BOOL fModal
);

UINT DragQueryFileW(
    [in] HDROP hDrop,
    [in] UINT iFile,
    [out] LPWSTR lpszFile,
    UINT cch
);

SHSTDAPI SHQueryRecycleBinA(
    [in, optional] LPCSTR pszRootPath,
    [in, out] LPSHQUERYRBINFO pSHQueryRBInfo
);

HRESULT SHSetUnreadMailCountW(
    [in] LPCWSTR pszMailAddress,
    DWORD dwCount,
    [in] LPCWSTR pszShellExecuteCommand
);

SHSTDAPI SHEmptyRecycleBinA(
    [in, optional] HWND hwnd,
    [in, optional] LPCSTR pszRootPath,
    DWORD dwFlags
);

BOOL ShellExecuteExA(
    [in, out] SHELLEXECUTEINFOA *pExecInfo
);

HICON ExtractAssociatedIconExA(
    [in] HINSTANCE hInst,
    [in, out] LPSTR pszIconPath,
    [in, out] WORD *piIconIndex,
    [in, out] WORD *piIconId
);

HICON ExtractAssociatedIconA(
    [in] HINSTANCE hInst,
    [in, out] LPSTR pszIconPath,
    [in, out] WORD *piIcon
);

int ShellMessageBoxA(
    [in] HINSTANCE hAppInst,
    [in] HWND hWnd,
    [in] LPCSTR lpcText,
    [in] LPCSTR lpcTitle,
    [in] UINT fuStyle,
    ...
);

HRESULT SHGetUnreadMailCountA(
    [in, optional] HKEY hKeyUser,
    [in, optional] LPCSTR pszMailAddress,
    [out, optional] DWORD *pdwCount,
    [out, optional] FILETIME *pFileTime,
    [out, optional] LPSTR pszShellExecuteCommand,
    int cchShellExecuteCommand
);

SHSTDAPI SHGetStockIconInfo(
    SHSTOCKICONID siid,
    UINT uFlags,
    [in, out] SHSTOCKICONINFO *psii
);

SHSTDAPI SHGetLocalizedName(
    [in] PCWSTR pszPath,
    [out] PWSTR pszResModule,
    UINT cch,
    [out] int *pidsRes
);

DWORD DoEnvironmentSubstW(
    [in, out] LPWSTR pszSrc,
    UINT cchSrc
);

UINT_PTR SHAppBarMessage(
    [in] DWORD dwMessage,
    [in, out] PAPPBARDATA pData
);

SHSTDAPI SHEmptyRecycleBinW(
    [in, optional] HWND hwnd,
    [in, optional] LPCWSTR pszRootPath,
    DWORD dwFlags
);

BOOL SHGetDiskFreeSpaceExA(
    [in] LPCSTR pszDirectoryName,
    [out, optional] ULARGE_INTEGER *pulFreeBytesAvailableToCaller,
    [out, optional] ULARGE_INTEGER *pulTotalNumberOfBytes,
    [out, optional] ULARGE_INTEGER *pulTotalNumberOfFreeBytes
);

DWORD DoEnvironmentSubstA(
    [in, out] LPSTR pszSrc,
    UINT cchSrc
);

HRESULT SHSetUnreadMailCountA(
    [in] LPCSTR pszMailAddress,
    DWORD dwCount,
    [in] LPCSTR pszShellExecuteCommand
);

UINT DragQueryFileA(
    [in] HDROP hDrop,
    [in] UINT iFile,
    [out] LPSTR lpszFile,
    UINT cch
);

BOOL ShellExecuteExW(
    [in, out] SHELLEXECUTEINFOW *pExecInfo
);

HICON ExtractIconW(
    [in] HINSTANCE hInst,
    [in] LPCWSTR pszExeFileName,
    UINT nIconIndex
);

BOOL SHGetNewLinkInfoW(
    [in] LPCWSTR pszLinkTo,
    [in] LPCWSTR pszDir,
    [out] LPWSTR pszName,
    [out] BOOL *pfMustCopy,
    [in] UINT uFlags
);

SHSTDAPI Shell_NotifyIconGetRect(
    [in] const NOTIFYICONIDENTIFIER *identifier,
    [out] RECT *iconLocation
);

void DragFinish(
    HDROP hDrop
);

UINT ExtractIconExA(
    [in] LPCSTR lpszFile,
    [in] int nIconIndex,
    [out] HICON *phiconLarge,
    [out] HICON *phiconSmall,
    UINT nIcons
);

SHSTDAPI SHIsFileAvailableOffline(
    [in] PCWSTR pwszPath,
    [out, optional] DWORD *pdwStatus
);

BOOL SHInvokePrinterCommandA(
    [in, optional] HWND hwnd,
    UINT uAction,
    [in] LPCSTR lpBuf1,
    [in, optional] LPCSTR lpBuf2,
    BOOL fModal
);

SHSTDAPI SHSetLocalizedName(
    [in] PCWSTR pszPath,
    [in] PCWSTR pszResModule,
    int idsRes
);

void NetAddr_GetAddress(
    hwnd,
    [in, out] pv
);

SHSTDAPI SHGetPropertyStoreForWindow(
    [in] HWND hwnd,
    [in] REFIID riid,
    [out] void **ppv
);

SHSTDAPI SHRemoveLocalizedName(
    [in] PCWSTR pszPath
);

BOOL SHTestTokenMembership(
    [in, optional] HANDLE hToken,
    ULONG ulRID
);

HINSTANCE FindExecutableA(
    [in] LPCSTR lpFile,
    [in, optional] LPCSTR lpDirectory,
    [out] LPSTR lpResult
);

BOOL Shell_NotifyIconA(
    [in] DWORD dwMessage,
    [in] PNOTIFYICONDATAA lpData
);

LPWSTR * CommandLineToArgvW(
    [in] LPCWSTR lpCmdLine,
    [out] int *pNumArgs
);

HRESULT SHEnumerateUnreadMailAccountsW(
    [in, optional] HKEY hKeyUser,
    DWORD dwIndex,
    [out] LPWSTR pszMailAddress,
    int cchMailAddress
);

HINSTANCE ShellExecuteW(
    [in, optional] HWND hwnd,
    [in, optional] LPCWSTR lpOperation,
    [in] LPCWSTR lpFile,
    [in, optional] LPCWSTR lpParameters,
    [in, optional] LPCWSTR lpDirectory,
    [in] INT nShowCmd
);

