DWORD InitiateShutdownW(
    [in, optional] LPWSTR lpMachineName,
    [in, optional] LPWSTR lpMessage,
    [in] DWORD dwGracePeriod,
    [in] DWORD dwShutdownFlags,
    [in] DWORD dwReason
);

LSTATUS RegDeleteValueW(
    [in] HKEY hKey,
    [in, optional] LPCWSTR lpValueName
);

LSTATUS RegCreateKeyExA(
    [in] HKEY hKey,
    [in] LPCSTR lpSubKey,
    DWORD Reserved,
    [in, optional] LPSTR lpClass,
    [in] DWORD dwOptions,
    [in] REGSAM samDesired,
    [in, optional] const LPSECURITY_ATTRIBUTES lpSecurityAttributes,
    [out] PHKEY phkResult,
    [out, optional] LPDWORD lpdwDisposition
);

LSTATUS RegSaveKeyExW(
    [in] HKEY hKey,
    [in] LPCWSTR lpFile,
    [in, optional] const LPSECURITY_ATTRIBUTES lpSecurityAttributes,
    [in] DWORD Flags
);

LSTATUS RegCreateKeyA(
    [in] HKEY hKey,
    [in, optional] LPCSTR lpSubKey,
    [out] PHKEY phkResult
);

LSTATUS RegConnectRegistryA(
    [in, optional] LPCSTR lpMachineName,
    [in] HKEY hKey,
    [out] PHKEY phkResult
);

LSTATUS RegEnumKeyExA(
    [in] HKEY hKey,
    [in] DWORD dwIndex,
    [out] LPSTR lpName,
    [in, out] LPDWORD lpcchName,
    LPDWORD lpReserved,
    [in, out] LPSTR lpClass,
    [in, out, optional] LPDWORD lpcchClass,
    [out, optional] PFILETIME lpftLastWriteTime
);

LSTATUS RegLoadAppKeyA(
    [in] LPCSTR lpFile,
    [out] PHKEY phkResult,
    [in] REGSAM samDesired,
    [in] DWORD dwOptions,
    DWORD Reserved
);

LSTATUS RegLoadMUIStringW(
    [in] HKEY hKey,
    [in, optional] LPCWSTR pszValue,
    [out, optional] LPWSTR pszOutBuf,
    [in] DWORD cbOutBuf,
    [out, optional] LPDWORD pcbData,
    [in] DWORD Flags,
    [in, optional] LPCWSTR pszDirectory
);

LSTATUS RegDeleteKeyValueW(
    [in] HKEY hKey,
    [in, optional] LPCWSTR lpSubKey,
    [in, optional] LPCWSTR lpValueName
);

BOOL AbortSystemShutdownW(
    [in, optional] LPWSTR lpMachineName
);

LONG RegDisableReflectionKey(
    [in] HKEY hBase
);

LSTATUS RegSetValueExW(
    [in] HKEY hKey,
    [in, optional] LPCWSTR lpValueName,
    DWORD Reserved,
    [in] DWORD dwType,
    [in] const BYTE *lpData,
    [in] DWORD cbData
);

LSTATUS RegLoadAppKeyW(
    [in] LPCWSTR lpFile,
    [out] PHKEY phkResult,
    [in] REGSAM samDesired,
    [in] DWORD dwOptions,
    DWORD Reserved
);

LSTATUS RegDeleteKeyA(
    [in] HKEY hKey,
    [in] LPCSTR lpSubKey
);

LSTATUS RegDeleteKeyExW(
    [in] HKEY hKey,
    [in] LPCWSTR lpSubKey,
    [in] REGSAM samDesired,
    DWORD Reserved
);

LSTATUS RegDeleteKeyValueA(
    [in] HKEY hKey,
    [in, optional] LPCSTR lpSubKey,
    [in, optional] LPCSTR lpValueName
);

LSTATUS RegLoadKeyW(
    [in] HKEY hKey,
    [in, optional] LPCWSTR lpSubKey,
    [in] LPCWSTR lpFile
);

LSTATUS RegQueryValueExA(
    [in] HKEY hKey,
    [in, optional] LPCSTR lpValueName,
    LPDWORD lpReserved,
    [out, optional] LPDWORD lpType,
    [out, optional] LPBYTE lpData,
    [in, out, optional] LPDWORD lpcbData
);

LSTATUS RegDeleteTreeW(
    [in] HKEY hKey,
    [in, optional] LPCWSTR lpSubKey
);

BOOL AbortSystemShutdownA(
    [in, optional] LPSTR lpMachineName
);

LSTATUS RegCopyTreeW(
    [in] HKEY hKeySrc,
    [in, optional] LPCWSTR lpSubKey,
    [in] HKEY hKeyDest
);

LSTATUS RegSetKeyValueA(
    [in] HKEY hKey,
    [in, optional] LPCSTR lpSubKey,
    [in, optional] LPCSTR lpValueName,
    [in] DWORD dwType,
    [in, optional] LPCVOID lpData,
    [in] DWORD cbData
);

DWORD InitiateShutdownA(
    [in, optional] LPSTR lpMachineName,
    [in, optional] LPSTR lpMessage,
    [in] DWORD dwGracePeriod,
    [in] DWORD dwShutdownFlags,
    [in] DWORD dwReason
);

LSTATUS RegCreateKeyTransactedW(
    [in] HKEY hKey,
    [in] LPCWSTR lpSubKey,
    DWORD Reserved,
    [in, optional] LPWSTR lpClass,
    [in] DWORD dwOptions,
    [in] REGSAM samDesired,
    [in, optional] const LPSECURITY_ATTRIBUTES lpSecurityAttributes,
    [out] PHKEY phkResult,
    [out, optional] LPDWORD lpdwDisposition,
    [in] HANDLE hTransaction,
    PVOID pExtendedParemeter
);

LONG RegEnableReflectionKey(
    [in] HKEY hBase
);

LSTATUS RegSetValueW(
    [in] HKEY hKey,
    [in, optional] LPCWSTR lpSubKey,
    [in] DWORD dwType,
    [in] LPCWSTR lpData,
    [in] DWORD cbData
);

LSTATUS RegUnLoadKeyA(
    [in] HKEY hKey,
    [in, optional] LPCSTR lpSubKey
);

LSTATUS RegOpenKeyTransactedA(
    [in] HKEY hKey,
    [in, optional] LPCSTR lpSubKey,
    [in] DWORD ulOptions,
    [in] REGSAM samDesired,
    [out] PHKEY phkResult,
    [in] HANDLE hTransaction,
    PVOID pExtendedParemeter
);

LSTATUS RegUnLoadKeyW(
    [in] HKEY hKey,
    [in, optional] LPCWSTR lpSubKey
);

LSTATUS RegSetKeyValueW(
    [in] HKEY hKey,
    [in, optional] LPCWSTR lpSubKey,
    [in, optional] LPCWSTR lpValueName,
    [in] DWORD dwType,
    [in, optional] LPCVOID lpData,
    [in] DWORD cbData
);

LSTATUS RegQueryInfoKeyA(
    [in] HKEY hKey,
    [out, optional] LPSTR lpClass,
    [in, out, optional] LPDWORD lpcchClass,
    LPDWORD lpReserved,
    [out, optional] LPDWORD lpcSubKeys,
    [out, optional] LPDWORD lpcbMaxSubKeyLen,
    [out, optional] LPDWORD lpcbMaxClassLen,
    [out, optional] LPDWORD lpcValues,
    [out, optional] LPDWORD lpcbMaxValueNameLen,
    [out, optional] LPDWORD lpcbMaxValueLen,
    [out, optional] LPDWORD lpcbSecurityDescriptor,
    [out, optional] PFILETIME lpftLastWriteTime
);

LSTATUS RegDeleteKeyTransactedA(
    [in] HKEY hKey,
    [in] LPCSTR lpSubKey,
    [in] REGSAM samDesired,
    DWORD Reserved,
    [in] HANDLE hTransaction,
    PVOID pExtendedParameter
);

LSTATUS RegLoadKeyA(
    [in] HKEY hKey,
    [in, optional] LPCSTR lpSubKey,
    [in] LPCSTR lpFile
);

LSTATUS RegGetKeySecurity(
    [in] HKEY hKey,
    [in] SECURITY_INFORMATION SecurityInformation,
    [out, optional] PSECURITY_DESCRIPTOR pSecurityDescriptor,
    [in, out] LPDWORD lpcbSecurityDescriptor
);

LONG RegQueryReflectionKey(
    [in] HKEY hBase,
    [out] BOOL *bIsReflectionDisabled
);

LSTATUS RegSetKeySecurity(
    [in] HKEY hKey,
    [in] SECURITY_INFORMATION SecurityInformation,
    [in] PSECURITY_DESCRIPTOR pSecurityDescriptor
);

LSTATUS RegDeleteKeyTransactedW(
    [in] HKEY hKey,
    [in] LPCWSTR lpSubKey,
    [in] REGSAM samDesired,
    DWORD Reserved,
    [in] HANDLE hTransaction,
    PVOID pExtendedParameter
);

LSTATUS RegQueryMultipleValuesW(
    [in] HKEY hKey,
    [out] PVALENTW val_list,
    [in] DWORD num_vals,
    [out, optional] LPWSTR lpValueBuf,
    [in, out, optional] LPDWORD ldwTotsize
);

LSTATUS RegSetValueExA(
    [in] HKEY hKey,
    [in, optional] LPCSTR lpValueName,
    DWORD Reserved,
    [in] DWORD dwType,
    [in] const BYTE *lpData,
    [in] DWORD cbData
);

LSTATUS RegDeleteKeyExA(
    [in] HKEY hKey,
    [in] LPCSTR lpSubKey,
    [in] REGSAM samDesired,
    DWORD Reserved
);

LSTATUS RegRestoreKeyW(
    [in] HKEY hKey,
    [in] LPCWSTR lpFile,
    [in] DWORD dwFlags
);

LSTATUS RegQueryValueW(
    [in] HKEY hKey,
    [in, optional] LPCWSTR lpSubKey,
    [out, optional] LPWSTR lpData,
    [in, out, optional] PLONG lpcbData
);

LSTATUS RegQueryInfoKeyW(
    [in] HKEY hKey,
    [out, optional] LPWSTR lpClass,
    [in, out, optional] LPDWORD lpcchClass,
    LPDWORD lpReserved,
    [out, optional] LPDWORD lpcSubKeys,
    [out, optional] LPDWORD lpcbMaxSubKeyLen,
    [out, optional] LPDWORD lpcbMaxClassLen,
    [out, optional] LPDWORD lpcValues,
    [out, optional] LPDWORD lpcbMaxValueNameLen,
    [out, optional] LPDWORD lpcbMaxValueLen,
    [out, optional] LPDWORD lpcbSecurityDescriptor,
    [out, optional] PFILETIME lpftLastWriteTime
);

BOOL InitiateSystemShutdownA(
    [in, optional] LPSTR lpMachineName,
    [in, optional] LPSTR lpMessage,
    [in] DWORD dwTimeout,
    [in] BOOL bForceAppsClosed,
    [in] BOOL bRebootAfterShutdown
);

LSTATUS RegDeleteValueA(
    [in] HKEY hKey,
    [in, optional] LPCSTR lpValueName
);

LSTATUS RegCreateKeyW(
    [in] HKEY hKey,
    [in, optional] LPCWSTR lpSubKey,
    [out] PHKEY phkResult
);

LSTATUS RegCopyTreeA(
    [in] HKEY hKeySrc,
    [in, optional] LPCSTR lpSubKey,
    [in] HKEY hKeyDest
);

LSTATUS RegCreateKeyExW(
    [in] HKEY hKey,
    [in] LPCWSTR lpSubKey,
    DWORD Reserved,
    [in, optional] LPWSTR lpClass,
    [in] DWORD dwOptions,
    [in] REGSAM samDesired,
    [in, optional] const LPSECURITY_ATTRIBUTES lpSecurityAttributes,
    [out] PHKEY phkResult,
    [out, optional] LPDWORD lpdwDisposition
);

LSTATUS RegOpenKeyW(
    [in] HKEY hKey,
    [in, optional] LPCWSTR lpSubKey,
    [out] PHKEY phkResult
);

LSTATUS RegEnumValueA(
    [in] HKEY hKey,
    [in] DWORD dwIndex,
    [out] LPSTR lpValueName,
    [in, out] LPDWORD lpcchValueName,
    LPDWORD lpReserved,
    [out, optional] LPDWORD lpType,
    [out, optional] LPBYTE lpData,
    [in, out, optional] LPDWORD lpcbData
);

LSTATUS RegOpenUserClassesRoot(
    [in] HANDLE hToken,
    DWORD dwOptions,
    [in] REGSAM samDesired,
    [out] PHKEY phkResult
);

BOOL InitiateSystemShutdownExA(
    [in, optional] LPSTR lpMachineName,
    [in, optional] LPSTR lpMessage,
    [in] DWORD dwTimeout,
    [in] BOOL bForceAppsClosed,
    [in] BOOL bRebootAfterShutdown,
    [in] DWORD dwReason
);

LSTATUS RegOpenKeyTransactedW(
    [in] HKEY hKey,
    [in, optional] LPCWSTR lpSubKey,
    [in] DWORD ulOptions,
    [in] REGSAM samDesired,
    [out] PHKEY phkResult,
    [in] HANDLE hTransaction,
    PVOID pExtendedParemeter
);

LSTATUS RegEnumValueW(
    [in] HKEY hKey,
    [in] DWORD dwIndex,
    [out] LPWSTR lpValueName,
    [in, out] LPDWORD lpcchValueName,
    LPDWORD lpReserved,
    [out, optional] LPDWORD lpType,
    [out, optional] LPBYTE lpData,
    [in, out, optional] LPDWORD lpcbData
);

LSTATUS RegDisablePredefinedCache();

LSTATUS RegOpenKeyExA(
    [in] HKEY hKey,
    [in, optional] LPCSTR lpSubKey,
    [in] DWORD ulOptions,
    [in] REGSAM samDesired,
    [out] PHKEY phkResult
);

BOOL InitiateSystemShutdownExW(
    [in, optional] LPWSTR lpMachineName,
    [in, optional] LPWSTR lpMessage,
    [in] DWORD dwTimeout,
    [in] BOOL bForceAppsClosed,
    [in] BOOL bRebootAfterShutdown,
    [in] DWORD dwReason
);

LSTATUS RegOpenKeyA(
    [in] HKEY hKey,
    [in, optional] LPCSTR lpSubKey,
    [out] PHKEY phkResult
);

LSTATUS RegRestoreKeyA(
    [in] HKEY hKey,
    [in] LPCSTR lpFile,
    [in] DWORD dwFlags
);

LSTATUS RegEnumKeyW(
    [in] HKEY hKey,
    [in] DWORD dwIndex,
    [out] LPWSTR lpName,
    [in] DWORD cchName
);

LSTATUS RegDeleteKeyW(
    [in] HKEY hKey,
    [in] LPCWSTR lpSubKey
);

LSTATUS RegCreateKeyTransactedA(
    [in] HKEY hKey,
    [in] LPCSTR lpSubKey,
    DWORD Reserved,
    [in, optional] LPSTR lpClass,
    [in] DWORD dwOptions,
    [in] REGSAM samDesired,
    [in, optional] const LPSECURITY_ATTRIBUTES lpSecurityAttributes,
    [out] PHKEY phkResult,
    [out, optional] LPDWORD lpdwDisposition,
    [in] HANDLE hTransaction,
    PVOID pExtendedParemeter
);

LSTATUS RegSaveKeyA(
    [in] HKEY hKey,
    [in] LPCSTR lpFile,
    [in, optional] const LPSECURITY_ATTRIBUTES lpSecurityAttributes
);

LSTATUS RegFlushKey(
    [in] HKEY hKey
);

LSTATUS RegSaveKeyW(
    [in] HKEY hKey,
    [in] LPCWSTR lpFile,
    [in, optional] const LPSECURITY_ATTRIBUTES lpSecurityAttributes
);

LSTATUS RegReplaceKeyA(
    [in] HKEY hKey,
    [in, optional] LPCSTR lpSubKey,
    [in] LPCSTR lpNewFile,
    [in] LPCSTR lpOldFile
);

LSTATUS RegLoadMUIStringA(
    [in] HKEY hKey,
    [in, optional] LPCSTR pszValue,
    [out, optional] LPSTR pszOutBuf,
    [in] DWORD cbOutBuf,
    [out, optional] LPDWORD pcbData,
    [in] DWORD Flags,
    [in, optional] LPCSTR pszDirectory
);

BOOL InitiateSystemShutdownW(
    [in, optional] LPWSTR lpMachineName,
    [in, optional] LPWSTR lpMessage,
    [in] DWORD dwTimeout,
    [in] BOOL bForceAppsClosed,
    [in] BOOL bRebootAfterShutdown
);

LSTATUS RegNotifyChangeKeyValue(
    [in] HKEY hKey,
    [in] BOOL bWatchSubtree,
    [in] DWORD dwNotifyFilter,
    [in, optional] HANDLE hEvent,
    [in] BOOL fAsynchronous
);

LSTATUS RegOpenKeyExW(
    [in] HKEY hKey,
    [in, optional] LPCWSTR lpSubKey,
    [in] DWORD ulOptions,
    [in] REGSAM samDesired,
    [out] PHKEY phkResult
);

LSTATUS RegEnumKeyA(
    [in] HKEY hKey,
    [in] DWORD dwIndex,
    [out] LPSTR lpName,
    [in] DWORD cchName
);

LSTATUS RegReplaceKeyW(
    [in] HKEY hKey,
    [in, optional] LPCWSTR lpSubKey,
    [in] LPCWSTR lpNewFile,
    [in] LPCWSTR lpOldFile
);

LSTATUS RegSetValueA(
    [in] HKEY hKey,
    [in, optional] LPCSTR lpSubKey,
    [in] DWORD dwType,
    [in] LPCSTR lpData,
    [in] DWORD cbData
);

LSTATUS RegGetValueW(
    [in] HKEY hkey,
    [in, optional] LPCWSTR lpSubKey,
    [in, optional] LPCWSTR lpValue,
    [in, optional] DWORD dwFlags,
    [out, optional] LPDWORD pdwType,
    [out, optional] PVOID pvData,
    [in, out, optional] LPDWORD pcbData
);

LSTATUS RegDisablePredefinedCacheEx();

LSTATUS RegCloseKey(
    [in] HKEY hKey
);

LSTATUS RegDeleteTreeA(
    [in] HKEY hKey,
    [in, optional] LPCSTR lpSubKey
);

LSTATUS RegQueryValueA(
    [in] HKEY hKey,
    [in, optional] LPCSTR lpSubKey,
    [out, optional] LPSTR lpData,
    [in, out, optional] PLONG lpcbData
);

LSTATUS RegGetValueA(
    [in] HKEY hkey,
    [in, optional] LPCSTR lpSubKey,
    [in, optional] LPCSTR lpValue,
    [in, optional] DWORD dwFlags,
    [out, optional] LPDWORD pdwType,
    [out, optional] PVOID pvData,
    [in, out, optional] LPDWORD pcbData
);

LSTATUS RegEnumKeyExW(
    [in] HKEY hKey,
    [in] DWORD dwIndex,
    [out] LPWSTR lpName,
    [in, out] LPDWORD lpcchName,
    LPDWORD lpReserved,
    [in, out] LPWSTR lpClass,
    [in, out, optional] LPDWORD lpcchClass,
    [out, optional] PFILETIME lpftLastWriteTime
);

LSTATUS RegQueryValueExW(
    [in] HKEY hKey,
    [in, optional] LPCWSTR lpValueName,
    LPDWORD lpReserved,
    [out, optional] LPDWORD lpType,
    [out, optional] LPBYTE lpData,
    [in, out, optional] LPDWORD lpcbData
);

LSTATUS RegRenameKey(
    HKEY hKey,
    LPCWSTR lpSubKeyName,
    LPCWSTR lpNewKeyName
);

LSTATUS RegOpenCurrentUser(
    [in] REGSAM samDesired,
    [out] PHKEY phkResult
);

LSTATUS RegQueryMultipleValuesA(
    [in] HKEY hKey,
    [out] PVALENTA val_list,
    [in] DWORD num_vals,
    [out, optional] LPSTR lpValueBuf,
    [in, out, optional] LPDWORD ldwTotsize
);

LSTATUS RegOverridePredefKey(
    [in] HKEY hKey,
    [in, optional] HKEY hNewHKey
);

LSTATUS RegSaveKeyExA(
    [in] HKEY hKey,
    [in] LPCSTR lpFile,
    [in, optional] const LPSECURITY_ATTRIBUTES lpSecurityAttributes,
    [in] DWORD Flags
);

LSTATUS RegConnectRegistryW(
    [in, optional] LPCWSTR lpMachineName,
    [in] HKEY hKey,
    [out] PHKEY phkResult
);

