BOOL SslEmptyCacheA(
    [in] LPSTR pszTargetName,
    [in] DWORD dwFlags
);

BOOL SslCrackCertificate(
    [in] PUCHAR pbCertificate,
    [in] DWORD cbCertificate,
    [in] DWORD dwFlags,
    [out] PX509Certificate *ppCertificate
);

void SslFreeCertificate(
    [in] PX509Certificate pCertificate
);

BOOL SslEmptyCacheW(
    [in] LPWSTR pszTargetName,
    [in] DWORD dwFlags
);

SECURITY_STATUS SslGetServerIdentity(
    [in] PBYTE ClientHello,
    [in] DWORD ClientHelloSize,
    [out] PBYTE *ServerIdentity,
    [out] PDWORD ServerIdentitySize,
    [in] DWORD Flags
);

