NTSTATUS BCryptEnumContextFunctions(
    [in] ULONG dwTable,
    [in] LPCWSTR pszContext,
    [in] ULONG dwInterface,
    [in, out] ULONG *pcbBuffer,
    [in, out] PCRYPT_CONTEXT_FUNCTIONS *ppBuffer
);

NTSTATUS BCryptDestroySecret(
    [in] BCRYPT_SECRET_HANDLE hSecret
);

NTSTATUS BCryptCreateContext(
    [in] ULONG dwTable,
    [in] LPCWSTR pszContext,
    [in, optional] PCRYPT_CONTEXT_CONFIG pConfig
);

NTSTATUS BCryptProcessMultiOperations(
    BCRYPT_HANDLE hObject,
    BCRYPT_MULTI_OPERATION_TYPE operationType,
    PVOID pOperations,
    ULONG cbOperations,
    ULONG dwFlags
);

NTSTATUS BCryptDecrypt(
    [in, out] BCRYPT_KEY_HANDLE hKey,
    [in] PUCHAR pbInput,
    [in] ULONG cbInput,
    [in, optional] VOID *pPaddingInfo,
    [in, out, optional] PUCHAR pbIV,
    [in] ULONG cbIV,
    [out, optional] PUCHAR pbOutput,
    [in] ULONG cbOutput,
    [out] ULONG *pcbResult,
    [in] ULONG dwFlags
);

NTSTATUS BCryptRegisterConfigChangeNotify(
    [out] PRKEVENT pEvent
);

NTSTATUS BCryptDuplicateKey(
    [in] BCRYPT_KEY_HANDLE hKey,
    [out] BCRYPT_KEY_HANDLE *phNewKey,
    [out] PUCHAR pbKeyObject,
    [in] ULONG cbKeyObject,
    [in] ULONG dwFlags
);

NTSTATUS BCryptGenRandom(
    [in, out] BCRYPT_ALG_HANDLE hAlgorithm,
    [in, out] PUCHAR pbBuffer,
    [in] ULONG cbBuffer,
    [in] ULONG dwFlags
);

NTSTATUS BCryptSetContextFunctionProperty(
    [in] ULONG dwTable,
    [in] LPCWSTR pszContext,
    [in] ULONG dwInterface,
    [in] LPCWSTR pszFunction,
    [in] LPCWSTR pszProperty,
    [in] ULONG cbValue,
    [in] PUCHAR pbValue
);

NTSTATUS BCryptAddContextFunction(
    [in] ULONG dwTable,
    [in] LPCWSTR pszContext,
    [in] ULONG dwInterface,
    [in] LPCWSTR pszFunction,
    [in] ULONG dwPosition
);

NTSTATUS BCryptEnumProviders(
    [in] LPCWSTR pszAlgId,
    [out] ULONG *pImplCount,
    [out] BCRYPT_PROVIDER_NAME **ppImplList,
    [in] ULONG dwFlags
);

NTSTATUS BCryptEnumAlgorithms(
    [in] ULONG dwAlgOperations,
    [out] ULONG *pAlgCount,
    [out] BCRYPT_ALGORITHM_IDENTIFIER **ppAlgList,
    [in] ULONG dwFlags
);

NTSTATUS BCryptDeriveKeyPBKDF2(
    [in] BCRYPT_ALG_HANDLE hPrf,
    [in, optional] PUCHAR pbPassword,
    [in] ULONG cbPassword,
    [in, optional] PUCHAR pbSalt,
    [in] ULONG cbSalt,
    [in] ULONGLONG cIterations,
    [out] PUCHAR pbDerivedKey,
    [in] ULONG cbDerivedKey,
    [in] ULONG dwFlags
);

NTSTATUS BCryptQueryProviderRegistration(
    [in] LPCWSTR pszProvider,
    [in] ULONG dwMode,
    [in] ULONG dwInterface,
    [in, out] ULONG *pcbBuffer,
    [in, out] PCRYPT_PROVIDER_REG *ppBuffer
);

NTSTATUS BCryptHash(
    BCRYPT_ALG_HANDLE hAlgorithm,
    PUCHAR pbSecret,
    ULONG cbSecret,
    PUCHAR pbInput,
    ULONG cbInput,
    PUCHAR pbOutput,
    ULONG cbOutput
);

NTSTATUS BCryptFinalizeKeyPair(
    [in, out] BCRYPT_KEY_HANDLE hKey,
    [in] ULONG dwFlags
);

NTSTATUS BCryptSignHash(
    [in] BCRYPT_KEY_HANDLE hKey,
    [in, optional] VOID *pPaddingInfo,
    [in] PUCHAR pbInput,
    [in] ULONG cbInput,
    [out] PUCHAR pbOutput,
    [in] ULONG cbOutput,
    [out] ULONG *pcbResult,
    [in] ULONG dwFlags
);

NTSTATUS BCryptEncrypt(
    [in, out] BCRYPT_KEY_HANDLE hKey,
    [in] PUCHAR pbInput,
    [in] ULONG cbInput,
    [in, optional] VOID *pPaddingInfo,
    [in, out, optional] PUCHAR pbIV,
    [in] ULONG cbIV,
    [out, optional] PUCHAR pbOutput,
    [in] ULONG cbOutput,
    [out] ULONG *pcbResult,
    [in] ULONG dwFlags
);

NTSTATUS BCryptEnumContextFunctionProviders(
    [in] ULONG dwTable,
    [in] LPCWSTR pszContext,
    [in] ULONG dwInterface,
    [in] LPCWSTR pszFunction,
    [in, out] ULONG *pcbBuffer,
    [in, out] PCRYPT_CONTEXT_FUNCTION_PROVIDERS *ppBuffer
);

NTSTATUS BCryptGenerateSymmetricKey(
    [in, out] BCRYPT_ALG_HANDLE hAlgorithm,
    [out] BCRYPT_KEY_HANDLE *phKey,
    [out, optional] PUCHAR pbKeyObject,
    [in] ULONG cbKeyObject,
    [in] PUCHAR pbSecret,
    [in] ULONG cbSecret,
    [in] ULONG dwFlags
);

NTSTATUS BCryptGetProperty(
    [in] BCRYPT_HANDLE hObject,
    [in] LPCWSTR pszProperty,
    [out] PUCHAR pbOutput,
    [in] ULONG cbOutput,
    [out] ULONG *pcbResult,
    [in] ULONG dwFlags
);

NTSTATUS BCryptCreateHash(
    [in, out] BCRYPT_ALG_HANDLE hAlgorithm,
    [out] BCRYPT_HASH_HANDLE *phHash,
    [out] PUCHAR pbHashObject,
    [in, optional] ULONG cbHashObject,
    [in, optional] PUCHAR pbSecret,
    [in] ULONG cbSecret,
    [in] ULONG dwFlags
);

NTSTATUS BCryptDeleteContext(
    [in] ULONG dwTable,
    [in] LPCWSTR pszContext
);

NTSTATUS BCryptResolveProviders(
    [in, optional] LPCWSTR pszContext,
    [in, optional] ULONG dwInterface,
    [in, optional] LPCWSTR pszFunction,
    [in, optional] LPCWSTR pszProvider,
    [in] ULONG dwMode,
    [in] ULONG dwFlags,
    [in, out] ULONG *pcbBuffer,
    [in, out] PCRYPT_PROVIDER_REFS *ppBuffer
);

NTSTATUS BCryptQueryContextConfiguration(
    [in] ULONG dwTable,
    [in] LPCWSTR pszContext,
    [in, out] ULONG *pcbBuffer,
    [in, out] PCRYPT_CONTEXT_CONFIG *ppBuffer
);

NTSTATUS BCryptEnumRegisteredProviders(
    [in, out] ULONG *pcbBuffer,
    [in, out] PCRYPT_PROVIDERS *ppBuffer
);

NTSTATUS BCryptConfigureContext(
    [in] ULONG dwTable,
    [in] LPCWSTR pszContext,
    [in] PCRYPT_CONTEXT_CONFIG pConfig
);

NTSTATUS BCryptDestroyHash(
    [in, out] BCRYPT_HASH_HANDLE hHash
);

NTSTATUS BCryptDeriveKey(
    [in] BCRYPT_SECRET_HANDLE hSharedSecret,
    [in] LPCWSTR pwszKDF,
    [in, optional] BCryptBufferDesc *pParameterList,
    [out, optional] PUCHAR pbDerivedKey,
    [in] ULONG cbDerivedKey,
    [out] ULONG *pcbResult,
    [in] ULONG dwFlags
);

NTSTATUS BCryptGenerateKeyPair(
    [in, out] BCRYPT_ALG_HANDLE hAlgorithm,
    [out] BCRYPT_KEY_HANDLE *phKey,
    [in] ULONG dwLength,
    [in] ULONG dwFlags
);

NTSTATUS BCryptImportKey(
    [in] BCRYPT_ALG_HANDLE hAlgorithm,
    [in, optional] BCRYPT_KEY_HANDLE hImportKey,
    [in] LPCWSTR pszBlobType,
    [out] BCRYPT_KEY_HANDLE *phKey,
    [out, optional] PUCHAR pbKeyObject,
    [in] ULONG cbKeyObject,
    [in] PUCHAR pbInput,
    [in] ULONG cbInput,
    [in] ULONG dwFlags
);

NTSTATUS BCryptSecretAgreement(
    [in] BCRYPT_KEY_HANDLE hPrivKey,
    [in] BCRYPT_KEY_HANDLE hPubKey,
    [out] BCRYPT_SECRET_HANDLE *phAgreedSecret,
    [in] ULONG dwFlags
);

NTSTATUS BCryptConfigureContextFunction(
    [in] ULONG dwTable,
    [in] LPCWSTR pszContext,
    [in] ULONG dwInterface,
    [in] LPCWSTR pszFunction,
    [in] PCRYPT_CONTEXT_FUNCTION_CONFIG pConfig
);

NTSTATUS BCryptExportKey(
    [in] BCRYPT_KEY_HANDLE hKey,
    [in] BCRYPT_KEY_HANDLE hExportKey,
    [in] LPCWSTR pszBlobType,
    [out] PUCHAR pbOutput,
    [in] ULONG cbOutput,
    [out] ULONG *pcbResult,
    [in] ULONG dwFlags
);

NTSTATUS BCryptQueryContextFunctionProperty(
    [in] ULONG dwTable,
    [in] LPCWSTR pszContext,
    [in] ULONG dwInterface,
    [in] LPCWSTR pszFunction,
    [in] LPCWSTR pszProperty,
    [in, out] ULONG *pcbValue,
    [in, out] PUCHAR *ppbValue
);

NTSTATUS BCryptCloseAlgorithmProvider(
    [in, out] BCRYPT_ALG_HANDLE hAlgorithm,
    [in] ULONG dwFlags
);

NTSTATUS BCryptUnregisterConfigChangeNotify(
    [in] PRKEVENT pEvent
);

NTSTATUS BCryptCreateMultiHash(
    BCRYPT_ALG_HANDLE hAlgorithm,
    BCRYPT_HASH_HANDLE *phHash,
    ULONG nHashes,
    PUCHAR pbHashObject,
    ULONG cbHashObject,
    PUCHAR pbSecret,
    ULONG cbSecret,
    ULONG dwFlags
);

NTSTATUS BCryptQueryContextFunctionConfiguration(
    [in] ULONG dwTable,
    [in] LPCWSTR pszContext,
    [in] ULONG dwInterface,
    [in] LPCWSTR pszFunction,
    [in, out] ULONG *pcbBuffer,
    [in, out] PCRYPT_CONTEXT_FUNCTION_CONFIG *ppBuffer
);

NTSTATUS BCryptHashData(
    [in, out] BCRYPT_HASH_HANDLE hHash,
    [in] PUCHAR pbInput,
    [in] ULONG cbInput,
    [in] ULONG dwFlags
);

NTSTATUS BCryptRegisterConfigChangeNotify(
    [in] HANDLE *phEvent
);

NTSTATUS BCryptRemoveContextFunction(
    [in] ULONG dwTable,
    [in] LPCWSTR pszContext,
    [in] ULONG dwInterface,
    [in] LPCWSTR pszFunction
);

NTSTATUS BCryptImportKeyPair(
    [in] BCRYPT_ALG_HANDLE hAlgorithm,
    [in, out] BCRYPT_KEY_HANDLE hImportKey,
    [in] LPCWSTR pszBlobType,
    [out] BCRYPT_KEY_HANDLE *phKey,
    [in] PUCHAR pbInput,
    [in] ULONG cbInput,
    [in] ULONG dwFlags
);

void BCRYPT_INIT_AUTH_MODE_INFO(
    _AUTH_INFO_STRUCT_
);

NTSTATUS BCryptDeriveKeyCapi(
    [in] BCRYPT_HASH_HANDLE hHash,
    [in, optional] BCRYPT_ALG_HANDLE hTargetAlg,
    [out] PUCHAR pbDerivedKey,
    [in] ULONG cbDerivedKey,
    [in] ULONG dwFlags
);

NTSTATUS BCryptOpenAlgorithmProvider(
    [out] BCRYPT_ALG_HANDLE *phAlgorithm,
    [in] LPCWSTR pszAlgId,
    [in] LPCWSTR pszImplementation,
    [in] ULONG dwFlags
);

NTSTATUS BCryptDuplicateHash(
    [in] BCRYPT_HASH_HANDLE hHash,
    [out] BCRYPT_HASH_HANDLE *phNewHash,
    [out] PUCHAR pbHashObject,
    [in] ULONG cbHashObject,
    [in] ULONG dwFlags
);

NTSTATUS BCryptSetProperty(
    [in, out] BCRYPT_HANDLE hObject,
    [in] LPCWSTR pszProperty,
    [in] PUCHAR pbInput,
    [in] ULONG cbInput,
    [in] ULONG dwFlags
);

NTSTATUS BCryptKeyDerivation(
    [in] BCRYPT_KEY_HANDLE hKey,
    [in, optional] BCryptBufferDesc *pParameterList,
    [out] PUCHAR pbDerivedKey,
    [in] ULONG cbDerivedKey,
    [out] ULONG *pcbResult,
    [in] ULONG dwFlags
);

NTSTATUS BCryptUnregisterConfigChangeNotify(
    HANDLE hEvent
);

void BCryptFreeBuffer(
    [in] PVOID pvBuffer
);

NTSTATUS BCryptDestroyKey(
    [in, out] BCRYPT_KEY_HANDLE hKey
);

NTSTATUS BCryptVerifySignature(
    [in] BCRYPT_KEY_HANDLE hKey,
    [in, optional] VOID *pPaddingInfo,
    [in] PUCHAR pbHash,
    [in] ULONG cbHash,
    [in] PUCHAR pbSignature,
    [in] ULONG cbSignature,
    [in] ULONG dwFlags
);

NTSTATUS BCryptGetFipsAlgorithmMode(
    [out] BOOLEAN *pfEnabled
);

NTSTATUS BCryptFinishHash(
    [in, out] BCRYPT_HASH_HANDLE hHash,
    [out] PUCHAR pbOutput,
    [in] ULONG cbOutput,
    [in] ULONG dwFlags
);

NTSTATUS BCryptEnumContexts(
    [in] ULONG dwTable,
    [in, out] ULONG *pcbBuffer,
    [in, out] PCRYPT_CONTEXTS *ppBuffer
);

