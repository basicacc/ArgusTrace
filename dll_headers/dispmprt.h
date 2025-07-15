VP_STATUS DlSetRegistryParameters(
    PVOID DeviceHandle,
    PWSTR ValueName,
    PVOID ValueData,
    ULONG ValueLength
);

VP_STATUS DlSetTrappedEmulatorPorts(
    PVOID DeviceHandle,
    ULONG NumAccessRanges,
    PVIDEO_ACCESS_RANGE AccessRange
);

VP_STATUS DlEnableInterrupt(
    PVOID DeviceHandle
);

void _IRQL_requires_DXGK_(
    param
);

PVOID DlGetAssociatedDeviceExtension(
    PVOID DeviceObject
);

void DlFreeDeviceBase(
    IN PVOID DeviceHandle,
    IN PVOID MappedAddress
);

void DlFreePool(
    IN PVOID DeviceHandle,
    IN PVOID Ptr
);

VP_STATUS DlEnumerateChildren(
    PVOID DeviceHandle,
    PVOID Reserved
);

BOOLEAN DlScanRom(
    PVOID DeviceHandle,
    PUCHAR RomBase,
    ULONG RomLength,
    PUCHAR String
);

PVOID DlAllocateCommonBuffer(
    IN PVOID DeviceHandle,
    IN PVP_DMA_ADAPTER DlpDmaAdapter,
    IN ULONG DesiredLength,
    OUT PPHYSICAL_ADDRESS LogicalAddress,
    IN BOOLEAN CacheEnabled,
    OUT PVOID Reserved
);

void DlUnlockBuffer(
    IN PVOID DeviceHandle,
    IN PVOID Mdl
);

void DlClearEvent(
    PVOID DeviceHandle,
    PEVENT pEvent
);

void DlReleaseCommonBuffer(
    IN PVOID DeviceHandle,
    IN PVP_DMA_ADAPTER DlpDmaAdapter,
    IN ULONG Length,
    IN PHYSICAL_ADDRESS LogicalAddress,
    IN PVOID VirtualAddress,
    IN BOOLEAN CacheEnabled
);

VP_STATUS DlGetVersion(
    PVOID DeviceHandle,
    PVPOSVERSIONINFO pDlpOsVersionInfo
);

ULONG DlSetBusData(
    PVOID DeviceHandle,
    ULONG BusDataType,
    ULONG SlotNumber,
    PVOID Buffer,
    ULONG Offset,
    ULONG Length
);

VP_STATUS DlDisableInterrupt(
    PVOID DeviceHandle
);

NTSTATUS DlEvalAcpiMethod(
    HANDLE DeviceHandle,
    ULONG DeviceUid,
    PACPI_EVAL_INPUT_BUFFER_COMPLEX AcpiInputBuffer,
    ULONG AcpiInputSize,
    PACPI_EVAL_OUTPUT_BUFFER AcpiOutputBuffer,
    ULONG AcpiOutputSize
);

BOOLEAN DlSynchronizeExecution(
    PVOID DeviceHandle,
    VIDEO_SYNCHRONIZE_PRIORITY Priority,
    PMINIPORT_SYNCHRONIZE_ROUTINE SynchronizeRoutine,
    PVOID Context,
    ULONG MessageNumber
);

VP_STATUS DlMapMemory(
    IN PVOID DeviceHandle,
    IN PHYSICAL_ADDRESS TranslatedAddress,
    IN OUT PULONG Length,
    IN PULONG InIoSpace,
    IN OUT PVOID *VirtualAddress
);

PVP_DMA_ADAPTER DlGetDmaAdapter(
    PVOID DeviceHandle,
    PVP_DEVICE_DESCRIPTION DlpDeviceDescription
);

NTSTATUS DlGetDeviceInformation(
    PVOID DeviceHandle,
    PDXGK_DEVICE_INFO DeviceInfo
);

PVOID DlGetDeviceBase(
    PVOID DeviceHandle,
    PHYSICAL_ADDRESS IoAddress,
    ULONG NumberOfUchars,
    UCHAR InIoSpace
);

VP_STATUS DlGetRegistryParameters(
    PVOID DeviceHandle,
    PWSTR ParameterName,
    UCHAR IsParameterFileName,
    PMINIPORT_GET_REGISTRY_ROUTINE CallbackRoutine,
    PVOID Context
);

NTSTATUS DxgkInitialize(
    [in] PDRIVER_OBJECT DriverObject,
    [in] PUNICODE_STRING RegistryPath,
    [in] PDRIVER_INITIALIZATION_DATA DriverInitializationData
);

VP_STATUS DlDeleteEvent(
    IN PVOID DeviceHandle,
    IN PEVENT pEvent
);

NTSTATUS DlMapMemoryEx(
    IN PVOID DeviceHandle,
    IN PHYSICAL_ADDRESS TranslatedAddress,
    IN OUT PULONG Length,
    IN PULONG InIoSpace,
    IN HANDLE ProcessHandle,
    IN OUT PVOID *VirtualAddress,
    IN BOOLEAN MapToUserMode
);

void DlDebugPrint(
    DEBUG_LEVEL DebugPrintLevel,
    PSTR DebugMessage,
    ...
);

NTSTATUS DlUnmapMemory(
    PVOID DeviceHandle,
    PVOID VirtualAddress,
    HANDLE ProcessHandle
);

LONG DlSetEvent(
    PVOID DeviceHandle,
    PEVENT pEvent
);

NTSTATUS DlGetAccessRanges(
    PVOID DeviceHandle,
    ULONG NumRequestedResources,
    PIO_RESOURCE_DESCRIPTOR RequestedResources,
    ULONG NumAccessRanges,
    PVIDEO_ACCESS_RANGE AccessRanges,
    PVOID VendorId,
    PVOID DeviceId,
    PULONG Slot
);

ULONG DlReadDeviceSpace(
    PVOID DeviceHandle,
    ULONG DataType,
    ULONG SlotNumber,
    PVOID Buffer,
    ULONG Offset,
    ULONG Length
);

NTSTATUS DxgkInitializeDisplayOnlyDriver(
    [in] PDRIVER_OBJECT DriverObject,
    [in] PUNICODE_STRING RegistryPath,
    [in] PKMDDOD_INITIALIZATION_DATA KmdDodInitializationData
);

void _Function_class_DXGK_(
    param
);

NTSTATUS DlIndicateChildStatus(
    PVOID DeviceHandle,
    PDXGK_CHILD_STATUS ChildStatus
);

NTSTATUS DlQueryServices(
    PVOID DeviceHandle,
    VIDEO_PORT_SERVICES ServicesType,
    PINTERFACE Interface
);

void DlStopTimer(
    PVOID DeviceHandle
);

NTSTATUS DxgkUnInitialize(
    PDRIVER_OBJECT DriverObject
);

PVOID DlGetRomImage(
    PVOID DeviceHandle,
    PVOID Unused1,
    ULONG Unused2,
    ULONG Length
);

PVOID DlLockBuffer(
    PVOID DeviceHandle,
    PVOID BaseAddress,
    ULONG Length,
    VP_LOCK_OPERATION Operation
);

VP_STATUS DlWaitForSingleObject(
    PVOID DeviceHandle,
    PVOID pEvent,
    PLARGE_INTEGER Timeout
);

void DlLogError(
    PVOID DeviceHandle,
    PVIDEO_REQUEST_PACKET Vrp,
    VP_STATUS ErrorCode,
    ULONG UniqueId
);

LONGLONG DlQueryPerformanceCounter(
    PVOID pDeviceHandle,
    PLONGLONG pllPerformanceFrequency
);

VP_STATUS DlCreateEvent(
    IN PVOID DeviceHandle,
    IN ULONG EventFlag,
    PVOID Unused,
    OUT PEVENT *ppEvent
);

BOOLEAN DlQueueDpc(
    PVOID DeviceHandle
);

void _Field_size_bytes_DXGK_(
    param
);

VP_STATUS DlVerifyAccessRanges(
    PVOID DeviceHandle,
    ULONG NumAccessRanges,
    PVIDEO_ACCESS_RANGE AccessRanges
);

PVOID DlAllocatePool(
    IN PVOID DeviceHandle,
    IN VP_POOL_TYPE PoolType,
    IN SIZE_T NumberOfBytes,
    IN ULONG Tag
);

void DlDebugPrintEx(
    arg
);

