BOOLEAN StorPortEnablePassiveInitialization(
    [in] PVOID DeviceExtension,
    [in] PHW_PASSIVE_INITIALIZE_ROUTINE HwPassiveInitializeRoutine
);

ULONG StorPortPutScatterGatherList(
    [in] PVOID HwDeviceExtension,
    [in] PSTOR_SCATTER_GATHER_LIST ScatterGatherList,
    [in] BOOLEAN WriteToDevice
);

void ScsiPortReadPortBufferUlong(
    [in] Port,
    [in] Buffer,
    [in] Count
);

ULONG StorPortSetAdapterBusType(
    [in] PVOID HwDeviceExtension,
    [in] ULONG BusType
);

ULONG StorPortRegisterDriverProxy(
    PVOID HwDeviceExtension,
    PVOID DriverObject,
    PSTOR_DRIVER_PROXY_EXTENSION *ProxyExtension
);

ULONG StorPortStorMQAddController(
    PVOID HwAdapterExtension,
    ULONG NumberOfBytes,
    PVOID *ControllerExtension
);

void ScsiPortWritePortBufferUlong(
    [in] Port,
    [in] Buffer,
    [in] Count
);

ULONG StorPortGetOriginalMdl(
    [in] PVOID HwDeviceExtension,
    [in] PSCSI_REQUEST_BLOCK Srb,
    [out] PVOID *Mdl
);

STORPORT_API BOOLEAN StorPortReadDriverRegistry(
    PVOID DriverObject,
    PUCHAR ValueName,
    PULONG ValueDataLength,
    PVOID ValueData
);

ULONG StorPortGetCurrentIrql(
    [in] PVOID HwDeviceExtension,
    [out] PKIRQL Irql
);

ULONG StorPortAllocateMdl(
    [in] PVOID HwDeviceExtension,
    [in] PVOID BufferPointer,
    [in] ULONG NumberOfBytes,
    [out] PVOID *Mdl
);

ULONG StorPortGetNodeAffinity2(
    PVOID HwDeviceExtension,
    ULONG NodeNumber,
    PGROUP_AFFINITY GroupAffinities,
    USHORT GroupAffinitiesCount,
    PUSHORT GroupAffinitiesCountRequired
);

void ScsiPortWriteRegisterUshort(
    [in] Register,
    [in] Value
);

ULONG StorPortGetGroupAffinity(
    [in] PVOID HwDeviceExtension,
    [in] USHORT GroupNumber,
    [out] PKAFFINITY GroupAffinityMask
);

void ScsiPortWriteRegisterBufferUlong(
    [in] Register,
    [in] Buffer,
    [in] Count
);

ULONG StorPortSetFeatureList(
    PVOID HwDeviceExtension,
    ULONG FeatureCount,
    PBOOLEAN FeatureList
);

void StorPortReadPortUlong(
    [in] h,
    [in] p
);

STORPORT_API VOID StorPortLogError(
    [in] PVOID HwDeviceExtension,
    [in, optional] PSCSI_REQUEST_BLOCK Srb,
    [in] UCHAR PathId,
    [in] UCHAR TargetId,
    [in] UCHAR Lun,
    [in] ULONG ErrorCode,
    [in] ULONG UniqueId
);

void StorPortInitializeDpc(
    [in] PVOID DeviceExtension,
    [out] PSTOR_DPC Dpc,
    [in] PHW_DPC_ROUTINE HwDpcRoutine
);

STORPORT_API BOOLEAN StorPortPause(
    [in] PVOID HwDeviceExtension,
    ULONG Timeout
);

ULONG StorPortGetMessageInterruptIDFromProcessorIndex(
    PVOID HwDeviceExtension,
    ULONG ProcessorIndex,
    PULONG MessageInterruptID
);

ULONG StorPortUpdatePortConfigMaxIOInfo(
    PVOID HwDeviceExtension,
    ULONG MaxIoCount,
    ULONG MaxIosPerLun
);

void StorPortReadRegisterBufferUchar(
    [in] h,
    [in] r,
    [in] b,
    [in] c
);

void StorPortWriteRegisterBufferUlong64(
    h,
    r,
    b,
    c
);

ULONG StorPortInitializeEvent(
    PVOID HwDeviceExtension,
    PSTOR_EVENT Event,
    STOR_EVENT_TYPE Type,
    BOOLEAN State
);

STORPORT_API VOID StorPortMoveMemory(
    [in] PVOID WriteBuffer,
    [in] PVOID ReadBuffer,
    [in] ULONG Length
);

ULONG StorPortSetSystemGroupAffinityThread(
    [in] PVOID HwDeviceExtension,
    [in/optional] PVOID ThreadContext,
    [in] PSTOR_GROUP_AFFINITY Affinity,
    [out/optional] PSTOR_GROUP_AFFINITY PreviousAffinity
);

ULONG StorPortEtwLogError(
    [in] PVOID HwDeviceExtension,
    [in, optional] PSTOR_ADDRESS Address,
    [in] ULONG Id,
    [in] PWSTR Description,
    [in] ULONG DataBufferLength,
    [in] PVOID DataBuffer
);

void StorPortReadRegisterUlong64(
    [in] h,
    [in] r
);

STORPORT_API PVOID StorPortGetLogicalUnit(
    [in] PVOID HwDeviceExtension,
    [in] UCHAR PathId,
    [in] UCHAR TargetId,
    [in] UCHAR Lun
);

ULONG StorPortInterlockedInsertTailList(
    [in] PVOID HwDeviceExtension,
    [in, out] PSTOR_LIST_ENTRY ListHead,
    [in, out] PSTOR_LIST_ENTRY ListEntry,
    [in, out] PSTOR_LIST_ENTRY *Result,
    [in, out] PSTOR_KSPIN_LOCK Lock
);

ULONG StorPortPoFxSetComponentLatency(
    [in] PVOID HwDeviceExtension,
    [in, optional] PSTOR_ADDRESS Address,
    [in] ULONG Component,
    [in] ULONGLONG Latency
);

BOOLEAN StorPortRegistryRead(
    PVOID HwDeviceExtension,
    PUCHAR ValueName,
    ULONG Global,
    ULONG Type,
    PUCHAR Buffer,
    PULONG BufferLength
);

ULONG StorPortCaptureLiveDump(
    [in] PVOID HwDeviceExtension,
    [in/optional] PSTOR_ADDRESS StorAddress,
    [in] PSTORPORT_CAPTURE_LIVEDUMP CaptureLivedump
);

ULONG StorPortInitializeSpinlock(
    [in] PVOID HwDeviceExtension,
    [out] PSTOR_KSPIN_LOCK Lock
);

ULONG StorPortGetLogicalProcessorRelationship(
    [in] PVOID HwDeviceExtension,
    [in, optional] PPROCESSOR_NUMBER ProcessorNumber,
    [in] LOGICAL_PROCESSOR_RELATIONSHIP RelationshipType,
    [out] PSYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX Information,
    [in, out] PULONG Length
);

ULONG StorPortQueryDepthSList(
    [in] PVOID HwDeviceExtension,
    [in, out] PSTOR_SLIST_HEADER SListHead,
    [out] PSHORT Result
);

void StorPortReadRegisterUshort(
    [in] h,
    [in] r
);

void StorPortWritePortUshort(
    h,
    p,
    v
);

ULONG StorPortFreeHostMemoryBuffer(
    [in] PVOID HwDeviceExtension,
    PACCESS_RANGE PhysicalAddressRanges,
    [in] ULONG PhysicalAddressRangeCount
);

ULONG StorPortInitializeCryptoEngine(
    PVOID HwDeviceExtension,
    PSTOR_CRYPTO_CAPABILITIES_DATA CryptoCapabilitiesData
);

ULONG StorPortQueueWorkItemToNode(
    PVOID HwDeviceExtension,
    PHW_WORKITEM WorkItemCallback,
    PVOID Worker,
    PVOID Context,
    ULONG Node
);

ULONG StorPortAllocatePool(
    [in] PVOID HwDeviceExtension,
    [in] ULONG NumberOfBytes,
    [in] ULONG Tag,
    [out] PVOID *BufferPointer
);

void StorPortReadPortUchar(
    [in] h,
    [in] p
);

STORPORT_API BOOLEAN StorPortBusy(
    [in] PVOID HwDeviceExtension,
    [in] ULONG RequestsToComplete
);

void ScsiPortReadRegisterUchar(
    [in] Register
);

STORPORT_API VOID StorPortFreeRegistryBuffer(
    [in] PVOID HwDeviceExtension,
    [in] PUCHAR Buffer
);

void StorPortWritePortBufferUchar(
    h,
    p,
    b,
    c
);

void StorPortReadPortUshort(
    [in] h,
    [in] p
);

ULONG StorPortGetMSIInfo(
    [in] PVOID HwDeviceExtension,
    [in] ULONG MessageId,
    [out] PMESSAGE_INTERRUPT_INFORMATION InterruptInfo
);

ULONG StorPortRequestTimer(
    [in] PVOID HwDeviceExtension,
    [in] PVOID TimerHandle,
    [in] PHW_TIMER_EX TimerCallback,
    [in, optional] PVOID CallbackContext,
    [in] ULONGLONG TimerValue,
    [in] ULONGLONG TolerableDelay
);

void StorPortMarkDeviceFailed(
    PVOID HwDeviceExtension,
    PSTOR_ADDRESS StorAddress,
    ULONG Flags,
    PWSTR FailReason
);

void StorPortWriteRegisterUlong(
    h,
    r,
    v
);

ULONG StorPortGetCurrentProcessorNumber(
    [in] PVOID HwDeviceExtension,
    [out] PPROCESSOR_NUMBER ProcNumber
);

void StorPortReadRegisterBufferUshort(
    [in] h,
    [in] r,
    [in] b,
    [in] c
);

ULONG StorPortEtwChannelEvent2(
    PVOID HwDeviceExtension,
    PSTOR_ADDRESS Address,
    STORPORT_ETW_EVENT_CHANNEL EventChannel,
    ULONG EventId,
    PWSTR EventDescription,
    ULONGLONG EventKeywords,
    STORPORT_ETW_LEVEL EventLevel,
    STORPORT_ETW_EVENT_OPCODE EventOpcode,
    PSCSI_REQUEST_BLOCK Srb,
    _In_reads_or_z_opt_(STORPORT_ETW_MAX_PARAM_NAME_LENGTH)PWSTR Parameter1Name,
    ULONGLONG Parameter1Value,
    _In_reads_or_z_opt_(STORPORT_ETW_MAX_PARAM_NAME_LENGTH)PWSTR Parameter2Name,
    ULONGLONG Parameter2Value
);

void StorPortWriteRegisterUchar(
    h,
    r,
    v
);

ULONG StorPortGetProcessorCount(
    PVOID HwDeviceExtension,
    PULONG ProcessorCount
);

ULONG StorPortQueryPerformanceCounter(
    [in] PVOID HwDeviceExtension,
    [out, optional] PLARGE_INTEGER PerformanceFrequency,
    [out] PLARGE_INTEGER PerformanceCounter
);

STORPORT_API BOOLEAN StorPortSetDeviceQueueDepth(
    [in] PVOID HwDeviceExtension,
    [in] UCHAR PathId,
    [in] UCHAR TargetId,
    [in] UCHAR Lun,
    [in] ULONG Depth
);

void StorPortReadPortBufferUlong(
    [in] h,
    [in] p,
    [in] b,
    [in] c
);

void StorPortReadRegisterUchar(
    [in] h,
    [in] r
);

ULONG StorPortSetPriorityThread(
    [in] PVOID HwDeviceExtension,
    [in] PVOID ThreadContext,
    [in] STOR_THREAD_PRIORITY Priority
);

void StorPortWriteRegisterBufferUchar(
    h,
    r,
    b,
    c
);

STORPORT_API BOOLEAN StorPortRegistryWrite(
    [in] PVOID HwDeviceExtension,
    [in] PUCHAR ValueName,
    [in] ULONG Global,
    [in] ULONG Type,
    [in] PUCHAR Buffer,
    [in] ULONG BufferLength
);

void StorPortWriteRegisterUlong64(
    h,
    r,
    v
);

void StorPortAcquireSpinLock(
    [in] PVOID DeviceExtension,
    [in] STOR_SPINLOCK SpinLock,
    [in] PVOID LockContext,
    [in/out] PSTOR_LOCK_HANDLE LockHandle
);

ULONG StorPortGetDataInBufferScatterGatherList(
    [in] PVOID HwDeviceExtension,
    [in] PSCSI_REQUEST_BLOCK Srb,
    [out] PSTOR_SCATTER_GATHER_LIST *SgList
);

STORPORT_API PUCHAR StorPortAllocateRegistryBuffer(
    [in] PVOID HwDeviceExtension,
    [in] PULONG Length
);

STORPORT_API STOR_PHYSICAL_ADDRESS StorPortConvertUlongToPhysicalAddress(
    [in] ULONG_PTR UlongAddress
);

ULONG StorPortFreeContiguousMemorySpecifyCache(
    [in] PVOID HwDeviceExtension,
    [in] PVOID BaseAddress,
    [in] SIZE_T NumberOfBytes,
    [in] MEMORY_CACHING_TYPE CacheType
);

ULONG StorPortFreeDmaMemory(
    [in] PVOID HwDeviceExtension,
    [in] PVOID BaseAddress,
    [in] SIZE_T NumberOfBytes,
    [in] MEMORY_CACHING_TYPE CacheType,
    [in_opt] PHYSICAL_ADDRESS PhysicalAddress
);

ULONG StorPortBuildScatterGatherList(
    [in] PVOID HwDeviceExtension,
    [in] PVOID Mdl,
    [in] PVOID CurrentVa,
    [in] ULONG Length,
    [in] PPOST_SCATTER_GATHER_EXECUTE ExecutionRoutine,
    [in] PVOID Context,
    [in] BOOLEAN WriteToDevice,
    [in, out] PVOID ScatterGatherBuffer,
    [in] ULONG ScatterGatherBufferLength
);

ULONG StorPortLogTelemetry(
    [in] PVOID HwDeviceExtension,
    [in, optional] PSTOR_ADDRESS StorAddress,
    [in] PSTORPORT_TELEMETRY_EVENT Event
);

STORPORT_API VOID StorPortFreeDeviceBase(
    [in] PVOID HwDeviceExtension,
    [in] PVOID MappedAddress
);

STORPORT_API ULONG StorPortInitialize(
    [in] PVOID Argument1,
    [in] PVOID Argument2,
    [in] _HW_INITIALIZATION_DATA *HwInitializationData,
    [in, optional] PVOID HwContext
);

ULONG StorPortNvmeIceIoStart(
    PVOID HwDeviceExtension,
    PSCSI_REQUEST_BLOCK Srb,
    ULONG LbaCount,
    ULONG PrpCount,
    PULONGLONG Prp1,
    PULONGLONG Prp2,
    PULONGLONG PrpList
);

void StorPortWritePortUchar(
    h,
    p,
    v
);

ULONG StorPortInterlockedFlushSList(
    [in] PVOID HwDeviceExtension,
    [in, out] PSTOR_SLIST_HEADER SListHead,
    [out] PSTOR_SLIST_ENTRY *Result
);

void ScsiPortReadRegisterUlong(
    [in] Register
);

ULONG StorPortInterlockedRemoveHeadList(
    [in] PVOID HwDeviceExtension,
    [in, out] PSTOR_LIST_ENTRY ListHead,
    [in, out] PSTOR_LIST_ENTRY *Result,
    [in, out] PSTOR_KSPIN_LOCK Lock
);

ULONG StorPortSetPowerSettingNotificationGuids(
    [in] PVOID HwDeviceExtension,
    [in] ULONG GuidCount,
    [in] LPGUID Guid
);

ULONG StorPortEtwEvent8(
    [in] PVOID HwDeviceExtension,
    [in/optional] PSTOR_ADDRESS Address,
    [in] ULONG EventId,
    [in] PWSTR EventDescription,
    [in] ULONGLONG EventKeywords,
    [in] STORPORT_ETW_LEVEL EventLevel,
    [in] STORPORT_ETW_EVENT_OPCODE EventOpcode,
    [in/optional] PSCSI_REQUEST_BLOCK Srb,
    [in/optional] _In_reads_or_z_opt_(STORPORT_ETW_MAX_PARAM_NAME_LENGTH)PWSTR Parameter1Name,
    [in] ULONGLONG Parameter1Value,
    [in/optional] _In_reads_or_z_opt_(STORPORT_ETW_MAX_PARAM_NAME_LENGTH)PWSTR Parameter2Name,
    [in] ULONGLONG Parameter2Value,
    [in/optional] _In_reads_or_z_opt_(STORPORT_ETW_MAX_PARAM_NAME_LENGTH)PWSTR Parameter3Name,
    [in] ULONGLONG Parameter3Value,
    [in/optional] _In_reads_or_z_opt_(STORPORT_ETW_MAX_PARAM_NAME_LENGTH)PWSTR Parameter4Name,
    [in] ULONGLONG Parameter4Value,
    [in/optional] _In_reads_or_z_opt_(STORPORT_ETW_MAX_PARAM_NAME_LENGTH)PWSTR Parameter5Name,
    [in] ULONGLONG Parameter5Value,
    [in/optional] _In_reads_or_z_opt_(STORPORT_ETW_MAX_PARAM_NAME_LENGTH)PWSTR Parameter6Name,
    [in] ULONGLONG Parameter6Value,
    [in/optional] _In_reads_or_z_opt_(STORPORT_ETW_MAX_PARAM_NAME_LENGTH)PWSTR Parameter7Name,
    [in] ULONGLONG Parameter7Value,
    [in/optional] _In_reads_or_z_opt_(STORPORT_ETW_MAX_PARAM_NAME_LENGTH)PWSTR Parameter8Name,
    [in] ULONGLONG Parameter8Value
);

ULONG StorPortInitializeWorker(
    [in] PVOID HwDeviceExtension,
    [out] PVOID *Worker
);

ULONG StorPortGetActiveNodeCount(
    [in] PVOID HwDeviceExtension,
    [out] PULONG NumberNodes
);

ULONG StorPortLogSystemEvent(
    [in] PVOID HwDeviceExtension,
    [in, out] PSTOR_LOG_EVENT_DETAILS LogDetails,
    [in, out] PULONG MaximumSize
);

ULONG StorPortRegisterDriverProxyEndpoints(
    PVOID HwDeviceExtension,
    PSTOR_DRIVER_PROXY_EXTENSION ProxyExtension,
    PSTOR_DRIVER_PROXY_ENDPOINT_INFORMATION EndpointInfo,
    ULONG Count
);

ULONG StorPortEtwChannelEvent8(
    PVOID HwDeviceExtension,
    PSTOR_ADDRESS Address,
    STORPORT_ETW_EVENT_CHANNEL EventChannel,
    ULONG EventId,
    PWSTR EventDescription,
    ULONGLONG EventKeywords,
    STORPORT_ETW_LEVEL EventLevel,
    STORPORT_ETW_EVENT_OPCODE EventOpcode,
    PSCSI_REQUEST_BLOCK Srb,
    _In_reads_or_z_opt_(STORPORT_ETW_MAX_PARAM_NAME_LENGTH)PWSTR Parameter1Name,
    ULONGLONG Parameter1Value,
    _In_reads_or_z_opt_(STORPORT_ETW_MAX_PARAM_NAME_LENGTH)PWSTR Parameter2Name,
    ULONGLONG Parameter2Value,
    _In_reads_or_z_opt_(STORPORT_ETW_MAX_PARAM_NAME_LENGTH)PWSTR Parameter3Name,
    ULONGLONG Parameter3Value,
    _In_reads_or_z_opt_(STORPORT_ETW_MAX_PARAM_NAME_LENGTH)PWSTR Parameter4Name,
    ULONGLONG Parameter4Value,
    _In_reads_or_z_opt_(STORPORT_ETW_MAX_PARAM_NAME_LENGTH)PWSTR Parameter5Name,
    ULONGLONG Parameter5Value,
    _In_reads_or_z_opt_(STORPORT_ETW_MAX_PARAM_NAME_LENGTH)PWSTR Parameter6Name,
    ULONGLONG Parameter6Value,
    _In_reads_or_z_opt_(STORPORT_ETW_MAX_PARAM_NAME_LENGTH)PWSTR Parameter7Name,
    ULONGLONG Parameter7Value,
    _In_reads_or_z_opt_(STORPORT_ETW_MAX_PARAM_NAME_LENGTH)PWSTR Parameter8Name,
    ULONGLONG Parameter8Value
);

ULONG StorPortPoFxSetComponentResidency(
    [in] PVOID HwDeviceExtension,
    [in, optional] PSTOR_ADDRESS Address,
    [in] ULONG Component,
    [in] ULONGLONG Residency
);

STORPORT_API BOOLEAN StorPortResumeDevice(
    [in] PVOID HwDeviceExtension,
    [in] UCHAR PathId,
    [in] UCHAR TargetId,
    [in] UCHAR Lun
);

ULONG StorPortStateChangeDetected(
    [in] PVOID HwDeviceExtension,
    [in] ULONG ChangedEntity,
    [in] PSTOR_ADDRESS Address,
    [in] ULONG Attributes,
    [in, optional] PHW_STATE_CHANGE HwStateChange,
    [in, optional] PVOID HwStateChangeContext
);

void StorPortTerminateSystemThread(
    [in] PVOID HwDeviceExtension,
    [in/optional] PVOID ThreadContext
);

void StorPortWriteRegisterBufferUlong(
    h,
    r,
    b,
    c
);

void StorPortWriteRegisterUshort(
    h,
    r,
    v
);

void ScsiPortReadRegisterBufferUlong(
    [in] Register,
    [in] Buffer,
    [in] Count
);

ULONG StorPortAcquireMSISpinLock(
    [in] PVOID HwDeviceExtension,
    ULONG MessageId,
    [in] PULONG OldIrql
);

ULONG StorPortGetHighestNodeNumber(
    [in] PVOID HwDeviceExtension,
    [out] PULONG HighestNode
);

ULONG StorPortNvmeMiniportEvent(
    PVOID HwDeviceExtension,
    PVOID ControllerHandle,
    ULONG NamespaceId,
    STORPORT_ETW_EVENT_CHANNEL EventChannel,
    ULONG EventId,
    PWSTR EventDescription,
    ULONGLONG EventKeywords,
    STORPORT_ETW_LEVEL EventLevel,
    STORPORT_ETW_EVENT_OPCODE EventOpcode,
    _In_reads_or_z_opt_(STORPORT_ETW_MAX_PARAM_NAME_LENGTH)PWSTR Parameter1Name,
    ULONGLONG Parameter1Value,
    _In_reads_or_z_opt_(STORPORT_ETW_MAX_PARAM_NAME_LENGTH)PWSTR Parameter2Name,
    ULONGLONG Parameter2Value,
    _In_reads_or_z_opt_(STORPORT_ETW_MAX_PARAM_NAME_LENGTH)PWSTR Parameter3Name,
    ULONGLONG Parameter3Value,
    _In_reads_or_z_opt_(STORPORT_ETW_MAX_PARAM_NAME_LENGTH)PWSTR Parameter4Name,
    ULONGLONG Parameter4Value,
    _In_reads_or_z_opt_(STORPORT_ETW_MAX_PARAM_NAME_LENGTH)PWSTR Parameter5Name,
    ULONGLONG Parameter5Value,
    _In_reads_or_z_opt_(STORPORT_ETW_MAX_PARAM_NAME_LENGTH)PWSTR Parameter6Name,
    ULONGLONG Parameter6Value,
    _In_reads_or_z_opt_(STORPORT_ETW_MAX_PARAM_NAME_LENGTH)PWSTR Parameter7Name,
    ULONGLONG Parameter7Value,
    _In_reads_or_z_opt_(STORPORT_ETW_MAX_PARAM_NAME_LENGTH)PWSTR Parameter8Name,
    ULONGLONG Parameter8Value
);

STORPORT_API PVOID StorPortGetDeviceBase(
    [in] PVOID HwDeviceExtension,
    [in] INTERFACE_TYPE BusType,
    [in] ULONG SystemIoBusNumber,
    [in] STOR_PHYSICAL_ADDRESS IoAddress,
    [in] ULONG NumberOfBytes,
    [in] BOOLEAN InIoSpace
);

STORPORT_API STOR_PHYSICAL_ADDRESS StorPortGetPhysicalAddress(
    [in] PVOID HwDeviceExtension,
    [in, optional] PSCSI_REQUEST_BLOCK Srb,
    [in] PVOID VirtualAddress,
    [out] ULONG *Length
);

ULONG StorPortQueryConfiguration(
    PVOID HwDeviceExtension,
    STORPORT_QUERY_CONFIGURATION_TYPE Type,
    PBOOLEAN Enabled
);

STORPORT_API VOID StorPortDebugPrint(
    ULONG DebugPrintLevel,
    PSTR DebugMessage,
    ...
);

ULONG StorPortFreeTimer(
    [in] PVOID HwDeviceExtension,
    [in] PVOID TimerHandle
);

STORPORT_API BOOLEAN StorPortValidateRange(
    [in] PVOID HwDeviceExtension,
    [in] INTERFACE_TYPE BusType,
    ULONG SystemIoBusNumber,
    [in] STOR_PHYSICAL_ADDRESS IoAddress,
    [in] ULONG NumberOfBytes,
    [in] BOOLEAN InIoSpace
);

STORPORT_API BOOLEAN StorPortDeviceBusy(
    [in] PVOID HwDeviceExtension,
    [in] UCHAR PathId,
    [in] UCHAR TargetId,
    [in] UCHAR Lun,
    [in] ULONG RequestsToComplete
);

ULONG StorPortUpdateAdapterMaxIO(
    PVOID HwDeviceExtension,
    ULONG MaxIoCount
);

ULONG StorPortAsyncNotificationDetected(
    [in] PVOID HwDeviceExtension,
    PSTOR_ADDRESS Address,
    ULONGLONG Flags
);

STORPORT_API ULONG StorPortSetBusDataByOffset(
    [in] PVOID DeviceExtension,
    [in] ULONG BusDataType,
    [in] ULONG SystemIoBusNumber,
    [in] ULONG SlotNumber,
    [in] PVOID Buffer,
    [in] ULONG Offset,
    [in] ULONG Length
);

ULONG StorPortGetDataInBufferMdl(
    [in] PVOID HwDeviceExtension,
    [in] PSCSI_REQUEST_BLOCK Srb,
    [out] PVOID *Mdl
);

void ScsiPortReadPortBufferUshort(
    [in] Port,
    [in] Buffer,
    [in] Count
);

void ScsiPortWritePortUchar(
    [in] Port,
    [in] Value
);

ULONG StorPortFreeWorker(
    [in] PVOID HwDeviceExtension,
    PVOID Worker
);

ULONG StorPortGetRequestCryptoInfo(
    PVOID HwDeviceExtension,
    PSCSI_REQUEST_BLOCK Srb,
    PSTOR_CRYPTO_KEY_INFO CryptoKeyInfo
);

ULONG StorPortAllocateDmaMemory(
    [in] PVOID HwDeviceExtension,
    [in] SIZE_T NumberOfBytes,
    [in] PHYSICAL_ADDRESS LowestAcceptableAddress,
    [in] PHYSICAL_ADDRESS HighestAcceptableAddress,
    [in, optional] PHYSICAL_ADDRESS BoundaryAddressMultiple,
    [in] MEMORY_CACHING_TYPE CacheType,
    [in] NODE_REQUIREMENT PreferredNode,
    [out] PVOID *BufferPointer,
    [out] PPHYSICAL_ADDRESS PhysicalAddress
);

ULONG StorPortInitializeTimer(
    [in] PVOID HwDeviceExtension,
    [out] PVOID *TimerHandle
);

ULONG StorPortGetActiveGroupCount(
    [in] PVOID HwDeviceExtension,
    [out] PUSHORT NumberGroups
);

void StorPortReadRegisterBufferUlong64(
    [in] h,
    [in] r,
    [out] b,
    [in] c
);

void StorPortReleaseSpinLock(
    PVOID DeviceExtension,
    [in, out] PSTOR_LOCK_HANDLE LockHandle
);

STORPORT_API BOOLEAN StorPortResume(
    [in] PVOID HwDeviceExtension
);

LONG FIELD_OFFSET(
    _In_ TYPE  Type,
    _In_ PCHAR Field
);

ULONG StorPortPoFxSetPerfState(
    PVOID HwDeviceExtension,
    PSTOR_ADDRESS Address,
    ULONG Component,
    ULONG Flags,
    ULONG SetIndex,
    ULONG State,
    PVOID Context
);

ULONG StorPortHardwareReset(
    PVOID HwDeviceExtension,
    STOR_DEVICE_RESET_TYPE Type
);

void ScsiPortReadPortUshort(
    [in] Port
);

void StorPortWritePortUlong(
    h,
    p,
    v
);

ULONG StorPortNvmeIceIoComplete(
    PVOID HwDeviceExtension,
    PSCSI_REQUEST_BLOCK Srb
);

void ScsiPortReadRegisterUshort(
    [in] Register
);

ULONG StorPortPoFxIdleComponent(
    [in] PVOID HwDeviceExtension,
    [in, optional] PSTOR_ADDRESS Address,
    [in, optional] PSCSI_REQUEST_BLOCK Srb,
    [in] ULONG Component,
    [in] ULONG Flags
);

void ScsiPortWriteRegisterBufferUchar(
    [in] Register,
    [in] Buffer,
    [in] Count
);

ULONG StorPortSetEvent(
    PVOID HwDeviceExtension,
    PSTOR_EVENT Event
);

ULONG StorPortReadRegistryKey(
    PVOID HwDeviceExtension,
    PWSTR AbsolutePath,
    PWSTR KeyName,
    ULONG ValueType,
    PVOID *ValueData,
    PULONG ValueDataLength
);

void ScsiPortWritePortBufferUshort(
    [in] Port,
    [in] Buffer,
    [in] Count
);

ULONG StorPortMaskMsixInterrupt(
    [in] PVOID HwDeviceExtension,
    [in] ULONG MessageId,
    [in] BOOLEAN Mask
);

ULONG StorPortGetRequestInfo(
    [in] PVOID HwDeviceExtension,
    [in] PSCSI_REQUEST_BLOCK Srb,
    [out] PSTOR_REQUEST_INFO RequestInfo
);

void ScsiPortWriteRegisterUlong(
    [in] Register,
    [in] Value
);

ULONG StorPortRegistryReadAdapterKey(
    [in] PVOID HwDeviceExtension,
    [in, optional] PUCHAR SubKeyName,
    [in] PUCHAR ValueName,
    [in] ULONG ValueType,
    [in, out] PVOID *ValueData,
    [in, out] PULONG ValueDataLength
);

void ScsiPortReadPortUlong(
    [in] Port
);

void ScsiPortWriteRegisterUchar(
    [in] Register,
    [in] Value
);

void StorPortReadRegisterUlong(
    [in] h,
    [in] r
);

BOOLEAN StorPortIssueDpc(
    [in] PVOID DeviceExtension,
    [in] PSTOR_DPC Dpc,
    [in] PVOID SystemArgument1,
    [in] PVOID SystemArgument2
);

void StorPortWritePortBufferUshort(
    h,
    p,
    b,
    c
);

ULONG StorPortAllocateHostMemoryBuffer(
    [in] PVOID HwDeviceExtension,
    [in] SIZE_T MinimumBytes,
    [in] SIZE_T PreferredBytes,
    [in] ULONGLONG UtilizationBytes,
    [in] ULONG AlignmentBytes,
    [in] PHYSICAL_ADDRESS LowestAcceptableAddress,
    [in] PHYSICAL_ADDRESS HighestAcceptableAddress,
    [in, optional] PHYSICAL_ADDRESS BoundaryAddressMultiple,
    [in, out] PACCESS_RANGE PhysicalAddressRanges,
    [in, out] PULONG PhysicalAddressRangeCount
);

ULONG StorPortEtwEvent2(
    [in] PVOID HwDeviceExtension,
    [in/optional] PSTOR_ADDRESS Address,
    [in] ULONG EventId,
    [in] PWSTR EventDescription,
    [in] ULONGLONG EventKeywords,
    [in] STORPORT_ETW_LEVEL EventLevel,
    [in] STORPORT_ETW_EVENT_OPCODE EventOpcode,
    [in/optional] PSCSI_REQUEST_BLOCK Srb,
    [in/optional] _In_reads_or_z_opt_(STORPORT_ETW_MAX_PARAM_NAME_LENGTH)PWSTR Parameter1Name,
    [in] ULONGLONG Parameter1Value,
    [in/optional] _In_reads_or_z_opt_(STORPORT_ETW_MAX_PARAM_NAME_LENGTH)PWSTR Parameter2Name,
    [in] ULONGLONG Parameter2Value
);

ULONG StorPortGetPfns(
    [in] PVOID HwDeviceExtension,
    [in] PSCSI_REQUEST_BLOCK Srb,
    [in] PVOID Mdl,
    [out] PVOID *Pfns,
    [out] ULONG *PfnCount,
    [out] ULONG *StartingOffset
);

STORPORT_API BOOLEAN StorPortPauseDevice(
    [in] PVOID HwDeviceExtension,
    [in] UCHAR PathId,
    [in] UCHAR TargetId,
    [in] UCHAR Lun,
    ULONG Timeout
);

ULONG StorPortEnableRegistryKeyNotification(
    PVOID HwDeviceExtension,
    PHW_REGISTRY_NOTIFICATION_ROUTINE NotificationCallback
);

ULONG StorPortQueryDpcWatchdogInformation(
    [in] PVOID HwDeviceExtension,
    [out] PSTOR_DPC_WATCHDOG_INFORMATION DpcWatchdogInformation
);

ULONG StorPortMarkDeviceFailedEx(
    PVOID HwDeviceExtension,
    PSTOR_ADDRESS StorAddress,
    ULONG Flags,
    USHORT FaultCode,
    PWSTR FaultDescription,
    USHORT AdditionalDataSize,
    PUCHAR AdditionalData,
    USHORT CriticalDataSize,
    PUCHAR CriticalData
);

STORPORT_API VOID StorPortNotification(
    SCSI_NOTIFICATION_TYPE NotificationType,
    PVOID HwDeviceExtension,
    ...
);

ULONG StorPortCompleteServiceIrp(
    [in] PVOID HwDeviceExtension,
    [in] PVOID Irp
);

void StorPortWritePortBufferUlong(
    h,
    p,
    b,
    c
);

ULONG StorPortDelayExecution(
    PVOID HwDeviceExtension,
    ULONG DelayInMicroseconds
);

ULONG StorPortRevertToUserGroupAffinityThread(
    [in] PVOID HwDeviceExtension,
    [in/optional] PVOID ThreadContext,
    [in] PSTOR_GROUP_AFFINITY PreviousAffinity
);

ULONG StorPortNvmeLogTelemetry(
    PVOID HwDeviceExtension,
    PVOID ControllerHandle,
    ULONG NamespaceId,
    PSTORPORT_TELEMETRY_EVENT Event,
    STOR_TELEMETRY_CATEGORY Category
);

void StorPortReadRegisterBufferUlong(
    [in] h,
    [in] r,
    [in] b,
    [in] c
);

ULONG StorPortGetNodeAffinity(
    [in] PVOID HwDeviceExtension,
    [in] ULONG NodeNumber,
    [out] PGROUP_AFFINITY NodeAffinityMask
);

void StorPortReadPortBufferUchar(
    [in] h,
    [in] p,
    [in] b,
    [in] c
);

STORPORT_API BOOLEAN StorPortSynchronizeAccess(
    [in] PVOID HwDeviceExtension,
    [in] PSTOR_SYNCHRONIZED_ACCESS SynchronizedAccessRoutine,
    [in, optional] PVOID Context
);

ULONG StorPortCancelDpc(
    PVOID HwDeviceExtension,
    PSTOR_DPC Dpc,
    BOOLEAN *ReturnValue
);

void ScsiPortWritePortUlong(
    [in] Port,
    [in] Value
);

ULONG StorPortGetDriverProxyEndpointWrapper(
    PVOID HwDeviceExtension,
    PSTOR_DRIVER_PROXY_EXTENSION ProxyExtension,
    STOR_DRIVER_PROXY_ENDPOINT_FUNCTION_ID Id,
    PVOID *Wrapper
);

ULONG StorPortQueryTimerMinInterval(
    [in] PVOID HwDeviceExtension,
    [out] PULONG TimerMinInterval
);

ULONG StorPortAcquireSpinLockEx(
    PVOID HwDeviceExtension,
    STOR_SPINLOCK SpinLock,
    PVOID LockContext,
    PSTOR_LOCK_HANDLE LockHandle
);

void StorPortInitializeListHead(
    [in] PVOID HwDeviceExtension,
    [out] PSTOR_LIST_ENTRY ListHead
);

VOID RtlZeroMemory(
    _Out_ VOID UNALIGNED *Destination,
    _In_  SIZE_T         Length
);

ULONG StorPortIsDeviceOperationAllowed(
    [in] PVOID HwDeviceExtension,
    [in] PSTOR_ADDRESS Address,
    [in] LPCGUID DeviceOperation,
    [out] ULONG *AllowedFlag
);

ULONG StorPortInterlockedPopEntrySList(
    [in] PVOID HwDeviceExtension,
    [in, out] PSTOR_SLIST_HEADER SListHead,
    [out] PSTOR_SLIST_ENTRY *Result
);

ULONG StorPortReleaseMSISpinLock(
    [in] PVOID HwDeviceExtension,
    ULONG MessageId,
    [in] ULONG OldIrql
);

ULONG StorPortBuildMdlForNonPagedPool(
    [in] PVOID HwDeviceExtension,
    [in, out] PVOID Mdl
);

ULONG StorPortFreeMdl(
    [in] PVOID HwDeviceExtension,
    [in] PVOID Mdl
);

void ScsiPortWritePortUshort(
    [in] Port,
    [in] Value
);

ULONG StorPortEtwChannelEvent4(
    PVOID HwDeviceExtension,
    PSTOR_ADDRESS Address,
    STORPORT_ETW_EVENT_CHANNEL EventChannel,
    ULONG EventId,
    PWSTR EventDescription,
    ULONGLONG EventKeywords,
    STORPORT_ETW_LEVEL EventLevel,
    STORPORT_ETW_EVENT_OPCODE EventOpcode,
    PSCSI_REQUEST_BLOCK Srb,
    _In_reads_or_z_opt_(STORPORT_ETW_MAX_PARAM_NAME_LENGTH)PWSTR Parameter1Name,
    ULONGLONG Parameter1Value,
    _In_reads_or_z_opt_(STORPORT_ETW_MAX_PARAM_NAME_LENGTH)PWSTR Parameter2Name,
    ULONGLONG Parameter2Value,
    _In_reads_or_z_opt_(STORPORT_ETW_MAX_PARAM_NAME_LENGTH)PWSTR Parameter3Name,
    ULONGLONG Parameter3Value,
    _In_reads_or_z_opt_(STORPORT_ETW_MAX_PARAM_NAME_LENGTH)PWSTR Parameter4Name,
    ULONGLONG Parameter4Value
);

ULONG StorPortGetSystemPortNumber(
    [in] PVOID HwDeviceExtension,
    [in, out] PSTOR_ADDRESS Address
);

ULONG StorPortGetDeviceObjects(
    [in] PVOID HwDeviceExtension,
    [out] PVOID *AdapterDeviceObject,
    [out] PVOID *PhysicalDeviceObject,
    [out] PVOID *LowerDeviceObject
);

ULONG StorPortQueueWorkItem(
    [in] PVOID HwDeviceExtension,
    [in] PHW_WORKITEM WorkItemCallback,
    [in] PVOID Worker,
    [in, optional] PVOID Context
);

void ScsiPortReadPortBufferUchar(
    [in] Port,
    [in] Buffer,
    [in] Count
);

void StorPortWriteRegisterBufferUshort(
    h,
    r,
    b,
    c
);

void StorPortReadPortBufferUshort(
    [in] h,
    [in] p,
    [in] b,
    [in] c
);

ULONG StorPortGetActivityIdSrb(
    [in] PVOID HwDeviceExtension,
    [in] PSCSI_REQUEST_BLOCK Srb,
    [out] LPGUID ActivityId
);

void ScsiPortReadRegisterBufferUshort(
    [in] Register,
    [in] Buffer,
    [in] Count
);

ULONG StorPortGetDeviceBase2(
    PVOID HwDeviceExtension,
    INTERFACE_TYPE BusType,
    ULONG SystemIoBusNumber,
    STOR_PHYSICAL_ADDRESS Address,
    ULONG NumberOfBytes,
    BOOLEAN InIoSpace,
    ULONG Flags,
    PVOID *BaseAddress
);

ULONG StorPortMarkDumpMemory(
    [in] PVOID HwDeviceExtension,
    [in] PVOID Address,
    [in] ULONG_PTR Length,
    [in] ULONG Flags
);

STORPORT_API PVOID StorPortGetUncachedExtension(
    PVOID HwDeviceExtension,
    PPORT_CONFIGURATION_INFORMATION ConfigInfo,
    ULONG NumberOfBytes
);

ULONG StorPortEtwLogByteStream(
    [in] PVOID HwDeviceExtension,
    [in, optional] PSTOR_ADDRESS Address,
    [in] STORPORT_ETW_EVENT_CHANNEL EventChannel,
    [in] ULONG EventId,
    [in] PWSTR EventDescription,
    [in] ULONGLONG EventKeywords,
    [in] STORPORT_ETW_LEVEL EventLevel,
    [in] STORPORT_ETW_EVENT_OPCODE EventOpcode,
    [in] USHORT DataLength,
    [in] PUCHAR Data
);

ULONG StorPortIsDriverHotSwapEnabled(
    PVOID HwDeviceExtension,
    PVOID DriverObject
);

STORPORT_API VOID StorPortStallExecution(
    [in] ULONG Delay
);

STORPORT_API VOID StorPortQuerySystemTime(
    [out] PLARGE_INTEGER CurrentTime
);

void ScsiPortWritePortBufferUchar(
    [in] Port,
    [in] Buffer,
    [in] Count
);

ULONG StorPortPoFxSetIdleTimeout(
    PVOID HwDeviceExtension,
    PSTOR_ADDRESS Address,
    ULONG IdleTimeoutInMS
);

ULONG StorPortEtwEvent4(
    [in] PVOID HwDeviceExtension,
    [in/optional] PSTOR_ADDRESS Address,
    [in] ULONG EventId,
    [in] PWSTR EventDescription,
    [in] ULONGLONG EventKeywords,
    [in] STORPORT_ETW_LEVEL EventLevel,
    [in] STORPORT_ETW_EVENT_OPCODE EventOpcode,
    [in/optional] PSCSI_REQUEST_BLOCK Srb,
    [in/optional] _In_reads_or_z_opt_(STORPORT_ETW_MAX_PARAM_NAME_LENGTH)PWSTR Parameter1Name,
    [in] ULONGLONG Parameter1Value,
    [in/optional] _In_reads_or_z_opt_(STORPORT_ETW_MAX_PARAM_NAME_LENGTH)PWSTR Parameter2Name,
    [in] ULONGLONG Parameter2Value,
    [in/optional] _In_reads_or_z_opt_(STORPORT_ETW_MAX_PARAM_NAME_LENGTH)PWSTR Parameter3Name,
    [in] ULONGLONG Parameter3Value,
    [in/optional] _In_reads_or_z_opt_(STORPORT_ETW_MAX_PARAM_NAME_LENGTH)PWSTR Parameter4Name,
    [in] ULONGLONG Parameter4Value
);

ULONG StorPortPoFxPowerControl(
    [in] PVOID HwDeviceExtension,
    PSTOR_ADDRESS Address,
    [in] LPCGUID PowerControlCode,
    [in, optional] PVOID InBuffer,
    [in] SIZE_T InBufferSize,
    [out, optional] PVOID OutBuffer,
    [in] SIZE_T OutBufferSize,
    [out, optional] PSIZE_T BytesReturned
);

ULONG StorPortFreePool(
    [in] PVOID HwDeviceExtension,
    [in] PVOID BufferPointer
);

ULONG StorPortGetSystemAddress(
    [in] PVOID HwDeviceExtension,
    [in] PSCSI_REQUEST_BLOCK Srb,
    [out] PVOID *SystemAddress
);

ULONG StorPortLogTelemetryEx(
    PVOID HwDeviceExtension,
    PSTOR_ADDRESS StorAddress,
    PSTORPORT_TELEMETRY_EVENT Event,
    STOR_TELEMETRY_CATEGORY Category
);

ULONG StorPortInterlockedInsertHeadList(
    [in] PVOID HwDeviceExtension,
    [in, out] PSTOR_LIST_ENTRY ListHead,
    [in, out] PSTOR_LIST_ENTRY ListEntry,
    [in, out] PSTOR_LIST_ENTRY *Result,
    [in, out] PSTOR_KSPIN_LOCK Lock
);

ULONG StorPortAllocateContiguousMemorySpecifyCacheNode(
    [in] PVOID HwDeviceExtension,
    [in] SIZE_T NumberOfBytes,
    [in] PHYSICAL_ADDRESS LowestAcceptableAddress,
    [in] PHYSICAL_ADDRESS HighestAcceptableAddress,
    [in, optional] PHYSICAL_ADDRESS BoundaryAddressMultiple,
    [in] MEMORY_CACHING_TYPE CacheType,
    [in] NODE_REQUIREMENT PreferredNode,
    [out] PVOID *BufferPointer
);

STORPORT_API PSTOR_SCATTER_GATHER_LIST StorPortGetScatterGatherList(
    [in] PVOID HwDeviceExtension,
    [in] PSCSI_REQUEST_BLOCK Srb
);

ULONG StorPortCreateSystemThread(
    [in] PVOID HwDeviceExtension,
    [in] PSTOR_THREAD_START_ROUTINE StartRoutine,
    [in/optional] PVOID StartContext,
    [in/optional] PSTOR_THREAD_PRIORITY Priority,
    [out/optional] PVOID *ThreadContext
);

STORPORT_API PVOID StorPortGetVirtualAddress(
    [in] PVOID HwDeviceExtension,
    [in] STOR_PHYSICAL_ADDRESS PhysicalAddress
);

ULONG StorPortRegistryWriteAdapterKey(
    [in] PVOID HwDeviceExtension,
    [in, optional] PUCHAR SubKeyName,
    [in] PUCHAR ValueName,
    [in] ULONG ValueType,
    [in, out] PVOID ValueData,
    [in, out] ULONG ValueDataLength
);

STORPORT_API ULONG StorPortGetBusData(
    [in] PVOID DeviceExtension,
    [in] ULONG BusDataType,
    [in] ULONG SystemIoBusNumber,
    [in] ULONG SlotNumber,
    [in, out] PVOID Buffer,
    [in] ULONG Length
);

void ScsiPortWriteRegisterBufferUshort(
    [in] Register,
    [in] Buffer,
    [in] Count
);

STORPORT_API BOOLEAN StorPortDeviceReady(
    [in] PVOID HwDeviceExtension,
    [in] UCHAR PathId,
    [in] UCHAR TargetId,
    [in] UCHAR Lun
);

ULONG StorPortGetStartIoPerfParams(
    [in] PVOID HwDeviceExtension,
    [in] PSCSI_REQUEST_BLOCK Srb,
    [in, out] PSTARTIO_PERFORMANCE_PARAMETERS StartIoPerfParams
);

ULONG StorPortInvokeAcpiMethod(
    [in] PVOID HwDeviceExtension,
    [in, optional] PSTOR_ADDRESS Address,
    [in] ULONG MethodName,
    [in, optional] PVOID InputBuffer,
    [in] ULONG InputBufferLength,
    [in, optional] PVOID OutputBuffer,
    [in] ULONG OutputBufferLength,
    [out, optional] PULONG BytesReturned
);

ULONG StorPortPoFxActivateComponent(
    [in] PVOID HwDeviceExtension,
    [in, optional] PSTOR_ADDRESS Address,
    [in, optional] PSCSI_REQUEST_BLOCK Srb,
    [in] ULONG Component,
    [in] ULONG Flags
);

STORPORT_API VOID StorPortCompleteRequest(
    [in] PVOID HwDeviceExtension,
    [in] UCHAR PathId,
    [in] UCHAR TargetId,
    [in] UCHAR Lun,
    [in] UCHAR SrbStatus
);

void ScsiPortReadPortUchar(
    [in] Port
);

ULONG StorPortInitializePerfOpts(
    [in] PVOID HwDeviceExtension,
    [in] BOOLEAN Query,
    [in, out] PPERF_CONFIGURATION_DATA PerfConfigData
);

ULONG StorPortInitializePoFxPower(
    [in] PVOID HwDeviceExtension,
    [in, optional] PSTOR_ADDRESS Address,
    [in] PSTOR_POFX_DEVICE Device,
    [in, out] PBOOLEAN D3ColdEnabled
);

STORPORT_API BOOLEAN StorPortReady(
    [in] PVOID HwDeviceExtension
);

ULONG StorPortGetDataInBufferSystemAddress(
    [in] PVOID HwDeviceExtension,
    [in] PSCSI_REQUEST_BLOCK Srb,
    [out] PVOID *SystemAddress
);

ULONG StorPortInterlockedPushEntrySList(
    [in] PVOID HwDeviceExtension,
    [in, out] PSTOR_SLIST_HEADER SListHead,
    [in, out] __drv_aliasesMem PSTOR_SLIST_ENTRY SListEntry,
    [out] PSTOR_SLIST_ENTRY *Result
);

ULONG StorPortSecureCopyMemory(
    [out] PVOID Dest,
    [in] SIZE_T DestSizeInBytes,
    [in] const PVOID Src,
    [in] SIZE_T Count
);

ULONG StorPortSetUnitAttributes(
    [in] PVOID HwDeviceExtension,
    [in] PSTOR_ADDRESS Address,
    [in] STOR_UNIT_ATTRIBUTES Attributes
);

ULONG StorPortWaitForSingleObject(
    PVOID HwDeviceExtension,
    PVOID Object,
    BOOLEAN Alertable,
    PLARGE_INTEGER Timeout
);

ULONG StorPortStorMQRemoveController(
    PVOID HwAdapterExtension,
    PVOID ControllerExtension
);

void ScsiPortReadRegisterBufferUchar(
    [in] Register,
    [in] Buffer,
    [in] Count
);

ULONG StorPortInitializeSListHead(
    [in] PVOID HwDeviceExtension,
    [in, out] PSTOR_SLIST_HEADER SListHead
);

