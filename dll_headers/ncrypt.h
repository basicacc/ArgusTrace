SECURITY_STATUS NCryptCreateClaim(
    [in] NCRYPT_KEY_HANDLE hSubjectKey,
    [in, optional] NCRYPT_KEY_HANDLE hAuthorityKey,
    [in] DWORD dwClaimType,
    [in, optional] NCryptBufferDesc *pParameterList,
    [out] PBYTE pbClaimBlob,
    [in] DWORD cbClaimBlob,
    [out] DWORD *pcbResult,
    [in] DWORD dwFlags
);

SECURITY_STATUS NCryptDeleteKey(
    [in] NCRYPT_KEY_HANDLE hKey,
    [in] DWORD dwFlags
);

SECURITY_STATUS NCryptSetProperty(
    [in] NCRYPT_HANDLE hObject,
    [in] LPCWSTR pszProperty,
    [in] PBYTE pbInput,
    [in] DWORD cbInput,
    [in] DWORD dwFlags
);

SECURITY_STATUS NCryptNotifyChangeKey(
    [in] NCRYPT_PROV_HANDLE hProvider,
    [in, out] HANDLE *phEvent,
    [in] DWORD dwFlags
);

SECURITY_STATUS NCryptSecretAgreement(
    [in] NCRYPT_KEY_HANDLE hPrivKey,
    [in] NCRYPT_KEY_HANDLE hPubKey,
    [out] NCRYPT_SECRET_HANDLE *phAgreedSecret,
    [in] DWORD dwFlags
);

SECURITY_STATUS NCryptImportKey(
    [in] NCRYPT_PROV_HANDLE hProvider,
    [in, optional] NCRYPT_KEY_HANDLE hImportKey,
    [in] LPCWSTR pszBlobType,
    [in, optional] NCryptBufferDesc *pParameterList,
    [out] NCRYPT_KEY_HANDLE *phKey,
    [in] PBYTE pbData,
    [in] DWORD cbData,
    [in] DWORD dwFlags
);

SECURITY_STATUS NCryptFreeObject(
    [in] NCRYPT_HANDLE hObject
);

SECURITY_STATUS NCryptEnumKeys(
    [in] NCRYPT_PROV_HANDLE hProvider,
    [in, optional] LPCWSTR pszScope,
    [out] NCryptKeyName **ppKeyName,
    [in, out] PVOID *ppEnumState,
    [in] DWORD dwFlags
);

SECURITY_STATUS NCryptDeriveKey(
    [in] NCRYPT_SECRET_HANDLE hSharedSecret,
    [in] LPCWSTR pwszKDF,
    [in, optional] NCryptBufferDesc *pParameterList,
    [out, optional] PBYTE pbDerivedKey,
    [in] DWORD cbDerivedKey,
    [out] DWORD *pcbResult,
    [in] ULONG dwFlags
);

SECURITY_STATUS NCryptEncrypt(
    [in] NCRYPT_KEY_HANDLE hKey,
    [in] PBYTE pbInput,
    [in] DWORD cbInput,
    [in, optional] VOID *pPaddingInfo,
    [out] PBYTE pbOutput,
    [in] DWORD cbOutput,
    [out] DWORD *pcbResult,
    [in] DWORD dwFlags
);

SECURITY_STATUS NCryptVerifySignature(
    [in] NCRYPT_KEY_HANDLE hKey,
    [in, optional] VOID *pPaddingInfo,
    [in] PBYTE pbHashValue,
    [in] DWORD cbHashValue,
    [in] PBYTE pbSignature,
    [in] DWORD cbSignature,
    [in] DWORD dwFlags
);

SECURITY_STATUS NCryptGetProperty(
    [in] NCRYPT_HANDLE hObject,
    [in] LPCWSTR pszProperty,
    [out] PBYTE pbOutput,
    [in] DWORD cbOutput,
    [out] DWORD *pcbResult,
    [in] DWORD dwFlags
);

SECURITY_STATUS NCryptSignHash(
    [in] NCRYPT_KEY_HANDLE hKey,
    [in, optional] VOID *pPaddingInfo,
    [in] PBYTE pbHashValue,
    [in] DWORD cbHashValue,
    [out] PBYTE pbSignature,
    [in] DWORD cbSignature,
    [out] DWORD *pcbResult,
    [in] DWORD dwFlags
);

SECURITY_STATUS NCryptFreeBuffer(
    [in] PVOID pvInput
);

SECURITY_STATUS NCryptFinalizeKey(
    [in] NCRYPT_KEY_HANDLE hKey,
    [in] DWORD dwFlags
);

SECURITY_STATUS NCryptExportKey(
    [in] NCRYPT_KEY_HANDLE hKey,
    [in, optional] NCRYPT_KEY_HANDLE hExportKey,
    [in] LPCWSTR pszBlobType,
    [in, optional] NCryptBufferDesc *pParameterList,
    [out, optional] PBYTE pbOutput,
    [in] DWORD cbOutput,
    [out] DWORD *pcbResult,
    [in] DWORD dwFlags
);

SECURITY_STATUS NCryptEnumStorageProviders(
    [out] DWORD *pdwProviderCount,
    [out] NCryptProviderName **ppProviderList,
    [in] DWORD dwFlags
);

SECURITY_STATUS NCryptCreatePersistedKey(
    [in] NCRYPT_PROV_HANDLE hProvider,
    [out] NCRYPT_KEY_HANDLE *phKey,
    [in] LPCWSTR pszAlgId,
    [in, optional] LPCWSTR pszKeyName,
    [in] DWORD dwLegacyKeySpec,
    [in] DWORD dwFlags
);

SECURITY_STATUS NCryptVerifyClaim(
    [in] NCRYPT_KEY_HANDLE hSubjectKey,
    [in, optional] NCRYPT_KEY_HANDLE hAuthorityKey,
    [in] DWORD dwClaimType,
    [in, optional] NCryptBufferDesc *pParameterList,
    [in] PBYTE pbClaimBlob,
    [in] DWORD cbClaimBlob,
    [out] NCryptBufferDesc *pOutput,
    [in] DWORD dwFlags
);

BOOL NCryptIsKeyHandle(
    [in] NCRYPT_KEY_HANDLE hKey
);

SECURITY_STATUS NCryptOpenKey(
    [in] NCRYPT_PROV_HANDLE hProvider,
    [out] NCRYPT_KEY_HANDLE *phKey,
    [in] LPCWSTR pszKeyName,
    [in] DWORD dwLegacyKeySpec,
    [in] DWORD dwFlags
);

SECURITY_STATUS NCryptTranslateHandle(
    [out, optional] NCRYPT_PROV_HANDLE *phProvider,
    [out] NCRYPT_KEY_HANDLE *phKey,
    [in] HCRYPTPROV hLegacyProv,
    [in, optional] HCRYPTKEY hLegacyKey,
    [in, optional] DWORD dwLegacyKeySpec,
    [in] DWORD dwFlags
);

SECURITY_STATUS NCryptKeyDerivation(
    [in] NCRYPT_KEY_HANDLE hKey,
    [in] NCryptBufferDesc *pParameterList,
    [out] PUCHAR pbDerivedKey,
    [in] DWORD cbDerivedKey,
    [out] DWORD *pcbResult,
    [in] ULONG dwFlags
);

SECURITY_STATUS NCryptOpenStorageProvider(
    [out] NCRYPT_PROV_HANDLE *phProvider,
    [in, optional] LPCWSTR pszProviderName,
    [in] DWORD dwFlags
);

SECURITY_STATUS NCryptDecrypt(
    [in] NCRYPT_KEY_HANDLE hKey,
    [in] PBYTE pbInput,
    [in] DWORD cbInput,
    [in, optional] VOID *pPaddingInfo,
    [out] PBYTE pbOutput,
    [in] DWORD cbOutput,
    [out] DWORD *pcbResult,
    [in] DWORD dwFlags
);

SECURITY_STATUS NCryptEnumAlgorithms(
    [in] NCRYPT_PROV_HANDLE hProvider,
    [in] DWORD dwAlgOperations,
    [out] DWORD *pdwAlgCount,
    [out] NCryptAlgorithmName **ppAlgList,
    [in] DWORD dwFlags
);

SECURITY_STATUS NCryptIsAlgSupported(
    [in] NCRYPT_PROV_HANDLE hProvider,
    [in] LPCWSTR pszAlgId,
    [in] DWORD dwFlags
);

