WINPATHCCHAPI HRESULT PathCchAddBackslash(
    [in, out] PWSTR pszPath,
    [in] size_t cchPath
);

WINPATHCCHAPI HRESULT PathCchCombineEx(
    [out] PWSTR pszPathOut,
    [in] size_t cchPathOut,
    [in, optional] PCWSTR pszPathIn,
    [in, optional] PCWSTR pszMore,
    [in] ULONG dwFlags
);

WINPATHCCHAPI HRESULT PathCchRenameExtension(
    [in, out] PWSTR pszPath,
    [in] size_t cchPath,
    [in] PCWSTR pszExt
);

WINPATHCCHAPI HRESULT PathCchAppend(
    [in, out] PWSTR pszPath,
    [in] size_t cchPath,
    [in, optional] PCWSTR pszMore
);

WINPATHCCHAPI HRESULT PathCchRemoveFileSpec(
    [in, out] PWSTR pszPath,
    [in] size_t cchPath
);

WINPATHCCHAPI HRESULT PathCchStripPrefix(
    [in, out] PWSTR pszPath,
    [in] size_t cchPath
);

WINPATHCCHAPI HRESULT PathCchSkipRoot(
    [in] PCWSTR pszPath,
    [out] PCWSTR *ppszRootEnd
);

WINPATHCCHAPI HRESULT PathCchCombine(
    [out] PWSTR pszPathOut,
    [in] size_t cchPathOut,
    [in, optional] PCWSTR pszPathIn,
    [in, optional] PCWSTR pszMore
);

WINPATHCCHAPI HRESULT PathCchCanonicalize(
    [out] PWSTR pszPathOut,
    [in] size_t cchPathOut,
    [in] PCWSTR pszPathIn
);

WINPATHCCHAPI HRESULT PathCchStripToRoot(
    [in, out] PWSTR pszPath,
    [in] size_t cchPath
);

WINPATHCCHAPI HRESULT PathCchRemoveBackslash(
    [in, out] PWSTR pszPath,
    [in] size_t cchPath
);

WINPATHCCHAPI BOOL PathCchIsRoot(
    [in, optional] PCWSTR pszPath
);

WINPATHCCHAPI HRESULT PathCchAppendEx(
    [in, out] PWSTR pszPath,
    [in] size_t cchPath,
    [in, optional] PCWSTR pszMore,
    [in] ULONG dwFlags
);

WINPATHCCHAPI HRESULT PathAllocCanonicalize(
    [in] PCWSTR pszPathIn,
    [in] ULONG dwFlags,
    [out] PWSTR *ppszPathOut
);

WINPATHCCHAPI HRESULT PathCchCanonicalizeEx(
    [out] PWSTR pszPathOut,
    [in] size_t cchPathOut,
    [in] PCWSTR pszPathIn,
    [in] ULONG dwFlags
);

WINPATHCCHAPI BOOL PathIsUNCEx(
    [in] PCWSTR pszPath,
    [out, optional] PCWSTR *ppszServer
);

WINPATHCCHAPI HRESULT PathCchRemoveExtension(
    [in, out] PWSTR pszPath,
    [in] size_t cchPath
);

WINPATHCCHAPI HRESULT PathCchAddBackslashEx(
    [in, out] PWSTR pszPath,
    [in] size_t cchPath,
    [out, optional] PWSTR *ppszEnd,
    [out, optional] size_t *pcchRemaining
);

WINPATHCCHAPI HRESULT PathCchFindExtension(
    [in] PCWSTR pszPath,
    [in] size_t cchPath,
    [out] PCWSTR *ppszExt
);

WINPATHCCHAPI HRESULT PathCchAddExtension(
    [in, out] PWSTR pszPath,
    [in] size_t cchPath,
    [in] PCWSTR pszExt
);

WINPATHCCHAPI HRESULT PathCchRemoveBackslashEx(
    [in, out] PWSTR pszPath,
    [in] size_t cchPath,
    [out, optional] PWSTR *ppszEnd,
    [out, optional] size_t *pcchRemaining
);

WINPATHCCHAPI HRESULT PathAllocCombine(
    [in] PCWSTR pszPathIn,
    [in] PCWSTR pszMore,
    [in] ULONG dwFlags,
    [out] PWSTR *ppszPathOut
);

