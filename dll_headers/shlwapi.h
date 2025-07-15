PCWSTR StrChrNIW(
    [in] PCWSTR pszStart,
    WCHAR wMatch,
    UINT cchMax
);

LWSTDAPI SHCreateStreamOnFileW(
    [in] LPCWSTR pszFile,
    [in] DWORD grfMode,
    [out] IStream **ppstm
);

LSTATUS SHDeleteValueW(
    HKEY hkey,
    LPCWSTR pszSubKey,
    LPCWSTR pszValue
);

LWSTDAPI IStream_Reset(
    [in] IStream *pstm
);

LRESULT SHSendMessageBroadcastA(
    [in] UINT uMsg,
    [in] WPARAM wParam,
    [in] LPARAM lParam
);

PSTR StrFormatKBSizeA(
    LONGLONG qdw,
    [out] PSTR pszBuf,
    UINT cchBuf
);

int GetMenuPosFromID(
    [in] HMENU hmenu,
    UINT id
);

BOOL PathRelativePathToA(
    [out] LPSTR pszPath,
    [in] LPCSTR pszFrom,
    [in] DWORD dwAttrFrom,
    [in] LPCSTR pszTo,
    [in] DWORD dwAttrTo
);

LSTATUS SHRegEnumUSKeyA(
    [in] HUSKEY hUSKey,
    [in] DWORD dwIndex,
    [out] LPSTR pszName,
    [in, out] LPDWORD pcchName,
    [in] SHREGENUM_FLAGS enumRegFlags
);

int StrCmpNCA(
    [in] LPCSTR pszStr1,
    [in] LPCSTR pszStr2,
    int nChar
);

BOOL SHRegGetBoolUSValueA(
    [in] LPCSTR pszSubKey,
    [in, optional] LPCSTR pszValue,
    [in] BOOL fIgnoreHKCU,
    [in] BOOL fDefault
);

LPCWSTR PathFindNextComponentW(
    [in] LPCWSTR pszPath
);

PWSTR StrDupW(
    PCWSTR pszSrch
);

PWSTR StrFormatByteSizeW(
    LONGLONG qdw,
    [out] PWSTR pszBuf,
    UINT cchBuf
);

LWSTDAPI SHReleaseThreadRef();

int PathCommonPrefixW(
    [in] LPCWSTR pszFile1,
    [in] LPCWSTR pszFile2,
    [out, optional] LPWSTR achPath
);

LWSTDAPI SHGetInverseCMAP(
    [out] BYTE *pbMap,
    [in] ULONG cbMap
);

LWSTDAPI IStream_ReadPidl(
    [in] IStream *pstm,
    [out] PIDLIST_RELATIVE *ppidlOut
);

LPSTR PathAddBackslashA(
    [in, out] LPSTR pszPath
);

BOOL PathIsRelativeW(
    [in] LPCWSTR pszPath
);

BOOL UrlIsW(
    [in] PCWSTR pszUrl,
    URLIS UrlIs
);

UINT WhichPlatform();

LWSTDAPI IStream_WriteStr(
    [in] IStream *pstm,
    [in] PCWSTR psz
);

PCWSTR StrChrIW(
    [in] PCWSTR pszStart,
    WCHAR wMatch
);

int wvnsprintfW(
    [out] PWSTR pszDest,
    [in] int cchDest,
    [in] PCWSTR pszFmt,
    [in] va_list arglist
);

LSTATUS SHDeleteKeyW(
    [in] HKEY hkey,
    [in, optional] LPCWSTR pszSubKey
);

LWSTDAPI IStream_WritePidl(
    [in] IStream *pstm,
    [in] PCUIDLIST_RELATIVE pidlWrite
);

BOOL IsInternetESCEnabled();

void PathRemoveArgsW(
    [in, out] LPWSTR pszPath
);

LSTATUS SHRegWriteUSValueA(
    [in] HUSKEY hUSKey,
    [in] LPCSTR pszValue,
    [in] DWORD dwType,
    [in] const void *pvData,
    [in] DWORD cbData,
    [in] DWORD dwFlags
);

LSTATUS SHRegGetValueW(
    [in] HKEY hkey,
    [in] LPCWSTR pszSubKey,
    [in] LPCWSTR pszValue,
    [in] SRRF srrfFlags,
    [in, out] DWORD *pdwType,
    [out] void *pvData,
    [in, out] DWORD *pcbData
);

int UrlCompareA(
    [in] PCSTR psz1,
    [in] PCSTR psz2,
    BOOL fIgnoreSlash
);

BOOL PathCompactPathW(
    [in] HDC hDC,
    [in, out] LPWSTR pszPath,
    [in] UINT dx
);

LWSTDAPI SHGetThreadRef(
    [in] IUnknown **ppunk
);

LWSTDAPI SHGetViewStatePropertyBag(
    [in, optional] PCIDLIST_ABSOLUTE pidl,
    [in, optional] PCWSTR pszBagName,
    DWORD dwFlags,
    [in] REFIID riid,
    [out] void **ppv
);

LWSTDAPI StrRetToStrA(
    [in, out] STRRET *pstr,
    [in, optional] PCUITEMID_CHILD pidl,
    [out] LPSTR *ppsz
);

BOOL PathQuoteSpacesW(
    [in, out] LPWSTR lpsz
);

LWSTDAPI SHCreateStreamOnFileA(
    [in] LPCSTR pszFile,
    [in] DWORD grfMode,
    [out] IStream **ppstm
);

long SHGlobalCounterIncrement(
    [in] const SHGLOBALCOUNTER id
);

LWSTDAPI UrlCombineA(
    [in] PCSTR pszBase,
    [in] PCSTR pszRelative,
    [out, optional] PSTR pszCombined,
    [in, out] DWORD *pcchCombined,
    DWORD dwFlags
);

LWSTDAPI UrlCreateFromPathA(
    [in] PCSTR pszPath,
    [out] PSTR pszUrl,
    [in, out] DWORD *pcchUrl,
    DWORD dwFlags
);

LWSTDAPI SHCreateStreamOnFileEx(
    [in] LPCWSTR pszFile,
    [in] DWORD grfMode,
    [in] DWORD dwAttributes,
    [in] BOOL fCreate,
    [in, optional] IStream *pstmTemplate,
    [out] IStream **ppstm
);

LWSTDAPI SHStrDupW(
    [in] LPCWSTR psz,
    [out] LPWSTR *ppwsz
);

void PathStripPathW(
    [in, out] LPWSTR pszPath
);

LPCSTR PathFindNextComponentA(
    [in] LPCSTR pszPath
);

BOOL PathIsUNCServerA(
    [in] LPCSTR pszPath
);

int StrCSpnA(
    [in] PCSTR pszStr,
    [in] PCSTR pszSet
);

int StrToIntW(
    [in] PCWSTR pszSrc
);

BOOL ChrCmpIW(
    [in] WCHAR w1,
    [in] WCHAR w2
);

BOOL PathAppendW(
    [in, out] LPWSTR pszPath,
    [in] LPCWSTR pszMore
);

LSTATUS SHRegSetPathA(
    [in] HKEY hKey,
    [in] LPCSTR pcszSubKey,
    [in] LPCSTR pcszValue,
    [in] LPCSTR pcszPath,
    DWORD dwFlags
);

DWORD StopWatchMode();

LWSTDAPI HashData(
    [in] BYTE *pbData,
    DWORD cbData,
    [out] BYTE *pbHash,
    DWORD cbHash
);

LWSTDAPI StrFormatByteSizeEx(
    ULONGLONG ull,
    SFBS_FLAGS flags,
    [out] PWSTR pszBuf,
    UINT cchBuf
);

LPSTR PathRemoveBackslashA(
    [in, out] LPSTR pszPath
);

LSTATUS SHRegWriteUSValueW(
    [in] HUSKEY hUSKey,
    LPCWSTR pwzValue,
    [in] DWORD dwType,
    [in] const void *pvData,
    [in] DWORD cbData,
    [in] DWORD dwFlags
);

COLORREF ColorHLSToRGB(
    WORD wHue,
    WORD wLuminance,
    WORD wSaturation
);

BOOL PathFindOnPathA(
    [in, out] LPSTR pszPath,
    [in, optional] PZPCSTR ppszOtherDirs
);

PCWSTR StrChrNW(
    [in] PCWSTR pszStart,
    WCHAR wMatch,
    UINT cchMax
);

LPCWSTR PathFindSuffixArrayW(
    [in] LPCWSTR pszPath,
    [in] const LPCWSTR *apszSuffix,
    [in] int iArraySize
);

BOOL PathIsSystemFolderW(
    [in, optional] LPCWSTR pszPath,
    [in] DWORD dwAttrb
);

BOOL SHCreateThread(
    [in] LPTHREAD_START_ROUTINE pfnThreadProc,
    [in, optional] void *pData,
    [in] SHCT_FLAGS flags,
    [in, optional] LPTHREAD_START_ROUTINE pfnCallback
);

int StrCmpICA(
    [in] LPCSTR pszStr1,
    [in] LPCSTR pszStr2
);

BOOL PathIsSystemFolderA(
    [in, optional] LPCSTR pszPath,
    [in] DWORD dwAttrb
);

LWSTDAPI UrlHashW(
    [in] PCWSTR pszUrl,
    [out] BYTE *pbHash,
    DWORD cbHash
);

LWSTDAPI UrlCreateFromPathW(
    [in] PCWSTR pszPath,
    [out] PWSTR pszUrl,
    [in, out] DWORD *pcchUrl,
    DWORD dwFlags
);

LPWSTR PathBuildRootW(
    [out] LPWSTR pszRoot,
    [in] int iDrive
);

LSTATUS SHRegSetUSValueW(
    LPCWSTR pwzSubKey,
    LPCWSTR pwzValue,
    [in] DWORD dwType,
    [in, optional] const void *pvData,
    [in, optional] DWORD cbData,
    [in, optional] DWORD dwFlags
);

void PathUndecorateA(
    [in, out] LPSTR pszPath
);

BOOL PathIsContentTypeW(
    [in] LPCWSTR pszPath,
    [in] LPCWSTR pszContentType
);

BOOL PathIsURLW(
    [in] LPCWSTR pszPath
);

PCWSTR StrChrW(
    [in] PCWSTR pszStart,
    WCHAR wMatch
);

int SHFormatDateTimeW(
    [in] const FILETIME *pft,
    [in, out, optional] DWORD *pdwFlags,
    [out] LPWSTR pszBuf,
    UINT cchBuf
);

BOOL PathMakeSystemFolderA(
    [in] LPCSTR pszPath
);

BOOL PathIsLFNFileSpecA(
    [in] LPCSTR pszName
);

LSTATUS SHRegDeleteUSValueA(
    [in] HUSKEY hUSKey,
    [in] LPCSTR pszValue,
    [in] SHREGDEL_FLAGS delRegFlags
);

PCWSTR StrRChrIW(
    [in] PCWSTR pszStart,
    [in, optional] PCWSTR pszEnd,
    WCHAR wMatch
);

LSTATUS SHSetValueA(
    [in] HKEY hkey,
    [in, optional] LPCSTR pszSubKey,
    [in, optional] LPCSTR pszValue,
    [in] DWORD dwType,
    [in, optional] LPCVOID pvData,
    [in] DWORD cbData
);

LSTATUS SHRegCreateUSKeyA(
    [in] LPCSTR pszPath,
    [in] REGSAM samDesired,
    [in, optional] HUSKEY hRelativeUSKey,
    [out] PHUSKEY phNewUSKey,
    [in] DWORD dwFlags
);

LPCSTR PathSkipRootA(
    [in] LPCSTR pszPath
);

HRESULT SHLocalStrDupW(
    PCWSTR psz,
    [out, optional] PWSTR *ppsz
);

DWORD StrCatChainW(
    [out] PWSTR pszDst,
    DWORD cchDst,
    DWORD ichAt,
    [in] PCWSTR pszSrc
);

BOOL PathUnquoteSpacesW(
    [in, out] LPWSTR lpsz
);

LSTATUS SHRegOpenUSKeyW(
    LPCWSTR pwzPath,
    [in] REGSAM samDesired,
    [in, optional] HUSKEY hRelativeUSKey,
    [out] PHUSKEY phNewUSKey,
    [in] BOOL fIgnoreHKCU
);

BOOL PathUnExpandEnvStringsW(
    [in] LPCWSTR pszPath,
    [out] LPWSTR pszBuf,
    [in] UINT cchBuf
);

BOOL PathFileExistsA(
    [in] LPCSTR pszPath
);

void IntlStrEqNIW(
    [in] s1,
    [in] s2,
    [in] nChar
);

BOOL StrToIntExA(
    [in] PCSTR pszString,
    STIF_FLAGS dwFlags,
    [out] int *piRet
);

BOOL PathRelativePathToW(
    [out] LPWSTR pszPath,
    [in] LPCWSTR pszFrom,
    [in] DWORD dwAttrFrom,
    [in] LPCWSTR pszTo,
    [in] DWORD dwAttrTo
);

BOOL PathMatchSpecW(
    [in] LPCWSTR pszFile,
    [in] LPCWSTR pszSpec
);

BOOL SHUnlockShared(
    [in] void *pvData
);

LSTATUS SHEnumValueW(
    [in] HKEY hkey,
    [in] DWORD dwIndex,
    PWSTR pszValueName,
    [in, out, optional] LPDWORD pcchValueName,
    [out, optional] LPDWORD pdwType,
    void *pvData,
    [in, out, optional] LPDWORD pcbData
);

BOOL SHRegGetBoolUSValueW(
    [in] LPCWSTR pszSubKey,
    [in, optional] LPCWSTR pszValue,
    [in] BOOL fIgnoreHKCU,
    [in] BOOL fDefault
);

LPWSTR PathAddBackslashW(
    [in, out] LPWSTR pszPath
);

BOOL AssocIsDangerous(
    [in] PCWSTR pszAssoc
);

void UrlUnescapeInPlace(
    [in, out] pszUrl,
    [in] dwFlags
);

void PathStripPathA(
    [in, out] LPSTR pszPath
);

BOOL StrIsIntlEqualA(
    BOOL fCaseSens,
    [in] PCSTR pszString1,
    [in] PCSTR pszString2,
    int nChar
);

BOOL UrlIsNoHistoryA(
    [in] PCSTR pszURL
);

int StrCSpnIA(
    [in] PCSTR pszStr,
    [in] PCSTR pszSet
);

BOOL PathMatchSpecA(
    [in] LPCSTR pszFile,
    [in] LPCSTR pszSpec
);

LSTATUS SHRegGetUSValueW(
    [in] LPCWSTR pszSubKey,
    [in, optional] LPCWSTR pszValue,
    [in, out, optional] DWORD *pdwType,
    [out, optional] void *pvData,
    [in, out, optional] DWORD *pcbData,
    [in] BOOL fIgnoreHKCU,
    [in, optional] void *pvDefaultData,
    [in] DWORD dwDefaultDataSize
);

int StrFromTimeIntervalW(
    [out] PWSTR pszOut,
    UINT cchMax,
    DWORD dwTimeMS,
    int digits
);

LWSTDAPI IStream_ReadStr(
    [in] IStream *pstm,
    [out] PWSTR *ppsz
);

LWSTDAPI UrlGetPartA(
    [in] PCSTR pszIn,
    [out] PSTR pszOut,
    [in, out] DWORD *pcchOut,
    DWORD dwPart,
    DWORD dwFlags
);

LSTATUS SHDeleteEmptyKeyW(
    [in] HKEY hkey,
    [in, optional] LPCWSTR pszSubKey
);

BOOL PathAddExtensionA(
    [in, out] LPSTR pszPath,
    [in, optional] LPCSTR pszExt
);

BOOL PathRemoveFileSpecA(
    [in, out] LPSTR pszPath
);

HRESULT SHLocalStrDupA(
    PCSTR psz,
    [out, optional] PSTR *ppsz
);

BOOL IsCharSpaceW(
    [in] WCHAR wch
);

BOOL StrToInt64ExW(
    [in] PCWSTR pszString,
    STIF_FLAGS dwFlags,
    [out] LONGLONG *pllRet
);

BOOL StrIsIntlEqualW(
    BOOL fCaseSens,
    [in] PCWSTR pszString1,
    [in] PCWSTR pszString2,
    int nChar
);

LWSTDAPI ParseURLW(
    [in] LPCWSTR pcszURL,
    [in, out] PARSEDURLW *ppu
);

LSTATUS SHRegQueryUSValueW(
    [in] HUSKEY hUSKey,
    [in, optional] LPCWSTR pszValue,
    [in, out, optional] DWORD *pdwType,
    [out, optional] void *pvData,
    [in, out] DWORD *pcbData,
    [in] BOOL fIgnoreHKCU,
    [in, optional] void *pvDefaultData,
    [in, optional] DWORD dwDefaultDataSize
);

LWSTDAPI UrlGetPartW(
    [in] PCWSTR pszIn,
    [out] PWSTR pszOut,
    [in, out] DWORD *pcchOut,
    DWORD dwPart,
    DWORD dwFlags
);

BOOL IsCharSpaceA(
    [in] CHAR wch
);

LWSTDAPI UrlFixupW(
    [in] PCWSTR pcszUrl,
    [out] PWSTR pszTranslatedUrl,
    DWORD cchMax
);

BOOL StrTrimW(
    [in, out] PWSTR psz,
    [in] PCWSTR pszTrimChars
);

BOOL PathIsUNCServerW(
    [in] LPCWSTR pszPath
);

BOOL PathAppendA(
    [in, out] LPSTR pszPath,
    [in] LPCSTR pszMore
);

int SHUnicodeToUnicode(
    [in] PCWSTR pwzSrc,
    [out] PWSTR pwzDst,
    int cwchBuf
);

BOOL ChrCmpIA(
    [in] WORD w1,
    [in] WORD w2
);

void IntlStrEqNW(
    [in] s1,
    [in] s2,
    [in] nChar
);

PCWSTR StrStrNIW(
    [in] PCWSTR pszFirst,
    [in] PCWSTR pszSrch,
    UINT cchMax
);

int StrCmpW(
    [in] PCWSTR psz1,
    [in] PCWSTR psz2
);

PCSTR StrChrA(
    [in] PCSTR pszStart,
    WORD wMatch
);

LWSTDAPI UrlHashA(
    [in] PCSTR pszUrl,
    [out] BYTE *pbHash,
    DWORD cbHash
);

long SHGlobalCounterGetValue(
    [in] const SHGLOBALCOUNTER id
);

LWSTDAPI UrlCanonicalizeA(
    [in] PCSTR pszUrl,
    [out] PSTR pszCanonicalized,
    [in, out] DWORD *pcchCanonicalized,
    DWORD dwFlags
);

LWSTDAPI StrRetToBSTR(
    [in, out] STRRET *pstr,
    [in] PCUITEMID_CHILD pidl,
    [out] BSTR *pbstr
);

LWSTDAPI AssocQueryKeyW(
    [in] ASSOCF flags,
    [in] ASSOCKEY key,
    [in] LPCWSTR pszAssoc,
    [in] LPCWSTR pszExtra,
    [out] HKEY *phkeyOut
);

BOOL PathSearchAndQualifyW(
    [in] LPCWSTR pszPath,
    [out] LPWSTR pszBuf,
    [in] UINT cchBuf
);

int StrFromTimeIntervalA(
    [out] PSTR pszOut,
    UINT cchMax,
    DWORD dwTimeMS,
    int digits
);

LSTATUS SHRegCreateUSKeyW(
    LPCWSTR pwzPath,
    [in] REGSAM samDesired,
    [in, optional] HUSKEY hRelativeUSKey,
    [out] PHUSKEY phNewUSKey,
    [in] DWORD dwFlags
);

int StrCmpNCW(
    [in] LPCWSTR pszStr1,
    [in] LPCWSTR pszStr2,
    int nChar
);

LSTATUS SHRegGetValueA(
    [in] HKEY hkey,
    [in] LPCSTR pszSubKey,
    [in] LPCSTR pszValue,
    [in] SRRF srrfFlags,
    [in, out] DWORD *pdwType,
    [out] void *pvData,
    [in, out] DWORD *pcbData
);

PCSTR StrRChrIA(
    [in] PCSTR pszStart,
    [in, optional] PCSTR pszEnd,
    WORD wMatch
);

PCSTR StrStrA(
    [in] PCSTR pszFirst,
    [in] PCSTR pszSrch
);

LWSTDAPI SHAutoComplete(
    [in] HWND hwndEdit,
    DWORD dwFlags
);

LPCWSTR PathFindFileNameW(
    [in] LPCWSTR pszPath
);

int PathCommonPrefixA(
    [in] LPCSTR pszFile1,
    [in] LPCSTR pszFile2,
    [out, optional] LPSTR achPath
);

int StrCmpLogicalW(
    [in] PCWSTR psz1,
    [in] PCWSTR psz2
);

void PathUndecorateW(
    [in, out] LPWSTR pszPath
);

LPSTR PathCombineA(
    [out] LPSTR pszDest,
    [in, optional] LPCSTR pszDir,
    [in] LPCSTR pszFile
);

LWSTDAPI PathCreateFromUrlA(
    [in] PCSTR pszUrl,
    [out] PSTR pszPath,
    [in, out] DWORD *pcchPath,
    DWORD dwFlags
);

LWSTDAPI SHCreateThreadRef(
    [in] LONG *pcRef,
    [out] IUnknown **ppunk
);

LWSTDAPI GetAcceptLanguagesW(
    [out] LPWSTR pszLanguages,
    [in, out] DWORD *pcchLanguages
);

BOOL UrlIsNoHistoryW(
    [in] PCWSTR pszURL
);

void PathRemoveBlanksW(
    [in, out] LPWSTR pszPath
);

LSTATUS SHRegEnumUSValueA(
    [in] HUSKEY hUSkey,
    [in] DWORD dwIndex,
    [out] LPSTR pszValueName,
    [in, out] LPDWORD pcchValueName,
    [out, optional] LPDWORD pdwType,
    [out, optional] void *pvData,
    [in, out, optional] LPDWORD pcbData,
    [in] SHREGENUM_FLAGS enumRegFlags
);

BOOL PathUnmakeSystemFolderA(
    [in] LPCSTR pszPath
);

CHAR SHStripMneumonicA(
    [in, out] LPSTR pszMenu
);

LWSTDAPI IUnknown_GetSite(
    [in] IUnknown *punk,
    [in] REFIID riid,
    [out] void **ppv
);

void PathRemoveExtensionA(
    [in, out] LPSTR pszPath
);

PCSTR StrRChrA(
    [in] PCSTR pszStart,
    [in, optional] PCSTR pszEnd,
    WORD wMatch
);

BOOL PathFileExistsW(
    [in] LPCWSTR pszPath
);

int PathParseIconLocationW(
    [in, out] LPWSTR pszIconFile
);

BOOL StrToInt64ExA(
    [in] PCSTR pszString,
    STIF_FLAGS dwFlags,
    [out] LONGLONG *pllRet
);

BOOL PathIsRootW(
    [in] LPCWSTR pszPath
);

HANDLE SHAllocShared(
    [in, optional] const void *pvData,
    [in] DWORD dwSize,
    [in] DWORD dwProcessId
);

int StrSpnA(
    [in] PCSTR psz,
    [in] PCSTR pszSet
);

PWSTR StrNCatW(
    [in, out] PWSTR psz1,
    PCWSTR psz2,
    int cchMax
);

PCWSTR StrStrIW(
    [in] PCWSTR pszFirst,
    [in] PCWSTR pszSrch
);

LSTATUS SHRegSetValue(
    [in] HKEY hkey,
    [in] LPCWSTR pszSubKey,
    [in] LPCWSTR pszValue,
    [in] SRRF srrfFlags,
    [in] DWORD dwType,
    [in] LPCVOID pvData,
    [in] DWORD cbData
);

void MAKEDLLVERULL(
    major,
    minor,
    build,
    qfe
);

void ColorRGBToHLS(
    COLORREF clrRGB,
    [out] WORD *pwHue,
    [out] WORD *pwLuminance,
    [out] WORD *pwSaturation
);

LSTATUS SHRegQueryInfoUSKeyA(
    [in] HUSKEY hUSKey,
    [out, optional] LPDWORD pcSubKeys,
    [out, optional] LPDWORD pcchMaxSubKeyLen,
    [out, optional] LPDWORD pcValues,
    [out, optional] LPDWORD pcchMaxValueNameLen,
    [in] SHREGENUM_FLAGS enumRegFlags
);

int wnsprintfA(
    [out] PSTR pszDest,
    [in] int cchDest,
    [in] PCSTR pszFmt,
    ...
);

PCSTR StrChrIA(
    [in] PCSTR pszStart,
    WORD wMatch
);

int StrCmpCA(
    [out] LPCSTR pszStr1,
    [out] LPCSTR pszStr2
);

HKEY SHRegDuplicateHKey(
    [in] HKEY hkey
);

PSTR StrNCatA(
    [in, out] PSTR psz1,
    PCSTR psz2,
    int cchMax
);

BOOL PathIsRelativeA(
    [in] LPCSTR pszPath
);

LWSTDAPI IUnknown_GetWindow(
    [in] IUnknown *punk,
    [out] HWND *phwnd
);

BOOL PathIsSameRootW(
    [in] LPCWSTR pszPath1,
    [in] LPCWSTR pszPath2
);

LSTATUS SHQueryInfoKeyW(
    [in] HKEY hkey,
    [out, optional] LPDWORD pcSubKeys,
    [out, optional] LPDWORD pcchMaxSubKeyLen,
    [out, optional] LPDWORD pcValues,
    [out, optional] LPDWORD pcchMaxValueNameLen
);

LWSTDAPI AssocQueryKeyA(
    [in] ASSOCF flags,
    [in] ASSOCKEY key,
    [in] LPCSTR pszAssoc,
    [in] LPCSTR pszExtra,
    [out] HKEY *phkeyOut
);

BOOL PathIsURLA(
    [in] LPCSTR pszPath
);

LWSTDAPI SHStrDupA(
    [in] LPCSTR psz,
    [out] LPWSTR *ppwsz
);

LSTATUS SHQueryValueExA(
    [in] HKEY hkey,
    [in, optional] LPCSTR pszValue,
    DWORD *pdwReserved,
    [out, optional] DWORD *pdwType,
    [out, optional] void *pvData,
    [in, out, optional] DWORD *pcbData
);

BOOL PathIsDirectoryA(
    [in] LPCSTR pszPath
);

LSTATUS SHEnumKeyExA(
    [in] HKEY hkey,
    DWORD dwIndex,
    LPSTR pszName,
    [in] LPDWORD pcchName
);

LPCSTR PathFindExtensionA(
    [in] LPCSTR pszPath
);

BOOL PathStripToRootW(
    [in, out] LPWSTR pszPath
);

LSTATUS SHQueryValueExW(
    [in] HKEY hkey,
    [in, optional] LPCWSTR pszValue,
    DWORD *pdwReserved,
    [out, optional] DWORD *pdwType,
    [out, optional] void *pvData,
    [in, out, optional] DWORD *pcbData
);

int StrCmpNA(
    [in] PCSTR psz1,
    [in] PCSTR psz2,
    [in] int nChar
);

int StrCmpCW(
    [out] LPCWSTR pszStr1,
    [out] LPCWSTR pszStr2
);

int SHFormatDateTimeA(
    [in] const FILETIME *pft,
    [in, out, optional] DWORD *pdwFlags,
    [out] LPSTR pszBuf,
    UINT cchBuf
);

LWSTDAPI AssocQueryStringByKeyA(
    [in] ASSOCF flags,
    [in] ASSOCSTR str,
    [in] HKEY hkAssoc,
    [in, optional] LPCSTR pszExtra,
    [out, optional] LPSTR pszOut,
    [in, out] DWORD *pcchOut
);

int SHAnsiToAnsi(
    [in] PCSTR pszSrc,
    [out] PSTR pszDst,
    int cchBuf
);

int PathParseIconLocationA(
    [in, out] LPSTR pszIconFile
);

BOOL PathIsUNCServerShareW(
    [in] LPCWSTR pszPath
);

void PathRemoveArgsA(
    [in, out] LPSTR pszPath
);

PWSTR StrCatW(
    [in, out] PWSTR psz1,
    [in] PCWSTR psz2
);

int StrCmpICW(
    [in] LPCWSTR pszStr1,
    [in] LPCWSTR pszStr2
);

LSTATUS SHSetValueW(
    [in] HKEY hkey,
    [in, optional] LPCWSTR pszSubKey,
    [in, optional] LPCWSTR pszValue,
    [in] DWORD dwType,
    [in, optional] LPCVOID pvData,
    [in] DWORD cbData
);

IStream * SHOpenRegStreamW(
    [in] HKEY hkey,
    [in, optional] LPCWSTR pszSubkey,
    [in, optional] LPCWSTR pszValue,
    [in] DWORD grfMode
);

BOOL UrlIsOpaqueW(
    [in] PCWSTR pszURL
);

LWSTDAPI StrRetToStrW(
    [in, out] STRRET *pstr,
    [in, optional] PCUITEMID_CHILD pidl,
    [out] LPWSTR *ppsz
);

LPCSTR PathFindSuffixArrayA(
    [in] LPCSTR pszPath,
    [in] const LPCSTR *apszSuffix,
    [in] int iArraySize
);

LWSTDAPI SHSetThreadRef(
    [in, optional] IUnknown *punk
);

BOOL PathIsPrefixA(
    [in] LPCSTR pszPrefix,
    [in] LPCSTR pszPath
);

BOOL PathSearchAndQualifyA(
    [in] LPCSTR pszPath,
    [out] LPSTR pszBuf,
    [in] UINT cchBuf
);

BOOL PathIsFileSpecA(
    [in] LPCSTR pszPath
);

LWSTDAPI ConnectToConnectionPoint(
    [in, optional] IUnknown *punk,
    [in] REFIID riidEvent,
    BOOL fConnect,
    [in] IUnknown *punkTarget,
    [out] DWORD *pdwCookie,
    [out, optional] IConnectionPoint **ppcpOut
);

BOOL PathUnquoteSpacesA(
    [in, out] LPSTR lpsz
);

LPCSTR PathFindFileNameA(
    [in] LPCSTR pszPath
);

LSTATUS SHDeleteEmptyKeyA(
    [in] HKEY hkey,
    [in, optional] LPCSTR pszSubKey
);

LSTATUS SHRegGetPathA(
    [in] HKEY hKey,
    [in] LPCSTR pcszSubKey,
    [in] LPCSTR pcszValue,
    [out] LPSTR pszPath,
    DWORD dwFlags
);

PCWSTR StrStrNW(
    [in] PCWSTR pszFirst,
    [in] PCWSTR pszSrch,
    UINT cchMax
);

LPCSTR PathGetArgsA(
    [in] LPCSTR pszPath
);

BOOL PathIsPrefixW(
    [in] LPCWSTR pszPrefix,
    [in] LPCWSTR pszPath
);

LWSTDAPI PathMatchSpecExW(
    [in] LPCWSTR pszFile,
    [in] LPCWSTR pszSpec,
    [in] DWORD dwFlags
);

BOOL PathQuoteSpacesA(
    [in, out] LPSTR lpsz
);

LPSTR PathBuildRootA(
    [out] LPSTR pszRoot,
    [in] int iDrive
);

BOOL PathIsContentTypeA(
    [in] LPCSTR pszPath,
    [in] LPCSTR pszContentType
);

void UrlIsFileUrlA(
    pszURL
);

LWSTDAPI IStream_Size(
    [in] IStream *pstm,
    [out] ULARGE_INTEGER *pui
);

BOOL PathIsRootA(
    [in] LPCSTR pszPath
);

LSTATUS SHRegEnumUSKeyW(
    [in] HUSKEY hUSKey,
    [in] DWORD dwIndex,
    LPWSTR pwzName,
    [in, out] LPDWORD pcchName,
    [in] SHREGENUM_FLAGS enumRegFlags
);

LSTATUS SHRegDeleteEmptyUSKeyW(
    [in] HUSKEY hUSKey,
    LPCWSTR pwzSubKey,
    [in] SHREGDEL_FLAGS delRegFlags
);

BOOL PathIsNetworkPathA(
    [in] LPCSTR pszPath
);

LWSTDAPI AssocQueryStringW(
    [in] ASSOCF flags,
    [in] ASSOCSTR str,
    [in] LPCWSTR pszAssoc,
    [in, optional] LPCWSTR pszExtra,
    [out, optional] LPWSTR pszOut,
    [in, out] DWORD *pcchOut
);

LPWSTR PathRemoveBackslashW(
    [in, out] LPWSTR pszPath
);

IStream * SHOpenRegStreamA(
    [in] HKEY hkey,
    [in, optional] LPCSTR pszSubkey,
    [in, optional] LPCSTR pszValue,
    [in] DWORD grfMode
);

int StrCmpNICW(
    [in] LPCWSTR pszStr1,
    [in] LPCWSTR pszStr2,
    int nChar
);

LWSTDAPI IStream_Write(
    [in] IStream *pstm,
    [in] const void *pv,
    [in] ULONG cb
);

BOOL PathIsFileSpecW(
    [in] LPCWSTR pszPath
);

int StrCmpNICA(
    [in] LPCSTR pszStr1,
    [in] LPCSTR pszStr2,
    int nChar
);

DWORD StopWatchFlush();

BOOL PathIsDirectoryEmptyW(
    [in] LPCWSTR pszPath
);

int StrCmpNW(
    [in] PCWSTR psz1,
    [in] PCWSTR psz2,
    [in] int nChar
);

int SHRegGetIntW(
    [in] HKEY hk,
    [in] PCWSTR pwzKey,
    [in] int iDefault
);

LWSTDAPI UrlEscapeA(
    [in] PCSTR pszUrl,
    [out] PSTR pszEscaped,
    [in, out] DWORD *pcchEscaped,
    DWORD dwFlags
);

PWSTR StrFormatKBSizeW(
    LONGLONG qdw,
    [out] PWSTR pszBuf,
    UINT cchBuf
);

BOOL IntlStrEqWorkerW(
    [in] BOOL fCaseSens,
    [in] LPCWSTR lpString1,
    [in] LPCWSTR lpString2,
    [in] int nChar
);

BOOL PathAddExtensionW(
    [in, out] LPWSTR pszPath,
    [in, optional] LPCWSTR pszExt
);

LPWSTR PathCombineW(
    [out] LPWSTR pszDest,
    [in, optional] LPCWSTR pszDir,
    [in] LPCWSTR pszFile
);

IStream * SHOpenRegStream2W(
    [in] HKEY hkey,
    [in, optional] LPCWSTR pszSubkey,
    [in, optional] LPCWSTR pszValue,
    [in] DWORD grfMode
);

BOOL IntlStrEqWorkerA(
    [in] BOOL fCaseSens,
    [in] LPCSTR lpString1,
    [in] LPCSTR lpString2,
    [in] int nChar
);

LWSTDAPI ParseURLA(
    [in] LPCSTR pcszURL,
    [in, out] PARSEDURLA *ppu
);

BOOL SHCreateThreadWithHandle(
    [in] LPTHREAD_START_ROUTINE pfnThreadProc,
    [in, optional] void *pData,
    [in] SHCT_FLAGS flags,
    [in, optional] LPTHREAD_START_ROUTINE pfnCallback,
    [out, optional] HANDLE *pHandle
);

BOOL StrTrimA(
    [in, out] PSTR psz,
    [in] PCSTR pszTrimChars
);

UINT PathGetCharTypeW(
    [in] WCHAR ch
);

int PathGetDriveNumberW(
    [in] LPCWSTR pszPath
);

LSTATUS SHGetValueA(
    [in] HKEY hkey,
    [in, optional] LPCSTR pszSubKey,
    [in, optional] LPCSTR pszValue,
    [out, optional] DWORD *pdwType,
    [out, optional] void *pvData,
    [in, out, optional] DWORD *pcbData
);

LSTATUS SHEnumKeyExW(
    [in] HKEY hkey,
    DWORD dwIndex,
    LPWSTR pszName,
    [in] LPDWORD pcchName
);

LSTATUS SHRegDeleteUSValueW(
    [in] HUSKEY hUSKey,
    LPCWSTR pwzValue,
    [in] SHREGDEL_FLAGS delRegFlags
);

UINT PathGetCharTypeA(
    [in] UCHAR ch
);

int StrCSpnIW(
    [in] PCWSTR pszStr,
    [in] PCWSTR pszSet
);

LWSTDAPI AssocQueryStringA(
    [in] ASSOCF flags,
    [in] ASSOCSTR str,
    [in] LPCSTR pszAssoc,
    [in, optional] LPCSTR pszExtra,
    [out, optional] LPSTR pszOut,
    [in, out] DWORD *pcchOut
);

BOOL PathIsUNCServerShareA(
    [in] LPCSTR pszPath
);

LWSTDAPI IUnknown_SetSite(
    [in] IUnknown *punk,
    [in] IUnknown *punkSite
);

BOOL PathCompactPathA(
    [in] HDC hDC,
    [in, out] LPSTR pszPath,
    [in] UINT dx
);

BOOL UrlIsOpaqueA(
    [in] PCSTR pszURL
);

BOOL PathUnExpandEnvStringsA(
    [in] LPCSTR pszPath,
    [out] LPSTR pszBuf,
    [in] UINT cchBuf
);

LSTATUS SHRegOpenUSKeyA(
    [in] LPCSTR pszPath,
    [in] REGSAM samDesired,
    [in, optional] HUSKEY hRelativeUSKey,
    [out] PHUSKEY phNewUSKey,
    [in] BOOL fIgnoreHKCU
);

LWSTDAPI AssocCreate(
    [in] CLSID clsid,
    [in] REFIID riid,
    [out] void **ppv
);

BOOL PathIsNetworkPathW(
    [in] LPCWSTR pszPath
);

int PathGetDriveNumberA(
    [in] LPCSTR pszPath
);

LWSTDAPI IStream_Copy(
    [in] IStream *pstmFrom,
    [in] IStream *pstmTo,
    [in] DWORD cb
);

PSTR StrFormatByteSize64A(
    LONGLONG qdw,
    [out] PSTR pszBuf,
    UINT cchBuf
);

int StrSpnW(
    [in] PCWSTR psz,
    [in] PCWSTR pszSet
);

PWSTR StrCpyW(
    [out] PWSTR psz1,
    [in] PCWSTR psz2
);

BOOL PathIsDirectoryW(
    [in] LPCWSTR pszPath
);

HPALETTE SHCreateShellPalette(
    [in, optional] HDC hdc
);

PCSTR StrStrIA(
    [in] PCSTR pszFirst,
    [in] PCSTR pszSrch
);

PSTR StrCatBuffA(
    [in, out] PSTR pszDest,
    [in] PCSTR pszSrc,
    int cchDestBuffSize
);

LSTATUS SHRegGetValueFromHKCUHKLM(
    [in] PCWSTR pwszKey,
    [in] PCWSTR pwszValue,
    [in] SRRF srrfFlags,
    [out] DWORD *pdwType,
    [in] void *pvData,
    [in, out] DWORD *pcbData
);

BOOL PathCompactPathExA(
    [out] LPSTR pszOut,
    [in] LPCSTR pszSrc,
    [in] UINT cchMax,
    [in] DWORD dwFlags
);

int StrCmpIW(
    [in] PCWSTR psz1,
    [in] PCWSTR psz2
);

void PathRemoveBlanksA(
    [in, out] LPSTR pszPath
);

BOOL PathMakePrettyA(
    [in, out] LPSTR pszPath
);

void UrlEscapeSpaces(
    [in] pszUrl,
    [out] pszEscaped,
    [out] pcchEscaped
);

PCWSTR StrPBrkW(
    [in] PCWSTR psz,
    [in] PCWSTR pszSet
);

BOOL PathIsSameRootA(
    [in] LPCSTR pszPath1,
    [in] LPCSTR pszPath2
);

LSTATUS SHRegEnumUSValueW(
    [in] HUSKEY hUSkey,
    [in] DWORD dwIndex,
    [out] LPWSTR pszValueName,
    [in, out] LPDWORD pcchValueName,
    [out, optional] LPDWORD pdwType,
    [out, optional] void *pvData,
    [in, out, optional] LPDWORD pcbData,
    [in] SHREGENUM_FLAGS enumRegFlags
);

LSTATUS SHQueryInfoKeyA(
    [in] HKEY hkey,
    [out, optional] LPDWORD pcSubKeys,
    [out, optional] LPDWORD pcchMaxSubKeyLen,
    [out, optional] LPDWORD pcValues,
    [out, optional] LPDWORD pcchMaxValueNameLen
);

int StrCmpNIW(
    [in] PCWSTR psz1,
    [in] PCWSTR psz2,
    [in] int nChar
);

BOOL PathIsLFNFileSpecW(
    [in] LPCWSTR pszName
);

BOOL PathRenameExtensionW(
    [in, out] LPWSTR pszPath,
    [in] LPCWSTR pszExt
);

void UrlIsFileUrlW(
    pszURL
);

LSTATUS SHRegGetUSValueA(
    [in] LPCSTR pszSubKey,
    [in, optional] LPCSTR pszValue,
    [in, out, optional] DWORD *pdwType,
    [out, optional] void *pvData,
    [in, out, optional] DWORD *pcbData,
    [in] BOOL fIgnoreHKCU,
    [in, optional] void *pvDefaultData,
    [in] DWORD dwDefaultDataSize
);

LWSTDAPI StrRetToBufA(
    [in, out] STRRET *pstr,
    [in] PCUITEMID_CHILD pidl,
    [out] LPSTR pszBuf,
    [in] UINT cchBuf
);

LWSTDAPI IUnknown_QueryService(
    [in] IUnknown *punk,
    [in] REFGUID guidService,
    [in] REFIID riid,
    [out] void **ppvOut
);

int SHUnicodeToAnsi(
    [in] PCWSTR pwszSrc,
    [out] PSTR pszDst,
    int cchBuf
);

LWSTDAPI GetAcceptLanguagesA(
    [out] LPSTR pszLanguages,
    [in, out] DWORD *pcchLanguages
);

LRESULT SHSendMessageBroadcastW(
    [in] UINT uMsg,
    [in] WPARAM wParam,
    [in] LPARAM lParam
);

LWSTDAPI UrlUnescapeA(
    [in, out] PSTR pszUrl,
    [out, optional] PSTR pszUnescaped,
    [in, out, optional] DWORD *pcchUnescaped,
    DWORD dwFlags
);

HRESULT QISearch(
    [in] void *that,
    [in] LPCQITAB pqit,
    [in] REFIID riid,
    [out] void **ppv
);

LSTATUS SHEnumValueA(
    [in] HKEY hkey,
    [in] DWORD dwIndex,
    PSTR pszValueName,
    [in, out, optional] LPDWORD pcchValueName,
    [out, optional] LPDWORD pdwType,
    void *pvData,
    [in, out, optional] LPDWORD pcbData
);

BOOL PathMakeSystemFolderW(
    [in] LPCWSTR pszPath
);

BOOL PathCanonicalizeW(
    [out] LPWSTR pszBuf,
    [in] LPCWSTR pszPath
);

LWSTDAPI GetProcessReference(
    [out] IUnknown **punk
);

BOOL SHIsLowMemoryMachine(
    [in] DWORD dwType
);

PCSTR StrPBrkA(
    [in] PCSTR psz,
    [in] PCSTR pszSet
);

LSTATUS SHCopyKeyW(
    [in] HKEY hkeySrc,
    [in, optional] LPCWSTR pszSrcSubKey,
    [in] HKEY hkeyDest,
    DWORD fReserved
);

HRESULT DllInstall(
    BOOL bInstall,
    [in, optional] PCWSTR pszCmdLine
);

void IntlStrEqNIA(
    [in] s1,
    [in] s2,
    [in] nChar
);

BOOL PathUnmakeSystemFolderW(
    [in] LPCWSTR pszPath
);

IStream * SHCreateMemStream(
    [in, optional] const BYTE *pInit,
    [in] UINT cbInit
);

LSTATUS SHRegSetPathW(
    [in] HKEY hKey,
    [in] LPCWSTR pcszSubKey,
    [in] LPCWSTR pcszValue,
    [in] LPCWSTR pcszPath,
    DWORD dwFlags
);

LSTATUS SHRegQueryInfoUSKeyW(
    [in] HUSKEY hUSKey,
    [out, optional] LPDWORD pcSubKeys,
    [out, optional] LPDWORD pcchMaxSubKeyLen,
    [out, optional] LPDWORD pcValues,
    [out, optional] LPDWORD pcchMaxValueNameLen,
    [in] SHREGENUM_FLAGS enumRegFlags
);

LWSTDAPI PathCreateFromUrlW(
    [in] PCWSTR pszUrl,
    [out] PWSTR pszPath,
    [in, out] DWORD *pcchPath,
    DWORD dwFlags
);

BOOL PathRenameExtensionA(
    [in, out] LPSTR pszPath,
    [in] LPCSTR pszExt
);

LWSTDAPI PathMatchSpecExA(
    [in] LPCSTR pszFile,
    [in] LPCSTR pszSpec,
    [in] DWORD dwFlags
);

LWSTDAPI UrlUnescapeW(
    [in, out] PWSTR pszUrl,
    [out, optional] PWSTR pszUnescaped,
    [in, out, optional] DWORD *pcchUnescaped,
    DWORD dwFlags
);

LSTATUS SHRegQueryUSValueA(
    [in] HUSKEY hUSKey,
    [in, optional] LPCSTR pszValue,
    [in, out, optional] DWORD *pdwType,
    [out, optional] void *pvData,
    [in, out] DWORD *pcbData,
    [in] BOOL fIgnoreHKCU,
    [in, optional] void *pvDefaultData,
    [in, optional] DWORD dwDefaultDataSize
);

int SHAnsiToUnicode(
    [in] PCSTR pszSrc,
    [out] PWSTR pwszDst,
    int cwchBuf
);

int SHMessageBoxCheckA(
    [in, optional] HWND hwnd,
    [in] LPCSTR pszText,
    [in] LPCSTR pszCaption,
    UINT uType,
    int iDefault,
    [in] LPCSTR pszRegVal
);

int StrCSpnW(
    [in] PCWSTR pszStr,
    [in] PCWSTR pszSet
);

PSTR StrDupA(
    PCSTR pszSrch
);

LWSTDAPI SHLoadIndirectString(
    [in] PCWSTR pszSource,
    [out] PWSTR pszOutBuf,
    [in] UINT cchOutBuf,
    void **ppvReserved
);

LSTATUS SHCopyKeyA(
    [in] HKEY hkeySrc,
    [in, optional] LPCSTR pszSrcSubKey,
    [in] HKEY hkeyDest,
    DWORD fReserved
);

LSTATUS SHDeleteKeyA(
    [in] HKEY hkey,
    [in, optional] LPCSTR pszSubKey
);

void * SHLockShared(
    [in] HANDLE hData,
    [in] DWORD dwProcessId
);

LWSTDAPI PathCreateFromUrlAlloc(
    [in] PCWSTR pszIn,
    [out] PWSTR *ppszOut,
    DWORD dwFlags
);

BOOL SHRegGetBoolValueFromHKCUHKLM(
    PCWSTR pszKey,
    [in] PCWSTR pszValue,
    [in] BOOL fDefault
);

BOOL PathStripToRootA(
    [in, out] LPSTR pszPath
);

LSTATUS SHRegGetPathW(
    [in] HKEY hKey,
    [in] LPCWSTR pcszSubKey,
    [in] LPCWSTR pcszValue,
    [out] LPWSTR pszPath,
    DWORD dwFlags
);

int wvnsprintfA(
    [out] PSTR pszDest,
    [in] int cchDest,
    [in] PCSTR pszFmt,
    [in] va_list arglist
);

LWSTDAPI UrlCanonicalizeW(
    [in] PCWSTR pszUrl,
    [out] PWSTR pszCanonicalized,
    [in, out] DWORD *pcchCanonicalized,
    DWORD dwFlags
);

int StrCmpNIA(
    [in] PCSTR psz1,
    [in] PCSTR psz2,
    [in] int nChar
);

LSTATUS SHRegSetUSValueA(
    [in] LPCSTR pszSubKey,
    [in] LPCSTR pszValue,
    [in] DWORD dwType,
    [in, optional] const void *pvData,
    [in, optional] DWORD cbData,
    [in, optional] DWORD dwFlags
);

void IntlStrEqNA(
    [in] s1,
    [in] s2,
    [in] nChar
);

LWSTDAPI StrRetToBufW(
    [in, out] STRRET *pstr,
    [in] PCUITEMID_CHILD pidl,
    [out] LPWSTR pszBuf,
    [in] UINT cchBuf
);

LWSTDAPI UrlCombineW(
    [in] PCWSTR pszBase,
    [in] PCWSTR pszRelative,
    [out, optional] PWSTR pszCombined,
    [in, out] DWORD *pcchCombined,
    DWORD dwFlags
);

BOOL PathMakePrettyW(
    [in, out] LPWSTR pszPath
);

BOOL SHFreeShared(
    [in] HANDLE hData,
    [in] DWORD dwProcessId
);

void PathSetDlgItemPathW(
    [in] HWND hDlg,
    [in] int id,
    [in] LPCWSTR pszPath
);

BOOL PathCanonicalizeA(
    [out] LPSTR pszBuf,
    [in] LPCSTR pszPath
);

BOOL PathIsDirectoryEmptyA(
    [in] LPCSTR pszPath
);

LPCWSTR PathGetArgsW(
    [in] LPCWSTR pszPath
);

LSTATUS SHDeleteValueA(
    HKEY hkey,
    LPCSTR pszSubKey,
    LPCSTR pszValue
);

int SHMessageBoxCheckW(
    [in, optional] HWND hwnd,
    [in] LPCWSTR pszText,
    [in] LPCWSTR pszCaption,
    UINT uType,
    int iDefault,
    [in] LPCWSTR pszRegVal
);

int wnsprintfW(
    [out] PWSTR pszDest,
    [in] int cchDest,
    [in] PCWSTR pszFmt,
    ...
);

void IUnknown_Set(
    [in, out] IUnknown **ppunk,
    [in, optional] IUnknown *punk
);

LSTATUS SHRegCloseUSKey(
    [in] HUSKEY hUSKey
);

BOOL PathCompactPathExW(
    [out] LPWSTR pszOut,
    [in] LPCWSTR pszSrc,
    [in] UINT cchMax,
    [in] DWORD dwFlags
);

int StrToIntA(
    [in] PCSTR pszSrc
);

long SHGlobalCounterDecrement(
    [in] const SHGLOBALCOUNTER id
);

PCWSTR StrRChrW(
    [in] PCWSTR pszStart,
    [in, optional] PCWSTR pszEnd,
    WCHAR wMatch
);

LWSTDAPI AssocGetPerceivedType(
    [in] PCWSTR pszExt,
    [out] PERCEIVED *ptype,
    [out] PERCEIVEDFLAG *pflag,
    [out, optional] PWSTR *ppszType
);

BOOL PathFindOnPathW(
    [in, out] LPWSTR pszPath,
    [in, optional] PZPCWSTR ppszOtherDirs
);

LWSTDAPI UrlEscapeW(
    [in] PCWSTR pszUrl,
    [out] PWSTR pszEscaped,
    [in, out] DWORD *pcchEscaped,
    DWORD dwFlags
);

LWSTDAPI UrlApplySchemeW(
    [in] PCWSTR pszIn,
    [out] PWSTR pszOut,
    [in, out] DWORD *pcchOut,
    DWORD dwFlags
);

LWSTDAPI IStream_Read(
    [in] IStream *pstm,
    [out] void *pv,
    [in] ULONG cb
);

IStream * SHOpenRegStream2A(
    [in] HKEY hkey,
    [in, optional] LPCSTR pszSubkey,
    [in, optional] LPCSTR pszValue,
    [in] DWORD grfMode
);

BOOL PathIsUNCA(
    [in] LPCSTR pszPath
);

PWSTR StrCpyNW(
    [out] PWSTR pszDst,
    [in] PCWSTR pszSrc,
    int cchMax
);

WCHAR SHStripMneumonicW(
    [in, out] LPWSTR pszMenu
);

void PathRemoveExtensionW(
    [in, out] LPWSTR pszPath
);

LPCWSTR PathFindExtensionW(
    [in] LPCWSTR pszPath
);

LPCWSTR UrlGetLocationW(
    [in] PCWSTR pszURL
);

LSTATUS SHRegDeleteEmptyUSKeyA(
    [in] HUSKEY hUSKey,
    [in] LPCSTR pszSubKey,
    [in] SHREGDEL_FLAGS delRegFlags
);

LSTATUS SHGetValueW(
    [in] HKEY hkey,
    [in, optional] LPCWSTR pszSubKey,
    [in, optional] LPCWSTR pszValue,
    [out, optional] DWORD *pdwType,
    [out, optional] void *pvData,
    [in, out, optional] DWORD *pcbData
);

PWSTR StrCatBuffW(
    [in, out] PWSTR pszDest,
    [in] PCWSTR pszSrc,
    int cchDestBuffSize
);

PCSTR StrRStrIA(
    [in] PCSTR pszSource,
    [in, optional] PCSTR pszLast,
    [in] PCSTR pszSrch
);

LWSTDAPI UrlApplySchemeA(
    [in] PCSTR pszIn,
    [out] PSTR pszOut,
    [in, out] DWORD *pcchOut,
    DWORD dwFlags
);

COLORREF ColorAdjustLuma(
    COLORREF clrRGB,
    int n,
    BOOL fScale
);

PSTR StrFormatByteSizeA(
    DWORD dw,
    [out] PSTR pszBuf,
    UINT cchBuf
);

LPCSTR UrlGetLocationA(
    [in] PCSTR pszURL
);

PCWSTR StrStrW(
    [in] PCWSTR pszFirst,
    [in] PCWSTR pszSrch
);

BOOL PathIsUNCW(
    [in] LPCWSTR pszPath
);

void IUnknown_AtomicRelease(
    [in, out, optional] void **ppunk
);

BOOL StrToIntExW(
    [in] PCWSTR pszString,
    STIF_FLAGS dwFlags,
    [out] int *piRet
);

BOOL SHSkipJunction(
    [in, optional] IBindCtx *pbc,
    [in] const CLSID *pclsid
);

void PathSetDlgItemPathA(
    [in] HWND hDlg,
    [in] int id,
    [in] LPCSTR pszPath
);

int UrlCompareW(
    [in] PCWSTR psz1,
    [in] PCWSTR psz2,
    BOOL fIgnoreSlash
);

LWSTDAPI AssocQueryStringByKeyW(
    [in] ASSOCF flags,
    [in] ASSOCSTR str,
    [in] HKEY hkAssoc,
    [in, optional] LPCWSTR pszExtra,
    [out, optional] LPWSTR pszOut,
    [in, out] DWORD *pcchOut
);

DWORD SHGetAssocKeys(
    [in] IQueryAssociations *pqa,
    [out] HKEY *rgKeys,
    DWORD cKeys
);

BOOL IsOS(
    [in] DWORD dwOS
);

void SetProcessReference(
    [in, optional] IUnknown *punk
);

void PathIsHTMLFileW(
    [in] pszPath
);

BOOL UrlIsA(
    [in] PCSTR pszUrl,
    URLIS UrlIs
);

void PathIsHTMLFileA(
    [in] pszPath
);

BOOL PathRemoveFileSpecW(
    [in, out] LPWSTR pszPath
);

LPCWSTR PathSkipRootW(
    [in] LPCWSTR pszPath
);

PCWSTR StrRStrIW(
    [in] PCWSTR pszSource,
    [in, optional] PCWSTR pszLast,
    [in] PCWSTR pszSrch
);

