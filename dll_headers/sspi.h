KSECDDDECLSPEC SECURITY_STATUS SEC_ENTRY ExportSecurityContext(
    [in] PCtxtHandle phContext,
    [in] ULONG fFlags,
    [out] PSecBuffer pPackedContext,
    [out, optional] void **pToken
);

SECURITY_STATUS SEC_ENTRY SspiPrepareForCredWrite(
    [in] PSEC_WINNT_AUTH_IDENTITY_OPAQUE AuthIdentity,
    [in] PCWSTR pszTargetName,
    [out] PULONG pCredmanCredentialType,
    [out] PCWSTR *ppszCredmanTargetName,
    [out] PCWSTR *ppszCredmanUserName,
    [out] PUCHAR *ppCredentialBlob,
    [out] PULONG pCredentialBlobSize
);

NTSTATUS SspiReinitAsyncContext(
    SspiAsyncContext *Handle
);

SspiAsyncContext * SspiCreateAsyncContext();

SECURITY_STATUS SEC_ENTRY SaslIdentifyPackageW(
    [in] PSecBufferDesc pInput,
    [out] PSecPkgInfoW *PackageInfo
);

BOOLEAN SEC_ENTRY SspiIsAuthIdentityEncrypted(
    [in] PSEC_WINNT_AUTH_IDENTITY_OPAQUE EncryptedAuthData
);

SECURITY_STATUS SspiInitializeSecurityContextAsyncA(
    SspiAsyncContext *AsyncContext,
    PCredHandle phCredential,
    PCtxtHandle phContext,
    LPSTR pszTargetName,
    unsigned long fContextReq,
    unsigned long Reserved1,
    unsigned long TargetDataRep,
    PSecBufferDesc pInput,
    unsigned long Reserved2,
    PCtxtHandle phNewContext,
    PSecBufferDesc pOutput,
    unsigned long *pfContextAttr,
    PTimeStamp ptsExpiry
);

SECURITY_STATUS SEC_ENTRY SspiUnmarshalCredUIContext(
    [in] PUCHAR MarshaledCredUIContext,
    [in] ULONG MarshaledCredUIContextLength,
    [out] PSEC_WINNT_CREDUI_CONTEXT *CredUIContext
);

SECURITY_STATUS SspiSetAsyncNotifyCallback(
    SspiAsyncContext *Context,
    SspiAsyncNotifyCallback Callback,
    void *CallbackData
);

BOOLEAN SEC_ENTRY SspiIsPromptingNeeded(
    [in] unsigned long ErrorOrNtStatus
);

SECURITY_STATUS SEC_ENTRY SspiPrepareForCredRead(
    [in] PSEC_WINNT_AUTH_IDENTITY_OPAQUE AuthIdentity,
    [in] PCWSTR pszTargetName,
    [out] PULONG pCredmanCredentialType,
    [out] PCWSTR *ppszCredmanTargetName
);

SECURITY_STATUS SEC_ENTRY SaslIdentifyPackageA(
    [in] PSecBufferDesc pInput,
    [out] PSecPkgInfoA *PackageInfo
);

SECURITY_STATUS SEC_ENTRY DeleteSecurityPackageW(
    [in] LPWSTR pszPackageName
);

SECURITY_STATUS SEC_ENTRY SspiUnmarshalAuthIdentity(
    [in] unsigned long AuthIdentityLength,
    [in] char *AuthIdentityByteArray,
    [out] PSEC_WINNT_AUTH_IDENTITY_OPAQUE *ppAuthIdentity
);

SECURITY_STATUS SEC_ENTRY SaslEnumerateProfilesW(
    [out] LPWSTR *ProfileList,
    [out] ULONG *ProfileCount
);

KSECDDDECLSPEC SECURITY_STATUS SEC_ENTRY FreeCredentialsHandle(
    [in] PCredHandle phCredential
);

KSECDDDECLSPEC SECURITY_STATUS SEC_ENTRY QueryCredentialsAttributesW(
    [in] PCredHandle phCredential,
    [in] unsigned long ulAttribute,
    [out] void *pBuffer
);

SECURITY_STATUS SEC_ENTRY SspiEncryptAuthIdentityEx(
    [in] ULONG Options,
    [in, out] PSEC_WINNT_AUTH_IDENTITY_OPAQUE AuthData
);

KSECDDDECLSPEC SECURITY_STATUS SEC_ENTRY SetCredentialsAttributesW(
    [in] PCredHandle phCredential,
    [in] unsigned long ulAttribute,
    [in] void *pBuffer,
    unsigned long cbBuffer
);

SECURITY_STATUS SEC_ENTRY DeleteSecurityPackageA(
    [in] LPSTR pszPackageName
);

KSECDDDECLSPEC SECURITY_STATUS SEC_ENTRY ImportSecurityContextW(
    [in] PSECURITY_STRING pszPackage,
    [in] PSecBuffer pPackedContext,
    [in, optional] void *Token,
    [out] PCtxtHandle phContext
);

void SspiFreeAsyncContext(
    SspiAsyncContext *Handle
);

SECURITY_STATUS SEC_ENTRY AddCredentialsA(
    PCredHandle hCredentials,
    LPSTR pszPrincipal,
    LPSTR pszPackage,
    unsigned long fCredentialUse,
    void *pAuthData,
    SEC_GET_KEY_FN pGetKeyFn,
    void *pvGetKeyArgument,
    PTimeStamp ptsExpiry
);

KSECDDDECLSPEC SECURITY_STATUS SEC_ENTRY ApplyControlToken(
    [in] PCtxtHandle phContext,
    [in] PSecBufferDesc pInput
);

KSECDDDECLSPEC SECURITY_STATUS SEC_ENTRY QuerySecurityPackageInfoW(
    PSECURITY_STRING pPackageName,
    [out] PSecPkgInfoW *ppPackageInfo
);

SECURITY_STATUS SspiAcquireCredentialsHandleAsyncW(
    SspiAsyncContext *AsyncContext,
    PSECURITY_STRING pszPrincipal,
    PSECURITY_STRING pszPackage,
    unsigned long fCredentialUse,
    void *pvLogonId,
    void *pAuthData,
    SEC_GET_KEY_FN pGetKeyFn,
    void *pvGetKeyArgument,
    PCredHandle phCredential,
    PTimeStamp ptsExpiry
);

SECURITY_STATUS SspiInitializeSecurityContextAsyncW(
    SspiAsyncContext *AsyncContext,
    PCredHandle phCredential,
    PCtxtHandle phContext,
    PSECURITY_STRING pszTargetName,
    unsigned long fContextReq,
    unsigned long Reserved1,
    unsigned long TargetDataRep,
    PSecBufferDesc pInput,
    unsigned long Reserved2,
    PCtxtHandle phNewContext,
    PSecBufferDesc pOutput,
    unsigned long *pfContextAttr,
    PTimeStamp ptsExpiry
);

SECURITY_STATUS SEC_ENTRY QueryContextAttributesExA(
    [in] PCtxtHandle phContext,
    [in] unsigned long ulAttribute,
    [out] void *pBuffer,
    [in] unsigned long cbBuffer
);

SECURITY_STATUS SEC_ENTRY SspiMarshalAuthIdentity(
    [in] PSEC_WINNT_AUTH_IDENTITY_OPAQUE AuthIdentity,
    [out] unsigned long *AuthIdentityLength,
    [out] char **AuthIdentityByteArray
);

KSECDDDECLSPEC SECURITY_STATUS SEC_ENTRY VerifySignature(
    [in] PCtxtHandle phContext,
    [in] PSecBufferDesc pMessage,
    [in] unsigned long MessageSeqNo,
    [out] unsigned long *pfQOP
);

SECURITY_STATUS SEC_ENTRY EnumerateSecurityPackagesA(
    [in] unsigned long *pcPackages,
    [in] PSecPkgInfoA *ppPackageInfo
);

SECURITY_STATUS SEC_ENTRY SspiEncodeAuthIdentityAsStrings(
    [in] PSEC_WINNT_AUTH_IDENTITY_OPAQUE pAuthIdentity,
    [out] PCWSTR *ppszUserName,
    [out] PCWSTR *ppszDomainName,
    [out] PCWSTR *ppszPackedCredentialsString
);

VOID SEC_ENTRY SspiFreeAuthIdentity(
    [in] PSEC_WINNT_AUTH_IDENTITY_OPAQUE AuthData
);

SECURITY_STATUS SEC_ENTRY QueryCredentialsAttributesExW(
    PCredHandle phCredential,
    unsigned long ulAttribute,
    void *pBuffer,
    unsigned long cbBuffer
);

SECURITY_STATUS SEC_ENTRY QueryCredentialsAttributesExA(
    PCredHandle phCredential,
    unsigned long ulAttribute,
    void *pBuffer,
    unsigned long cbBuffer
);

KSECDDDECLSPEC SECURITY_STATUS SEC_ENTRY AcceptSecurityContext(
    [in, optional] PCredHandle phCredential,
    [in, optional] PCtxtHandle phContext,
    [in, optional] PSecBufferDesc pInput,
    [in] unsigned long fContextReq,
    [in] unsigned long TargetDataRep,
    [in, out, optional] PCtxtHandle phNewContext,
    [in, out, optional] PSecBufferDesc pOutput,
    [out] unsigned long *pfContextAttr,
    [out, optional] PTimeStamp ptsExpiry
);

SECURITY_STATUS SEC_ENTRY SaslAcceptSecurityContext(
    [in] PCredHandle phCredential,
    [in, optional] PCtxtHandle phContext,
    [in] PSecBufferDesc pInput,
    [in] unsigned long fContextReq,
    [in] unsigned long TargetDataRep,
    [out] PCtxtHandle phNewContext,
    [in, out] PSecBufferDesc pOutput,
    [out] unsigned long *pfContextAttr,
    [out, optional] PTimeStamp ptsExpiry
);

SECURITY_STATUS SEC_ENTRY SspiDecryptAuthIdentity(
    [in, out] PSEC_WINNT_AUTH_IDENTITY_OPAQUE EncryptedAuthData
);

SECURITY_STATUS SspiAcquireCredentialsHandleAsyncA(
    SspiAsyncContext *AsyncContext,
    LPSTR pszPrincipal,
    LPSTR pszPackage,
    unsigned long fCredentialUse,
    void *pvLogonId,
    void *pAuthData,
    SEC_GET_KEY_FN pGetKeyFn,
    void *pvGetKeyArgument,
    PCredHandle phCredential,
    PTimeStamp ptsExpiry
);

SECURITY_STATUS SEC_ENTRY ChangeAccountPasswordA(
    [in] SEC_CHAR *pszPackageName,
    [in] SEC_CHAR *pszDomainName,
    [in] SEC_CHAR *pszAccountName,
    [in] SEC_CHAR *pszOldPassword,
    [in] SEC_CHAR *pszNewPassword,
    [in] BOOLEAN bImpersonating,
    [in] unsigned long dwReserved,
    [in, out] PSecBufferDesc pOutput
);

KSECDDDECLSPEC SECURITY_STATUS SEC_ENTRY AcquireCredentialsHandleW(
    PSECURITY_STRING pPrincipal,
    PSECURITY_STRING pPackage,
    [in] unsigned long fCredentialUse,
    [in, optional] void *pvLogonId,
    [in, optional] void *pAuthData,
    [in, optional] SEC_GET_KEY_FN pGetKeyFn,
    [in, optional] void *pvGetKeyArgument,
    [out] PCredHandle phCredential,
    [out, optional] PTimeStamp ptsExpiry
);

SECURITY_STATUS SEC_ENTRY FreeContextBuffer(
    [in] PVOID pvContextBuffer
);

SECURITY_STATUS SEC_ENTRY AcquireCredentialsHandleA(
    [in, optional] LPSTR pszPrincipal,
    [in] LPSTR pszPackage,
    [in] unsigned long fCredentialUse,
    [in, optional] void *pvLogonId,
    [in, optional] void *pAuthData,
    [in, optional] SEC_GET_KEY_FN pGetKeyFn,
    [in, optional] void *pvGetKeyArgument,
    [out] PCredHandle phCredential,
    [out, optional] PTimeStamp ptsExpiry
);

KSECDDDECLSPEC SECURITY_STATUS SEC_ENTRY EnumerateSecurityPackagesW(
    [in] unsigned long *pcPackages,
    [in] PSecPkgInfoW *ppPackageInfo
);

unsigned long SEC_ENTRY SspiPromptForCredentialsA(
    [in] PCSTR pszTargetName,
    [in] PCREDUI_INFOA pUiInfo,
    [in] unsigned long dwAuthError,
    [in] PCSTR pszPackage,
    [in] PSEC_WINNT_AUTH_IDENTITY_OPAQUE pInputAuthIdentity,
    [out] PSEC_WINNT_AUTH_IDENTITY_OPAQUE *ppAuthIdentity,
    [in, out, optional] int *pfSave,
    [in] unsigned long dwFlags
);

SECURITY_STATUS SEC_ENTRY QueryContextAttributesA(
    [in] PCtxtHandle phContext,
    [in] unsigned long ulAttribute,
    [out] void *pBuffer
);

unsigned long SEC_ENTRY SspiPromptForCredentialsW(
    [in] PCWSTR pszTargetName,
    [in] PCREDUI_INFOW pUiInfo,
    [in] unsigned long dwAuthError,
    [in] PCWSTR pszPackage,
    [in] PSEC_WINNT_AUTH_IDENTITY_OPAQUE pInputAuthIdentity,
    [out] PSEC_WINNT_AUTH_IDENTITY_OPAQUE *ppAuthIdentity,
    [in, out, optional] int *pfSave,
    [in] unsigned long dwFlags
);

SECURITY_STATUS SEC_ENTRY SspiUpdateCredentials(
    [in] HANDLE ContextHandle,
    [in] GUID *CredType,
    [in] ULONG FlatCredUIContextLength,
    [in] PUCHAR FlatCredUIContext
);

SECURITY_STATUS SEC_ENTRY SspiGetCredUIContext(
    [in] HANDLE ContextHandle,
    [in] GUID *CredType,
    [in] LUID *LogonId,
    [out] PSEC_WINNT_CREDUI_CONTEXT_VECTOR *CredUIContexts,
    [out] HANDLE *TokenHandle
);

SECURITY_STATUS SEC_ENTRY SaslEnumerateProfilesA(
    [out] LPSTR *ProfileList,
    [out] ULONG *ProfileCount
);

SECURITY_STATUS SspiAcceptSecurityContextAsync(
    SspiAsyncContext *AsyncContext,
    PCredHandle phCredential,
    PCtxtHandle phContext,
    PSecBufferDesc pInput,
    unsigned long fContextReq,
    unsigned long TargetDataRep,
    PCtxtHandle phNewContext,
    PSecBufferDesc pOutput,
    unsigned long *pfContextAttr,
    PTimeStamp ptsExpiry
);

SECURITY_STATUS SEC_ENTRY SspiEncodeStringsAsAuthIdentity(
    [in] PCWSTR pszUserName,
    [in] PCWSTR pszDomainName,
    [in] PCWSTR pszPackedCredentialsString,
    [out] PSEC_WINNT_AUTH_IDENTITY_OPAQUE *ppAuthIdentity
);

VOID SEC_ENTRY SspiLocalFree(
    [in] PVOID DataBuffer
);

SECURITY_STATUS SEC_ENTRY SaslInitializeSecurityContextA(
    [in] PCredHandle phCredential,
    [in] PCtxtHandle phContext,
    [in] LPSTR pszTargetName,
    [in] unsigned long fContextReq,
    [in] unsigned long Reserved1,
    [in] unsigned long TargetDataRep,
    [in] PSecBufferDesc pInput,
    [in] unsigned long Reserved2,
    [out] PCtxtHandle phNewContext,
    [in, out] PSecBufferDesc pOutput,
    [out] unsigned long *pfContextAttr,
    [out, optional] PTimeStamp ptsExpiry
);

SECURITY_STATUS SEC_ENTRY DelegateSecurityContext(
    PCtxtHandle phContext,
    PSECURITY_STRING pTarget,
    SecDelegationType DelegationType,
    PTimeStamp pExpiry,
    PSecBuffer pPackageParameters,
    PSecBufferDesc pOutput
);

SECURITY_STATUS SEC_ENTRY QueryContextAttributesExW(
    [in] PCtxtHandle phContext,
    [in] unsigned long ulAttribute,
    [out] void *pBuffer,
    [in] unsigned long cbBuffer
);

KSECDDDECLSPEC SECURITY_STATUS SEC_ENTRY AddCredentialsW(
    PCredHandle hCredentials,
    PSECURITY_STRING pPrincipal,
    PSECURITY_STRING pPackage,
    unsigned long fCredentialUse,
    void *pAuthData,
    SEC_GET_KEY_FN pGetKeyFn,
    void *pvGetKeyArgument,
    PTimeStamp ptsExpiry
);

SECURITY_STATUS SEC_ENTRY SaslSetContextOption(
    [in] PCtxtHandle ContextHandle,
    [in] ULONG Option,
    [in] PVOID Value,
    [in] ULONG Size
);

SECURITY_STATUS SspiFreeCredentialsHandleAsync(
    SspiAsyncContext *AsyncContext,
    PCredHandle phCredential
);

KSECDDDECLSPEC SECURITY_STATUS SEC_ENTRY MakeSignature(
    [in] PCtxtHandle phContext,
    [in] unsigned long fQOP,
    [in, out] PSecBufferDesc pMessage,
    [in] unsigned long MessageSeqNo
);

SECURITY_STATUS SEC_ENTRY SaslInitializeSecurityContextW(
    [in] PCredHandle phCredential,
    [in] PCtxtHandle phContext,
    [in] LPWSTR pszTargetName,
    [in] unsigned long fContextReq,
    [in] unsigned long Reserved1,
    [in] unsigned long TargetDataRep,
    [in] PSecBufferDesc pInput,
    [in] unsigned long Reserved2,
    [out] PCtxtHandle phNewContext,
    [in, out] PSecBufferDesc pOutput,
    [out] unsigned long *pfContextAttr,
    [out, optional] PTimeStamp ptsExpiry
);

SECURITY_STATUS SEC_ENTRY ImportSecurityContextA(
    [in] LPSTR pszPackage,
    [in] PSecBuffer pPackedContext,
    [in, optional] VOID *Token,
    [out] PCtxtHandle phContext
);

SECURITY_STATUS SEC_ENTRY SspiGetTargetHostName(
    [in] PCWSTR pszTargetName,
    [out] PWSTR *pszHostName
);

KSECDDDECLSPEC SECURITY_STATUS SEC_ENTRY RevertSecurityContext(
    [in] PCtxtHandle phContext
);

SECURITY_STATUS SEC_ENTRY AddSecurityPackageA(
    [in] LPSTR pszPackageName,
    [in] PSECURITY_PACKAGE_OPTIONS pOptions
);

SECURITY_STATUS SEC_ENTRY ChangeAccountPasswordW(
    [in] SEC_WCHAR *pszPackageName,
    [in] SEC_WCHAR *pszDomainName,
    [in] SEC_WCHAR *pszAccountName,
    [in] SEC_WCHAR *pszOldPassword,
    [in] SEC_WCHAR *pszNewPassword,
    [in] BOOLEAN bImpersonating,
    [in] unsigned long dwReserved,
    [in, out] PSecBufferDesc pOutput
);

SECURITY_STATUS SEC_ENTRY CompleteAuthToken(
    [in] PCtxtHandle phContext,
    [in] PSecBufferDesc pToken
);

KSECDDDECLSPEC SECURITY_STATUS SEC_ENTRY QueryContextAttributesW(
    [in] PCtxtHandle phContext,
    [in] unsigned long ulAttribute,
    [out] void *pBuffer
);

SECURITY_STATUS SEC_ENTRY SetContextAttributesW(
    [in] PCtxtHandle phContext,
    [in] unsigned long ulAttribute,
    [in] void *pBuffer,
    [in] unsigned long cbBuffer
);

SECURITY_STATUS SEC_ENTRY SaslGetContextOption(
    [in] PCtxtHandle ContextHandle,
    [in] ULONG Option,
    [out] PVOID Value,
    [out] ULONG Size,
    [out, optional] PULONG Needed
);

KSECDDDECLSPEC SECURITY_STATUS SEC_ENTRY QuerySecurityContextToken(
    [in] PCtxtHandle phContext,
    [out] void **Token
);

SECURITY_STATUS SEC_ENTRY InitializeSecurityContextA(
    [in, optional] PCredHandle phCredential,
    [in, optional] PCtxtHandle phContext,
    SEC_CHAR *pszTargetName,
    [in] unsigned long fContextReq,
    [in] unsigned long Reserved1,
    [in] unsigned long TargetDataRep,
    [in, optional] PSecBufferDesc pInput,
    [in] unsigned long Reserved2,
    [in, out, optional] PCtxtHandle phNewContext,
    [in, out, optional] PSecBufferDesc pOutput,
    [out] unsigned long *pfContextAttr,
    [out, optional] PTimeStamp ptsExpiry
);

SECURITY_STATUS SEC_ENTRY SspiCompareAuthIdentities(
    [in] PSEC_WINNT_AUTH_IDENTITY_OPAQUE AuthIdentity1,
    [in] PSEC_WINNT_AUTH_IDENTITY_OPAQUE AuthIdentity2,
    [out] PBOOLEAN SameSuppliedUser,
    [out] PBOOLEAN SameSuppliedIdentity
);

KSECDDDECLSPEC PSecurityFunctionTableW SEC_ENTRY InitSecurityInterfaceW();

KSECDDDECLSPEC SECURITY_STATUS SEC_ENTRY ImpersonateSecurityContext(
    [in] PCtxtHandle phContext
);

KSECDDDECLSPEC SECURITY_STATUS SEC_ENTRY InitializeSecurityContextW(
    [in, optional] PCredHandle phCredential,
    [in, optional] PCtxtHandle phContext,
    [in, optional] PSECURITY_STRING pTargetName,
    [in] unsigned long fContextReq,
    [in] unsigned long Reserved1,
    [in] unsigned long TargetDataRep,
    [in, optional] PSecBufferDesc pInput,
    [in] unsigned long Reserved2,
    [in, out, optional] PCtxtHandle phNewContext,
    [in, out, optional] PSecBufferDesc pOutput,
    [out] unsigned long *pfContextAttr,
    [out, optional] PTimeStamp ptsExpiry
);

SECURITY_STATUS SEC_ENTRY SspiValidateAuthIdentity(
    [in] PSEC_WINNT_AUTH_IDENTITY_OPAQUE AuthData
);

SECURITY_STATUS SEC_ENTRY SspiExcludePackage(
    [in] PSEC_WINNT_AUTH_IDENTITY_OPAQUE AuthIdentity,
    [in] PCWSTR pszPackageName,
    [out] PSEC_WINNT_AUTH_IDENTITY_OPAQUE *ppNewAuthIdentity
);

SECURITY_STATUS SEC_ENTRY SspiDecryptAuthIdentityEx(
    [in] ULONG Options,
    [in, out] PSEC_WINNT_AUTH_IDENTITY_OPAQUE EncryptedAuthData
);

SECURITY_STATUS SEC_ENTRY DecryptMessage(
    [in] PCtxtHandle phContext,
    [in, out] PSecBufferDesc pMessage,
    [in] unsigned long MessageSeqNo,
    [out] unsigned long *pfQOP
);

SECURITY_STATUS SEC_ENTRY SspiEncryptAuthIdentity(
    [in, out] PSEC_WINNT_AUTH_IDENTITY_OPAQUE AuthData
);

SECURITY_STATUS SEC_ENTRY SspiCopyAuthIdentity(
    [in] PSEC_WINNT_AUTH_IDENTITY_OPAQUE AuthData,
    [out] PSEC_WINNT_AUTH_IDENTITY_OPAQUE *AuthDataCopy
);

SECURITY_STATUS SEC_ENTRY SaslGetProfilePackageW(
    [in] LPWSTR ProfileName,
    [out] PSecPkgInfoW *PackageInfo
);

KSECDDDECLSPEC SECURITY_STATUS SEC_ENTRY DeleteSecurityContext(
    [in] PCtxtHandle phContext
);

BOOLEAN SspiAsyncContextRequiresNotify(
    SspiAsyncContext *AsyncContext
);

SECURITY_STATUS SEC_ENTRY SetContextAttributesA(
    [in] PCtxtHandle phContext,
    [in] unsigned long ulAttribute,
    [in] void *pBuffer,
    [in] unsigned long cbBuffer
);

SECURITY_STATUS SspiGetAsyncCallStatus(
    SspiAsyncContext *Handle
);

SECURITY_STATUS SEC_ENTRY QuerySecurityPackageInfoA(
    [in] LPSTR pszPackageName,
    [out] PSecPkgInfoA *ppPackageInfo
);

SECURITY_STATUS SEC_ENTRY SetCredentialsAttributesA(
    [in] PCredHandle phCredential,
    [in] unsigned long ulAttribute,
    [in] void *pBuffer,
    unsigned long cbBuffer
);

SECURITY_STATUS SEC_ENTRY AddSecurityPackageW(
    [in] LPWSTR pszPackageName,
    [in] PSECURITY_PACKAGE_OPTIONS pOptions
);

SECURITY_STATUS SspiDeleteSecurityContextAsync(
    SspiAsyncContext *AsyncContext,
    PCtxtHandle phContext
);

SECURITY_STATUS SEC_ENTRY EncryptMessage(
    [in] PCtxtHandle phContext,
    [in] unsigned long fQOP,
    [in, out] PSecBufferDesc pMessage,
    [in] unsigned long MessageSeqNo
);

PSecurityFunctionTableA SEC_ENTRY InitSecurityInterfaceA();

SECURITY_STATUS SEC_ENTRY QueryCredentialsAttributesA(
    [in] PCredHandle phCredential,
    [in] unsigned long ulAttribute,
    [out] void *pBuffer
);

SECURITY_STATUS SEC_ENTRY SaslGetProfilePackageA(
    [in] LPSTR ProfileName,
    [out] PSecPkgInfoA *PackageInfo
);

VOID SEC_ENTRY SspiZeroAuthIdentity(
    [in] PSEC_WINNT_AUTH_IDENTITY_OPAQUE AuthData
);

