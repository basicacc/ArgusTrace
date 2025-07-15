CLFSUSER_API NTSTATUS ClfsTerminateReadLog(
    [in] PVOID pvCursorContext
);

void ExInitializeSetTimerParameters(
    [out] PEXT_SET_PARAMETERS Parameters
);

BOOLEAN IoCancelIrp(
    [in] PIRP Irp
);

void ExFreeToLookasideListEx(
    [in, out] PLOOKASIDE_LIST_EX Lookaside,
    [in] PVOID Entry
);

PVOID MmAllocateMappingAddressEx(
    SIZE_T NumberOfBytes,
    ULONG PoolTag,
    ULONG Flags
);

NTSTATUS TmRecoverEnlistment(
    [in] PKENLISTMENT Enlistment,
    [in] PVOID EnlistmentKey
);

NTSTATUS PoCallDriver(
    [in] PDEVICE_OBJECT DeviceObject,
    [in, out] __drv_aliasesMem PIRP Irp
);

NTSYSAPI VOID RtlSetBits(
    [in] PRTL_BITMAP BitMapHeader,
    [in] ULONG StartingIndex,
    [in] ULONG NumberToSet
);

LARGE_INTEGER ExInterlockedAddLargeInteger(
    [in, out] PLARGE_INTEGER Addend,
    [in] LARGE_INTEGER Increment,
    [in, out] PKSPIN_LOCK Lock
);

void IoBuildPartialMdl(
    [in] PMDL SourceMdl,
    [in, out] PMDL TargetMdl,
    [in] PVOID VirtualAddress,
    [in] ULONG Length
);

PIRP IoGetTopLevelIrp();

NTSTATUS IoReportTargetDeviceChangeAsynchronous(
    [in] PDEVICE_OBJECT PhysicalDeviceObject,
    [in] PVOID NotificationStructure,
    [in, optional] PDEVICE_CHANGE_COMPLETE_CALLBACK Callback,
    [in, out] PVOID Context
);

__kernel_entry NTSYSCALLAPI NTSTATUS NtReadOnlyEnlistment(
    [in] HANDLE EnlistmentHandle,
    [in, optional] PLARGE_INTEGER TmVirtualClock
);

NTSYSCALLAPI NTSTATUS ZwRecoverEnlistment(
    [in] HANDLE EnlistmentHandle,
    [in, optional] PVOID EnlistmentKey
);

NTSTATUS IoRegisterLastChanceShutdownNotification(
    [in] PDEVICE_OBJECT DeviceObject
);

PVOID MmAllocateContiguousMemorySpecifyCacheNode(
    [in] SIZE_T NumberOfBytes,
    [in] PHYSICAL_ADDRESS LowestAcceptableAddress,
    [in] PHYSICAL_ADDRESS HighestAcceptableAddress,
    [in, optional] PHYSICAL_ADDRESS BoundaryAddressMultiple,
    [in] MEMORY_CACHING_TYPE CacheType,
    [in] NODE_REQUIREMENT PreferredNode
);

void MmFreeMappingAddress(
    [in] PVOID BaseAddress,
    [in] ULONG PoolTag
);

ULONG KeQueryMaximumProcessorCountEx(
    [in] USHORT GroupNumber
);

void IoInitializeRemoveLock(
    [in] Lock,
    [in] Tag,
    [in] Maxmin,
    [in] HighWater
);

NTSYSAPI ULONG RtlFindFirstRunClear(
    [in] PRTL_BITMAP BitMapHeader,
    [out] PULONG StartingIndex
);

NTSYSAPI NTSTATUS ZwQueryInformationFile(
    [in] HANDLE FileHandle,
    [out] PIO_STATUS_BLOCK IoStatusBlock,
    [out] PVOID FileInformation,
    [in] ULONG Length,
    [in] FILE_INFORMATION_CLASS FileInformationClass
);

CLFSUSER_API NTSTATUS ClfsReserveAndAppendLogAligned(
    [in] PVOID pvMarshalContext,
    [in, optional] PCLFS_WRITE_ENTRY rgWriteEntries,
    [in] ULONG cWriteEntries,
    [in] ULONG cbEntryAlignment,
    [in, optional] PCLFS_LSN plsnUndoNext,
    [in, optional] PCLFS_LSN plsnPrevious,
    [in] ULONG cReserveRecords,
    [in, out] PLONGLONG rgcbReservation,
    [in] ULONG fFlags,
    [out, optional] PCLFS_LSN plsn
);

void ExFreePool2(
    PVOID P,
    ULONG Tag,
    PCPOOL_EXTENDED_PARAMETER ExtendedParameters,
    ULONG ExtendedParametersCount
);

NTSTATUS IoWMIOpenBlock(
    [in] LPCGUID Guid,
    [in] ULONG DesiredAccess,
    [out] PVOID *DataBlockObject
);

BOOLEAN IsListEmpty(
    [in] const LIST_ENTRY *ListHead
);

void PoFxIssueComponentPerfStateChangeMultiple(
    [in] POHANDLE Handle,
    [in] ULONG Flags,
    [in] ULONG Component,
    [in] ULONG PerfChangesCount,
    [in] PO_FX_PERF_STATE_CHANGE [] PerfChanges,
    [in] PVOID Context
);

PKDEVICE_QUEUE_ENTRY KeRemoveDeviceQueue(
    [in, out] PKDEVICE_QUEUE DeviceQueue
);

void RtlStoreUshort(
    [out] ADDRESS,
    [in] VALUE
);

NTSTATUS KeInitializeTriageDumpDataArray(
    PKTRIAGE_DUMP_DATA_ARRAY KtriageDumpDataArray,
    ULONG Size
);

NTSYSAPI NTSTATUS RtlVerifyVersionInfo(
    [in] PRTL_OSVERSIONINFOEXW VersionInfo,
    [in] ULONG TypeMask,
    [in] ULONGLONG ConditionMask
);

NTSTATUS TmDereferenceEnlistmentKey(
    [in] PKENLISTMENT Enlistment,
    [out, optional] PBOOLEAN LastReference
);

NTSTATUS IoOpenDeviceInterfaceRegistryKey(
    [in] PUNICODE_STRING SymbolicLinkName,
    [in] ACCESS_MASK DesiredAccess,
    [out] PHANDLE DeviceInterfaceRegKey
);

PIRP IoAllocateIrp(
    [in] CCHAR StackSize,
    [in] BOOLEAN ChargeQuota
);

PVOID MmAllocateContiguousNodeMemory(
    [in] SIZE_T NumberOfBytes,
    [in] PHYSICAL_ADDRESS LowestAcceptableAddress,
    [in] PHYSICAL_ADDRESS HighestAcceptableAddress,
    [in, optional] PHYSICAL_ADDRESS BoundaryAddressMultiple,
    [in] ULONG Protect,
    [in] NODE_REQUIREMENT PreferredNode
);

NTSTATUS TmEnableCallbacks(
    [in] PKRESOURCEMANAGER ResourceManager,
    [in] PTM_RM_NOTIFICATION CallbackRoutine,
    [in, optional] PVOID RMKey
);

CLFSUSER_API NTSTATUS ClfsReadRestartArea(
    [in, out] PVOID pvMarshalContext,
    [out] PVOID *ppvRestartBuffer,
    [out] PULONG pcbRestartBuffer,
    [out] PCLFS_LSN plsn,
    [out] PVOID *ppvReadContext
);

BOOLEAN ExAcquireRundownProtection(
    [in, out] PEX_RUNDOWN_REF RunRef
);

NTSTATUS KdChangeOption(
    [in] KD_OPTION Option,
    [in, optional] ULONG InBufferBytes,
    [in] PVOID InBuffer,
    [in, optional] ULONG OutBufferBytes,
    [out] PVOID OutBuffer,
    [out, optional] PULONG OutBufferNeeded
);

IO_PRIORITY_HINT IoGetIoPriorityHint(
    [in] PIRP Irp
);

CLFSUSER_API NTSTATUS ClfsSetLogFileInformation(
    [in] PLOG_FILE_OBJECT plfoLog,
    [in] CLFS_LOG_INFORMATION_CLASS eInformationClass,
    [in] PVOID pinfoBuffer,
    [in] ULONG cbBuffer
);

ULONG ExIsResourceAcquiredSharedLite(
    [in] PERESOURCE Resource
);

CLFSUSER_API NTSTATUS ClfsDeleteMarshallingArea(
    [in] PVOID pvMarshalContext
);

CLFSUSER_API NTSTATUS ClfsMgmtQueryPolicy(
    [in] PLOG_FILE_OBJECT LogFile,
    [in] CLFS_MGMT_POLICY_TYPE PolicyType,
    [out] PCLFS_MGMT_POLICY Policy,
    [out] PULONG PolicyLength
);

NTSYSAPI ULONG vDbgPrintEx(
    [in] ULONG ComponentId,
    [in] ULONG Level,
    [in] PCCH Format,
    [in] va_list arglist
);

void ExRundownCompletedCacheAware(
    [in, out] PEX_RUNDOWN_REF_CACHE_AWARE RunRefCacheAware
);

BOOLEAN ExTryToAcquireFastMutex(
    PFAST_MUTEX FastMutex
);

void BYTE_OFFSET(
    [in] Va
);

NTSTATUS IoCheckShareAccess(
    [in] ACCESS_MASK DesiredAccess,
    [in] ULONG DesiredShareAccess,
    [in, out] PFILE_OBJECT FileObject,
    [in, out] PSHARE_ACCESS ShareAccess,
    [in] BOOLEAN Update
);

NTSYSAPI WCHAR RtlUpcaseUnicodeChar(
    [in] WCHAR SourceCharacter
);

__analysis_noreturn VOID DbgBreakPoint();

void IoUpdateLinkShareAccess(
    [in] PFILE_OBJECT FileObject,
    [in, out] PSHARE_ACCESS ShareAccess,
    [in, out, optional] PLINK_SHARE_ACCESS LinkShareAccess
);

NTSTATUS TmPrepareComplete(
    [in] PKENLISTMENT Enlistment,
    [in] PLARGE_INTEGER TmVirtualClock
);

NTSYSCALLAPI NTSTATUS ZwCreateResourceManager(
    [out] PHANDLE ResourceManagerHandle,
    [in] ACCESS_MASK DesiredAccess,
    [in] HANDLE TmHandle,
    [in, optional] LPGUID ResourceManagerGuid,
    [in, optional] POBJECT_ATTRIBUTES ObjectAttributes,
    [in, optional] ULONG CreateOptions,
    [in, optional] PUNICODE_STRING Description
);

void ExAcquirePushLockExclusive(
    Lock
);

PVOID KeRegisterBoundCallback(
    [in] PBOUND_CALLBACK CallbackRoutine
);

void RtlEqualLuid(
    L1,
    L2
);

NTSTATUS CmCallbackGetKeyObjectIDEx(
    [in] PLARGE_INTEGER Cookie,
    [in] PVOID Object,
    [out, optional] PULONG_PTR ObjectID,
    [out, optional] PCUNICODE_STRING *ObjectName,
    [in] ULONG Flags
);

void MmInitializeMdl(
    [in] PMDL MemoryDescriptorList,
    [in] PVOID BaseVa,
    [in] SIZE_T Length
);

NTSTATUS ExSetFirmwareEnvironmentVariable(
    [in] PUNICODE_STRING VariableName,
    [in] LPGUID VendorGuid,
    [in] PVOID Value,
    [in] ULONG ValueLength,
    [in] ULONG Attributes
);

void KeQueryNodeActiveAffinity(
    [in] USHORT NodeNumber,
    [out, optional] PGROUP_AFFINITY Affinity,
    [out, optional] PUSHORT Count
);

NTSTATUS IoWMISetSingleItem(
    [in] PVOID DataBlockObject,
    [in] PUNICODE_STRING InstanceName,
    [in] ULONG DataItemId,
    [in] ULONG Version,
    [in] ULONG ValueBufferSize,
    [in] PVOID ValueBuffer
);

void KefAcquireSpinLockAtDpcLevel(
    PKSPIN_LOCK SpinLock
);

NTSYSCALLAPI NTSTATUS ZwCreateTransactionManager(
    [out] PHANDLE TmHandle,
    [in] ACCESS_MASK DesiredAccess,
    [in, optional] POBJECT_ATTRIBUTES ObjectAttributes,
    [in, optional] PUNICODE_STRING LogFileName,
    [in, optional] ULONG CreateOptions,
    [in, optional] ULONG CommitStrength
);

KAFFINITY KeQueryGroupAffinity(
    [in] USHORT GroupNumber
);

__kernel_entry NTSYSCALLAPI NTSTATUS NtRecoverResourceManager(
    [in] HANDLE ResourceManagerHandle
);

NTSTATUS MmAllocateMdlForIoSpace(
    [in] PMM_PHYSICAL_ADDRESS_LIST PhysicalAddressList,
    [in] SIZE_T NumberOfEntries,
    [out] PMDL *NewMdl
);

__kernel_entry NTSYSCALLAPI NTSTATUS NtRollbackEnlistment(
    [in] HANDLE EnlistmentHandle,
    [in, optional] PLARGE_INTEGER TmVirtualClock
);

NTSTATUS TmPrePrepareEnlistment(
    [in] PKENLISTMENT Enlistment,
    [in] PLARGE_INTEGER TmVirtualClock
);

NTSYSAPI ULONG RtlFindClearRuns(
    [in] PRTL_BITMAP BitMapHeader,
    [out] PRTL_BITMAP_RUN RunArray,
    [in] ULONG SizeOfRunArray,
    [in] BOOLEAN LocateLongestRuns
);

void ExInitializeNPagedLookasideList(
    [out] PNPAGED_LOOKASIDE_LIST Lookaside,
    [in, optional] PALLOCATE_FUNCTION Allocate,
    [in, optional] PFREE_FUNCTION Free,
    [in] ULONG Flags,
    [in] SIZE_T Size,
    [in] ULONG Tag,
    [in] USHORT Depth
);

ULONG KeQueryActiveProcessorCountEx(
    [in] USHORT GroupNumber
);

NTSYSCALLAPI NTSTATUS ZwRollbackEnlistment(
    [in] HANDLE EnlistmentHandle,
    [in, optional] PLARGE_INTEGER TmVirtualClock
);

void WRITE_REGISTER_BUFFER_UCHAR(
    [in] volatile UCHAR *Register,
    [in] PUCHAR Buffer,
    [in] ULONG Count
);

NTSYSCALLAPI NTSTATUS ZwCommitComplete(
    [in] HANDLE EnlistmentHandle,
    [in, optional] PLARGE_INTEGER TmVirtualClock
);

NTSTATUS IoSetCompletionRoutineEx(
    [in] PDEVICE_OBJECT DeviceObject,
    [in] PIRP Irp,
    [in] PIO_COMPLETION_ROUTINE CompletionRoutine,
    [in, optional] PVOID Context,
    [in] BOOLEAN InvokeOnSuccess,
    [in] BOOLEAN InvokeOnError,
    [in] BOOLEAN InvokeOnCancel
);

CLFSUSER_API NTSTATUS ClfsCloseAndResetLogFile(
    [in] PLOG_FILE_OBJECT plfoLog
);

PSINGLE_LIST_ENTRY PopEntryList(
    [in, out] PSINGLE_LIST_ENTRY ListHead
);

void ExReleaseRundownProtectionEx(
    [in, out] PEX_RUNDOWN_REF RunRef,
    [in] ULONG Count
);

NTSYSAPI NTSTATUS RtlInitUTF8StringEx(
    PUTF8_STRING DestinationString,
    __drv_aliasesMem PCSZ SourceString
);

NTSTATUS MmMapMdl(
    [in] PMDL MemoryDescriptorList,
    [in] ULONG Protection,
    [in] PMM_MDL_ROUTINE DriverRoutine,
    [in] PVOID DriverContext
);

void READ_REGISTER_BUFFER_USHORT(
    [in] volatile USHORT *Register,
    [out] PUSHORT Buffer,
    [in] ULONG Count
);

LONG InterlockedExchangeAdd(
    [in, out] LONG volatile *Addend,
    [in] LONG Value
);

NTSTATUS IoGetContainerInformation(
    [in] IO_CONTAINER_INFORMATION_CLASS InformationClass,
    [in, optional] PVOID ContainerObject,
    [in, out] PVOID Buffer,
    [in] ULONG BufferLength
);

NTSTATUS EtwRegister(
    [in] LPCGUID ProviderId,
    [in, optional] PETWENABLECALLBACK EnableCallback,
    [in, optional] PVOID CallbackContext,
    [out] PREGHANDLE RegHandle
);

void IosbToIosb64(
    _iosb64,
    _iosb
);

void ExReleasePushLockShared(
    Lock
);

NTSTATUS IoWriteKsrPersistentMemory(
    PVOID DataHandle,
    PVOID Buffer,
    SIZE_T Size
);

FIRMWARE_TYPE ExGetFirmwareType();

ULONG KeQueryActiveProcessorCount(
    [out, optional] PKAFFINITY ActiveProcessors
);

void RtlZeroMemory(
    void* Destination,
    size_t Length
);

PVOID ExEnterCriticalRegionAndAcquireResourceExclusive(
    PERESOURCE Resource
);

PVOID MmGetSystemAddressForMdlSafe(
    [in] PMDL Mdl,
    [in] ULONG Priority
);

NTSTATUS PoFxRegisterCrashdumpDevice(
    POHANDLE Handle
);

PSLIST_ENTRY ExpInterlockedPopEntrySList(
    PSLIST_HEADER ListHead
);

void ExReleaseResourceForThreadLite(
    [in, out] PERESOURCE Resource,
    [in] ERESOURCE_THREAD ResourceThreadId
);

void ObReleaseObjectSecurity(
    [in] PSECURITY_DESCRIPTOR SecurityDescriptor,
    [in] BOOLEAN MemoryAllocated
);

PVOID MmLockPagableDataSection(
    [in] PVOID AddressWithinSection
);

NTHALAPI VOID WRITE_PORT_UCHAR(
    [in] PUCHAR Port,
    [in] UCHAR Value
);

void IoFreeIrp(
    [in] PIRP Irp
);

BOOLEAN KeAreAllApcsDisabled();

PVOID MmAllocateMappingAddress(
    [in] SIZE_T NumberOfBytes,
    [in] ULONG PoolTag
);

void PoFxIdleComponent(
    [in] POHANDLE Handle,
    [in] ULONG Component,
    [in] ULONG Flags
);

void IoUnregisterContainerNotification(
    [in] PVOID CallbackRegistration
);

NTSTATUS PoFxSetTargetDripsDevicePowerState(
    [in] POHANDLE Handle,
    [in] DEVICE_POWER_STATE TargetState
);

CLFSUSER_API NTSTATUS ClfsAddLogContainerSet(
    [in] PLOG_FILE_OBJECT plfoLog,
    [in] USHORT cContainers,
    [in, optional] PULONGLONG pcbContainer,
    [in] PUNICODE_STRING rguszContainerPath
);

void IoFreeMdl(
    [in] PMDL Mdl
);

NTSTATUS ExReinitializeResourceLite(
    [in, out] PERESOURCE Resource
);

void IoFreeErrorLogEntry(
    [in] PVOID ElEntry
);

_DECL_HAL_KE_IMPORT KIRQL KeRaiseIrqlToDpcLevel();

__drv_aliasesMem PVOID IoGetDriverObjectExtension(
    [in] PDRIVER_OBJECT DriverObject,
    [in] PVOID ClientIdentificationAddress
);

__kernel_entry NTSYSCALLAPI NTSTATUS NtRecoverEnlistment(
    [in] HANDLE EnlistmentHandle,
    [in, optional] PVOID EnlistmentKey
);

NTSYSAPI NTSTATUS ZwUnloadDriver(
    [in] PUNICODE_STRING DriverServiceName
);

NTSTATUS PsAllocateAffinityToken(
    [out] PAFFINITY_TOKEN *AffinityToken
);

NTSYSAPI VOID RtlFreeAnsiString(
    [in, out] PANSI_STRING AnsiString
);

__kernel_entry NTSYSCALLAPI NTSTATUS NtSetInformationTransactionManager(
    [in, optional] HANDLE TmHandle,
    [in] TRANSACTIONMANAGER_INFORMATION_CLASS TransactionManagerInformationClass,
    [in] PVOID TransactionManagerInformation,
    [in] ULONG TransactionManagerInformationLength
);

PLIST_ENTRY ExInterlockedInsertHeadList(
    [in, out] PLIST_ENTRY ListHead,
    [in, out] __drv_aliasesMem PLIST_ENTRY ListEntry,
    [in, out] PKSPIN_LOCK Lock
);

void PoFxCompleteIdleCondition(
    [in] POHANDLE Handle,
    [in] ULONG Component
);

NTSYSAPI NTSTATUS ZwOpenKey(
    [out] PHANDLE KeyHandle,
    [in] ACCESS_MASK DesiredAccess,
    [in] POBJECT_ATTRIBUTES ObjectAttributes
);

void IoSetCompletionRoutine(
    [in] PIRP Irp,
    [in, optional] PIO_COMPLETION_ROUTINE CompletionRoutine,
    [in, optional] __drv_aliasesMem PVOID Context,
    [in] BOOLEAN InvokeOnSuccess,
    [in] BOOLEAN InvokeOnError,
    [in] BOOLEAN InvokeOnCancel
);

NTSYSAPI VOID RtlCopyMemoryNonTemporal(
    VOID *Destination,
    const VOID *Source,
    SIZE_T Length
);

volatile void * RtlZeroDeviceMemory(
    [out] volatile void *Destination,
    [in] size_t Length
);

PIRP IoCsqRemoveNextIrp(
    [in, out] PIO_CSQ Csq,
    [in, optional] PVOID PeekContext
);

NTSYSAPI NTSTATUS ZwEnumerateValueKey(
    [in] HANDLE KeyHandle,
    [in] ULONG Index,
    [in] KEY_VALUE_INFORMATION_CLASS KeyValueInformationClass,
    [out, optional] PVOID KeyValueInformation,
    [in] ULONG Length,
    [out] PULONG ResultLength
);

void RtlInitEmptyUnicodeString(
    [out] PUNICODE_STRING UnicodeString,
    [in] __drv_aliasesMem PWCHAR Buffer,
    [in] USHORT BufferSize
);

void IoMarkIrpPending(
    [in, out] PIRP Irp
);

PMDL MmAllocatePagesForMdlEx(
    [in] PHYSICAL_ADDRESS LowAddress,
    [in] PHYSICAL_ADDRESS HighAddress,
    [in] PHYSICAL_ADDRESS SkipBytes,
    [in] SIZE_T TotalBytes,
    [in] MEMORY_CACHING_TYPE CacheType,
    [in] ULONG Flags
);

NTSYSAPI NTSTATUS ZwCreateKeyTransacted(
    [out] PHANDLE KeyHandle,
    [in] ACCESS_MASK DesiredAccess,
    [in] POBJECT_ATTRIBUTES ObjectAttributes,
    ULONG TitleIndex,
    [in, optional] PUNICODE_STRING Class,
    [in] ULONG CreateOptions,
    [in] HANDLE TransactionHandle,
    [out, optional] PULONG Disposition
);

void IofCompleteRequest(
    PIRP Irp,
    CCHAR PriorityBoost
);

BOOLEAN KeRegisterBugCheckReasonCallback(
    [out] PKBUGCHECK_REASON_CALLBACK_RECORD CallbackRecord,
    [in] PKBUGCHECK_REASON_CALLBACK_ROUTINE CallbackRoutine,
    [in] KBUGCHECK_CALLBACK_REASON Reason,
    [in] PUCHAR Component
);

BOOLEAN ExSetTimer(
    [in] PEX_TIMER Timer,
    [in] LONGLONG DueTime,
    [in] LONGLONG Period,
    [in, optional] PEXT_SET_PARAMETERS Parameters
);

PVOID MmPageEntireDriver(
    [in] PVOID AddressWithinSection
);

void PoFxReportDevicePoweredOn(
    [in] POHANDLE Handle
);

NTSTATUS ExGetFirmwareEnvironmentVariable(
    [in] PUNICODE_STRING VariableName,
    [in] LPGUID VendorGuid,
    [out, optional] PVOID Value,
    [in, out] PULONG ValueLength,
    [out, optional] PULONG Attributes
);

ULONG DbgPrint(
    PCSTR Format,
    ...
);

NTSYSAPI ULONG DbgPrintEx(
    [in] ULONG ComponentId,
    [in] ULONG Level,
    [in] PCSTR Format,
    ...
);

NTSTATUS IoAcquireKsrPersistentMemory(
    PDRIVER_OBJECT DriverObject,
    PDEVICE_OBJECT PhysicalDeviceObject,
    PVOID Buffer,
    PSIZE_T Size
);

CLFSUSER_API NTSTATUS ClfsMgmtRemovePolicy(
    [in] PLOG_FILE_OBJECT LogFile,
    [in] CLFS_MGMT_POLICY_TYPE PolicyType
);

CLFSUSER_API NTSTATUS ClfsSetArchiveTail(
    [in] PLOG_FILE_OBJECT plfoLog,
    [in] PCLFS_LSN plsnArchiveTail
);

void KeQueryTickCount(
    [out] CurrentCount
);

NTHALAPI VOID WRITE_PORT_BUFFER_USHORT(
    [in] PUSHORT Port,
    [in] PUSHORT Buffer,
    [in] ULONG Count
);

NTSYSAPI NTSTATUS ZwDeleteKey(
    [in] HANDLE KeyHandle
);

CLFSUSER_API NTSTATUS ClfsCreateMarshallingAreaEx(
    PLOG_FILE_OBJECT plfoLog,
    POOL_TYPE ePoolType,
    PALLOCATE_FUNCTION pfnAllocBuffer,
    PFREE_FUNCTION pfnFreeBuffer,
    ULONG cbMarshallingBuffer,
    ULONG cMaxWriteBuffers,
    ULONG cMaxReadBuffers,
    ULONG cAlignmentSize,
    ULONGLONG fFlags,
    PVOID *ppvMarshalContext
);

void IoSizeOfIrp(
    [in] StackSize
);

CLFSUSER_API NTSTATUS ClfsMgmtDeregisterManagedClient(
    CLFS_MGMT_CLIENT ClientCookie
);

void PoUnregisterSystemState(
    [in, out] PVOID StateHandle
);

PIRP IoAllocateIrpEx(
    PDEVICE_OBJECT DeviceObject,
    CCHAR StackSize,
    BOOLEAN ChargeQuota
);

void ObReferenceObject(
    [in] Object
);

NTSTATUS ObRegisterCallbacks(
    [in] POB_CALLBACK_REGISTRATION CallbackRegistration,
    [out] PVOID *RegistrationHandle
);

void ExLocalTimeToSystemTime(
    [in] PLARGE_INTEGER LocalTime,
    [out] PLARGE_INTEGER SystemTime
);

NTSYSAPI NTSTATUS RtlAnsiStringToUnicodeString(
    [in, out] PUNICODE_STRING DestinationString,
    [in] PCANSI_STRING SourceString,
    [in] BOOLEAN AllocateDestinationString
);

void RtlStoreUlonglong(
    [out] ADDRESS,
    [in] VALUE
);

NTSYSAPI ULONG RtlLengthSecurityDescriptor(
    [in] PSECURITY_DESCRIPTOR SecurityDescriptor
);

NTSTATUS IoAllocateDriverObjectExtension(
    [in] PDRIVER_OBJECT DriverObject,
    [in] PVOID ClientIdentificationAddress,
    [in] ULONG DriverObjectExtensionSize,
    [out] PVOID *DriverObjectExtension
);

void IoDisconnectInterruptEx(
    [in, out] PIO_DISCONNECT_INTERRUPT_PARAMETERS Parameters
);

PVOID CmGetBoundTransaction(
    [in] PLARGE_INTEGER Cookie,
    [in] PVOID Object
);

LONG KeSetEvent(
    [in, out] PRKEVENT Event,
    [in] KPRIORITY Increment,
    [in] BOOLEAN Wait
);

NTSTATUS PoFxRegisterDevice(
    [in] PDEVICE_OBJECT Pdo,
    [in] PPO_FX_DEVICE Device,
    [out] POHANDLE *Handle
);

NTSTATUS CmUnRegisterCallback(
    [in] LARGE_INTEGER Cookie
);

void RtlUnicodeStringToAnsiSize(
    [in] STRING
);

NTSTATUS TmRollbackEnlistment(
    [in] PKENLISTMENT Enlistment,
    [in] PLARGE_INTEGER TmVirtualClock
);

unsigned char _BitTestAndComplement64(
    __int64 *Base,
    __int64 Index
);

NTSTATUS TmInitializeTransactionManager(
    [in] PRKTM TransactionManager,
    [in, optional] PCUNICODE_STRING LogFileName,
    [in] PGUID TmId,
    [in, optional] ULONG CreateOptions
);

NTSTATUS PoRegisterPowerSettingCallback(
    [in, optional] PDEVICE_OBJECT DeviceObject,
    [in] LPCGUID SettingGuid,
    [in] PPOWER_SETTING_CALLBACK Callback,
    [in, optional] PVOID Context,
    [out] PVOID *Handle
);

NTSYSAPI VOID RtlClearBit(
    [in] PRTL_BITMAP BitMapHeader,
    [in] ULONG BitNumber
);

void IoQueueWorkItem(
    [in] __drv_aliasesMem PIO_WORKITEM IoWorkItem,
    [in] PIO_WORKITEM_ROUTINE WorkerRoutine,
    [in] WORK_QUEUE_TYPE QueueType,
    [in, optional] __drv_aliasesMem PVOID Context
);

NTSYSAPI ULONG RtlxUnicodeStringToAnsiSize(
    [in] PCUNICODE_STRING UnicodeString
);

void MmFreeContiguousMemory(
    [in] PVOID BaseAddress
);

void KeInitializeGuardedMutex(
    [out] PKGUARDED_MUTEX Mutex
);

void BarrierAfterRead();

BOOLEAN IoIs32bitProcess(
    [in, optional] PIRP Irp
);

NTSYSAPI NTSTATUS ZwOpenSymbolicLinkObject(
    [out] PHANDLE LinkHandle,
    [in] ACCESS_MASK DesiredAccess,
    [in] POBJECT_ATTRIBUTES ObjectAttributes
);

void ExReleaseSpinLockSharedFromDpcLevel(
    PEX_SPIN_LOCK SpinLock
);

NTSTATUS SeAssignSecurityEx(
    [in, optional] PSECURITY_DESCRIPTOR ParentDescriptor,
    [in, optional] PSECURITY_DESCRIPTOR ExplicitDescriptor,
    [out] PSECURITY_DESCRIPTOR *NewDescriptor,
    [in, optional] GUID *ObjectType,
    [in] BOOLEAN IsDirectoryObject,
    [in] ULONG AutoInheritFlags,
    [in] PSECURITY_SUBJECT_CONTEXT SubjectContext,
    [in] PGENERIC_MAPPING GenericMapping,
    [in] POOL_TYPE PoolType
);

NTSTATUS IoWMIWriteEvent(
    [in, out] PVOID WnodeEventItem
);

void PoEndDeviceBusy(
    [in, out] PULONG IdlePointer
);

LOGICAL ExTryConvertSharedSpinLockExclusive(
    [in, out] PEX_SPIN_LOCK SpinLock
);

PKDEVICE_QUEUE_ENTRY KeRemoveByKeyDeviceQueue(
    [in, out] PKDEVICE_QUEUE DeviceQueue,
    [in] ULONG SortKey
);

PETHREAD PsGetCurrentThread();

NTSTATUS KdEnableDebugger();

NTSYSAPI NTSTATUS ZwWriteFile(
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

KIRQL KzRaiseIrql(
    [in] KIRQL NewIrql
);

void AppendTailList(
    [in, out] PLIST_ENTRY ListHead,
    [in, out] PLIST_ENTRY ListToAppend
);

NTSYSCALLAPI NTSTATUS ZwRecoverTransactionManager(
    [in] HANDLE TransactionManagerHandle
);

void PoStartNextPowerIrp(
    [in, out] PIRP Irp
);

void SeLockSubjectContext(
    [in] PSECURITY_SUBJECT_CONTEXT SubjectContext
);

__kernel_entry NTSYSCALLAPI NTSTATUS NtRollbackComplete(
    [in] HANDLE EnlistmentHandle,
    [in, optional] PLARGE_INTEGER TmVirtualClock
);

BOOLEAN KeInsertDeviceQueue(
    [in, out] PKDEVICE_QUEUE DeviceQueue,
    [in, out] PKDEVICE_QUEUE_ENTRY DeviceQueueEntry
);

NTSTATUS IoGetDeviceProperty(
    [in] PDEVICE_OBJECT DeviceObject,
    [in] DEVICE_REGISTRY_PROPERTY DeviceProperty,
    [in] ULONG BufferLength,
    [out, optional] PVOID PropertyBuffer,
    [out] PULONG ResultLength
);

NTSTATUS KeDeregisterBoundCallback(
    [in] PVOID Handle
);

LOGICAL KeIsExecutingDpc();

NTSTATUS ObReferenceObjectByHandleWithTag(
    [in] HANDLE Handle,
    [in] ACCESS_MASK DesiredAccess,
    [in, optional] POBJECT_TYPE ObjectType,
    [in] KPROCESSOR_MODE AccessMode,
    [in] ULONG Tag,
    [out] PVOID *Object,
    [out, optional] POBJECT_HANDLE_INFORMATION HandleInformation
);

NTSTATUS IoOpenDeviceRegistryKey(
    [in] PDEVICE_OBJECT DeviceObject,
    [in] ULONG DevInstKeyType,
    [in] ACCESS_MASK DesiredAccess,
    [out] PHANDLE DeviceRegKey
);

void BarrierAfterRead();

NTSTATUS KeGetProcessorNumberFromIndex(
    [in] ULONG ProcIndex,
    [out] PPROCESSOR_NUMBER ProcNumber
);

PSINGLE_LIST_ENTRY ExInterlockedPushEntryList(
    [in, out] PSINGLE_LIST_ENTRY ListHead,
    [in, out] __drv_aliasesMem PSINGLE_LIST_ENTRY ListEntry,
    [in, out] PKSPIN_LOCK Lock
);

void IoAcquireCancelSpinLock(
    PKIRQL Irql
);

PVOID ExAllocatePoolQuotaZero(
    __drv_strictTypeMatch(__drv_typeExpr)POOL_TYPE PoolType,
    SIZE_T NumberOfBytes,
    ULONG Tag
);

void RtlInitEmptyAnsiString(
    [out] PANSI_STRING AnsiString,
    [in] __drv_aliasesMem PCHAR Buffer,
    [in] USHORT BufferSize
);

ULONG64 KeQueryInterruptTimePrecise(
    [out] PULONG64 QpcTimeStamp
);

NTSTATUS IoCsqInitialize(
    [out] PIO_CSQ Csq,
    [in] PIO_CSQ_INSERT_IRP CsqInsertIrp,
    [in] PIO_CSQ_REMOVE_IRP CsqRemoveIrp,
    [in] PIO_CSQ_PEEK_NEXT_IRP CsqPeekNextIrp,
    [in] PIO_CSQ_ACQUIRE_LOCK CsqAcquireLock,
    [in] PIO_CSQ_RELEASE_LOCK CsqReleaseLock,
    [in] PIO_CSQ_COMPLETE_CANCELED_IRP CsqCompleteCanceledIrp
);

PVOID PoRegisterSystemState(
    [in, out] PVOID StateHandle,
    [in] EXECUTION_STATE Flags
);

void KeInitializeDpc(
    [out] __drv_aliasesMem PRKDPC Dpc,
    [in] PKDEFERRED_ROUTINE DeferredRoutine,
    [in, optional] __drv_aliasesMem PVOID DeferredContext
);

void WriteUInt32Release(
    UINT32 volatile *Destination,
    UINT32 Value
);

void ExReleaseRundownProtectionCacheAwareEx(
    [in, out] PEX_RUNDOWN_REF_CACHE_AWARE RunRef,
    [in] ULONG Count
);

NTSTATUS ExDeleteResourceLite(
    [in, out] PERESOURCE Resource
);

void IoFreeWorkItem(
    [in] PIO_WORKITEM IoWorkItem
);

NTSYSAPI NTSTATUS ZwCreateSection(
    [out] PHANDLE SectionHandle,
    [in] ACCESS_MASK DesiredAccess,
    [in, optional] POBJECT_ATTRIBUTES ObjectAttributes,
    [in, optional] PLARGE_INTEGER MaximumSize,
    [in] ULONG SectionPageProtection,
    [in] ULONG AllocationAttributes,
    [in, optional] HANDLE FileHandle
);

void ExReleaseFastMutexUnsafe(
    PFAST_MUTEX FastMutex
);

NTSTATUS KeConvertPerformanceCounterToAuxiliaryCounter(
    [in] ULONG64 PerformanceCounterValue,
    [out] PULONG64 AuxiliaryCounterValue,
    [out, optional] PULONG64 ConversionError
);

NTSTATUS TmRollbackComplete(
    [in] PKENLISTMENT Enlistment,
    [in] PLARGE_INTEGER TmVirtualClock
);

NTSYSCALLAPI NTSTATUS ZwOpenTransactionManager(
    [out] PHANDLE TmHandle,
    [in] ACCESS_MASK DesiredAccess,
    [in, optional] POBJECT_ATTRIBUTES ObjectAttributes,
    [in, optional] PUNICODE_STRING LogFileName,
    [in, optional] LPGUID TmIdentity,
    [in, optional] ULONG OpenOptions
);

NTSTATUS IoWMIExecuteMethod(
    [in] PVOID DataBlockObject,
    [in] PUNICODE_STRING InstanceName,
    [in] ULONG MethodId,
    [in] ULONG InBufferSize,
    [in, out] PULONG OutBufferSize,
    [in, out] PUCHAR InOutBuffer
);

__kernel_entry NTSYSCALLAPI NTSTATUS NtOpenResourceManager(
    [out] PHANDLE ResourceManagerHandle,
    [in] ACCESS_MASK DesiredAccess,
    [in] HANDLE TmHandle,
    [in] LPGUID ResourceManagerGuid,
    [in, optional] POBJECT_ATTRIBUTES ObjectAttributes
);

NTSTATUS CmRegisterCallback(
    [in] PEX_CALLBACK_FUNCTION Function,
    [in, optional] PVOID Context,
    [out] PLARGE_INTEGER Cookie
);

void IoUpdateLinkShareAccessEx(
    PFILE_OBJECT FileObject,
    PSHARE_ACCESS ShareAccess,
    PLINK_SHARE_ACCESS LinkShareAccess,
    ULONG IoShareAccessFlags
);

KIRQL ExAcquireSpinLockExclusive(
    PEX_SPIN_LOCK SpinLock
);

NTSTATUS KeRestoreFloatingPointState(
    [in] PKFLOATING_SAVE FloatSave
);

PDEVICE_OBJECT IoGetAttachedDeviceReference(
    [in] PDEVICE_OBJECT DeviceObject
);

BOOLEAN KeSetTimerEx(
    [in, out] PKTIMER Timer,
    [in] LARGE_INTEGER DueTime,
    [in] LONG Period,
    [in, optional] PKDPC Dpc
);

void MmResetDriverPaging(
    [in] PVOID AddressWithinSection
);

void KeReleaseInStackQueuedSpinLockFromDpcLevel(
    [in] PKLOCK_QUEUE_HANDLE LockHandle
);

void RtlMoveMemory(
    void* Destination,
    const void* Source,
    size_t Length
);

NTSTATUS PsCreateSystemThread(
    [out] PHANDLE ThreadHandle,
    [in] ULONG DesiredAccess,
    [in, optional] POBJECT_ATTRIBUTES ObjectAttributes,
    [in, optional] HANDLE ProcessHandle,
    [out, optional] PCLIENT_ID ClientId,
    [in] PKSTART_ROUTINE StartRoutine,
    [in, optional] PVOID StartContext
);

NTSTATUS TmCommitComplete(
    [in] PKENLISTMENT Enlistment,
    [in] PLARGE_INTEGER TmVirtualClock
);

__kernel_entry NTSYSCALLAPI NTSTATUS NtCommitTransaction(
    [in] HANDLE TransactionHandle,
    [in] BOOLEAN Wait
);

CLFSUSER_API NTSTATUS ClfsMgmtSetLogFileSize(
    [in] PLOG_FILE_OBJECT LogFile,
    [in] PULONGLONG NewSizeInContainers,
    [out] PULONGLONG ResultingSizeInContainers,
    [in, optional] PCLFS_SET_LOG_SIZE_COMPLETE_CALLBACK CompletionRoutine,
    [in, optional] PVOID CompletionRoutineData
);

PDEVICE_OBJECT IoGetRelatedDeviceObject(
    [in] PFILE_OBJECT FileObject
);

CLFSUSER_API BOOLEAN ClfsLsnEqual(
    [in] const CLFS_LSN *plsn1,
    [in] const CLFS_LSN *plsn2
);

PVOID KeRegisterProcessorChangeCallback(
    [in] PPROCESSOR_CALLBACK_FUNCTION CallbackFunction,
    [in, optional] PVOID CallbackContext,
    [in] ULONG Flags
);

PEX_TIMER ExAllocateTimer(
    [in, optional] PEXT_CALLBACK Callback,
    [in, optional] PVOID CallbackContext,
    [in] ULONG Attributes
);

void WRITE_REGISTER_BUFFER_USHORT(
    [in] volatile USHORT *Register,
    [in] PUSHORT Buffer,
    [in] ULONG Count
);

NTSTATUS KeSetTargetProcessorDpcEx(
    [in, out] PKDPC Dpc,
    [in] PPROCESSOR_NUMBER ProcNumber
);

NTSTATUS IoSetDevicePropertyData(
    [in] PDEVICE_OBJECT Pdo,
    [in] const DEVPROPKEY *PropertyKey,
    [in] LCID Lcid,
    [in] ULONG Flags,
    [in] DEVPROPTYPE Type,
    [in] ULONG Size,
    [in, optional] PVOID Data
);

CLFSUSER_API NTSTATUS ClfsRemoveLogContainerSet(
    [in] PLOG_FILE_OBJECT plfoLog,
    [in] USHORT cContainers,
    [in] PUNICODE_STRING rgwszContainerPath,
    [in] BOOLEAN fForce
);

NTSYSAPI ULONG vDbgPrintExWithPrefix(
    [in] PCCH Prefix,
    [in] ULONG ComponentId,
    [in] ULONG Level,
    [in] PCCH Format,
    [in] va_list arglist
);

PSLIST_ENTRY ExpInterlockedPushEntrySList(
    PSLIST_HEADER ListHead,
    __drv_aliasesMem PSLIST_ENTRY ListEntry
);

void ExDeleteNPagedLookasideList(
    [in, out] PNPAGED_LOOKASIDE_LIST Lookaside
);

NTSTATUS IoSetDeviceInterfaceState(
    [in] PUNICODE_STRING SymbolicLinkName,
    [in] BOOLEAN Enable
);

void IoStartNextPacketByKey(
    [in] PDEVICE_OBJECT DeviceObject,
    [in] BOOLEAN Cancelable,
    [in] ULONG Key
);

void IoCopyCurrentIrpStackLocationToNext(
    [in, out] PIRP Irp
);

__drv_aliasesMem PIRP IoBuildSynchronousFsdRequest(
    [in] ULONG MajorFunction,
    [in] PDEVICE_OBJECT DeviceObject,
    [in, out] PVOID Buffer,
    [in, optional] ULONG Length,
    [in, optional] PLARGE_INTEGER StartingOffset,
    [in] PKEVENT Event,
    [out] PIO_STATUS_BLOCK IoStatusBlock
);

NTSYSAPI NTSTATUS RtlDeleteRegistryValue(
    [in] ULONG RelativeTo,
    [in] PCWSTR Path,
    [in] PCWSTR ValueName
);

void ExQueueWorkItem(
    [in, out] __drv_aliasesMem PWORK_QUEUE_ITEM WorkItem,
    [in] WORK_QUEUE_TYPE QueueType
);

void IMAGE_POLICY_OVERRIDE(
    _PolicyId_
);

BOOLEAN SeValidSecurityDescriptor(
    [in] ULONG Length,
    [in] PSECURITY_DESCRIPTOR SecurityDescriptor
);

PEX_RUNDOWN_REF_CACHE_AWARE ExAllocateCacheAwareRundownProtection(
    [in] __drv_strictTypeMatch(__drv_typeExpr)POOL_TYPE PoolType,
    [in] ULONG PoolTag
);

PEPROCESS IoGetCurrentProcess();

NTSTATUS IoGetDriverDirectory(
    [_In_] PDRIVER_OBJECT DriverObject,
    [_In_] DRIVER_DIRECTORY_TYPE DirectoryType,
    [_In_] ULONG Flags,
    [_Out_] PHANDLE DriverDirectoryHandle
);

void PoStartDeviceBusy(
    [in, out] PULONG IdlePointer
);

LONG KeReadStateMutex(
    [in] PRKMUTEX Mutex
);

PVOID ExRegisterCallback(
    [in, out] PCALLBACK_OBJECT CallbackObject,
    [in] PCALLBACK_FUNCTION CallbackFunction,
    [in, optional] PVOID CallbackContext
);

LONG InterlockedExchange(
    [in, out] LONG volatile *Target,
    [in] LONG Value
);

PVOID ExAllocateFromLookasideListEx(
    [in, out] PLOOKASIDE_LIST_EX Lookaside
);

NTSTATUS IoGetDeviceInterfacePropertyData(
    [in] PUNICODE_STRING SymbolicLinkName,
    [in] const DEVPROPKEY *PropertyKey,
    [in] LCID Lcid,
    ULONG Flags,
    [in] ULONG Size,
    [out] PVOID Data,
    [out] PULONG RequiredSize,
    [out] PDEVPROPTYPE Type
);

void IoReleaseRemoveLock(
    [in] RemoveLock,
    [in] Tag
);

NTSTATUS
    KeWaitForSingleObject (
    PVOID Object,
    KWAIT_REASON WaitReason,
    KPROCESSOR_MODE WaitMode,
    BOOLEAN Alertable,
    PLARGE_INTEGER Timeout
);

__kernel_entry NTSYSCALLAPI NTSTATUS NtPrePrepareEnlistment(
    [in] HANDLE EnlistmentHandle,
    [in, optional] PLARGE_INTEGER TmVirtualClock
);

NTSYSAPI VOID RtlFreeUnicodeString(
    [in, out] PUNICODE_STRING UnicodeString
);

void ExAcquireSpinLockExclusiveAtDpcLevel(
    [in, out] PEX_SPIN_LOCK SpinLock
);

USHORT KeQueryActiveGroupCount();

NTSYSAPI VOID RtlInitAnsiString(
    [out] PANSI_STRING DestinationString,
    [in, optional] __drv_aliasesMem PCSZ SourceString
);

BOOLEAN RtlCheckBit(
    [in] PRTL_BITMAP BitMapHeader,
    [in] ULONG BitPosition
);

NTSTATUS ExSecurePoolUpdate(
    [in] HANDLE SecurePoolHandle,
    [in] ULONG Tag,
    [in] PVOID Allocation,
    [in] ULONG_PTR Cookie,
    [in] SIZE_T Offset,
    [in] SIZE_T Size,
    [in] PVOID Buffer
);

void RtlRetrieveUlong(
    [out] DEST_ADDRESS,
    [in] SRC_ADDRESS
);

void InsertHeadList(
    [in, out] PLIST_ENTRY ListHead,
    [in, out] __drv_aliasesMem PLIST_ENTRY Entry
);

void PAGE_ALIGN(
    [in] Va
);

void ExInitializePagedLookasideList(
    [out] PPAGED_LOOKASIDE_LIST Lookaside,
    [in, optional] PALLOCATE_FUNCTION Allocate,
    [in, optional] PFREE_FUNCTION Free,
    [in] ULONG Flags,
    [in] SIZE_T Size,
    [in] ULONG Tag,
    [in] USHORT Depth
);

void IoUpdateShareAccess(
    [in] PFILE_OBJECT FileObject,
    [in, out] PSHARE_ACCESS ShareAccess
);

CLFSUSER_API BOOLEAN ClfsLsnLess(
    [in] const CLFS_LSN *plsn1,
    [in] const CLFS_LSN *plsn2
);

BOOLEAN KeAreApcsDisabled();

INT32 ReadInt32Acquire(
    INT32 const volatile *Source
);

NTSYSAPI ULONG RtlFindLastBackwardRunClear(
    [in] PRTL_BITMAP BitMapHeader,
    [in] ULONG FromIndex,
    [out] PULONG StartingRunIndex
);

LONG KeReadStateEvent(
    [in] PRKEVENT Event
);

PVOID MmGetSystemRoutineAddressEx(
    PUNICODE_STRING ModuleName,
    PSTR FunctionName
);

NTSTATUS EtwWriteEx(
    [in] REGHANDLE RegHandle,
    [in] PCEVENT_DESCRIPTOR EventDescriptor,
    [in] ULONG64 Filter,
    [in] ULONG Flags,
    [in, optional] LPCGUID ActivityId,
    [in, optional] LPCGUID RelatedActivityId,
    [in] ULONG UserDataCount,
    [in, optional] PEVENT_DATA_DESCRIPTOR UserData
);

PDRIVER_CANCEL IoSetCancelRoutine(
    [in] PIRP Irp,
    [in] PDRIVER_CANCEL CancelRoutine
);

volatile void * RtlFillVolatileMemory(
    [out] volatile void *Destination,
    [in] size_t Length,
    [in] int Fill
);

NTSYSAPI CCHAR RtlFindLeastSignificantBit(
    [in] ULONGLONG Set
);

NTSYSAPI NTSTATUS RtlQueryRegistryValues(
    [in] ULONG RelativeTo,
    [in] PCWSTR Path,
    [in, out] PRTL_QUERY_REGISTRY_TABLE QueryTable,
    [in, optional] PVOID Context,
    [in, optional] PVOID Environment
);

NTSTATUS KdDisableDebugger();

BOOLEAN ExAcquireSharedWaitForExclusive(
    [in, out] PERESOURCE Resource,
    [in] BOOLEAN Wait
);

void KeQuerySystemTime(
    [out] PLARGE_INTEGER CurrentTime
);

PVOID ExAllocatePoolWithTagPriority(
    [in] __drv_strictTypeMatch(__drv_typeCond)POOL_TYPE PoolType,
    [in] SIZE_T NumberOfBytes,
    [in] ULONG Tag,
    [in] __drv_strictTypeMatch(__drv_typeExpr)EX_POOL_PRIORITY Priority
);

void ExDestroyPool(
    HANDLE PoolHandle
);

void WriteUInt32Raw(
    UINT32 volatile *Destination,
    UINT32 Value
);

NTSTATUS IoCheckLinkShareAccess(
    [in] ACCESS_MASK DesiredAccess,
    [in] ULONG DesiredShareAccess,
    [in, out, optional] PFILE_OBJECT FileObject,
    [in, out, optional] PSHARE_ACCESS ShareAccess,
    [in, out, optional] PLINK_SHARE_ACCESS LinkShareAccess,
    [in] ULONG IoShareAccessFlags
);

NTSTATUS PoClearPowerRequest(
    [in, out] PVOID PowerRequest,
    [in] POWER_REQUEST_TYPE Type
);

CLFSUSER_API NTSTATUS ClfsFlushToLsn(
    [in] PVOID pvMarshalContext,
    [in] PCLFS_LSN plsnFlush,
    [out, optional] PCLFS_LSN plsnLastFlushed
);

NTKERNELAPI
    PSLIST_ENTRY
    FASTCALL
    ExInterlockedFlushSList (
    _Inout_ PSLIST_HEADER ListHead
);

__kernel_entry NTSYSCALLAPI NTSTATUS NtOpenTransactionManager(
    [out] PHANDLE TmHandle,
    [in] ACCESS_MASK DesiredAccess,
    [in, optional] POBJECT_ATTRIBUTES ObjectAttributes,
    [in, optional] PUNICODE_STRING LogFileName,
    [in, optional] LPGUID TmIdentity,
    [in, optional] ULONG OpenOptions
);

ULONG_PTR IoGetRemainingStackSize();

__kernel_entry NTSYSCALLAPI NTSTATUS NtEnumerateTransactionObject(
    [in, optional] HANDLE RootObjectHandle,
    [in] KTMOBJECT_TYPE QueryType,
    [in, out] PKTMOBJECT_CURSOR ObjectCursor,
    [in] ULONG ObjectCursorLength,
    [out] PULONG ReturnLength
);

void ExWaitForRundownProtectionRelease(
    [in, out] PEX_RUNDOWN_REF RunRef
);

void IoRequestDpc(
    [in] PDEVICE_OBJECT DeviceObject,
    [in] PIRP Irp,
    [in] __drv_aliasesMem PVOID Context
);

__kernel_entry NTSYSCALLAPI NTSTATUS NtSetInformationResourceManager(
    HANDLE ResourceManagerHandle,
    RESOURCEMANAGER_INFORMATION_CLASS ResourceManagerInformationClass,
    PVOID ResourceManagerInformation,
    ULONG ResourceManagerInformationLength
);

void ExReleaseSpinLockExclusiveFromDpcLevel(
    PEX_SPIN_LOCK SpinLock
);

NTSYSAPI BOOLEAN RtlEqualUnicodeString(
    [in] PCUNICODE_STRING String1,
    [in] PCUNICODE_STRING String2,
    [in] BOOLEAN CaseInSensitive
);

NTSYSCALLAPI NTSTATUS ZwReadOnlyEnlistment(
    [in] HANDLE EnlistmentHandle,
    [in, optional] PLARGE_INTEGER TmVirtualClock
);

NTSYSAPI NTSTATUS ZwMapViewOfSection(
    [in] HANDLE SectionHandle,
    [in] HANDLE ProcessHandle,
    [in, out] PVOID *BaseAddress,
    [in] ULONG_PTR ZeroBits,
    [in] SIZE_T CommitSize,
    [in, out, optional] PLARGE_INTEGER SectionOffset,
    [in, out] PSIZE_T ViewSize,
    [in] SECTION_INHERIT InheritDisposition,
    [in] ULONG AllocationType,
    [in] ULONG Win32Protect
);

NTSTATUS ExInitializeDeviceAts(
    _DEVICE_OBJECT *PhysicalDeviceObject,
    ULONG Flags
);

LONG CDECL_NON_WVMPURE InterlockedDecrement(
    [in, out] LONG volatile *Addend
);

void ExSetResourceOwnerPointer(
    [in, out] PERESOURCE Resource,
    [in] PVOID OwnerPointer
);

void WriteInt32Raw(
    INT32 volatile *Destination,
    INT32 Value
);

void ARM64_SYSREG_CRN(
    _Reg_
);

NTSTATUS PoUnregisterFromEffectivePowerModeNotifications(
    PO_EPM_HANDLE RegistrationHandle
);

void ProbeForWrite(
    [in, out] volatile VOID *Address,
    [in] SIZE_T Length,
    [in] ULONG Alignment
);

NTSYSAPI NTSTATUS ZwCreateDirectoryObject(
    [out] PHANDLE DirectoryHandle,
    [in] ACCESS_MASK DesiredAccess,
    [in] POBJECT_ATTRIBUTES ObjectAttributes
);

NTSTATUS IoAcquireKsrPersistentMemoryEx(
    PDRIVER_OBJECT DriverObject,
    PDEVICE_OBJECT PhysicalDeviceObject,
    PUNICODE_STRING PhysicalDeviceId,
    PUSHORT DataTag,
    PULONG DataVersion,
    PVOID Buffer,
    PSIZE_T Size
);

ULONG READ_REGISTER_ULONG(
    [in] volatile ULONG *Register
);

BOOLEAN KeCancelTimer(
    [in, out] PKTIMER unnamedParam1
);

void READ_REGISTER_BUFFER_ULONG(
    [in] volatile ULONG *Register,
    [out] PULONG Buffer,
    [in] ULONG Count
);

NTSYSAPI NTSTATUS ZwLoadDriver(
    [in] PUNICODE_STRING DriverServiceName
);

NTSYSAPI VOID RtlClearBits(
    [in] PRTL_BITMAP BitMapHeader,
    [in] ULONG StartingIndex,
    [in] ULONG NumberToClear
);

NTSYSAPI BOOLEAN RtlValidRelativeSecurityDescriptor(
    [in] PSECURITY_DESCRIPTOR SecurityDescriptorInput,
    [in] ULONG SecurityDescriptorLength,
    [in] SECURITY_INFORMATION RequiredInformation
);

CLFSUSER_API NTSTATUS ClfsMgmtInstallPolicy(
    [in] PLOG_FILE_OBJECT LogFile,
    [in] PCLFS_MGMT_POLICY Policy,
    [in] ULONG PolicyLength
);

void KeReleaseGuardedMutex(
    [in, out] PKGUARDED_MUTEX Mutex
);

NTSTATUS TmCommitEnlistment(
    [in] PKENLISTMENT Enlistment,
    [in] PLARGE_INTEGER TmVirtualClock
);

LONG KeResetEvent(
    [in, out] PRKEVENT Event
);

void RtlSecureZeroMemory(
    Ptr,
    [in] cnt
);

ULONG KeGetRecommendedSharedDataAlignment();

NTSTATUS TmReferenceEnlistmentKey(
    [in] PKENLISTMENT Enlistment,
    [out] PVOID *Key
);

NTSYSAPI ULONG RtlFindSetBits(
    [in] PRTL_BITMAP BitMapHeader,
    [in] ULONG NumberToFind,
    [in] ULONG HintIndex
);

NTSTATUS KeDelayExecutionThread(
    [in] KPROCESSOR_MODE WaitMode,
    [in] BOOLEAN Alertable,
    [in] PLARGE_INTEGER Interval
);

LOGICAL IoWithinStackLimits(
    [in] ULONG_PTR RegionStart,
    [in] SIZE_T RegionSize
);

PVOID MmGetSystemRoutineAddress(
    [in] PUNICODE_STRING SystemRoutineName
);

void ExReleaseRundownProtectionCacheAware(
    [in, out] PEX_RUNDOWN_REF_CACHE_AWARE RunRefCacheAware
);

void ObReferenceObjectWithTag(
    [in] Object,
    [in] Tag
);

ULONG64 PsQueryTotalCycleTimeProcess(
    [in, out] PEPROCESS Process,
    [out] PULONG64 CycleTimeStamp
);

NTSYSCALLAPI NTSTATUS ZwCreateTransaction(
    [out] PHANDLE TransactionHandle,
    [in] ACCESS_MASK DesiredAccess,
    [in, optional] POBJECT_ATTRIBUTES ObjectAttributes,
    [in, optional] LPGUID Uow,
    [in, optional] HANDLE TmHandle,
    [in, optional] ULONG CreateOptions,
    [in, optional] ULONG IsolationLevel,
    [in, optional] ULONG IsolationFlags,
    [in, optional] PLARGE_INTEGER Timeout,
    [in, optional] PUNICODE_STRING Description
);

NTSTATUS TmRollbackTransaction(
    [in] PKTRANSACTION Transaction,
    [in] BOOLEAN Wait
);

KIRQL ExAcquireSpinLockShared(
    [in, out] PEX_SPIN_LOCK SpinLock
);

void KeInitializeThreadedDpc(
    [out] PRKDPC Dpc,
    [in] PKDEFERRED_ROUTINE DeferredRoutine,
    [in, optional] PVOID DeferredContext
);

LONG CDECL_NON_WVMPURE InterlockedCompareExchange(
    [in, out] LONG volatile *Destination,
    [in] LONG ExChange,
    [in] LONG Comperand
);

NTSTATUS IoFreeKsrPersistentMemory(
    PVOID DataHandle
);

void KeSetSystemAffinityThread(
    [in] KAFFINITY Affinity
);

void CmGetCallbackVersion(
    [out, optional] PULONG Major,
    [out, optional] PULONG Minor
);

POWER_STATE PoSetPowerState(
    [in] PDEVICE_OBJECT DeviceObject,
    [in] POWER_STATE_TYPE Type,
    [in] POWER_STATE State
);

void PoFxCompleteDevicePowerNotRequired(
    [in] POHANDLE Handle
);

NTSTATUS WmiQueryTraceInformation(
    [in] TRACE_INFORMATION_CLASS TraceInformationClass,
    [out] PVOID TraceInformation,
    [in] ULONG TraceInformationLength,
    [out, optional] PULONG RequiredLength,
    [in, optional] PVOID Buffer
);

PVOID
    MmGetMdlVirtualAddress (
    _In_ PMDL Mdl
);

NTSTATUS IoGetDevicePropertyData(
    [in] PDEVICE_OBJECT Pdo,
    [in] const DEVPROPKEY *PropertyKey,
    [in] LCID Lcid,
    ULONG Flags,
    [in] ULONG Size,
    [out] PVOID Data,
    [out] PULONG RequiredSize,
    [out] PDEVPROPTYPE Type
);

CLFSUSER_API NTSTATUS ClfsDeleteLogFile(
    [in] PUNICODE_STRING puszLogFileName,
    PVOID pvReserved,
    [in] ULONG fLogOptionFlag,
    [in, optional] PVOID pvContext,
    [in] ULONG cbContext
);

void PsFreeAffinityToken(
    _Frees_ptr_ PAFFINITY_TOKEN AffinityToken
);

NTSTATUS PcwAddInstance(
    [in] PPCW_BUFFER Buffer,
    [in] PCUNICODE_STRING Name,
    [in] ULONG Id,
    [in] ULONG Count,
    [in] PPCW_DATA Data
);

void KeInitializeTimerEx(
    [out] PKTIMER Timer,
    [in] TIMER_TYPE Type
);

BOOLEAN RtlIsServicePackVersionInstalled(
    [in] ULONG Version
);

void RtlFillMemory(
    void* Destination,
    size_t Length
    int Fill
);

void MmUnmapLockedPages(
    [in] PVOID BaseAddress,
    [in] PMDL MemoryDescriptorList
);

NTSYSAPI VOID RtlTimeToTimeFields(
    [in] PLARGE_INTEGER Time,
    [out] PTIME_FIELDS TimeFields
);

NTSYSAPI NTSTATUS ZwQuerySymbolicLinkObject(
    [in] HANDLE LinkHandle,
    [in, out] PUNICODE_STRING LinkTarget,
    [out, optional] PULONG ReturnedLength
);

NTSTATUS PsSetSystemMultipleGroupAffinityThread(
    [in] PGROUP_AFFINITY GroupAffinities,
    [in] USHORT GroupCount,
    [in, out] PAFFINITY_TOKEN AffinityToken
);

NTSYSAPI NTSTATUS ZwFlushKey(
    [in] HANDLE KeyHandle
);

__analysis_noreturn NTSYSAPI VOID DbgBreakPointWithStatus(
    [in] ULONG Status
);

KAFFINITY KeQueryActiveProcessors();

void IoRemoveLinkShareAccess(
    [in] PFILE_OBJECT FileObject,
    [in, out] PSHARE_ACCESS ShareAccess,
    [in, out, optional] PLINK_SHARE_ACCESS LinkShareAccess
);

void SeCaptureSubjectContext(
    [out] PSECURITY_SUBJECT_CONTEXT SubjectContext
);

void ExAcquireFastMutex(
    PFAST_MUTEX FastMutex
);

__kernel_entry NTSYSCALLAPI NTSTATUS NtSetInformationTransaction(
    [in] HANDLE TransactionHandle,
    [in] TRANSACTION_INFORMATION_CLASS TransactionInformationClass,
    [in] PVOID TransactionInformation,
    [in] ULONG TransactionInformationLength
);

void KdBreakPointWithStatus(
    [in] s
);

NTSTATUS KeDeregisterNmiCallback(
    [in] PVOID Handle
);

NTSYSAPI NTSTATUS RtlHashUnicodeString(
    [in] PCUNICODE_STRING String,
    [in] BOOLEAN CaseInSensitive,
    [in] ULONG HashAlgorithm,
    [out] PULONG HashValue
);

void KeAcquireSpinLock(
    SpinLock,
    OldIrql
);

__kernel_entry NTSYSCALLAPI NTSTATUS NtSinglePhaseReject(
    [in] HANDLE EnlistmentHandle,
    [in, optional] PLARGE_INTEGER TmVirtualClock
);

CLFSUSER_API NTSTATUS ClfsCreateScanContext(
    [in] PLOG_FILE_OBJECT plfoLog,
    [in] ULONG cFromContainer,
    [in] ULONG cContainers,
    [in] CLFS_SCAN_MODE eScanMode,
    [in, out] PCLFS_SCAN_CONTEXT pcxScan
);

CLFSUSER_API NTSTATUS ClfsReadNextLogRecord(
    [in, out] PVOID pvReadContext,
    [out] PVOID *ppvBuffer,
    [out] PULONG pcbBuffer,
    [in, out] PCLFS_RECORD_TYPE peRecordType,
    [in, optional] PCLFS_LSN plsnUser,
    [out] PCLFS_LSN plsnUndoNext,
    [out] PCLFS_LSN plsnPrevious,
    [out] PCLFS_LSN plsnRecord
);

BOOLEAN ExAcquireRundownProtectionCacheAware(
    [in, out] PEX_RUNDOWN_REF_CACHE_AWARE RunRefCacheAware
);

void KeDeregisterProcessorChangeCallback(
    [in] PVOID CallbackHandle
);

NTSYSAPI NTSTATUS ZwMapViewOfSectionEx(
    [in] HANDLE SectionHandle,
    [in] HANDLE ProcessHandle,
    [in, out] PVOID *BaseAddress,
    [in, out, optional] PLARGE_INTEGER SectionOffset,
    [in, out] PSIZE_T ViewSize,
    [in] ULONG AllocationType,
    [in] ULONG PageProtection,
    [in, out, optional] PMEM_EXTENDED_PARAMETER ExtendedParameters,
    [in] ULONG ExtendedParameterCount
);

NTSTATUS IoCreateUnprotectedSymbolicLink(
    [in] PUNICODE_STRING SymbolicLinkName,
    [in] PUNICODE_STRING DeviceName
);

NTSTATUS PcwRegister(
    [out] PPCW_REGISTRATION *Registration,
    [in] PPCW_REGISTRATION_INFORMATION Info
);

void IoDeleteDevice(
    [in] PDEVICE_OBJECT DeviceObject
);

__kernel_entry NTSYSCALLAPI NTSTATUS NtRollbackTransaction(
    [in] HANDLE TransactionHandle,
    [in] BOOLEAN Wait
);

PPFN_NUMBER MmGetMdlPfnArray(
    _In_ PMDL Mdl
);

void MmUnmapIoSpace(
    [in] PVOID BaseAddress,
    [in] SIZE_T NumberOfBytes
);

NTSTATUS IoConnectInterruptEx(
    [in, out] PIO_CONNECT_INTERRUPT_PARAMETERS Parameters
);

BOOLEAN EtwProviderEnabled(
    [in] REGHANDLE RegHandle,
    [in] UCHAR Level,
    [in] ULONGLONG Keyword
);

BOOLEAN ExAcquireResourceExclusiveLite(
    [in, out] PERESOURCE Resource,
    [in] BOOLEAN Wait
);

NTSTATUS KeConvertAuxiliaryCounterToPerformanceCounter(
    [in] ULONG64 AuxiliaryCounterValue,
    [out] PULONG64 PerformanceCounterValue,
    [out, optional] PULONG64 ConversionError
);

CLFSUSER_API NTSTATUS ClfsGetContainerName(
    [in] PLOG_FILE_OBJECT plfoLog,
    [in] CLFS_CONTAINER_ID cidLogicalContainer,
    [out] PUNICODE_STRING puszContainerName,
    [out, optional] PULONG pcActualLenContainerName
);

NTSTATUS KeQueryLogicalProcessorRelationship(
    [in, optional] PPROCESSOR_NUMBER ProcessorNumber,
    [in] LOGICAL_PROCESSOR_RELATIONSHIP RelationshipType,
    [out, optional] PSYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX Information,
    [in, out] PULONG Length
);

NTSTATUS IoAttachDevice(
    [in] PDEVICE_OBJECT SourceDevice,
    [in] PUNICODE_STRING TargetDevice,
    [out] PDEVICE_OBJECT *AttachedDevice
);

void InsertTailList(
    [in, out] PLIST_ENTRY ListHead,
    [in, out] __drv_aliasesMem PLIST_ENTRY Entry
);

NTSTATUS ExCreateCallback(
    [out] PCALLBACK_OBJECT *CallbackObject,
    [in] POBJECT_ATTRIBUTES ObjectAttributes,
    [in] BOOLEAN Create,
    [in] BOOLEAN AllowMultipleCallbacks
);

void TmGetTransactionId(
    [in] PKTRANSACTION Transaction,
    [out] PUOW TransactionId
);

void MmPrepareMdlForReuse(
    [in] PMDL MDL
);

PVOID ExAllocateFromPagedLookasideList(
    [in, out] PPAGED_LOOKASIDE_LIST Lookaside
);

PIO_WORKITEM IoAllocateWorkItem(
    [in] PDEVICE_OBJECT DeviceObject
);

KIRQL KeAcquireSpinLockRaiseToDpc(
    PKSPIN_LOCK SpinLock
);

LONG CDECL_NON_WVMPURE InterlockedIncrement(
    [in, out] LONG volatile *Addend
);

void ExReleaseSpinLockExclusive(
    [in, out] PEX_SPIN_LOCK SpinLock,
    [in] KIRQL OldIrql
);

NTSYSAPI CCHAR RtlFindMostSignificantBit(
    [in] ULONGLONG Set
);

NTSTATUS IoInitializeTimer(
    [in] PDEVICE_OBJECT DeviceObject,
    [in] PIO_TIMER_ROUTINE TimerRoutine,
    [in, optional] __drv_aliasesMem PVOID Context
);

void IoInvalidateDeviceState(
    [in] PDEVICE_OBJECT PhysicalDeviceObject
);

ULONG ExInterlockedAddUlong(
    [in, out] PULONG Addend,
    [in] ULONG Increment,
    [in, out] PKSPIN_LOCK Lock
);

__kernel_entry NTSYSCALLAPI NTSTATUS NtQueryInformationTransactionManager(
    [in] HANDLE TransactionManagerHandle,
    [in] TRANSACTIONMANAGER_INFORMATION_CLASS TransactionManagerInformationClass,
    [out] PVOID TransactionManagerInformation,
    [in] ULONG TransactionManagerInformationLength,
    [out, optional] PULONG ReturnLength
);

NTSYSAPI NTSTATUS RtlCreateRegistryKey(
    [in] ULONG RelativeTo,
    [in] PWSTR Path
);

NTSYSAPI NTSTATUS ZwQueryFullAttributesFile(
    [in] POBJECT_ATTRIBUTES ObjectAttributes,
    [out] PFILE_NETWORK_OPEN_INFORMATION FileInformation
);

NTSTATUS KeQueryNodeActiveAffinity2(
    [in] USHORT NodeNumber,
    [out] PGROUP_AFFINITY GroupAffinities,
    [in] USHORT GroupAffinitiesCount,
    [out] PUSHORT GroupAffinitiesRequired
);

void MmFreePagesFromMdl(
    [in] PMDL MemoryDescriptorList
);

NTSTATUS
    KeWaitForMultipleObjects (
    ULONG Count,
    PVOID Object[],
    WaitType,
    KWAIT_REASON WaitReason,
    KPROCESSOR_MODE WaitMode,
    BOOLEAN Alertable,
    PLARGE_INTEGER Timeout,
    PKWAIT_BLOCK WaitBlockArray
);

NTHALAPI ULONG READ_PORT_ULONG(
    [in] PULONG Port
);

CLFSUSER_API NTSTATUS ClfsMgmtSetLogFileSizeAsClient(
    [in] PLOG_FILE_OBJECT LogFile,
    [in, optional] CLFS_MGMT_CLIENT ClientCookie,
    [in] PULONGLONG NewSizeInContainers,
    [out, optional] PULONGLONG ResultingSizeInContainers,
    [in, optional] PCLFS_SET_LOG_SIZE_COMPLETE_CALLBACK CompletionRoutine,
    [in, optional] PVOID CompletionRoutineData
);

void MmUnlockPages(
    [in, out] PMDL MemoryDescriptorList
);

INT32 ReadInt32Raw(
    INT32 const volatile *Source
);

ULONG KeGetCurrentProcessorNumberEx(
    [out, optional] PPROCESSOR_NUMBER ProcNumber
);

NTSTATUS IoGetDeviceDirectory(
    [_In_] PDEVICE_OBJECT PhysicalDeviceObject,
    [_In_] DEVICE_DIRECTORY_TYPE DirectoryType,
    [_In_] ULONG Flags,
    [_In_] PVOID Reserved,
    [_Out_] PHANDLE DeviceDirectoryHandle
);

NTSTATUS PoFxQueryCurrentComponentPerfState(
    [in] POHANDLE Handle,
    [in] ULONG Flags,
    [in] ULONG Component,
    [in] ULONG SetIndex,
    [in] PULONGLONG CurrentPerf
);

NTSYSAPI NTSTATUS RtlUnicodeStringToUTF8String(
    PUTF8_STRING DestinationString,
    PCUNICODE_STRING SourceString,
    BOOLEAN AllocateDestinationString
);

void ExReleasePushLockExclusive(
    Lock
);

void FIELD_OFFSET(
    [in] type,
    [in] field
);

PVOID MmMapLockedPagesWithReservedMapping(
    [in] PVOID MappingAddress,
    [in] ULONG PoolTag,
    [in] PMDL MemoryDescriptorList,
    [in] __drv_strictTypeMatch(__drv_typeCond)MEMORY_CACHING_TYPE CacheType
);

__drv_aliasesMem PIRP IoBuildDeviceIoControlRequest(
    [in] ULONG IoControlCode,
    [in] PDEVICE_OBJECT DeviceObject,
    [in, optional] PVOID InputBuffer,
    [in] ULONG InputBufferLength,
    [out, optional] PVOID OutputBuffer,
    [in] ULONG OutputBufferLength,
    [in] BOOLEAN InternalDeviceIoControl,
    [in, optional] PKEVENT Event,
    [out] PIO_STATUS_BLOCK IoStatusBlock
);

NTSYSAPI NTSTATUS RtlGUIDFromString(
    [in] PCUNICODE_STRING GuidString,
    [out] GUID *Guid
);

PVOID InterlockedCompareExchangePointer(
    [in, out] PVOID volatile *Destination,
    [in] PVOID Exchange,
    [in] PVOID Comperand
);

void PoFxSetDeviceIdleTimeout(
    [in] POHANDLE Handle,
    [in] ULONGLONG IdleTimeout
);

NTSTATUS WmiTraceMessage(
    [in] TRACELOGGER_HANDLE LoggerHandle,
    [in] ULONG MessageFlags,
    [in] LPCGUID MessageGuid,
    [in] USHORT MessageNumber,
    ...
);

NTSYSCALLAPI NTSTATUS ZwRollforwardTransactionManager(
    [in] HANDLE TransactionManagerHandle,
    [in, optional] PLARGE_INTEGER TmVirtualClock
);

void ExReleaseResourceLite(
    [in, out] PERESOURCE Resource
);

NTSTATUS PoRegisterForEffectivePowerModeNotifications(
    ULONG Version,
    PPO_EFFECTIVE_POWER_MODE_CALLBACK Callback,
    PVOID Context,
    PO_EPM_HANDLE *RegistrationHandle,
    PDEVICE_OBJECT DeviceObject
);

NTSYSAPI SIZE_T RtlCompareMemory(
    [in] const VOID *Source1,
    [in] const VOID *Source2,
    [in] SIZE_T Length
);

INT32 ReadInt32NoFence(
    INT32 const volatile *Source
);

void MmLockPagableCodeSection(
    [in] Address
);

NTHALAPI LARGE_INTEGER KeQueryPerformanceCounter(
    [out, optional] PLARGE_INTEGER PerformanceFrequency
);

void KeRevertToUserAffinityThreadEx(
    [in] KAFFINITY Affinity
);

void KeRevertToUserGroupAffinityThread(
    [in] PGROUP_AFFINITY PreviousAffinity
);

void IoStopTimer(
    [in] PDEVICE_OBJECT DeviceObject
);

ULONG KeQueryNodeActiveProcessorCount(
    [in] USHORT NodeNumber
);

DECLSPEC_DEPRECATED_DDK_WINXP LARGE_INTEGER NTAPI_INLINE RtlConvertLongToLargeInteger(
    [in] LONG SignedInteger
);

void IoSetLinkShareAccess(
    [in] ACCESS_MASK DesiredAccess,
    [in] ULONG DesiredShareAccess,
    [in, out] PFILE_OBJECT FileObject,
    [in, out] PSHARE_ACCESS ShareAccess,
    [in, out, optional] PLINK_SHARE_ACCESS LinkShareAccess,
    [in] ULONG IoShareAccessFlags
);

NTSTATUS IoWMIQueryAllDataMultiple(
    [in] PVOID *DataBlockObjectList,
    [in] ULONG ObjectCount,
    [in, out] PULONG InOutBufferSize,
    [out, optional] PVOID OutBuffer
);

__kernel_entry NTSYSCALLAPI NTSTATUS NtQueryInformationEnlistment(
    [in] HANDLE EnlistmentHandle,
    [in] ENLISTMENT_INFORMATION_CLASS EnlistmentInformationClass,
    [out] PVOID EnlistmentInformation,
    [in] ULONG EnlistmentInformationLength,
    [out, optional] PULONG ReturnLength
);

PDEVICE_OBJECT IoAttachDeviceToDeviceStack(
    [in] PDEVICE_OBJECT SourceDevice,
    [in] PDEVICE_OBJECT TargetDevice
);

void IoStartPacket(
    [in] PDEVICE_OBJECT DeviceObject,
    [in] PIRP Irp,
    [in, optional] PULONG Key,
    [in, optional] PDRIVER_CANCEL CancelFunction
);

void KzLowerIrql(
    [in] KIRQL NewIrql
);

NTSYSCALLAPI NTSTATUS ZwOpenTransaction(
    [out] PHANDLE TransactionHandle,
    [in] ACCESS_MASK DesiredAccess,
    [in, optional] POBJECT_ATTRIBUTES ObjectAttributes,
    [in] LPGUID Uow,
    [in, optional] HANDLE TmHandle
);

ULONGLONG KeQueryInterruptTime();

NTSTATUS IoSetIoPriorityHint(
    [in] PIRP Irp,
    [in] IO_PRIORITY_HINT PriorityHint
);

NTSYSAPI ULONG RtlFindNextForwardRunClear(
    [in] PRTL_BITMAP BitMapHeader,
    [in] ULONG FromIndex,
    [out] PULONG StartingRunIndex
);

__kernel_entry NTSYSCALLAPI NTSTATUS NtCommitEnlistment(
    [in] HANDLE EnlistmentHandle,
    [in, optional] PLARGE_INTEGER TmVirtualClock
);

void KeReleaseInterruptSpinLock(
    [in, out] PKINTERRUPT Interrupt,
    [in] KIRQL OldIrql
);

BOOLEAN ExAcquireRundownProtectionCacheAwareEx(
    [in, out] PEX_RUNDOWN_REF_CACHE_AWARE RunRefCacheAware,
    [in] ULONG Count
);

NTSTATUS IoWMISetSingleInstance(
    [in] PVOID DataBlockObject,
    [in] PUNICODE_STRING InstanceName,
    [in] ULONG Version,
    [in] ULONG ValueBufferSize,
    [in] PVOID ValueBuffer
);

void ExUnregisterCallback(
    [in, out] PVOID CallbackRegistration
);

NTSTATUS IoReserveKsrPersistentMemory(
    PDRIVER_OBJECT DriverObject,
    PDEVICE_OBJECT PhysicalDeviceObject,
    SIZE_T Size,
    ULONG Flags,
    PVOID *DataHandle
);

__kernel_entry NTSYSCALLAPI NTSTATUS NtCreateEnlistment(
    [out] PHANDLE EnlistmentHandle,
    [in] ACCESS_MASK DesiredAccess,
    [in] HANDLE ResourceManagerHandle,
    [in] HANDLE TransactionHandle,
    [in, optional] POBJECT_ATTRIBUTES ObjectAttributes,
    [in, optional] ULONG CreateOptions,
    [in] NOTIFICATION_MASK NotificationMask,
    [in, optional] PVOID EnlistmentKey
);

NTSYSCALLAPI NTSTATUS ZwQueryInformationResourceManager(
    [in] HANDLE ResourceManagerHandle,
    [in] RESOURCEMANAGER_INFORMATION_CLASS ResourceManagerInformationClass,
    [out] PVOID ResourceManagerInformation,
    [in] ULONG ResourceManagerInformationLength,
    [out, optional] PULONG ReturnLength
);

NTSYSAPI VOID RtlSetBit(
    [in] PRTL_BITMAP BitMapHeader,
    [in] ULONG BitNumber
);

BOOLEAN KeSetTimer(
    [in, out] PKTIMER Timer,
    [in] LARGE_INTEGER DueTime,
    [in, optional] PKDPC Dpc
);

void PoFxStartDevicePowerManagement(
    [in] POHANDLE Handle
);

void KeSetSystemGroupAffinityThread(
    [in] PGROUP_AFFINITY Affinity,
    [out, optional] PGROUP_AFFINITY PreviousAffinity
);

NTSTATUS IoCreateFile(
    [out] PHANDLE FileHandle,
    [in] ACCESS_MASK DesiredAccess,
    [in] POBJECT_ATTRIBUTES ObjectAttributes,
    [out] PIO_STATUS_BLOCK IoStatusBlock,
    [in, optional] PLARGE_INTEGER AllocationSize,
    [in] ULONG FileAttributes,
    [in] ULONG ShareAccess,
    [in] ULONG Disposition,
    [in] ULONG CreateOptions,
    [in, optional] PVOID EaBuffer,
    [in] ULONG EaLength,
    [in] CREATE_FILE_TYPE CreateFileType,
    [in, optional] PVOID InternalParameters,
    [in] ULONG Options
);

void ExInitializeWorkItem(
    [in] PWORK_QUEUE_ITEM Item,
    [in] PWORKER_THREAD_ROUTINE Routine,
    [in] PVOID Context
);

void PoSetSystemState(
    [in] EXECUTION_STATE Flags
);

void ExAcquirePushLockShared(
    Lock
);

BOOLEAN ExAcquireSharedStarveExclusive(
    [in, out] PERESOURCE Resource,
    [in] BOOLEAN Wait
);

SIZE_T ExSizeOfRundownProtectionCacheAware();

NTSTATUS ExInitializeLookasideListEx(
    [out] PLOOKASIDE_LIST_EX Lookaside,
    [in, optional] PALLOCATE_FUNCTION_EX Allocate,
    [in, optional] PFREE_FUNCTION_EX Free,
    [in] POOL_TYPE PoolType,
    [in] ULONG Flags,
    [in] SIZE_T Size,
    [in] ULONG Tag,
    [in] USHORT Depth
);

void MmGetMdlByteOffset(
    [in] Mdl
);

NTSYSAPI NTSTATUS RtlAppendUnicodeToString(
    [in, out] PUNICODE_STRING Destination,
    [in, optional] PCWSTR Source
);

NTSTATUS TmReadOnlyEnlistment(
    [in] PKENLISTMENT Enlistment,
    [in] PLARGE_INTEGER TmVirtualClock
);

NTHALAPI VOID READ_PORT_BUFFER_UCHAR(
    [in] PUCHAR Port,
    [out] PUCHAR Buffer,
    [in] ULONG Count
);

LONG KeReleaseMutex(
    [in, out] PRKMUTEX Mutex,
    [in] BOOLEAN Wait
);

UCHAR READ_REGISTER_UCHAR(
    [in] volatile UCHAR *Register
);

USHORT READ_REGISTER_USHORT(
    [in] volatile USHORT *Register
);

PLIST_ENTRY RemoveTailList(
    [in, out] PLIST_ENTRY ListHead
);

NTHALAPI VOID WRITE_PORT_BUFFER_UCHAR(
    [in] PUCHAR Port,
    [in] PUCHAR Buffer,
    [in] ULONG Count
);

NTSYSAPI NTSTATUS ZwDeleteValueKey(
    [in] HANDLE KeyHandle,
    [in] PUNICODE_STRING ValueName
);

CLFSUSER_API NTSTATUS ClfsCloseLogFileObject(
    [in] PLOG_FILE_OBJECT plfoLog
);

CLFSUSER_API NTSTATUS ClfsGetIoStatistics(
    [in] PLOG_FILE_OBJECT plfoLog,
    [in, out] PVOID pvStatsBuffer,
    [in] ULONG cbStatsBuffer,
    [in] CLFS_IOSTATS_CLASS eStatsClass,
    [out, optional] PULONG pcbStatsWritten
);

void KeFlushQueuedDpcs();

void KeInitializeSpinLock(
    [out] PKSPIN_LOCK SpinLock
);

NTHALAPI VOID KeStallExecutionProcessor(
    [in] ULONG MicroSeconds
);

PVOID MmMapLockedPagesSpecifyCache(
    [in] PMDL MemoryDescriptorList,
    [in] __drv_strictType(KPROCESSOR_MODE / enum _MODE,__drv_typeConst)KPROCESSOR_MODE AccessMode,
    [in] __drv_strictTypeMatch(__drv_typeCond)MEMORY_CACHING_TYPE CacheType,
    [in, optional] PVOID RequestedAddress,
    [in] ULONG BugCheckOnFailure,
    [in] ULONG Priority
);

void IoInitializeDpcRequest(
    [in] PDEVICE_OBJECT DeviceObject,
    [in] PIO_DPC_ROUTINE DpcRoutine
);

void KeFlushIoBuffers(
    [in] PMDL Mdl,
    [in] BOOLEAN ReadOperation,
    [in] BOOLEAN DmaOperation
);

__kernel_entry NTSYSCALLAPI NTSTATUS NtRollforwardTransactionManager(
    [in] HANDLE TransactionManagerHandle,
    [in, optional] PLARGE_INTEGER TmVirtualClock
);

PVOID InterlockedExchangePointer(
    [in, out] PVOID volatile *Target,
    [in, optional] PVOID Value
);

void BarrierAfterRead();

KPRIORITY KeSetPriorityThread(
    [in, out] PKTHREAD Thread,
    [in] KPRIORITY Priority
);

void MmProbeAndLockPages(
    [in, out] PMDL MemoryDescriptorList,
    [in] KPROCESSOR_MODE AccessMode,
    [in] LOCK_OPERATION Operation
);

__kernel_entry NTSYSCALLAPI NTSTATUS NtQueryInformationResourceManager(
    [in] HANDLE ResourceManagerHandle,
    [in] RESOURCEMANAGER_INFORMATION_CLASS ResourceManagerInformationClass,
    [out] PVOID ResourceManagerInformation,
    [in] ULONG ResourceManagerInformationLength,
    [out, optional] PULONG ReturnLength
);

NTSTATUS ObReferenceObjectByPointer(
    [in] PVOID Object,
    [in] ACCESS_MASK DesiredAccess,
    [in, optional] POBJECT_TYPE ObjectType,
    [in] KPROCESSOR_MODE AccessMode
);

CLFSUSER_API BOOLEAN ClfsLsnNull(
    [in] const CLFS_LSN *plsn
);

NTSYSAPI NTSTATUS RtlUTF8ToUnicodeN(
    [out, optional] PWSTR UnicodeStringDestination,
    [in] ULONG UnicodeStringMaxByteCount,
    [out] PULONG UnicodeStringActualByteCount,
    [in] PCCH UTF8StringSource,
    [in] ULONG UTF8StringByteCount
);

NTSYSAPI NTSTATUS ZwSetInformationFile(
    [in] HANDLE FileHandle,
    [out] PIO_STATUS_BLOCK IoStatusBlock,
    [in] PVOID FileInformation,
    [in] ULONG Length,
    [in] FILE_INFORMATION_CLASS FileInformationClass
);

NTSYSCALLAPI NTSTATUS ZwSetInformationResourceManager(
    HANDLE ResourceManagerHandle,
    RESOURCEMANAGER_INFORMATION_CLASS ResourceManagerInformationClass,
    PVOID ResourceManagerInformation,
    ULONG ResourceManagerInformationLength
);

ULONG KeQueryMaximumProcessorCount();

NTSTATUS PoDeletePowerLimitRequest(
    PVOID PowerLimitRequest
);

__kernel_entry NTSYSCALLAPI NTSTATUS NtGetNotificationResourceManager(
    [in] HANDLE ResourceManagerHandle,
    [out] PTRANSACTION_NOTIFICATION TransactionNotification,
    [in] ULONG NotificationLength,
    [in] PLARGE_INTEGER Timeout,
    [out, optional] PULONG ReturnLength,
    [in] ULONG Asynchronous,
    [in, optional] ULONG_PTR AsynchronousContext
);

void ObUnRegisterCallbacks(
    [in] PVOID RegistrationHandle
);

NTSYSAPI NTSTATUS ZwEnumerateKey(
    [in] HANDLE KeyHandle,
    [in] ULONG Index,
    [in] KEY_INFORMATION_CLASS KeyInformationClass,
    [out, optional] PVOID KeyInformation,
    [in] ULONG Length,
    [out] PULONG ResultLength
);

NTSYSCALLAPI NTSTATUS ZwQueryInformationEnlistment(
    [in] HANDLE EnlistmentHandle,
    [in] ENLISTMENT_INFORMATION_CLASS EnlistmentInformationClass,
    [out] PVOID EnlistmentInformation,
    [in] ULONG EnlistmentInformationLength,
    [out, optional] PULONG ReturnLength
);

NTSYSAPI NTSTATUS RtlInitStringEx(
    [out] PSTRING DestinationString,
    [in, optional] __drv_aliasesMem PCSZ SourceString
);

NTHALAPI VOID WRITE_PORT_USHORT(
    [in] PUSHORT Port,
    [in] USHORT Value
);

BOOLEAN ObReferenceObjectSafe(
    PVOID Object
);

void ExNotifyCallback(
    [in] PVOID CallbackObject,
    [in, optional] PVOID Argument1,
    [in, optional] PVOID Argument2
);

volatile void * RtlCopyVolatileMemory(
    [out] volatile void *Destination,
    [in] volatile const void *Source,
    [in] size_t Length
);

unsigned char _BitTestAndSet64(
    __int64 *Base,
    __int64 Index
);

void IoSetStartIoAttributes(
    [in] PDEVICE_OBJECT DeviceObject,
    [in] BOOLEAN DeferredStartIo,
    [in] BOOLEAN NonCancelable
);

BOOLEAN PoGetSystemWake(
    [in] PIRP Irp
);

void IoDetachDevice(
    [in, out] PDEVICE_OBJECT TargetDevice
);

void IoDisconnectInterrupt(
    [in] PKINTERRUPT InterruptObject
);

NTSYSAPI NTSTATUS ZwCreateKey(
    [out] PHANDLE KeyHandle,
    [in] ACCESS_MASK DesiredAccess,
    [in] POBJECT_ATTRIBUTES ObjectAttributes,
    ULONG TitleIndex,
    [in, optional] PUNICODE_STRING Class,
    [in] ULONG CreateOptions,
    [out, optional] PULONG Disposition
);

NTSYSAPI NTSTATUS ZwOpenFile(
    [out] PHANDLE FileHandle,
    [in] ACCESS_MASK DesiredAccess,
    [in] POBJECT_ATTRIBUTES ObjectAttributes,
    [out] PIO_STATUS_BLOCK IoStatusBlock,
    [in] ULONG ShareAccess,
    [in] ULONG OpenOptions
);

PVOID ExAllocatePoolPriorityZero(
    __drv_strictTypeMatch(__drv_typeExpr)POOL_TYPE PoolType,
    SIZE_T NumberOfBytes,
    ULONG Tag,
    EX_POOL_PRIORITY Priority
);

NTSTATUS ObGetObjectSecurity(
    [in] PVOID Object,
    [out] PSECURITY_DESCRIPTOR *SecurityDescriptor,
    [out] PBOOLEAN MemoryAllocated
);

void ExAcquireSpinLockSharedAtDpcLevel(
    PEX_SPIN_LOCK SpinLock
);

NTSYSAPI NTSTATUS RtlUnicodeToUTF8N(
    [out] PCHAR UTF8StringDestination,
    [in] ULONG UTF8StringMaxByteCount,
    [out] PULONG UTF8StringActualByteCount,
    [in] PCWCH UnicodeStringSource,
    [in] ULONG UnicodeStringByteCount
);

BOOLEAN ExTryAcquirePushLockExclusiveEx(
    PEX_PUSH_LOCK PushLock,
    ULONG Flags
);

BOOLEAN ExTryAcquirePushLockSharedEx(
    PEX_PUSH_LOCK PushLock,
    ULONG Flags
);

PVOID MmMapLockedPages(
    [in] PMDL MemoryDescriptorList,
    [in] __drv_strictType(KPROCESSOR_MODE / enum _MODE,__drv_typeConst)KPROCESSOR_MODE AccessMode
);

BOOLEAN TmIsTransactionActive(
    [in] PKTRANSACTION Transaction
);

void WRITE_REGISTER_USHORT(
    [in] volatile USHORT *Register,
    [in] USHORT Value
);

NTSYSCALLAPI NTSTATUS ZwSinglePhaseReject(
    [in] HANDLE EnlistmentHandle,
    [in, optional] PLARGE_INTEGER TmVirtualClock
);

unsigned char _BitTestAndReset64(
    __int64 *Base,
    __int64 Index
);

NTSTATUS ObCloseHandle(
    [in] HANDLE Handle,
    [in] KPROCESSOR_MODE PreviousMode
);

NTSYSAPI NTSTATUS RtlInt64ToUnicodeString(
    [in] ULONGLONG Value,
    [in, optional] ULONG Base,
    [in, out] PUNICODE_STRING String
);

DECLSPEC_RESTRICT PVOID ExAllocatePool3(
    POOL_FLAGS Flags,
    SIZE_T NumberOfBytes,
    ULONG Tag,
    PCPOOL_EXTENDED_PARAMETER ExtendedParameters,
    ULONG ExtendedParametersCount
);

PVOID IoAllocateErrorLogEntry(
    [in] PVOID IoObject,
    [in] UCHAR EntrySize
);

NTSYSAPI NTSTATUS ZwMakeTemporaryObject(
    [in] HANDLE Handle
);

void KeAcquireInStackQueuedSpinLockForDpc(
    PKSPIN_LOCK SpinLock,
    PKLOCK_QUEUE_HANDLE LockHandle
);

void WriteInt32Release(
    INT32 volatile *Destination,
    INT32 Value
);

NTSYSAPI LONG RtlCompareUnicodeString(
    [in] PCUNICODE_STRING String1,
    [in] PCUNICODE_STRING String2,
    [in] BOOLEAN CaseInSensitive
);

void ADDRESS_AND_SIZE_TO_SPAN_PAGES(
    [in] Va,
    [in] Size
);

void KeMemoryBarrier();

PVOID ExAllocatePoolUninitialized(
    __drv_strictTypeMatch(__drv_typeExpr)POOL_TYPE PoolType,
    SIZE_T NumberOfBytes,
    ULONG Tag
);

CLFSUSER_API NTSTATUS ClfsMgmtTailAdvanceFailure(
    [in] CLFS_MGMT_CLIENT Client,
    [in] NTSTATUS Reason
);

BOOLEAN ExTryAcquirePushLockShared(
    Lock
);

void KeReleaseGuardedMutexUnsafe(
    [in, out] PKGUARDED_MUTEX FastMutex
);

NTSTATUS PoRequestPowerIrp(
    [in] PDEVICE_OBJECT DeviceObject,
    [in] UCHAR MinorFunction,
    [in] POWER_STATE PowerState,
    [in, optional] PREQUEST_POWER_COMPLETE CompletionFunction,
    [in, optional] __drv_aliasesMem PVOID Context,
    [out] PIRP *Irp
);

NTSTATUS KeSaveFloatingPointState(
    [out] PKFLOATING_SAVE FloatSave
);

NTSYSAPI ULONG RtlNumberOfSetBitsUlongPtr(
    [in] ULONG_PTR Target
);

void MmUnlockPagableImageSection(
    [in] PVOID ImageSectionHandle
);

NTSTATUS KeAddTriageDumpDataBlock(
    [_Inout_] PKTRIAGE_DUMP_DATA_ARRAY KtriageDumpDataArray,
    PVOID Address,
    [_In_] SIZE_T Size
);

void PoSetSystemWake(
    [in, out] PIRP Irp
);

NTSTATUS IoWMIQuerySingleInstanceMultiple(
    [in] PVOID *DataBlockObjectList,
    [in] PUNICODE_STRING InstanceNames,
    [in] ULONG ObjectCount,
    [in, out] PULONG InOutBufferSize,
    [out, optional] PVOID OutBuffer
);

CLFSUSER_API NTSTATUS ClfsCreateMarshallingArea(
    [in] PLOG_FILE_OBJECT plfoLog,
    [in] POOL_TYPE ePoolType,
    [in, optional] PALLOCATE_FUNCTION pfnAllocBuffer,
    [in, optional] PFREE_FUNCTION pfnFreeBuffer,
    [in] ULONG cbMarshallingBuffer,
    [in] ULONG cMaxWriteBuffers,
    [in] ULONG cMaxReadBuffers,
    [out] PVOID *ppvMarshalContext
);

void IoUnregisterShutdownNotification(
    [in] PDEVICE_OBJECT DeviceObject
);

ULONG IoSizeofWorkItem();

__kernel_entry NTSYSCALLAPI NTSTATUS NtCreateResourceManager(
    [out] PHANDLE ResourceManagerHandle,
    [in] ACCESS_MASK DesiredAccess,
    [in] HANDLE TmHandle,
    [in] LPGUID RmGuid,
    [in, optional] POBJECT_ATTRIBUTES ObjectAttributes,
    [in, optional] ULONG CreateOptions,
    [in, optional] PUNICODE_STRING Description
);

__kernel_entry NTSYSCALLAPI NTSTATUS NtPrepareEnlistment(
    [in] HANDLE EnlistmentHandle,
    [in, optional] PLARGE_INTEGER TmVirtualClock
);

NTSTATUS PoFxPowerControl(
    [in] POHANDLE Handle,
    [in] LPCGUID PowerControlCode,
    [in, optional] PVOID InBuffer,
    [in] SIZE_T InBufferSize,
    [out, optional] PVOID OutBuffer,
    [in] SIZE_T OutBufferSize,
    [out, optional] PSIZE_T BytesReturned
);

NTSYSAPI NTSTATUS RtlIntegerToUnicodeString(
    [in] ULONG Value,
    [in, optional] ULONG Base,
    [in, out] PUNICODE_STRING String
);

BOOLEAN ExAcquireResourceSharedLite(
    [in, out] PERESOURCE Resource,
    [in] BOOLEAN Wait
);

void SeReleaseSubjectContext(
    [in, out] PSECURITY_SUBJECT_CONTEXT SubjectContext
);

void CmCallbackReleaseKeyObjectIDEx(
    PCUNICODE_STRING ObjectName
);

void KeQuerySystemTimePrecise(
    [out] PLARGE_INTEGER CurrentTime
);

volatile void * RtlSecureZeroMemory2(
    [out] volatile void *Destination,
    [in] size_t Length
);

PMDL MmAllocateNodePagesForMdlEx(
    [in] PHYSICAL_ADDRESS LowAddress,
    [in] PHYSICAL_ADDRESS HighAddress,
    [in] PHYSICAL_ADDRESS SkipBytes,
    [in] SIZE_T TotalBytes,
    [in] MEMORY_CACHING_TYPE CacheType,
    [in] ULONG IdealNode,
    [in] ULONG Flags
);

__kernel_entry NTSYSCALLAPI NTSTATUS NtRenameTransactionManager(
    [in] PUNICODE_STRING LogFileName,
    [in] LPGUID ExistingTransactionManagerGuid
);

void RtlIsZeroLuid(
    [in] L1
);

NTSYSAPI NTSTATUS RtlUTF8StringToUnicodeString(
    PUNICODE_STRING DestinationString,
    PUTF8_STRING SourceString,
    BOOLEAN AllocateDestinationString
);

__drv_aliasesMem PIO_STACK_LOCATION IoGetNextIrpStackLocation(
    [in] PIRP Irp
);

void IoInvalidateDeviceRelations(
    [in] PDEVICE_OBJECT DeviceObject,
    [in] DEVICE_RELATION_TYPE Type
);

NTSYSAPI NTSTATUS ZwOpenKeyEx(
    [out] PHANDLE KeyHandle,
    [in] ACCESS_MASK DesiredAccess,
    [in] POBJECT_ATTRIBUTES ObjectAttributes,
    [in] ULONG OpenOptions
);

CLFSUSER_API NTSTATUS ClfsQueryLogFileInformation(
    [in] PLOG_FILE_OBJECT plfoLog,
    [in] CLFS_LOG_INFORMATION_CLASS eInformationClass,
    PVOID pinfoInputBuffer,
    ULONG cbinfoInputBuffer,
    [out] PVOID pinfoBuffer,
    PULONG pcbInfoBuffer
);

void ExInterlockedAddLargeStatistic(
    [in] Addend,
    [in] Increment
);

void InitializeListHead(
    [out] PLIST_ENTRY ListHead
);

NTSYSAPI NTSTATUS RtlUnicodeStringToAnsiString(
    [in, out] PANSI_STRING DestinationString,
    [in] PCUNICODE_STRING SourceString,
    [in] BOOLEAN AllocateDestinationString
);

NTSTATUS CmCallbackGetKeyObjectID(
    [in] PLARGE_INTEGER Cookie,
    [in] PVOID Object,
    [out, optional] PULONG_PTR ObjectID,
    [out, optional] PCUNICODE_STRING *ObjectName
);

KIRQL KfAcquireSpinLock(
    PKSPIN_LOCK SpinLock
);

CLFSUSER_API NTSTATUS ClfsCreateLogFile(
    [out] PPLOG_FILE_OBJECT pplfoLog,
    [in] PUNICODE_STRING puszLogFileName,
    [in] ACCESS_MASK fDesiredAccess,
    [in] ULONG dwShareMode,
    [in, optional] PSECURITY_DESCRIPTOR psdLogFile,
    [in] ULONG fCreateDisposition,
    [in] ULONG fCreateOptions,
    [in] ULONG fFlagsAndAttributes,
    [in] ULONG fLogOptionFlag,
    [in, optional] PVOID pvContext,
    [in] ULONG cbContext
);

void ObDereferenceObjectWithTag(
    [in] a,
    [in] t
);

NTSYSAPI NTSTATUS RtlIoEncodeMemIoResource(
    [in] PIO_RESOURCE_DESCRIPTOR Descriptor,
    [in] UCHAR Type,
    [in] ULONGLONG Length,
    [in] ULONGLONG Alignment,
    [in] ULONGLONG MinimumAddress,
    [in] ULONGLONG MaximumAddress
);

void IoUninitializeWorkItem(
    [in] PIO_WORKITEM IoWorkItem
);

void ExFreeToPagedLookasideList(
    [in, out] PPAGED_LOOKASIDE_LIST Lookaside,
    [in] PVOID Entry
);

void ARM64_SYSREG_CRM(
    _Reg_
);

void READ_REGISTER_BUFFER_ULONG64(
    [in] volatile ULONG64 *Register,
    [out] PULONG64 Buffer,
    [in] ULONG Count
);

void ExRaiseStatus(
    [in] NTSTATUS Status
);

NTSYSCALLAPI NTSTATUS ZwPrePrepareComplete(
    [in] HANDLE EnlistmentHandle,
    [in, optional] PLARGE_INTEGER TmVirtualClock
);

NTSTATUS CmRegisterCallbackEx(
    [in] PEX_CALLBACK_FUNCTION Function,
    [in] PCUNICODE_STRING Altitude,
    [in] PVOID Driver,
    [in, optional] PVOID Context,
    [out] PLARGE_INTEGER Cookie,
    PVOID Reserved
);

ULONG KeGetCurrentProcessorIndex();

void ExInitializeRundownProtectionCacheAware(
    [out] PEX_RUNDOWN_REF_CACHE_AWARE RunRefCacheAware,
    [in] SIZE_T RunRefSize
);

void KeInitializeEvent(
    [out] PRKEVENT Event,
    [in] EVENT_TYPE Type,
    [in] BOOLEAN State
);

LONG InterlockedXor(
    [in, out] LONG volatile *Destination,
    [in] LONG Value
);

ULONG MmGetMdlByteCount(
    [in] PMDL Mdl
);

NTSYSAPI VOID RtlSetAllBits(
    [in] PRTL_BITMAP BitMapHeader
);

PVOID ExAllocatePool(
    [in] __drv_strictTypeMatch(__drv_typeExpr)POOL_TYPE PoolType,
    [in] SIZE_T NumberOfBytes
);

NTSTATUS IoGetIommuInterface(
    ULONG Version,
    PDMA_IOMMU_INTERFACE InterfaceOut
);

NTSTATUS PoSetPowerLimitValue(
    PVOID PowerLimitRequest,
    PCOUNTED_REASON_CONTEXT Reason,
    ULONG ValueCount,
    PPOWER_LIMIT_VALUE Values
);

KIRQL KeAcquireSpinLockForDpc(
    PKSPIN_LOCK SpinLock
);

void KeInitializeTimer(
    [out] PKTIMER Timer
);

NTSYSCALLAPI NTSTATUS ZwOpenResourceManager(
    [out] PHANDLE ResourceManagerHandle,
    [in] ACCESS_MASK DesiredAccess,
    [in] HANDLE TmHandle,
    [in] LPGUID ResourceManagerGuid,
    [in, optional] POBJECT_ATTRIBUTES ObjectAttributes
);

CLFSUSER_API NTSTATUS ClfsWriteRestartArea(
    [in, out] PVOID pvMarshalContext,
    [in] PVOID pvRestartBuffer,
    [in] ULONG cbRestartBuffer,
    [in, optional] PCLFS_LSN plsnBase,
    [in] ULONG fFlags,
    [out, optional] PULONG pcbWritten,
    [out, optional] PCLFS_LSN plsnNext
);

NTSTATUS IoWMIAllocateInstanceIds(
    [in] LPCGUID Guid,
    [in] ULONG InstanceCount,
    [out] ULONG *FirstInstanceId
);

void PushEntryList(
    [in, out] PSINGLE_LIST_ENTRY ListHead,
    [in, out] __drv_aliasesMem PSINGLE_LIST_ENTRY Entry
);

NTSYSAPI ULONG RtlNumberOfClearBits(
    [in] PRTL_BITMAP BitMapHeader
);

NTSTATUS PsTerminateSystemThread(
    [in] NTSTATUS ExitStatus
);

BOOLEAN PoQueryWatchdogTime(
    [in] PDEVICE_OBJECT Pdo,
    [out] PULONG SecondsRemaining
);

__kernel_entry NTSYSCALLAPI NTSTATUS NtPrePrepareComplete(
    [in] HANDLE EnlistmentHandle,
    [in, optional] PLARGE_INTEGER TmVirtualClock
);

NTSYSAPI NTSTATUS ZwQueryInformationByName(
    [in] POBJECT_ATTRIBUTES ObjectAttributes,
    [out] PIO_STATUS_BLOCK IoStatusBlock,
    [out] PVOID FileInformation,
    [in] ULONG Length,
    [in] FILE_INFORMATION_CLASS FileInformationClass
);

void KefReleaseSpinLockFromDpcLevel(
    [in, out] PKSPIN_LOCK SpinLock
);

DECLSPEC_RESTRICT PVOID ExAllocatePool2(
    POOL_FLAGS Flags,
    SIZE_T NumberOfBytes,
    ULONG Tag
);

void PoFxActivateComponent(
    [in] POHANDLE Handle,
    [in] ULONG Component,
    [in] ULONG Flags
);

void ObDereferenceObjectDeferDelete(
    [in] PVOID Object
);

PVOID ExAllocatePoolWithQuotaTag(
    [in] __drv_strictTypeMatch(__drv_typeExpr)POOL_TYPE PoolType,
    [in] SIZE_T NumberOfBytes,
    [in] ULONG Tag
);

CLFSUSER_API NTSTATUS ClfsAddLogContainer(
    [in] PLOG_FILE_OBJECT plfoLog,
    [in] PULONGLONG pcbContainer,
    [in] PUNICODE_STRING puszContainerPath
);

NTSTATUS
    IoAcquireRemoveLock (
    _Inout_ PIO_REMOVE_LOCK RemoveLock,
    _In_opt_ PVOID Tag
);

NTSTATUS PoCreatePowerLimitRequest(
    PVOID *PowerLimitRequest,
    PDEVICE_OBJECT TargetDeviceObject,
    PDEVICE_OBJECT PolicyDeviceObject,
    PCOUNTED_REASON_CONTEXT Context
);

void KfReleaseSpinLock(
    PKSPIN_LOCK SpinLock,
    KIRQL NewIrql
);

void ExSystemTimeToLocalTime(
    [in] PLARGE_INTEGER SystemTime,
    [out] PLARGE_INTEGER LocalTime
);

__drv_aliasesMem PIO_STACK_LOCATION IoGetCurrentIrpStackLocation(
    [in] PIRP Irp
);

BOOLEAN IoIsWdmVersionAvailable(
    [in] UCHAR MajorVersion,
    [in] UCHAR MinorVersion
);

NTSTATUS KeInitializeCrashDumpHeader(
    [in] ULONG DumpType,
    [in] ULONG Flags,
    [out] PVOID Buffer,
    [in] ULONG BufferSize,
    [out, optional] PULONG BufferNeeded
);

CLFSUSER_API NTSTATUS ClfsAlignReservedLog(
    [in] PVOID pvMarshalContext,
    [in] ULONG cRecords,
    [in] LONGLONG [] rgcbReservation,
    [out] PLONGLONG pcbAlignReservation
);

NTSYSAPI ULONG RtlFindSetBitsAndClear(
    [in] PRTL_BITMAP BitMapHeader,
    [in] ULONG NumberToFind,
    [in] ULONG HintIndex
);

BOOLEAN ExIsSoftBoot();

void IoInitializeIrp(
    [in, out] PIRP Irp,
    [in] USHORT PacketSize,
    [in] CCHAR StackSize
);

PSINGLE_LIST_ENTRY ExInterlockedPopEntryList(
    [in, out] PSINGLE_LIST_ENTRY ListHead,
    [in, out] PKSPIN_LOCK Lock
);

NTSTATUS VslCreateSecureSection(
    PHANDLE Handle,
    PEPROCESS TargetProcess,
    PMDL Mdl,
    ULONG DevicePageProtection,
    ULONG Attributes
);

MM_SYSTEMSIZE MmQuerySystemSize();

NTSTATUS IoCheckShareAccessEx(
    [in] ACCESS_MASK DesiredAccess,
    [in] ULONG DesiredShareAccess,
    [in, out] PFILE_OBJECT FileObject,
    [in, out] PSHARE_ACCESS ShareAccess,
    [in] BOOLEAN Update,
    [in] PBOOLEAN WritePermission
);

NTSYSAPI VOID RtlInitUnicodeString(
    [out] PUNICODE_STRING DestinationString,
    [in, optional] __drv_aliasesMem PCWSTR SourceString
);

ULONG ExGetExclusiveWaiterCount(
    [in] PERESOURCE Resource
);

void IoQueueWorkItemEx(
    [in] __drv_aliasesMem PIO_WORKITEM IoWorkItem,
    [in] PIO_WORKITEM_ROUTINE_EX WorkerRoutine,
    [in] WORK_QUEUE_TYPE QueueType,
    [in, optional] __drv_aliasesMem PVOID Context
);

NTSTATUS ObReferenceObjectByHandle(
    [in] HANDLE Handle,
    [in] ACCESS_MASK DesiredAccess,
    [in, optional] POBJECT_TYPE ObjectType,
    [in] KPROCESSOR_MODE AccessMode,
    [out] PVOID *Object,
    [out, optional] POBJECT_HANDLE_INFORMATION HandleInformation
);

void RtlIntPtrToUnicodeString(
    [in] Value,
    [in, optional] Base,
    [in, out] String
);

__kernel_entry NTSYSCALLAPI NTSTATUS NtRecoverTransactionManager(
    [in] HANDLE TransactionManagerHandle
);

PKEVENT IoCreateSynchronizationEvent(
    [in] PUNICODE_STRING EventName,
    [out] PHANDLE EventHandle
);

CLFSUSER_API NTSTATUS ClfsMgmtHandleLogFileFull(
    [in] CLFS_MGMT_CLIENT Client
);

CLFSUSER_API CLFS_CONTAINER_ID ClfsLsnContainer(
    [in] const CLFS_LSN *plsn
);

NTSYSCALLAPI NTSTATUS ZwCommitTransaction(
    [in] HANDLE TransactionHandle,
    [in] BOOLEAN Wait
);

KPROCESSOR_MODE ExGetPreviousMode();

KIRQL KeAcquireInterruptSpinLock(
    PKINTERRUPT Interrupt
);

NTSYSAPI ULONG RtlFindClearBits(
    [in] PRTL_BITMAP BitMapHeader,
    [in] ULONG NumberToFind,
    [in] ULONG HintIndex
);

NTSYSAPI NTSTATUS ZwOpenKeyTransacted(
    [out] PHANDLE KeyHandle,
    [in] ACCESS_MASK DesiredAccess,
    [in] POBJECT_ATTRIBUTES ObjectAttributes,
    [in] HANDLE TransactionHandle
);

void RtlRetrieveUshort(
    [out] DEST_ADDRESS,
    [in] SRC_ADDRESS
);

void ExSetResourceOwnerPointerEx(
    [in, out] PERESOURCE Resource,
    [in] PVOID OwnerPointer,
    [in] ULONG Flags
);

void ExReleaseResourceAndLeaveCriticalRegion(
    PERESOURCE Resource
);

void KeEnterGuardedRegion();

NTSYSAPI VOID RtlInitUTF8String(
    PUTF8_STRING DestinationString,
    __drv_aliasesMem PCSZ SourceString
);

NTSYSCALLAPI NTSTATUS ZwSetInformationEnlistment(
    [in] HANDLE EnlistmentHandle,
    [in] ENLISTMENT_INFORMATION_CLASS EnlistmentInformationClass,
    [in] PVOID EnlistmentInformation,
    [in] ULONG EnlistmentInformationLength
);

NTSTATUS TmRenameTransactionManager(
    [in] PUNICODE_STRING LogFileName,
    [in] LPGUID ExistingTransactionManagerGuid
);

NTSTATUS IoGetDeviceNumaNode(
    [in] PDEVICE_OBJECT Pdo,
    [out] PUSHORT NodeNumber
);

void PoSetDeviceBusyEx(
    [in, out] PULONG IdlePointer
);

NTSYSAPI ULONGLONG RtlUlonglongByteSwap(
    ULONGLONG Source
);

__kernel_entry NTSYSCALLAPI NTSTATUS NtQueryInformationTransaction(
    [in] HANDLE TransactionHandle,
    [in] TRANSACTION_INFORMATION_CLASS TransactionInformationClass,
    [out] PVOID TransactionInformation,
    [in] ULONG TransactionInformationLength,
    [out, optional] PULONG ReturnLength
);

void IoCsqInsertIrp(
    [in, out] PIO_CSQ Csq,
    [in, out] PIRP Irp,
    [out, optional] PIO_CSQ_IRP_CONTEXT Context
);

void KeReleaseSpinLock(
    PKSPIN_LOCK SpinLock,
    KIRQL NewIrql
);

NTSYSCALLAPI NTSTATUS ZwOpenEvent(
    [out] PHANDLE EventHandle,
    [in] ACCESS_MASK DesiredAccess,
    [in] POBJECT_ATTRIBUTES ObjectAttributes
);

NTSYSAPI BOOLEAN RtlAreBitsClear(
    [in] PRTL_BITMAP BitMapHeader,
    [in] ULONG StartingIndex,
    [in] ULONG Length
);

BOOLEAN KeDeregisterBugCheckReasonCallback(
    [in, out] PKBUGCHECK_REASON_CALLBACK_RECORD CallbackRecord
);

void ExReInitializeRundownProtectionCacheAware(
    [in, out] PEX_RUNDOWN_REF_CACHE_AWARE RunRefCacheAware
);

void ExDeleteLookasideListEx(
    [in, out] PLOOKASIDE_LIST_EX Lookaside
);

NTSYSAPI ULONGLONG RtlIoDecodeMemIoResource(
    [in] PIO_RESOURCE_DESCRIPTOR Descriptor,
    [out, optional] PULONGLONG Alignment,
    [out, optional] PULONGLONG MinimumAddress,
    [out, optional] PULONGLONG MaximumAddress
);

NTSTATUS EtwUnregister(
    [in] REGHANDLE RegHandle
);

PMDL MmAllocatePagesForMdl(
    [in] PHYSICAL_ADDRESS LowAddress,
    [in] PHYSICAL_ADDRESS HighAddress,
    [in] PHYSICAL_ADDRESS SkipBytes,
    [in] SIZE_T TotalBytes
);

NTSTATUS IoGetDeviceInterfaceAlias(
    [in] PUNICODE_STRING SymbolicLinkName,
    [in] const GUID *AliasInterfaceClassGuid,
    [out] PUNICODE_STRING AliasSymbolicLinkName
);

PVOID MmMapIoSpaceEx(
    [in] PHYSICAL_ADDRESS PhysicalAddress,
    [in] SIZE_T NumberOfBytes,
    [in] ULONG Protect
);

void ExInitializeDeleteTimerParameters(
    PEXT_DELETE_PARAMETERS Parameters
);

CLFSUSER_API CLFS_LSN ClfsLsnCreate(
    [in] CLFS_CONTAINER_ID cidContainer,
    [in] ULONG offBlock,
    [in] ULONG cRecord
);

void WRITE_REGISTER_UCHAR(
    [in] volatile UCHAR *Register,
    [in] UCHAR Value
);

void ARM64_SYSREG_OP1(
    _Reg_
);

NTSTATUS IoGetAffinityInterrupt(
    [in] PKINTERRUPT InterruptObject,
    [out] PGROUP_AFFINITY GroupAffinity
);

NTSYSAPI NTSTATUS ZwClose(
    [in] HANDLE Handle
);

NTSTATUS IoReportTargetDeviceChange(
    [in] PDEVICE_OBJECT PhysicalDeviceObject,
    [in] PVOID NotificationStructure
);

NTSYSCALLAPI NTSTATUS ZwCommitEnlistment(
    [in] HANDLE EnlistmentHandle,
    [in, optional] PLARGE_INTEGER TmVirtualClock
);

PVOID IoGetInitialStack();

NTSTATUS IoQueryKsrPersistentMemorySize(
    PDRIVER_OBJECT DriverObject,
    PDEVICE_OBJECT PhysicalDeviceObject,
    PSIZE_T BufferSize
);

void _ReadWriteBarrier();

NTSTATUS PcwCreateInstance(
    [out] PPCW_INSTANCE *Instance,
    [in] PPCW_REGISTRATION Registration,
    [in] PCUNICODE_STRING Name,
    [in] ULONG Count,
    [in] PPCW_DATA Data
);

NTSTATUS
    IoRegisterContainerNotification(
    _In_ IO_CONTAINER_NOTIFICATION_CLASS NotificationClass,
    _In_ PIO_CONTAINER_NOTIFICATION_FUNCTION CallbackFunction,
    _In_reads_bytes_opt_(NotificationInformationLength) PVOID NotificationInformation,
    _In_ ULONG NotificationInformationLength,
    _Out_ PVOID * CallbackRegistration
);

__kernel_entry NTSYSCALLAPI NTSTATUS NtOpenEnlistment(
    [out] PHANDLE EnlistmentHandle,
    [in] ACCESS_MASK DesiredAccess,
    [in] HANDLE ResourceManagerHandle,
    [in] LPGUID EnlistmentGuid,
    [in, optional] POBJECT_ATTRIBUTES ObjectAttributes
);

void KeAcquireInStackQueuedSpinLockAtDpcLevel(
    PKSPIN_LOCK SpinLock,
    PKLOCK_QUEUE_HANDLE LockHandle
);

UCHAR ReadBooleanRaw(
    BOOLEAN const volatile *Source
);

void KdPrintEx(
    _x_
);

NTSYSCALLAPI NTSTATUS ZwRollbackComplete(
    [in] HANDLE EnlistmentHandle,
    [in, optional] PLARGE_INTEGER TmVirtualClock
);

void IoGetStackLimits(
    [out] PULONG_PTR LowLimit,
    [out] PULONG_PTR HighLimit
);

void IoRemoveLinkShareAccessEx(
    [in] PFILE_OBJECT FileObject,
    [in, out] PSHARE_ACCESS ShareAccess,
    [in, out, optional] PLINK_SHARE_ACCESS LinkShareAccess,
    ULONG IoShareAccessFlags
);

NTSYSAPI NTSTATUS RtlSetDaclSecurityDescriptor(
    [in, out] PSECURITY_DESCRIPTOR SecurityDescriptor,
    [in] BOOLEAN DaclPresent,
    [in, optional] PACL Dacl,
    [in, optional] BOOLEAN DaclDefaulted
);

__kernel_entry NTSYSCALLAPI NTSTATUS NtSetInformationEnlistment(
    [in] HANDLE EnlistmentHandle,
    [in] ENLISTMENT_INFORMATION_CLASS EnlistmentInformationClass,
    [in] PVOID EnlistmentInformation,
    [in] ULONG EnlistmentInformationLength
);

NTSTATUS IoConnectInterrupt(
    [out] PKINTERRUPT *InterruptObject,
    [in] PKSERVICE_ROUTINE ServiceRoutine,
    [in, optional] PVOID ServiceContext,
    [in, optional] PKSPIN_LOCK SpinLock,
    [in] ULONG Vector,
    [in] KIRQL Irql,
    [in] KIRQL SynchronizeIrql,
    [in] KINTERRUPT_MODE InterruptMode,
    [in] BOOLEAN ShareVector,
    [in] KAFFINITY ProcessorEnableMask,
    [in] BOOLEAN FloatingSave
);

BOOLEAN RtlIsNtDdiVersionAvailable(
    [in] ULONG Version
);

volatile void * RtlZeroVolatileMemory(
    [out] volatile void *Destination,
    [in] size_t Length
);

void KeReleaseInStackQueuedSpinLockForDpc(
    [in] PKLOCK_QUEUE_HANDLE LockHandle
);

LONG KeReadStateSemaphore(
    [in] PRKSEMAPHORE Semaphore
);

BOOLEAN KeReadStateTimer(
    [in] PKTIMER Timer
);

void KeInitializeCallbackRecord(
    [in] CallbackRecord
);

__kernel_entry NTSYSCALLAPI NTSTATUS NtCommitComplete(
    [in] HANDLE EnlistmentHandle,
    [in, optional] PLARGE_INTEGER TmVirtualClock
);

void KeEnterCriticalRegion();

NTSYSAPI NTSTATUS ZwOpenSection(
    [out] PHANDLE SectionHandle,
    [in] ACCESS_MASK DesiredAccess,
    [in] POBJECT_ATTRIBUTES ObjectAttributes
);

NTSTATUS TmCreateEnlistment(
    [out] PHANDLE EnlistmentHandle,
    [in] KPROCESSOR_MODE PreviousMode,
    [in] ACCESS_MASK DesiredAccess,
    [in] POBJECT_ATTRIBUTES ObjectAttributes,
    [in] PRKRESOURCEMANAGER ResourceManager,
    [in] PKTRANSACTION Transaction,
    [in, optional] ULONG CreateOptions,
    [in] NOTIFICATION_MASK NotificationMask,
    [in, optional] PVOID EnlistmentKey
);

ULONG_PTR KeIpiGenericCall(
    [in] PKIPI_BROADCAST_WORKER BroadcastFunction,
    [in] ULONG_PTR Context
);

NTSYSCALLAPI NTSTATUS ZwRollbackTransaction(
    [in] HANDLE TransactionHandle,
    [in] BOOLEAN Wait
);

KAFFINITY KeSetSystemAffinityThreadEx(
    [in] KAFFINITY Affinity
);

NTSTATUS IoGetDeviceObjectPointer(
    [in] PUNICODE_STRING ObjectName,
    [in] ACCESS_MASK DesiredAccess,
    [out] PFILE_OBJECT *FileObject,
    [out] PDEVICE_OBJECT *DeviceObject
);

void IoSetShareAccessEx(
    [in] ACCESS_MASK DesiredAccess,
    [in] ULONG DesiredShareAccess,
    [in, out] PFILE_OBJECT FileObject,
    [out] PSHARE_ACCESS ShareAccess,
    [in, optional] PBOOLEAN WritePermission
);

USHORT KeQueryMaximumGroupCount();

NTSYSAPI NTSTATUS ZwQueryKey(
    [in] HANDLE KeyHandle,
    [in] KEY_INFORMATION_CLASS KeyInformationClass,
    [out, optional] PVOID KeyInformation,
    [in] ULONG Length,
    [out] PULONG ResultLength
);

BOOLEAN KeInsertByKeyDeviceQueue(
    [in, out] PKDEVICE_QUEUE DeviceQueue,
    [in, out] PKDEVICE_QUEUE_ENTRY DeviceQueueEntry,
    [in] ULONG SortKey
);

void ExFreeToNPagedLookasideList(
    [in, out] PNPAGED_LOOKASIDE_LIST Lookaside,
    [in] PVOID Entry
);

void PoFxIssueComponentPerfStateChange(
    [in] POHANDLE Handle,
    [in] ULONG Flags,
    [in] ULONG Component,
    [in] PPO_FX_PERF_STATE_CHANGE PerfChange,
    [in] PVOID Context
);

void ARM64_SYSREG_OP2(
    _Reg_
);

NTKERNELAPI
    PSLIST_ENTRY
    FASTCALL
    ExInterlockedPopEntrySList (
    _Inout_ PSLIST_HEADER ListHead,
    _Inout_opt_ _Requires_lock_not_held_(*_Curr_) PKSPIN_LOCK Lock
);

PIRP IoCsqRemoveIrp(
    [in, out] PIO_CSQ Csq,
    [in, out] PIO_CSQ_IRP_CONTEXT Context
);

void IoReportInterruptInactive(
    [in] PIO_REPORT_INTERRUPT_ACTIVE_STATE_PARAMETERS Parameters
);

PLIST_ENTRY RemoveHeadList(
    [in, out] PLIST_ENTRY ListHead
);

NTSTATUS MmAllocateContiguousMemoryEx(
    [in] PSIZE_T NumberOfBytes,
    [in] PHYSICAL_ADDRESS LowestAcceptableAddress,
    [in] PHYSICAL_ADDRESS HighestAcceptableAddress,
    [in] PHYSICAL_ADDRESS BoundaryAddressMultiple,
    [in] NODE_REQUIREMENT PreferredNode,
    [in] ULONG Protect,
    [in, optional] PVOID PartitionObject,
    [in] ULONG Tag,
    [in] ULONG Flags,
    [out] PVOID *BaseAddress
);

NTSYSCALLAPI NTSTATUS ZwPrepareEnlistment(
    [in] HANDLE EnlistmentHandle,
    [in, optional] PLARGE_INTEGER TmVirtualClock
);

NTSTATUS WmiTraceMessageVa(
    [in] TRACELOGGER_HANDLE LoggerHandle,
    [in] ULONG MessageFlags,
    [in] LPCGUID MessageGuid,
    [in] USHORT MessageNumber,
    [in] va_list MessageArgList
);

NTSYSAPI VOID RtlFreeUTF8String(
    PUTF8_STRING utf8String
);

CLFSUSER_API NTSTATUS ClfsReadPreviousRestartArea(
    [in] PVOID pvReadContext,
    [out] PVOID *ppvRestartBuffer,
    [out] PULONG pcbRestartBuffer,
    [out] PCLFS_LSN plsnRestart
);

BOOLEAN IoIsErrorUserInduced(
    Status
);

NTSTATUS EtwSetInformation(
    [in] REGHANDLE RegHandle,
    [in] EVENT_INFO_CLASS InformationClass,
    [in, optional] PVOID EventInformation,
    [in] ULONG InformationLength
);

PSLIST_ENTRY FirstEntrySList(
    [in] PSLIST_HEADER SListHead
);

USHORT KeQueryHighestNodeNumber();

NTSYSAPI NTSTATUS ZwCreateFile(
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

void ExInitializeRundownProtection(
    [out] PEX_RUNDOWN_REF RunRef
);

__kernel_entry NTSYSCALLAPI NTSTATUS NtPowerInformation(
    [in] POWER_INFORMATION_LEVEL InformationLevel,
    [in, optional] PVOID InputBuffer,
    [in] ULONG InputBufferLength,
    [out, optional] PVOID OutputBuffer,
    [in] ULONG OutputBufferLength
);

void PoFxCompleteIdleState(
    [in] POHANDLE Handle,
    [in] ULONG Component
);

LONG InterlockedOr(
    [in, out] LONG volatile *Destination,
    [in] LONG Value
);

PKEVENT IoCreateNotificationEvent(
    [in] PUNICODE_STRING EventName,
    [out] PHANDLE EventHandle
);

NTSTATUS IoUnregisterPlugPlayNotificationEx(
    [in] PVOID NotificationEntry
);

BOOLEAN ExDeleteTimer(
    [in] PEX_TIMER Timer,
    [in] BOOLEAN Cancel,
    [in] BOOLEAN Wait,
    [in] PEXT_DELETE_PARAMETERS Parameters
);

NTSTATUS IoWMIQueryAllData(
    [in] PVOID DataBlockObject,
    [in, out] PULONG InOutBufferSize,
    [out, optional] PVOID OutBuffer
);

PVOID MmMapIoSpace(
    [in] PHYSICAL_ADDRESS PhysicalAddress,
    [in] SIZE_T NumberOfBytes,
    [in] MEMORY_CACHING_TYPE CacheType
);

void ExFreePoolWithTag(
    [in] PVOID P,
    [in] ULONG Tag
);

CLFSUSER_API NTSTATUS ClfsReserveAndAppendLog(
    [in] PVOID pvMarshalContext,
    [in, optional] PCLFS_WRITE_ENTRY rgWriteEntries,
    [in] ULONG cWriteEntries,
    [in, optional] PCLFS_LSN plsnUndoNext,
    [in, optional] PCLFS_LSN plsnPrevious,
    [in] ULONG cReserveRecords,
    [in, out] PLONGLONG rgcbReservation,
    [in] ULONG fFlags,
    [out, optional] PCLFS_LSN plsn
);

void PoFxCompleteDirectedPowerDown(
    POHANDLE Handle
);

void PoFxSetComponentWake(
    [in] POHANDLE Handle,
    [in] ULONG Component,
    [in] BOOLEAN WakeHint
);

NTSYSAPI ULONG RtlNumberOfSetBits(
    [in] PRTL_BITMAP BitMapHeader
);

NTSYSAPI NTSTATUS RtlStringFromGUID(
    [in] REFGUID Guid,
    [out] PUNICODE_STRING GuidString
);

ULONG KeQueryRuntimeThread(
    [in] PKTHREAD Thread,
    [out] PULONG UserTime
);

NTSYSAPI NTSTATUS RtlWriteRegistryValue(
    [in] ULONG RelativeTo,
    [in] PCWSTR Path,
    [in] PCWSTR ValueName,
    [in] ULONG ValueType,
    [in, optional] PVOID ValueData,
    [in] ULONG ValueLength
);

PLIST_ENTRY ExInterlockedRemoveHeadList(
    [in, out] PLIST_ENTRY ListHead,
    [in, out] PKSPIN_LOCK Lock
);

BOOLEAN KeDeregisterBugCheckCallback(
    [in, out] PKBUGCHECK_CALLBACK_RECORD CallbackRecord
);

NTSTATUS EtwActivityIdControl(
    [in] ULONG ControlCode,
    [in, out] LPGUID ActivityId
);

void KeBugCheckEx(
    [in] ULONG BugCheckCode,
    [in] ULONG_PTR BugCheckParameter1,
    [in] ULONG_PTR BugCheckParameter2,
    [in] ULONG_PTR BugCheckParameter3,
    [in] ULONG_PTR BugCheckParameter4
);

void WriteUInt32NoFence(
    UINT32 volatile *Destination,
    UINT32 Value
);

NTSYSAPI NTSTATUS ZwOpenKeyTransactedEx(
    [out] PHANDLE KeyHandle,
    [in] ACCESS_MASK DesiredAccess,
    [in] POBJECT_ATTRIBUTES ObjectAttributes,
    [in] ULONG OpenOptions,
    [in] HANDLE TransactionHandle
);

void ExAcquireFastMutexUnsafe(
    PFAST_MUTEX FastMutex
);

ULONG ExSetTimerResolution(
    [in] ULONG DesiredTime,
    [in] BOOLEAN SetResolution
);

void ExReInitializeRundownProtection(
    [in, out] PEX_RUNDOWN_REF RunRef
);

NTSTATUS PoFxRegisterComponentPerfStates(
    [in] POHANDLE Handle,
    [in] ULONG Component,
    [in] ULONGLONG Flags,
    [in] PPO_FX_COMPONENT_PERF_STATE_CALLBACK ComponentPerfStateCallback,
    [in] PPO_FX_COMPONENT_PERF_INFO InputStateInfo,
    [out] PPO_FX_COMPONENT_PERF_INFO *OutputStateInfo
);

NTKERNELAPI
    PSLIST_ENTRY
    FASTCALL
    ExInterlockedPushEntrySList (
    _Inout_ PSLIST_HEADER ListHead,
    _Inout_ __drv_aliasesMem PSLIST_ENTRY ListEntry,
    _Inout_opt_ _Requires_lock_not_held_(*_Curr_) PKSPIN_LOCK Lock
);

PVOID ExAllocatePoolZero(
    __drv_strictTypeMatch(__drv_typeExpr)POOL_TYPE PoolType,
    SIZE_T NumberOfBytes,
    ULONG Tag
);

ULONG64 KeQueryTotalCycleTimeThread(
    [in, out] PKTHREAD Thread,
    [out] PULONG64 CycleTimeStamp
);

void RtlCopyMemory(
    void* Destination,
    const void* Source,
    size_t Length
);

NTSYSCALLAPI NTSTATUS ZwOpenEnlistment(
    [out] PHANDLE EnlistmentHandle,
    [in] ACCESS_MASK DesiredAccess,
    [in] HANDLE RmHandle,
    [in] LPGUID EnlistmentGuid,
    [in, optional] POBJECT_ATTRIBUTES ObjectAttributes
);

void MmProbeAndLockSelectedPages(
    [in, out] PMDL MemoryDescriptorList,
    [in] PFILE_SEGMENT_ELEMENT SegmentArray,
    [in] KPROCESSOR_MODE AccessMode,
    [in] LOCK_OPERATION Operation
);

NTSTATUS IoQueryKsrPersistentMemorySizeEx(
    PDRIVER_OBJECT DriverObject,
    PDEVICE_OBJECT PhysicalDeviceObject,
    PUNICODE_STRING PhysicalDeviceId,
    PUSHORT DataTag,
    PULONG DataVersion,
    PSIZE_T BufferSize
);

NTSYSAPI VOID RtlFillMemoryNonTemporal(
    VOID *Destination,
    SIZE_T Length,
    const UCHAR Value
);

void IoReleaseRemoveLockAndWait(
    [in] RemoveLock,
    [in] Tag
);

NTSYSAPI NTSTATUS RtlCreateSecurityDescriptor(
    [out] PSECURITY_DESCRIPTOR SecurityDescriptor,
    [in] ULONG Revision
);

NTSTATUS CmSetCallbackObjectContext(
    [in, out] PVOID Object,
    [in] PLARGE_INTEGER Cookie,
    [in] PVOID NewContext,
    [out, optional] PVOID *OldContext
);

volatile void * RtlCopyDeviceMemory(
    [out] volatile void *Destination,
    [in] volatile const void *Source,
    [in] size_t Length
);

NTSYSAPI BOOLEAN RtlValidSecurityDescriptor(
    [in] PSECURITY_DESCRIPTOR SecurityDescriptor
);

NTSTATUS PoQueryPowerLimitAttributes(
    PVOID PowerLimitRequest,
    ULONG BufferCount,
    PPOWER_LIMIT_ATTRIBUTES Buffer,
    PULONG AttributeCount
);

void RtlSanitizeUnicodeStringPadding(
    PUNICODE_STRING String
);

NTSYSAPI ULONG RtlFindClearBitsAndSet(
    [in] PRTL_BITMAP BitMapHeader,
    [in] ULONG NumberToFind,
    [in] ULONG HintIndex
);

void SeUnlockSubjectContext(
    [in] PSECURITY_SUBJECT_CONTEXT SubjectContext
);

void KeSetTargetProcessorDpc(
    [in, out] PRKDPC Dpc,
    [in] CCHAR Number
);

__kernel_entry NTSYSCALLAPI NTSTATUS NtOpenTransaction(
    [out] PHANDLE TransactionHandle,
    [in] ACCESS_MASK DesiredAccess,
    [in, optional] POBJECT_ATTRIBUTES ObjectAttributes,
    [in] LPGUID Uow,
    [in, optional] HANDLE TmHandle
);

KPRIORITY KeQueryPriorityThread(
    [in] PKTHREAD Thread
);

ULONG KeQueryTimeIncrement();

void ObDereferenceObject(
    [in] a
);

void KeRestoreExtendedProcessorState(
    [in] PXSTATE_SAVE XStateSave
);

CLFSUSER_API BOOLEAN ClfsLsnGreater(
    [in] const CLFS_LSN *plsn1,
    [in] const CLFS_LSN *plsn2
);

NTSTATUS IoWMIRegistrationControl(
    [in] PDEVICE_OBJECT DeviceObject,
    [in] ULONG Action
);

NTSTATUS MmProtectMdlSystemAddress(
    [in] PMDL MemoryDescriptorList,
    [in] ULONG NewProtect
);

void ROUND_TO_PAGES(
    [in] Size
);

void KeLeaveGuardedRegion();

void IoStartTimer(
    [in] PDEVICE_OBJECT DeviceObject
);

NTSTATUS MmMapMemoryDumpMdlEx(
    PVOID Va,
    PFN_NUMBER PageTotal,
    PMDL MemoryDumpMdl,
    ULONG Flags
);

void WriteInt32NoFence(
    INT32 volatile *Destination,
    INT32 Value
);

NTSTATUS SeAssignSecurity(
    [in, optional] PSECURITY_DESCRIPTOR ParentDescriptor,
    [in, optional] PSECURITY_DESCRIPTOR ExplicitDescriptor,
    [out] PSECURITY_DESCRIPTOR *NewDescriptor,
    [in] BOOLEAN IsDirectoryObject,
    [in] PSECURITY_SUBJECT_CONTEXT SubjectContext,
    [in] PGENERIC_MAPPING GenericMapping,
    [in] POOL_TYPE PoolType
);

void ExInitializeFastMutex(
    [out] PFAST_MUTEX FastMutex
);

void IoStartNextPacket(
    [in] PDEVICE_OBJECT DeviceObject,
    [in] BOOLEAN Cancelable
);

NTSTATUS TmCommitTransaction(
    [in] PKTRANSACTION Transaction,
    [in] BOOLEAN Wait
);

NTSTATUS IoGetBootDiskInformation(
    [in, out] PBOOTDISK_INFORMATION BootDiskInformation,
    [in] ULONG Size
);

void IoSetNextIrpStackLocation(
    [in, out] PIRP Irp
);

void IoWriteErrorLogEntry(
    [in] PVOID ElEntry
);

BOOLEAN KeTryToAcquireSpinLockAtDpcLevel(
    [in, out] PKSPIN_LOCK SpinLock
);

PVOID ExAllocatePoolPriorityUninitialized(
    __drv_strictTypeMatch(__drv_typeExpr)POOL_TYPE PoolType,
    SIZE_T NumberOfBytes,
    ULONG Tag,
    EX_POOL_PRIORITY Priority
);

unsigned char _BitTest64(
    __int64 const *Base,
    __int64 Index
);

NTSYSAPI BOOLEAN RtlTestBit(
    [in] PRTL_BITMAP BitMapHeader,
    [in] ULONG BitNumber
);

NTSYSAPI NTSTATUS RtlAppendUnicodeStringToString(
    [in, out] PUNICODE_STRING Destination,
    [in] PCUNICODE_STRING Source
);

NTSYSCALLAPI NTSTATUS ZwCreateEnlistment(
    [out] PHANDLE EnlistmentHandle,
    [in] ACCESS_MASK DesiredAccess,
    [in] HANDLE ResourceManagerHandle,
    [in] HANDLE TransactionHandle,
    [in, optional] POBJECT_ATTRIBUTES ObjectAttributes,
    [in, optional] ULONG CreateOptions,
    [in] NOTIFICATION_MASK NotificationMask,
    [in, optional] PVOID EnlistmentKey
);

NTHALAPI VOID WRITE_PORT_ULONG(
    [in] PULONG Port,
    [in] ULONG Value
);

LOGICAL MmIsDriverSuspectForVerifier(
    [in] _DRIVER_OBJECT *DriverObject
);

void IoSkipCurrentIrpStackLocation(
    [in, out] PIRP Irp
);

void KeLowerIrql(
    [in] KIRQL NewIrql
);

NTSYSCALLAPI NTSTATUS ZwRecoverResourceManager(
    [in] HANDLE ResourceManagerHandle
);

NTSYSAPI NTSTATUS ZwUnmapViewOfSection(
    [in] HANDLE ProcessHandle,
    [in, optional] PVOID BaseAddress
);

DECLSPEC_DEPRECATED_DDK_WINXP LARGE_INTEGER NTAPI_INLINE RtlConvertUlongToLargeInteger(
    [in] ULONG UnsignedInteger
);

NTSTATUS IoRegisterPlugPlayNotification(
    [in] IO_NOTIFICATION_EVENT_CATEGORY EventCategory,
    [in] ULONG EventCategoryFlags,
    [in, optional] PVOID EventCategoryData,
    [in] PDRIVER_OBJECT DriverObject,
    [in] PDRIVER_NOTIFICATION_CALLBACK_ROUTINE CallbackRoutine,
    [in, optional] __drv_aliasesMem PVOID Context,
    [out] PVOID *NotificationEntry
);

NTSTATUS MmProtectDriverSection(
    [in] PVOID AddressWithinSection,
    [in] SIZE_T Size,
    [in] ULONG Flags
);

BOOLEAN RemoveEntryList(
    [in] PLIST_ENTRY Entry
);

void IoGetFunctionCodeFromCtlCode(
    [in] ControlCode
);

NTSYSAPI ULONGLONG RtlCmDecodeMemIoResource(
    [in] PCM_PARTIAL_RESOURCE_DESCRIPTOR Descriptor,
    [out, optional] PULONGLONG Start
);

void InitializeSListHead(
    [in] PSLIST_HEADER SListHead
);

void PoDeletePowerRequest(
    [in, out] PVOID PowerRequest
);

CLFSUSER_API ULONG ClfsLsnBlockOffset(
    [in] const CLFS_LSN *plsn
);

NTSTATUS IoReserveKsrPersistentMemoryEx(
    PDRIVER_OBJECT DriverObject,
    PDEVICE_OBJECT PhysicalDeviceObject,
    PUNICODE_STRING PhysicalDeviceId,
    PUSHORT DataTag,
    ULONG DataVersion,
    SIZE_T Size,
    ULONG Flags,
    PVOID *DataHandle
);

__drv_aliasesMem PIRP IoBuildAsynchronousFsdRequest(
    [in] ULONG MajorFunction,
    [in] PDEVICE_OBJECT DeviceObject,
    [in, out] PVOID Buffer,
    [in, optional] ULONG Length,
    [in, optional] PLARGE_INTEGER StartingOffset,
    [in, optional] PIO_STATUS_BLOCK IoStatusBlock
);

NTSTATUS TmRecoverResourceManager(
    [in] PKRESOURCEMANAGER ResourceManager
);

void IoAdjustPagingPathCount(
    [in] _count_,
    [in] _paging_
);

void IoSetTopLevelIrp(
    [in, optional] PIRP Irp
);

NTSTATUS IoEnumerateKsrPersistentMemoryEx(
    PDRIVER_OBJECT DriverObject,
    PDEVICE_OBJECT PhysicalDeviceObject,
    PUNICODE_STRING PhysicalDeviceId,
    PIO_PERSISTED_MEMORY_ENUMERATION_CALLBACK Callback,
    PVOID CallbackContext
);

void IoRemoveShareAccess(
    [in] PFILE_OBJECT FileObject,
    [in, out] PSHARE_ACCESS ShareAccess
);

void KeReleaseSpinLockForDpc(
    [in, out] PKSPIN_LOCK SpinLock,
    [in] KIRQL OldIrql
);

NTSYSAPI NTSTATUS ZwSetValueKey(
    [in] HANDLE KeyHandle,
    [in] PUNICODE_STRING ValueName,
    [in, optional] ULONG TitleIndex,
    [in] ULONG Type,
    [in, optional] PVOID Data,
    [in] ULONG DataSize
);

void PoFxSetComponentResidency(
    [in] POHANDLE Handle,
    [in] ULONG Component,
    [in] ULONGLONG Residency
);

NTSTATUS EtwWriteTransfer(
    [in] REGHANDLE RegHandle,
    [in] PCEVENT_DESCRIPTOR EventDescriptor,
    [in, optional] LPCGUID ActivityId,
    [in, optional] LPCGUID RelatedActivityId,
    [in] ULONG UserDataCount,
    [in, optional] PEVENT_DATA_DESCRIPTOR UserData
);

NTSTATUS IofCallDriver(
    PDEVICE_OBJECT DeviceObject,
    __drv_aliasesMem PIRP Irp
);

void ExFlushLookasideListEx(
    [in, out] PLOOKASIDE_LIST_EX Lookaside
);

NTSYSAPI ULONG RtlFindLongestRunClear(
    [in] PRTL_BITMAP BitMapHeader,
    [out] PULONG StartingIndex
);

NTSYSAPI NTSTATUS RtlGetVersion(
    [out] PRTL_OSVERSIONINFOW lpVersionInformation
);

void ExInitializeDriverRuntime(
    ULONG RuntimeFlags
);

_DMA_ADAPTER * IoGetDmaAdapter(
    [in, optional] PDEVICE_OBJECT PhysicalDeviceObject,
    [in] _DEVICE_DESCRIPTION *DeviceDescription,
    [out] PULONG NumberOfMapRegisters
);

void Iosb64ToIosb(
    _iosb,
    _iosb64
);

void IoInitializeWorkItem(
    [in] PVOID IoObject,
    [in] PIO_WORKITEM IoWorkItem
);

void PoFxNotifySurprisePowerOn(
    [in] PDEVICE_OBJECT Pdo
);

NTSTATUS IoWMIQuerySingleInstance(
    [in] PVOID DataBlockObject,
    [in] PUNICODE_STRING InstanceName,
    [in, out] PULONG InOutBufferSize,
    [out, optional] PVOID OutBuffer
);

void KeInitializeMutex(
    [out] PRKMUTEX Mutex,
    [in] ULONG Level
);

void ObDereferenceObjectDeferDeleteWithTag(
    [in] PVOID Object,
    [in] ULONG Tag
);

NTSTATUS PoQueryPowerLimitValue(
    PVOID PowerLimitRequest,
    ULONG ValueCount,
    PPOWER_LIMIT_VALUE Values
);

NTHALAPI VOID READ_PORT_BUFFER_USHORT(
    [in] PUSHORT Port,
    [out] PUSHORT Buffer,
    [in] ULONG Count
);

ULONG IoWMIDeviceObjectToProviderId(
    [in] PDEVICE_OBJECT DeviceObject
);

void KeReleaseInStackQueuedSpinLock(
    [in] PKLOCK_QUEUE_HANDLE LockHandle
);

void KeAcquireGuardedMutex(
    PKGUARDED_MUTEX Mutex
);

void KdPrint(
    [in] _x_
);

void MmUnmapReservedMapping(
    [in] PVOID BaseAddress,
    [in] ULONG PoolTag,
    [in] PMDL MemoryDescriptorList
);

__kernel_entry NTSYSCALLAPI NTSTATUS NtCreateTransaction(
    [out] PHANDLE TransactionHandle,
    [in] ACCESS_MASK DesiredAccess,
    [in, optional] POBJECT_ATTRIBUTES ObjectAttributes,
    [in, optional] LPGUID Uow,
    [in, optional] HANDLE TmHandle,
    [in, optional] ULONG CreateOptions,
    [in, optional] ULONG IsolationLevel,
    [in, optional] ULONG IsolationFlags,
    [in, optional] PLARGE_INTEGER Timeout,
    [in, optional] PUNICODE_STRING Description
);

NTSYSAPI BOOLEAN RtlTimeFieldsToTime(
    [in] PTIME_FIELDS TimeFields,
    [out] PLARGE_INTEGER Time
);

void ExConvertExclusiveToSharedLite(
    [in, out] PERESOURCE Resource
);

NTSTATUS ExCreatePool(
    ULONG Flags,
    ULONG_PTR Tag,
    POOL_CREATE_EXTENDED_PARAMS *Params,
    HANDLE *PoolHandle
);

NTSTATUS ExInitializeResourceLite(
    [out] PERESOURCE Resource
);

NTSTATUS IoGetDeviceInterfaces(
    [in] const GUID *InterfaceClassGuid,
    [in, optional] PDEVICE_OBJECT PhysicalDeviceObject,
    [in] ULONG Flags,
    [out] PZZWSTR *SymbolicLinkList
);

void PoSetDeviceBusy(
    [in, out] IdlePointer
);

NTSYSAPI VOID RtlClearAllBits(
    [in] PRTL_BITMAP BitMapHeader
);

NTSYSCALLAPI NTSTATUS ZwGetNotificationResourceManager(
    [in] HANDLE ResourceManagerHandle,
    [out] PTRANSACTION_NOTIFICATION TransactionNotification,
    [in] ULONG NotificationLength,
    [in] PLARGE_INTEGER Timeout,
    [out, optional] PULONG ReturnLength,
    [in] ULONG Asynchronous,
    [in, optional] ULONG_PTR AsynchronousContext
);

BOOLEAN ExIsResourceAcquiredExclusiveLite(
    [in] PERESOURCE Resource
);

void RtlStoreUlongPtr(
    [out] ADDRESS,
    [in] VALUE
);

CLFSUSER_API NTSTATUS ClfsFlushBuffers(
    [in] PVOID pvMarshalContext
);

NTSTATUS IoCreateSymbolicLink(
    [in] PUNICODE_STRING SymbolicLinkName,
    [in] PUNICODE_STRING DeviceName
);

ULONGLONG KeQueryUnbiasedInterruptTime();

void ProbeForRead(
    [in] const volatile VOID *Address,
    [in] SIZE_T Length,
    [in] ULONG Alignment
);

UINT32 ReadUInt32Raw(
    UINT32 const volatile *Source
);

BOOLEAN ExTryAcquirePushLockExclusive(
    Lock
);

void ExReleaseSpinLockShared(
    [in, out] PEX_SPIN_LOCK SpinLock,
    [in] KIRQL OldIrql
);

NTSTATUS IoRegisterShutdownNotification(
    [in] PDEVICE_OBJECT DeviceObject
);

BOOLEAN KeTryToAcquireGuardedMutex(
    [in, out] PKGUARDED_MUTEX Mutex
);

void PcwCloseInstance(
    [in] PPCW_INSTANCE Instance
);

void ExFreeCacheAwareRundownProtection(
    [in, out] PEX_RUNDOWN_REF_CACHE_AWARE RunRefCacheAware
);

BOOL WINAPI
    RtlEqualMemory(
    [in] void* Destination,
    [in] void* Source,
    [in] size_t Length
);

NTSYSAPI VOID RtlInitializeBitMap(
    [out] PRTL_BITMAP BitMapHeader,
    [in] __drv_aliasesMem PULONG BitMapBuffer,
    [in] ULONG SizeOfBitMap
);

UINT32 ReadUInt32NoFence(
    UINT32 const volatile *Source
);

NTSTATUS SeDeassignSecurity(
    [in, out] PSECURITY_DESCRIPTOR *SecurityDescriptor
);

NTSTATUS KeQueryAuxiliaryCounterFrequency(
    [out, optional] PULONG64 AuxiliaryCounterFrequency
);

NTSTATUS TmPrepareEnlistment(
    [in] PKENLISTMENT Enlistment,
    [in] PLARGE_INTEGER TmVirtualClock
);

void ExDeletePagedLookasideList(
    [in, out] PPAGED_LOOKASIDE_LIST Lookaside
);

NTSTATUS IoDeleteSymbolicLink(
    [in] PUNICODE_STRING SymbolicLinkName
);

void KeInitializeSemaphore(
    [out] PRKSEMAPHORE Semaphore,
    [in] LONG Count,
    [in] LONG Limit
);

__kernel_entry NTSYSCALLAPI NTSTATUS NtCreateTransactionManager(
    [out] PHANDLE TmHandle,
    [in] ACCESS_MASK DesiredAccess,
    [in, optional] POBJECT_ATTRIBUTES ObjectAttributes,
    [in, optional] PUNICODE_STRING LogFileName,
    [in, optional] ULONG CreateOptions,
    [in, optional] ULONG CommitStrength
);

PVOID ExAllocatePoolQuotaUninitialized(
    __drv_strictTypeMatch(__drv_typeExpr)POOL_TYPE PoolType,
    SIZE_T NumberOfBytes,
    ULONG Tag
);

void READ_REGISTER_BUFFER_UCHAR(
    [in] volatile UCHAR *Register,
    [out] PUCHAR Buffer,
    [in] ULONG Count
);

CLFSUSER_API NTSTATUS ClfsMgmtRegisterManagedClient(
    [in] PLOG_FILE_OBJECT LogFile,
    [in] PCLFS_MGMT_CLIENT_REGISTRATION RegistrationData,
    PCLFS_MGMT_CLIENT ClientCookie
);

CLFSUSER_API NTSTATUS ClfsAdvanceLogBase(
    [in, out] PVOID pvMarshalContext,
    [in] PCLFS_LSN plsnBase,
    [in] ULONG fFlags
);

PKTHREAD KeGetCurrentThread();

LOGICAL KeShouldYieldProcessor();

void RtlStoreUlong(
    [out] ADDRESS,
    [in] VALUE
);

NTSTATUS SeEtwWriteKMCveEvent(
    [in] PCUNICODE_STRING CveId,
    [in, optional] PCUNICODE_STRING AdditionalDetails
);

NTSTATUS TmRequestOutcomeEnlistment(
    [in] PKENLISTMENT Enlistment,
    [in] PLARGE_INTEGER TmVirtualClock
);

void ExReleaseFastMutex(
    PFAST_MUTEX FastMutex
);

NTSTATUS IoWMIDeviceObjectToInstanceName(
    [in] PVOID DataBlockObject,
    [in] PDEVICE_OBJECT DeviceObject,
    [out] PUNICODE_STRING InstanceName
);

NTHALAPI KIRQL KeGetCurrentIrql();

NTSTATUS VslDeleteSecureSection(
    HANDLE GlobalHandle
);

BOOLEAN IoForwardIrpSynchronously(
    [in] PDEVICE_OBJECT DeviceObject,
    [in] PIRP Irp
);

int RtlConstantTimeEqualMemory(
    const void *v1,
    const void *v2,
    unsigned long len
);

NTSTATUS IoWMISuggestInstanceName(
    [in, optional] PDEVICE_OBJECT PhysicalDeviceObject,
    [in, optional] PUNICODE_STRING SymbolicLinkName,
    [in] BOOLEAN CombineNames,
    [out] PUNICODE_STRING SuggestedInstanceName
);

NTSTATUS PoSetPowerRequest(
    [in, out] PVOID PowerRequest,
    [in] POWER_REQUEST_TYPE Type
);

void WRITE_REGISTER_ULONG(
    [in] volatile ULONG *Register,
    [in] ULONG Value
);

NTSTATUS IoRegisterDeviceInterface(
    [in] PDEVICE_OBJECT PhysicalDeviceObject,
    [in] const GUID *InterfaceClassGuid,
    [in, optional] PUNICODE_STRING ReferenceString,
    [out] PUNICODE_STRING SymbolicLinkName
);

NTSTATUS PoFxPowerOnCrashdumpDevice(
    [in] POHANDLE Handle,
    [in, optional] PVOID Context
);

NTSYSAPI VOID RtlPrefetchMemoryNonTemporal(
    [in] PVOID Source,
    [in] SIZE_T Length
);

BOOLEAN KeRegisterBugCheckCallback(
    [out] PKBUGCHECK_CALLBACK_RECORD CallbackRecord,
    [in] PKBUGCHECK_CALLBACK_ROUTINE CallbackRoutine,
    [in, optional] PVOID Buffer,
    [in] ULONG Length,
    [in] PUCHAR Component
);

PVOID MmGetSystemAddressForMdl(
    MDL
);

void ExFreePool(
    [in] PVOID P
);

LONG KeReleaseSemaphore(
    [in, out] PRKSEMAPHORE Semaphore,
    [in] KPRIORITY Increment,
    [in] LONG Adjustment,
    [in] BOOLEAN Wait
);

NTSTATUS PoUnregisterPowerSettingCallback(
    [in, out] PVOID Handle
);

NTSTATUS IoSetDeviceInterfacePropertyData(
    [in] PUNICODE_STRING SymbolicLinkName,
    [in] const DEVPROPKEY *PropertyKey,
    [in] LCID Lcid,
    [in] ULONG Flags,
    [in] DEVPROPTYPE Type,
    [in] ULONG Size,
    [in, optional] PVOID Data
);

PMDL IoAllocateMdl(
    [in, optional] __drv_aliasesMem PVOID VirtualAddress,
    [in] ULONG Length,
    [in] BOOLEAN SecondaryBuffer,
    [in] BOOLEAN ChargeQuota,
    [in, out, optional] PIRP Irp
);

ULONG ExGetSharedWaiterCount(
    [in] PERESOURCE Resource
);

USHORT KeGetCurrentNodeNumber();

NTSYSCALLAPI NTSTATUS ZwQueryInformationTransactionManager(
    [in] HANDLE TransactionManagerHandle,
    [in] TRANSACTIONMANAGER_INFORMATION_CLASS TransactionManagerInformationClass,
    [out] PVOID TransactionManagerInformation,
    [in] ULONG TransactionManagerInformationLength,
    [out, optional] PULONG ReturnLength
);

NTSYSAPI NTSTATUS RtlCheckRegistryKey(
    [in] ULONG RelativeTo,
    [in] PWSTR Path
);

PLIST_ENTRY ExInterlockedInsertTailList(
    [in, out] PLIST_ENTRY ListHead,
    [in, out] __drv_aliasesMem PLIST_ENTRY ListEntry,
    [in, out] PKSPIN_LOCK Lock
);

NTSTATUS IoCsqInsertIrpEx(
    [in, out] PIO_CSQ Csq,
    [in, out] PIRP Irp,
    [out, optional] PIO_CSQ_IRP_CONTEXT Context,
    [in, optional] PVOID InsertContext
);

void MmFreeContiguousMemorySpecifyCache(
    [in] PVOID BaseAddress,
    [in] SIZE_T NumberOfBytes,
    [in] MEMORY_CACHING_TYPE CacheType
);

void ExInitializePushLock(
    [Out] PEX_PUSH_LOCK PushLock
);

NTSTATUS EtwWrite(
    [in] REGHANDLE RegHandle,
    [in] PCEVENT_DESCRIPTOR EventDescriptor,
    [in, optional] LPCGUID ActivityId,
    [in] ULONG UserDataCount,
    [in, optional] PEVENT_DATA_DESCRIPTOR UserData
);

CLFSUSER_API NTSTATUS ClfsReadLogRecord(
    [in] PVOID pvMarshalContext,
    [in, out] PCLFS_LSN plsnFirst,
    [in] CLFS_CONTEXT_MODE peContextMode,
    [out] PVOID *ppvReadBuffer,
    [out] PULONG pcbReadBuffer,
    [out] PCLFS_RECORD_TYPE peRecordType,
    [out] PCLFS_LSN plsnUndoNext,
    [out] PCLFS_LSN plsnPrevious,
    [out] PVOID *ppvReadContext
);

void KeAcquireGuardedMutexUnsafe(
    PKGUARDED_MUTEX FastMutex
);

void KeAcquireInStackQueuedSpinLock(
    PKSPIN_LOCK SpinLock,
    PKLOCK_QUEUE_HANDLE LockHandle
);

NTSTATUS PoCreatePowerRequest(
    [out] PVOID *PowerRequest,
    [in] PDEVICE_OBJECT DeviceObject,
    [in] PCOUNTED_REASON_CONTEXT Context
);

void IoReuseIrp(
    [in, out] PIRP Irp,
    [in] NTSTATUS Iostatus
);

BOOLEAN KeSynchronizeExecution(
    [in, out] PKINTERRUPT Interrupt,
    [in] PKSYNCHRONIZE_ROUTINE SynchronizeRoutine,
    [in, optional] __drv_aliasesMem PVOID SynchronizeContext
);

volatile void * RtlFillDeviceMemory(
    [out] volatile void *Destination,
    [in] size_t Length,
    [in] int Fill
);

NTSTATUS IoWMIHandleToInstanceName(
    [in] PVOID DataBlockObject,
    [in] HANDLE FileHandle,
    [out] PUNICODE_STRING InstanceName
);

#define IoCallDriver(a,b) \
    IofCallDriver(a,b)
);

void KeInitializeDeviceQueue(
    [out] PKDEVICE_QUEUE DeviceQueue
);

void PoFxUnregisterDevice(
    [in] POHANDLE Handle
);

NTSYSCALLAPI NTSTATUS ZwPrepareComplete(
    [in] HANDLE EnlistmentHandle,
    [in, optional] PLARGE_INTEGER TmVirtualClock
);

void ASSERTMSG(
    msg,
    exp
);

void BYTES_TO_PAGES(
    [in] Size
);

PVOID MmAllocateContiguousMemorySpecifyCache(
    [in] SIZE_T NumberOfBytes,
    [in] PHYSICAL_ADDRESS LowestAcceptableAddress,
    [in] PHYSICAL_ADDRESS HighestAcceptableAddress,
    [in, optional] PHYSICAL_ADDRESS BoundaryAddressMultiple,
    [in] MEMORY_CACHING_TYPE CacheType
);

void PoSetSystemWakeDevice(
    [in] PDEVICE_OBJECT DeviceObject
);

void PsRevertToUserMultipleGroupAffinityThread(
    [in] PAFFINITY_TOKEN AffinityToken
);

void PoFxSetComponentLatency(
    [in] POHANDLE Handle,
    [in] ULONG Component,
    [in] ULONGLONG Latency
);

UINT32 ReadUInt32Acquire(
    UINT32 const volatile *Source
);

void ExWaitForRundownProtectionReleaseCacheAware(
    [in, out] PEX_RUNDOWN_REF_CACHE_AWARE RunRef
);

void ExReleaseRundownProtection(
    [in, out] PEX_RUNDOWN_REF RunRef
);

void IoReleaseCancelSpinLock(
    KIRQL Irql
);

void KeClearEvent(
    [in, out] PRKEVENT Event
);

NTSYSAPI VOID RtlInitString(
    [out] PSTRING DestinationString,
    [in, optional] __drv_aliasesMem PCSZ SourceString
);

NTSTATUS TmSinglePhaseReject(
    [in] PKENLISTMENT Enlistment,
    [in] PLARGE_INTEGER TmVirtualClock
);

NTSTATUS TmRecoverTransactionManager(
    [in] PKTM Tm,
    [in] PLARGE_INTEGER TargetVirtualClock
);

NTSYSAPI NTSTATUS ZwReadFile(
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

NTSYSAPI VOID RtlCopyUnicodeString(
    [in, out] PUNICODE_STRING DestinationString,
    [in, optional] PCUNICODE_STRING SourceString
);

CLFSUSER_API NTSTATUS ClfsScanLogContainers(
    [in, out] PCLFS_SCAN_CONTEXT pcxScan,
    [in] CLFS_SCAN_MODE eScanMode
);

NTSYSCALLAPI NTSTATUS ZwSetInformationTransaction(
    [in] HANDLE TransactionHandle,
    [in] TRANSACTION_INFORMATION_CLASS TransactionInformationClass,
    [in] PVOID TransactionInformation,
    [in] ULONG TransactionInformationLength
);

NTSYSAPI ULONG RtlxAnsiStringToUnicodeSize(
    [in] PCANSI_STRING AnsiString
);

NTSTATUS MmAdvanceMdl(
    [in, out] PMDL Mdl,
    [in] ULONG NumberOfBytes
);

PVOID MmAllocateContiguousMemory(
    [in] SIZE_T NumberOfBytes,
    [in] PHYSICAL_ADDRESS HighestAcceptableAddress
);

__kernel_entry NTSYSCALLAPI NTSTATUS NtPrepareComplete(
    [in] HANDLE EnlistmentHandle,
    [in, optional] PLARGE_INTEGER TmVirtualClock
);

ULONG KeGetProcessorIndexFromNumber(
    [in] PPROCESSOR_NUMBER ProcNumber
);

NTSTATUS IoCsqInitializeEx(
    [out] PIO_CSQ Csq,
    [in] PIO_CSQ_INSERT_IRP_EX CsqInsertIrp,
    [in] PIO_CSQ_REMOVE_IRP CsqRemoveIrp,
    [in] PIO_CSQ_PEEK_NEXT_IRP CsqPeekNextIrp,
    [in] PIO_CSQ_ACQUIRE_LOCK CsqAcquireLock,
    [in] PIO_CSQ_RELEASE_LOCK CsqReleaseLock,
    [in] PIO_CSQ_COMPLETE_CANCELED_IRP CsqCompleteCanceledIrp
);

LOGICAL ExSecurePoolValidate(
    [in] HANDLE SecurePoolHandle,
    [in] ULONG Tag,
    [in] PVOID Allocation,
    [in] ULONG_PTR Cookie
);

void KeReleaseSpinLockFromDpcLevel(
    [in, out] PKSPIN_LOCK SpinLock
);

NTSYSAPI NTSTATUS RtlCmEncodeMemIoResource(
    [in] PCM_PARTIAL_RESOURCE_DESCRIPTOR Descriptor,
    [in] UCHAR Type,
    [in] ULONGLONG Length,
    [in] ULONGLONG Start
);

void KeLeaveCriticalRegion();

void KeSetImportanceDpc(
    [in, out] PRKDPC Dpc,
    [in] KDPC_IMPORTANCE Importance
);

void WRITE_REGISTER_BUFFER_ULONG(
    [in] volatile ULONG *Register,
    [in] PULONG Buffer,
    [in] ULONG Count
);

NTSYSAPI WCHAR RtlDowncaseUnicodeChar(
    [in] WCHAR SourceCharacter
);

NTSTATUS IoCreateSystemThread(
    [in, out] PVOID IoObject,
    [out] PHANDLE ThreadHandle,
    [in] ULONG DesiredAccess,
    [in, optional] POBJECT_ATTRIBUTES ObjectAttributes,
    [in, optional] HANDLE ProcessHandle,
    [out, optional] PCLIENT_ID ClientId,
    [in] PKSTART_ROUTINE StartRoutine,
    [in, optional] PVOID StartContext
);

LOGICAL MmIsDriverVerifying(
    [in] _DRIVER_OBJECT *DriverObject
);

BOOLEAN KeRemoveQueueDpc(
    [in, out] PRKDPC Dpc
);

NTSYSCALLAPI NTSTATUS ZwPrePrepareEnlistment(
    [in] HANDLE EnlistmentHandle,
    [in, optional] PLARGE_INTEGER TmVirtualClock
);

NTSYSCALLAPI NTSTATUS ZwEnumerateTransactionObject(
    [in, optional] HANDLE RootObjectHandle,
    [in] KTMOBJECT_TYPE QueryType,
    [in, out] PKTMOBJECT_CURSOR ObjectCursor,
    [in] ULONG ObjectCursorLength,
    [out] PULONG ReturnLength
);

NTHALAPI USHORT READ_PORT_USHORT(
    [in] PUSHORT Port
);

NTSYSAPI ULONG RtlUlongByteSwap(
    [in] ULONG Source
);

PVOID ExAllocateFromNPagedLookasideList(
    [in, out] PNPAGED_LOOKASIDE_LIST Lookaside
);

PVOID ExAllocatePoolWithQuota(
    [in] __drv_strictTypeMatch(__drv_typeExpr)POOL_TYPE PoolType,
    [in] SIZE_T NumberOfBytes
);

LONG InterlockedAnd(
    [in, out] LONG volatile *Destination,
    [in] LONG Value
);

VOID KeRaiseIrql(
    _In_ KIRQL NewIrql,
    _Out_ PKIRQL OldIrql
);

PULONG PoRegisterDeviceForIdleDetection(
    [in] PDEVICE_OBJECT DeviceObject,
    [in] ULONG ConservationIdleTime,
    [in] ULONG PerformanceIdleTime,
    [in] DEVICE_POWER_STATE State
);

void IoReportInterruptActive(
    [in] PIO_REPORT_INTERRUPT_ACTIVE_STATE_PARAMETERS Parameters
);

NTSYSAPI USHORT RtlUshortByteSwap(
    [in] USHORT Source
);

NTSTATUS TmPrePrepareComplete(
    [in] PKENLISTMENT Enlistment,
    [in] PLARGE_INTEGER TmVirtualClock
);

void MmBuildMdlForNonPagedPool(
    [in, out] PMDL MemoryDescriptorList
);

NTSTATUS EtwWriteString(
    [in] REGHANDLE RegHandle,
    [in] UCHAR Level,
    [in] ULONGLONG Keyword,
    [in, optional] LPCGUID ActivityId,
    [in] PCWSTR String
);

NTHALAPI VOID READ_PORT_BUFFER_ULONG(
    [in] PULONG Port,
    [out] PULONG Buffer,
    [in] ULONG Count
);

void KeAcquireSpinLockAtDpcLevel(
    [in, out] PKSPIN_LOCK SpinLock
);

LOGICAL MmIsDriverVerifyingByAddress(
    [in] PVOID AddressWithinSection
);

void WRITE_REGISTER_ULONG64(
    [in] volatile ULONG64 *Register,
    [in] ULONG64 Value
);

NTSTATUS ObReferenceObjectByPointerWithTag(
    [in] PVOID Object,
    [in] ACCESS_MASK DesiredAccess,
    [in, optional] POBJECT_TYPE ObjectType,
    [in] KPROCESSOR_MODE AccessMode,
    [in] ULONG Tag
);

NTSTATUS IoOpenDriverRegistryKey(
    [in] PDRIVER_OBJECT DriverObject,
    [in] DRIVER_REGKEY_TYPE RegKeyType,
    [in] ACCESS_MASK DesiredAccess,
    [in] ULONG Flags,
    [out] PHANDLE DriverRegKey
);

CLFSUSER_API NTSTATUS ClfsAllocReservedLog(
    [in] PVOID pvMarshalContext,
    [in] ULONG cRecords,
    [in] PLONGLONG pcbAdjustment
);

BOOLEAN KdRefreshDebuggerNotPresent();

__kernel_entry NTSYSCALLAPI NTSTATUS NtManagePartition(
    [in] HANDLE TargetHandle,
    [in, optional] HANDLE SourceHandle,
    [in] PARTITION_INFORMATION_CLASS PartitionInformationClass,
    [in, out] PVOID PartitionInformation,
    [in] ULONG PartitionInformationLength
);

NTSYSAPI NTSTATUS RtlUnicodeStringToInteger(
    [in] PCUNICODE_STRING String,
    [in, optional] ULONG Base,
    [out] PULONG Value
);

NTSTATUS KeSaveExtendedProcessorState(
    [in] ULONG64 Mask,
    [out] PXSTATE_SAVE XStateSave
);

BOOLEAN SeAccessCheck(
    [in] PSECURITY_DESCRIPTOR SecurityDescriptor,
    [in] PSECURITY_SUBJECT_CONTEXT SubjectSecurityContext,
    [in] BOOLEAN SubjectContextLocked,
    [in] ACCESS_MASK DesiredAccess,
    [in] ACCESS_MASK PreviouslyGrantedAccess,
    [out] PPRIVILEGE_SET *Privileges,
    [in] PGENERIC_MAPPING GenericMapping,
    [in] KPROCESSOR_MODE AccessMode,
    [out] PACCESS_MASK GrantedAccess,
    [out] PNTSTATUS AccessStatus
);

SIZE_T MmSizeOfMdl(
    [in] PVOID Base,
    [in] SIZE_T Length
);

BOOLEAN ExIsProcessorFeaturePresent(
    [in] ULONG ProcessorFeature
);

CLFSUSER_API NTSTATUS ClfsRemoveLogContainer(
    [in] PLOG_FILE_OBJECT plfoLog,
    [in] PUNICODE_STRING puszContainerPath,
    [in] BOOLEAN fForce
);

NTSTATUS IoCreateDevice(
    [in] PDRIVER_OBJECT DriverObject,
    [in] ULONG DeviceExtensionSize,
    [in, optional] PUNICODE_STRING DeviceName,
    [in] DEVICE_TYPE DeviceType,
    [in] ULONG DeviceCharacteristics,
    [in] BOOLEAN Exclusive,
    [out] PDEVICE_OBJECT *DeviceObject
);

void ExQueryTimerResolution(
    [out] PULONG MaximumTime,
    [out] PULONG MinimumTime,
    [out] PULONG CurrentTime
);

void ExInterlockedCompareExchange64(
    [in, out] Destination,
    [in] Exchange,
    Comperand,
    [in] Lock
);

CLFSUSER_API ULONG ClfsLsnRecordSequence(
    [in] const CLFS_LSN *plsn
);

BOOLEAN KeSetCoalescableTimer(
    [in, out] PKTIMER Timer,
    [in] LARGE_INTEGER DueTime,
    [in] ULONG Period,
    [in] ULONG TolerableDelay,
    [in, optional] PKDPC Dpc
);

LONG_PTR ObfReferenceObject(
    [in] PVOID Object
);

void WRITE_REGISTER_BUFFER_ULONG64(
    [in] volatile ULONG64 *Register,
    [in] PULONG64 Buffer,
    [in] ULONG Count
);

BOOLEAN PsGetVersion(
    [out, optional] PULONG MajorVersion,
    [out, optional] PULONG MinorVersion,
    [out, optional] PULONG BuildNumber,
    [out, optional] PUNICODE_STRING CSDVersion
);

NTSTATUS IoUnregisterPlugPlayNotification(
    [in] PVOID NotificationEntry
);

PVOID KeRegisterNmiCallback(
    [in] PNMI_CALLBACK CallbackRoutine,
    [in, optional] PVOID Context
);

ULONG64 READ_REGISTER_ULONG64(
    [in] volatile ULONG64 *Register
);

void IoRequestDeviceEject(
    [in] PDEVICE_OBJECT PhysicalDeviceObject
);

BOOLEAN EtwEventEnabled(
    [in] REGHANDLE RegHandle,
    [in] PCEVENT_DESCRIPTOR EventDescriptor
);

void ExRundownCompleted(
    [out] PEX_RUNDOWN_REF RunRef
);

void IoSetShareAccess(
    [in] ACCESS_MASK DesiredAccess,
    [in] ULONG DesiredShareAccess,
    [in, out] PFILE_OBJECT FileObject,
    [out] PSHARE_ACCESS ShareAccess
);

NTHALAPI UCHAR READ_PORT_UCHAR(
    [in] PUCHAR Port
);

NTSTATUS IoValidateDeviceIoControlAccess(
    [in] PIRP Irp,
    [in] ULONG RequiredAccess
);

BOOLEAN KeInsertQueueDpc(
    [in, out] PRKDPC Dpc,
    [in, optional] PVOID SystemArgument1,
    [in, optional] __drv_aliasesMem PVOID SystemArgument2
);

NTSYSCALLAPI NTSTATUS ZwQueryInformationTransaction(
    [in] HANDLE TransactionHandle,
    [in] TRANSACTION_INFORMATION_CLASS TransactionInformationClass,
    [out] PVOID TransactionInformation,
    [in] ULONG TransactionInformationLength,
    [out, optional] PULONG ReturnLength
);

CLFSUSER_API NTSTATUS ClfsDeleteLogByPointer(
    [in] PLOG_FILE_OBJECT plfoLog
);

BOOLEAN ExAcquireRundownProtectionEx(
    [in, out] PEX_RUNDOWN_REF RunRef,
    [in] ULONG Count
);

NTSYSAPI BOOLEAN RtlAreBitsSet(
    [in] PRTL_BITMAP BitMapHeader,
    [in] ULONG StartingIndex,
    [in] ULONG Length
);

BOOLEAN ExCancelTimer(
    [in, out] PEX_TIMER Timer,
    [in, optional] PEXT_CANCEL_PARAMETERS Parameters
);

void PcwUnregister(
    PPCW_REGISTRATION Registration
);

NTSTATUS KeQueryDpcWatchdogInformation(
    [out] PKDPC_WATCHDOG_INFORMATION WatchdogInformation
);

BOOLEAN KeRemoveEntryDeviceQueue(
    [in, out] PKDEVICE_QUEUE DeviceQueue,
    [in, out] PKDEVICE_QUEUE_ENTRY DeviceQueueEntry
);

BOOLEAN KeTestSpinLock(
    [in] PKSPIN_LOCK SpinLock
);

CLFSUSER_API NTSTATUS ClfsSetEndOfLog(
    [in] PLOG_FILE_OBJECT plfoLog,
    [in] PCLFS_LSN plsnEnd
);

USHORT KeQueryNodeMaximumProcessorCount(
    [in] USHORT NodeNumber
);

NTSTATUS IoWMISetNotificationCallback(
    [in, out] PVOID Object,
    [in] WMI_NOTIFICATION_CALLBACK Callback,
    [in, optional] PVOID Context
);

volatile void * RtlMoveVolatileMemory(
    [out] volatile void *Destination,
    [in] volatile const void *Source,
    [in] size_t Length
);

USHORT ExQueryDepthSList(
    [in] PSLIST_HEADER SListHead
);

PVOID ExAllocatePoolWithTag(
    [in] __drv_strictTypeMatch(__drv_typeExpr)POOL_TYPE PoolType,
    [in] SIZE_T NumberOfBytes,
    [in] ULONG Tag
);

NTSTATUS IoGetIommuInterfaceEx(
    ULONG Version,
    ULONGLONG Flags,
    PDMA_IOMMU_INTERFACE_EX InterfaceOut
);

NTSYSAPI NTSTATUS ZwQueryValueKey(
    [in] HANDLE KeyHandle,
    [in] PUNICODE_STRING ValueName,
    [in] KEY_VALUE_INFORMATION_CLASS KeyValueInformationClass,
    [out, optional] PVOID KeyValueInformation,
    [in] ULONG Length,
    [out] PULONG ResultLength
);

