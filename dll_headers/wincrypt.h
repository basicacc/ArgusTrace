BOOL CryptSignCertificate(
    [in] BCRYPT_KEY_HANDLE hBCryptKey,
    [in] DWORD dwKeySpec,
    [in] DWORD dwCertEncodingType,
    [in] const BYTE *pbEncodedToBeSigned,
    [in] DWORD cbEncodedToBeSigned,
    [in] PCRYPT_ALGORITHM_IDENTIFIER pSignatureAlgorithm,
    [in] const void *pvHashAuxInfo,
    [out] BYTE *pbSignature,
    [in, out] DWORD *pcbSignature
);

BOOL CertFreeCTLContext(
    [in] PCCTL_CONTEXT pCtlContext
);

BOOL CryptVerifyMessageSignatureWithKey(
    [in] PCRYPT_KEY_VERIFY_MESSAGE_PARA pVerifyPara,
    [in] PCERT_PUBLIC_KEY_INFO pPublicKeyInfo,
    [in] const BYTE *pbSignedBlob,
    [in] DWORD cbSignedBlob,
    [out] BYTE *pbDecoded,
    [in, out] DWORD *pcbDecoded
);

LPVOID CryptMemRealloc(
    [in] LPVOID pv,
    [in] ULONG cbSize
);

PCRYPT_ATTRIBUTE CertFindAttribute(
    [in] LPCSTR pszObjId,
    [in] DWORD cAttr,
    [in] CRYPT_ATTRIBUTE [] rgAttr
);

PCCERT_CONTEXT CertGetSubjectCertificateFromStore(
    [in] HCERTSTORE hCertStore,
    [in] DWORD dwCertEncodingType,
    [in] PCERT_INFO pCertId
);

LPVOID CryptMemAlloc(
    [in] ULONG cbSize
);

BOOL CertGetCertificateContextProperty(
    [in] PCCERT_CONTEXT pCertContext,
    [in] DWORD dwPropId,
    [out] void *pvData,
    [in, out] DWORD *pcbData
);

BOOL CertGetCRLContextProperty(
    [in] PCCRL_CONTEXT pCrlContext,
    [in] DWORD dwPropId,
    [out] void *pvData,
    [in, out] DWORD *pcbData
);

BOOL CryptFindCertificateKeyProvInfo(
    [in] PCCERT_CONTEXT pCert,
    [in] DWORD dwFlags,
    [in] void *pvReserved
);

BOOL CryptFormatObject(
    [in] DWORD dwCertEncodingType,
    [in] DWORD dwFormatType,
    [in] DWORD dwFormatStrType,
    [in] void *pFormatStruct,
    [in] LPCSTR lpszStructType,
    [in] const BYTE *pbEncoded,
    [in] DWORD cbEncoded,
    [out] void *pbFormat,
    [in, out] DWORD *pcbFormat
);

BOOL CertVerifySubjectCertificateContext(
    [in] PCCERT_CONTEXT pSubject,
    [in, optional] PCCERT_CONTEXT pIssuer,
    [in, out] DWORD *pdwFlags
);

BOOL CertGetEnhancedKeyUsage(
    [in] PCCERT_CONTEXT pCertContext,
    [in] DWORD dwFlags,
    [out] PCERT_ENHKEY_USAGE pUsage,
    [in, out] DWORD *pcbUsage
);

BOOL CertAddCertificateLinkToStore(
    [in] HCERTSTORE hCertStore,
    [in] PCCERT_CONTEXT pCertContext,
    [in] DWORD dwAddDisposition,
    [out, optional] PCCERT_CONTEXT *ppStoreContext
);

BOOL CryptExportPublicKeyInfo(
    [in] HCRYPTPROV_OR_NCRYPT_KEY_HANDLE hCryptProvOrNCryptKey,
    [in] DWORD dwKeySpec,
    [in] DWORD dwCertEncodingType,
    [out] PCERT_PUBLIC_KEY_INFO pInfo,
    [in, out] DWORD *pcbInfo
);

BOOL CryptExportPublicKeyInfoEx(
    [in] HCRYPTPROV_OR_NCRYPT_KEY_HANDLE hCryptProvOrNCryptKey,
    [in] DWORD dwKeySpec,
    [in] DWORD dwCertEncodingType,
    [in] LPSTR pszPublicKeyObjId,
    [in] DWORD dwFlags,
    [in] void *pvAuxInfo,
    [out] PCERT_PUBLIC_KEY_INFO pInfo,
    [in, out] DWORD *pcbInfo
);

BOOL CryptMsgClose(
    [in] HCRYPTMSG hCryptMsg
);

DWORD CertEnumCTLContextProperties(
    [in] PCCTL_CONTEXT pCtlContext,
    [in] DWORD dwPropId
);

BOOL CryptHashCertificate(
    [in] HCRYPTPROV_LEGACY hCryptProv,
    [in] ALG_ID Algid,
    [in] DWORD dwFlags,
    [in] const BYTE *pbEncoded,
    [in] DWORD cbEncoded,
    [out] BYTE *pbComputedHash,
    [in, out] DWORD *pcbComputedHash
);

BOOL CryptGetUserKey(
    [in] HCRYPTPROV hProv,
    [in] DWORD dwKeySpec,
    [out] HCRYPTKEY *phUserKey
);

BOOL CryptSetKeyParam(
    [in] HCRYPTKEY hKey,
    [in] DWORD dwParam,
    [in] const BYTE *pbData,
    [in] DWORD dwFlags
);

BOOL CryptQueryObject(
    [in] DWORD dwObjectType,
    [in] const void *pvObject,
    [in] DWORD dwExpectedContentTypeFlags,
    [in] DWORD dwExpectedFormatTypeFlags,
    [in] DWORD dwFlags,
    [out] DWORD *pdwMsgAndCertEncodingType,
    [out] DWORD *pdwContentType,
    [out] DWORD *pdwFormatType,
    [out] HCERTSTORE *phCertStore,
    [out] HCRYPTMSG *phMsg,
    [out] const void **ppvContext
);

BOOL CryptDecrypt(
    [in] HCRYPTKEY hKey,
    [in] HCRYPTHASH hHash,
    [in] BOOL Final,
    [in] DWORD dwFlags,
    [in, out] BYTE *pbData,
    [in, out] DWORD *pdwDataLen
);

BOOL CertControlStore(
    [in] HCERTSTORE hCertStore,
    [in] DWORD dwFlags,
    [in] DWORD dwCtrlType,
    [in] void const *pvCtrlPara
);

BOOL CertCreateCTLEntryFromCertificateContextProperties(
    [in] PCCERT_CONTEXT pCertContext,
    [in] DWORD cOptAttr,
    [in] PCRYPT_ATTRIBUTE rgOptAttr,
    [in] DWORD dwFlags,
    [in] void *pvReserved,
    [out] PCTL_ENTRY pCtlEntry,
    [in, out] DWORD *pcbCtlEntry
);

BOOL CryptMsgCountersign(
    [in, out] HCRYPTMSG hCryptMsg,
    [in] DWORD dwIndex,
    [in] DWORD cCountersigners,
    [in] PCMSG_SIGNER_ENCODE_INFO rgCountersigners
);

BOOL CertFindSubjectInSortedCTL(
    [in] PCRYPT_DATA_BLOB pSubjectIdentifier,
    [in] PCCTL_CONTEXT pCtlContext,
    [in] DWORD dwFlags,
    [in] void *pvReserved,
    [out] PCRYPT_DER_BLOB pEncodedAttributes
);

PCCRL_CONTEXT CertDuplicateCRLContext(
    [in] PCCRL_CONTEXT pCrlContext
);

BOOL CertRetrieveLogoOrBiometricInfo(
    [in] PCCERT_CONTEXT pCertContext,
    [in] LPCSTR lpszLogoOrBiometricType,
    [in] DWORD dwRetrievalFlags,
    [in] DWORD dwTimeout,
    [in] DWORD dwFlags,
    void *pvReserved,
    [out] BYTE **ppbData,
    [out] DWORD *pcbData,
    [out] LPWSTR *ppwszMimeType
);

BOOL CertAddCertificateContextToStore(
    [in] HCERTSTORE hCertStore,
    [in] PCCERT_CONTEXT pCertContext,
    [in] DWORD dwAddDisposition,
    [out, optional] PCCERT_CONTEXT *ppStoreContext
);

BOOL CertIsStrongHashToSign(
    [in] PCCERT_STRONG_SIGN_PARA pStrongSignPara,
    [in] LPCWSTR pwszCNGHashAlgid,
    [in, optional] PCCERT_CONTEXT pSigningCert
);

BOOL CertSetCertificateContextProperty(
    [in] PCCERT_CONTEXT pCertContext,
    [in] DWORD dwPropId,
    [in] DWORD dwFlags,
    [in] const void *pvData
);

BOOL CryptEncryptMessage(
    [in] PCRYPT_ENCRYPT_MESSAGE_PARA pEncryptPara,
    [in] DWORD cRecipientCert,
    [in] PCCERT_CONTEXT [] rgpRecipientCert,
    [in] const BYTE *pbToBeEncrypted,
    [in] DWORD cbToBeEncrypted,
    [out] BYTE *pbEncryptedBlob,
    [in, out] DWORD *pcbEncryptedBlob
);

BOOL CryptEnumProvidersA(
    [in] DWORD dwIndex,
    [in] DWORD *pdwReserved,
    [in] DWORD dwFlags,
    [out] DWORD *pdwProvType,
    [out] LPSTR szProvName,
    [in, out] DWORD *pcbProvName
);

HCRYPTMSG CryptMsgOpenToEncode(
    [in] DWORD dwMsgEncodingType,
    [in] DWORD dwFlags,
    [in] DWORD dwMsgType,
    [in] void const *pvMsgEncodeInfo,
    [in, optional] LPSTR pszInnerContentObjID,
    [in] PCMSG_STREAM_INFO pStreamInfo
);

BOOL CryptSignMessageWithKey(
    [in] PCRYPT_KEY_SIGN_MESSAGE_PARA pSignPara,
    [in] const BYTE *pbToBeSigned,
    [in] DWORD cbToBeSigned,
    [out] BYTE *pbSignedBlob,
    [in, out] DWORD *pcbSignedBlob
);

BOOL CryptVerifyDetachedMessageSignature(
    [in] PCRYPT_VERIFY_MESSAGE_PARA pVerifyPara,
    [in] DWORD dwSignerIndex,
    [in] const BYTE *pbDetachedSignBlob,
    [in] DWORD cbDetachedSignBlob,
    [in] DWORD cToBeSigned,
    [in] const BYTE * [] rgpbToBeSigned,
    [in] DWORD [] rgcbToBeSigned,
    [out, optional] PCCERT_CONTEXT *ppSignerCert
);

const void * CertCreateContext(
    [in] DWORD dwContextType,
    [in] DWORD dwEncodingType,
    [in] const BYTE *pbEncoded,
    [in] DWORD cbEncoded,
    [in] DWORD dwFlags,
    [in, optional] PCERT_CREATE_CONTEXT_PARA pCreatePara
);

BOOL CertFreeCertificateContext(
    [in] PCCERT_CONTEXT pCertContext
);

BOOL CryptSetHashParam(
    [in] HCRYPTHASH hHash,
    [in] DWORD dwParam,
    [in] const BYTE *pbData,
    [in] DWORD dwFlags
);

DWORD CertGetNameStringA(
    [in] PCCERT_CONTEXT pCertContext,
    [in] DWORD dwType,
    [in] DWORD dwFlags,
    [in] void *pvTypePara,
    [out] LPSTR pszNameString,
    [in] DWORD cchNameString
);

BOOL CryptGetObjectUrl(
    [in] LPCSTR pszUrlOid,
    [in] LPVOID pvPara,
    [in] DWORD dwFlags,
    [out] PCRYPT_URL_ARRAY pUrlArray,
    [in, out] DWORD *pcbUrlArray,
    [out] PCRYPT_URL_INFO pUrlInfo,
    [in, out] DWORD *pcbUrlInfo,
    LPVOID pvReserved
);

BOOL CryptEncodeObjectEx(
    [in] DWORD dwCertEncodingType,
    [in] LPCSTR lpszStructType,
    [in] const void *pvStructInfo,
    [in] DWORD dwFlags,
    [in] PCRYPT_ENCODE_PARA pEncodePara,
    [out] void *pvEncoded,
    [in, out] DWORD *pcbEncoded
);

BOOL CryptSignAndEncryptMessage(
    [in] PCRYPT_SIGN_MESSAGE_PARA pSignPara,
    [in] PCRYPT_ENCRYPT_MESSAGE_PARA pEncryptPara,
    [in] DWORD cRecipientCert,
    [in] PCCERT_CONTEXT [] rgpRecipientCert,
    [in] const BYTE *pbToBeSignedAndEncrypted,
    [in] DWORD cbToBeSignedAndEncrypted,
    [out] BYTE *pbSignedAndEncryptedBlob,
    [in, out] DWORD *pcbSignedAndEncryptedBlob
);

BOOL CryptSetProviderExA(
    [in] LPCSTR pszProvName,
    [in] DWORD dwProvType,
    [in] DWORD *pdwReserved,
    [in] DWORD dwFlags
);

BOOL CertVerifyCRLRevocation(
    [in] DWORD dwCertEncodingType,
    [in] PCERT_INFO pCertId,
    [in] DWORD cCrlInfo,
    [in] PCRL_INFO [] rgpCrlInfo
);

BOOL CryptMsgGetAndVerifySigner(
    [in] HCRYPTMSG hCryptMsg,
    [in] DWORD cSignerStore,
    [in, optional] HCERTSTORE *rghSignerStore,
    [in] DWORD dwFlags,
    [out, optional] PCCERT_CONTEXT *ppSigner,
    [in, out, optional] DWORD *pdwSignerIndex
);

PCCRL_CONTEXT CertFindCRLInStore(
    [in] HCERTSTORE hCertStore,
    [in] DWORD dwCertEncodingType,
    [in] DWORD dwFindFlags,
    [in] DWORD dwFindType,
    [in] const void *pvFindPara,
    [in] PCCRL_CONTEXT pPrevCrlContext
);

BOOL CertAddStoreToCollection(
    [in] HCERTSTORE hCollectionStore,
    [in, optional] HCERTSTORE hSiblingStore,
    [in] DWORD dwUpdateFlags,
    [in] DWORD dwPriority
);

BOOL CryptSignAndEncodeCertificate(
    [in] BCRYPT_KEY_HANDLE hBCryptKey,
    [in] DWORD dwKeySpec,
    [in] DWORD dwCertEncodingType,
    [in] LPCSTR lpszStructType,
    [in] const void *pvStructInfo,
    [in] PCRYPT_ALGORITHM_IDENTIFIER pSignatureAlgorithm,
    [in] const void *pvHashAuxInfo,
    [out] BYTE *pbEncoded,
    [in, out] DWORD *pcbEncoded
);

PCCERT_CONTEXT CertCreateCertificateContext(
    [in] DWORD dwCertEncodingType,
    [in] const BYTE *pbCertEncoded,
    [in] DWORD cbCertEncoded
);

PCTL_ENTRY CertFindSubjectInCTL(
    [in] DWORD dwEncodingType,
    [in] DWORD dwSubjectType,
    [in] void *pvSubject,
    [in] PCCTL_CONTEXT pCtlContext,
    [in] DWORD dwFlags
);

DWORD CertNameToStrW(
    [in] DWORD dwCertEncodingType,
    [in] PCERT_NAME_BLOB pName,
    [in] DWORD dwStrType,
    [out] LPWSTR psz,
    [in] DWORD csz
);

BOOL CertRegisterPhysicalStore(
    [in] const void *pvSystemStore,
    [in] DWORD dwFlags,
    [in] LPCWSTR pwszStoreName,
    [in] PCERT_PHYSICAL_STORE_INFO pStoreInfo,
    [in] void *pvReserved
);

BOOL CertAddEncodedCRLToStore(
    [in] HCERTSTORE hCertStore,
    [in] DWORD dwCertEncodingType,
    [in] const BYTE *pbCrlEncoded,
    [in] DWORD cbCrlEncoded,
    [in] DWORD dwAddDisposition,
    [out, optional] PCCRL_CONTEXT *ppCrlContext
);

LONG CertVerifyTimeValidity(
    [in] LPFILETIME pTimeToVerify,
    [in] PCERT_INFO pCertInfo
);

BOOL CryptStringToBinaryW(
    [in] LPCWSTR pszString,
    [in] DWORD cchString,
    [in] DWORD dwFlags,
    [in] BYTE *pbBinary,
    [in, out] DWORD *pcbBinary,
    [out] DWORD *pdwSkip,
    [out] DWORD *pdwFlags
);

BOOL CryptDuplicateKey(
    [in] HCRYPTKEY hKey,
    [in] DWORD *pdwReserved,
    [in] DWORD dwFlags,
    [out] HCRYPTKEY *phKey
);

HCRYPTMSG CryptMsgDuplicate(
    [in] HCRYPTMSG hCryptMsg
);

BOOL CryptRegisterDefaultOIDFunction(
    [in] DWORD dwEncodingType,
    [in] LPCSTR pszFuncName,
    [in] DWORD dwIndex,
    [in] LPCWSTR pwszDll
);

BOOL CryptVerifySignatureA(
    [in] HCRYPTHASH hHash,
    [in] const BYTE *pbSignature,
    [in] DWORD dwSigLen,
    [in] HCRYPTKEY hPubKey,
    [in] LPCSTR szDescription,
    [in] DWORD dwFlags
);

BOOL CertVerifyCTLUsage(
    [in] DWORD dwEncodingType,
    [in] DWORD dwSubjectType,
    [in] void *pvSubject,
    [in] PCTL_USAGE pSubjectUsage,
    [in] DWORD dwFlags,
    [in, optional] PCTL_VERIFY_USAGE_PARA pVerifyUsagePara,
    [in, out] PCTL_VERIFY_USAGE_STATUS pVerifyUsageStatus
);

LONG CryptGetMessageSignerCount(
    [in] DWORD dwMsgEncodingType,
    [in] const BYTE *pbSignedBlob,
    [in] DWORD cbSignedBlob
);

BOOL CryptGetDefaultProviderA(
    [in] DWORD dwProvType,
    [in] DWORD *pdwReserved,
    [in] DWORD dwFlags,
    [out] LPSTR pszProvName,
    [in, out] DWORD *pcbProvName
);

BOOL CryptEnumOIDInfo(
    [in] DWORD dwGroupId,
    [in] DWORD dwFlags,
    [in] void *pvArg,
    [in] PFN_CRYPT_ENUM_OID_INFO pfnEnumOIDInfo
);

BOOL CryptHashPublicKeyInfo(
    [in] HCRYPTPROV_LEGACY hCryptProv,
    [in] ALG_ID Algid,
    [in] DWORD dwFlags,
    [in] DWORD dwCertEncodingType,
    [in] PCERT_PUBLIC_KEY_INFO pInfo,
    [out] BYTE *pbComputedHash,
    [in, out] DWORD *pcbComputedHash
);

BOOL CryptBinaryToStringW(
    [in] const BYTE *pbBinary,
    [in] DWORD cbBinary,
    [in] DWORD dwFlags,
    [out, optional] LPWSTR pszString,
    [in, out] DWORD *pcchString
);

BOOL CryptVerifySignatureW(
    [in] HCRYPTHASH hHash,
    [in] const BYTE *pbSignature,
    [in] DWORD dwSigLen,
    [in] HCRYPTKEY hPubKey,
    [in] LPCWSTR szDescription,
    [in] DWORD dwFlags
);

BOOL CertSetStoreProperty(
    [in] HCERTSTORE hCertStore,
    [in] DWORD dwPropId,
    [in] DWORD dwFlags,
    [in] const void *pvData
);

BOOL CryptSignHashA(
    [in] HCRYPTHASH hHash,
    [in] DWORD dwKeySpec,
    [in] LPCSTR szDescription,
    [in] DWORD dwFlags,
    [out] BYTE *pbSignature,
    [in, out] DWORD *pdwSigLen
);

BOOL CryptSetProvParam(
    [in] HCRYPTPROV hProv,
    [in] DWORD dwParam,
    [in] const BYTE *pbData,
    [in] DWORD dwFlags
);

BOOL CertAddEnhancedKeyUsageIdentifier(
    [in] PCCERT_CONTEXT pCertContext,
    [in] LPCSTR pszUsageIdentifier
);

PCCTL_CONTEXT CertCreateCTLContext(
    [in] DWORD dwMsgAndCertEncodingType,
    [in] const BYTE *pbCtlEncoded,
    [in] DWORD cbCtlEncoded
);

BOOL CertGetCTLContextProperty(
    [in] PCCTL_CONTEXT pCtlContext,
    [in] DWORD dwPropId,
    [out] void *pvData,
    [in, out] DWORD *pcbData
);

BOOL CryptGetDefaultOIDDllList(
    [in] HCRYPTOIDFUNCSET hFuncSet,
    [in] DWORD dwEncodingType,
    [out] WCHAR *pwszDllList,
    [in, out] DWORD *pcchDllList
);

PCCERT_CONTEXT CertDuplicateCertificateContext(
    [in] PCCERT_CONTEXT pCertContext
);

BOOL CryptInstallDefaultContext(
    [in] HCRYPTPROV hCryptProv,
    [in] DWORD dwDefaultType,
    [in] const void *pvDefaultPara,
    [in] DWORD dwFlags,
    [in] void *pvReserved,
    [out] HCRYPTDEFAULTCONTEXT *phDefaultContext
);

BOOL PFXVerifyPassword(
    [in] CRYPT_DATA_BLOB *pPFX,
    [in] LPCWSTR szPassword,
    [in] DWORD dwFlags
);

BOOL CertSaveStore(
    [in] HCERTSTORE hCertStore,
    [in] DWORD dwEncodingType,
    [in] DWORD dwSaveAs,
    [in] DWORD dwSaveTo,
    [in, out] void *pvSaveToPara,
    [in] DWORD dwFlags
);

DWORD CertNameToStrA(
    [in] DWORD dwCertEncodingType,
    [in] PCERT_NAME_BLOB pName,
    [in] DWORD dwStrType,
    [out] LPSTR psz,
    [in] DWORD csz
);

BOOL CryptGetHashParam(
    [in] HCRYPTHASH hHash,
    [in] DWORD dwParam,
    [out] BYTE *pbData,
    [in, out] DWORD *pdwDataLen,
    [in] DWORD dwFlags
);

void CertFreeCertificateChain(
    [in] PCCERT_CHAIN_CONTEXT pChainContext
);

BOOL CryptSetProviderExW(
    [in] LPCWSTR pszProvName,
    [in] DWORD dwProvType,
    [in] DWORD *pdwReserved,
    [in] DWORD dwFlags
);

BOOL CryptEncodeObject(
    [in] DWORD dwCertEncodingType,
    [in] LPCSTR lpszStructType,
    [in] const void *pvStructInfo,
    [out] BYTE *pbEncoded,
    [in, out] DWORD *pcbEncoded
);

HCERT_SERVER_OCSP_RESPONSE CertOpenServerOcspResponse(
    [in] PCCERT_CHAIN_CONTEXT pChainContext,
    [in] DWORD dwFlags,
    PCERT_SERVER_OCSP_RESPONSE_OPEN_PARA pOpenPara
);

BOOL CryptGenRandom(
    [in] HCRYPTPROV hProv,
    [in] DWORD dwLen,
    [in, out] BYTE *pbBuffer
);

void CertFreeServerOcspResponseContext(
    [in] PCCERT_SERVER_OCSP_RESPONSE_CONTEXT pServerOcspResponseContext
);

BOOL CryptSignMessage(
    [in] PCRYPT_SIGN_MESSAGE_PARA pSignPara,
    [in] BOOL fDetachedSignature,
    [in] DWORD cToBeSigned,
    [in] const BYTE * [] rgpbToBeSigned,
    [in] DWORD [] rgcbToBeSigned,
    [out] BYTE *pbSignedBlob,
    [in, out] DWORD *pcbSignedBlob
);

void CertCloseServerOcspResponse(
    [in] HCERT_SERVER_OCSP_RESPONSE hServerOcspResponse,
    [in] DWORD dwFlags
);

BOOL CertEnumSystemStore(
    [in] DWORD dwFlags,
    [in, optional] void *pvSystemStoreLocationPara,
    [in] void *pvArg,
    [in] PFN_CERT_ENUM_SYSTEM_STORE pfnEnum
);

BOOL CryptGetAsyncParam(
    HCRYPTASYNC hAsync,
    LPSTR pszParamOid,
    LPVOID *ppvParam,
    PFN_CRYPT_ASYNC_PARAM_FREE_FUNC *ppfnFree
);

BOOL CryptGetOIDFunctionValue(
    [in] DWORD dwEncodingType,
    [in] LPCSTR pszFuncName,
    [in] LPCSTR pszOID,
    [in] LPCWSTR pwszValueName,
    [out] DWORD *pdwValueType,
    [out] BYTE *pbValueData,
    [in, out] DWORD *pcbValueData
);

BOOL PFXIsPFXBlob(
    [in] CRYPT_DATA_BLOB *pPFX
);

PCCERT_CHAIN_CONTEXT CertFindChainInStore(
    [in] HCERTSTORE hCertStore,
    [in] DWORD dwCertEncodingType,
    [in] DWORD dwFindFlags,
    [in] DWORD dwFindType,
    [in] const void *pvFindPara,
    [in] PCCERT_CHAIN_CONTEXT pPrevChainContext
);

BOOL CertIsRDNAttrsInCertificateName(
    [in] DWORD dwCertEncodingType,
    [in] DWORD dwFlags,
    [in] PCERT_NAME_BLOB pCertName,
    [in] PCERT_RDN pRDN
);

BOOL CertCreateCertificateChainEngine(
    [in] PCERT_CHAIN_ENGINE_CONFIG pConfig,
    [out] HCERTCHAINENGINE *phChainEngine
);

PCERT_EXTENSION CertFindExtension(
    [in] LPCSTR pszObjId,
    [in] DWORD cExtensions,
    [in] CERT_EXTENSION [] rgExtensions
);

BOOL CryptFreeOIDFunctionAddress(
    [in] HCRYPTOIDFUNCADDR hFuncAddr,
    [in] DWORD dwFlags
);

BOOL CryptMsgVerifyCountersignatureEncodedEx(
    [in, optional] HCRYPTPROV_LEGACY hCryptProv,
    [in] DWORD dwEncodingType,
    [in] PBYTE pbSignerInfo,
    [in] DWORD cbSignerInfo,
    [in] PBYTE pbSignerInfoCountersignature,
    [in] DWORD cbSignerInfoCountersignature,
    [in] DWORD dwSignerType,
    [in] void *pvSigner,
    DWORD dwFlags,
    void *pvExtra
);

BOOL CertSerializeCRLStoreElement(
    [in] PCCRL_CONTEXT pCrlContext,
    [in] DWORD dwFlags,
    [out] BYTE *pbElement,
    [in, out] DWORD *pcbElement
);

BOOL CryptDecodeObject(
    [in] DWORD dwCertEncodingType,
    [in] LPCSTR lpszStructType,
    [in] const BYTE *pbEncoded,
    [in] DWORD cbEncoded,
    [in] DWORD dwFlags,
    [out] void *pvStructInfo,
    [in, out] DWORD *pcbStructInfo
);

BOOL CryptGetKeyIdentifierProperty(
    [in] const CRYPT_HASH_BLOB *pKeyIdentifier,
    [in] DWORD dwPropId,
    [in] DWORD dwFlags,
    [in] LPCWSTR pwszComputerName,
    [in] void *pvReserved,
    [out] void *pvData,
    [in, out] DWORD *pcbData
);

BOOL CryptEnumProvidersW(
    [in] DWORD dwIndex,
    [in] DWORD *pdwReserved,
    [in] DWORD dwFlags,
    [out] DWORD *pdwProvType,
    [out] LPWSTR szProvName,
    [in, out] DWORD *pcbProvName
);

BOOL CryptGetProvParam(
    [in] HCRYPTPROV hProv,
    [in] DWORD dwParam,
    [out] BYTE *pbData,
    [in, out] DWORD *pdwDataLen,
    [in] DWORD dwFlags
);

BOOL CertGetStoreProperty(
    [in] HCERTSTORE hCertStore,
    [in] DWORD dwPropId,
    [out] void *pvData,
    [in, out] DWORD *pcbData
);

DWORD CertRDNValueToStrA(
    [in] DWORD dwValueType,
    [in] PCERT_RDN_VALUE_BLOB pValue,
    [out] LPSTR psz,
    [in] DWORD csz
);

BOOL CryptSignHashW(
    [in] HCRYPTHASH hHash,
    [in] DWORD dwKeySpec,
    [in] LPCWSTR szDescription,
    [in] DWORD dwFlags,
    [out] BYTE *pbSignature,
    [in, out] DWORD *pdwSigLen
);

BOOL CertEnumSystemStoreLocation(
    [in] DWORD dwFlags,
    [in] void *pvArg,
    [in] PFN_CERT_ENUM_SYSTEM_STORE_LOCATION pfnEnum
);

BOOL CryptEnumKeyIdentifierProperties(
    [in, optional] const CRYPT_HASH_BLOB *pKeyIdentifier,
    [in] DWORD dwPropId,
    [in] DWORD dwFlags,
    [in, optional] LPCWSTR pwszComputerName,
    [in] void *pvReserved,
    [in, optional] void *pvArg,
    [in] PFN_CRYPT_ENUM_KEYID_PROP pfnEnum
);

BOOL CertRegisterSystemStore(
    [in] const void *pvSystemStore,
    [in] DWORD dwFlags,
    [in] PCERT_SYSTEM_STORE_INFO pStoreInfo,
    [in] void *pvReserved
);

HCERTSTORE PFXImportCertStore(
    [in] CRYPT_DATA_BLOB *pPFX,
    [in] LPCWSTR szPassword,
    [in] DWORD dwFlags
);

BOOL CryptExportPublicKeyInfoFromBCryptKeyHandle(
    [in] BCRYPT_KEY_HANDLE hBCryptKey,
    [in] DWORD dwCertEncodingType,
    [in, optional] LPSTR pszPublicKeyObjId,
    [in] DWORD dwFlags,
    [in, optional] void *pvAuxInfo,
    [out, optional] PCERT_PUBLIC_KEY_INFO pInfo,
    [in, out] DWORD *pcbInfo
);

BOOL CertUnregisterSystemStore(
    [in] const void *pvSystemStore,
    [in] DWORD dwFlags
);

BOOL CryptUnregisterOIDInfo(
    [in] PCCRYPT_OID_INFO pInfo
);

BOOL CryptMsgEncodeAndSignCTL(
    [in] DWORD dwMsgEncodingType,
    [in] PCTL_INFO pCtlInfo,
    [in] PCMSG_SIGNED_ENCODE_INFO pSignInfo,
    [in] DWORD dwFlags,
    [out] BYTE *pbEncoded,
    [in, out] DWORD *pcbEncoded
);

BOOL CertFindCertificateInCRL(
    [in] PCCERT_CONTEXT pCert,
    [in] PCCRL_CONTEXT pCrlContext,
    [in] DWORD dwFlags,
    [in, optional] void *pvReserved,
    [out] PCRL_ENTRY *ppCrlEntry
);

BOOL CryptMsgGetParam(
    [in] HCRYPTMSG hCryptMsg,
    [in] DWORD dwParamType,
    [in] DWORD dwIndex,
    [out] void *pvData,
    [in, out] DWORD *pcbData
);

BOOL CryptSetProviderA(
    [in] LPCSTR pszProvName,
    [in] DWORD dwProvType
);

BOOL CryptGetDefaultOIDFunctionAddress(
    [in] HCRYPTOIDFUNCSET hFuncSet,
    [in] DWORD dwEncodingType,
    [in, optional] LPCWSTR pwszDll,
    [in] DWORD dwFlags,
    [out] void **ppvFuncAddr,
    [in, out] HCRYPTOIDFUNCADDR *phFuncAddr
);

BOOL CryptImportPublicKeyInfoEx(
    [in] HCRYPTPROV hCryptProv,
    [in] DWORD dwCertEncodingType,
    [in] PCERT_PUBLIC_KEY_INFO pInfo,
    [in] ALG_ID aiKeyAlg,
    [in] DWORD dwFlags,
    [in] void *pvAuxInfo,
    [out] HCRYPTKEY *phKey
);

DWORD CertEnumCRLContextProperties(
    [in] PCCRL_CONTEXT pCrlContext,
    [in] DWORD dwPropId
);

BOOL CryptUnregisterOIDFunction(
    [in] DWORD dwEncodingType,
    [in] LPCSTR pszFuncName,
    [in] LPCSTR pszOID
);

BOOL CertDeleteCertificateFromStore(
    [in] PCCERT_CONTEXT pCertContext
);

BOOL CertSerializeCTLStoreElement(
    [in] PCCTL_CONTEXT pCtlContext,
    [in] DWORD dwFlags,
    [out] BYTE *pbElement,
    [in, out] DWORD *pcbElement
);

DWORD CertRDNValueToStrW(
    [in] DWORD dwValueType,
    [in] PCERT_RDN_VALUE_BLOB pValue,
    [out] LPWSTR psz,
    [in] DWORD csz
);

DWORD CertGetNameStringW(
    [in] PCCERT_CONTEXT pCertContext,
    [in] DWORD dwType,
    [in] DWORD dwFlags,
    [in] void *pvTypePara,
    [out] LPWSTR pszNameString,
    [in] DWORD cchNameString
);

BOOL CryptCreateAsyncHandle(
    DWORD dwFlags,
    PHCRYPTASYNC phAsync
);

BOOL CryptHashCertificate2(
    [in] LPCWSTR pwszCNGHashAlgid,
    [in] DWORD dwFlags,
    void *pvReserved,
    [in] const BYTE *pbEncoded,
    [in] DWORD cbEncoded,
    [out] BYTE *pbComputedHash,
    [in, out] DWORD *pcbComputedHash
);

LONG CertVerifyCRLTimeValidity(
    [in] LPFILETIME pTimeToVerify,
    [in] PCRL_INFO pCrlInfo
);

BOOL CryptMsgVerifyCountersignatureEncoded(
    [in] HCRYPTPROV_LEGACY hCryptProv,
    [in] DWORD dwEncodingType,
    [in] PBYTE pbSignerInfo,
    [in] DWORD cbSignerInfo,
    [in] PBYTE pbSignerInfoCountersignature,
    [in] DWORD cbSignerInfoCountersignature,
    [in] PCERT_INFO pciCountersigner
);

BOOL CryptRegisterOIDInfo(
    [in] PCCRYPT_OID_INFO pInfo,
    [in] DWORD dwFlags
);

BOOL CryptUninstallDefaultContext(
    [in] HCRYPTDEFAULTCONTEXT hDefaultContext,
    [in] DWORD dwFlags,
    [in] void *pvReserved
);

BOOL CertGetIntendedKeyUsage(
    [in] DWORD dwCertEncodingType,
    [in] PCERT_INFO pCertInfo,
    [out] BYTE *pbKeyUsage,
    [in] DWORD cbKeyUsage
);

BOOL CertIsValidCRLForCertificate(
    [in] PCCERT_CONTEXT pCert,
    [in] PCCRL_CONTEXT pCrl,
    [in] DWORD dwFlags,
    [in] void *pvReserved
);

PCCRYPT_OID_INFO CryptFindOIDInfo(
    [in] DWORD dwKeyType,
    [in] void *pvKey,
    [in] DWORD dwGroupId
);

BOOL CryptDecodeMessage(
    [in] DWORD dwMsgTypeFlags,
    [in] PCRYPT_DECRYPT_MESSAGE_PARA pDecryptPara,
    [in] PCRYPT_VERIFY_MESSAGE_PARA pVerifyPara,
    [in] DWORD dwSignerIndex,
    [in] const BYTE *pbEncodedBlob,
    [in] DWORD cbEncodedBlob,
    [in] DWORD dwPrevInnerContentType,
    [out, optional] DWORD *pdwMsgType,
    [out, optional] DWORD *pdwInnerContentType,
    [out, optional] BYTE *pbDecoded,
    [in, out, optional] DWORD *pcbDecoded,
    [out, optional] PCCERT_CONTEXT *ppXchgCert,
    [out, optional] PCCERT_CONTEXT *ppSignerCert
);

HCERTSTORE CertOpenStore(
    [in] LPCSTR lpszStoreProvider,
    [in] DWORD dwEncodingType,
    [in] HCRYPTPROV_LEGACY hCryptProv,
    [in] DWORD dwFlags,
    [in] const void *pvPara
);

BOOL CryptImportPublicKeyInfo(
    [in] HCRYPTPROV hCryptProv,
    [in] DWORD dwCertEncodingType,
    [in] PCERT_PUBLIC_KEY_INFO pInfo,
    [out] HCRYPTKEY *phKey
);

BOOL CryptImportPublicKeyInfoEx2(
    [in] DWORD dwCertEncodingType,
    [in] PCERT_PUBLIC_KEY_INFO pInfo,
    [in] DWORD dwFlags,
    [in] void *pvAuxInfo,
    [out] BCRYPT_KEY_HANDLE *phKey
);

BOOL CryptSetAsyncParam(
    HCRYPTASYNC hAsync,
    LPSTR pszParamOid,
    LPVOID pvParam,
    PFN_CRYPT_ASYNC_PARAM_FREE_FUNC pfnFree
);

BOOL CertSetCTLContextProperty(
    [in] PCCTL_CONTEXT pCtlContext,
    [in] DWORD dwPropId,
    [in] DWORD dwFlags,
    [in] const void *pvData
);

BOOL CryptInstallOIDFunctionAddress(
    [in] HMODULE hModule,
    [in] DWORD dwEncodingType,
    [in] LPCSTR pszFuncName,
    [in] DWORD cFuncEntry,
    [in] const CRYPT_OID_FUNC_ENTRY [] rgFuncEntry,
    [in] DWORD dwFlags
);

BOOL CertDeleteCTLFromStore(
    [in] PCCTL_CONTEXT pCtlContext
);

PCCTL_CONTEXT CertFindCTLInStore(
    [in] HCERTSTORE hCertStore,
    [in] DWORD dwMsgAndCertEncodingType,
    [in] DWORD dwFindFlags,
    [in] DWORD dwFindType,
    [in] const void *pvFindPara,
    [in] PCCTL_CONTEXT pPrevCtlContext
);

BOOL CryptHashMessage(
    [in] PCRYPT_HASH_MESSAGE_PARA pHashPara,
    [in] BOOL fDetachedHash,
    [in] DWORD cToBeHashed,
    [in] const BYTE * [] rgpbToBeHashed,
    [in] DWORD [] rgcbToBeHashed,
    [out] BYTE *pbHashedBlob,
    [in, out] DWORD *pcbHashedBlob,
    [out, optional] BYTE *pbComputedHash,
    [in, out, optional] DWORD *pcbComputedHash
);

BOOL CryptExportPKCS8(
    [in] HCRYPTPROV hCryptProv,
    [in] DWORD dwKeySpec,
    [in] LPSTR pszPrivateKeyObjId,
    [in] DWORD dwFlags,
    [in, optional] void *pvAuxInfo,
    [out, optional] BYTE *pbPrivateKeyBlob,
    [in, out] DWORD *pcbPrivateKeyBlob
);

PCCTL_CONTEXT CertEnumCTLsInStore(
    [in] HCERTSTORE hCertStore,
    [in] PCCTL_CONTEXT pPrevCtlContext
);

BOOL CertEnumSubjectInSortedCTL(
    [in] PCCTL_CONTEXT pCtlContext,
    [in, out] void **ppvNextSubject,
    [out] PCRYPT_DER_BLOB pSubjectIdentifier,
    [out] PCRYPT_DER_BLOB pEncodedAttributes
);

BOOL CryptMsgControl(
    [in] HCRYPTMSG hCryptMsg,
    [in] DWORD dwFlags,
    [in] DWORD dwCtrlType,
    [in] void const *pvCtrlPara
);

BOOL CryptCreateHash(
    [in] HCRYPTPROV hProv,
    [in] ALG_ID Algid,
    [in] HCRYPTKEY hKey,
    [in] DWORD dwFlags,
    [out] HCRYPTHASH *phHash
);

BOOL PFXExportCertStore(
    [in] HCERTSTORE hStore,
    [in, out] CRYPT_DATA_BLOB *pPFX,
    [in] LPCWSTR szPassword,
    [in] DWORD dwFlags
);

BOOL PFXExportCertStoreEx(
    [in] HCERTSTORE hStore,
    [in, out] CRYPT_DATA_BLOB *pPFX,
    [in] LPCWSTR szPassword,
    [in] void *pvPara,
    [in] DWORD dwFlags
);

BOOL CertCompareIntegerBlob(
    [in] PCRYPT_INTEGER_BLOB pInt1,
    [in] PCRYPT_INTEGER_BLOB pInt2
);

BOOL CryptGenKey(
    [in] HCRYPTPROV hProv,
    [in] ALG_ID Algid,
    [in] DWORD dwFlags,
    [out] HCRYPTKEY *phKey
);

BOOL CryptRetrieveObjectByUrlA(
    [in] LPCSTR pszUrl,
    [in] LPCSTR pszObjectOid,
    [in] DWORD dwRetrievalFlags,
    [in] DWORD dwTimeout,
    [out] LPVOID *ppvObject,
    [in] HCRYPTASYNC hAsyncRetrieve,
    [in, optional] PCRYPT_CREDENTIALS pCredentials,
    [in, optional] LPVOID pvVerify,
    [in] PCRYPT_RETRIEVE_AUX_INFO pAuxInfo
);

BOOL CertAddCTLContextToStore(
    [in] HCERTSTORE hCertStore,
    [in] PCCTL_CONTEXT pCtlContext,
    [in] DWORD dwAddDisposition,
    [out, optional] PCCTL_CONTEXT *ppStoreContext
);

BOOL CryptDestroyHash(
    [in] HCRYPTHASH hHash
);

BOOL CryptEnumProviderTypesW(
    [in] DWORD dwIndex,
    [in] DWORD *pdwReserved,
    [in] DWORD dwFlags,
    [out] DWORD *pdwProvType,
    [out] LPWSTR szTypeName,
    [in, out] DWORD *pcbTypeName
);

BOOL CertVerifyRevocation(
    [in] DWORD dwEncodingType,
    [in] DWORD dwRevType,
    [in] DWORD cContext,
    [in] PVOID [] rgpvContext,
    [in] DWORD dwFlags,
    [in, optional] PCERT_REVOCATION_PARA pRevPara,
    [in, out] PCERT_REVOCATION_STATUS pRevStatus
);

BOOL CertAddEncodedCertificateToSystemStoreW(
    [in] LPCWSTR szCertStoreName,
    [in] const BYTE *pbCertEncoded,
    [in] DWORD cbCertEncoded
);

BOOL CryptDestroyKey(
    [in] HCRYPTKEY hKey
);

DWORD CertOIDToAlgId(
    [in] LPCSTR pszObjId
);

BOOL CertAddEncodedCertificateToSystemStoreA(
    [in] LPCSTR szCertStoreName,
    [in] const BYTE *pbCertEncoded,
    [in] DWORD cbCertEncoded
);

BOOL CertStrToNameW(
    [in] DWORD dwCertEncodingType,
    [in] LPCWSTR pszX500,
    [in] DWORD dwStrType,
    [in, optional] void *pvReserved,
    [out] BYTE *pbEncoded,
    [in, out] DWORD *pcbEncoded,
    [out, optional] LPCWSTR *ppszError
);

BOOL CertAddEncodedCTLToStore(
    [in] HCERTSTORE hCertStore,
    [in] DWORD dwMsgAndCertEncodingType,
    [in] const BYTE *pbCtlEncoded,
    [in] DWORD cbCtlEncoded,
    [in] DWORD dwAddDisposition,
    [out, optional] PCCTL_CONTEXT *ppCtlContext
);

BOOL CryptHashSessionKey(
    [in] HCRYPTHASH hHash,
    [in] HCRYPTKEY hKey,
    [in] DWORD dwFlags
);

BOOL CertAddCRLLinkToStore(
    [in] HCERTSTORE hCertStore,
    [in] PCCRL_CONTEXT pCrlContext,
    [in] DWORD dwAddDisposition,
    [out, optional] PCCRL_CONTEXT *ppStoreContext
);

HCRYPTMSG CryptMsgOpenToDecode(
    [in] DWORD dwMsgEncodingType,
    [in] DWORD dwFlags,
    [in] DWORD dwMsgType,
    [in] HCRYPTPROV_LEGACY hCryptProv,
    [in] PCERT_INFO pRecipientInfo,
    [in, optional] PCMSG_STREAM_INFO pStreamInfo
);

BOOL CryptVerifyMessageHash(
    [in] PCRYPT_HASH_MESSAGE_PARA pHashPara,
    [in] BYTE *pbHashedBlob,
    [in] DWORD cbHashedBlob,
    [out] BYTE *pbToBeHashed,
    [in, out] DWORD *pcbToBeHashed,
    [out, optional] BYTE *pbComputedHash,
    [in, out, optional] DWORD *pcbComputedHash
);

PCERT_RDN_ATTR CertFindRDNAttr(
    [in] LPCSTR pszObjId,
    [in] PCERT_NAME_INFO pName
);

BOOL CryptExportPKCS8Ex(
    [in] CRYPT_PKCS8_EXPORT_PARAMS *psExportParams,
    [in] DWORD dwFlags,
    [in, optional] void *pvAuxInfo,
    [out, optional] BYTE *pbPrivateKeyBlob,
    [in, out] DWORD *pcbPrivateKeyBlob
);

BOOL CryptEnumProviderTypesA(
    [in] DWORD dwIndex,
    [in] DWORD *pdwReserved,
    [in] DWORD dwFlags,
    [out] DWORD *pdwProvType,
    [out] LPSTR szTypeName,
    [in, out] DWORD *pcbTypeName
);

BOOL CryptSetOIDFunctionValue(
    [in] DWORD dwEncodingType,
    [in] LPCSTR pszFuncName,
    [in] LPCSTR pszOID,
    [in] LPCWSTR pwszValueName,
    [in] DWORD dwValueType,
    [in] const BYTE *pbValueData,
    [in] DWORD cbValueData
);

BOOL CryptMsgCountersignEncoded(
    [in] DWORD dwEncodingType,
    [in] PBYTE pbSignerInfo,
    [in] DWORD cbSignerInfo,
    [in] DWORD cCountersigners,
    [in] PCMSG_SIGNER_ENCODE_INFO rgCountersigners,
    [out] PBYTE pbCountersignature,
    [in, out] PDWORD pcbCountersignature
);

BOOL CryptSetKeyIdentifierProperty(
    [in] const CRYPT_HASH_BLOB *pKeyIdentifier,
    [in] DWORD dwPropId,
    [in] DWORD dwFlags,
    [in] LPCWSTR pwszComputerName,
    [in] void *pvReserved,
    [out] const void *pvData
);

BOOL CryptMsgUpdate(
    [in] HCRYPTMSG hCryptMsg,
    [in] const BYTE *pbData,
    [in] DWORD cbData,
    [in] BOOL fFinal
);

void CertAddRefServerOcspResponse(
    [in] HCERT_SERVER_OCSP_RESPONSE hServerOcspResponse
);

DWORD CertEnumCertificateContextProperties(
    [in] PCCERT_CONTEXT pCertContext,
    [in] DWORD dwPropId
);

BOOL CertAddEncodedCertificateToStore(
    [in] HCERTSTORE hCertStore,
    [in] DWORD dwCertEncodingType,
    [in] const BYTE *pbCertEncoded,
    [in] DWORD cbCertEncoded,
    [in] DWORD dwAddDisposition,
    [out, optional] PCCERT_CONTEXT *ppCertContext
);

BOOL CertSetCertificateContextPropertiesFromCTLEntry(
    [in] PCCERT_CONTEXT pCertContext,
    [in] PCTL_ENTRY pCtlEntry,
    [in] DWORD dwFlags
);

BOOL CertFreeCRLContext(
    [in] PCCRL_CONTEXT pCrlContext
);

BOOL CryptGetOIDFunctionAddress(
    [in] HCRYPTOIDFUNCSET hFuncSet,
    [in] DWORD dwEncodingType,
    [in] LPCSTR pszOID,
    [in] DWORD dwFlags,
    [out] void **ppvFuncAddr,
    [out] HCRYPTOIDFUNCADDR *phFuncAddr
);

BOOL CertGetCertificateChain(
    [in, optional] HCERTCHAINENGINE hChainEngine,
    [in] PCCERT_CONTEXT pCertContext,
    [in, optional] LPFILETIME pTime,
    [in] HCERTSTORE hAdditionalStore,
    [in] PCERT_CHAIN_PARA pChainPara,
    [in] DWORD dwFlags,
    [in] LPVOID pvReserved,
    [out] PCCERT_CHAIN_CONTEXT *ppChainContext
);

BOOL CertVerifyValidityNesting(
    [in] PCERT_INFO pSubjectInfo,
    [in] PCERT_INFO pIssuerInfo
);

BOOL CryptSetProviderW(
    [in] LPCWSTR pszProvName,
    [in] DWORD dwProvType
);

BOOL CryptVerifyCertificateSignatureEx(
    [in] HCRYPTPROV_LEGACY hCryptProv,
    [in] DWORD dwCertEncodingType,
    [in] DWORD dwSubjectType,
    [in] void *pvSubject,
    [in] DWORD dwIssuerType,
    [in] void *pvIssuer,
    [in] DWORD dwFlags,
    [in, out, optional] void *pvExtra
);

BOOL CertComparePublicKeyInfo(
    [in] DWORD dwCertEncodingType,
    [in] PCERT_PUBLIC_KEY_INFO pPublicKey1,
    [in] PCERT_PUBLIC_KEY_INFO pPublicKey2
);

BOOL CryptVerifyMessageSignature(
    [in] PCRYPT_VERIFY_MESSAGE_PARA pVerifyPara,
    [in] DWORD dwSignerIndex,
    [in] const BYTE *pbSignedBlob,
    [in] DWORD cbSignedBlob,
    [out] BYTE *pbDecoded,
    [in, out] DWORD *pcbDecoded,
    [out, optional] PCCERT_CONTEXT *ppSignerCert
);

PCCERT_CHAIN_CONTEXT CertDuplicateCertificateChain(
    [in] PCCERT_CHAIN_CONTEXT pChainContext
);

void CertFreeCertificateChainList(
    [in] PCCERT_CHAIN_CONTEXT *prgpSelection
);

BOOL CryptVerifyTimeStampSignature(
    [in] const BYTE *pbTSContentInfo,
    DWORD cbTSContentInfo,
    [in, optional] const BYTE *pbData,
    DWORD cbData,
    [in, optional] HCERTSTORE hAdditionalStore,
    [out] PCRYPT_TIMESTAMP_CONTEXT *ppTsContext,
    [out, optional] PCCERT_CONTEXT *ppTsSigner,
    [out, optional] HCERTSTORE *phStore
);

BOOL CryptVerifyCertificateSignature(
    [in] HCRYPTPROV_LEGACY hCryptProv,
    [in] DWORD dwCertEncodingType,
    [in] const BYTE *pbEncoded,
    [in] DWORD cbEncoded,
    [in] PCERT_PUBLIC_KEY_INFO pPublicKey
);

BOOL CryptAcquireCertificatePrivateKey(
    [in] PCCERT_CONTEXT pCert,
    [in] DWORD dwFlags,
    [in, optional] void *pvParameters,
    [out] HCRYPTPROV_OR_NCRYPT_KEY_HANDLE *phCryptProvOrNCryptKey,
    [out] DWORD *pdwKeySpec,
    [out] BOOL *pfCallerFreeProvOrNCryptKey
);

BOOL CertCloseStore(
    [in] HCERTSTORE hCertStore,
    [in] DWORD dwFlags
);

BOOL CertResyncCertificateChainEngine(
    [in, optional] HCERTCHAINENGINE hChainEngine
);

BOOL CertAddCRLContextToStore(
    [in] HCERTSTORE hCertStore,
    [in] PCCRL_CONTEXT pCrlContext,
    [in] DWORD dwAddDisposition,
    [out, optional] PCCRL_CONTEXT *ppStoreContext
);

BOOL CertSerializeCertificateStoreElement(
    [in] PCCERT_CONTEXT pCertContext,
    [in] DWORD dwFlags,
    [out] BYTE *pbElement,
    [in, out] DWORD *pcbElement
);

BOOL CryptGetKeyParam(
    [in] HCRYPTKEY hKey,
    [in] DWORD dwParam,
    [out] BYTE *pbData,
    [in, out] DWORD *pdwDataLen,
    [in] DWORD dwFlags
);

BOOL CryptHashData(
    [in] HCRYPTHASH hHash,
    [in] const BYTE *pbData,
    [in] DWORD dwDataLen,
    [in] DWORD dwFlags
);

BOOL CertSelectCertificateChains(
    [in, optional] LPCGUID pSelectionContext,
    [in] DWORD dwFlags,
    [in, optional] PCCERT_SELECT_CHAIN_PARA pChainParameters,
    [in] DWORD cCriteria,
    [in, optional] PCCERT_SELECT_CRITERIA rgpCriteria,
    [in] HCERTSTORE hStore,
    [out] PDWORD pcSelection,
    [out] PCCERT_CHAIN_CONTEXT **pprgpSelection
);

BOOL CertSetCRLContextProperty(
    [in] PCCRL_CONTEXT pCrlContext,
    [in] DWORD dwPropId,
    [in] DWORD dwFlags,
    [in] const void *pvData
);

DWORD CertGetPublicKeyLength(
    [in] DWORD dwCertEncodingType,
    [in] PCERT_PUBLIC_KEY_INFO pPublicKey
);

BOOL CryptRetrieveTimeStamp(
    [in] LPCWSTR wszUrl,
    DWORD dwRetrievalFlags,
    DWORD dwTimeout,
    [in] LPCSTR pszHashId,
    [in, optional] const CRYPT_TIMESTAMP_PARA *pPara,
    [in] const BYTE *pbData,
    DWORD cbData,
    [out] PCRYPT_TIMESTAMP_CONTEXT *ppTsContext,
    [out, optional] PCCERT_CONTEXT *ppTsSigner,
    [out, optional] HCERTSTORE *phStore
);

BOOL GetEncSChannel(
    [out] BYTE **pData,
    [out] DWORD *dwDecSize
);

PCCERT_CONTEXT CertEnumCertificatesInStore(
    [in] HCERTSTORE hCertStore,
    [in] PCCERT_CONTEXT pPrevCertContext
);

BOOL CertAddSerializedElementToStore(
    [in] HCERTSTORE hCertStore,
    [in] const BYTE *pbElement,
    [in] DWORD cbElement,
    [in] DWORD dwAddDisposition,
    [in] DWORD dwFlags,
    [in] DWORD dwContextTypeFlags,
    [out] DWORD *pdwContextType,
    [out] const void **ppvContext
);

HCERTSTORE CertOpenSystemStoreW(
    [in] HCRYPTPROV_LEGACY hProv,
    [in] LPCWSTR szSubsystemProtocol
);

PCCRL_CONTEXT CertEnumCRLsInStore(
    [in] HCERTSTORE hCertStore,
    [in] PCCRL_CONTEXT pPrevCrlContext
);

void CertAddRefServerOcspResponseContext(
    [in] PCCERT_SERVER_OCSP_RESPONSE_CONTEXT pServerOcspResponseContext
);

BOOL CryptExportKey(
    [in] HCRYPTKEY hKey,
    [in] HCRYPTKEY hExpKey,
    [in] DWORD dwBlobType,
    [in] DWORD dwFlags,
    [out] BYTE *pbData,
    [in, out] DWORD *pdwDataLen
);

BOOL CertCompareCertificate(
    [in] DWORD dwCertEncodingType,
    [in] PCERT_INFO pCertId1,
    [in] PCERT_INFO pCertId2
);

PCCRL_CONTEXT CertCreateCRLContext(
    [in] DWORD dwCertEncodingType,
    [in] const BYTE *pbCrlEncoded,
    [in] DWORD cbCrlEncoded
);

void CryptMemFree(
    [in] LPVOID pv
);

BOOL CryptMsgSignCTL(
    [in] DWORD dwMsgEncodingType,
    [in] BYTE *pbCtlContent,
    [in] DWORD cbCtlContent,
    [in] PCMSG_SIGNED_ENCODE_INFO pSignInfo,
    [in] DWORD dwFlags,
    [out] BYTE *pbEncoded,
    [in, out] DWORD *pcbEncoded
);

BOOL CertStrToNameA(
    [in] DWORD dwCertEncodingType,
    [in] LPCSTR pszX500,
    [in] DWORD dwStrType,
    [in, optional] void *pvReserved,
    [out] BYTE *pbEncoded,
    [in, out] DWORD *pcbEncoded,
    [out, optional] LPCSTR *ppszError
);

BOOL CertAddCTLLinkToStore(
    [in] HCERTSTORE hCertStore,
    [in] PCCTL_CONTEXT pCtlContext,
    [in] DWORD dwAddDisposition,
    [out, optional] PCCTL_CONTEXT *ppStoreContext
);

HCRYPTOIDFUNCSET CryptInitOIDFunctionSet(
    [in] LPCSTR pszFuncName,
    [in] DWORD dwFlags
);

BOOL CryptDecryptAndVerifyMessageSignature(
    [in] PCRYPT_DECRYPT_MESSAGE_PARA pDecryptPara,
    [in] PCRYPT_VERIFY_MESSAGE_PARA pVerifyPara,
    [in] DWORD dwSignerIndex,
    [in] const BYTE *pbEncryptedBlob,
    [in] DWORD cbEncryptedBlob,
    [out, optional] BYTE *pbDecrypted,
    [in, out, optional] DWORD *pcbDecrypted,
    [out, optional] PCCERT_CONTEXT *ppXchgCert,
    [out, optional] PCCERT_CONTEXT *ppSignerCert
);

PCCERT_SERVER_OCSP_RESPONSE_CONTEXT CertGetServerOcspResponseContext(
    [in] HCERT_SERVER_OCSP_RESPONSE hServerOcspResponse,
    [in] DWORD dwFlags,
    LPVOID pvReserved
);

HCERTSTORE CryptGetMessageCertificates(
    [in] DWORD dwMsgAndCertEncodingType,
    [in] HCRYPTPROV_LEGACY hCryptProv,
    [in] DWORD dwFlags,
    [in] const BYTE *pbSignedBlob,
    [in] DWORD cbSignedBlob
);

BOOL CryptGetDefaultProviderW(
    [in] DWORD dwProvType,
    [in] DWORD *pdwReserved,
    [in] DWORD dwFlags,
    [out] LPWSTR pszProvName,
    [in, out] DWORD *pcbProvName
);

BOOL CryptRetrieveObjectByUrlW(
    [in] LPCWSTR pszUrl,
    [in] LPCSTR pszObjectOid,
    [in] DWORD dwRetrievalFlags,
    [in] DWORD dwTimeout,
    [out] LPVOID *ppvObject,
    [in] HCRYPTASYNC hAsyncRetrieve,
    [in, optional] PCRYPT_CREDENTIALS pCredentials,
    [in, optional] LPVOID pvVerify,
    [in] PCRYPT_RETRIEVE_AUX_INFO pAuxInfo
);

BOOL CertSetEnhancedKeyUsage(
    [in] PCCERT_CONTEXT pCertContext,
    [in] PCERT_ENHKEY_USAGE pUsage
);

PCCTL_CONTEXT CertDuplicateCTLContext(
    [in] PCCTL_CONTEXT pCtlContext
);

LPCSTR CertAlgIdToOID(
    [in] DWORD dwAlgId
);

BOOL CryptReleaseContext(
    [in] HCRYPTPROV hProv,
    [in] DWORD dwFlags
);

BOOL CryptEncrypt(
    [in] HCRYPTKEY hKey,
    [in] HCRYPTHASH hHash,
    [in] BOOL Final,
    [in] DWORD dwFlags,
    [in, out] BYTE *pbData,
    [in, out] DWORD *pdwDataLen,
    [in] DWORD dwBufLen
);

BOOL CertDeleteCRLFromStore(
    [in] PCCRL_CONTEXT pCrlContext
);

BOOL CryptCloseAsyncHandle(
    HCRYPTASYNC hAsync
);

DWORD CryptMsgCalculateEncodedLength(
    [in] DWORD dwMsgEncodingType,
    [in] DWORD dwFlags,
    [in] DWORD dwMsgType,
    [in] void const *pvMsgEncodeInfo,
    [in, optional] LPSTR pszInnerContentObjID,
    [in] DWORD cbData
);

BOOL CryptUnregisterDefaultOIDFunction(
    [in] DWORD dwEncodingType,
    [in] LPCSTR pszFuncName,
    [in] LPCWSTR pwszDll
);

BOOL CertEnumPhysicalStore(
    [in] const void *pvSystemStore,
    [in] DWORD dwFlags,
    [in] void *pvArg,
    [in] PFN_CERT_ENUM_PHYSICAL_STORE pfnEnum
);

HCERTSTORE CertOpenSystemStoreA(
    [in] HCRYPTPROV_LEGACY hProv,
    [in] LPCSTR szSubsystemProtocol
);

PCCERT_CONTEXT CertFindCertificateInStore(
    [in] HCERTSTORE hCertStore,
    [in] DWORD dwCertEncodingType,
    [in] DWORD dwFindFlags,
    [in] DWORD dwFindType,
    [in] const void *pvFindPara,
    [in] PCCERT_CONTEXT pPrevCertContext
);

BOOL CryptDecryptMessage(
    [in] PCRYPT_DECRYPT_MESSAGE_PARA pDecryptPara,
    [in] const BYTE *pbEncryptedBlob,
    [in] DWORD cbEncryptedBlob,
    [out, optional] BYTE *pbDecrypted,
    [in, out, optional] DWORD *pcbDecrypted,
    [out, optional] PCCERT_CONTEXT *ppXchgCert
);

BOOL CertRemoveEnhancedKeyUsageIdentifier(
    [in] PCCERT_CONTEXT pCertContext,
    [in] LPCSTR pszUsageIdentifier
);

BOOL CertGetValidUsages(
    [in] DWORD cCerts,
    [in] PCCERT_CONTEXT *rghCerts,
    [out] int *cNumOIDs,
    [out] LPSTR *rghOIDs,
    [in, out] DWORD *pcbOIDs
);

BOOL CertUnregisterPhysicalStore(
    [in] const void *pvSystemStore,
    [in] DWORD dwFlags,
    [in] LPCWSTR pwszStoreName
);

PCCERT_CONTEXT CertCreateSelfSignCertificate(
    [in, optional] HCRYPTPROV_OR_NCRYPT_KEY_HANDLE hCryptProvOrNCryptKey,
    [in] PCERT_NAME_BLOB pSubjectIssuerBlob,
    [in] DWORD dwFlags,
    [in, optional] PCRYPT_KEY_PROV_INFO pKeyProvInfo,
    [in, optional] PCRYPT_ALGORITHM_IDENTIFIER pSignatureAlgorithm,
    [in, optional] PSYSTEMTIME pStartTime,
    [in, optional] PSYSTEMTIME pEndTime,
    [optional] PCERT_EXTENSIONS pExtensions
);

BOOL CryptBinaryToStringA(
    [in] const BYTE *pbBinary,
    [in] DWORD cbBinary,
    [in] DWORD dwFlags,
    [out, optional] LPSTR pszString,
    [in, out] DWORD *pcchString
);

BOOL CryptVerifyDetachedMessageHash(
    [in] PCRYPT_HASH_MESSAGE_PARA pHashPara,
    [in] BYTE *pbDetachedHashBlob,
    [in] DWORD cbDetachedHashBlob,
    [in] DWORD cToBeHashed,
    [in] const BYTE * [] rgpbToBeHashed,
    [in] DWORD [] rgcbToBeHashed,
    [out] BYTE *pbComputedHash,
    [in, out] DWORD *pcbComputedHash
);

BOOL CryptDecodeObjectEx(
    [in] DWORD dwCertEncodingType,
    [in] LPCSTR lpszStructType,
    [in] const BYTE *pbEncoded,
    [in] DWORD cbEncoded,
    [in] DWORD dwFlags,
    [in] PCRYPT_DECODE_PARA pDecodePara,
    [out] void *pvStructInfo,
    [in, out] DWORD *pcbStructInfo
);

LPCWSTR CryptFindLocalizedName(
    [in] LPCWSTR pwszCryptName
);

BOOL CryptRegisterOIDFunction(
    [in] DWORD dwEncodingType,
    [in] LPCSTR pszFuncName,
    [in] LPCSTR pszOID,
    [in] LPCWSTR pwszDll,
    [in] LPCSTR pszOverrideFuncName
);

void CertRemoveStoreFromCollection(
    [in] HCERTSTORE hCollectionStore,
    [in] HCERTSTORE hSiblingStore
);

BOOL CryptAcquireContextW(
    [out] HCRYPTPROV *phProv,
    [in] LPCWSTR szContainer,
    [in] LPCWSTR szProvider,
    [in] DWORD dwProvType,
    [in] DWORD dwFlags
);

BOOL CryptImportPKCS8(
    [in] CRYPT_PKCS8_IMPORT_PARAMS sPrivateKeyAndParams,
    [in] DWORD dwFlags,
    [out, optional] HCRYPTPROV *phCryptProv,
    [in, optional] void *pvAuxInfo
);

BOOL CryptDuplicateHash(
    [in] HCRYPTHASH hHash,
    [in] DWORD *pdwReserved,
    [in] DWORD dwFlags,
    [out] HCRYPTHASH *phHash
);

BOOL CryptDeriveKey(
    [in] HCRYPTPROV hProv,
    [in] ALG_ID Algid,
    [in] HCRYPTHASH hBaseData,
    [in] DWORD dwFlags,
    [in, out] HCRYPTKEY *phKey
);

HCERTSTORE CertDuplicateStore(
    [in] HCERTSTORE hCertStore
);

BOOL CryptGetTimeValidObject(
    [in] LPCSTR pszTimeValidOid,
    [in] LPVOID pvPara,
    [in] PCCERT_CONTEXT pIssuer,
    [in, optional] LPFILETIME pftValidFor,
    [in] DWORD dwFlags,
    [in] DWORD dwTimeout,
    [out, optional] LPVOID *ppvObject,
    [in, optional] PCRYPT_CREDENTIALS pCredentials,
    [in, out, optional] PCRYPT_GET_TIME_VALID_OBJECT_EXTRA_INFO pExtraInfo
);

BOOL CryptHashToBeSigned(
    [in] HCRYPTPROV_LEGACY hCryptProv,
    [in] DWORD dwCertEncodingType,
    [in] const BYTE *pbEncoded,
    [in] DWORD cbEncoded,
    [out] BYTE *pbComputedHash,
    [in, out] DWORD *pcbComputedHash
);

BOOL CryptStringToBinaryA(
    [in] LPCSTR pszString,
    [in] DWORD cchString,
    [in] DWORD dwFlags,
    [in] BYTE *pbBinary,
    [in, out] DWORD *pcbBinary,
    [out] DWORD *pdwSkip,
    [out] DWORD *pdwFlags
);

BOOL CryptContextAddRef(
    [in] HCRYPTPROV hProv,
    [in] DWORD *pdwReserved,
    [in] DWORD dwFlags
);

BOOL CryptCreateKeyIdentifierFromCSP(
    [in] DWORD dwCertEncodingType,
    [in] LPCSTR pszPubKeyOID,
    [in] const PUBLICKEYSTRUC *pPubKeyStruc,
    [in] DWORD cbPubKeyStruc,
    [in] DWORD dwFlags,
    [in] void *pvReserved,
    [out] BYTE *pbHash,
    [in, out] DWORD *pcbHash
);

BOOL CertCompareCertificateName(
    [in] DWORD dwCertEncodingType,
    [in] PCERT_NAME_BLOB pCertName1,
    [in] PCERT_NAME_BLOB pCertName2
);

BOOL CertVerifyCertificateChainPolicy(
    [in] LPCSTR pszPolicyOID,
    [in] PCCERT_CHAIN_CONTEXT pChainContext,
    [in] PCERT_CHAIN_POLICY_PARA pPolicyPara,
    [in, out] PCERT_CHAIN_POLICY_STATUS pPolicyStatus
);

BOOL CryptImportKey(
    [in] HCRYPTPROV hProv,
    [in] const BYTE *pbData,
    [in] DWORD dwDataLen,
    [in] HCRYPTKEY hPubKey,
    [in] DWORD dwFlags,
    [out] HCRYPTKEY *phKey
);

PCCRL_CONTEXT CertGetCRLFromStore(
    [in] HCERTSTORE hCertStore,
    [in, optional] PCCERT_CONTEXT pIssuerContext,
    [in] PCCRL_CONTEXT pPrevCrlContext,
    [in, out] DWORD *pdwFlags
);

BOOL CryptEnumOIDFunction(
    [in] DWORD dwEncodingType,
    [in] LPCSTR pszFuncName,
    [in] LPCSTR pszOID,
    [in] DWORD dwFlags,
    [in] void *pvArg,
    [in] PFN_CRYPT_ENUM_OID_FUNC pfnEnumOIDFunc
);

void CertFreeCertificateChainEngine(
    [in] HCERTCHAINENGINE hChainEngine
);

BOOL CryptAcquireContextA(
    [out] HCRYPTPROV *phProv,
    [in] LPCSTR szContainer,
    [in] LPCSTR szProvider,
    [in] DWORD dwProvType,
    [in] DWORD dwFlags
);

PCCERT_CONTEXT CertGetIssuerCertificateFromStore(
    [in] HCERTSTORE hCertStore,
    [in] PCCERT_CONTEXT pSubjectContext,
    [in, optional] PCCERT_CONTEXT pPrevIssuerContext,
    [in, out] DWORD *pdwFlags
);

