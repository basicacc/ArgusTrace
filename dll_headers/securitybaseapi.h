BOOL ImpersonateLoggedOnUser(
    [in] HANDLE hToken
);

BOOL AccessCheckAndAuditAlarmW(
    [in] LPCWSTR SubsystemName,
    [in, optional] LPVOID HandleId,
    [in] LPWSTR ObjectTypeName,
    [in, optional] LPWSTR ObjectName,
    [in] PSECURITY_DESCRIPTOR SecurityDescriptor,
    [in] DWORD DesiredAccess,
    [in] PGENERIC_MAPPING GenericMapping,
    [in] BOOL ObjectCreation,
    [out] LPDWORD GrantedAccess,
    [out] LPBOOL AccessStatus,
    [out] LPBOOL pfGenerateOnClose
);

BOOL AddAce(
    [in, out] PACL pAcl,
    [in] DWORD dwAceRevision,
    [in] DWORD dwStartingAceIndex,
    [in] LPVOID pAceList,
    [in] DWORD nAceListLength
);

BOOL DuplicateToken(
    [in] HANDLE ExistingTokenHandle,
    [in] SECURITY_IMPERSONATION_LEVEL ImpersonationLevel,
    [out] PHANDLE DuplicateTokenHandle
);

BOOL IsValidSecurityDescriptor(
    [in] PSECURITY_DESCRIPTOR pSecurityDescriptor
);

BOOL IsValidSid(
    [in] PSID pSid
);

BOOL SetPrivateObjectSecurityEx(
    [in] SECURITY_INFORMATION SecurityInformation,
    [in] PSECURITY_DESCRIPTOR ModificationDescriptor,
    [in, out] PSECURITY_DESCRIPTOR *ObjectsSecurityDescriptor,
    [in] ULONG AutoInheritFlags,
    [in] PGENERIC_MAPPING GenericMapping,
    [in, optional] HANDLE Token
);

BOOL AdjustTokenPrivileges(
    [in] HANDLE TokenHandle,
    [in] BOOL DisableAllPrivileges,
    [in, optional] PTOKEN_PRIVILEGES NewState,
    [in] DWORD BufferLength,
    [out, optional] PTOKEN_PRIVILEGES PreviousState,
    [out, optional] PDWORD ReturnLength
);

PSID_IDENTIFIER_AUTHORITY GetSidIdentifierAuthority(
    [in] PSID pSid
);

BOOL AddAccessAllowedAce(
    [in, out] PACL pAcl,
    [in] DWORD dwAceRevision,
    [in] DWORD AccessMask,
    [in] PSID pSid
);

BOOL IsValidAcl(
    [in] PACL pAcl
);

void QuerySecurityAccessMask(
    [in] SECURITY_INFORMATION SecurityInformation,
    [out] LPDWORD DesiredAccess
);

BOOL GetSecurityDescriptorDacl(
    [in] PSECURITY_DESCRIPTOR pSecurityDescriptor,
    [out] LPBOOL lpbDaclPresent,
    [out] PACL *pDacl,
    [out] LPBOOL lpbDaclDefaulted
);

BOOL InitializeAcl(
    [out] PACL pAcl,
    [in] DWORD nAclLength,
    [in] DWORD dwAclRevision
);

DWORD GetSecurityDescriptorLength(
    [in] PSECURITY_DESCRIPTOR pSecurityDescriptor
);

BOOL ConvertToAutoInheritPrivateObjectSecurity(
    [in, optional] PSECURITY_DESCRIPTOR ParentDescriptor,
    [in] PSECURITY_DESCRIPTOR CurrentSecurityDescriptor,
    [out] PSECURITY_DESCRIPTOR *NewSecurityDescriptor,
    [in, optional] GUID *ObjectType,
    [in] BOOLEAN IsDirectoryObject,
    [in] PGENERIC_MAPPING GenericMapping
);

BOOL CreateRestrictedToken(
    [in] HANDLE ExistingTokenHandle,
    [in] DWORD Flags,
    [in] DWORD DisableSidCount,
    [in, optional] PSID_AND_ATTRIBUTES SidsToDisable,
    [in] DWORD DeletePrivilegeCount,
    [in, optional] PLUID_AND_ATTRIBUTES PrivilegesToDelete,
    [in] DWORD RestrictedSidCount,
    [in, optional] PSID_AND_ATTRIBUTES SidsToRestrict,
    [out] PHANDLE NewTokenHandle
);

BOOL GetWindowsAccountDomainSid(
    [in] PSID pSid,
    [out, optional] PSID pDomainSid,
    [in, out] DWORD *cbDomainSid
);

BOOL GetSecurityDescriptorGroup(
    [in] PSECURITY_DESCRIPTOR pSecurityDescriptor,
    [out] PSID *pGroup,
    [out] LPBOOL lpbGroupDefaulted
);

BOOL RevertToSelf();

BOOL ObjectOpenAuditAlarmW(
    [in] LPCWSTR SubsystemName,
    [in] LPVOID HandleId,
    [in] LPWSTR ObjectTypeName,
    [in, optional] LPWSTR ObjectName,
    [in] PSECURITY_DESCRIPTOR pSecurityDescriptor,
    [in] HANDLE ClientToken,
    [in] DWORD DesiredAccess,
    [in] DWORD GrantedAccess,
    [in, optional] PPRIVILEGE_SET Privileges,
    [in] BOOL ObjectCreation,
    [in] BOOL AccessGranted,
    [out] LPBOOL GenerateOnClose
);

BOOL GetSecurityDescriptorSacl(
    [in] PSECURITY_DESCRIPTOR pSecurityDescriptor,
    [out] LPBOOL lpbSaclPresent,
    [out] PACL *pSacl,
    [out] LPBOOL lpbSaclDefaulted
);

BOOL CreatePrivateObjectSecurity(
    [in, optional] PSECURITY_DESCRIPTOR ParentDescriptor,
    [in, optional] PSECURITY_DESCRIPTOR CreatorDescriptor,
    [out] PSECURITY_DESCRIPTOR *NewDescriptor,
    [in] BOOL IsDirectoryObject,
    [in, optional] HANDLE Token,
    [in] PGENERIC_MAPPING GenericMapping
);

BOOL DeleteAce(
    [in, out] PACL pAcl,
    [in] DWORD dwAceIndex
);

BOOL ImpersonateSelf(
    [in] SECURITY_IMPERSONATION_LEVEL ImpersonationLevel
);

BOOL MakeAbsoluteSD(
    [in] PSECURITY_DESCRIPTOR pSelfRelativeSecurityDescriptor,
    [out, optional] PSECURITY_DESCRIPTOR pAbsoluteSecurityDescriptor,
    [in, out] LPDWORD lpdwAbsoluteSecurityDescriptorSize,
    [out, optional] PACL pDacl,
    [in, out] LPDWORD lpdwDaclSize,
    [out, optional] PACL pSacl,
    [in, out] LPDWORD lpdwSaclSize,
    [out, optional] PSID pOwner,
    [in, out] LPDWORD lpdwOwnerSize,
    [out, optional] PSID pPrimaryGroup,
    [in, out] LPDWORD lpdwPrimaryGroupSize
);

BOOL AddAuditAccessAce(
    [in, out] PACL pAcl,
    [in] DWORD dwAceRevision,
    [in] DWORD dwAccessMask,
    [in] PSID pSid,
    [in] BOOL bAuditSuccess,
    [in] BOOL bAuditFailure
);

BOOL AccessCheckByTypeResultListAndAuditAlarmW(
    [in] LPCWSTR SubsystemName,
    [in] LPVOID HandleId,
    [in] LPCWSTR ObjectTypeName,
    [in, optional] LPCWSTR ObjectName,
    [in] PSECURITY_DESCRIPTOR SecurityDescriptor,
    [in, optional] PSID PrincipalSelfSid,
    [in] DWORD DesiredAccess,
    [in] AUDIT_EVENT_TYPE AuditType,
    [in] DWORD Flags,
    [in, out, optional] POBJECT_TYPE_LIST ObjectTypeList,
    [in] DWORD ObjectTypeListLength,
    [in] PGENERIC_MAPPING GenericMapping,
    [in] BOOL ObjectCreation,
    LPDWORD GrantedAccessList,
    [out] LPDWORD AccessStatusList,
    [out] LPBOOL pfGenerateOnClose
);

BOOL GetSecurityDescriptorOwner(
    [in] PSECURITY_DESCRIPTOR pSecurityDescriptor,
    [out] PSID *pOwner,
    [out] LPBOOL lpbOwnerDefaulted
);

BOOL AddAccessDeniedAceEx(
    [in, out] PACL pAcl,
    [in] DWORD dwAceRevision,
    [in] DWORD AceFlags,
    [in] DWORD AccessMask,
    [in] PSID pSid
);

BOOL DuplicateTokenEx(
    [in] HANDLE hExistingToken,
    [in] DWORD dwDesiredAccess,
    [in, optional] LPSECURITY_ATTRIBUTES lpTokenAttributes,
    [in] SECURITY_IMPERSONATION_LEVEL ImpersonationLevel,
    [in] TOKEN_TYPE TokenType,
    [out] PHANDLE phNewToken
);

BOOL SetTokenInformation(
    [in] HANDLE TokenHandle,
    [in] TOKEN_INFORMATION_CLASS TokenInformationClass,
    [in] LPVOID TokenInformation,
    [in] DWORD TokenInformationLength
);

BOOL CreatePrivateObjectSecurityEx(
    [in, optional] PSECURITY_DESCRIPTOR ParentDescriptor,
    [in, optional] PSECURITY_DESCRIPTOR CreatorDescriptor,
    [out] PSECURITY_DESCRIPTOR *NewDescriptor,
    [in, optional] GUID *ObjectType,
    [in] BOOL IsContainerObject,
    [in] ULONG AutoInheritFlags,
    [in, optional] HANDLE Token,
    [in] PGENERIC_MAPPING GenericMapping
);

DWORD GetSidLengthRequired(
    [in] UCHAR nSubAuthorityCount
);

PDWORD GetSidSubAuthority(
    [in] PSID pSid,
    [in] DWORD nSubAuthority
);

BOOL EqualPrefixSid(
    [in] PSID pSid1,
    [in] PSID pSid2
);

BOOL AllocateLocallyUniqueId(
    [out] PLUID Luid
);

BOOL AccessCheckByTypeResultListAndAuditAlarmByHandleW(
    [in] LPCWSTR SubsystemName,
    [in] LPVOID HandleId,
    [in] HANDLE ClientToken,
    [in] LPCWSTR ObjectTypeName,
    [in, optional] LPCWSTR ObjectName,
    [in] PSECURITY_DESCRIPTOR SecurityDescriptor,
    [in, optional] PSID PrincipalSelfSid,
    [in] DWORD DesiredAccess,
    [in] AUDIT_EVENT_TYPE AuditType,
    [in] DWORD Flags,
    [in, out, optional] POBJECT_TYPE_LIST ObjectTypeList,
    [in] DWORD ObjectTypeListLength,
    [in] PGENERIC_MAPPING GenericMapping,
    [in] BOOL ObjectCreation,
    LPDWORD GrantedAccessList,
    [out] LPDWORD AccessStatusList,
    [out] LPBOOL pfGenerateOnClose
);

BOOL CreatePrivateObjectSecurityWithMultipleInheritance(
    [in, optional] PSECURITY_DESCRIPTOR ParentDescriptor,
    [in, optional] PSECURITY_DESCRIPTOR CreatorDescriptor,
    [out] PSECURITY_DESCRIPTOR *NewDescriptor,
    [in, optional] GUID **ObjectTypes,
    [in] ULONG GuidCount,
    [in] BOOL IsContainerObject,
    [in] ULONG AutoInheritFlags,
    [in, optional] HANDLE Token,
    [in] PGENERIC_MAPPING GenericMapping
);

LONG CveEventWrite(
    [in] PCWSTR CveId,
    [in, optional] PCWSTR AdditionalDetails
);

DWORD GetSecurityDescriptorRMControl(
    [in] PSECURITY_DESCRIPTOR SecurityDescriptor,
    [out] PUCHAR RMControl
);

BOOL CopySid(
    [in] DWORD nDestinationSidLength,
    [out] PSID pDestinationSid,
    [in] PSID pSourceSid
);

BOOL SetSecurityDescriptorControl(
    [in] PSECURITY_DESCRIPTOR pSecurityDescriptor,
    [in] SECURITY_DESCRIPTOR_CONTROL ControlBitsOfInterest,
    [in] SECURITY_DESCRIPTOR_CONTROL ControlBitsToSet
);

BOOL AccessCheck(
    [in] PSECURITY_DESCRIPTOR pSecurityDescriptor,
    [in] HANDLE ClientToken,
    [in] DWORD DesiredAccess,
    [in] PGENERIC_MAPPING GenericMapping,
    [out, optional] PPRIVILEGE_SET PrivilegeSet,
    [in, out] LPDWORD PrivilegeSetLength,
    [out] LPDWORD GrantedAccess,
    [out] LPBOOL AccessStatus
);

BOOL MakeSelfRelativeSD(
    [in] PSECURITY_DESCRIPTOR pAbsoluteSecurityDescriptor,
    [out, optional] PSECURITY_DESCRIPTOR pSelfRelativeSecurityDescriptor,
    [in, out] LPDWORD lpdwBufferLength
);

BOOL GetFileSecurityW(
    [in] LPCWSTR lpFileName,
    [in] SECURITY_INFORMATION RequestedInformation,
    [out, optional] PSECURITY_DESCRIPTOR pSecurityDescriptor,
    [in] DWORD nLength,
    [out] LPDWORD lpnLengthNeeded
);

DWORD SetSecurityDescriptorRMControl(
    [in, out] PSECURITY_DESCRIPTOR SecurityDescriptor,
    [in, optional] PUCHAR RMControl
);

BOOL GetPrivateObjectSecurity(
    [in] PSECURITY_DESCRIPTOR ObjectDescriptor,
    [in] SECURITY_INFORMATION SecurityInformation,
    [out, optional] PSECURITY_DESCRIPTOR ResultantDescriptor,
    [in] DWORD DescriptorLength,
    [out] PDWORD ReturnLength
);

BOOL CheckTokenCapability(
    [in, optional] HANDLE TokenHandle,
    [in] PSID CapabilitySidToCheck,
    [out] PBOOL HasCapability
);

BOOL GetAce(
    [in] PACL pAcl,
    [in] DWORD dwAceIndex,
    [out] LPVOID *pAce
);

BOOL SetSecurityDescriptorGroup(
    [in, out] PSECURITY_DESCRIPTOR pSecurityDescriptor,
    [in, optional] PSID pGroup,
    [in] BOOL bGroupDefaulted
);

BOOL ImpersonateAnonymousToken(
    [in] HANDLE ThreadHandle
);

BOOL AccessCheckByTypeAndAuditAlarmW(
    [in] LPCWSTR SubsystemName,
    [in] LPVOID HandleId,
    [in] LPCWSTR ObjectTypeName,
    [in, optional] LPCWSTR ObjectName,
    [in] PSECURITY_DESCRIPTOR SecurityDescriptor,
    [in, optional] PSID PrincipalSelfSid,
    [in] DWORD DesiredAccess,
    [in] AUDIT_EVENT_TYPE AuditType,
    [in] DWORD Flags,
    [in, out, optional] POBJECT_TYPE_LIST ObjectTypeList,
    [in] DWORD ObjectTypeListLength,
    [in] PGENERIC_MAPPING GenericMapping,
    [in] BOOL ObjectCreation,
    [out] LPDWORD GrantedAccess,
    [out] LPBOOL AccessStatus,
    [out] LPBOOL pfGenerateOnClose
);

BOOL GetSecurityDescriptorControl(
    [in] PSECURITY_DESCRIPTOR pSecurityDescriptor,
    [out] PSECURITY_DESCRIPTOR_CONTROL pControl,
    [out] LPDWORD lpdwRevision
);

BOOL DeriveCapabilitySidsFromName(
    [in] LPCWSTR CapName,
    [out] PSID **CapabilityGroupSids,
    [out] DWORD *CapabilityGroupSidCount,
    [out] PSID **CapabilitySids,
    [out] DWORD *CapabilitySidCount
);

BOOL GetAclInformation(
    [in] PACL pAcl,
    [out] LPVOID pAclInformation,
    [in] DWORD nAclInformationLength,
    [in] ACL_INFORMATION_CLASS dwAclInformationClass
);

BOOL AddResourceAttributeAce(
    [in, out] PACL pAcl,
    [in] DWORD dwAceRevision,
    [in] DWORD AceFlags,
    [in] DWORD AccessMask,
    [in] PSID pSid,
    [in] PCLAIM_SECURITY_ATTRIBUTES_INFORMATION pAttributeInfo,
    [out] PDWORD pReturnLength
);

BOOL SetAclInformation(
    [in, out] PACL pAcl,
    [in] LPVOID pAclInformation,
    [in] DWORD nAclInformationLength,
    [in] ACL_INFORMATION_CLASS dwAclInformationClass
);

BOOL EqualDomainSid(
    [in] PSID pSid1,
    [in] PSID pSid2,
    [out] BOOL *pfEqual
);

BOOL GetKernelObjectSecurity(
    [in] HANDLE Handle,
    [in] SECURITY_INFORMATION RequestedInformation,
    [out, optional] PSECURITY_DESCRIPTOR pSecurityDescriptor,
    [in] DWORD nLength,
    [out] LPDWORD lpnLengthNeeded
);

BOOL SetPrivateObjectSecurity(
    [in] SECURITY_INFORMATION SecurityInformation,
    [in] PSECURITY_DESCRIPTOR ModificationDescriptor,
    [in, out] PSECURITY_DESCRIPTOR *ObjectsSecurityDescriptor,
    [in] PGENERIC_MAPPING GenericMapping,
    [in, optional] HANDLE Token
);

BOOL SetKernelObjectSecurity(
    [in] HANDLE Handle,
    [in] SECURITY_INFORMATION SecurityInformation,
    [in] PSECURITY_DESCRIPTOR SecurityDescriptor
);

BOOL GetTokenInformation(
    [in] HANDLE TokenHandle,
    [in] TOKEN_INFORMATION_CLASS TokenInformationClass,
    [out, optional] LPVOID TokenInformation,
    [in] DWORD TokenInformationLength,
    [out] PDWORD ReturnLength
);

BOOL SetFileSecurityW(
    [in] LPCWSTR lpFileName,
    [in] SECURITY_INFORMATION SecurityInformation,
    [in] PSECURITY_DESCRIPTOR pSecurityDescriptor
);

BOOL PrivilegedServiceAuditAlarmW(
    [in] LPCWSTR SubsystemName,
    [in] LPCWSTR ServiceName,
    [in] HANDLE ClientToken,
    [in] PPRIVILEGE_SET Privileges,
    [in] BOOL AccessGranted
);

BOOL ObjectCloseAuditAlarmW(
    [in] LPCWSTR SubsystemName,
    [in] LPVOID HandleId,
    [in] BOOL GenerateOnClose
);

BOOL GetAppContainerAce(
    [in] PACL Acl,
    [in] DWORD StartingAceIndex,
    [out] PVOID *AppContainerAce,
    [out, optional] DWORD *AppContainerAceIndex
);

BOOL AddAccessDeniedAce(
    [in, out] PACL pAcl,
    [in] DWORD dwAceRevision,
    [in] DWORD AccessMask,
    [in] PSID pSid
);

BOOL InitializeSecurityDescriptor(
    [out] PSECURITY_DESCRIPTOR pSecurityDescriptor,
    [in] DWORD dwRevision
);

BOOL AreAnyAccessesGranted(
    [in] DWORD GrantedAccess,
    [in] DWORD DesiredAccess
);

BOOL SetCachedSigningLevel(
    [in] PHANDLE SourceFiles,
    [in] ULONG SourceFileCount,
    [in] ULONG Flags,
    [in, optional] HANDLE TargetFile
);

BOOL SetSecurityDescriptorDacl(
    [in, out] PSECURITY_DESCRIPTOR pSecurityDescriptor,
    [in] BOOL bDaclPresent,
    [in, optional] PACL pDacl,
    [in] BOOL bDaclDefaulted
);

PUCHAR GetSidSubAuthorityCount(
    [in] PSID pSid
);

BOOL AddMandatoryAce(
    [in, out] PACL pAcl,
    [in] DWORD dwAceRevision,
    [in] DWORD AceFlags,
    [in] DWORD MandatoryPolicy,
    [in] PSID pLabelSid
);

PVOID FreeSid(
    [in] PSID pSid
);

BOOL AdjustTokenGroups(
    [in] HANDLE TokenHandle,
    [in] BOOL ResetToDefault,
    [in, optional] PTOKEN_GROUPS NewState,
    [in] DWORD BufferLength,
    [out, optional] PTOKEN_GROUPS PreviousState,
    [out, optional] PDWORD ReturnLength
);

BOOL AccessCheckByTypeResultList(
    [in] PSECURITY_DESCRIPTOR pSecurityDescriptor,
    [in, optional] PSID PrincipalSelfSid,
    [in] HANDLE ClientToken,
    [in] DWORD DesiredAccess,
    [in, out, optional] POBJECT_TYPE_LIST ObjectTypeList,
    [in] DWORD ObjectTypeListLength,
    [out] PGENERIC_MAPPING GenericMapping,
    [out, optional] PPRIVILEGE_SET PrivilegeSet,
    [in, out] LPDWORD PrivilegeSetLength,
    [out] LPDWORD GrantedAccessList,
    [out] LPDWORD AccessStatusList
);

BOOL DestroyPrivateObjectSecurity(
    [in, out] PSECURITY_DESCRIPTOR *ObjectDescriptor
);

BOOL SetSecurityDescriptorOwner(
    [in, out] PSECURITY_DESCRIPTOR pSecurityDescriptor,
    [in, optional] PSID pOwner,
    [in] BOOL bOwnerDefaulted
);

BOOL PrivilegeCheck(
    [in] HANDLE ClientToken,
    [in, out] PPRIVILEGE_SET RequiredPrivileges,
    [out] LPBOOL pfResult
);

BOOL AddAuditAccessObjectAce(
    [in, out] PACL pAcl,
    [in] DWORD dwAceRevision,
    [in] DWORD AceFlags,
    [in] DWORD AccessMask,
    [in, optional] GUID *ObjectTypeGuid,
    [in, optional] GUID *InheritedObjectTypeGuid,
    [in] PSID pSid,
    [in] BOOL bAuditSuccess,
    [in] BOOL bAuditFailure
);

BOOL EqualSid(
    [in] PSID pSid1,
    [in] PSID pSid2
);

BOOL CheckTokenMembershipEx(
    [in, optional] HANDLE TokenHandle,
    [in] PSID SidToCheck,
    [in] DWORD Flags,
    [out] PBOOL IsMember
);

BOOL SetSecurityDescriptorSacl(
    [in, out] PSECURITY_DESCRIPTOR pSecurityDescriptor,
    [in] BOOL bSaclPresent,
    [in, optional] PACL pSacl,
    [in] BOOL bSaclDefaulted
);

BOOL AddScopedPolicyIDAce(
    [in, out] PACL pAcl,
    [in] DWORD dwAceRevision,
    [in] DWORD AceFlags,
    [in] DWORD AccessMask,
    [in] PSID pSid
);

BOOL AddAccessAllowedAceEx(
    [in, out] PACL pAcl,
    [in] DWORD dwAceRevision,
    [in] DWORD AceFlags,
    [in] DWORD AccessMask,
    [in] PSID pSid
);

BOOL AddAccessDeniedObjectAce(
    [in, out] PACL pAcl,
    [in] DWORD dwAceRevision,
    [in] DWORD AceFlags,
    [in] DWORD AccessMask,
    [in, optional] GUID *ObjectTypeGuid,
    [in, optional] GUID *InheritedObjectTypeGuid,
    [in] PSID pSid
);

BOOL CheckTokenMembership(
    [in, optional] HANDLE TokenHandle,
    [in] PSID SidToCheck,
    [out] PBOOL IsMember
);

BOOL ObjectPrivilegeAuditAlarmW(
    [in] LPCWSTR SubsystemName,
    [in] LPVOID HandleId,
    [in] HANDLE ClientToken,
    [in] DWORD DesiredAccess,
    [in] PPRIVILEGE_SET Privileges,
    [in] BOOL AccessGranted
);

BOOL IsWellKnownSid(
    [in] PSID pSid,
    [in] WELL_KNOWN_SID_TYPE WellKnownSidType
);

BOOL InitializeSid(
    [out] PSID Sid,
    [in] PSID_IDENTIFIER_AUTHORITY pIdentifierAuthority,
    [in] BYTE nSubAuthorityCount
);

void SetSecurityAccessMask(
    [in] SECURITY_INFORMATION SecurityInformation,
    [out] LPDWORD DesiredAccess
);

BOOL AddAuditAccessAceEx(
    [in, out] PACL pAcl,
    [in] DWORD dwAceRevision,
    [in] DWORD AceFlags,
    [in] DWORD dwAccessMask,
    [in] PSID pSid,
    [in] BOOL bAuditSuccess,
    [in] BOOL bAuditFailure
);

BOOL GetCachedSigningLevel(
    [in] HANDLE File,
    [Out] PULONG Flags,
    [Out] PULONG SigningLevel,
    [Out, optional] PUCHAR Thumbprint,
    [In, Out, optional] PULONG ThumbprintSize,
    [Out, optional] PULONG ThumbprintAlgorithm
);

void MapGenericMask(
    [in, out] PDWORD AccessMask,
    [in] PGENERIC_MAPPING GenericMapping
);

BOOL IsTokenRestricted(
    [in] HANDLE TokenHandle
);

BOOL AreAllAccessesGranted(
    [in] DWORD GrantedAccess,
    [in] DWORD DesiredAccess
);

BOOL FindFirstFreeAce(
    [in] PACL pAcl,
    [out] LPVOID *pAce
);

BOOL ObjectDeleteAuditAlarmW(
    [in] LPCWSTR SubsystemName,
    [in] LPVOID HandleId,
    [in] BOOL GenerateOnClose
);

BOOL AddAccessAllowedObjectAce(
    [in, out] PACL pAcl,
    [in] DWORD dwAceRevision,
    [in] DWORD AceFlags,
    [in] DWORD AccessMask,
    [in, optional] GUID *ObjectTypeGuid,
    [in, optional] GUID *InheritedObjectTypeGuid,
    [in] PSID pSid
);

DWORD GetLengthSid(
    [in] PSID pSid
);

BOOL AccessCheckByType(
    [in] PSECURITY_DESCRIPTOR pSecurityDescriptor,
    [in, optional] PSID PrincipalSelfSid,
    [in] HANDLE ClientToken,
    [in] DWORD DesiredAccess,
    [in, out, optional] POBJECT_TYPE_LIST ObjectTypeList,
    [in] DWORD ObjectTypeListLength,
    [in] PGENERIC_MAPPING GenericMapping,
    [out, optional] PPRIVILEGE_SET PrivilegeSet,
    [in, out] LPDWORD PrivilegeSetLength,
    [out] LPDWORD GrantedAccess,
    [out] LPBOOL AccessStatus
);

BOOL CreateWellKnownSid(
    [in] WELL_KNOWN_SID_TYPE WellKnownSidType,
    [in, optional] PSID DomainSid,
    [out, optional] PSID pSid,
    [in, out] DWORD *cbSid
);

BOOL AllocateAndInitializeSid(
    [in] PSID_IDENTIFIER_AUTHORITY pIdentifierAuthority,
    [in] BYTE nSubAuthorityCount,
    [in] DWORD nSubAuthority0,
    [in] DWORD nSubAuthority1,
    [in] DWORD nSubAuthority2,
    [in] DWORD nSubAuthority3,
    [in] DWORD nSubAuthority4,
    [in] DWORD nSubAuthority5,
    [in] DWORD nSubAuthority6,
    [in] DWORD nSubAuthority7,
    [out] PSID *pSid
);

