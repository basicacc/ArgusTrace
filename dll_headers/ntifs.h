BOOLEAN SeAccessCheckFromState(
    PSECURITY_DESCRIPTOR SecurityDescriptor,
    PTOKEN_ACCESS_INFORMATION PrimaryTokenInformation,
    PTOKEN_ACCESS_INFORMATION ClientTokenInformation,
    ACCESS_MASK DesiredAccess,
    ACCESS_MASK PreviouslyGrantedAccess,
    PPRIVILEGE_SET *Privileges,
    PGENERIC_MAPPING GenericMapping,
    KPROCESSOR_MODE AccessMode,
    PACCESS_MASK GrantedAccess,
    PNTSTATUS AccessStatus
);

void FsRtlFreeExtraCreateParameter(
    [in] PVOID EcpContext
);

NTSTATUS FsRtlAllocateExtraCreateParameterList(
    [in] FSRTL_ALLOCATE_ECPLIST_FLAGS Flags,
    [out] PECP_LIST *EcpList
);

NTSYSAPI NTSTATUS RtlOemStringToUnicodeString(
    PUNICODE_STRING DestinationString,
    [in] PCOEM_STRING SourceString,
    [in] BOOLEAN AllocateDestinationString
);

NTSTATUS ObInsertObject(
    PVOID Object,
    PACCESS_STATE PassedAccessState,
    ACCESS_MASK DesiredAccess,
    ULONG ObjectPointerBias,
    PVOID *NewObject,
    PHANDLE Handle
);

NTSTATUS FsRtlGetEcpListFromIrp(
    [in] PIRP Irp,
    [out] PECP_LIST *EcpList
);

PDEVICE_OBJECT IoGetDeviceToVerify(
    [in] PETHREAD Thread
);

NTSYSAPI NTSTATUS RtlMultiByteToUnicodeSize(
    [out] PULONG BytesInUnicodeString,
    [in] const CHAR *MultiByteString,
    [in] ULONG BytesInMultiByteString
);

KSECDDDECLSPEC NTSTATUS SecMakeSPN(
    [in] IN PUNICODE_STRING ServiceClass,
    [in] IN PUNICODE_STRING ServiceName,
    [in, optional] IN PUNICODE_STRING InstanceName,
    [in, optional] IN USHORT InstancePort,
    [in, optional] IN PUNICODE_STRING Referrer,
    [in, out] IN OUT PUNICODE_STRING Spn,
    [out, optional] OUT PULONG Length,
    [in] IN BOOLEAN Allocate
);

BOOLEAN FsRtlAddLargeMcbEntry(
    PLARGE_MCB Mcb,
    LONGLONG Vbn,
    LONGLONG Lbn,
    LONGLONG SectorCount
);

NTSTATUS SeRegisterLogonSessionTerminatedRoutine(
    [in] PSE_LOGON_SESSION_TERMINATED_ROUTINE CallbackRoutine
);

void FsRtlDeleteExtraCreateParameterLookasideList(
    [in, out] PVOID Lookaside,
    [in] FSRTL_ECP_LOOKASIDE_FLAGS Flags
);

NTSYSAPI NTSTATUS RtlUnicodeToCustomCPN(
    PCPTABLEINFO CustomCP,
    PCH CustomCPString,
    ULONG MaxBytesInCustomCPString,
    PULONG BytesInCustomCPString,
    PWCH UnicodeString,
    ULONG BytesInUnicodeString
);

NTSTATUS KeGetProcessorNumberFromIndex(
    [in] ULONG ProcIndex,
    [out] PPROCESSOR_NUMBER ProcNumber
);

BOOLEAN FsRtlIsHpfsDbcsLegal(
    [in] ANSI_STRING DbcsName,
    [in] BOOLEAN WildCardsPermissible,
    [in] BOOLEAN PathNamePermissible,
    [in] BOOLEAN LeadingBackslashPermissible
);

NTSTATUS FsRtlRegisterUncProvider(
    [out] PHANDLE MupHandle,
    PCUNICODE_STRING RedirectorDeviceName,
    [in] BOOLEAN MailslotsSupported
);

NTSTATUS SeSetSecurityDescriptorInfo(
    [in, optional] PVOID Object,
    [in] PSECURITY_INFORMATION SecurityInformation,
    PSECURITY_DESCRIPTOR ModificationDescriptor,
    [in, out] PSECURITY_DESCRIPTOR *ObjectsSecurityDescriptor,
    [in] POOL_TYPE PoolType,
    [in] PGENERIC_MAPPING GenericMapping
);

NTSTATUS CcWaitForCurrentLazyWriterActivity();

NTSTATUS SeFilterToken(
    [in] PACCESS_TOKEN ExistingToken,
    [in] ULONG Flags,
    [in, optional] PTOKEN_GROUPS SidsToDisable,
    [in, optional] PTOKEN_PRIVILEGES PrivilegesToDelete,
    [in, optional] PTOKEN_GROUPS RestrictedSids,
    PACCESS_TOKEN *FilteredToken
);

void FsRtlInitializeFileLock(
    [in] PFILE_LOCK FileLock,
    [in, optional] PCOMPLETE_LOCK_IRP_ROUTINE CompleteLockIrpRoutine,
    [in, optional] PUNLOCK_ROUTINE UnlockRoutine
);

NTSYSAPI NTSTATUS ZwSetQuotaInformationFile(
    [in] HANDLE FileHandle,
    [out] PIO_STATUS_BLOCK IoStatusBlock,
    [in] PVOID Buffer,
    [in] ULONG Length
);

__kernel_entry NTSYSCALLAPI NTSTATUS NtCreateFile(
    [out] PHANDLE FileHandle,
    [in] ACCESS_MASK DesiredAccess,
    [in] POBJECT_ATTRIBUTES ObjectAttributes,
    [out] PIO_STATUS_BLOCK IoStatusBlock,
    [in, optional] PLARGE_INTEGER AllocationSize,
    [in] ULONG FileAttributes,
    [in] ULONG ShareAccess,
    [in] ULONG CreateDisposition,
    [in] ULONG CreateOptions,
    [in, optional] PVOID EaBuffer,
    [in] ULONG EaLength
);

NTSYSAPI USHORT RtlCaptureStackBackTrace(
    [in] ULONG FramesToSkip,
    [in] ULONG FramesToCapture,
    [out] PVOID *BackTrace,
    [out, optional] PULONG BackTraceHash
);

void IoQueueThreadIrp(
    PIRP Irp
);

NTSYSAPI NTSTATUS ZwSetVolumeInformationFile(
    [in] HANDLE FileHandle,
    [out] PIO_STATUS_BLOCK IoStatusBlock,
    [in] PVOID FsInformation,
    [in] ULONG Length,
    [in] FS_INFORMATION_CLASS FsInformationClass
);

void SeTokenSetNoChildProcessRestricted(
    [in] PACCESS_TOKEN Token,
    [in] BOOLEAN UnlessSecure,
    [in] BOOLEAN AuditOnly
);

void FsRtlNotifyFilterChangeDirectory(
    [in] PNOTIFY_SYNC NotifySync,
    [in] PLIST_ENTRY NotifyList,
    [in] PVOID FsContext,
    [in] PSTRING FullDirectoryName,
    [in] BOOLEAN WatchTree,
    [in] BOOLEAN IgnoreBuffer,
    [in] ULONG CompletionFilter,
    [in, optional] PIRP NotifyIrp,
    [in, optional] PCHECK_FOR_TRAVERSE_ACCESS TraverseCallback,
    [in, optional] PSECURITY_SUBJECT_CONTEXT SubjectContext,
    [in, optional] PFILTER_REPORT_CHANGE FilterCallback
);

__kernel_entry NTSYSCALLAPI NTSTATUS NtOpenProcessTokenEx(
    [in] HANDLE ProcessHandle,
    [in] ACCESS_MASK DesiredAccess,
    [in] ULONG HandleAttributes,
    [out] PHANDLE TokenHandle
);

NTSYSAPI NTSTATUS RtlGetAce(
    [in] PACL Acl,
    [in] ULONG AceIndex,
    [out] PVOID *Ace
);

NTSTATUS SeQuerySessionIdToken(
    PACCESS_TOKEN Token,
    PULONG SessionId
);

NTSTATUS FsRtlInsertExtraCreateParameter(
    [in, out] PECP_LIST EcpList,
    [in, out] PVOID EcpContext
);

NTSYSAPI NTSTATUS RtlInitStringEx(
    [out] PSTRING DestinationString,
    [in, optional] __drv_aliasesMem PCSZ SourceString
);

NTSTATUS SeCreateClientSecurity(
    [in] PETHREAD ClientThread,
    [in] PSECURITY_QUALITY_OF_SERVICE ClientSecurityQos,
    BOOLEAN RemoteSession,
    [out] PSECURITY_CLIENT_CONTEXT ClientContext
);

NTSYSAPI BOOLEAN RtlTimeToSecondsSince1980(
    [in] PLARGE_INTEGER Time,
    [out] PULONG ElapsedSeconds
);

void IsReparseTagNameSurrogate(
    [in] _tag
);

void FsRtlInitializeOplock(
    [in, out] POPLOCK Oplock
);

void FsRtlAddToTunnelCache(
    [in] TUNNEL *Cache,
    [in] ULONGLONG DirectoryKey,
    [in] UNICODE_STRING *ShortName,
    [in] UNICODE_STRING *LongName,
    [in] BOOLEAN KeyByShortName,
    [in] ULONG DataLength,
    [in] VOID *Data
);

NTSTATUS FsRtlCheckOplock(
    [in] POPLOCK Oplock,
    [in] PIRP Irp,
    [in, optional] PVOID Context,
    [in, optional] POPLOCK_WAIT_COMPLETE_ROUTINE CompletionRoutine,
    [in, optional] POPLOCK_FS_PREPOST_IRP PostIrpRoutine
);

void ExDisableResourceBoostLite(
    PERESOURCE Resource
);

NTSTATUS FsRtlNotifyVolumeEventEx(
    [in] PFILE_OBJECT FileObject,
    [in] ULONG EventCode,
    [in] PTARGET_DEVICE_CUSTOM_NOTIFICATION Event
);

NTSYSAPI NTSTATUS RtlInitializeSid(
    [out] PSID Sid,
    [in] PSID_IDENTIFIER_AUTHORITY IdentifierAuthority,
    [in] UCHAR SubAuthorityCount
);

BOOLEAN FsRtlGetNextMcbEntry(
    PMCB Mcb,
    ULONG RunIndex,
    PVBN Vbn,
    PLBN Lbn,
    PULONG SectorCount
);

void CcFastCopyWrite(
    [in] PFILE_OBJECT FileObject,
    [in] ULONG FileOffset,
    [in] ULONG Length,
    [in] PVOID Buffer
);

NTSTATUS FsRtlOplockBreakToNone(
    POPLOCK Oplock,
    PIO_STACK_LOCATION IrpSp,
    PIRP Irp,
    PVOID Context,
    POPLOCK_WAIT_COMPLETE_ROUTINE CompletionRoutine,
    POPLOCK_FS_PREPOST_IRP PostIrpRoutine
);

NTSTATUS SeMarkLogonSessionForTerminationNotification(
    [in] PLUID LogonId
);

void CcFastCopyRead(
    [in] PFILE_OBJECT FileObject,
    [in] ULONG FileOffset,
    [in] ULONG Length,
    [in] ULONG PageCount,
    [out] PVOID Buffer,
    [out] PIO_STATUS_BLOCK IoStatus
);

NTSTATUS FsRtlMdlReadEx(
    [in] PFILE_OBJECT FileObject,
    [in] PLARGE_INTEGER FileOffset,
    [in] ULONG Length,
    [in] ULONG LockKey,
    [out] PMDL *MdlChain,
    [out] PIO_STATUS_BLOCK IoStatus
);

__kernel_entry NTSYSCALLAPI NTSTATUS NtQueryQuotaInformationFile(
    [in] HANDLE FileHandle,
    [out] PIO_STATUS_BLOCK IoStatusBlock,
    [out] PVOID Buffer,
    [in] ULONG Length,
    [in] BOOLEAN ReturnSingleEntry,
    [in, optional] PVOID SidList,
    [in] ULONG SidListLength,
    [in, optional] PSID StartSid,
    [in] BOOLEAN RestartScan
);

void FsRtlPostStackOverflow(
    [in] PVOID Context,
    [in] PKEVENT Event,
    [in] PFSRTL_STACK_OVERFLOW_ROUTINE StackOverflowRoutine
);

void SeImpersonateClient(
    PSECURITY_CLIENT_CONTEXT ClientContext,
    PETHREAD ServerThread
);

NTSYSAPI NTSTATUS RtlAddAccessAllowedAce(
    [in, out] PACL Acl,
    [in] ULONG AceRevision,
    [in] ACCESS_MASK AccessMask,
    [in] PSID Sid
);

KSECDDDECLSPEC NTSTATUS SEC_ENTRY SecLookupAccountSid(
    [in] PSID Sid,
    [out] PULONG NameSize,
    [in, out] PUNICODE_STRING NameBuffer,
    [out] PULONG DomainSize,
    [out, optional] PUNICODE_STRING DomainBuffer,
    [out] PSID_NAME_USE NameUse
);

NTSYSAPI NTSTATUS ZwDuplicateObject(
    [in] HANDLE SourceProcessHandle,
    [in] HANDLE SourceHandle,
    [in, optional] HANDLE TargetProcessHandle,
    [out, optional] PHANDLE TargetHandle,
    [in] ACCESS_MASK DesiredAccess,
    [in] ULONG HandleAttributes,
    [in] ULONG Options
);

NTSTATUS FsRtlQueryInformationFile(
    [in] PFILE_OBJECT FileObject,
    [out] PVOID FileInformation,
    [in] ULONG Length,
    [in] FILE_INFORMATION_CLASS FileInformationClass,
    [out] PULONG RetFileInformationSize
);

__kernel_entry NTSYSCALLAPI NTSTATUS NtFlushBuffersFileEx(
    [in] HANDLE FileHandle,
    [in] ULONG Flags,
    [in] PVOID Parameters,
    [in] ULONG ParametersSize,
    [out] PIO_STATUS_BLOCK IoStatusBlock
);

NTSTATUS FsRtlSetEcpListIntoIrp(
    [in, out] PIRP Irp,
    [in] PECP_LIST EcpList
);

void CcUnpinDataForThread(
    [in] PVOID Bcb,
    [in] ERESOURCE_THREAD ResourceThreadId
);

NTSTATUS SeQueryInformationToken(
    [in] PACCESS_TOKEN Token,
    [in] TOKEN_INFORMATION_CLASS TokenInformationClass,
    [out] PVOID *TokenInformation
);

NTSTATUS FsRtlCancellableWaitForSingleObject(
    [in] PVOID Object,
    [in, optional] PLARGE_INTEGER Timeout,
    [in, optional] PIRP Irp
);

void FsRtlIsAnsiCharacterLegal(
    C,
    FLAGS
);

NTSTATUS IoCreateStreamFileObjectEx2(
    [in] PIO_CREATE_STREAM_FILE_OPTIONS CreateOptions,
    [in, optional] PFILE_OBJECT FileObject,
    [in, optional] PDEVICE_OBJECT DeviceObject,
    [out] PFILE_OBJECT *StreamFileObject,
    [out, optional] PHANDLE FileHandle
);

void IoUnregisterFsRegistrationChange(
    [in] PDRIVER_OBJECT DriverObject,
    [in] PDRIVER_FS_NOTIFICATION DriverNotificationRoutine
);

NTSYSAPI NTSTATUS RtlCreateAcl(
    [out] PACL Acl,
    [in] ULONG AclLength,
    ULONG AclRevision
);

PVOID FsRtlAllocateAePushLock(
    [in] POOL_TYPE PoolType,
    [in] ULONG Tag
);

NTSYSAPI NTSTATUS RtlAddAce(
    [in, out] PACL Acl,
    [in] ULONG AceRevision,
    [in] ULONG StartingAceIndex,
    [in] PVOID AceList,
    [in] ULONG AceListLength
);

void PsDereferencePrimaryToken(
    [in] PACCESS_TOKEN PrimaryToken
);

void FsRtlInitializeMcb(
    PMCB Mcb,
    POOL_TYPE PoolType
);

BOOLEAN FsRtlDoesDbcsContainWildCards(
    [in] PANSI_STRING Name
);

NT_RTL_COMPRESS_API NTSTATUS RtlCompressBuffer(
    [in] USHORT CompressionFormatAndEngine,
    [in] PUCHAR UncompressedBuffer,
    [in] ULONG UncompressedBufferSize,
    [out] PUCHAR CompressedBuffer,
    [in] ULONG CompressedBufferSize,
    [in] ULONG UncompressedChunkSize,
    [out] PULONG FinalCompressedSize,
    [in] PVOID WorkSpace
);

NTSYSAPI VOID RtlFreeOemString(
    [in, out] POEM_STRING OemString
);

NTSTATUS CcRegisterExternalCacheEx(
    PFILE_OBJECT FileObject,
    PEXTERNAL_CACHE_CALLBACK_EX Callback,
    PVOID *ExternalCacheContext
);

__kernel_entry NTSYSCALLAPI NTSTATUS NtOpenThreadTokenEx(
    [in] HANDLE ThreadHandle,
    [in] ACCESS_MASK DesiredAccess,
    [in] BOOLEAN OpenAsSelf,
    [in] ULONG HandleAttributes,
    [out] PHANDLE TokenHandle
);

void SeOpenObjectAuditAlarm(
    [in] PUNICODE_STRING ObjectTypeName,
    [in, optional] PVOID Object,
    [in, optional] PUNICODE_STRING AbsoluteObjectName,
    [in] PSECURITY_DESCRIPTOR SecurityDescriptor,
    [in] PACCESS_STATE AccessState,
    [in] BOOLEAN ObjectCreated,
    [in] BOOLEAN AccessGranted,
    [in] KPROCESSOR_MODE AccessMode,
    [out] PBOOLEAN GenerateOnClose
);

NTSYSAPI NTSTATUS ZwSetSecurityObject(
    [in] HANDLE Handle,
    [in] SECURITY_INFORMATION SecurityInformation,
    [in] PSECURITY_DESCRIPTOR SecurityDescriptor
);

void FsRtlIsLeadDbcsCharacter(
    DBCS_CHAR
);

NTSTATUS FsRtlCreateSectionForDataScan(
    [out] PHANDLE SectionHandle,
    [out] PVOID *SectionObject,
    [out, optional] PLARGE_INTEGER SectionFileSize,
    [in] PFILE_OBJECT FileObject,
    [in] ACCESS_MASK DesiredAccess,
    [in, optional] POBJECT_ATTRIBUTES ObjectAttributes,
    [in, optional] PLARGE_INTEGER MaximumSize,
    [in] ULONG SectionPageProtection,
    [in] ULONG AllocationAttributes,
    [in] ULONG Flags
);

NTSTATUS CcUpdateExternalCacheInfoEx(
    PVOID ExternalCacheContext,
    PCC_DIRTY_PAGES_INFO DirtyPagesInfo
);

void FsRtlAllocatePoolWithQuotaTag(
    [in] PoolType,
    [in] NumberOfBytes,
    [in] Tag
);

BOOLEAN FsRtlIsEcpFromUserMode(
    [in] PVOID EcpContext
);

__kernel_entry NTSYSCALLAPI NTSTATUS NtSetQuotaInformationFile(
    [in] HANDLE FileHandle,
    [out] PIO_STATUS_BLOCK IoStatusBlock,
    [in] PVOID Buffer,
    [in] ULONG Length
);

BOOLEAN FsRtlCheckFileSystemFilterCallbacksRegistered(
    _DRIVER_OBJECT *FilterDriverObject
);

NTSTATUS FsRtlLogCcFlushError(
    [in] PUNICODE_STRING FileName,
    [in] PDEVICE_OBJECT DeviceObject,
    [in] PSECTION_OBJECT_POINTERS SectionObjectPointer,
    [in] NTSTATUS FlushError,
    [in] ULONG Flags
);

NTSYSAPI NTSTATUS ZwUnlockFile(
    [in] HANDLE FileHandle,
    [out] PIO_STATUS_BLOCK IoStatusBlock,
    [in] PLARGE_INTEGER ByteOffset,
    [in] PLARGE_INTEGER Length,
    [in] ULONG Key
);

NTSYSAPI ULONG RtlRandomEx(
    [in, out] PULONG Seed
);

void FsRtlInitializeBaseMcb(
    PBASE_MCB Mcb,
    POOL_TYPE PoolType
);

NTHALAPI VOID KeStallExecutionProcessor(
    [in] ULONG MicroSeconds
);

NTSYSAPI BOOLEAN RtlCreateUnicodeString(
    [out] PUNICODE_STRING DestinationString,
    [in] PCWSTR SourceString
);

NTSYSAPI NTSTATUS ZwAllocateVirtualMemory(
    [in] HANDLE ProcessHandle,
    [in, out] PVOID *BaseAddress,
    [in] ULONG_PTR ZeroBits,
    [in, out] PSIZE_T RegionSize,
    [in] ULONG AllocationType,
    [in] ULONG Protect
);

void FsRtlFreeFileLock(
    [in] PFILE_LOCK FileLock
);

NTSTATUS FsRtlFindExtraCreateParameter(
    [in] PECP_LIST EcpList,
    [in] LPCGUID EcpType,
    [out, optional] PVOID *EcpContext,
    [out, optional] ULONG *EcpContextSize
);

NTSTATUS ObOpenObjectByPointer(
    [in] PVOID Object,
    [in] ULONG HandleAttributes,
    [in, optional] PACCESS_STATE PassedAccessState,
    [in] ACCESS_MASK DesiredAccess,
    [in, optional] POBJECT_TYPE ObjectType,
    [in] KPROCESSOR_MODE AccessMode,
    [out] PHANDLE Handle
);

NTSYSAPI NTSTATUS RtlUnicodeStringToUTF8String(
    PUTF8_STRING DestinationString,
    PCUNICODE_STRING SourceString,
    BOOLEAN AllocateDestinationString
);

NTSTATUS FsRtlInitializeExtraCreateParameterList(
    [in, out] PECP_LIST EcpList
);

BOOLEAN FsRtlOplockIsSharedRequest(
    [in] PIRP Irp
);

NTSYSAPI NTSTATUS ZwQueryDirectoryFile(
    [in] HANDLE FileHandle,
    [in, optional] HANDLE Event,
    [in, optional] PIO_APC_ROUTINE ApcRoutine,
    [in, optional] PVOID ApcContext,
    [out] PIO_STATUS_BLOCK IoStatusBlock,
    [out] PVOID FileInformation,
    [in] ULONG Length,
    [in] FILE_INFORMATION_CLASS FileInformationClass,
    [in] BOOLEAN ReturnSingleEntry,
    [in, optional] PUNICODE_STRING FileName,
    [in] BOOLEAN RestartScan
);

PDEVICE_OBJECT IoGetDeviceAttachmentBaseRef(
    [in] PDEVICE_OBJECT DeviceObject
);

void FsRtlAcquireFileExclusive(
    PFILE_OBJECT FileObject
);

NTSYSAPI NTSTATUS RtlAppendStringToString(
    [in, out] PSTRING Destination,
    [in] const STRING *Source
);

NTSYSAPI NTSTATUS RtlAddAccessAllowedAceEx(
    [in, out] PACL Acl,
    [in] ULONG AceRevision,
    [in] ULONG AceFlags,
    [in] ACCESS_MASK AccessMask,
    [in] PSID Sid
);

NTSYSAPI PUCHAR RtlSubAuthorityCountSid(
    PSID Sid
);

NTSTATUS FsRtlGetFileSize(
    [in] PFILE_OBJECT FileObject,
    [out] PLARGE_INTEGER FileSize
);

NTSTATUS SeSetSecurityDescriptorInfoEx(
    [in, optional] PVOID Object,
    [in] PSECURITY_INFORMATION SecurityInformation,
    PSECURITY_DESCRIPTOR ModificationDescriptor,
    [in, out] PSECURITY_DESCRIPTOR *ObjectsSecurityDescriptor,
    [in] ULONG AutoInheritFlags,
    [in] POOL_TYPE PoolType,
    [in] PGENERIC_MAPPING GenericMapping
);

NTSTATUS FsRtlValidateReparsePointBuffer(
    [in] ULONG BufferLength,
    [in] PREPARSE_DATA_BUFFER ReparseBuffer
);

void FsRtlIsAnsiCharacterLegalFat(
    C,
    WILD_OK
);

BOOLEAN FsRtlAreNamesEqual(
    [in] PCUNICODE_STRING ConstantNameA,
    [in] PCUNICODE_STRING ConstantNameB,
    [in] BOOLEAN IgnoreCase,
    [in, optional] PCWCH UpcaseTable
);

void FsRtlGetBypassIoOpenCount(
    _fo
);

void IoSetTopLevelIrp(
    [in, optional] PIRP Irp
);

NTSTATUS IoSetInformation(
    PFILE_OBJECT FileObject,
    FILE_INFORMATION_CLASS FileInformationClass,
    ULONG Length,
    PVOID FileInformation
);

NTSYSAPI NTSTATUS ZwLockFile(
    [in] HANDLE FileHandle,
    [in, optional] HANDLE Event,
    [in, optional] PIO_APC_ROUTINE ApcRoutine,
    [in, optional] PVOID ApcContext,
    [out] PIO_STATUS_BLOCK IoStatusBlock,
    [in] PLARGE_INTEGER ByteOffset,
    [in] PLARGE_INTEGER Length,
    [in] ULONG Key,
    [in] BOOLEAN FailImmediately,
    [in] BOOLEAN ExclusiveLock
);

__kernel_entry NTSYSCALLAPI NTSTATUS NtFsControlFile(
    [in] HANDLE FileHandle,
    [in, optional] HANDLE Event,
    [in, optional] PIO_APC_ROUTINE ApcRoutine,
    [in, optional] PVOID ApcContext,
    [out] PIO_STATUS_BLOCK IoStatusBlock,
    [in] ULONG FsControlCode,
    [in, optional] PVOID InputBuffer,
    [in] ULONG InputBufferLength,
    [out, optional] PVOID OutputBuffer,
    [in] ULONG OutputBufferLength
);

NTSYSAPI NTSTATUS RtlIsPartialPlaceholderFileHandle(
    [in] HANDLE FileHandle,
    [out] PBOOLEAN IsPartialPlaceholder
);

void FsRtlTeardownPerFileContexts(
    [in] PVOID *PerFileContextPointer
);

__kernel_entry NTSYSCALLAPI NTSTATUS NtCreateSection(
    [out] PHANDLE SectionHandle,
    [in] ACCESS_MASK DesiredAccess,
    [in, optional] POBJECT_ATTRIBUTES ObjectAttributes,
    [in, optional] PLARGE_INTEGER MaximumSize,
    [in] ULONG SectionPageProtection,
    [in] ULONG AllocationAttributes,
    [in, optional] HANDLE FileHandle
);

BOOLEAN SeTokenIsRestricted(
    [in] PACCESS_TOKEN Token
);

void FsRtlCompleteRequest(
    IRP,
    STATUS
);

__kernel_entry NTSYSCALLAPI NTSTATUS NtCopyFileChunk(
    [in] HANDLE SourceHandle,
    [in] HANDLE DestHandle,
    [in, optional] HANDLE Event,
    [out] PIO_STATUS_BLOCK IoStatusBlock,
    [in] ULONG Length,
    [in] PLARGE_INTEGER SourceOffset,
    [in] PLARGE_INTEGER DestOffset,
    [in, optional] PULONG SourceKey,
    [in, optional] PULONG DestKey,
    [in] ULONG Flags
);

BOOLEAN
    FsRtlFastLock( A1, /* FileLock */
    A2, /* FileObject */
    A3, /* FileOffset */
    A4, /* Length */
    A5, /* ProcessId */
    A6, /* Key */
    A7, /* FailImmediately */
    A8, /* ExclusiveLock */
    A9, /* Iosb */
    A10, /* Context */
A11 /* AlreadySynchronized */ );

void FsRtlSetupAdvancedHeaderEx2(
    _advhdr,
    _fmutx,
    _fctxptr,
    _aepushlock
);

PDEVICE_OBJECT IoGetBaseFileSystemDeviceObject(
    PFILE_OBJECT FileObject
);

PCONFIGURATION_INFORMATION IoGetConfigurationInformation();

NTSTATUS IoRegisterFsRegistrationChangeMountAware(
    [in] PDRIVER_OBJECT DriverObject,
    [in] PDRIVER_FS_NOTIFICATION DriverNotificationRoutine,
    [in] BOOLEAN SynchronizeWithMounts
);

NTSTATUS FsRtlGetSupportedFeatures(
    [in] PDEVICE_OBJECT DeviceObject,
    [out] PULONG SupportedFeatures
);

NTSTATUS FsRtlGetSectorSizeInformation(
    PDEVICE_OBJECT DeviceObject,
    [out] PFILE_FS_SECTOR_SIZE_INFORMATION SectorSizeInfo
);

NTSYSAPI NTSTATUS RtlDescribeChunk(
    USHORT CompressionFormat,
    PUCHAR *CompressedBuffer,
    PUCHAR EndOfCompressedBufferPlus1,
    PUCHAR *ChunkBuffer,
    PULONG ChunkSize
);

void KeUnstackDetachProcess(
    [in] PRKAPC_STATE ApcState
);

NTSTATUS FsRtlCheckUpperOplock(
    [in] POPLOCK Oplock,
    [in] ULONG NewLowerOplockState,
    [in, optional] PVOID CompletionRoutineContext,
    [in, optional] POPLOCK_WAIT_COMPLETE_ROUTINE CompletionRoutine,
    POPLOCK_FS_PREPOST_IRP PrePendRoutine,
    [in] ULONG Flags
);

PETHREAD PsGetCurrentThread();

BOOLEAN CcUninitializeCacheMap(
    [in] PFILE_OBJECT FileObject,
    [in, optional] PLARGE_INTEGER TruncateSize,
    PCACHE_UNINITIALIZE_EVENT UninitializeEvent
);

NTSTATUS FsRtlRegisterFileSystemFilterCallbacks(
    [in] _DRIVER_OBJECT *FilterDriverObject,
    [in] PFS_FILTER_CALLBACKS Callbacks
);

NTSTATUS FsRtlAllocateExtraCreateParameter(
    [in] LPCGUID EcpType,
    [in] ULONG SizeOfContext,
    [in] FSRTL_ALLOCATE_ECP_FLAGS Flags,
    [in, optional] PFSRTL_EXTRA_CREATE_PARAMETER_CLEANUP_CALLBACK CleanupCallback,
    [in] ULONG PoolTag,
    [out] PVOID *EcpContext
);

void CcCoherencyFlushAndPurgeCache(
    [in] PSECTION_OBJECT_POINTERS SectionObjectPointer,
    [in, optional] PLARGE_INTEGER FileOffset,
    [in] ULONG Length,
    [out] PIO_STATUS_BLOCK IoStatus,
    [in, optional] ULONG Flags
);

void IoSetStartIoAttributes(
    [in] PDEVICE_OBJECT DeviceObject,
    [in] BOOLEAN DeferredStartIo,
    [in] BOOLEAN NonCancelable
);

NTSYSAPI VOID RtlSecondsSince1970ToTime(
    [in] ULONG ElapsedSeconds,
    [out] PLARGE_INTEGER Time
);

void CcUnregisterExternalCacheEx(
    PVOID ExternalCacheContext
);

BOOLEAN FsRtlAreThereWaitingFileLocks(
    [in] PFILE_LOCK FileLock
);

NTSYSAPI BOOLEAN RtlEqualPrefixSid(
    [in] PSID Sid1,
    [in] PSID Sid2
);

BOOLEAN FsRtlAreThereCurrentOrInProgressFileLocks(
    [in] PFILE_LOCK FileLock
);

NTSYSAPI NTSTATUS ZwSetEvent(
    [in] HANDLE EventHandle,
    [out, optional] PLONG PreviousState
);

BOOLEAN SePrivilegeCheck(
    [in, out] PPRIVILEGE_SET RequiredPrivileges,
    [in] PSECURITY_SUBJECT_CONTEXT SubjectSecurityContext,
    [in] KPROCESSOR_MODE AccessMode
);

BOOLEAN CcMapData(
    [in] PFILE_OBJECT FileObject,
    [in] PLARGE_INTEGER FileOffset,
    [in] ULONG Length,
    [in] ULONG Flags,
    [out] PVOID *Bcb,
    [out] PVOID *Buffer
);

BOOLEAN FsRtlCurrentOplockH(
    [in] POPLOCK Oplock
);

void PsReturnPoolQuota(
    [in] PEPROCESS Process,
    [in] POOL_TYPE PoolType,
    [in] ULONG_PTR Amount
);

NTSTATUS IoCheckEaBufferValidity(
    [in] PFILE_FULL_EA_INFORMATION EaBuffer,
    [in] ULONG EaLength,
    [out] PULONG ErrorOffset
);

BOOLEAN FsRtlInitializeBaseMcbEx(
    PBASE_MCB Mcb,
    POOL_TYPE PoolType,
    USHORT Flags
);

void KeStackAttachProcess(
    PRKPROCESS PROCESS,
    [out] PRKAPC_STATE ApcState
);

__kernel_entry NTSYSCALLAPI NTSTATUS NtCreateSectionEx(
    [out] PHANDLE SectionHandle,
    [in] ACCESS_MASK DesiredAccess,
    [in, optional] POBJECT_ATTRIBUTES ObjectAttributes,
    [in, optional] PLARGE_INTEGER MaximumSize,
    [in] ULONG SectionPageProtection,
    [in] ULONG AllocationAttributes,
    [in, optional] HANDLE FileHandle,
    [in/out] PMEM_EXTENDED_PARAMETER ExtendedParameters,
    ULONG ExtendedParameterCount
);

LARGE_INTEGER PsGetProcessExitTime();

NTSTATUS SeQuerySecurityDescriptorInfo(
    [in] PSECURITY_INFORMATION SecurityInformation,
    [out] PSECURITY_DESCRIPTOR SecurityDescriptor,
    [in, out] PULONG Length,
    [in, out] PSECURITY_DESCRIPTOR *ObjectsSecurityDescriptor
);

PFILE_OBJECT CcGetFileObjectFromBcb(
    [in] PVOID Bcb
);

BOOLEAN FsRtlIsNtstatusExpected(
    [in] NTSTATUS Exception
);

LONG KeReadStateMutant(
    PRKMUTANT Mutant
);

__kernel_entry NTSYSCALLAPI NTSTATUS NtOpenThreadToken(
    [in] HANDLE ThreadHandle,
    [in] ACCESS_MASK DesiredAccess,
    [in] BOOLEAN OpenAsSelf,
    [out] PHANDLE TokenHandle
);

NTSYSAPI NTSTATUS RtlUnicodeToUTF8N(
    [out] PCHAR UTF8StringDestination,
    [in] ULONG UTF8StringMaxByteCount,
    [out] PULONG UTF8StringActualByteCount,
    [in] PCWCH UnicodeStringSource,
    [in] ULONG UnicodeStringByteCount
);

PDEVICE_OBJECT IoGetAttachedDeviceReference(
    [in] PDEVICE_OBJECT DeviceObject
);

void CcSetAdditionalCacheAttributesEx(
    [in] PFILE_OBJECT FileObject,
    [in] ULONG Flags
);

void IoStartTimer(
    [in] PDEVICE_OBJECT DeviceObject
);

void SeUnlockSubjectContext(
    [in] PSECURITY_SUBJECT_CONTEXT SubjectContext
);

TOKEN_TYPE SeTokenType(
    PACCESS_TOKEN Token
);

NTSYSAPI NTSTATUS ZwFlushBuffersFileEx(
    [in] HANDLE FileHandle,
    ULONG FLags,
    PVOID Parameters,
    ULONG ParametersSize,
    [out] PIO_STATUS_BLOCK IoStatusBlock
);

BOOLEAN FsRtlLookupBaseMcbEntry(
    PBASE_MCB Mcb,
    LONGLONG Vbn,
    PLONGLONG Lbn,
    PLONGLONG SectorCountFromLbn,
    PLONGLONG StartingLbn,
    PLONGLONG SectorCountFromStartingLbn,
    PULONG Index
);

NTSYSAPI NTSTATUS RtlCreateSystemVolumeInformationFolder(
    [in] PCUNICODE_STRING VolumeRootPath
);

void SeFreePrivileges(
    [in] PPRIVILEGE_SET Privileges
);

PULONG PoRegisterDeviceForIdleDetection(
    [in] PDEVICE_OBJECT DeviceObject,
    [in] ULONG ConservationIdleTime,
    [in] ULONG PerformanceIdleTime,
    [in] DEVICE_POWER_STATE State
);

NTSYSAPI VOID RtlRemoveUnicodePrefix(
    [in] PUNICODE_PREFIX_TABLE PrefixTable,
    [in] PUNICODE_PREFIX_TABLE_ENTRY PrefixTableEntry
);

NTSYSAPI NTSTATUS RtlUpcaseUnicodeStringToOemString(
    POEM_STRING DestinationString,
    [in] PCUNICODE_STRING SourceString,
    [in] BOOLEAN AllocateDestinationString
);

void CcScheduleReadAhead(
    [in] PFILE_OBJECT FileObject,
    [in] PLARGE_INTEGER FileOffset,
    [in] ULONG Length
);

NTSYSAPI NTSTATUS RtlDeleteAce(
    [in, out] PACL Acl,
    [in] ULONG AceIndex
);

void PoStartDeviceBusy(
    [in, out] PULONG IdlePointer
);

BOOLEAN CcCanIWrite(
    [in] PFILE_OBJECT FileObject,
    [in] ULONG BytesToWrite,
    [in] BOOLEAN Wait,
    [in] UCHAR Retrying
);

BOOLEAN FsRtlOplockKeysEqual(
    [in, optional] PFILE_OBJECT Fo1,
    [in, optional] PFILE_OBJECT Fo2
);

KSECDDDECLSPEC NTSTATUS SecMakeSPNEx(
    [in] IN PUNICODE_STRING ServiceClass,
    [in] IN PUNICODE_STRING ServiceName,
    [in] IN PUNICODE_STRING InstanceName,
    [in, optional] IN USHORT InstancePort,
    [in, optional] IN PUNICODE_STRING Referrer,
    [in, optional] IN PUNICODE_STRING TargetInfo,
    [in, out] IN OUT PUNICODE_STRING Spn,
    [out, optional] OUT PULONG Length,
    [in] IN BOOLEAN Allocate
);

__kernel_entry NTSYSCALLAPI NTSTATUS NtQueryInformationByName(
    [in] POBJECT_ATTRIBUTES ObjectAttributes,
    [out] PIO_STATUS_BLOCK IoStatusBlock,
    [out] PVOID FileInformation,
    [in] ULONG Length,
    [in] FILE_INFORMATION_CLASS FileInformationClass
);

BOOLEAN FsRtlOplockIsFastIoPossible(
    [in] POPLOCK Oplock
);

void FsRtlIncrementCcFastReadNotPossible();

NT_RTL_COMPRESS_API NTSTATUS RtlDecompressBufferEx(
    [in] USHORT CompressionFormat,
    [out] PUCHAR UncompressedBuffer,
    [in] ULONG UncompressedBufferSize,
    [in] PUCHAR CompressedBuffer,
    [in] ULONG CompressedBufferSize,
    [out] PULONG FinalUncompressedSize,
    [in] PVOID WorkSpace
);

NTSTATUS FsRtlCancellableWaitForMultipleObjects(
    [in] ULONG Count,
    [in] PVOID [] ObjectArray,
    [in] WAIT_TYPE WaitType,
    [in, optional] PLARGE_INTEGER Timeout,
    [in, optional] PKWAIT_BLOCK WaitBlockArray,
    [in, optional] PIRP Irp
);

NTSYSAPI NTSTATUS RtlGetDaclSecurityDescriptor(
    [in] PSECURITY_DESCRIPTOR SecurityDescriptor,
    [out] PBOOLEAN DaclPresent,
    [out] PACL *Dacl,
    [out] PBOOLEAN DaclDefaulted
);

NTSYSAPI NTSTATUS RtlUpcaseUnicodeToOemN(
    [out] PCHAR OemString,
    [in] ULONG MaxBytesInOemString,
    [out, optional] PULONG BytesInOemString,
    [in] PCWCH UnicodeString,
    [in] ULONG BytesInUnicodeString
);

NTSTATUS FsRtlInsertPerFileObjectContext(
    [in] PFILE_OBJECT FileObject,
    [in] PFSRTL_PER_FILEOBJECT_CONTEXT Ptr
);

void CcMdlWriteAbort(
    [in] PFILE_OBJECT FileObject,
    [in] PMDL MdlChain
);

BOOLEAN IoIsValidNameGraftingBuffer(
    PIRP Irp,
    PREPARSE_DATA_BUFFER ReparseBuffer
);

NTSTATUS FsRtlUpperOplockFsctrl(
    [in] POPLOCK Oplock,
    [in] PIRP Irp,
    [in] ULONG OpenCount,
    [in] ULONG LowerOplockState,
    [in] ULONG Flags
);

void KeReleaseQueuedSpinLock(
    KSPIN_LOCK_QUEUE_NUMBER Number,
    KIRQL OldIrql
);

NTSTATUS SeCreateClientSecurityFromSubjectContext(
    [in] PSECURITY_SUBJECT_CONTEXT SubjectContext,
    [in] PSECURITY_QUALITY_OF_SERVICE ClientSecurityQos,
    [in] BOOLEAN ServerIsRemote,
    [out] PSECURITY_CLIENT_CONTEXT ClientContext
);

void PsRevertToSelf();

BOOLEAN FsRtlMdlReadCompleteDev(
    [in] PFILE_OBJECT FileObject,
    [in] PMDL MdlChain,
    [ in, optional ] PDEVICE_OBJECT DeviceObject
);

BOOLEAN IoIsSystemThread(
    [in] PETHREAD Thread
);

LARGE_INTEGER CcGetFlushedValidData(
    [in] PSECTION_OBJECT_POINTERS SectionObjectPointer,
    [in] BOOLEAN BcbListHeld
);

void CcSetAdditionalCacheAttributes(
    [in] PFILE_OBJECT FileObject,
    [in] BOOLEAN DisableReadAhead,
    [in] BOOLEAN DisableWriteBehind
);

PFILE_OBJECT IoCreateStreamFileObjectEx(
    [in, optional] PFILE_OBJECT FileObject,
    [in, optional] PDEVICE_OBJECT DeviceObject,
    [out, optional] PHANDLE FileHandle
);

void FsRtlUninitializeFileLock(
    [in] PFILE_LOCK FileLock
);

void SeLockSubjectContext(
    [in] PSECURITY_SUBJECT_CONTEXT SubjectContext
);

NTSYSAPI NTSTATUS ZwFlushVirtualMemory(
    [in] HANDLE ProcessHandle,
    [in, out] PVOID *BaseAddress,
    [in, out] PSIZE_T RegionSize,
    [out] PIO_STATUS_BLOCK IoStatus
);

NTSYSAPI NTSTATUS RtlDowncaseUnicodeString(
    PUNICODE_STRING DestinationString,
    [in] PCUNICODE_STRING SourceString,
    [in] BOOLEAN AllocateDestinationString
);

LONG KeInsertQueue(
    [in, out] PRKQUEUE Queue,
    [in, out] PLIST_ENTRY Entry
);

void RtlOemStringToCountedUnicodeSize(
    STRING
);

NTSYSAPI CHAR RtlQueryProcessPlaceholderCompatibilityMode();

NTSTATUS FsRtlOplockBreakToNoneEx(
    [in, out] POPLOCK Oplock,
    [in] PIRP Irp,
    [in] ULONG Flags,
    [in, optional] PVOID Context,
    [in, optional] POPLOCK_WAIT_COMPLETE_ROUTINE CompletionRoutine,
    [in, optional] POPLOCK_FS_PREPOST_IRP PostIrpRoutine
);

void CcUnpinRepinnedBcb(
    [in] PVOID Bcb,
    [in] BOOLEAN WriteThrough,
    [out] PIO_STATUS_BLOCK IoStatus
);

NTSTATUS FsRtlOplockFsctrlEx(
    [in] POPLOCK Oplock,
    [in] PIRP Irp,
    [in] ULONG OpenCount,
    [in] ULONG Flags
);

NTSTATUS FsRtlMupGetProviderIdFromName(
    [in] PCUNICODE_STRING pProviderName,
    [out] PULONG32 pProviderId
);

PFILE_LOCK FsRtlAllocateFileLock(
    [in, optional] PCOMPLETE_LOCK_IRP_ROUTINE CompleteLockIrpRoutine,
    [in, optional] PUNLOCK_ROUTINE UnlockRoutine
);

NTSTATUS ZwQueryEaFile(
    [in] HANDLE FileHandle,
    [out] PIO_STATUS_BLOCK IoStatusBlock,
    [out] PVOID Buffer,
    [in] ULONG Length,
    [in] BOOLEAN ReturnSingleEntry,
    [in, optional] PVOID EaList,
    [in] ULONG EaListLength,
    [in, optional] PULONG EaIndex,
    [in] BOOLEAN RestartScan
);

PFSRTL_PER_STREAM_CONTEXT FsRtlRemovePerStreamContext(
    [in] PFSRTL_ADVANCED_FCB_HEADER StreamContext,
    [in, optional] PVOID OwnerId,
    [in, optional] PVOID InstanceId
);

void KeDetachProcess();

NTSTATUS SeLocateProcessImageName(
    PEPROCESS Process,
    PUNICODE_STRING *pImageFileName
);

PFILE_OBJECT IoCreateStreamFileObject(
    [in, optional] PFILE_OBJECT FileObject,
    [in, optional] PDEVICE_OBJECT DeviceObject
);

void FsRtlFreeAePushLock(
    [in] PVOID AePushLock
);

BOOLEAN FsRtlIsNameInUnUpcasedExpression(
    PUNICODE_STRING Expression,
    PUNICODE_STRING Name,
    BOOLEAN IgnoreCase,
    PWCH UpcaseTable
);

ULONG FsRtlNumberOfRunsInMcb(
    PMCB Mcb
);

BOOLEAN FsRtlLookupMcbEntry(
    PMCB Mcb,
    VBN Vbn,
    PLBN Lbn,
    PULONG SectorCount,
    PULONG Index
);

NT_RTL_COMPRESS_API NTSTATUS RtlDecompressFragment(
    [in] USHORT CompressionFormat,
    [out] PUCHAR UncompressedFragment,
    [in] ULONG UncompressedFragmentSize,
    [in] PUCHAR CompressedBuffer,
    [in] ULONG CompressedBufferSize,
    [in] ULONG FragmentOffset,
    [out] PULONG FinalUncompressedSize,
    [in] PVOID WorkSpace
);

void RtlUnicodeStringToOemSize(
    STRING
);

void FsRtlNotifyUninitializeSync(
    [in] PNOTIFY_SYNC *NotifySync
);

PERESOURCE FsRtlAllocateResource();

void IsReparseTagReserved(
    _tag
);

BOOLEAN FsRtlPrepareMdlWriteDev(
    [in] PFILE_OBJECT FileObject,
    [in] PLARGE_INTEGER FileOffset,
    [in] ULONG Length,
    [in] ULONG LockKey,
    [out] PMDL *MdlChain,
    [out] PIO_STATUS_BLOCK IoStatus,
    [ in, optional ] PDEVICE_OBJECT DeviceObject
);

POWER_STATE PoSetPowerState(
    [in] PDEVICE_OBJECT DeviceObject,
    [in] POWER_STATE_TYPE Type,
    [in] POWER_STATE State
);

NTSYSAPI PVOID RtlAllocateHeap(
    [in] PVOID HeapHandle,
    [in, optional] ULONG Flags,
    [in] SIZE_T Size
);

NTSYSAPI BOOLEAN RtlIsValidOemCharacter(
    [in, out] PWCHAR Char
);

void IoStopTimer(
    [in] PDEVICE_OBJECT DeviceObject
);

void FsRtlIncrementCcFastReadWait();

NTSTATUS FsRtlFastUnlockAll(
    [in] PFILE_LOCK FileLock,
    [in] PFILE_OBJECT FileObject,
    [in] PEPROCESS ProcessId,
    [in, optional] PVOID Context
);

NTSYSAPI NTSTATUS RtlInitUTF8StringEx(
    PUTF8_STRING DestinationString,
    __drv_aliasesMem PCSZ SourceString
);

void RtlOemStringToUnicodeSize(
    STRING
);

NTSTATUS IoEnumerateDeviceObjectList(
    [in] PDRIVER_OBJECT DriverObject,
    [out] PDEVICE_OBJECT *DeviceObjectList,
    [in] ULONG DeviceObjectListSize,
    [out] PULONG ActualNumberDeviceObjects
);

NTSYSAPI NTSTATUS ZwQueryInformationToken(
    [in] HANDLE TokenHandle,
    [in] TOKEN_INFORMATION_CLASS TokenInformationClass,
    [out] PVOID TokenInformation,
    [in] ULONG TokenInformationLength,
    [out] PULONG ReturnLength
);

NTSYSAPI NTSTATUS RtlQueryPackageIdentityEx(
    PVOID TokenObject,
    PWSTR PackageFullName,
    PSIZE_T PackageSize,
    PWSTR AppId,
    PSIZE_T AppIdSize,
    LPGUID DynamicId,
    PULONG64 Flags
);

PDEVICE_OBJECT IoGetLowerDeviceObject(
    [in] PDEVICE_OBJECT DeviceObject
);

void IsReparseTagMicrosoft(
    [in] _tag
);

void CcSetBcbOwnerPointer(
    [in] PVOID Bcb,
    [in] PVOID OwnerPointer
);

void FsRtlNotifyCleanupAll(
    [in] PNOTIFY_SYNC NotifySync,
    [in] PLIST_ENTRY NotifyList
);

ULONG FsRtlNumberOfRunsInLargeMcb(
    PLARGE_MCB Mcb
);

BOOLEAN FsRtlCopyRead(
    [in] PFILE_OBJECT FileObject,
    [in] PLARGE_INTEGER FileOffset,
    [in] ULONG Length,
    [in] BOOLEAN Wait,
    [in] ULONG LockKey,
    [out] PVOID Buffer,
    [out] PIO_STATUS_BLOCK IoStatus,
    [in] PDEVICE_OBJECT DeviceObject
);

PFILE_LOCK_INFO FsRtlGetNextFileLock(
    [in] PFILE_LOCK FileLock,
    [in] BOOLEAN Restart
);

LONG KeInsertHeadQueue(
    [in, out] PRKQUEUE Queue,
    [in, out] PLIST_ENTRY Entry
);

NTSYSAPI NTSTATUS RtlCompressChunks(
    PUCHAR UncompressedBuffer,
    ULONG UncompressedBufferSize,
    PUCHAR CompressedBuffer,
    ULONG CompressedBufferSize,
    PCOMPRESSED_DATA_INFO CompressedDataInfo,
    ULONG CompressedDataInfoLength,
    PVOID WorkSpace
);

BOOLEAN FsRtlLookupLastMcbEntry(
    PMCB Mcb,
    PVBN Vbn,
    PLBN Lbn
);

BOOLEAN FsRtlFindInTunnelCache(
    [in] TUNNEL *Cache,
    ULONGLONG DirectoryKey,
    [in] UNICODE_STRING *Name,
    [out] UNICODE_STRING *ShortName,
    [out] UNICODE_STRING *LongName,
    [in, out] ULONG *DataLength,
    [out] VOID *Data
);

ULONGLONG MmGetMaximumFileSectionSize();

NTSTATUS FsRtlPrepareMdlWriteEx(
    [in] PFILE_OBJECT FileObject,
    [in] PLARGE_INTEGER FileOffset,
    [in] ULONG Length,
    [in] ULONG LockKey,
    [out] PMDL *MdlChain,
    [out] PIO_STATUS_BLOCK IoStatus
);

NTSTATUS IoQueryFileDosDeviceName(
    [in] PFILE_OBJECT FileObject,
    [out] POBJECT_NAME_INFORMATION *ObjectNameInformation
);

void FsRtlIsAnsiCharacterLegalNtfs(
    C,
    WILD_OK
);

void IoInitializePriorityInfo(
    [in] PIO_PRIORITY_INFO PriorityInfo
);

PEPROCESS IoThreadToProcess(
    [in] PETHREAD Thread
);

NTSYSAPI PUNICODE_PREFIX_TABLE_ENTRY RtlFindUnicodePrefix(
    [in] PUNICODE_PREFIX_TABLE PrefixTable,
    [in] PCUNICODE_STRING FullName,
    [in] ULONG CaseInsensitiveIndex
);

NTSYSAPI NTSTATUS RtlMultiByteToUnicodeN(
    [out] PWCH UnicodeString,
    [in] ULONG MaxBytesInUnicodeString,
    [out, optional] PULONG BytesInUnicodeString,
    [in] const CHAR *MultiByteString,
    [in] ULONG BytesInMultiByteString
);

void FsRtlInitPerStreamContext(
    _fc,
    _owner,
    _inst,
    _cb
);

BOOLEAN FsRtlIsEcpAcknowledged(
    [in] PVOID EcpContext
);

void KeAttachProcess(
    PRKPROCESS Process
);

PEPROCESS IoGetRequestorProcess(
    [in] PIRP Irp
);

__kernel_entry NTSYSCALLAPI NTSTATUS NtQueryObject(
    [in, optional] HANDLE Handle,
    [in] OBJECT_INFORMATION_CLASS ObjectInformationClass,
    [out, optional] PVOID ObjectInformation,
    [in] ULONG ObjectInformationLength,
    [out, optional] PULONG ReturnLength
);

void SeOpenObjectForDeleteAuditAlarm(
    [in] PUNICODE_STRING ObjectTypeName,
    [in, optional] PVOID Object,
    [in, optional] PUNICODE_STRING AbsoluteObjectName,
    [in] PSECURITY_DESCRIPTOR SecurityDescriptor,
    [in] PACCESS_STATE AccessState,
    [in] BOOLEAN ObjectCreated,
    [in] BOOLEAN AccessGranted,
    [in] KPROCESSOR_MODE AccessMode,
    [out] PBOOLEAN GenerateOnClose
);

NTSTATUS FsRtlProcessFileLock(
    [in] PFILE_LOCK FileLock,
    [in] PIRP Irp,
    [in, optional] PVOID Context
);

void PoEndDeviceBusy(
    [in, out] PULONG IdlePointer
);

void RtlFillMemoryUlonglong(
    [out] Destination,
    [in] Length,
    [in] Pattern
);

void FsRtlSetupAdvancedHeader(
    PVOID AdvHdr,
    PFAST_MUTEX FMutex
);

__kernel_entry NTSYSCALLAPI NTSTATUS NtQueryVolumeInformationFile(
    [in] HANDLE FileHandle,
    [out] PIO_STATUS_BLOCK IoStatusBlock,
    [out] PVOID FsInformation,
    [in] ULONG Length,
    [in] FS_INFORMATION_CLASS FsInformationClass
);

BOOLEAN MmForceSectionClosed(
    [in] PSECTION_OBJECT_POINTERS SectionObjectPointer,
    [in] BOOLEAN DelayClose
);

BOOLEAN CcPinRead(
    [in] PFILE_OBJECT FileObject,
    [in] PLARGE_INTEGER FileOffset,
    [in] ULONG Length,
    [in] ULONG Flags,
    [out] PVOID *Bcb,
    [out] PVOID *Buffer
);

void FsRtlSetupAdvancedHeaderEx(
    _advhdr,
    _fmutx,
    _fctxptr
);

NTSYSAPI NTSTATUS ZwQueryQuotaInformationFile(
    [in] HANDLE FileHandle,
    [out] PIO_STATUS_BLOCK IoStatusBlock,
    [out] PVOID Buffer,
    [in] ULONG Length,
    [in] BOOLEAN ReturnSingleEntry,
    [in, optional] PVOID SidList,
    [in] ULONG SidListLength,
    [in, optional] PSID StartSid,
    [in] BOOLEAN RestartScan
);

BOOLEAN PsIsSystemThread(
    [in] PETHREAD Thread
);

void FsRtlLookupPerStreamContext(
    _sc,
    _oid,
    _iid
);

BOOLEAN SeAuditingHardLinkEvents(
    BOOLEAN AccessGranted,
    PSECURITY_DESCRIPTOR SecurityDescriptor
);

NTSTATUS FsRtlKernelFsControlFile(
    [in] PFILE_OBJECT FileObject,
    [in] ULONG FsControlCode,
    [in] PVOID InputBuffer,
    [in] ULONG InputBufferLength,
    [out] PVOID OutputBuffer,
    [out] ULONG OutputBufferLength,
    [out] PULONG RetOutputBufferSize
);

void IoSetDeviceToVerify(
    [in] PETHREAD Thread,
    [in, optional] PDEVICE_OBJECT DeviceObject
);

NTSTATUS SeQueryAuthenticationIdToken(
    [in] PACCESS_TOKEN Token,
    [out] PLUID AuthenticationId
);

void IoSizeOfIrp(
    StackSize
);

NTSYSAPI NTSTATUS RtlIsPartialPlaceholderFileInfo(
    [in] const VOID *InfoBuffer,
    [in] FILE_INFORMATION_CLASS InfoClass,
    [out] PBOOLEAN IsPartialPlaceholder
);

BOOLEAN FsRtlCurrentBatchOplock(
    [in] POPLOCK Oplock
);

BOOLEAN IoCheckFileObjectOpenedAsCopySource(
    [in] PFILE_OBJECT FileObject
);

__kernel_entry NTSYSCALLAPI NTSTATUS NtClose(
    [in] HANDLE Handle
);

void PoSetDeviceBusyEx(
    [in, out] PULONG IdlePointer
);

void FsRtlIsAnsiCharacterLegalHpfs(
    C,
    WILD_OK
);

NTSTATUS ZwSetEaFile(
    [in] HANDLE FileHandle,
    [out] PIO_STATUS_BLOCK IoStatusBlock,
    [in] PVOID Buffer,
    [in] ULONG Length
);

SECURITY_STATUS SEC_ENTRY SecAllocateAndSetCallTarget(
    PUCHAR lpIpAddress,
    ULONG cchIpAddress,
    LPWSTR TargetName,
    int *FreeCallContext
);

void FsRtlTruncateMcb(
    PMCB Mcb,
    VBN Vbn
);

NTSYSAPI NTSTATUS ZwOpenDirectoryObject(
    [out] PHANDLE DirectoryHandle,
    [in] ACCESS_MASK DesiredAccess,
    [in] POBJECT_ATTRIBUTES ObjectAttributes
);

void IoStartPacket(
    [in] PDEVICE_OBJECT DeviceObject,
    [in] PIRP Irp,
    [in, optional] PULONG Key,
    [in, optional] PDRIVER_CANCEL CancelFunction
);

BOOLEAN FsRtlMdlWriteCompleteDev(
    [in] PFILE_OBJECT FileObject,
    [in] PLARGE_INTEGER FileOffset,
    [in] PMDL MdlChain,
    [ in, optional ] PDEVICE_OBJECT DeviceObject
);

__kernel_entry NTSYSCALLAPI NTSTATUS NtQueryDirectoryFile(
    [in] HANDLE FileHandle,
    [in, optional] HANDLE Event,
    [in, optional] PIO_APC_ROUTINE ApcRoutine,
    [in, optional] PVOID ApcContext,
    [out] PIO_STATUS_BLOCK IoStatusBlock,
    [out] PVOID FileInformation,
    [in] ULONG Length,
    [in] FILE_INFORMATION_CLASS FileInformationClass,
    [in] BOOLEAN ReturnSingleEntry,
    [in, optional] PUNICODE_STRING FileName,
    [in] BOOLEAN RestartScan
);

void FsRtlAcknowledgeEcp(
    [in] PVOID EcpContext
);

void RtlFillMemoryUlong(
    [out] PVOID Destination,
    [in] SIZE_T Length,
    [in] ULONG Pattern
);

NTSYSAPI NTSTATUS RtlUnicodeToMultiByteN(
    [out] PCHAR MultiByteString,
    [in] ULONG MaxBytesInMultiByteString,
    [out, optional] PULONG BytesInMultiByteString,
    [in] PCWCH UnicodeString,
    [in] ULONG BytesInUnicodeString
);

void FsRtlAllocatePoolWithTag(
    [in] PoolType,
    [in] NumberOfBytes,
    [in] Tag
);

void FsRtlInitExtraCreateParameterLookasideList(
    [in, out] PVOID Lookaside,
    [in] FSRTL_ECP_LOOKASIDE_FLAGS Flags,
    [in] SIZE_T Size,
    [in] ULONG Tag
);

ULONG KeGetProcessorIndexFromNumber(
    [in] PPROCESSOR_NUMBER ProcNumber
);

NTSTATUS IoCheckQuotaBufferValidity(
    [in] PFILE_QUOTA_INFORMATION QuotaBuffer,
    [in] ULONG QuotaLength,
    [out] PULONG ErrorOffset
);

__kernel_entry NTSYSCALLAPI NTSTATUS NtPrivilegeCheck(
    [in] HANDLE ClientToken,
    [in, out] PPRIVILEGE_SET RequiredPrivileges,
    [out] PBOOLEAN Result
);

BOOLEAN CcPurgeCacheSection(
    [in] PSECTION_OBJECT_POINTERS SectionObjectPointer,
    [in, optional] PLARGE_INTEGER FileOffset,
    [in] ULONG Length,
    ULONG Flags
);

NTSTATUS CcSetCacheFileSizes(
    [in] PSECTION_OBJECT_POINTERS SectionObjectPointer,
    [in] PCC_FILE_SIZES FileSizes
);

__kernel_entry NTSYSCALLAPI NTSTATUS NtOpenFile(
    [out] PHANDLE FileHandle,
    [in] ACCESS_MASK DesiredAccess,
    [in] POBJECT_ATTRIBUTES ObjectAttributes,
    [out] PIO_STATUS_BLOCK IoStatusBlock,
    [in] ULONG ShareAccess,
    [in] ULONG OpenOptions
);

BOOLEAN CcPreparePinWrite(
    [in] PFILE_OBJECT FileObject,
    [in] PLARGE_INTEGER FileOffset,
    [in] ULONG Length,
    [in] BOOLEAN Zero,
    [in] ULONG Flags,
    [out] PVOID *Bcb,
    [out] PVOID *Buffer
);

NTSYSAPI NTSTATUS RtlCopySid(
    [in] ULONG DestinationSidLength,
    [in] PSID DestinationSid,
    [in] PSID SourceSid
);

BOOLEAN MmForceSectionClosedEx(
    PSECTION_OBJECT_POINTERS SectionObjectPointer,
    ULONG ForceCloseFlags
);

NTSYSAPI NTSTATUS ZwOpenProcessTokenEx(
    [in] HANDLE ProcessHandle,
    [in] ACCESS_MASK DesiredAccess,
    [in] ULONG HandleAttributes,
    [out] PHANDLE TokenHandle
);

void SeDeleteObjectAuditAlarm(
    [in] PVOID Object,
    [in] HANDLE Handle
);

BOOLEAN KeSetKernelStackSwapEnable(
    [in] BOOLEAN Enable
);

KSECDDDECLSPEC NTSTATUS SEC_ENTRY SecLookupAccountName(
    [in] PUNICODE_STRING Name,
    [in, out] PULONG SidSize,
    [out] PSID Sid,
    [out] PSID_NAME_USE NameUse,
    [out] PULONG DomainSize,
    [in_out, optional] PUNICODE_STRING ReferencedDomain
);

NTSYSAPI NTSTATUS RtlCustomCPToUnicodeN(
    PCPTABLEINFO CustomCP,
    PWCH UnicodeString,
    ULONG MaxBytesInUnicodeString,
    PULONG BytesInUnicodeString,
    PCH CustomCPString,
    ULONG BytesInCustomCPString
);

void FsRtlPrepareToReuseEcp(
    [in] PVOID EcpContext
);

void SeSetAccessStateGenericMapping(
    [in, out] PACCESS_STATE AccessState,
    [in] PGENERIC_MAPPING GenericMapping
);

NTSTATUS FsRtlOplockFsctrl(
    [in] POPLOCK Oplock,
    [in] PIRP Irp,
    [in] ULONG OpenCount
);

void CcSetDirtyPageThreshold(
    [in] PFILE_OBJECT FileObject,
    [in] ULONG DirtyPageThreshold
);

NTSYSAPI BOOLEAN RtlIsNameLegalDOS8Dot3(
    [in] PCUNICODE_STRING Name,
    [in, out] POEM_STRING OemName,
    [out, optional] PBOOLEAN NameContainsSpaces
);

NTSYSAPI NTSTATUS RtlUTF8StringToUnicodeString(
    PUNICODE_STRING DestinationString,
    PUTF8_STRING SourceString,
    BOOLEAN AllocateDestinationString
);

void FsRtlInitializeTunnelCache(
    [in] TUNNEL *Cache
);

PLIST_ENTRY KeRemoveQueue(
    [in, out] PRKQUEUE Queue,
    [in] KPROCESSOR_MODE WaitMode,
    [in, optional] PLARGE_INTEGER Timeout
);

void FsRtlUninitializeMcb(
    PMCB Mcb
);

LOGICAL KeTryToAcquireQueuedSpinLock(
    KSPIN_LOCK_QUEUE_NUMBER Number,
    PKIRQL OldIrql
);

NTSTATUS FsRtlRegisterUncProviderEx(
    [out] PHANDLE MupHandle,
    [in] PCUNICODE_STRING RedirDevName,
    [in] PDEVICE_OBJECT DeviceObject,
    [in] FSRTL_UNC_PROVIDER_FLAGS Flags
);

NTSYSAPI BOOLEAN RtlEqualSid(
    [in] PSID Sid1,
    [in] PSID Sid2
);

NTSTATUS FsRtlSetKernelEaFile(
    [in] PFILE_OBJECT FileObject,
    [in] PVOID EaBuffer,
    [in] ULONG Length
);

NTSTATUS FsRtlRemoveExtraCreateParameter(
    [in, out] PECP_LIST EcpList,
    [in] LPCGUID EcpType,
    [out] PVOID *EcpContext,
    [out, optional] ULONG *EcpContextSize
);

BOOLEAN CcPinMappedData(
    [in] PFILE_OBJECT FileObject,
    [in] PLARGE_INTEGER FileOffset,
    [in] ULONG Length,
    [in] ULONG Flags,
    [in, out] PVOID *Bcb
);

NTSYSAPI NTSTATUS RtlDecompressChunks(
    PUCHAR UncompressedBuffer,
    ULONG UncompressedBufferSize,
    PUCHAR CompressedBuffer,
    ULONG CompressedBufferSize,
    PUCHAR CompressedTail,
    ULONG CompressedTailSize,
    PCOMPRESSED_DATA_INFO CompressedDataInfo
);

__kernel_entry NTSYSCALLAPI NTSTATUS NtQueryDirectoryFileEx(
    [in] HANDLE FileHandle,
    [in, optional] HANDLE Event,
    [in, optional] PIO_APC_ROUTINE ApcRoutine,
    [in, optional] PVOID ApcContext,
    [out] PIO_STATUS_BLOCK IoStatusBlock,
    [out] PVOID FileInformation,
    [in] ULONG Length,
    FILE_INFORMATION_CLASS FileInformationClass,
    [in] ULONG QueryFlags,
    [in, optional] PUNICODE_STRING FileName
);

NTSTATUS PoCreatePowerRequest(
    [out] PVOID *PowerRequest,
    [in] PDEVICE_OBJECT DeviceObject,
    [in] PCOUNTED_REASON_CONTEXT Context
);

void FsRtlNotifyFilterReportChange(
    [in] PNOTIFY_SYNC NotifySync,
    [in] PLIST_ENTRY NotifyList,
    [in] PSTRING FullTargetName,
    [in] USHORT TargetNameOffset,
    [in, optional] PSTRING StreamName,
    [in, optional] PSTRING NormalizedParentName,
    [in] ULONG FilterMatch,
    [in] ULONG Action,
    [in, optional] PVOID TargetContext,
    [in, optional] PVOID FilterContext
);

PFSRTL_PER_STREAM_CONTEXT FsRtlLookupPerStreamContextInternal(
    PFSRTL_ADVANCED_FCB_HEADER StreamContext,
    PVOID OwnerId,
    PVOID InstanceId
);

NTSYSAPI NTSTATUS ZwCreateEvent(
    [out] PHANDLE EventHandle,
    [in] ACCESS_MASK DesiredAccess,
    [in, optional] POBJECT_ATTRIBUTES ObjectAttributes,
    [in] EVENT_TYPE EventType,
    [in] BOOLEAN InitialState
);

BOOLEAN FsRtlLookupLargeMcbEntry(
    PLARGE_MCB Mcb,
    LONGLONG Vbn,
    PLONGLONG Lbn,
    PLONGLONG SectorCountFromLbn,
    PLONGLONG StartingLbn,
    PLONGLONG SectorCountFromStartingLbn,
    [out, optional] PULONG Index
);

BOOLEAN PoQueryWatchdogTime(
    [in] PDEVICE_OBJECT Pdo,
    [out] PULONG SecondsRemaining
);

NTSTATUS SeAppendPrivileges(
    [in, out] PACCESS_STATE AccessState,
    [in] PPRIVILEGE_SET Privileges
);

PACESS_TOKEN
SeQuerySubjectContextToken(SubjectContext);

void FsRtlIsAnsiCharacterLegalNtfsStream(
    C,
    WILD_OK
);

NTSYSAPI SIZE_T RtlCompareMemoryUlong(
    [in] PVOID Source,
    [in] SIZE_T Length,
    [in] ULONG Pattern
);

NTSTATUS FsRtlQueryKernelEaFile(
    [in] PFILE_OBJECT FileObject,
    [out] PVOID ReturnedEaData,
    [in] ULONG Length,
    [in] BOOLEAN ReturnSingleEntry,
    [in] PVOID EaList,
    [in] ULONG EaListLength,
    [in, optional] PULONG EaIndex,
    [in] BOOLEAN RestartScan,
    [out, optional] PULONG LengthReturned
);

NTSTATUS IoGetRequestorSessionId(
    [in] PIRP Irp,
    [out] PULONG pSessionId
);

NTSTATUS PoRegisterPowerSettingCallback(
    [in, optional] PDEVICE_OBJECT DeviceObject,
    [in] LPCGUID SettingGuid,
    [in] PPOWER_SETTING_CALLBACK Callback,
    [in, optional] PVOID Context,
    [out] PVOID *Handle
);

NTSYSAPI PSID_IDENTIFIER_AUTHORITY RtlIdentifierAuthoritySid(
    PSID Sid
);

BOOLEAN FsRtlFastCheckLockForRead(
    [in] PFILE_LOCK FileLock,
    [in] PLARGE_INTEGER StartingByte,
    [in] PLARGE_INTEGER Length,
    [in] ULONG Key,
    [in] PFILE_OBJECT FileObject,
    [in] PVOID ProcessId
);

NTSTATUS PoCallDriver(
    [in] PDEVICE_OBJECT DeviceObject,
    [in, out] __drv_aliasesMem PIRP Irp
);

__kernel_entry NTSYSCALLAPI NTSTATUS NtDuplicateToken(
    [in] HANDLE ExistingTokenHandle,
    [in] ACCESS_MASK DesiredAccess,
    [in] POBJECT_ATTRIBUTES ObjectAttributes,
    [in] BOOLEAN EffectiveOnly,
    [in] TOKEN_TYPE TokenType,
    [out] PHANDLE NewTokenHandle
);

BOOLEAN FsRtlIsNameInExpression(
    [in] PUNICODE_STRING Expression,
    [in] PUNICODE_STRING Name,
    [in] BOOLEAN IgnoreCase,
    [in, optional] PWCH UpcaseTable
);

SECURITY_STATUS SEC_ENTRY SecAllocateAndSetIPAddress(
    PUCHAR lpIpAddress,
    ULONG cchIpAddress,
    int *FreeCallContext
);

KIRQL KeAcquireQueuedSpinLock(
    KSPIN_LOCK_QUEUE_NUMBER Number
);

NTSYSAPI CHAR RtlQueryThreadPlaceholderCompatibilityMode();

BOOLEAN FsRtlFastCheckLockForWrite(
    [in] PFILE_LOCK FileLock,
    [in] PLARGE_INTEGER StartingByte,
    [in] PLARGE_INTEGER Length,
    [in] ULONG Key,
    [in] PVOID FileObject,
    [in] PVOID ProcessId
);

void IsReparseTagValid(
    _tag
);

void FsRtlAreThereCurrentFileLocks(
    FL
);

BOOLEAN SeAuditingFileEvents(
    [in] BOOLEAN AccessGranted,
    [in] PSECURITY_DESCRIPTOR SecurityDescriptor
);

BOOLEAN SeTokenIsAdmin(
    [in] PACCESS_TOKEN Token
);

NTSYSAPI NTSTATUS ZwSetInformationVirtualMemory(
    [in] HANDLE ProcessHandle,
    [in] VIRTUAL_MEMORY_INFORMATION_CLASS VmInformationClass,
    [in] ULONG_PTR NumberOfEntries,
    [in] PMEMORY_RANGE_ENTRY VirtualAddresses,
    [in] PVOID VmInformation,
    [in] ULONG VmInformationLength
);

NTSYSAPI NTSTATUS ZwQueryObject(
    [in, optional] HANDLE Handle,
    [in] OBJECT_INFORMATION_CLASS ObjectInformationClass,
    [out, optional] PVOID ObjectInformation,
    [in] ULONG ObjectInformationLength,
    [out, optional] PULONG ReturnLength
);

void FsRtlTestAnsiCharacter(
    C,
    DEFAULT_RET,
    WILD_OK,
    FLAGS
);

void FsRtlPostPagingFileStackOverflow(
    [in] PVOID Context,
    [in] PKEVENT Event,
    [in] PFSRTL_STACK_OVERFLOW_ROUTINE StackOverflowRoutine
);

NTSYSAPI NTSTATUS ZwFsControlFile(
    [in] HANDLE FileHandle,
    [in, optional] HANDLE Event,
    [in, optional] PIO_APC_ROUTINE ApcRoutine,
    [in, optional] PVOID ApcContext,
    [out] PIO_STATUS_BLOCK IoStatusBlock,
    [in] ULONG FsControlCode,
    [in, optional] PVOID InputBuffer,
    [in] ULONG InputBufferLength,
    [out, optional] PVOID OutputBuffer,
    [in] ULONG OutputBufferLength
);

__kernel_entry NTSYSCALLAPI NTSTATUS NtSetInformationThread(
    [in] HANDLE ThreadHandle,
    [in] THREADINFOCLASS ThreadInformationClass,
    [in] PVOID ThreadInformation,
    [in] ULONG ThreadInformationLength
);

void SeReleaseSubjectContext(
    [in, out] PSECURITY_SUBJECT_CONTEXT SubjectContext
);

NTSYSAPI NTSTATUS RtlGetGroupSecurityDescriptor(
    [in] PSECURITY_DESCRIPTOR SecurityDescriptor,
    [out] PSID *Group,
    [out] PBOOLEAN GroupDefaulted
);

NTSTATUS SeImpersonateClientEx(
    [in] PSECURITY_CLIENT_CONTEXT ClientContext,
    [in, optional] PETHREAD ServerThread
);

NTSYSAPI NTSTATUS ZwWaitForSingleObject(
    [in] HANDLE Handle,
    [in] BOOLEAN Alertable,
    [in, optional] PLARGE_INTEGER Timeout
);

NTSTATUS CcSetFileSizesEx(
    PFILE_OBJECT FileObject,
    PCC_FILE_SIZES FileSizes
);

NT_RTL_COMPRESS_API NTSTATUS RtlGetCompressionWorkSpaceSize(
    [in] USHORT CompressionFormatAndEngine,
    [out] PULONG CompressBufferWorkSpaceSize,
    [out] PULONG CompressFragmentWorkSpaceSize
);

NTSYSAPI BOOLEAN RtlValidSid(
    [in] PSID Sid
);

NTSYSAPI NTSTATUS ZwQueryVolumeInformationFile(
    [in] HANDLE FileHandle,
    [out] PIO_STATUS_BLOCK IoStatusBlock,
    [out] PVOID FsInformation,
    [in] ULONG Length,
    [in] FS_INFORMATION_CLASS FsInformationClass
);

NTSYSAPI NTSTATUS RtlOemStringToCountedUnicodeString(
    PUNICODE_STRING DestinationString,
    [in] PCOEM_STRING SourceString,
    [in] BOOLEAN AllocateDestinationString
);

NTSTATUS IoEnumerateRegisteredFiltersList(
    [out] PDRIVER_OBJECT *DriverObjectList,
    [in] ULONG DriverObjectListSize,
    [out] PULONG ActualNumberDriverObjects
);

NTSYSAPI BOOLEAN RtlIsPartialPlaceholder(
    [in] ULONG FileAttributes,
    [in] ULONG ReparseTag
);

PFSRTL_PER_FILE_CONTEXT FsRtlRemovePerFileContext(
    [in] PVOID *PerFileContextPointer,
    [in, optional] PVOID OwnerId,
    [in, optional] PVOID InstanceId
);

NTSTATUS FsRtlAddBaseMcbEntryEx(
    PBASE_MCB Mcb,
    LONGLONG Vbn,
    LONGLONG Lbn,
    LONGLONG SectorCount
);

BOOLEAN FsRtlCheckLockForWriteAccess(
    [in] PFILE_LOCK FileLock,
    [in] PIRP Irp
);

void FsRtlGetBypassIoOpenCountPtr(
    _fo
);

NTSYSAPI NTSTATUS ZwDuplicateToken(
    [in] HANDLE ExistingTokenHandle,
    [in] ACCESS_MASK DesiredAccess,
    [in] POBJECT_ATTRIBUTES ObjectAttributes,
    [in] BOOLEAN EffectiveOnly,
    [in] TOKEN_TYPE TokenType,
    [out] PHANDLE NewTokenHandle
);

BOOLEAN FsRtlAreVolumeStartupApplicationsComplete();

NTSYSAPI NTSTATUS ZwQueryDirectoryFileEx(
    [in] HANDLE FileHandle,
    [in, optional] HANDLE Event,
    [in, optional] PIO_APC_ROUTINE ApcRoutine,
    [in, optional] PVOID ApcContext,
    [out] PIO_STATUS_BLOCK IoStatusBlock,
    [out] PVOID FileInformation,
    [in] ULONG Length,
    [in] FILE_INFORMATION_CLASS FileInformationClass,
    [in] ULONG QueryFlags,
    [in, optional] PUNICODE_STRING FileName
);

void IoUnregisterFileSystem(
    [in] PDEVICE_OBJECT DeviceObject
);

void KeInitializeMutant(
    PRKMUTANT Mutant,
    BOOLEAN InitialOwner
);

void PoStartNextPowerIrp(
    [in, out] PIRP Irp
);

void FsRtlIsUnicodeCharacterWild(
    C
);

void FsRtlTeardownPerStreamContexts(
    [in] PFSRTL_ADVANCED_FCB_HEADER AdvancedHeader
);

NTSTATUS PsImpersonateClient(
    [in, out] PETHREAD Thread,
    [in] PACCESS_TOKEN Token,
    [in] BOOLEAN CopyOnOpen,
    [in] BOOLEAN EffectiveOnly,
    [in] SECURITY_IMPERSONATION_LEVEL ImpersonationLevel
);

void KeInitializeQueue(
    [out] PRKQUEUE Queue,
    [in] ULONG Count
);

NTSTATUS PoUnregisterPowerSettingCallback(
    [in, out] PVOID Handle
);

NTSYSAPI NTSTATUS RtlGetOwnerSecurityDescriptor(
    [in] PSECURITY_DESCRIPTOR SecurityDescriptor,
    [out] PSID *Owner,
    [out] PBOOLEAN OwnerDefaulted
);

NTSYSAPI VOID RtlCaptureContext(
    [out] PCONTEXT ContextRecord
);

NTSYSAPI CHAR RtlSetProcessPlaceholderCompatibilityMode(
    CHAR Mode
);

NTSYSAPI NTSTATUS RtlGenerate8dot3Name(
    [in] PCUNICODE_STRING Name,
    [in] BOOLEAN AllowExtendedCharacters,
    [in, out] PGENERATE_NAME_CONTEXT Context,
    [in, out] PUNICODE_STRING Name8dot3
);

NTSTATUS PoClearPowerRequest(
    [in, out] PVOID PowerRequest,
    [in] POWER_REQUEST_TYPE Type
);

NTSYSAPI LOGICAL RtlFreeHeap(
    [in] PVOID HeapHandle,
    [in, optional] ULONG Flags,
    _Frees_ptr_opt_ PVOID BaseAddress
);

NTSYSAPI NTSTATUS RtlInitializeSidEx(
    [out] PSID Sid,
    [in] PSID_IDENTIFIER_AUTHORITY IdentifierAuthority,
    [in] UCHAR SubAuthorityCount,
    ...
);

NTSTATUS FsRtlMupGetProviderInfoFromFileObject(
    [in] PFILE_OBJECT pFileObject,
    [in] ULONG Level,
    [out] PVOID pBuffer,
    [in, out] PULONG pBufferSize
);

NTSYSAPI NTSTATUS RtlUpcaseUnicodeToCustomCPN(
    PCPTABLEINFO CustomCP,
    PCH CustomCPString,
    ULONG MaxBytesInCustomCPString,
    PULONG BytesInCustomCPString,
    PWCH UnicodeString,
    ULONG BytesInUnicodeString
);

NTSTATUS IoPageRead(
    PFILE_OBJECT FileObject,
    PMDL MemoryDescriptorList,
    PLARGE_INTEGER StartingOffset,
    PKEVENT Event,
    PIO_STATUS_BLOCK IoStatusBlock
);

BOOLEAN CcIsThereDirtyDataEx(
    [in] PVPB Vpb,
    [in, optional] PULONG NumberOfDirtyPages
);

void FsRtlRemoveLargeMcbEntry(
    PLARGE_MCB Mcb,
    LONGLONG Vbn,
    LONGLONG SectorCount
);

NTSTATUS FsRtlInsertPerStreamContext(
    PFSRTL_ADVANCED_FCB_HEADER PerStreamContext,
    [in] PFSRTL_PER_STREAM_CONTEXT Ptr
);

BOOLEAN ObIsKernelHandle(
    [in] HANDLE Handle
);

void SeAuditHardLinkCreation(
    PUNICODE_STRING FileName,
    PUNICODE_STRING LinkName,
    BOOLEAN bSuccess
);

NTSYSAPI NTSTATUS RtlOemToUnicodeN(
    [out] PWCH UnicodeString,
    [in] ULONG MaxBytesInUnicodeString,
    [out, optional] PULONG BytesInUnicodeString,
    [in] PCCH OemString,
    [in] ULONG BytesInOemString
);

__kernel_entry NTSYSCALLAPI NTSTATUS NtOpenProcessToken(
    [in] HANDLE ProcessHandle,
    [in] ACCESS_MASK DesiredAccess,
    [out] PHANDLE TokenHandle
);

BOOLEAN FsRtlSplitLargeMcb(
    [in] PLARGE_MCB Mcb,
    [in] LONGLONG Vbn,
    [in] LONGLONG Amount
);

SIZE_T ExQueryPoolBlockSize(
    PVOID PoolBlock,
    PBOOLEAN QuotaCharged
);

NTSTATUS SEC_ENTRY GetSecurityUserInfo(
    [in, optional] PLUID LogonId,
    [in] ULONG Flags,
    [out] PSecurityUserData *UserInformation
);

void CcScheduleReadAheadEx(
    [in] PFILE_OBJECT FileObject,
    [in] PLARGE_INTEGER FileOffset,
    [in] ULONG Length,
    [in] PETHREAD IoIssuerThread
);

BOOLEAN IoCheckFileObjectOpenedAsCopyDestination(
    [in] PFILE_OBJECT FileObject
);

void FsRtlDissectName(
    [in] UNICODE_STRING Path,
    [out] PUNICODE_STRING FirstName,
    [out] PUNICODE_STRING RemainingName
);

BOOLEAN IoFastQueryNetworkAttributes(
    POBJECT_ATTRIBUTES ObjectAttributes,
    ACCESS_MASK DesiredAccess,
    ULONG OpenOptions,
    PIO_STATUS_BLOCK IoStatus,
    PFILE_NETWORK_OPEN_INFORMATION Buffer
);

LOGICAL FsRtlIsSystemPagingFile(
    [in] PFILE_OBJECT FileObject
);

void IoWriteErrorLogEntry(
    [in] PVOID ElEntry
);

NTSTATUS FsRtlGetNextExtraCreateParameter(
    [in] PECP_LIST EcpList,
    [in, optional] PVOID CurrentEcpContext,
    [out, optional] LPGUID NextEcpType,
    [out] PVOID *NextEcpContext,
    [out, optional] ULONG *NextEcpContextSize
);

void CcSetDirtyPinnedData(
    [in] PVOID BcbVoid,
    [in, optional] PLARGE_INTEGER Lsn
);

void SeTokenGetNoChildProcessRestricted(
    [in] PACCESS_TOKEN Token,
    [out] PBOOLEAN Enforced,
    [out] PBOOLEAN UnlessSecure,
    [out] PBOOLEAN AuditOnly
);

void PoUnregisterSystemState(
    [in, out] PVOID StateHandle
);

NTSYSAPI NTSTATUS RtlAllocateAndInitializeSid(
    PSID_IDENTIFIER_AUTHORITY IdentifierAuthority,
    UCHAR SubAuthorityCount,
    ULONG SubAuthority0,
    ULONG SubAuthority1,
    ULONG SubAuthority2,
    ULONG SubAuthority3,
    ULONG SubAuthority4,
    ULONG SubAuthority5,
    ULONG SubAuthority6,
    ULONG SubAuthority7,
    PSID *Sid
);

LONGLONG CcGetCacheFileSize(
    [in] const SECTION_OBJECT_POINTERS *SectionObjectPointer
);

NTSYSAPI NTSTATUS RtlCreateSecurityDescriptorRelative(
    [out] PISECURITY_DESCRIPTOR_RELATIVE SecurityDescriptor,
    [in] ULONG Revision
);

NTSTATUS FsRtlFastUnlockAllByKey(
    [in] PFILE_LOCK FileLock,
    [in] PFILE_OBJECT FileObject,
    [in] PEPROCESS ProcessId,
    [in] ULONG Key,
    [in, optional] PVOID Context
);

void SeCaptureSubjectContextEx(
    PETHREAD Thread,
    PEPROCESS Process,
    PSECURITY_SUBJECT_CONTEXT SubjectContext
);

PVOID CcRemapBcb(
    [in] PVOID Bcb
);

__kernel_entry NTSYSCALLAPI NTSTATUS NtSetInformationToken(
    [in] HANDLE TokenHandle,
    [in] TOKEN_INFORMATION_CLASS TokenInformationClass,
    [in] PVOID TokenInformation,
    [in] ULONG TokenInformationLength
);

NTSYSAPI PVOID RtlFreeSid(
    PSID Sid
);

NTSYSAPI ULONG RtlxUnicodeStringToOemSize(
    PCUNICODE_STRING UnicodeString
);

KSECDDDECLSPEC NTSTATUS SecMakeSPNEx2(
    [in] IN PUNICODE_STRING ServiceClass,
    [in] IN PUNICODE_STRING ServiceName,
    [in, optional] IN PUNICODE_STRING InstanceName,
    [in, optional] IN USHORT InstancePort,
    [in, optional] IN PUNICODE_STRING Referrer,
    [in, optional] IN PUNICODE_STRING InTargetInfo,
    [in, out] IN OUT PUNICODE_STRING Spn,
    [out, optional] OUT PULONG TotalSize,
    [in] IN BOOLEAN Allocate,
    [in] IN BOOLEAN IsTargetInfoMarshaled
);

void IoIsFileOpenedExclusively(
    FileObject
);

NTSYSAPI NTSTATUS ZwFreeVirtualMemory(
    [in] HANDLE ProcessHandle,
    [in, out] PVOID *BaseAddress,
    [in, out] PSIZE_T RegionSize,
    [in] ULONG FreeType
);

BOOLEAN MmCanFileBeTruncated(
    [in] PSECTION_OBJECT_POINTERS SectionPointer,
    [in, optional] PLARGE_INTEGER NewFileSize
);

void FsRtlUninitializeOplock(
    [in, out] POPLOCK Oplock
);

__kernel_entry NTSYSCALLAPI NTSTATUS NtLockFile(
    [in] HANDLE FileHandle,
    [in, optional] HANDLE Event,
    [in, optional] PIO_APC_ROUTINE ApcRoutine,
    [in, optional] PVOID ApcContext,
    [out] PIO_STATUS_BLOCK IoStatusBlock,
    [in] PLARGE_INTEGER ByteOffset,
    [in] PLARGE_INTEGER Length,
    [in] ULONG Key,
    [in] BOOLEAN FailImmediately,
    [in] BOOLEAN ExclusiveLock
);

__kernel_entry NTSYSCALLAPI NTSTATUS NtFreeVirtualMemory(
    [in] HANDLE ProcessHandle,
    [in, out] PVOID *BaseAddress,
    [in, out] PSIZE_T RegionSize,
    [in] ULONG FreeType
);

NTSYSAPI NTSTATUS ZwQuerySecurityObject(
    [in] HANDLE Handle,
    [in] SECURITY_INFORMATION SecurityInformation,
    [out] PSECURITY_DESCRIPTOR SecurityDescriptor,
    [in] ULONG Length,
    [out] PULONG LengthNeeded
);

void FsRtlSupportsPerFileContexts(
    _fo
);

void FsRtlIncrementCcFastReadNoWait();

void FsRtlTruncateLargeMcb(
    PLARGE_MCB Mcb,
    LONGLONG Vbn
);

NTSTATUS IoVerifyVolume(
    [in] PDEVICE_OBJECT DeviceObject,
    [in] BOOLEAN AllowRawMount
);

NTSTATUS FsRtlQueryCachedVdl(
    [in] PFILE_OBJECT FileObject,
    [out] PLONGLONG Vdl
);

NTSYSAPI NTSTATUS RtlQueryPackageIdentity(
    PVOID TokenObject,
    PWSTR PackageFullName,
    PSIZE_T PackageSize,
    PWSTR AppId,
    PSIZE_T AppIdSize,
    PBOOLEAN Packaged
);

void IoRegisterFileSystem(
    [in] __drv_aliasesMem PDEVICE_OBJECT DeviceObject
);

NTSYSAPI NTSTATUS ZwOpenThreadTokenEx(
    [in] HANDLE ThreadHandle,
    [in] ACCESS_MASK DesiredAccess,
    [in] BOOLEAN OpenAsSelf,
    [in] ULONG HandleAttributes,
    [out] PHANDLE TokenHandle
);

NTSTATUS SeUnregisterLogonSessionTerminatedRoutine(
    [in] PSE_LOGON_SESSION_TERMINATED_ROUTINE CallbackRoutine
);

NT_RTL_COMPRESS_API NTSTATUS RtlDecompressFragmentEx(
    [in] USHORT CompressionFormat,
    [out] PUCHAR UncompressedFragment,
    [in] ULONG UncompressedFragmentSize,
    [in] PUCHAR CompressedBuffer,
    [in] ULONG CompressedBufferSize,
    [in] ULONG FragmentOffset,
    [in] ULONG UncompressedChunkSize,
    [out] PULONG FinalUncompressedSize,
    [in] PVOID WorkSpace
);

NTSTATUS IoCheckDesiredAccess(
    PACCESS_MASK DesiredAccess,
    ACCESS_MASK GrantedAccess
);

__kernel_entry NTSYSCALLAPI NTSTATUS NtQuerySecurityObject(
    [in] HANDLE Handle,
    [in] SECURITY_INFORMATION SecurityInformation,
    [out] PSECURITY_DESCRIPTOR SecurityDescriptor,
    [in] ULONG Length,
    [out] PULONG LengthNeeded
);

BOOLEAN CcIsThereDirtyData(
    [in] PVPB Vpb
);

void CcInitializeCacheMap(
    [in] PFILE_OBJECT FileObject,
    [in] PCC_FILE_SIZES FileSizes,
    [in] BOOLEAN PinAccess,
    [in] PCACHE_MANAGER_CALLBACKS Callbacks,
    [in] PVOID LazyWriteContext
);

void CcUnpinData(
    [in] PVOID Bcb
);

void CcMdlWriteComplete(
    [in] PFILE_OBJECT FileObject,
    [in] PLARGE_INTEGER FileOffset,
    [in] PMDL MdlChain
);

BOOLEAN CcCopyRead(
    [in] PFILE_OBJECT FileObject,
    [in] PLARGE_INTEGER FileOffset,
    [in] ULONG Length,
    [in] BOOLEAN Wait,
    [out] PVOID Buffer,
    [out] PIO_STATUS_BLOCK IoStatus
);

BOOLEAN FsRtlMdlReadDev(
    [in] PFILE_OBJECT FileObject,
    [in] PLARGE_INTEGER FileOffset,
    [in] ULONG Length,
    [in] ULONG LockKey,
    [out] PMDL *MdlChain,
    [out] PIO_STATUS_BLOCK IoStatus,
    [ in, optional ] PDEVICE_OBJECT DeviceObject
);

void FsRtlIncrementCcFastMdlReadWait();

__kernel_entry NTSYSCALLAPI NTSTATUS NtReadFile(
    [in] HANDLE FileHandle,
    [in, optional] HANDLE Event,
    [in, optional] PIO_APC_ROUTINE ApcRoutine,
    [in, optional] PVOID ApcContext,
    [out] PIO_STATUS_BLOCK IoStatusBlock,
    [out] PVOID Buffer,
    [in] ULONG Length,
    [in, optional] PLARGE_INTEGER ByteOffset,
    [in, optional] PULONG Key
);

__kernel_entry NTSYSCALLAPI NTSTATUS NtDeviceIoControlFile(
    [in] HANDLE FileHandle,
    [in, optional] HANDLE Event,
    [in, optional] PIO_APC_ROUTINE ApcRoutine,
    [in, optional] PVOID ApcContext,
    [out] PIO_STATUS_BLOCK IoStatusBlock,
    [in] ULONG IoControlCode,
    [in, optional] PVOID InputBuffer,
    [in] ULONG InputBufferLength,
    [out, optional] PVOID OutputBuffer,
    [in] ULONG OutputBufferLength
);

void CcSetFileSizes(
    [in] PFILE_OBJECT FileObject,
    [in] PCC_FILE_SIZES FileSizes
);

void FsRtlNotifyCleanup(
    [in] PNOTIFY_SYNC NotifySync,
    [in] PLIST_ENTRY NotifyList,
    [in] PVOID FsContext
);

NTSYSAPI NTSTATUS RtlUnicodeToMultiByteSize(
    [out] PULONG BytesInMultiByteString,
    [in] PCWCH UnicodeString,
    [in] ULONG BytesInUnicodeString
);

NTSYSAPI CHAR RtlSetThreadPlaceholderCompatibilityMode(
    [in] CHAR Mode
);

NTSTATUS IoRegisterFsRegistrationChange(
    [in] PDRIVER_OBJECT DriverObject,
    [in] PDRIVER_FS_NOTIFICATION DriverNotificationRoutine
);

NTSTATUS FsRtlRemoveDotsFromPath(
    [in, out] PWSTR OriginalString,
    [in] USHORT PathLength,
    [out] USHORT *NewLength
);

BOOLEAN FsRtlPrivateLock(
    PFILE_LOCK FileLock,
    PFILE_OBJECT FileObject,
    PLARGE_INTEGER FileOffset,
    PLARGE_INTEGER Length,
    PEPROCESS ProcessId,
    ULONG Key,
    BOOLEAN FailImmediately,
    BOOLEAN ExclusiveLock,
    PIO_STATUS_BLOCK Iosb,
    PIRP Irp,
    __drv_aliasesMem PVOID Context,
    BOOLEAN AlreadySynchronized
);

void CcRepinBcb(
    [in] PVOID Bcb
);

__kernel_entry NTSYSCALLAPI NTSTATUS NtWriteFile(
    [in] HANDLE FileHandle,
    [in, optional] HANDLE Event,
    [in, optional] PIO_APC_ROUTINE ApcRoutine,
    [in, optional] PVOID ApcContext,
    [out] PIO_STATUS_BLOCK IoStatusBlock,
    [in] PVOID Buffer,
    [in] ULONG Length,
    [in, optional] PLARGE_INTEGER ByteOffset,
    [in, optional] PULONG Key
);

NTSTATUS IoQueryFileInformation(
    PFILE_OBJECT FileObject,
    FILE_INFORMATION_CLASS FileInformationClass,
    ULONG Length,
    PVOID FileInformation,
    PULONG ReturnedLength
);

PVOID PoRegisterSystemState(
    [in, out] PVOID StateHandle,
    [in] EXECUTION_STATE Flags
);

void FsRtlRemoveMcbEntry(
    PMCB Mcb,
    VBN Vbn,
    ULONG SectorCount
);

NTSYSAPI VOID RtlInitCodePageTable(
    PUSHORT TableBase,
    PCPTABLEINFO CodePageTable
);

NTSYSAPI NTSTATUS RtlUTF8ToUnicodeN(
    [out, optional] PWSTR UnicodeStringDestination,
    [in] ULONG UnicodeStringMaxByteCount,
    [out] PULONG UnicodeStringActualByteCount,
    [in] PCCH UTF8StringSource,
    [in] ULONG UTF8StringByteCount
);

void FsRtlReleaseFile(
    PFILE_OBJECT FileObject
);

NT_RTL_COMPRESS_API NTSTATUS RtlDecompressBufferEx2(
    [in] USHORT CompressionFormat,
    [out] PUCHAR UncompressedBuffer,
    [in] ULONG UncompressedBufferSize,
    [in] PUCHAR CompressedBuffer,
    [in] ULONG CompressedBufferSize,
    [in] ULONG UncompressedChunkSize,
    [out] PULONG FinalUncompressedSize,
    [in, optional] PVOID WorkSpace
);

void FsRtlInitializeLargeMcb(
    PLARGE_MCB Mcb,
    [in] POOL_TYPE PoolType
);

BOOLEAN FsRtlIsTotalDeviceFailure(
    [in] NTSTATUS Status
);

void PsUpdateDiskCounters(
    PEPROCESS Process,
    ULONG64 BytesRead,
    ULONG64 BytesWritten,
    ULONG ReadOperationCount,
    ULONG WriteOperationCount,
    ULONG FlushOperationCount
);

NTSTATUS FsRtlAllocateExtraCreateParameterFromLookasideList(
    [in] LPCGUID EcpType,
    [in] ULONG SizeOfContext,
    [in] FSRTL_ALLOCATE_ECP_FLAGS Flags,
    [in, optional] PFSRTL_EXTRA_CREATE_PARAMETER_CLEANUP_CALLBACK CleanupCallback,
    [in, out] PVOID LookasideList,
    [out] PVOID *EcpContext
);

void CcDeferWrite(
    [in] PFILE_OBJECT FileObject,
    [in] PCC_POST_DEFERRED_WRITE PostRoutine,
    [in] PVOID Context1,
    [in] PVOID Context2,
    [in] ULONG BytesToWrite,
    [in] BOOLEAN Retrying
);

NTSYSAPI PULONG RtlSubAuthoritySid(
    [in] PSID Sid,
    ULONG SubAuthority
);

NTSYSAPI NTSTATUS ZwNotifyChangeKey(
    [in] HANDLE KeyHandle,
    [in, optional] HANDLE Event,
    [in, optional] PIO_APC_ROUTINE ApcRoutine,
    [in, optional] PVOID ApcContext,
    [out] PIO_STATUS_BLOCK IoStatusBlock,
    [in] ULONG CompletionFilter,
    [in] BOOLEAN WatchTree,
    [out, optional] PVOID Buffer,
    [in] ULONG BufferSize,
    [in] BOOLEAN Asynchronous
);

void IoStartNextPacket(
    [in] PDEVICE_OBJECT DeviceObject,
    [in] BOOLEAN Cancelable
);

__kernel_entry NTSYSCALLAPI NTSTATUS NtQueryVirtualMemory(
    [in] HANDLE ProcessHandle,
    [in, optional] PVOID BaseAddress,
    [in] MEMORY_INFORMATION_CLASS MemoryInformationClass,
    [out] PVOID MemoryInformation,
    [in] SIZE_T MemoryInformationLength,
    [out, optional] PSIZE_T ReturnLength
);

void FsRtlIncrementCcFastReadResourceMiss();

NTSTATUS FsRtlCheckOplockEx(
    [in] POPLOCK Oplock,
    [in] PIRP Irp,
    [in] ULONG Flags,
    [in, optional] PVOID Context,
    [in, optional] POPLOCK_WAIT_COMPLETE_ROUTINE CompletionRoutine,
    [in, optional] POPLOCK_FS_PREPOST_IRP PostIrpRoutine
);

NT_RTL_COMPRESS_API NTSTATUS RtlDecompressBuffer(
    [in] USHORT CompressionFormat,
    [out] PUCHAR UncompressedBuffer,
    [in] ULONG UncompressedBufferSize,
    [in] PUCHAR CompressedBuffer,
    [in] ULONG CompressedBufferSize,
    [out] PULONG FinalUncompressedSize
);

void FsRtlDeleteKeyFromTunnelCache(
    [in] TUNNEL *Cache,
    ULONGLONG DirectoryKey
);

void FsRtlNotifyFullChangeDirectory(
    [in] PNOTIFY_SYNC NotifySync,
    [in] PLIST_ENTRY NotifyList,
    [in] PVOID FsContext,
    [in] PSTRING FullDirectoryName,
    [in] BOOLEAN WatchTree,
    [in] BOOLEAN IgnoreBuffer,
    [in] ULONG CompletionFilter,
    [in, optional] PIRP NotifyIrp,
    [in, optional] PCHECK_FOR_TRAVERSE_ACCESS TraverseCallback,
    [in, optional] PSECURITY_SUBJECT_CONTEXT SubjectContext
);

LOGICAL FsRtlIsPagingFile(
    [in] PFILE_OBJECT FileObject
);

BOOLEAN FsRtlLookupLastLargeMcbEntry(
    PLARGE_MCB Mcb,
    PLONGLONG Vbn,
    PLONGLONG Lbn
);

NTSYSAPI NTSTATUS ZwDeviceIoControlFile(
    [in] HANDLE FileHandle,
    [in, optional] HANDLE Event,
    [in, optional] PIO_APC_ROUTINE ApcRoutine,
    [in, optional] PVOID ApcContext,
    [out] PIO_STATUS_BLOCK IoStatusBlock,
    [in] ULONG IoControlCode,
    [in, optional] PVOID InputBuffer,
    [in] ULONG InputBufferLength,
    [out, optional] PVOID OutputBuffer,
    [in] ULONG OutputBufferLength
);

void CcPrepareMdlWrite(
    [in] PFILE_OBJECT FileObject,
    [in] PLARGE_INTEGER FileOffset,
    [in] ULONG Length,
    [out] PMDL *MdlChain,
    [out] PIO_STATUS_BLOCK IoStatus
);

PFILE_OBJECT IoCreateStreamFileObjectLite(
    [in, optional] PFILE_OBJECT FileObject,
    [in, optional] PDEVICE_OBJECT DeviceObject
);

NTSTATUS IoRegisterFsRegistrationChangeEx(
    [in] PDRIVER_OBJECT DriverObject,
    [in] PDRIVER_FS_NOTIFICATION DriverNotificationRoutine
);

NTSTATUS FsRtlCheckOplockForFsFilterCallback(
    POPLOCK Oplock,
    PVOID CallbackData,
    ULONG Flags
);

BOOLEAN FsRtlCheckLockForReadAccess(
    [in] PFILE_LOCK FileLock,
    [in] PIRP Irp
);

NTSTATUS MmPrefetchPages(
    [in] ULONG NumberOfLists,
    [in] PREAD_LIST *ReadLists
);

BOOLEAN FsRtlLookupLastLargeMcbEntryAndIndex(
    [in] PLARGE_MCB OpaqueMcb,
    [out] PLONGLONG LargeVbn,
    [out] PLONGLONG LargeLbn,
    [out] PULONG Index
);

void PsChargePoolQuota(
    [in] PEPROCESS Process,
    [in] POOL_TYPE PoolType,
    [in] ULONG_PTR Amount
);

__kernel_entry NTSYSCALLAPI NTSTATUS NtAllocateVirtualMemory(
    [in] HANDLE ProcessHandle,
    [in, out] PVOID *BaseAddress,
    [in] ULONG_PTR ZeroBits,
    [in, out] PSIZE_T RegionSize,
    [in] ULONG AllocationType,
    [in] ULONG Protect
);

NTSYSAPI BOOLEAN RtlTimeToSecondsSince1970(
    [in] PLARGE_INTEGER Time,
    [out] PULONG ElapsedSeconds
);

NTSYSAPI NTSTATUS RtlGetSaclSecurityDescriptor(
    [in] PSECURITY_DESCRIPTOR SecurityDescriptor,
    [out] PBOOLEAN SaclPresent,
    [out] PACL *Sacl,
    [out] PBOOLEAN SaclDefaulted
);

PFILE_OBJECT CcGetFileObjectFromSectionPtrsRef(
    [in] PSECTION_OBJECT_POINTERS SectionObjectPointer
);

NTSYSAPI ULONG RtlxOemStringToUnicodeSize(
    PCOEM_STRING OemString
);

void CcMdlReadComplete(
    [in] PFILE_OBJECT FileObject,
    [in] PMDL MdlChain
);

BOOLEAN CcCopyWriteEx(
    [in] PFILE_OBJECT FileObject,
    [in] PLARGE_INTEGER FileOffset,
    [in] ULONG Length,
    [in] BOOLEAN Wait,
    [in] PVOID Buffer,
    [in] PETHREAD IoIssuerThread
);

BOOLEAN FsRtlGetNextLargeMcbEntry(
    PLARGE_MCB Mcb,
    [in] ULONG RunIndex,
    PLONGLONG Vbn,
    PLONGLONG Lbn,
    PLONGLONG SectorCount
);

NTSYSAPI NTSTATUS RtlUpcaseUnicodeStringToCountedOemString(
    POEM_STRING DestinationString,
    [in] PCUNICODE_STRING SourceString,
    [in] BOOLEAN AllocateDestinationString
);

NTSYSAPI NTSTATUS RtlUnicodeStringToOemString(
    POEM_STRING DestinationString,
    [in] PCUNICODE_STRING SourceString,
    [in] BOOLEAN AllocateDestinationString
);

NTSTATUS IoCheckQuerySetFileInformation(
    FILE_INFORMATION_CLASS FileInformationClass,
    ULONG Length,
    BOOLEAN SetOperation
);

NTSYSAPI BOOLEAN RtlInsertUnicodePrefix(
    [in] PUNICODE_PREFIX_TABLE PrefixTable,
    [in] __drv_aliasesMem PUNICODE_STRING Prefix,
    [out] PUNICODE_PREFIX_TABLE_ENTRY PrefixTableEntry
);

void FsRtlIsAnsiCharacterWild(
    C
);

NTSYSAPI ULONG RtlNtStatusToDosError(
    [in] NTSTATUS Status
);

NTSYSAPI NTSTATUS RtlSetOwnerSecurityDescriptor(
    [in, out] PSECURITY_DESCRIPTOR SecurityDescriptor,
    [in, optional] PSID Owner,
    [in, optional] BOOLEAN OwnerDefaulted
);

NTSTATUS ObQueryNameString(
    [in] PVOID Object,
    [out, optional] POBJECT_NAME_INFORMATION ObjectNameInfo,
    [in] ULONG Length,
    [out] PULONG ReturnLength
);

PACCESS_TOKEN PsReferencePrimaryToken(
    [in, out] PEPROCESS Process
);

void FsRtlUninitializeLargeMcb(
    PLARGE_MCB Mcb
);

NTSTATUS FsRtlChangeBackingFileObject(
    PFILE_OBJECT CurrentFileObject,
    PFILE_OBJECT NewFileObject,
    FSRTL_CHANGE_BACKING_TYPE ChangeBackingType,
    ULONG Flags
);

NTSYSAPI NTSTATUS RtlUpcaseUnicodeToMultiByteN(
    [out] PCHAR MultiByteString,
    [in] ULONG MaxBytesInMultiByteString,
    [out, optional] PULONG BytesInMultiByteString,
    [in] PCWCH UnicodeString,
    [in] ULONG BytesInUnicodeString
);

BOOLEAN MmSetAddressRangeModified(
    [in] PVOID Address,
    [in] SIZE_T Length
);

void FsRtlDissectDbcs(
    [in] ANSI_STRING Path,
    [out] PANSI_STRING FirstName,
    [out] PANSI_STRING RemainingName
);

NTSTATUS FsRtlOplockBreakH(
    [in] POPLOCK Oplock,
    [in] PIRP Irp,
    [in] ULONG Flags,
    [in, optional] PVOID Context,
    [in, optional] POPLOCK_WAIT_COMPLETE_ROUTINE CompletionRoutine,
    [in, optional] POPLOCK_FS_PREPOST_IRP PostIrpRoutine
);

NTHALAPI LARGE_INTEGER KeQueryPerformanceCounter(
    [out, optional] PLARGE_INTEGER PerformanceFrequency
);

NTSYSAPI PUNICODE_PREFIX_TABLE_ENTRY RtlNextUnicodePrefix(
    [in] PUNICODE_PREFIX_TABLE PrefixTable,
    [in] BOOLEAN Restart
);

void CcGetFileSizePointer(
    FO
);

LONG KeReadStateQueue(
    PRKQUEUE Queue
);

NTSYSAPI VOID RtlInitializeUnicodePrefix(
    [out] PUNICODE_PREFIX_TABLE PrefixTable
);

BOOLEAN MmIsRecursiveIoFault();

BOOLEAN CcCopyWriteWontFlush(
    [in] PFILE_OBJECT FileObject,
    [in] PLARGE_INTEGER FileOffset,
    [in] ULONG Length
);

NTSTATUS PsLookupProcessByProcessId(
    [in] HANDLE ProcessId,
    [out] PEPROCESS *Process
);

NTSYSAPI NTSTATUS RtlGetAcesBufferSize(
    PACL Acl,
    PULONG AcesBufferSize
);

NTSYSAPI BOOLEAN RtlIsCloudFilesPlaceholder(
    [in] ULONG FileAttributes,
    [in] ULONG ReparseTag
);

ULONG MmDoesFileHaveUserWritableReferences(
    [in] PSECTION_OBJECT_POINTERS SectionPointer
);

void PsDereferenceImpersonationToken(
    [in] PACCESS_TOKEN ImpersonationToken
);

BOOLEAN PsIsDiskCountersEnabled();

void SeLengthSid(
    Sid
);

NTSTATUS IoReplaceFileObjectName(
    [in] PFILE_OBJECT FileObject,
    [in] PWSTR NewFileName,
    [in] USHORT FileNameLength
);

void PoDeletePowerRequest(
    [in, out] PVOID PowerRequest
);

__kernel_entry NTSYSCALLAPI NTSTATUS NtSetSecurityObject(
    [in] HANDLE Handle,
    [in] SECURITY_INFORMATION SecurityInformation,
    [in] PSECURITY_DESCRIPTOR SecurityDescriptor
);

NTSYSAPI PVOID RtlCreateHeap(
    [in] ULONG Flags,
    [in, optional] PVOID HeapBase,
    [in, optional] SIZE_T ReserveSize,
    [in, optional] SIZE_T CommitSize,
    [in, optional] PVOID Lock,
    [in, optional] PRTL_HEAP_PARAMETERS Parameters
);

NTSTATUS IoSynchronousPageWrite(
    PFILE_OBJECT FileObject,
    PMDL MemoryDescriptorList,
    PLARGE_INTEGER StartingOffset,
    PKEVENT Event,
    PIO_STATUS_BLOCK IoStatusBlock
);

__kernel_entry NTSYSCALLAPI NTSTATUS NtQueryInformationFile(
    [in] HANDLE FileHandle,
    [out] PIO_STATUS_BLOCK IoStatusBlock,
    [out] PVOID FileInformation,
    [in] ULONG Length,
    [in] FILE_INFORMATION_CLASS FileInformationClass
);

NTSTATUS FsRtlFastUnlockSingle(
    [in] PFILE_LOCK FileLock,
    [in] PFILE_OBJECT FileObject,
    [in] LARGE_INTEGER *FileOffset,
    [in] PLARGE_INTEGER Length,
    [in] PEPROCESS ProcessId,
    [in] ULONG Key,
    [in, optional] PVOID Context,
    [in] BOOLEAN AlreadySynchronized
);

PDEVICE_OBJECT IoGetAttachedDevice(
    [in] PDEVICE_OBJECT DeviceObject
);

BOOLEAN FsRtlIsDaxVolume(
    [in] PFILE_OBJECT FileObject
);

VOID SEC_ENTRY SecFreeCallContext();

NTSYSAPI NTSTATUS RtlUnicodeToOemN(
    [out] PCHAR OemString,
    [in] ULONG MaxBytesInOemString,
    [out, optional] PULONG BytesInOemString,
    [in] PCWCH UnicodeString,
    [in] ULONG BytesInUnicodeString
);

void CcSetReadAheadGranularity(
    [in] PFILE_OBJECT FileObject,
    [in] ULONG Granularity
);

NTSYSAPI VOID RtlSecondsSince1980ToTime(
    [in] ULONG ElapsedSeconds,
    [out] PLARGE_INTEGER Time
);

PLIST_ENTRY KeRundownQueue(
    [in, out] PRKQUEUE Queue
);

BOOLEAN PsIsThreadTerminating(
    [in] PETHREAD Thread
);

void ObMakeTemporaryObject(
    PVOID Object
);

NTSYSAPI VOID RtlCopyLuid(
    [out] PLUID DestinationLuid,
    [in] PLUID SourceLuid
);

void FsRtlInitializeExtraCreateParameter(
    [in] PECP_HEADER Ecp,
    [in] ULONG EcpFlags,
    [in, optional] PFSRTL_EXTRA_CREATE_PARAMETER_CLEANUP_CALLBACK CleanupCallback,
    [in] ULONG TotalSize,
    [in] LPCGUID EcpType,
    [in, optional] PVOID ListAllocatedFrom
);

PEPROCESS FsRtlOplockGetAnyBreakOwnerProcess(
    POPLOCK Oplock
);

void REFS_VOLUME_DATA_BUFFER_CONTAINS_DRIVER_VERSION(
    VOLUME_DATA_BUFFER
);

void CcSetLogHandleForFile(
    [in] PFILE_OBJECT FileObject,
    [in] PVOID LogHandle,
    [in] PFLUSH_TO_LSN FlushToLsnRoutine
);

NTSTATUS FsRtlNormalizeNtstatus(
    [in] NTSTATUS Exception,
    [in] NTSTATUS GenericException
);

PACCESS_TOKEN PsReferenceImpersonationToken(
    [in, out] PETHREAD Thread,
    [out] PBOOLEAN CopyOnOpen,
    [out] PBOOLEAN EffectiveOnly,
    [out] PSECURITY_IMPERSONATION_LEVEL ImpersonationLevel
);

NTSYSAPI NTSTATUS ZwDeleteFile(
    [in] POBJECT_ATTRIBUTES ObjectAttributes
);

BOOLEAN FsRtlIsDbcsInExpression(
    [in] PANSI_STRING Expression,
    [in] PANSI_STRING Name
);

NTSTATUS FsRtlCheckOplockEx2(
    [in] POPLOCK Oplock,
    [in] PIRP Irp,
    [in] ULONG Flags,
    [in] ULONG FlagsEx2,
    [in, optional] PVOID CompletionRoutineContext,
    [in, optional] POPLOCK_WAIT_COMPLETE_ROUTINE CompletionRoutine,
    [in, optional] POPLOCK_FS_PREPOST_IRP PostIrpRoutine,
    [in] ULONGLONG Timeout,
    [in, optional] PVOID NotifyContext,
    [in, optional] POPLOCK_NOTIFY_ROUTINE NotifyRoutine
);

__kernel_entry NTSYSCALLAPI NTSTATUS NtQueryInformationToken(
    [in] HANDLE TokenHandle,
    [in] TOKEN_INFORMATION_CLASS TokenInformationClass,
    [out] PVOID TokenInformation,
    [in] ULONG TokenInformationLength,
    [out] PULONG ReturnLength
);

NTSTATUS ObQueryObjectAuditingByHandle(
    HANDLE Handle,
    PBOOLEAN GenerateOnClose
);

NTSYSAPI NTSTATUS RtlSelfRelativeToAbsoluteSD(
    [in] PSECURITY_DESCRIPTOR SelfRelativeSecurityDescriptor,
    [out] PSECURITY_DESCRIPTOR AbsoluteSecurityDescriptor,
    [in, out] PULONG AbsoluteSecurityDescriptorSize,
    [out] PACL Dacl,
    [in, out] PULONG DaclSize,
    [out] PACL Sacl,
    [in, out] PULONG SaclSize,
    [out] PSID Owner,
    [in, out] PULONG OwnerSize,
    [out] PSID PrimaryGroup,
    [in, out] PULONG PrimaryGroupSize
);

NTSTATUS SeSetSessionIdToken(
    PACCESS_TOKEN Token,
    ULONG SessionId
);

NTSYSAPI NTSTATUS ZwQueryVirtualMemory(
    [in] HANDLE ProcessHandle,
    [in, optional] PVOID BaseAddress,
    [in] MEMORY_INFORMATION_CLASS MemoryInformationClass,
    [out] PVOID MemoryInformation,
    [in] SIZE_T MemoryInformationLength,
    [out, optional] PSIZE_T ReturnLength
);

BOOLEAN FsRtlAddMcbEntry(
    PMCB Mcb,
    VBN Vbn,
    LBN Lbn,
    ULONG SectorCount
);

ULONG IoGetRequestorProcessId(
    [in] PIRP Irp
);

BOOLEAN FsRtlCurrentOplock(
    [in] POPLOCK Oplock
);

NTSYSAPI PVOID RtlDestroyHeap(
    [in] PVOID HeapHandle
);

NTSYSAPI ULONG RtlLengthSid(
    [in] PSID Sid
);

KSECDDDECLSPEC NTSTATUS SEC_ENTRY SecLookupWellKnownSid(
    [in] WELL_KNOWN_SID_TYPE SidType,
    [out] PSID Sid,
    [in] ULONG SidBufferSize,
    [in_out, optional] PULONG SidSize
);

void FsRtlFreeExtraCreateParameterList(
    [in] PECP_LIST EcpList
);

NTSYSAPI ULONG RtlNtStatusToDosErrorNoTeb(
    [in] NTSTATUS Status
);

NTSTATUS FsRtlInsertPerFileContext(
    [in] PVOID *PerFileContextPointer,
    [in] PFSRTL_PER_FILE_CONTEXT Ptr
);

NTSTATUS PoSetPowerRequest(
    [in, out] PVOID PowerRequest,
    [in] POWER_REQUEST_TYPE Type
);

PFILE_OBJECT CcGetFileObjectFromSectionPtrs(
    [in] PSECTION_OBJECT_POINTERS SectionObjectPointer
);

BOOLEAN IoIsOperationSynchronous(
    [in] PIRP Irp
);

BOOLEAN FsRtlCopyWrite(
    [in] PFILE_OBJECT FileObject,
    [in] PLARGE_INTEGER FileOffset,
    [in] ULONG Length,
    [in] BOOLEAN Wait,
    [in] ULONG LockKey,
    [in] PVOID Buffer,
    [out] PIO_STATUS_BLOCK IoStatus,
    [in] PDEVICE_OBJECT DeviceObject
);

PFSRTL_PER_FILE_CONTEXT FsRtlLookupPerFileContext(
    [in] PVOID *PerFileContextPointer,
    [in, optional] PVOID OwnerId,
    [in, optional] PVOID InstanceId
);

NTSYSAPI NTSTATUS ZwFlushBuffersFile(
    [in] HANDLE FileHandle,
    [out] PIO_STATUS_BLOCK IoStatusBlock
);

NTSTATUS IoCheckQuerySetVolumeInformation(
    FS_INFORMATION_CLASS FsInformationClass,
    ULONG Length,
    BOOLEAN SetOperation
);

NTSYSAPI NTSTATUS RtlReserveChunk(
    USHORT CompressionFormat,
    PUCHAR *CompressedBuffer,
    PUCHAR EndOfCompressedBufferPlus1,
    PUCHAR *ChunkBuffer,
    ULONG ChunkSize
);

void IoReleaseVpbSpinLock(
    [in] KIRQL Irql
);

NTSYSAPI NTSTATUS RtlSetGroupSecurityDescriptor(
    [in, out] PSECURITY_DESCRIPTOR SecurityDescriptor,
    [in, optional] PSID Group,
    [in, optional] BOOLEAN GroupDefaulted
);

BOOLEAN CcCopyWrite(
    [in] PFILE_OBJECT FileObject,
    [in] PLARGE_INTEGER FileOffset,
    [in] ULONG Length,
    [in] BOOLEAN Wait,
    [in] PVOID Buffer
);

void SeDeleteClientSecurity(
    PSECURITY_CLIENT_CONTEXT ClientContext
);

NTSTATUS FsRtlNotifyVolumeEvent(
    [in] PFILE_OBJECT FileObject,
    [in] ULONG EventCode
);

void SeCaptureSubjectContext(
    [out] PSECURITY_SUBJECT_CONTEXT SubjectContext
);

LONG KeReleaseMutant(
    PRKMUTANT Mutant,
    KPRIORITY Increment,
    BOOLEAN Abandoned,
    BOOLEAN Wait
);

NTSTATUS SEC_ENTRY MapSecurityError(
    SECURITY_STATUS SecStatus
);

NTSTATUS FsRtlIssueDeviceIoControl(
    [in] PDEVICE_OBJECT DeviceObject,
    [in] ULONG IoCtl,
    UCHAR Flags,
    [in, optional] PVOID InputBuffer,
    [in] ULONG InputBufferLength,
    [out, optional] PVOID OutputBuffer,
    [in] ULONG OutputBufferLength,
    [in] PULONG_PTR IosbInformation
);

NTSTATUS PsLookupThreadByThreadId(
    [in] HANDLE ThreadId,
    [out] PETHREAD *Thread
);

BOOLEAN CcZeroData(
    [in] PFILE_OBJECT FileObject,
    [in] PLARGE_INTEGER StartOffset,
    [in] PLARGE_INTEGER EndOffset,
    [in] BOOLEAN Wait
);

UCHAR KeSetIdealProcessorThread(
    PKTHREAD Thread,
    UCHAR Processor
);

__kernel_entry NTSYSCALLAPI NTSTATUS NtUnlockFile(
    [in] HANDLE FileHandle,
    [out] PIO_STATUS_BLOCK IoStatusBlock,
    [in] PLARGE_INTEGER ByteOffset,
    [in] PLARGE_INTEGER Length,
    [in] ULONG Key
);

PFSRTL_PER_FILEOBJECT_CONTEXT FsRtlLookupPerFileObjectContext(
    [in] PFILE_OBJECT FileObject,
    [in, optional] PVOID OwnerId,
    [in, optional] PVOID InstanceId
);

void ExAdjustLookasideDepth();

BOOLEAN FsRtlIsFatDbcsLegal(
    [in] ANSI_STRING DbcsName,
    [in] BOOLEAN WildCardsPermissible,
    [in] BOOLEAN PathNamePermissible,
    [in] BOOLEAN LeadingBackslashPermissible
);

LARGE_INTEGER CcGetDirtyPages(
    [in] PVOID LogHandle,
    [in] PDIRTY_PAGE_ROUTINE DirtyPageRoutine,
    [in] PVOID Context1,
    [in] PVOID Context2
);

void FsRtlUninitializeBaseMcb(
    PBASE_MCB Mcb
);

void CcFlushCache(
    [in] PSECTION_OBJECT_POINTERS SectionObjectPointer,
    [in, optional] PLARGE_INTEGER FileOffset,
    [in] ULONG Length,
    [out, optional] PIO_STATUS_BLOCK IoStatus
);

__kernel_entry NTSYSCALLAPI NTSTATUS NtSetInformationFile(
    [in] HANDLE FileHandle,
    [out] PIO_STATUS_BLOCK IoStatusBlock,
    [in] PVOID FileInformation,
    [in] ULONG Length,
    [in] FILE_INFORMATION_CLASS FileInformationClass
);

NTSYSAPI NTSTATUS RtlConvertSidToUnicodeString(
    [in, out] PUNICODE_STRING UnicodeString,
    [in] PSID Sid,
    [in] BOOLEAN AllocateDestinationString
);

void FsRtlNotifyFullReportChange(
    [in] PNOTIFY_SYNC NotifySync,
    [in] PLIST_ENTRY NotifyList,
    [in] PSTRING FullTargetName,
    [in] USHORT TargetNameOffset,
    [in, optional] PSTRING StreamName,
    [in, optional] PSTRING NormalizedParentName,
    [in] ULONG FilterMatch,
    [in] ULONG Action,
    [in, optional] PVOID TargetContext
);

BOOLEAN MmFlushImageSection(
    PSECTION_OBJECT_POINTERS SectionObjectPointer,
    [in] MMFLUSH_TYPE FlushType
);

void FsRtlGetPerStreamContextPointer(
    _fo
);

NTSTATUS IoGetDiskDeviceObject(
    [in] PDEVICE_OBJECT FileSystemDeviceObject,
    PDEVICE_OBJECT *DiskDeviceObject
);

void FsRtlNotifyInitializeSync(
    [in] PNOTIFY_SYNC *NotifySync
);

BOOLEAN FsRtlDoesNameContainWildCards(
    [in] PUNICODE_STRING Name
);

BOOLEAN CcCopyReadEx(
    [in] PFILE_OBJECT FileObject,
    [in] PLARGE_INTEGER FileOffset,
    [in] ULONG Length,
    [in] BOOLEAN Wait,
    [out] PVOID Buffer,
    [out] PIO_STATUS_BLOCK IoStatus,
    [in] PETHREAD IoIssuerThread
);

void IoStartNextPacketByKey(
    [in] PDEVICE_OBJECT DeviceObject,
    [in] BOOLEAN Cancelable,
    [in] ULONG Key
);

PIRP IoGetTopLevelIrp();

NTSYSAPI ULONG RtlLengthRequiredSid(
    [in] ULONG SubAuthorityCount
);

BOOLEAN SeTokenIsNoChildProcessRestrictionEnforced(
    [in] PACCESS_TOKEN Token,
    [out, optional] PBOOLEAN UnlessSecure
);

void FsRtlDeleteTunnelCache(
    [in] TUNNEL *Cache
);

BOOLEAN SeAuditingFileOrGlobalEvents(
    [in] BOOLEAN AccessGranted,
    [in] PSECURITY_DESCRIPTOR SecurityDescriptor,
    [in] PSECURITY_SUBJECT_CONTEXT SubjectSecurityContext
);

NTSTATUS IoCheckFunctionAccess(
    ACCESS_MASK GrantedAccess,
    UCHAR MajorFunction,
    UCHAR MinorFunction,
    ULONG IoControlCode,
    PVOID Arg1,
    PVOID Arg2
);

NTSYSAPI NTSTATUS ZwSetInformationToken(
    [in] HANDLE TokenHandle,
    [in] TOKEN_INFORMATION_CLASS TokenInformationClass,
    [in] PVOID TokenInformation,
    [in] ULONG TokenInformationLength
);

NTSYSAPI ULONG RtlRandom(
    [in, out] PULONG Seed
);

void FsRtlDeregisterUncProvider(
    [in] HANDLE Handle
);

void FsRtlResetLargeMcb(
    [in] PLARGE_MCB Mcb,
    [in] BOOLEAN SelfSynchronized
);

NTSTATUS IoQueryVolumeInformation(
    PFILE_OBJECT FileObject,
    FS_INFORMATION_CLASS FsInformationClass,
    ULONG Length,
    PVOID FsInformation,
    PULONG ReturnedLength
);

NTSYSAPI NTSTATUS RtlAbsoluteToSelfRelativeSD(
    [in] PSECURITY_DESCRIPTOR AbsoluteSecurityDescriptor,
    [out] PSECURITY_DESCRIPTOR SelfRelativeSecurityDescriptor,
    [in, out] PULONG BufferLength
);

NTSTATUS FsRtlBalanceReads(
    [in] PDEVICE_OBJECT TargetDevice
);

BOOLEAN FsRtlCheckLockForOplockRequest(
    [in] PFILE_LOCK FileLock,
    [in] PLARGE_INTEGER AllocationSize
);

BOOLEAN SeAccessCheckFromStateEx(
    PSECURITY_DESCRIPTOR SecurityDescriptor,
    PACCESS_TOKEN PrimaryToken,
    PACCESS_TOKEN ClientToken,
    ACCESS_MASK DesiredAccess,
    ACCESS_MASK PreviouslyGrantedAccess,
    PPRIVILEGE_SET *Privileges,
    PGENERIC_MAPPING GenericMapping,
    KPROCESSOR_MODE AccessMode,
    PACCESS_MASK GrantedAccess,
    PNTSTATUS AccessStatus
);

NTSYSAPI NTSTATUS RtlUnicodeStringToCountedOemString(
    POEM_STRING DestinationString,
    [in] PCUNICODE_STRING SourceString,
    [in] BOOLEAN AllocateDestinationString
);

void IoAcquireVpbSpinLock(
    [out] PKIRQL Irql
);

BOOLEAN FsRtlRemoveBaseMcbEntry(
    PBASE_MCB Mcb,
    LONGLONG Vbn,
    LONGLONG SectorCount
);

PFSRTL_PER_FILEOBJECT_CONTEXT FsRtlRemovePerFileObjectContext(
    [in] PFILE_OBJECT FileObject,
    [in, optional] PVOID OwnerId,
    [in, optional] PVOID InstanceId
);

