SHSTDAPI SHCreateAssociationRegistration(
    [in] REFIID riid,
    [out] void **ppv
);

HRESULT SHLoadLibraryFromParsingName(
    [in] PCWSTR pszParsingName,
    [in] DWORD grfMode,
    [in] REFIID riid,
    [out] void **ppv
);

HRESULT SHCreateLibrary(
    [in] REFIID riid,
    [out] void **ppv
);

SHSTDAPI SHCreateItemFromParsingName(
    [in] PCWSTR pszPath,
    [in, optional] IBindCtx *pbc,
    [in] REFIID riid,
    [out] void **ppv
);

SHSTDAPI SHGetNameFromIDList(
    [in] PCIDLIST_ABSOLUTE pidl,
    [in] SIGDN sigdnName,
    [out] PWSTR *ppszName
);

SHSTDAPI SHCreateItemWithParent(
    [in] PCIDLIST_ABSOLUTE pidlParent,
    [in] IShellFolder *psfParent,
    [in] PCUITEMID_CHILD pidl,
    [in] REFIID riid,
    [out] void **ppvItem
);

SHSTDAPI SHAssocEnumHandlersForProtocolByApplication(
    [in] PCWSTR protocol,
    [in] REFIID riid,
    [out] void **enumHandlers
);

PIDLIST_ABSOLUTE SHSimpleIDListFromPath(
    [in] PCWSTR pszPath
);

SHSTDAPI SHGetIDListFromObject(
    [in] IUnknown *punk,
    [out] PIDLIST_ABSOLUTE *ppidl
);

SHSTDAPI SHGetTemporaryPropertyForItem(
    [in] IShellItem *psi,
    REFPROPERTYKEY propkey,
    [out] PROPVARIANT *ppropvar
);

HRESULT SHAddFolderPathToLibrary(
    [in] IShellLibrary *plib,
    [in] PCWSTR pszFolderPath
);

SHSTDAPI SHGetPropertyStoreFromParsingName(
    [in] PCWSTR pszPath,
    [in, optional] IBindCtx *pbc,
    [in] GETPROPERTYSTOREFLAGS flags,
    [in] REFIID riid,
    [out] void **ppv
);

HRESULT SHGetItemFromDataObject(
    [in] IDataObject *pdtobj,
    [in] DATAOBJ_GET_ITEM_FLAGS dwFlags,
    [in] REFIID riid,
    [out] void **ppv
);

SHSTDAPI SetCurrentProcessExplicitAppUserModelID(
    [in] PCWSTR AppID
);

SHSTDAPI SHCreateShellItemArrayFromDataObject(
    [in] IDataObject *pdo,
    [in] REFIID riid,
    [out] void **ppv
);

void FreeIDListArray(
    [in] PIDLIST_RELATIVE *ppidls,
    UINT cItems
);

void SetContractDelegateWindow(
    [in] HWND hwndSource,
    [in, optional] HWND hwndDelegate
);

SHSTDAPI SHGetItemFromObject(
    [in] IUnknown *punk,
    [in] REFIID riid,
    [out] void **ppv
);

SHSTDAPI SHCreateItemFromIDList(
    [in] PCIDLIST_ABSOLUTE pidl,
    [in] REFIID riid,
    [out] void **ppv
);

SHSTDAPI SHCreateItemInKnownFolder(
    [in] REFKNOWNFOLDERID kfid,
    DWORD dwKFFlags,
    [in, optional] PCWSTR pszItem,
    [in] REFIID riid,
    [out] void **ppv
);

SHSTDAPI SHCreateShellItemArrayFromIDLists(
    [in] UINT cidl,
    [in] PCIDLIST_ABSOLUTE_ARRAY rgpidl,
    [out] IShellItemArray **ppsiItemArray
);

SHSTDAPI SHCreateItemFromRelativeName(
    [in] IShellItem *psiParent,
    [in] PCWSTR pszName,
    [in] IBindCtx *pbc,
    [in] REFIID riid,
    [out] void **ppv
);

HRESULT SHCreateDefaultExtractIcon(
    REFIID riid,
    [out] void **ppv
);

SHSTDAPI SHSetTemporaryPropertyForItem(
    [in] IShellItem *psi,
    [in] REFPROPERTYKEY propkey,
    [in] REFPROPVARIANT propvar
);

HRESULT SHShowManageLibraryUI(
    [in] IShellItem *psiLibrary,
    [in, optional] HWND hwndOwner,
    [in, optional] LPCWSTR pszTitle,
    [in, optional] LPCWSTR pszInstruction,
    [in] LIBRARYMANAGEDIALOGOPTIONS lmdOptions
);

HRESULT SHLoadLibraryFromItem(
    [in] IShellItem *psiLibrary,
    [in] DWORD grfMode,
    [in] REFIID riid,
    [out] void **ppv
);

SHSTDAPI SHAssocEnumHandlers(
    [in] PCWSTR pszExtra,
    [in] ASSOC_FILTER afFilter,
    [out] IEnumAssocHandlers **ppEnumHandler
);

void FreeIDListArrayFull(
    [in] PIDLIST_ABSOLUTE *ppidls,
    UINT cItems
);

SHSTDAPI SHGetPropertyStoreFromIDList(
    [in] PCIDLIST_ABSOLUTE pidl,
    [in] GETPROPERTYSTOREFLAGS flags,
    [in] REFIID riid,
    [out] void **ppv
);

HRESULT SHSaveLibraryInFolderPath(
    [in] IShellLibrary *plib,
    [in] PCWSTR pszFolderPath,
    [in] PCWSTR pszLibraryName,
    [in] LIBRARYSAVEFLAGS lsf,
    [out, optional] PWSTR *ppszSavedToPath
);

HRESULT SHLoadLibraryFromKnownFolder(
    [in] REFKNOWNFOLDERID kfidLibrary,
    [in] DWORD grfMode,
    [in] REFIID riid,
    [out] void **ppv
);

HRESULT SHResolveLibrary(
    [in] IShellItem *psiLibrary
);

void FreeIDListArrayChild(
    [in] PITEMID_CHILD *ppidls,
    UINT cItems
);

void FreeKnownFolderDefinitionFields(
    [in] KNOWNFOLDER_DEFINITION *pKFD
);

SHSTDAPI GetCurrentProcessExplicitAppUserModelID(
    [out] PWSTR *AppID
);

HRESULT SHRemoveFolderPathFromLibrary(
    [in] IShellLibrary *plib,
    [in] PCWSTR pszFolderPath
);

SHSTDAPI SHCreateShellItemArrayFromShellItem(
    [in] IShellItem *psi,
    [in] REFIID riid,
    [out] void **ppv
);

SHSTDAPI SHCreateShellItemArray(
    [in] PCIDLIST_ABSOLUTE pidlParent,
    [in] IShellFolder *psf,
    [in] UINT cidl,
    [in] PCUITEMID_CHILD_ARRAY ppidl,
    [out] IShellItemArray **ppsiItemArray
);

