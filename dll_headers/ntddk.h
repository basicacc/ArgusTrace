void PsReferenceSiloContext(
    [in] PVOID SiloContext
);

NTSTATUS PsSetCreateThreadNotifyRoutine(
    [in] PCREATE_THREAD_NOTIFY_ROUTINE NotifyRoutine
);

NTSYSAPI BOOLEAN RtlNormalizeSecurityDescriptor(
    PSECURITY_DESCRIPTOR *SecurityDescriptor,
    ULONG SecurityDescriptorLength,
    PSECURITY_DESCRIPTOR *NewSecurityDescriptor,
    PULONG NewSecurityDescriptorLength,
    BOOLEAN CheckOnly
);

void WheaErrorRecordBuilderInit(
    PWHEA_ERROR_RECORD Record,
    UINT32 RecordLength,
    WHEA_ERROR_SEVERITY Severity,
    GUID Notify
);

NTSTATUS PsGetThreadExitStatus(
    [in] PETHREAD Thread
);

BOOLEAN WheaHighIrqlLogSelEventHandlerRegister(
    PFN_WHEA_HIGH_IRQL_LOG_SEL_EVENT_HANDLER Handler,
    PVOID Context
);

PVOID WheaErrorRecordBuilderAddPacket(
    [in, out] PWHEA_ERROR_RECORD Record,
    [in, out] PWHEA_ERROR_PACKET_V2 Packet,
    [in] UINT32 MaxSectionCount
);

PEPROCESS IoGetInitiatorProcess(
    [in] PFILE_OBJECT FileObject
);

NTSTATUS PsRemoveLoadImageNotifyRoutine(
    [in] PLOAD_IMAGE_NOTIFY_ROUTINE NotifyRoutine
);

ULONG KeGetCurrentProcessorNumber();

ULONG KeQueryMaximumProcessorCount();

NTSTATUS PsInsertPermanentSiloContext(
    [in] PESILO Silo,
    [in] ULONG ContextSlot,
    [in] PVOID SiloContext
);

NTSTATUS WheaFindErrorRecordSection(
    [in] PWHEA_ERROR_RECORD Record,
    [in] const GUID *SectionType,
    [out] PWHEA_ERROR_RECORD_SECTION_DESCRIPTOR *SectionDescriptor,
    [out, optional] PVOID *SectionData
);

NTSYSAPI VOID RtlRunOnceInitialize(
    [out] PRTL_RUN_ONCE RunOnce
);

NTSTATUS IoVerifyPartitionTable(
    [in] PDEVICE_OBJECT DeviceObject,
    [in] BOOLEAN FixErrors
);

ULONG KeQueryActiveProcessorCount(
    [out, optional] PKAFFINITY ActiveProcessors
);

NTSTATUS WheaRemoveErrorSourceDeviceDriver(
    ULONG ErrorSourceId
);

void IoAllocateController(
    [in] PCONTROLLER_OBJECT ControllerObject,
    [in] PDEVICE_OBJECT DeviceObject,
    [in] PDRIVER_CONTROL ExecutionRoutine,
    [in, optional] PVOID Context
);

void KeEnterGuardedRegion();

NTSYSAPI VOID RtlInitializeGenericTable(
    [out] PRTL_GENERIC_TABLE Table,
    [in] PRTL_GENERIC_COMPARE_ROUTINE CompareRoutine,
    [in] PRTL_GENERIC_ALLOCATE_ROUTINE AllocateRoutine,
    [in] PRTL_GENERIC_FREE_ROUTINE FreeRoutine,
    [in, optional] PVOID TableContext
);

NTSYSAPI PRTL_SPLAY_LINKS RtlSplay(
    [in, out] PRTL_SPLAY_LINKS Links
);

BOOLEAN MmIsAddressValid(
    [in] PVOID VirtualAddress
);

void RtlLeftChild(
    [in] Links
);

ULONG KeGetCurrentProcessorNumberEx(
    [out, optional] PPROCESSOR_NUMBER ProcNumber
);

NTSTATUS WheaAddErrorSourceDeviceDriver(
    PVOID Context,
    PWHEA_ERROR_SOURCE_CONFIGURATION_DEVICE_DRIVER Configuration,
    ULONG NumberPreallocatedErrorReports
);

NTSTATUS PsInsertSiloContext(
    [in] PESILO Silo,
    [in] ULONG ContextSlot,
    [in] PVOID SiloContext
);

NTSTATUS IoAllocateAdapterChannel(
    PADAPTER_OBJECT AdapterObject,
    PDEVICE_OBJECT DeviceObject,
    ULONG NumberOfMapRegisters,
    PDRIVER_CONTROL ExecutionRoutine,
    PVOID Context
);

ULONG KeQueryMaximumProcessorCountEx(
    [in] USHORT GroupNumber
);

NTSTATUS KeSetHardwareCounterConfiguration(
    [in] PHARDWARE_COUNTER CounterArray,
    [in] ULONG Count
);

NTSYSAPI BOOLEAN RtlIsGenericTableEmptyAvl(
    [in] PRTL_AVL_TABLE Table
);

NTSTATUS PsSetCreateProcessNotifyRoutine(
    [in] PCREATE_PROCESS_NOTIFY_ROUTINE NotifyRoutine,
    [in] BOOLEAN Remove
);

NTSTATUS PsMakeSiloContextPermanent(
    [in] PESILO Silo,
    [in] ULONG ContextSlot
);

void WheaUnregisterErrorSourceOverride(
    [in] WHEA_ERROR_SOURCE_TYPE Type,
    [in] ULONG32 OverrideErrorSourceId
);

VOID
    KeQueryTickCount (
    _Out_ PLARGE_INTEGER CurrentCount
);

NTSTATUS KeExpandKernelStackAndCalloutEx(
    PEXPAND_STACK_CALLOUT Callout,
    PVOID Parameter,
    SIZE_T Size,
    BOOLEAN Wait,
    PVOID Context
);

NTSTATUS PsGetProcessExitStatus(
    [in] PEPROCESS Process
);

BOOLEAN FsRtlIsTotalDeviceFailure(
    [in] NTSTATUS Status
);

NTSTATUS PsRemoveCreateThreadNotifyRoutine(
    [in] PCREATE_THREAD_NOTIFY_ROUTINE NotifyRoutine
);

NTSYSAPI PVOID RtlLookupElementGenericTableFullAvl(
    [in] PRTL_AVL_TABLE Table,
    [in] PVOID Buffer,
    [out] PVOID *NodeOrParent,
    [out] TABLE_SEARCH_RESULT *SearchResult
);

NTSYSAPI PRTL_SPLAY_LINKS RtlRealSuccessor(
    [in] PRTL_SPLAY_LINKS Links
);

void WheaAdd2Ptr(
    P,
    I
);

NTSTATUS WheaAddErrorSourceDeviceDriverV1(
    PVOID Context,
    PWHEA_ERROR_SOURCE_CONFIGURATION_DEVICE_DRIVER Configuration,
    ULONG NumBuffersToPreallocate,
    ULONG MaxDataLength
);

HANDLE PsGetCurrentThreadId();

void WheaLogInternalEvent(
    PWHEA_EVENT_LOG_ENTRY Entry
);

USHORT KeQueryActiveGroupCount();

void ExRaiseDatatypeMisalignment();

NTSTATUS IoPropagateActivityIdToThread(
    [in] PIRP Irp,
    [out] LPGUID PropagatedId,
    LPCGUID *OriginalId
);

NTSTATUS PsCreateSiloContext(
    [in] PESILO Silo,
    [in] ULONG Size,
    [in] POOL_TYPE PoolType,
    [in, optional] SILO_CONTEXT_CLEANUP_CALLBACK ContextCleanupCallback,
    PVOID *ReturnedSiloContext
);

HANDLE PsGetThreadProcessId(
    PETHREAD Thread
);

NTSYSAPI NTSTATUS RtlUpcaseUnicodeString(
    [in, out] PUNICODE_STRING DestinationString,
    [in] PCUNICODE_STRING SourceString,
    [in] BOOLEAN AllocateDestinationString
);

NTSTATUS IoVolumeDeviceToDosName(
    [in] PVOID VolumeDeviceObject,
    [out] PUNICODE_STRING DosName
);

NTSTATUS WheaAddErrorSource(
    PWHEA_ERROR_SOURCE_DESCRIPTOR ErrorSource,
    PVOID Context
);

NTSTATUS WheaHwErrorReportSetSectionNameDeviceDriver(
    PWHEA_DRIVER_BUFFER_SET BufferSet,
    ULONG NameLength,
    PUCHAR Name
);

LUID NTAPI_INLINE RtlConvertLongToLuid(
    [in] LONG Long
);

void MmFreeNonCachedMemory(
    [in] PVOID BaseAddress,
    [in] SIZE_T NumberOfBytes
);

__kernel_entry NTSYSCALLAPI NTSTATUS NtOpenProcess(
    [out] PHANDLE ProcessHandle,
    [in] ACCESS_MASK DesiredAccess,
    [in] POBJECT_ATTRIBUTES ObjectAttributes,
    [in, optional] PCLIENT_ID ClientId
);

NTSYSAPI NTSTATUS RtlFreeNonVolatileToken(
    [in] PVOID NvToken
);

NTSTATUS HalFreeHardwareCounters(
    _In_ HANDLE CounterSetHandle
);

NTSTATUS IoSetPartitionInformationEx(
    [in] PDEVICE_OBJECT DeviceObject,
    [in] ULONG PartitionNumber,
    [in] _SET_PARTITION_INFORMATION_EX *PartitionInfo
);

PHYSICAL_ADDRESS MmGetPhysicalAddress(
    [in] PVOID BaseAddress
);

NTSYSAPI LONG RtlCompareString(
    [in] const STRING *String1,
    [in] const STRING *String2,
    [in] BOOLEAN CaseInSensitive
);

NTPSHEDAPI BOOLEAN PshedSynchronizeExecution(
    [in] PWHEA_ERROR_SOURCE_DESCRIPTOR ErrorSource,
    [in] PKSYNCHRONIZE_ROUTINE SynchronizeRoutine,
    [in] PVOID SynchronizeContext
);

NTSTATUS PsAllocSiloContextSlot(
    [in] ULONG_PTR Reserved,
    [out] ULONG *ReturnedContextSlot
);

NTSYSAPI NTSTATUS RtlGetNonVolatileToken(
    PVOID NvBuffer,
    SIZE_T Size,
    PVOID *NvToken
);

NTSYSAPI PRTL_SPLAY_LINKS RtlRealPredecessor(
    [in] PRTL_SPLAY_LINKS Links
);

NTSTATUS IoReportDetectedDevice(
    [in] PDRIVER_OBJECT DriverObject,
    [in] INTERFACE_TYPE LegacyBusType,
    [in] ULONG BusNumber,
    [in] ULONG SlotNumber,
    [in, optional] PCM_RESOURCE_LIST ResourceList,
    [in, optional] PIO_RESOURCE_REQUIREMENTS_LIST ResourceRequirements,
    [in] BOOLEAN ResourceAssigned,
    [in, out] PDEVICE_OBJECT *DeviceObject
);

PESILO PsGetParentSilo(
    [in, optional] PEJOB Job
);

NTSYSAPI PVOID RtlEnumerateGenericTableLikeADirectory(
    [in] PRTL_AVL_TABLE Table,
    [in, optional] PRTL_AVL_MATCH_FUNCTION MatchFunction,
    [in, optional] PVOID MatchData,
    [in] ULONG NextFlag,
    [in, out] PVOID *RestartKey,
    [in, out] PULONG DeleteCount,
    [in] PVOID Buffer
);

NTSYSAPI NTSTATUS RtlQueryRegistryValueWithFallback(
    [in] HANDLE PrimaryHandle,
    [in] HANDLE FallbackHandle,
    [in] PUNICODE_STRING ValueName,
    [in] ULONG ValueLength,
    [Out] PULONG ValueType,
    [out] PVOID ValueData,
    [out] PULONG ResultLength
);

NTSYSAPI VOID RtlUpperString(
    [in, out] PSTRING DestinationString,
    [in] const STRING *SourceString
);

NTSTATUS IoDecrementKeepAliveCount(
    [in, out] PFILE_OBJECT FileObject,
    [in, out] PEPROCESS Process
);

void IoRegisterBootDriverReinitialization(
    [in] PDRIVER_OBJECT DriverObject,
    [in] PDRIVER_REINITIALIZE DriverReinitializationRoutine,
    [in, optional] PVOID Context
);

NTSTATUS PsGetJobServerSilo(
    [in, optional] PEJOB Job,
    [out] PESILO *ServerSilo
);

PIO_FOEXT_SHADOW_FILE IoGetShadowFileInformation(
    [in] PFILE_OBJECT FileObject
);

NTSTATUS PsRegisterSiloMonitor(
    [in] PSILO_MONITOR_REGISTRATION Registration,
    [out] PSILO_MONITOR *ReturnedMonitor
);

NTSTATUS IoCreateDisk(
    [in] PDEVICE_OBJECT DeviceObject,
    [in, optional] _CREATE_DISK *Disk
);

NTSTATUS PsSetCreateProcessNotifyRoutineEx2(
    [in] PSCREATEPROCESSNOTIFYTYPE NotifyType,
    [in] PVOID NotifyInformation,
    [in] BOOLEAN Remove
);

NTSYSAPI NTSTATUS RtlInitializeCorrelationVector(
    [in, out] PCORRELATION_VECTOR CorrelationVector,
    [in] int Version,
    [in] const GUID *Guid
);

NTSTATUS WheaHwErrorReportSubmitDeviceDriver(
    WHEA_ERROR_HANDLE ErrorHandle
);

NTSTATUS PsSetLoadImageNotifyRoutineEx(
    [in] PLOAD_IMAGE_NOTIFY_ROUTINE NotifyRoutine,
    [in] ULONG_PTR Flags
);

void KeEnterCriticalRegion();

NTSTATUS ExUuidCreate(
    [out] UUID *Uuid
);

NTSYSAPI CHAR RtlUpperChar(
    [in] CHAR Character
);

NTSTATUS IoSetFileObjectIgnoreSharing(
    PFILE_OBJECT FileObject
);

NTSYSAPI PVOID RtlEnumerateGenericTableWithoutSplayingAvl(
    [in] PRTL_AVL_TABLE Table,
    [in, out] PVOID *RestartKey
);

NTHALAPI ULONG HalSetBusDataByOffset(
    [in] BUS_DATA_TYPE BusDataType,
    [in] ULONG BusNumber,
    [in] ULONG SlotNumber,
    [in] PVOID Buffer,
    [in] ULONG Offset,
    [in] ULONG Length
);

PVOID MmAllocateNonCachedMemory(
    [in] SIZE_T NumberOfBytes
);

void WheaHighIrqlLogSelEventHandlerUnregister();

PVOID MmAllocateContiguousMemorySpecifyCache(
    [in] SIZE_T NumberOfBytes,
    [in] PHYSICAL_ADDRESS LowestAcceptableAddress,
    [in] PHYSICAL_ADDRESS HighestAcceptableAddress,
    [in, optional] PHYSICAL_ADDRESS BoundaryAddressMultiple,
    [in] MEMORY_CACHING_TYPE CacheType
);

ULONG KeQueryActiveProcessorCountEx(
    [in] USHORT GroupNumber
);

LPCGUID IoGetActivityIdThread();

NTSYSAPI BOOLEAN RtlDeleteElementGenericTableAvl(
    [in] PRTL_AVL_TABLE Table,
    [in] PVOID Buffer
);

PESILO PsGetCurrentSilo();

NTSTATUS WheaReportHwError(
    PWHEA_ERROR_PACKET ErrorPacket
);

PCONTROLLER_OBJECT IoCreateController(
    [in] ULONG Size
);

NTSYSAPI NTSTATUS RtlRunOnceComplete(
    [in, out] PRTL_RUN_ONCE RunOnce,
    [in] ULONG Flags,
    [in, optional] PVOID Context
);

NTSYSAPI NTSTATUS ZwQueryVolumeInformationFile(
    [in] HANDLE FileHandle,
    [out] PIO_STATUS_BLOCK IoStatusBlock,
    [out] PVOID FsInformation,
    [in] ULONG Length,
    [in] FS_INFORMATION_CLASS FsInformationClass
);

HANDLE MmSecureVirtualMemory(
    [in] PVOID Address,
    [in] SIZE_T Size,
    [in] ULONG ProbeMode
);

NTSTATUS MmMapViewInSystemSpace(
    PVOID Section,
    PVOID *MappedBase,
    PSIZE_T ViewSize
);

NTSTATUS IoSetActivityIdIrp(
    [in] PIRP Irp,
    [in, optional] LPCGUID Guid
);

WHEA_ERROR_HANDLE WheaCreateHwErrorReportDeviceDriver(
    ULONG ErrorSourceId,
    PDEVICE_OBJECT DeviceObject
);

LONG KeSetBasePriorityThread(
    [in, out] PKTHREAD Thread,
    [in] LONG Increment
);

_DECL_HAL_KE_IMPORT KIRQL KeRaiseIrqlToDpcLevel();

PESILO PsAttachSiloToCurrentThread(
    [in] PESILO Silo
);

NTSYSAPI NTSTATUS RtlCharToInteger(
    [in] PCSZ String,
    [in, optional] ULONG Base,
    [out] PULONG Value
);

NTSYSAPI PVOID RtlInsertElementGenericTable(
    [in] PRTL_GENERIC_TABLE Table,
    [in] PVOID Buffer,
    [in] CLONG BufferSize,
    [out, optional] PBOOLEAN NewElement
);

NTSYSAPI PRTL_SPLAY_LINKS RtlSubtreePredecessor(
    [in] PRTL_SPLAY_LINKS Links
);

void KeBugCheck(
    [in] ULONG BugCheckCode
);

BOOLEAN IoIsFileObjectIgnoringSharing(
    PFILE_OBJECT FileObject
);

NTSYSAPI VOID RtlCopyString(
    [out] PSTRING DestinationString,
    [in, optional] const STRING *SourceString
);

BOOLEAN SeSinglePrivilegeCheck(
    [in] LUID PrivilegeValue,
    [in] KPROCESSOR_MODE PreviousMode
);

NTSYSAPI ULONG RtlNumberGenericTableElementsAvl(
    [in] PRTL_AVL_TABLE Table
);

NTSTATUS WheaFindNextErrorRecordSection(
    [in] PWHEA_ERROR_RECORD Record,
    [in, out] ULONG *Context,
    [out] PWHEA_ERROR_RECORD_SECTION_DESCRIPTOR *SectionDescriptor,
    [out, optional] PVOID *SectionData
);

PGENERIC_MAPPING IoGetFileObjectGenericMapping();

void MmFreeContiguousMemorySpecifyCache(
    [in] PVOID BaseAddress,
    [in] SIZE_T NumberOfBytes,
    [in] MEMORY_CACHING_TYPE CacheType
);

NTSTATUS IoCreateFileSpecifyDeviceObjectHint(
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
    [in] ULONG Options,
    [in, optional] PVOID DeviceObject
);

void IoAssignArcName(
    [in] ArcName,
    [in] DeviceName
);

NTPSHEDAPI NTSTATUS PshedRegisterPlugin(
    [in, out] PWHEA_PSHED_PLUGIN_REGISTRATION_PACKET Packet
);

void IoDeassignArcName(
    [in] ArcName
);

NTSTATUS IoWritePartitionTable(
    [in] PDEVICE_OBJECT DeviceObject,
    [in] ULONG SectorSize,
    [in] ULONG SectorsPerTrack,
    [in] ULONG NumberOfHeads,
    [in] _DRIVE_LAYOUT_INFORMATION *PartitionBuffer
);

PIRP IoMakeAssociatedIrp(
    [in] PIRP Irp,
    [in] CCHAR StackSize
);

PWHEA_ERROR_PACKET WheaGetErrPacketFromErrRecord(
    [in] PWHEA_ERROR_RECORD Record
);

HANDLE PsGetCurrentProcessId();

NTSYSAPI NTSTATUS RtlFlushNonVolatileMemoryRanges(
    PVOID NvToken,
    PNV_MEMORY_RANGE NvRanges,
    SIZE_T NumRanges,
    ULONG Flags
);

NTSYSAPI BOOLEAN RtlPrefixUnicodeString(
    [in] PCUNICODE_STRING String1,
    [in] PCUNICODE_STRING String2,
    [in] BOOLEAN CaseInSensitive
);

BOOLEAN WheaIsValidErrorRecordSignature(
    [in] PWHEA_ERROR_RECORD Record
);

NTSYSAPI NTSTATUS ZwTerminateProcess(
    [in, optional] HANDLE ProcessHandle,
    [in] NTSTATUS ExitStatus
);

ULONG PsGetServerSiloActiveConsoleId(
    PESILO Silo
);

PVOID IoRegisterBootDriverCallback(
    [in] PBOOT_DRIVER_CALLBACK_FUNCTION CallbackFunction,
    [in, optional] PVOID CallbackContext
);

void IoInitializeDriverCreateContext(
    PIO_DRIVER_CREATE_CONTEXT DriverContext
);

NTSYSAPI NTSTATUS ZwPowerInformation(
    [in] POWER_INFORMATION_LEVEL InformationLevel,
    [in, optional] PVOID InputBuffer,
    [in] ULONG InputBufferLength,
    [out, optional] PVOID OutputBuffer,
    [in] ULONG OutputBufferLength
);

PCONFIGURATION_INFORMATION IoGetConfigurationInformation();

PESILO PsGetEffectiveServerSilo(
    [in] PESILO Silo
);

void CUSTOM_SYSTEM_EVENT_TRIGGER_INIT(
    PCUSTOM_SYSTEM_EVENT_TRIGGER_CONFIG Config,
    PCWSTR TriggerId
);

PESILO PsGetHostSilo();

void IoRegisterDriverReinitialization(
    [in] PDRIVER_OBJECT DriverObject,
    [in] PDRIVER_REINITIALIZE DriverReinitializationRoutine,
    [in, optional] PVOID Context
);

NTSYSAPI NTSTATUS RtlFillNonVolatileMemory(
    PVOID NvToken,
    VOID *NvDestination,
    SIZE_T Size,
    const UCHAR Value,
    ULONG Flags
);

NTSYSAPI PVOID RtlInsertElementGenericTableAvl(
    [in] PRTL_AVL_TABLE Table,
    [in] PVOID Buffer,
    [in] CLONG BufferSize,
    [out, optional] PBOOLEAN NewElement
);

void RtlRightChild(
    [in] Links
);

void IoClearActivityIdThread(
    [in] LPCGUID OriginalId
);

HANDLE PsGetThreadId(
    [in] PETHREAD Thread
);

ULONG PsGetSiloMonitorContextSlot(
    [in] PSILO_MONITOR Monitor
);

NTSTATUS IoReadPartitionTableEx(
    [in] PDEVICE_OBJECT DeviceObject,
    _DRIVE_LAYOUT_INFORMATION_EX **DriveLayout
);

NTSYSAPI NTSTATUS RtlFlushNonVolatileMemory(
    PVOID NvToken,
    PVOID NvBuffer,
    SIZE_T Size,
    ULONG Flags
);

void IoSetHardErrorOrVerifyDevice(
    [in] PIRP Irp,
    [in] PDEVICE_OBJECT DeviceObject
);

PVOID PsGetCurrentThreadTeb();

NTSTATUS MmUnmapViewInSystemSpace(
    PVOID MappedBase
);

NTSTATUS IoCreateFileEx(
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
    [in] ULONG Options,
    [in, optional] PIO_DRIVER_CREATE_CONTEXT DriverContext
);

void ExRaiseAccessViolation();

NTSTATUS MmCopyMemory(
    [in] PVOID TargetAddress,
    [in] MM_COPY_ADDRESS SourceAddress,
    [in] SIZE_T NumberOfBytes,
    [in] ULONG Flags,
    [out] PSIZE_T NumberOfBytesTransferred
);

NTSYSAPI PVOID RtlLookupElementGenericTableAvl(
    [in] PRTL_AVL_TABLE Table,
    [in] PVOID Buffer
);

USHORT KeQueryNodeMaximumProcessorCount(
    [in] USHORT NodeNumber
);

BOOLEAN IoSetThreadHardErrorMode(
    [in] BOOLEAN EnableHardErrors
);

NTSYSAPI PVOID RtlEnumerateGenericTableAvl(
    [in] PRTL_AVL_TABLE Table,
    [in] BOOLEAN Restart
);

NTSYSAPI NTSTATUS ZwAllocateLocallyUniqueId(
    PLUID Luid
);

NTSYSAPI NTSTATUS ZwOpenProcess(
    [out] PHANDLE ProcessHandle,
    [in] ACCESS_MASK DesiredAccess,
    [in] POBJECT_ATTRIBUTES ObjectAttributes,
    [in, optional] PCLIENT_ID ClientId
);

void IoFreeController(
    [in] PCONTROLLER_OBJECT ControllerObject
);

NTSTATUS PsSetCreateProcessNotifyRoutineEx(
    [in] PCREATE_PROCESS_NOTIFY_ROUTINE_EX NotifyRoutine,
    [in] BOOLEAN Remove
);

NTSTATUS WheaHwErrorReportAbandonDeviceDriver(
    WHEA_ERROR_HANDLE ErrorHandle
);

NTSYSAPI NTSTATUS RtlGetPersistedStateLocation(
    [_In_] PCWSTR SourceID,
    [_In_opt_] PCWSTR CustomValue,
    [_In_opt_] PCWSTR DefaultPath,
    [_In_] STATE_LOCATION_TYPE StateLocationType,
    [_In_] PWCHAR TargetPath,
    [_In_] ULONG BufferLengthIn,
    [_Out_opt_] PULONG BufferLengthOut
);

void PsDereferenceSiloContext(
    [in] PVOID SiloContext
);

IO_PAGING_PRIORITY IoGetPagingIoPriority(
    [in] PIRP Irp
);

NTSTATUS IoIncrementKeepAliveCount(
    [in, out] PFILE_OBJECT FileObject,
    [in, out] PEPROCESS Process
);

BOOLEAN KeAreApcsDisabled();

void RtlIsRoot(
    [in] Links
);

USHORT KeQueryMaximumGroupCount();

NTSYSAPI BOOLEAN RtlDeleteElementGenericTable(
    [in] PRTL_GENERIC_TABLE Table,
    [in] PVOID Buffer
);

NTSYSAPI PVOID RtlGetElementGenericTableAvl(
    [in] PRTL_AVL_TABLE Table,
    [in] ULONG I
);

KAFFINITY KeQueryActiveProcessors();

void KeSetTargetProcessorDpc(
    [in, out] PRKDPC Dpc,
    [in] CCHAR Number
);

NTSYSAPI NTSTATUS RtlWriteNonVolatileMemory(
    PVOID NvToken,
    VOID *NvDestination,
    const VOID *Source,
    SIZE_T Size,
    ULONG Flags
);

NTSTATUS KeQueryHardwareCounterConfiguration(
    [out] PHARDWARE_COUNTER CounterArray,
    [in] ULONG MaximumCount,
    [out] PULONG Count
);

NTSTATUS WheaUnconfigureErrorSource(
    WHEA_ERROR_SOURCE_TYPE SourceType
);

NTSTATUS IoReadDiskSignature(
    [in] PDEVICE_OBJECT DeviceObject,
    [in] ULONG BytesPerSector,
    [out] PDISK_SIGNATURE Signature
);

void KeLeaveCriticalRegion();

LONGLONG PsGetThreadCreateTime(
    [in] PETHREAD Thread
);

void RtlInsertAsLeftChild(
    [in] PRTL_SPLAY_LINKS ParentLinks,
    [in] PRTL_SPLAY_LINKS ChildLinks
);

NTSYSAPI NTSTATUS RtlRunOnceExecuteOnce(
    PRTL_RUN_ONCE RunOnce,
    PRTL_RUN_ONCE_INIT_FN InitFn,
    PVOID Parameter,
    PVOID *Context
);

PIO_FOEXT_SILO_PARAMETERS IoGetSiloParameters(
    [in] PFILE_OBJECT FileObject
);

NTSYSAPI NTSTATUS RtlDrainNonVolatileFlush(
    [in] PVOID NvToken
);

LUID NTAPI_INLINE RtlConvertUlongToLuid(
    [in] ULONG Ulong
);

NTSYSAPI NTSTATUS RtlIncrementCorrelationVector(
    [in, out] PCORRELATION_VECTOR CorrelationVector
);

NTSTATUS PsFreeSiloContextSlot(
    [in] ULONG ContextSlot
);

PTXN_PARAMETER_BLOCK IoGetTransactionParameterBlock(
    [in] PFILE_OBJECT FileObject
);

NTSTATUS PsStartSiloMonitor(
    [in] PSILO_MONITOR Monitor
);

LPCGUID IoSetActivityIdThread(
    LPCGUID ActivityId
);

NTSTATUS IoReadPartitionTable(
    [in] PDEVICE_OBJECT DeviceObject,
    [in] ULONG SectorSize,
    [in] BOOLEAN ReturnRecognizedPartitions,
    [out] _DRIVE_LAYOUT_INFORMATION **PartitionBuffer
);

void RtlParent(
    [in] Links
);

PVOID MmAllocateContiguousNodeMemory(
    [in] SIZE_T NumberOfBytes,
    [in] PHYSICAL_ADDRESS LowestAcceptableAddress,
    [in] PHYSICAL_ADDRESS HighestAcceptableAddress,
    [in, optional] PHYSICAL_ADDRESS BoundaryAddressMultiple,
    [in] ULONG Protect,
    [in] NODE_REQUIREMENT PreferredNode
);

NTSYSAPI PRTL_SPLAY_LINKS RtlDelete(
    [in] PRTL_SPLAY_LINKS Links
);

NTSTATUS PsGetSiloContext(
    [in] PESILO Silo,
    [in] ULONG ContextSlot,
    PVOID *ReturnedSiloContext
);

NTSTATUS PsRemoveSiloContext(
    [in] PESILO Silo,
    [in] ULONG ContextSlot,
    PVOID *RemovedSiloContext
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

PVOID MmAllocateContiguousMemory(
    [in] SIZE_T NumberOfBytes,
    [in] PHYSICAL_ADDRESS HighestAcceptableAddress
);

NTSYSAPI VOID RtlDeleteNoSplay(
    [in] PRTL_SPLAY_LINKS Links,
    [in, out] PRTL_SPLAY_LINKS *Root
);

USHORT KeQueryHighestNodeNumber();

NTSTATUS WheaRegisterErrorSourceOverride(
    [in] WHEA_ERROR_SOURCE_OVERRIDE_SETTINGS OverrideSettings,
    [in] PWHEA_ERROR_SOURCE_CONFIGURATION OverrideConfig,
    [in] WHEA_SIGNAL_HANDLER_OVERRIDE_CALLBACK OverrideCallback
);

NTSYSAPI PVOID RtlEnumerateGenericTableWithoutSplaying(
    [in] PRTL_GENERIC_TABLE Table,
    [in, out] PVOID *RestartKey
);

void IoCancelFileOpen(
    [in] PDEVICE_OBJECT DeviceObject,
    [in] PFILE_OBJECT FileObject
);

NTSTATUS IoSetPartitionInformation(
    [in] PDEVICE_OBJECT DeviceObject,
    [in] ULONG SectorSize,
    [in] ULONG PartitionNumber,
    [in] ULONG PartitionType
);

void RtlIsLeftChild(
    [in] Links
);

HANDLE MmSecureVirtualMemoryEx(
    PVOID Address,
    SIZE_T Size,
    ULONG ProbeMode,
    ULONG Flags
);

void HalExamineMBR(
    [in] PDEVICE_OBJECT DeviceObject,
    [in] ULONG SectorSize,
    [in] ULONG MBRTypeIdentifier,
    [out] PVOID *Buffer
);

ULONGLONG PsGetProcessStartKey(
    [in] PEPROCESS Process
);

LONGLONG PsGetProcessCreateTimeQuadPart(
    [in] PEPROCESS Process
);

NTSTATUS IoReportRootDevice(
    [in] PDRIVER_OBJECT DriverObject
);

NTSTATUS IoSetSystemPartition(
    [in] PUNICODE_STRING VolumeNameString
);

void PsUnregisterSiloMonitor(
    [in] PSILO_MONITOR Monitor
);

NTSYSAPI VOID RtlMapGenericMask(
    [in, out] PACCESS_MASK AccessMask,
    [in] const GENERIC_MAPPING *GenericMapping
);

NTSTATUS KeInitializeCrashDumpHeader(
    [in] ULONG DumpType,
    [in] ULONG Flags,
    [out] PVOID Buffer,
    [in] ULONG BufferSize,
    [out, optional] PULONG BufferNeeded
);

NTSYSAPI BOOLEAN RtlIsGenericTableEmpty(
    [in] PRTL_GENERIC_TABLE Table
);

HANDLE PsGetProcessId(
    [in] PEPROCESS Process
);

NTPSHEDAPI BOOLEAN PshedIsSystemWheaEnabled();

void MmUnsecureVirtualMemory(
    [in] HANDLE SecureHandle
);

BOOLEAN IoRaiseInformationalHardError(
    [in] NTSTATUS ErrorStatus,
    [in, optional] PUNICODE_STRING String,
    [in, optional] PKTHREAD Thread
);

NTPSHEDAPI PVOID PshedAllocateMemory(
    [in] ULONG Size
);

void RtlInitializeSplayLinks(
    [in] PRTL_SPLAY_LINKS Links
);

LONG KePulseEvent(
    [in, out] PRKEVENT Event,
    [in] KPRIORITY Increment,
    [in] BOOLEAN Wait
);

NTSTATUS WheaAddHwErrorReportSectionDeviceDriver(
    WHEA_ERROR_HANDLE ErrorHandle,
    ULONG SectionDataLength,
    PWHEA_DRIVER_BUFFER_SET BufferSet
);

NTSTATUS IoSetFileOrigin(
    [in] PFILE_OBJECT FileObject,
    [in] BOOLEAN Remote
);

NTSTATUS RtlRaiseCustomSystemEventTrigger(
    [_In_] PCUSTOM_SYSTEM_EVENT_TRIGGER_CONFIG TriggerConfig
);

NTHALAPI ULONG HalGetBusDataByOffset(
    [in] BUS_DATA_TYPE BusDataType,
    [in] ULONG BusNumber,
    [in] ULONG SlotNumber,
    [in] PVOID Buffer,
    [in] ULONG Offset,
    [in] ULONG Length
);

BOOLEAN KeInvalidateAllCaches();

PVOID WheaErrorRecordBuilderAddSection(
    [in, out] PWHEA_ERROR_RECORD Record,
    [in] UINT32 MaxSectionCount,
    [in] UINT32 SectionLength,
    [in] WHEA_ERROR_RECORD_SECTION_DESCRIPTOR_FLAGS Flags,
    [in] GUID SectionType,
    [in, out, optional] PVOID DescriptorOut
);

NTSYSAPI PVOID RtlInsertElementGenericTableFullAvl(
    [in] PRTL_AVL_TABLE Table,
    [in] PVOID Buffer,
    [in] CLONG BufferSize,
    [out, optional] PBOOLEAN NewElement,
    [in] PVOID NodeOrParent,
    [in] TABLE_SEARCH_RESULT SearchResult
);

void WheaRemoveErrorSource(
    ULONG ErrorSourceId
);

void KeLeaveGuardedRegion();

BOOLEAN MmIsThisAnNtAsSystem();

void RtlIsRightChild(
    [in] Links
);

NTSYSAPI ULONG RtlNumberGenericTableElements(
    [in] PRTL_GENERIC_TABLE Table
);

NTPSHEDAPI VOID PshedUnregisterPlugin(
    PVOID PluginHandle
);

NTHALAPI NTSTATUS HalAllocateHardwareCounters(
    PGROUP_AFFINITY GroupAffinty,
    [in] ULONG GroupCount,
    [in] PPHYSICAL_COUNTER_RESOURCE_LIST ResourceList,
    [out] PHANDLE CounterSetHandle
);

NTSYSAPI NTSTATUS RtlVolumeDeviceToDosName(
    [in] PVOID VolumeDeviceObject,
    [out] PUNICODE_STRING DosName
);

GUID * PsGetSiloContainerId(
    [in] PESILO Silo
);

PPHYSICAL_MEMORY_RANGE MmGetPhysicalMemoryRangesEx2(
    PVOID PartitionObject,
    ULONG Flags
);

BOOLEAN PsIsHostSilo(
    [in] PESILO Silo
);

LOGICAL IoIsValidIrpStatus(
    [in] IN NTSTATUS Status
);

NTSTATUS
    KeExpandKernelStackAndCallout (
    _In_ PEXPAND_STACK_CALLOUT Callout,
    _In_opt_ PVOID Parameter,
    _In_ SIZE_T Size
);

POPLOCK_KEY_CONTEXT IoGetOplockKeyContextEx(
    PFILE_OBJECT FileObject
);

NTSTATUS IoAttachDeviceToDeviceStackSafe(
    [in] PDEVICE_OBJECT SourceDevice,
    [in] PDEVICE_OBJECT TargetDevice,
    [out] PDEVICE_OBJECT *AttachedToDeviceObject
);

NTPSHEDAPI VOID PshedFreeMemory(
    [in] PVOID Address
);

NTSYSAPI NTSTATUS ZwSetInformationThread(
    [in] HANDLE ThreadHandle,
    [in] THREADINFOCLASS ThreadInformationClass,
    [in] PVOID ThreadInformation,
    [in] ULONG ThreadInformationLength
);

PVOID MmAllocateContiguousMemorySpecifyCacheNode(
    [in] SIZE_T NumberOfBytes,
    [in] PHYSICAL_ADDRESS LowestAcceptableAddress,
    [in] PHYSICAL_ADDRESS HighestAcceptableAddress,
    [in, optional] PHYSICAL_ADDRESS BoundaryAddressMultiple,
    [in] MEMORY_CACHING_TYPE CacheType,
    [in] NODE_REQUIREMENT PreferredNode
);

NTSTATUS IoQueryFullDriverPath(
    [in] PDRIVER_OBJECT DriverObject,
    [out] PUNICODE_STRING FullPath
);

NTSYSAPI ULONG64 RtlGetEnabledExtendedFeatures(
    [in] ULONG64 FeatureMask
);

PETHREAD PsGetCurrentThread();

NTSTATUS MmAddPhysicalMemory(
    [in] PPHYSICAL_ADDRESS StartAddress,
    [in] PLARGE_INTEGER NumberOfBytes
);

NTSTATUS PsGetPermanentSiloContext(
    [in] PESILO Silo,
    [in] ULONG ContextSlot,
    PVOID *ReturnedSiloContext
);

PESILO PsGetThreadServerSilo(
    [In] PETHREAD Thread
);

NTSYSAPI NTSTATUS RtlValidateCorrelationVector(
    PCORRELATION_VECTOR Vector
);

void ExFreePool(
    a
);

KAFFINITY KeQueryGroupAffinity(
    [in] USHORT GroupNumber
);

void KeInvalidateRangeAllCaches(
    PVOID BaseAddress,
    ULONG Length
);

NTSTATUS PsGetJobSilo(
    [in] PEJOB Job,
    [out] PESILO *Silo
);

NTSYSAPI BOOLEAN RtlEqualString(
    [in] const STRING *String1,
    [in] const STRING *String2,
    [in] BOOLEAN CaseInSensitive
);

void IoDeleteController(
    [in] PCONTROLLER_OBJECT ControllerObject
);

NTSYSAPI PVOID RtlLookupElementGenericTable(
    PRTL_GENERIC_TABLE Table,
    PVOID Buffer
);

void PsDetachSiloFromCurrentThread(
    [in] PESILO PreviousSilo
);

NTSTATUS WheaReportHwErrorDeviceDriver(
    ULONG ErrorSourceId,
    PDEVICE_OBJECT DeviceObject,
    PUCHAR ErrorData,
    ULONG ErrorDataLength,
    LPGUID SectionTypeGuid,
    WHEA_ERROR_SEVERITY ErrorSeverity,
    LPSTR DeviceFriendlyName
);

NTSTATUS IoGetActivityIdIrp(
    [in] PIRP Irp,
    [out] LPGUID Guid
);

NTSTATUS WheaInitializeRecordHeader(
    PWHEA_ERROR_RECORD_HEADER Header
);

NTSTATUS WheaConfigureErrorSource(
    WHEA_ERROR_SOURCE_TYPE SourceType,
    PWHEA_ERROR_SOURCE_CONFIGURATION Configuration
);

void IoTransferActivityId(
    [in] LPCGUID ActivityId,
    [in] LPCGUID RelatedActivityId
);

NTSTATUS PsReplaceSiloContext(
    [in] PESILO Silo,
    [in] ULONG ContextSlot,
    [in] PVOID NewSiloContext,
    [optional] PVOID *OldSiloContext
);

void MmLockPagableSectionByHandle(
    [in] PVOID ImageSectionHandle
);

NTSYSAPI PVOID RtlEnumerateGenericTable(
    [in] PRTL_GENERIC_TABLE Table,
    [in] BOOLEAN Restart
);

BOOLEAN IoIsFileOriginRemote(
    [in] PFILE_OBJECT FileObject
);

USHORT KeGetCurrentNodeNumber();

NTSTATUS WheaHwErrorReportSetSeverityDeviceDriver(
    WHEA_ERROR_HANDLE ErrorHandle,
    WHEA_ERROR_SEVERITY ErrorSeverity
);

NTSTATUS PsSetLoadImageNotifyRoutine(
    [in] PLOAD_IMAGE_NOTIFY_ROUTINE NotifyRoutine
);

NTSYSAPI PVOID RtlGetElementGenericTable(
    [in] PRTL_GENERIC_TABLE Table,
    [in] ULONG I
);

NTSTATUS IoWritePartitionTableEx(
    [in] PDEVICE_OBJECT DeviceObject,
    _DRIVE_LAYOUT_INFORMATION_EX *DriveLayout
);

NTSYSAPI BOOLEAN RtlIsStateSeparationEnabled();

void RtlInsertAsRightChild(
    [in] PRTL_SPLAY_LINKS ParentLinks,
    [in] PRTL_SPLAY_LINKS ChildLinks
);

NTSTATUS IoSetShadowFileInformation(
    [in] PFILE_OBJECT FileObject,
    [in] PFILE_OBJECT BackingFileObject,
    [in] PVOID BackingFltInstance
);

NTSTATUS IoReportResourceForDetection(
    [in] PDRIVER_OBJECT DriverObject,
    [in, optional] PCM_RESOURCE_LIST DriverList,
    [in, optional] ULONG DriverListSize,
    [in, optional] PDEVICE_OBJECT DeviceObject,
    [in, optional] PCM_RESOURCE_LIST DeviceList,
    [in, optional] ULONG DeviceListSize,
    [out] PBOOLEAN ConflictDetected
);

NTSYSAPI NTSTATUS RtlRunOnceBeginInitialize(
    [in, out] PRTL_RUN_ONCE RunOnce,
    [in] ULONG Flags,
    [out] PVOID *Context
);

void MmFreeContiguousMemory(
    [in] PVOID BaseAddress
);

NTSYSAPI NTSTATUS RtlExtendCorrelationVector(
    [in, out] PCORRELATION_VECTOR CorrelationVector
);

NTSYSAPI PRTL_SPLAY_LINKS RtlSubtreeSuccessor(
    [in] PRTL_SPLAY_LINKS Links
);

void IoSetMasterIrpStatus(
    [in, out] PIRP MasterIrp,
    [in] NTSTATUS Status
);

PESILO PsGetCurrentServerSilo();

void PsTerminateServerSilo(
    [in] PESILO ServerSilo,
    NTSTATUS ExitStatus
);

NTSYSAPI BOOLEAN RtlIsZeroMemory(
    PVOID Buffer,
    SIZE_T Length
);

NTSYSAPI ULONG DbgPrompt(
    [in] PCCH Prompt,
    [out] PCH Response,
    ULONG Length
);

void KeSetImportanceDpc(
    [in, out] PRKDPC Dpc,
    [in] KDPC_IMPORTANCE Importance
);

void IoUnregisterBootDriverCallback(
    [in] PVOID CallbackHandle
);

NTSTATUS PsSetCreateThreadNotifyRoutineEx(
    [in] PSCREATETHREADNOTIFYTYPE NotifyType,
    [in] PVOID NotifyInformation
);

void IoRaiseHardError(
    [in] PIRP Irp,
    [in, optional] PVPB Vpb,
    [in] PDEVICE_OBJECT RealDeviceObject
);

NTSYSAPI VOID RtlInitializeGenericTableAvl(
    [out] PRTL_AVL_TABLE Table,
    [in] PRTL_AVL_COMPARE_ROUTINE CompareRoutine,
    [in] PRTL_AVL_ALLOCATE_ROUTINE AllocateRoutine,
    [in] PRTL_AVL_FREE_ROUTINE FreeRoutine,
    [in, optional] PVOID TableContext
);

POPLOCK_KEY_ECP_CONTEXT IoGetOplockKeyContext(
    PFILE_OBJECT FileObject
);

BOOLEAN WheaSignalHandlerOverride(
    [in] WHEA_ERROR_SOURCE_TYPE SourceType,
    [in, out, optional] UINT_PTR Context
);

NTSYSAPI PVOID RtlLookupFirstMatchingElementGenericTableAvl(
    [in] PRTL_AVL_TABLE Table,
    [in] PVOID Buffer,
    [out] PVOID *RestartKey
);

