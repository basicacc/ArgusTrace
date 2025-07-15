void NdisMGetDeviceProperty(
    [in] NDIS_HANDLE MiniportAdapterHandle,
    [out, optional] PDEVICE_OBJECT *PhysicalDeviceObject,
    [out, optional] PDEVICE_OBJECT *FunctionalDeviceObject,
    [out, optional] PDEVICE_OBJECT *NextDeviceObject,
    [out, optional] PCM_RESOURCE_LIST *AllocatedResources,
    [out, optional] PCM_RESOURCE_LIST *AllocatedResourcesTranslated
);

PVOID NdisGetRoutineAddress(
    [in] PNDIS_STRING NdisRoutineName
);

void NDIS_NBL_ADD_MEDIA_SPECIFIC_INFO_EX(
    _NBL,
    _MediaSpecificInfo
);

void NdisReleaseSpinLock(
    [in] _SpinLock
);

void NdisMFlushLog(
    [in] NDIS_HANDLE LogHandle
);

void NdisFreeGenericObject(
    PNDIS_GENERIC_OBJECT NdisObject
);

void NdisCancelOidRequest(
    [in] NDIS_HANDLE NdisBindingHandle,
    [in] PVOID RequestId
);

NDIS_STATUS NdisMQueryProbedBars(
    [in] NDIS_HANDLE NdisMiniportHandle,
    [out] PULONG BaseRegisterValues
);

void NDIS_INIT_MUTEX(
    _M_
);

VOID NdisInitializeWrapper(
    _Out_ PNDIS_HANDLE NdisWrapperHandle,
    _In_ PVOID SystemSpecific1,
    _In_ PVOID SystemSpecific2,
    _In_ PVOID SystemSpecific3
);

USHORT NdisMaxGroupCount();

void NdisRawWritePortUshort(
    [in] Port,
    [in] Data
);

void NdisRequest(
    [out] PNDIS_STATUS Status,
    [in] NDIS_HANDLE NdisBindingHandle,
    [in] PNDIS_REQUEST NdisRequest
);

void NdisEqualUnicodeString(
    [in] _String1,
    [in] _String2,
    _CaseInsensitive
);

NDIS_STATUS NdisDirectOidRequest(
    [in] NDIS_HANDLE NdisBindingHandle,
    [in] PNDIS_OID_REQUEST OidRequest
);

NDIS_STATUS NdisCoCreateVc(
    [in] NDIS_HANDLE NdisBindingHandle,
    [in, optional] NDIS_HANDLE NdisAfHandle,
    [in] NDIS_HANDLE ProtocolVcContext,
    [in, out] PNDIS_HANDLE NdisVcHandle
);

NDIS_STATUS NdisFSetAttributes(
    [in] NDIS_HANDLE NdisFilterHandle,
    [in] __drv_aliasesMem NDIS_HANDLE FilterModuleContext,
    [in] PNDIS_FILTER_ATTRIBUTES FilterAttributes
);

NDIS_STATUS NdisIMCancelInitializeDeviceInstance(
    [in] NDIS_HANDLE DriverHandle,
    [in] PNDIS_STRING DeviceInstance
);

void NdisFreeTimerObject(
    [in] NDIS_HANDLE TimerObject
);

NDIS_HANDLE NdisIMGetDeviceContext(
    [in] NDIS_HANDLE MiniportAdapterHandle
);

void NdisFCancelDirectOidRequest(
    [in] NDIS_HANDLE NdisFilterHandle,
    [in] PVOID RequestId
);

void NdisCoOidRequestComplete(
    [in] NDIS_HANDLE NdisAfHandle,
    [in, optional] NDIS_HANDLE NdisVcHandle,
    [in, optional] NDIS_HANDLE NdisPartyHandle,
    [in] PNDIS_OID_REQUEST OidRequest,
    [in] NDIS_STATUS Status
);

void NdisMCmMakeCallComplete(
    _S_,
    _VH_,
    _PH_,
    _CC_,
    _CP_
);

void NDIS_GET_NET_BUFFER_LIST_CANCEL_ID(
    _NBL
);

void NdisInterlockedAddLargeStatistic(
    [in] _Addend,
    [in] _Increment
);

void NdisIMCopySendPerPacketInfo(
    [out] OUT PNDIS_PACKET DstPacket,
    [in] IN PNDIS_PACKET SrcPacket
);

void NdisAllocateBuffer(
    [out] PNDIS_STATUS Status,
    [out] PNDIS_BUFFER *Buffer,
    [in, optional] NDIS_HANDLE PoolHandle,
    [in] PVOID VirtualAddress,
    [in] UINT Length
);

NDIS_STATUS NdisMWriteConfigBlock(
    [in] NDIS_HANDLE NdisMiniportHandle,
    [in] ULONG BlockId,
    [in] PVOID Buffer,
    [in] ULONG Length
);

NDIS_STATUS NdisSetOptionalHandlers(
    NDIS_HANDLE NdisHandle,
    PNDIS_DRIVER_OPTIONAL_HANDLERS OptionalHandlers
);

void NdisFCancelSendNetBufferLists(
    [in] NDIS_HANDLE NdisFilterHandle,
    [in] PVOID CancelId
);

void NdisMCmAddPartyComplete(
    _S_,
    _H_,
    _C_,
    _P_
);

NDIS_STATUS NdisMNetPnPEvent(
    [in] NDIS_HANDLE MiniportAdapterHandle,
    PNET_PNP_EVENT_NOTIFICATION NetPnPEventNotification
);

void NdisSetPhysicalAddressLow(
    [in] _PhysicalAddress,
    [in] _Value
);

void NdisAllocateBufferPool(
    [out] PNDIS_STATUS Status,
    [out] PNDIS_HANDLE PoolHandle,
    [in] UINT NumberOfDescriptors
);

void NdisInterlockedDecrement(
    [in] Addend
);

NDIS_STATUS NdisMCmCreateVc(
    [in] NDIS_HANDLE MiniportAdapterHandle,
    [in] NDIS_HANDLE NdisAfHandle,
    [in] NDIS_HANDLE MiniportVcContext,
    [out] PNDIS_HANDLE NdisVcHandle
);

void NdisFDevicePnPEventNotify(
    [in] NDIS_HANDLE NdisFilterHandle,
    [in] PNET_DEVICE_PNP_EVENT NetDevicePnPEvent
);

NDIS_STATUS NdisMCmOidRequest(
    [in] NDIS_HANDLE NdisAfHandle,
    [in, optional] NDIS_HANDLE NdisVcHandle,
    [in, optional] NDIS_HANDLE NdisPartyHandle,
    PNDIS_OID_REQUEST NdisOidRequest
);

NDIS_STATUS NdisGetProcessorInformationEx(
    [in, optional] NDIS_HANDLE NdisHandle,
    [out, optional] PNDIS_SYSTEM_PROCESSOR_INFO_EX SystemProcessorInfo,
    [in, out] PSIZE_T Size
);

void NdisCmDispatchCallConnected(
    [in] NDIS_HANDLE NdisVcHandle
);

NDIS_STATUS NdisIMDeInitializeDeviceInstance(
    [in] NDIS_HANDLE NdisMiniportHandle
);

UINT NdisPacketPoolUsage(
    [in] NDIS_HANDLE PoolHandle
);

NDIS_STATUS NdisAllocateCloneOidRequest(
    [in] IN NDIS_HANDLE SourceHandle,
    IN PNDIS_OID_REQUEST OidRequest,
    [in] IN UINT PoolTag,
    OUT PNDIS_OID_REQUEST *ClonedOidRequest
);

void NdisMUnmapIoSpace(
    [in] NDIS_HANDLE MiniportAdapterHandle,
    [in] PVOID VirtualAddress,
    [in] UINT Length
);

void NdisMRestartComplete(
    [in] IN NDIS_HANDLE MiniportAdapterHandle,
    [in] IN NDIS_STATUS Status
);

void NdisGetPhysicalAddressLow(
    [in] _PhysicalAddress
);

void NdisCoSendNetBufferLists(
    [in] NDIS_HANDLE NdisVcHandle,
    [in] PNET_BUFFER_LIST NetBufferLists,
    [in] ULONG SendFlags
);

ULONG NdisMGetDmaAlignment(
    [in] NDIS_HANDLE MiniportAdapterHandle
);

void NdisSendNetBufferLists(
    [in] NDIS_HANDLE NdisBindingHandle,
    [in] __drv_aliasesMem PNET_BUFFER_LIST NetBufferLists,
    [in] NDIS_PORT_NUMBER PortNumber,
    [in] ULONG SendFlags
);

void NET_BUFFER_LIST_RECEIVE_FILTER_VPORT_ID(
    _NBL
);

void NdisInterlockedPopEntrySList(
    SListHead,
    [in] Lock
);

void NdisCmDropPartyComplete(
    [in] NDIS_STATUS Status,
    [in] NDIS_HANDLE NdisPartyHandle
);

NDIS_STATUS NdisQueryAdapterInstanceName(
    PNDIS_STRING pAdapterInstanceName,
    [in] NDIS_HANDLE NdisBindingHandle
);

void NdisMCoIndicateReceiveNetBufferLists(
    [in] IN NDIS_HANDLE NdisVcHandle,
    [in] IN PNET_BUFFER_LIST NetBufferLists,
    [in] IN ULONG NumberOfNetBufferLists,
    [in] IN ULONG CoReceiveFlags
);

BOOLEAN NdisSetCoalescableTimerObject(
    [in] NDIS_HANDLE TimerObject,
    [in] LARGE_INTEGER DueTime,
    [in, optional] LONG MillisecondsPeriod,
    [in, optional] PVOID FunctionContext,
    [in, optional] ULONG Tolerance
);

void NdisAcquireRWLockRead(
    [in] PNDIS_RW_LOCK_EX Lock,
    [out] PLOCK_STATE_EX LockState,
    [in] UCHAR Flags
);

NDIS_STATUS NdisFOidRequest(
    [in] NDIS_HANDLE NdisFilterHandle,
    [in] PNDIS_OID_REQUEST OidRequest
);

void NdisMCmDispatchCallConnected(
    _H_
);

NDIS_STATUS NdisClCloseCall(
    [in] NDIS_HANDLE NdisVcHandle,
    [in, optional] NDIS_HANDLE NdisPartyHandle,
    [in, optional] PVOID Buffer,
    [in] UINT Size
);

NDIS_STATUS NdisCmRegisterAddressFamilyEx(
    [in] NDIS_HANDLE NdisBindingHandle,
    [in] PCO_ADDRESS_FAMILY AddressFamily
);

NDIS_STATUS NdisClMakeCall(
    [in] NDIS_HANDLE NdisVcHandle,
    [in, out] PCO_CALL_PARAMETERS CallParameters,
    [in, optional] NDIS_HANDLE ProtocolPartyContext,
    [out, optional] PNDIS_HANDLE NdisPartyHandle
);

NDIS_STATUS NdisFGetOptionalSwitchHandlers(
    [in] NDIS_HANDLE NdisFilterHandle,
    [out] PNDIS_SWITCH_CONTEXT NdisSwitchContext,
    [in, out] PNDIS_SWITCH_OPTIONAL_HANDLERS NdisSwitchHandlers
);

void NdisCloseFile(
    [in] NDIS_HANDLE FileHandle
);

void NdisReturnNetBufferLists(
    [in] NDIS_HANDLE NdisBindingHandle,
    [in] PNET_BUFFER_LIST NetBufferLists,
    [in] ULONG ReturnFlags
);

void NDIS_WAIT_FOR_MUTEX(
    _M_
);

NDIS_STATUS NdisClGetProtocolVcContextFromTapiCallId(
    [in] UNICODE_STRING TapiCallId,
    [out] PNDIS_HANDLE ProtocolVcContext
);

void NdisCancelSendNetBufferLists(
    [in] NDIS_HANDLE NdisBindingHandle,
    [in] PVOID CancelId
);

void NdisQueueIoWorkItem(
    [in] NDIS_HANDLE NdisIoWorkItemHandle,
    [in] NDIS_IO_WORKITEM_ROUTINE Routine,
    [in] PVOID WorkItemContext
);

NDIS_STATUS NdisFNetPnPEvent(
    NDIS_HANDLE NdisFilterHandle,
    PNET_PNP_EVENT_NOTIFICATION NetPnPEventNotification
);

void NdisFPauseComplete(
    [in] NDIS_HANDLE NdisFilterHandle
);

NDIS_STATUS NdisIMRegisterLayeredMiniport(
    [in] NDIS_HANDLE NdisWrapperHandle,
    [in] PNDIS_MINIPORT_CHARACTERISTICS MiniportCharacteristics,
    [in] UINT CharacteristicsLength,
    [out] PNDIS_HANDLE DriverHandle
);

void NdisGetCurrentProcessorCpuUsage(
    [out] PULONG pCpuUsage
);

NDIS_STATUS NdisMCmRegisterAddressFamilyEx(
    [in] NDIS_HANDLE MiniportAdapterHandle,
    [in] PCO_ADDRESS_FAMILY AddressFamily
);

void NDIS_NBL_GET_MEDIA_SPECIFIC_INFO_EX(
    _NBL,
    _Tag,
    _MediaSpecificInfo
);

void NdisStallExecution(
    MicroSecondsToStall
);

void NdisCancelDirectOidRequest(
    [in] NDIS_HANDLE NdisBindingHandle,
    [in] PVOID RequestId
);

NDIS_STATUS NdisCoDeleteVc(
    [in] NDIS_HANDLE NdisVcHandle
);

NDIS_HANDLE NdisIMGetBindingContext(
    [in] NDIS_HANDLE NdisBindingHandle
);

NDIS_STATUS NdisMAllocateSharedMemoryAsyncEx(
    [in] NDIS_HANDLE MiniportDmaHandle,
    [in] ULONG Length,
    [in] BOOLEAN Cached,
    [in] PVOID Context
);

NDIS_STATUS NdisCmDeactivateVc(
    [in] NDIS_HANDLE NdisVcHandle
);

UINT NdisGetVersion();

void NdisIfDeleteIfStackEntry(
    [in] NET_IFINDEX HigherLayerIfIndex,
    [in] NET_IFINDEX LowerLayerIfIndex
);

ULONG NdisSystemActiveProcessorCount(
    PKAFFINITY ActiveProcessors
);

NDIS_STATUS NdisMRegisterInterruptEx(
    [in] NDIS_HANDLE MiniportAdapterHandle,
    [in] NDIS_HANDLE MiniportInterruptContext,
    [in] PNDIS_MINIPORT_INTERRUPT_CHARACTERISTICS MiniportInterruptCharacteristics,
    [out] PNDIS_HANDLE NdisInterruptHandle
);

PNDIS_PACKET NdisGetReceivedPacket(
    [in] NDIS_HANDLE NdisBindingHandle,
    [in] NDIS_HANDLE MacContext
);

void NdisTerminateWrapper(
    [in] NDIS_HANDLE NdisWrapperHandle,
    [in] PVOID SystemSpecific
);

NDIS_STATUS NdisMCmActivateVc(
    [in] NDIS_HANDLE NdisVcHandle,
    [in] PCO_CALL_PARAMETERS CallParameters
);

void NdisMCmDispatchIncomingCallQoSChange(
    _H_,
    _P_
);

void NdisCmCloseCallComplete(
    [in] NDIS_STATUS Status,
    [in] NDIS_HANDLE NdisVcHandle,
    [in, optional] NDIS_HANDLE NdisPartyHandle
);

void NdisReEnumerateProtocolBindings(
    [in] NDIS_HANDLE NdisProtocolHandle
);

void NdisFOidRequestComplete(
    [in] NDIS_HANDLE NdisFilterHandle,
    [in] PNDIS_OID_REQUEST OidRequest,
    [in] NDIS_STATUS Status
);

void NdisRawWritePortUchar(
    [in] Port,
    [in] Data
);

void NdisCancelSendPackets(
    [in] NDIS_HANDLE NdisBindingHandle,
    [in] PVOID CancelId
);

NDIS_STATUS NdisCmNotifyCloseAddressFamily(
    [in] NDIS_HANDLE NdisAfHandle
);

BOOLEAN NdisWaitEvent(
    [in] PNDIS_EVENT Event,
    [in] UINT MsToWait
);

ULONG NdisMGetBusData(
    NDIS_HANDLE NdisMiniportHandle,
    [in] ULONG WhichSpace,
    [in] ULONG Offset,
    [out] PVOID Buffer,
    [in] ULONG Length
);

void NdisFreePacketPool(
    NDIS_HANDLE PoolHandle
);

void NdisMIndicateStatusEx(
    [in] NDIS_HANDLE MiniportAdapterHandle,
    [in] PNDIS_STATUS_INDICATION StatusIndication
);

void NdisAdjustMdlLength(
    [in] _Mdl,
    [in] _Length
);

NDIS_STATUS NdisUnbindAdapter(
    [in] NDIS_HANDLE NdisBindingHandle
);

ULONG NdisMReadDmaCounter(
    [in] NDIS_HANDLE MiniportDmaHandle
);

NDIS_STATUS NdisMRegisterDmaChannel(
    [out] PNDIS_HANDLE MiniportDmaHandle,
    [in] NDIS_HANDLE MiniportAdapterHandle,
    [in] UINT DmaChannel,
    [in] BOOLEAN Dma32BitAddresses,
    [in] PNDIS_DMA_DESCRIPTION DmaDescription,
    [in] ULONG MaximumLength
);

void NDIS_SWITCH_PORT_DESTINATION_AT_ARRAY_INDEX(
    _DestArray_,
    _Index_
);

NDIS_STATUS NdisBuildScatterGatherList(
    [in] IN NDIS_HANDLE NdisHandle,
    [in] IN PNDIS_SCATTER_GATHER_LIST_PARAMETERS SGListParameters
);

void NdisCompleteUnbindAdapterEx(
    [in] NDIS_HANDLE UnbindContext
);

void NdisAnsiStringToUnicodeString(
    _us,
    _as
);

void NdisCmMakeCallComplete(
    [in] NDIS_STATUS Status,
    [in] NDIS_HANDLE NdisVcHandle,
    [in, optional] NDIS_HANDLE NdisPartyHandle,
    [in, optional] NDIS_HANDLE CallMgrPartyContext,
    [in] PCO_CALL_PARAMETERS CallParameters
);

NDIS_STATUS NdisCoOidRequest(
    [in] NDIS_HANDLE NdisBindingHandle,
    [in, optional] NDIS_HANDLE NdisAfHandle,
    [in, optional] NDIS_HANDLE NdisVcHandle,
    [in, optional] NDIS_HANDLE NdisPartyHandle,
    [in, out] PNDIS_OID_REQUEST OidRequest
);

KAFFINITY NdisMQueueDpcEx(
    [in] IN NDIS_HANDLE NdisInterruptHandle,
    [in] IN ULONG MessageId,
    [in] IN PGROUP_AFFINITY TargetProcessors,
    [in] IN PVOID MiniportDpcContext
);

USHORT NdisActiveGroupCount();

void NdisGetCurrentSystemTime(
    [in] _pSystemTime
);

void NdisMResetComplete(
    _M,
    _S,
    _A
);

NDIS_STATUS NdisQueryBindInstanceName(
    [out] PNDIS_STRING pAdapterInstanceName,
    [in] NDIS_HANDLE BindingContext
);

void NdisRawWritePortUlong(
    [in] Port,
    [in] Data
);

void NdisEqualString(
    [in] _String1,
    [in] _String2,
    [in] _CaseInsensitive
);

void NdisFreeSpinLock(
    [in] PNDIS_SPIN_LOCK SpinLock
);

NDIS_STATUS NdisMCreateLog(
    [in] NDIS_HANDLE MiniportAdapterHandle,
    [in] UINT Size,
    [out] PNDIS_HANDLE LogHandle
);

void NdisWriteConfiguration(
    [out] PNDIS_STATUS Status,
    [in] NDIS_HANDLE ConfigurationHandle,
    [in] PNDIS_STRING Keyword,
    [in] PNDIS_CONFIGURATION_PARAMETER ParameterValue
);

NDIS_STATUS NdisIfQueryBindingIfIndex(
    [in] NDIS_HANDLE NdisBindingHandle,
    [out] PNET_IFINDEX pBoundIfIndex,
    [out] PNET_LUID pBoundIfNetLuid,
    [out] PNET_IFINDEX pLowestIfIndex,
    [out] PNET_LUID pLowestIfNetLuid
);

NDIS_STATUS NdisFRegisterFilterDriver(
    [in] PDRIVER_OBJECT DriverObject,
    [in] NDIS_HANDLE FilterDriverContext,
    PNDIS_FILTER_DRIVER_CHARACTERISTICS FilterDriverCharacteristics,
    [out] PNDIS_HANDLE NdisFilterDriverHandle
);

NDIS_STATUS NdisMRegisterDevice(
    [in] NDIS_HANDLE NdisWrapperHandle,
    [in] PNDIS_STRING DeviceName,
    [in] PNDIS_STRING SymbolicName,
    [in] PDRIVER_DISPATCH *MajorFunctions,
    [in] PDEVICE_OBJECT *pDeviceObject,
    [out] NDIS_HANDLE *NdisDeviceHandle
);

void NdisRawReadPortUshort(
    [in] Port,
    [out] Data
);

NDIS_STATUS NdisMRegisterIoPortRange(
    [out] PVOID *PortOffset,
    [in] NDIS_HANDLE MiniportAdapterHandle,
    [in] UINT InitialPort,
    [in] UINT NumberOfPorts
);

void NdisMDeregisterDmaChannel(
    [in] NDIS_HANDLE MiniportDmaHandle
);

NDIS_STATUS NdisOpenConfigurationEx(
    [in] PNDIS_CONFIGURATION_OBJECT ConfigObject,
    [out] PNDIS_HANDLE ConfigurationHandle
);

void NdisUpcaseUnicodeString(
    _d,
    _s
);

void NdisReleaseRWLock(
    [in] PNDIS_RW_LOCK_EX Lock,
    [in] PLOCK_STATE_EX LockState
);

void NdisMGetVirtualFunctionLocation(
    [in] NDIS_HANDLE NdisMiniportHandle,
    [in] NDIS_SRIOV_FUNCTION_ID VFId,
    [out] PUSHORT SegmentNumber,
    [out] PUCHAR BusNumber,
    [out] PUCHAR FunctionNumber
);

void NdisCmRegisterSapComplete(
    [in] NDIS_STATUS Status,
    [in] NDIS_HANDLE NdisSapHandle,
    [in] NDIS_HANDLE CallMgrSapContext
);

NDIS_STATUS NdisIfGetNetLuidFromInterfaceIndex(
    NET_IFINDEX ifIndex,
    [out] PNET_LUID pNetLuid
);

void NdisFDirectOidRequestComplete(
    [in] NDIS_HANDLE NdisFilterHandle,
    [in] PNDIS_OID_REQUEST OidRequest,
    [in] NDIS_STATUS Status
);

void NdisFreeMemoryWithTagPriority(
    [in] NDIS_HANDLE NdisHandle,
    [in] PVOID VirtualAddress,
    [in] ULONG Tag
);

void NdisReadConfiguration(
    [out] PNDIS_STATUS Status,
    [out] PNDIS_CONFIGURATION_PARAMETER *ParameterValue,
    [in] NDIS_HANDLE ConfigurationHandle,
    [in] PNDIS_STRING Keyword,
    [in] NDIS_PARAMETER_TYPE ParameterType
);

void NdisFIndicateReceiveNetBufferLists(
    [in] NDIS_HANDLE NdisFilterHandle,
    [in] PNET_BUFFER_LIST NetBufferLists,
    [in] NDIS_PORT_NUMBER PortNumber,
    [in] ULONG NumberOfNetBufferLists,
    [in] ULONG ReceiveFlags
);

void NdisReadRegisterUchar(
    [in] Register,
    [out] Data
);

ULONG NdisGroupActiveProcessorCount(
    USHORT Group
);

void NdisRawReadPortBufferUlong(
    [in] Port,
    [out] Buffer,
    [in] Length
);

void NdisRawReadPortUlong(
    [in] Port,
    [out] Data
);

void NdisDeregisterProtocol(
    [out] PNDIS_STATUS Status,
    [in] NDIS_HANDLE NdisProtocolHandle
);

void NdisIfDeregisterProvider(
    [in] NDIS_HANDLE NdisProviderHandle
);

void NdisMCmDispatchIncomingCloseCall(
    _S_,
    _H_,
    _B_,
    _Z_
);

void NdisMDirectOidRequestComplete(
    [in] NDIS_HANDLE MiniportAdapterHandle,
    [in] PNDIS_OID_REQUEST OidRequest,
    [in] NDIS_STATUS Status
);

NDIS_STATUS NdisCmDispatchIncomingCall(
    [in] NDIS_HANDLE NdisSapHandle,
    [in] NDIS_HANDLE NdisVcHandle,
    [in] PCO_CALL_PARAMETERS CallParameters
);

void NdisFreeScatterGatherList(
    [in] IN NDIS_HANDLE NdisHandle,
    [in] IN PSCATTER_GATHER_LIST ScatterGatherListBuffer,
    [in] IN BOOLEAN WriteToDevice
);

NDIS_STATUS NdisClDeregisterSap(
    [in] NDIS_HANDLE NdisSapHandle
);

void NdisStoreUlong(
    Destination,
    [in] Value
);

NDIS_STATUS NdisSynchronousOidRequest(
    [in] NDIS_HANDLE NdisBindingHandle,
    [in] NDIS_OID_REQUEST *OidRequest
);

void NDIS_NBL_REMOVE_MEDIA_SPECIFIC_INFO(
    _NBL,
    _MediaSpecificInfo
);

PVOID NdisAllocateMemoryWithTagPriority(
    [in] NDIS_HANDLE NdisHandle,
    [in] UINT Length,
    [in] ULONG Tag,
    [in] EX_POOL_PRIORITY Priority
);

NDIS_STATUS NdisClRegisterSap(
    [in] NDIS_HANDLE NdisAfHandle,
    [in] NDIS_HANDLE ProtocolSapContext,
    [in] PCO_SAP Sap,
    [out] PNDIS_HANDLE NdisSapHandle
);

ULONG NdisMQueueDpc(
    [in] NDIS_HANDLE NdisInterruptHandle,
    [in] ULONG MessageId,
    [in] ULONG TargetProcessors,
    [in, optional] PVOID MiniportDpcContext
);

void NdisOpenConfigurationKeyByName(
    [out] PNDIS_STATUS Status,
    [in] NDIS_HANDLE ConfigurationHandle,
    [in] PNDIS_STRING SubKeyName,
    [out] PNDIS_HANDLE SubKeyHandle
);

void NdisReadRegisterUlong(
    [in] Register,
    [out] Data
);

NDIS_STATUS NdisRegisterProtocolDriver(
    [in, optional] NDIS_HANDLE ProtocolDriverContext,
    [in] PNDIS_PROTOCOL_DRIVER_CHARACTERISTICS ProtocolCharacteristics,
    [out] PNDIS_HANDLE NdisProtocolHandle
);

void NdisMAllocateSharedMemory(
    [in] NDIS_HANDLE MiniportAdapterHandle,
    [in] ULONG Length,
    [in] BOOLEAN Cached,
    [out] PVOID *VirtualAddress,
    [out] PNDIS_PHYSICAL_ADDRESS PhysicalAddress
);

NDIS_STATUS NdisIfRegisterInterface(
    [in] NDIS_HANDLE NdisProviderHandle,
    [in] NET_LUID NetLuid,
    [in] NDIS_HANDLE ProviderIfContext,
    [in] PNET_IF_INFORMATION pIfInfo,
    PNET_IFINDEX pfIndex
);

NDIS_STATUS NdisMFreePort(
    NDIS_HANDLE NdisMiniportHandle,
    [in] NDIS_PORT_NUMBER PortNumber
);

void NdisRetrieveUlong(
    Destination,
    Source
);

PNDIS_RW_LOCK_EX NdisAllocateRWLock(
    NDIS_HANDLE NdisHandle
);

void NDIS_RELEASE_MUTEX(
    _M_
);

NDIS_STATUS NdisIfFreeNetLuidIndex(
    NET_IFTYPE ifType,
    [in] UINT32 NetLuidIndex
);

void NdisResetEvent(
    [in] PNDIS_EVENT Event
);

ULONG NdisMSetVirtualFunctionBusData(
    [in] NDIS_HANDLE NdisMiniportHandle,
    [in] NDIS_SRIOV_FUNCTION_ID VFId,
    [in] PVOID Buffer,
    [in] ULONG Offset,
    [in] ULONG Length
);

void NdisFreeMemory(
    [in] PVOID VirtualAddress,
    [in] UINT Length,
    [in] UINT MemoryFlags
);

void NdisAllocatePacketPoolEx(
    [out] PNDIS_STATUS Status,
    [out] PNDIS_HANDLE PoolHandle,
    [in] UINT NumberOfDescriptors,
    [in] UINT NumberOfOverflowDescriptors,
    [in] UINT ProtocolReservedLength
);

NDIS_STATUS NdisOpenAdapterEx(
    [in] NDIS_HANDLE NdisProtocolHandle,
    [in] NDIS_HANDLE ProtocolBindingContext,
    [in] PNDIS_OPEN_PARAMETERS OpenParameters,
    [in] NDIS_HANDLE BindContext,
    [out] PNDIS_HANDLE NdisBindingHandle
);

void NDIS_NBL_REMOVE_MEDIA_SPECIFIC_INFO_EX(
    _NBL,
    _MediaSpecificInfo
);

NDIS_STATUS NdisAllocateSharedMemory(
    [in] NDIS_HANDLE NdisHandle,
    [in] PNDIS_SHARED_MEMORY_PARAMETERS SharedMemoryParameters,
    [in, out] PNDIS_HANDLE pAllocationHandle
);

void NdisCompleteBindAdapterEx(
    NDIS_HANDLE BindAdapterContext,
    [in] NDIS_STATUS Status
);

void NdisCmDispatchIncomingDropParty(
    [in] NDIS_STATUS DropStatus,
    [in] NDIS_HANDLE NdisPartyHandle,
    [in, optional] PVOID Buffer,
    [in] UINT Size
);

void NdisGetSystemUpTimeEx(
    [out] PLARGE_INTEGER pSystemUpTime
);

NDIS_STATUS NdisMDeregisterDevice(
    [in] NDIS_HANDLE NdisDeviceHandle
);

void NdisMIndicateStatus(
    [in] NDIS_HANDLE MiniportHandle,
    [in] NDIS_STATUS GeneralStatus,
    [in] PVOID StatusBuffer,
    [in] UINT StatusBufferSize
);

void NdisIMCopySendCompletePerPacketInfo(
    [out] OUT PNDIS_PACKET DstPacket,
    [in] IN PNDIS_PACKET SrcPacket
);

void NdisMDeregisterMiniportDriver(
    [in] NDIS_HANDLE NdisMiniportDriverHandle
);

NDIS_STATUS NdisFSynchronousOidRequest(
    [in] NDIS_HANDLE NdisFilterModuleHandle,
    [in] NDIS_OID_REQUEST *OidRequest
);

NDIS_STATUS NdisMRemoveMiniport(
    NDIS_HANDLE MiniportHandle
);

NDIS_STATUS NdisCmActivateVc(
    [in] NDIS_HANDLE NdisVcHandle,
    [in, out] PCO_CALL_PARAMETERS CallParameters
);

void NdisMRegisterUnloadHandler(
    [in] NDIS_HANDLE NdisWrapperHandle,
    [in] PDRIVER_UNLOAD UnloadHandler
);

void NdisInitUnicodeString(
    _us,
    s
);

void NdisFillMemory(
    [in] Destination,
    [in] Length,
    [in] Fill
);

void NdisRawWritePortBufferUchar(
    [in] Port,
    [in] Buffer,
    [in] Length
);

void NdisFreeToNPagedLookasideList(
    _L,
    _E
);

void NdisIMAssociateMiniport(
    [in] NDIS_HANDLE DriverHandle,
    [in] NDIS_HANDLE ProtocolHandle
);

void NdisReadNetworkAddress(
    [out] PNDIS_STATUS Status,
    [out] PVOID *NetworkAddress,
    [out] PUINT NetworkAddressLength,
    [in] NDIS_HANDLE ConfigurationHandle
);

void NdisMSendNetBufferListsComplete(
    [in] NDIS_HANDLE MiniportAdapterHandle,
    PNET_BUFFER_LIST NetBufferList,
    [in] ULONG SendCompleteFlags
);

PVOID NdisGetDeviceReservedExtension(
    [in] PDEVICE_OBJECT DeviceObject
);

void NdisCompleteNetPnPEvent(
    [in] NDIS_HANDLE NdisBindingHandle,
    PNET_PNP_EVENT_NOTIFICATION NetPnPEventNotification,
    [in] NDIS_STATUS Status
);

void NdisMSetAttributesEx(
    [in] NDIS_HANDLE MiniportAdapterHandle,
    [in] NDIS_HANDLE MiniportAdapterContext,
    [in, optional] UINT CheckForHangTimeInSeconds,
    [in] ULONG AttributeFlags,
    [in, optional] NDIS_INTERFACE_TYPE AdapterType
);

NDIS_STATUS NdisClCloseAddressFamily(
    [in] NDIS_HANDLE NdisAfHandle
);

void NdisSetPhysicalAddressHigh(
    [in] _PhysicalAddress,
    [in] _Value
);

NDIS_STATUS NdisMReadConfigBlock(
    [in] NDIS_HANDLE NdisMiniportHandle,
    [in] ULONG BlockId,
    [out] PVOID Buffer,
    [in] ULONG Length
);

void NdisInitializeSListHead(
    [in] SListHead
);

NDIS_STATUS NdisWriteEventLogEntry(
    [in] PVOID LogHandle,
    [in] NDIS_STATUS EventCode,
    [in] ULONG UniqueEventValue,
    [in] USHORT NumStrings,
    [in, optional] PVOID StringsList,
    [in] ULONG DataSize,
    [in, optional] PVOID Data
);

void NdisWriteRegisterUshort(
    [in] Register,
    [in] Data
);

ULONG NdisGroupMaxProcessorCount(
    USHORT Group
);

void NdisMCmDeregisterSapComplete(
    _S_,
    _H_
);

void NdisZeroMappedMemory(
    [in] Destination,
    [in] Length
);

void NdisWriteErrorLogEntry(
    [in] NDIS_HANDLE NdisAdapterHandle,
    [in] NDIS_ERROR_CODE ErrorCode,
    [in] ULONG NumberOfErrorValues,
    ...
);

void NET_BUFFER_LIST_SWITCH_FORWARDING_DETAIL(
    _NBL
);

void NdisMIdleNotificationComplete(
    [in] NDIS_HANDLE MiniportAdapterHandle
);

void NdisMResetMiniport(
    [in] NDIS_HANDLE MiniportAdapterHandle
);

void NdisQueryDepthSList(
    [in] SListHead
);

NDIS_STATUS NdisAllocateTimerObject(
    [in] NDIS_HANDLE NdisHandle,
    [in] PNDIS_TIMER_CHARACTERISTICS TimerCharacteristics,
    [out] PNDIS_HANDLE pTimerObject
);

void NdisClIncomingCallComplete(
    [in] NDIS_STATUS Status,
    [in] NDIS_HANDLE NdisVcHandle,
    [in] PCO_CALL_PARAMETERS CallParameters
);

void NdisFreeString(
    [in] String
);

NDIS_STATUS NdisMCmDeleteVc(
    [in] NDIS_HANDLE NdisVcHandle
);

NDIS_STATUS NdisIfAllocateNetLuidIndex(
    NET_IFTYPE ifType,
    [out] PUINT32 pNetLuidIndex
);

void NdisMCmOpenAddressFamilyComplete(
    _S_,
    _H_,
    _C_
);

NDIS_STATUS NdisMConfigMSIXTableEntry(
    [in] NDIS_HANDLE NdisMiniportHandle,
    [in] PNDIS_MSIX_CONFIG_PARAMETERS MSIXConfigParameters
);

NDIS_STATUS NdisMRegisterScatterGatherDma(
    [in] NDIS_HANDLE MiniportAdapterHandle,
    [in, out] PNDIS_SG_DMA_DESCRIPTION DmaDescription,
    [out] PNDIS_HANDLE NdisMiniportDmaHandle
);

void NdisCmModifyCallQoSComplete(
    [in] NDIS_STATUS Status,
    [in] NDIS_HANDLE NdisVcHandle,
    [in] PCO_CALL_PARAMETERS CallParameters
);

void NdisCmOpenAddressFamilyComplete(
    [in] NDIS_STATUS Status,
    [in] NDIS_HANDLE NdisAfHandle,
    [in] NDIS_HANDLE CallMgrAfContext
);

void NdisFDeregisterFilterDriver(
    [in] NDIS_HANDLE NdisFilterDriverHandle
);

void NdisFreeMemoryWithTag(
    [in] IN PVOID VirtualAddress,
    [in] IN ULONG Tag
);

void NdisMSleep(
    [in] ULONG MicrosecondsToSleep
);

BOOLEAN NdisSetTimerObject(
    [in] NDIS_HANDLE TimerObject,
    [in] LARGE_INTEGER DueTime,
    [in, optional] LONG MillisecondsPeriod,
    [in, optional] PVOID FunctionContext
);

void NdisMPauseComplete(
    [in] NDIS_HANDLE MiniportAdapterHandle
);

void NdisFreeCloneOidRequest(
    [in] IN NDIS_HANDLE SourceHandle,
    [in] IN PNDIS_OID_REQUEST Request
);

NDIS_STATUS FILTER_SYNCHRONOUS_OID_REQUEST(
    NDIS_HANDLE FilterModuleContext,
    [in, out] NDIS_OID_REQUEST *OidRequest,
    [out] PVOID *CallContext
);

void NdisCloseConfiguration(
    [in] NDIS_HANDLE ConfigurationHandle
);

NDIS_STATUS NdisCoAssignInstanceName(
    [in] NDIS_HANDLE NdisVcHandle,
    [in] PNDIS_STRING BaseInstanceName,
    [out, optional] PNDIS_STRING VcInstanceName
);

NDIS_STATUS NdisMMapIoSpace(
    [out] PVOID *VirtualAddress,
    [in] NDIS_HANDLE MiniportAdapterHandle,
    [in] NDIS_PHYSICAL_ADDRESS PhysicalAddress,
    [in] UINT Length
);

NDIS_STATUS NdisMCmDeactivateVc(
    [in] NDIS_HANDLE NdisVcHandle
);

void NDIS_RAISE_IRQL_TO_DISPATCH(
    _pIrql_
);

NDIS_STATUS NdisCloseAdapterEx(
    [in] NDIS_HANDLE NdisBindingHandle
);

void NdisIMDeregisterLayeredMiniport(
    [in] NDIS_HANDLE DriverHandle
);

void NdisOpenAdapter(
    [out] PNDIS_STATUS Status,
    [out] PNDIS_STATUS OpenErrorStatus,
    [out] PNDIS_HANDLE NdisBindingHandle,
    [out] PUINT SelectedMediumIndex,
    [in] PNDIS_MEDIUM MediumArray,
    [in] UINT MediumArraySize,
    [in] NDIS_HANDLE NdisProtocolHandle,
    [in] NDIS_HANDLE ProtocolBindingContext,
    [in] PNDIS_STRING AdapterName,
    [in] UINT OpenOptions,
    [in, optional] PSTRING AddressingInformation
);

void NdisClNotifyCloseAddressFamilyComplete(
    [in] NDIS_HANDLE NdisAfHandle,
    [in] NDIS_STATUS Status
);

void NdisRawWritePortBufferUlong(
    [in] Port,
    [in] Buffer,
    [in] Length
);

void NdisInitAnsiString(
    _as,
    s
);

void NdisUnmapFile(
    [in] NDIS_HANDLE FileHandle
);

ULONG NdisMGetVirtualFunctionBusData(
    [in] NDIS_HANDLE NdisMiniportHandle,
    [in] NDIS_SRIOV_FUNCTION_ID VFId,
    [out] PVOID Buffer,
    [in] ULONG Offset,
    [in] ULONG Length
);

void NET_BUFFER_LIST_RECEIVE_FILTER_ID(
    _NBL
);

BOOLEAN NdisMSynchronizeWithInterruptEx(
    [in] NDIS_HANDLE NdisInterruptHandle,
    [in] ULONG MessageId,
    [in] MINIPORT_SYNCHRONIZE_INTERRUPT_HANDLER SynchronizeFunction,
    [in] PVOID SynchronizeFunction,
    [in] PVOID SynchronizeContext
);

void NdisInitializeEvent(
    [out] PNDIS_EVENT Event
);

NDIS_STATUS NdisClDropParty(
    [in] NDIS_HANDLE NdisPartyHandle,
    [in, optional] PVOID Buffer,
    [in, optional] UINT Size
);

void NdisAcquireReadWriteLock(
    [in, out] PNDIS_RW_LOCK Lock,
    [in] BOOLEAN fWrite,
    [_out_] PLOCK_STATE LockState
);

void NdisAcquireSpinLock(
    [in] _SpinLock
);

void NdisFSendNetBufferListsComplete(
    [in] NDIS_HANDLE NdisFilterHandle,
    PNET_BUFFER_LIST NetBufferList,
    [in] ULONG SendCompleteFlags
);

void NdisMFreeNetBufferSGList(
    [in] NDIS_HANDLE NdisMiniportDmaHandle,
    [in] PSCATTER_GATHER_LIST pSGL,
    [in] PNET_BUFFER NetBuffer
);

void NdisFreeIoWorkItem(
    [in] NDIS_HANDLE NdisIoWorkItemHandle
);

void NdisMCmModifyCallQoSComplete(
    _S_,
    _H_,
    _P_
);

void NdisMDeregisterIoPortRange(
    [in] NDIS_HANDLE MiniportAdapterHandle,
    [in] UINT InitialPort,
    [in] UINT NumberOfPorts,
    [in] PVOID PortOffset
);

NDIS_STATUS NdisIMNotifyPnPEvent(
    [in] NDIS_HANDLE MiniportHandle,
    [in] PNET_PNP_EVENT NetPnPEvent
);

CCHAR NdisSystemProcessorCount();

void NdisOpenProtocolConfiguration(
    [out] PNDIS_STATUS Status,
    [out] PNDIS_HANDLE ConfigurationHandle,
    [in] PCNDIS_STRING ProtocolSection
);

void NdisInitializeListHead(
    [in] _ListHead
);

void NdisMCmCloseAddressFamilyComplete(
    _S_,
    _H_
);

void NdisSetEvent(
    [in] PNDIS_EVENT Event
);

void NdisIfDeregisterInterface(
    NET_IFINDEX ifIndex
);

void NdisDeregisterProtocolDriver(
    [in] NDIS_HANDLE NdisProtocolHandle
);

void NdisFIndicateStatus(
    [in] NDIS_HANDLE NdisFilterHandle,
    [in] PNDIS_STATUS_INDICATION StatusIndication
);

void NdisDprReleaseSpinLock(
    [in] _SpinLock
);

void NdisCmAddPartyComplete(
    [in] NDIS_STATUS Status,
    [in] NDIS_HANDLE NdisPartyHandle,
    [in, optional] NDIS_HANDLE CallMgrPartyContext,
    [in] PCO_CALL_PARAMETERS CallParameters
);

void NdisEqualMemory(
    Source1,
    Source2,
    Length
);

void NdisCopyFromPacketToPacketSafe(
    [in] IN PNDIS_PACKET Destination,
    [in] IN UINT DestinationOffset,
    [in] IN UINT BytesToCopy,
    [in] IN PNDIS_PACKET Source,
    [in] IN UINT SourceOffset,
    [out] OUT PUINT BytesCopied,
    IN MM_PAGE_PRIORITY Priority
);

void NdisWriteRegisterUlong(
    [in] Register,
    [in] Data
);

ULONG NdisCurrentProcessorIndex();

void NdisMIndicateReceiveNetBufferLists(
    [in] NDIS_HANDLE MiniportAdapterHandle,
    PNET_BUFFER_LIST NetBufferList,
    [in] NDIS_PORT_NUMBER PortNumber,
    [in] ULONG NumberOfNetBufferLists,
    [in] ULONG ReceiveFlags
);

void NdisMFreeSharedMemory(
    [in] NDIS_HANDLE MiniportAdapterHandle,
    [in] ULONG Length,
    [in] BOOLEAN Cached,
    [in] PVOID VirtualAddress,
    [in] NDIS_PHYSICAL_ADDRESS PhysicalAddress
);

NDIS_STATUS NdisIfGetInterfaceIndexFromNetLuid(
    [in] NET_LUID NetLuid,
    [out] PNET_IFINDEX pIfIndex
);

void NDIS_LOWER_IRQL(
    _OldIrql_,
    _CurIrql_
);

void NdisMOidRequestComplete(
    [in] NDIS_HANDLE MiniportAdapterHandle,
    [in] PNDIS_OID_REQUEST OidRequest,
    [in] NDIS_STATUS Status
);

void NdisMIdleNotificationConfirm(
    [in] NDIS_HANDLE MiniportAdapterHandle,
    [in] NDIS_DEVICE_POWER_STATE IdlePowerState
);

NDIS_STATUS NdisClAddParty(
    [in] NDIS_HANDLE NdisVcHandle,
    [in] NDIS_HANDLE ProtocolPartyContext,
    [in, out] PCO_CALL_PARAMETERS CallParameters,
    [out] PNDIS_HANDLE NdisPartyHandle
);

NDIS_STATUS NdisIfRegisterProvider(
    [in] PNDIS_IF_PROVIDER_CHARACTERISTICS ProviderCharacteristics,
    [in] NDIS_HANDLE IfProviderContext,
    PNDIS_HANDLE pNdisIfProviderHandle
);

void NdisMInvalidateConfigBlock(
    [in] NDIS_HANDLE NdisMiniportHandle,
    [in] NDIS_SRIOV_FUNCTION_ID VFId,
    [in] ULONGLONG BlockMask
);

NDIS_STATUS NdisRegisterDeviceEx(
    [in] NDIS_HANDLE NdisHandle,
    [in] PNDIS_DEVICE_OBJECT_ATTRIBUTES DeviceObjectAttributes,
    [out] PDEVICE_OBJECT *pDeviceObject,
    [out] PNDIS_HANDLE NdisDeviceHandle
);

void NdisRawWritePortBufferUshort(
    [in] Port,
    [in] Buffer,
    [in] Length
);

NDIS_STATUS NdisMQueryAdapterInstanceName(
    PNDIS_STRING pAdapterInstanceName,
    NDIS_HANDLE MiniportHandle
);

void NdisCmDispatchIncomingCallQoSChange(
    [in] NDIS_HANDLE NdisVcHandle,
    [in] PCO_CALL_PARAMETERS CallParameters
);

void NdisFreeRWLock(
    [in] PNDIS_RW_LOCK_EX Lock
);

void NdisReadRegisterUshort(
    [in] Register,
    [out] Data
);

void NdisMCmNotifyCloseAddressFamily(
    _AH_
);

ULONG NdisGetSharedDataAlignment();

NDIS_STATUS NdisScheduleWorkItem(
    [in] __drv_aliasesMem PNDIS_WORK_ITEM WorkItem
);

void NdisMCoOidRequestComplete(
    [in] NDIS_HANDLE MiniportAdapterHandle,
    NDIS_HANDLE NdisMiniportVcHandle,
    PNDIS_OID_REQUEST Request,
    [in] NDIS_STATUS Status
);

PROCESSOR_NUMBER NdisCurrentGroupAndProcessor();

void NdisMCmRegisterSapComplete(
    _S_,
    _H_,
    _C_
);

void NdisInterlockedIncrement(
    [in] Addend
);

NDIS_STATUS NdisCoGetTapiCallId(
    [in] NDIS_HANDLE NdisVcHandle,
    [in, out] PVAR_STRING TapiCallId
);

void NdisMoveMemory(
    [out] Destination,
    [in] Source,
    [in] Length
);

void NdisUnicodeStringToAnsiString(
    _as,
    _us
);

void NdisCmDispatchIncomingCloseCall(
    [in] NDIS_STATUS CloseStatus,
    [in] NDIS_HANDLE NdisVcHandle,
    [in, optional] PVOID Buffer,
    [in] UINT Size
);

UCHAR NdisGeneratePartialCancelId();

void NdisGetPhysicalAddressHigh(
    [in] _PhysicalAddress
);

void NdisMResetComplete(
    NDIS_HANDLE MiniportAdapterHandle,
    NDIS_STATUS Status,
    BOOLEAN AddressingReset
);

NDIS_STATUS NdisGetRssProcessorInformation(
    [in] NDIS_HANDLE NdisHandle,
    [out, optional] PNDIS_RSS_PROCESSOR_INFO RssProcessorInfo,
    [in, out] PSIZE_T Size
);

NDIS_STATUS NdisMRegisterMiniportDriver(
    [in] PDRIVER_OBJECT DriverObject,
    [in] PUNICODE_STRING RegistryPath,
    [in, optional] NDIS_HANDLE MiniportDriverContext,
    [in] PNDIS_MINIPORT_DRIVER_CHARACTERISTICS MiniportDriverCharacteristics,
    [out] PNDIS_HANDLE NdisMiniportDriverHandle
);

void NDIS_NBL_GET_MEDIA_SPECIFIC_INFO(
    _NBL,
    _Tag,
    _MediaSpecificInfo
);

void NdisMCloseLog(
    [in] NDIS_HANDLE LogHandle
);

NDIS_STATUS NdisMSetMiniportAttributes(
    NDIS_HANDLE NdisMiniportHandle,
    [in] PNDIS_MINIPORT_ADAPTER_ATTRIBUTES MiniportAttributes
);

NDIS_STATUS NdisGetProcessorInformation(
    [in, out] PNDIS_SYSTEM_PROCESSOR_INFO SystemProcessorInfo
);

void NdisGetCurrentProcessorCounts(
    [out] PULONG pIdleCount,
    [out] PULONG pKernelAndUser,
    [out] PULONG pIndex
);

NDIS_STATUS NdisMAllocateNetBufferSGList(
    [in] NDIS_HANDLE NdisMiniportDmaHandle,
    [in] PNET_BUFFER NetBuffer,
    [in] PVOID Context,
    [in] ULONG Flags,
    [in, optional] PVOID ScatterGatherListBuffer,
    [in] ULONG ScatterGatherListBufferSize
);

void NdisOpenConfigurationKeyByIndex(
    [out] PNDIS_STATUS Status,
    [in] NDIS_HANDLE ConfigurationHandle,
    [in] ULONG Index,
    [out] PNDIS_STRING KeyName,
    [out] PNDIS_HANDLE KeyHandle
);

KAFFINITY NdisGroupActiveProcessorMask(
    USHORT Group
);

void NdisMCoActivateVcComplete(
    [in] NDIS_STATUS Status,
    [in] NDIS_HANDLE NdisVcHandle,
    [in] PCO_CALL_PARAMETERS CallParameters
);

void NdisMCoSendNetBufferListsComplete(
    [in] IN NDIS_HANDLE NdisVcHandle,
    [in] IN PNET_BUFFER_LIST NetBufferLists,
    [in] IN ULONG SendCompleteFlags
);

void NdisMDeregisterInterruptEx(
    [in] NDIS_HANDLE NdisInterruptHandle
);

void NdisMCmOidRequestComplete(
    _AH_,
    _VH_,
    _PH_,
    _R_,
    _S_
);

void NdisUnchainBufferAtBack(
    [in, out] IN OUT PNDIS_PACKET Packet,
    [out] OUT PNDIS_BUFFER *Buffer
);

void NdisInterlockedAddUlong(
    [in] _Addend,
    [in] _Increment,
    [in] _SpinLock
);

NDIS_STATUS NdisFRestartFilter(
    [in] NDIS_HANDLE NdisFilterHandle
);

void NdisAcquireRWLockWrite(
    [in] PNDIS_RW_LOCK_EX Lock,
    [out] PLOCK_STATE_EX LockState,
    [in] UCHAR Flags
);

void NdisMapFile(
    [out] PNDIS_STATUS Status,
    [out] PVOID *MappedBuffer,
    [in] NDIS_HANDLE FileHandle
);

void NdisDprReleaseReadWriteLock(
    [in, out] PNDIS_RW_LOCK Lock,
    PLOCK_STATE LockState
);

void NdisFSendNetBufferLists(
    [in] NDIS_HANDLE NdisFilterHandle,
    __drv_aliasesMem PNET_BUFFER_LIST NetBufferList,
    [in] NDIS_PORT_NUMBER PortNumber,
    [in] ULONG SendFlags
);

void NdisMDeregisterScatterGatherDma(
    [in] NDIS_HANDLE NdisMiniportDmaHandle
);

void NDIS_NBL_ADD_MEDIA_SPECIFIC_INFO(
    _NBL,
    _MediaSpecificInfo
);

void NdisFReturnNetBufferLists(
    [in] NDIS_HANDLE NdisFilterHandle,
    [in] PNET_BUFFER_LIST NetBufferLists,
    [in] ULONG ReturnFlags
);

void NdisMSetupDmaTransfer(
    _S,
    _H,
    _B,
    _O,
    _L,
    _M_
);

void NdisDprAcquireReadWriteLock(
    [in, out] PNDIS_RW_LOCK Lock,
    [in] BOOLEAN fWrite,
    [out] PLOCK_STATE LockState
);

void NdisMCompleteDmaTransfer(
    _S,
    _H,
    _B,
    _O,
    _L,
    _M_
);

void NdisInterlockedInsertTailList(
    [in] _ListHead,
    [in] _ListEntry,
    [in] _SpinLock
);

void NdisMCoDeactivateVcComplete(
    [in] NDIS_STATUS Status,
    [in] NDIS_HANDLE NdisVcHandle
);

NDIS_STATUS NdisGetHypervisorInfo(
    [in, out] PNDIS_HYPERVISOR_INFO HypervisorInfo
);

NDIS_STATUS NdisIMInitializeDeviceInstanceEx(
    [in] NDIS_HANDLE DriverHandle,
    [in] PNDIS_STRING DriverInstance,
    [in, optional] NDIS_HANDLE DeviceContext
);

NDIS_STATUS NdisIfAddIfStackEntry(
    [in] NET_IFINDEX HigherLayerIfIndex,
    [in] NET_IFINDEX LowerLayerIfIndex
);

void NdisInterlockedInsertHeadList(
    [in] _ListHead,
    [in] _ListEntry,
    [in] _SpinLock
);

void NdisMCmDropPartyComplete(
    _S_,
    _H_
);

void NdisCloseAdapter(
    [out] PNDIS_STATUS Status,
    [in] NDIS_HANDLE NdisBindingHandle
);

NDIS_STATUS NdisMEnableVirtualization(
    [in] NDIS_HANDLE NdisMiniportHandle,
    [in] USHORT NumVFs,
    [in] BOOLEAN EnableVFMigration,
    [in] BOOLEAN EnableMigrationInterrupt,
    [in] BOOLEAN EnableVirtualization
);

NDIS_STATUS NdisFDirectOidRequest(
    [in] NDIS_HANDLE NdisFilterHandle,
    [in] PNDIS_OID_REQUEST OidRequest
);

void NdisAllocateSpinLock(
    [out] PNDIS_SPIN_LOCK SpinLock
);

NDIS_STATUS NdisEnumerateFilterModules(
    [in] NDIS_HANDLE NdisHandle,
    [in] PVOID InterfaceBuffer,
    [in] ULONG InterfaceBufferLength,
    [in, out] PULONG BytesNeeded,
    [in, out] PULONG BytesWritten
);

NDIS_HANDLE NdisAllocateIoWorkItem(
    [in] NDIS_HANDLE NdisObjectHandle
);

NDIS_STATUS NdisClOpenAddressFamilyEx(
    [in] NDIS_HANDLE NdisBindingHandle,
    [in] PCO_ADDRESS_FAMILY AddressFamily,
    [in] NDIS_HANDLE ClientAfContext,
    [out] PNDIS_HANDLE NdisAfHandle
);

void FILTER_SYNCHRONOUS_OID_REQUEST_COMPLETE(
    [in] NDIS_HANDLE FilterModuleContext,
    [in, out] NDIS_OID_REQUEST *OidRequest,
    [in, out] NDIS_STATUS *Status,
    [in] PVOID CallContext
);

NDIS_STATUS NdisMWriteLogData(
    [in] NDIS_HANDLE LogHandle,
    [in] PVOID LogBuffer,
    [in] UINT LogBufferSize
);

void NDIS_MAKE_RID(
    _Segment,
    _Bus,
    _Function
);

void NdisCmCloseAddressFamilyComplete(
    [in] NDIS_STATUS Status,
    [in] NDIS_HANDLE NdisAfHandle
);

void NdisCmDeregisterSapComplete(
    [in] NDIS_STATUS Status,
    [in] NDIS_HANDLE NdisSapHandle
);

void NdisAllocateFromNPagedLookasideList(
    _L
);

BOOLEAN NdisCancelTimerObject(
    [in] NDIS_HANDLE TimerObject
);

PNDIS_GENERIC_OBJECT NdisAllocateGenericObject(
    [optional] PDRIVER_OBJECT DriverObject,
    ULONG Tag,
    USHORT Size
);

void NdisMCmCloseCallComplete(
    _S_,
    _VH_,
    _PH_
);

void NdisMCmDispatchIncomingDropParty(
    _S_,
    _H_,
    _B_,
    _Z_
);

NDIS_STATUS MINIPORT_SYNCHRONOUS_OID_REQUEST(
    [in] NDIS_HANDLE MiniportAdapterContext,
    [in] NDIS_OID_REQUEST *OidRequest
);

void NdisDeleteNPagedLookasideList(
    _L
);

void NdisMCoIndicateStatusEx(
    [in] NDIS_HANDLE MiniportAdapterHandle,
    [in, optional] NDIS_HANDLE NdisVcHandle,
    [in] PNDIS_STATUS_INDICATION StatusIndication
);

void NdisZeroMemory(
    [in] Destination,
    [in] Length
);

void NdisFreeSharedMemory(
    [in] NDIS_HANDLE NdisHandle,
    [in] NDIS_HANDLE AllocationHandle
);

NDIS_STATUS NdisClModifyCallQoS(
    [in] NDIS_HANDLE NdisVcHandle,
    [in] PCO_CALL_PARAMETERS CallParameters
);

void NdisDeregisterDeviceEx(
    [in] NDIS_HANDLE NdisDeviceHandle
);

void NdisRawReadPortBufferUchar(
    [in] Port,
    [out] Buffer,
    [in] Length
);

void NdisWriteRegisterUchar(
    [in] Register,
    [in] Data
);

void NdisMCmDispatchIncomingCall(
    _SH_,
    _VH_,
    _CP_
);

void NDIS_DECLARE_SWITCH_NET_BUFFER_LIST_CONTEXT_TYPE(
    _ContextName,
    _ExtensionId
);

ULONG NdisMSetBusData(
    IN NDIS_HANDLE NdisMiniportHandle,
    [in] IN ULONG WhichSpace,
    [in] IN ULONG Offset,
    [in] IN PVOID Buffer,
    [in] IN ULONG Length
);

void NdisReleaseReadWriteLock(
    [in, out] PNDIS_RW_LOCK Lock,
    [in] PLOCK_STATE LockState
);

void NDIS_SET_NET_BUFFER_LIST_CANCEL_ID(
    _NBL,
    _CancelId
);

PLIST_ENTRY NdisInterlockedRemoveHeadList(
    [in] _ListHead,
    [in] _SpinLock
);

NDIS_STATUS NdisMAllocatePort(
    NDIS_HANDLE NdisMiniportHandle,
    [in, out] PNDIS_PORT_CHARACTERISTICS PortCharacteristics
);

void NdisRawReadPortUchar(
    [in] Port,
    [out] Data
);

NDIS_STATUS NdisOidRequest(
    [in] NDIS_HANDLE NdisBindingHandle,
    [in] PNDIS_OID_REQUEST OidRequest
);

void NdisInitializeReadWriteLock(
    [out] PNDIS_RW_LOCK Lock
);

void NdisInitializeString(
    PNDIS_STRING Destination,
    PUCHAR Source
);

void NdisInterlockedPushEntrySList(
    SListHead,
    SListEntry,
    [in] Lock
);

void NdisRegisterProtocol(
    [out] PNDIS_STATUS Status,
    [out] PNDIS_HANDLE NdisProtocolHandle,
    [in] PNDIS_PROTOCOL_CHARACTERISTICS ProtocolCharacteristics,
    [in] UINT CharacteristicsLength
);

void NdisFRestartComplete(
    [in] NDIS_HANDLE NdisFilterHandle,
    [in] NDIS_STATUS Status
);

void NdisRawReadPortBufferUshort(
    [in] Port,
    [out] Buffer,
    [in] Length
);

void NdisDprAcquireSpinLock(
    [in] _SpinLock
);

void NET_BUFFER_LIST_RECEIVE_QUEUE_ID(
    _NBL
);

void NdisFCancelOidRequest(
    [in] NDIS_HANDLE NdisFilterHandle,
    [in] PVOID RequestId
);

void NdisOpenFile(
    [out] PNDIS_STATUS Status,
    [out] PNDIS_HANDLE FileHandle,
    [out] PUINT FileLength,
    [in] PNDIS_STRING FileName,
    [in] NDIS_PHYSICAL_ADDRESS HighestAcceptableAddress
);

void NdisInitializeNPagedLookasideList(
    [in] PNPAGED_LOOKASIDE_LIST Lookaside,
    [in, optional] PALLOCATE_FUNCTION Allocate,
    [in, optional] PFREE_FUNCTION Free,
    [in] ULONG Flags,
    [in] SIZE_T Size,
    [in] ULONG Tag,
    [in] USHORT Depth
);

