PORTCLASSAPI NTSTATUS PcUnregisterAdapterPowerManagement(
    [in] PDEVICE_OBJECT pDeviceObject
);

PORTCLASSAPI NTSTATUS PcRegisterPhysicalConnectionFromExternal(
    [in] PDEVICE_OBJECT DeviceObject,
    [in] PUNICODE_STRING FromString,
    [in] ULONG FromPin,
    [in] PUNKNOWN ToUnknown,
    [in] ULONG ToPin
);

PORTCLASSAPI NTSTATUS PcCompletePendingPropertyRequest(
    [in] PPCPROPERTY_REQUEST PropertyRequest,
    [in] NTSTATUS NtStatus
);

PORTCLASSAPI NTSTATUS PcRequestNewPowerState(
    [in] PDEVICE_OBJECT pDeviceObject,
    [in] DEVICE_POWER_STATE RequestedNewState
);

PORTCLASSAPI NTSTATUS PcUnregisterAdapterPnpManagement(
    [in] PDEVICE_OBJECT DeviceObject
);

PORTCLASSAPI NTSTATUS PcAddContentHandlers(
    [in] ULONG ContentId,
    [in] PVOID *paHandlers,
    [in] ULONG NumHandlers
);

PORTCLASSAPI NTSTATUS PcRegisterSubdevice(
    [in] PDEVICE_OBJECT DeviceObject,
    [in] PWSTR Name,
    [in] PUNKNOWN Unknown
);

PORTCLASSAPI NTSTATUS PcForwardContentToDeviceObject(
    [in] ULONG ContentId,
    [in, optional] PVOID Reserved,
    [in] PCDRMFORWARD DrmForward
);

PORTCLASSAPI NTSTATUS PcNewServiceGroup(
    [out] PSERVICEGROUP *OutServiceGroup,
    [in, optional] PUNKNOWN OuterUnknown
);

PORTCLASSAPI NTSTATUS PcRegisterPhysicalConnectionToExternal(
    [in] PDEVICE_OBJECT DeviceObject,
    [in] PUNKNOWN FromUnknown,
    [in] ULONG FromPin,
    [in] PUNICODE_STRING ToString,
    [in] ULONG ToPin
);

PORTCLASSAPI NTSTATUS PcForwardIrpSynchronous(
    [in] PDEVICE_OBJECT DeviceObject,
    [in] PIRP Irp
);

PORTCLASSAPI NTSTATUS PcForwardContentToFileObject(
    [in] ULONG ContentId,
    [in] PFILE_OBJECT FileObject
);

PORTCLASSAPI NTSTATUS PcForwardContentToInterface(
    [in] ULONG ContentId,
    [in] PUNKNOWN pUnknown,
    [in] ULONG NumMethods
);

PORTCLASSAPI NTSTATUS PcRegisterPhysicalConnection(
    [in] PDEVICE_OBJECT DeviceObject,
    [in] PUNKNOWN FromUnknown,
    [in] ULONG FromPin,
    [in] PUNKNOWN ToUnknown,
    [in] ULONG ToPin
);

PORTCLASSAPI NTSTATUS PcNewMiniport(
    [out] PMINIPORT *OutMiniPort,
    [in] REFCLSID ClassID
);

PORTCLASSAPI NTSTATUS PcUnregisterIoTimeout(
    [in] PDEVICE_OBJECT pDeviceObject,
    [in] PIO_TIMER_ROUTINE pTimerRoutine,
    [in] PVOID pContext
);

PORTCLASSAPI NTSTATUS PcDestroyContent(
    [in] ULONG ContentId
);

PORTCLASSAPI NTSTATUS PcNewPort(
    [out] PPORT *OutPort,
    [in] REFCLSID ClassID
);

PORTCLASSAPI NTSTATUS PcAddAdapterDevice(
    [in] PDRIVER_OBJECT DriverObject,
    [in] PDEVICE_OBJECT PhysicalDeviceObject,
    [in] PCPFNSTARTDEVICE StartDevice,
    [in] ULONG MaxObjects,
    [in] ULONG DeviceExtensionSize
);

PORTCLASSAPI NTSTATUS PcAddStreamResource(
    [in] PDEVICE_OBJECT PhysicalDeviceObject,
    [in] PVOID ResourceSet,
    [in] PPCSTREAMRESOURCE_DESCRIPTOR ResourceDescriptor,
    [out] PCSTREAMRESOURCE *ResourceHandle
);

PORTCLASSAPI NTSTATUS PcRemoveStreamResource(
    [in] PCSTREAMRESOURCE ResourceHandle
);

PORTCLASSAPI NTSTATUS PcGetContentRights(
    [in] ULONG ContentId,
    [out] PDRMRIGHTS DrmRights
);

PORTCLASSAPI NTSTATUS PcNewInterruptSync(
    [out] PINTERRUPTSYNC *OutInterruptSync,
    [in, optional] PUNKNOWN OuterUnknown,
    [in] PRESOURCELIST ResourceList,
    [in] ULONG ResourceIndex,
    [in] INTERRUPTSYNCMODE Mode
);

PORTCLASSAPI NTSTATUS PcRegisterIoTimeout(
    [in] PDEVICE_OBJECT pDeviceObject,
    [in] PIO_TIMER_ROUTINE pTimerRoutine,
    [in] PVOID pContext
);

PORTCLASSAPI NTSTATUS PcCompleteIrp(
    [in] PDEVICE_OBJECT pDeviceObject,
    [in] PIRP pIrp,
    [in] NTSTATUS ntStatus
);

PORTCLASSAPI NTSTATUS PcDispatchIrp(
    [in] PDEVICE_OBJECT pDeviceObject,
    [in] PIRP pIrp
);

PORTCLASSAPI NTSTATUS PcNewDmaChannel(
    [out] PDMACHANNEL *OutDmaChannel,
    [in, optional] PUNKNOWN OuterUnknown,
    [in] POOL_TYPE PoolType,
    [in] PDEVICE_DESCRIPTION DeviceDescription,
    [in] PDEVICE_OBJECT DeviceObject
);

PORTCLASSAPI NTSTATUS PcNewRegistryKey(
    [out] PREGISTRYKEY *OutRegistryKey,
    [in, optional] PUNKNOWN OuterUnknown,
    [in] ULONG RegistryKeyType,
    [in] ACCESS_MASK DesiredAccess,
    [in, optional] PVOID DeviceObject,
    [in, optional] PVOID SubDevice,
    [in, optional] POBJECT_ATTRIBUTES ObjectAttributes,
    [in, optional] ULONG CreateOptions,
    [out, optional] PULONG Disposition
);

PORTCLASSAPI NTSTATUS PcNewResourceSublist(
    [out] PRESOURCELIST *OutResourceList,
    [in, optional] PUNKNOWN OuterUnknown,
    [in] POOL_TYPE PoolType,
    [in] PRESOURCELIST ParentList,
    [in] ULONG MaximumEntries
);

PORTCLASSAPI NTSTATUS PcRegisterAdapterPnpManagement(
    PUNKNOWN Unknown,
    [in] PDEVICE_OBJECT DeviceObject
);

PORTCLASSAPI ULONGLONG PcGetTimeInterval(
    [in] ULONGLONG Since
);

PORTCLASSAPI NTSTATUS PcNewResourceList(
    [out] PRESOURCELIST *OutResourceList,
    [in, optional] PUNKNOWN OuterUnknown,
    [in] POOL_TYPE PoolType,
    [in] PCM_RESOURCE_LIST TranslatedResources,
    [in] PCM_RESOURCE_LIST UntranslatedResources
);

PORTCLASSAPI NTSTATUS PcCreateContentMixed(
    [in] PULONG paContentId,
    [in] ULONG cContentId,
    [out] PULONG pMixedContentId
);

PORTCLASSAPI NTSTATUS PcRegisterAdapterPowerManagement(
    PUNKNOWN Unknown,
    [in] PVOID pvContext1
);

PORTCLASSAPI NTSTATUS PcGetPhysicalDeviceObject(
    [in] IN PDEVICE_OBJECT pDeviceObject,
    [out] OUT PDEVICE_OBJECT *ppPhysicalObject
);

PORTCLASSAPI NTSTATUS PcGetDeviceProperty(
    [in] PVOID DeviceObject,
    [in] DEVICE_REGISTRY_PROPERTY DeviceProperty,
    [in] ULONG BufferLength,
    [out] PVOID PropertyBuffer,
    [out] PULONG ResultLength
);

PORTCLASSAPI NTSTATUS PcInitializeAdapterDriver(
    [in] PDRIVER_OBJECT DriverObject,
    [in] PUNICODE_STRING RegistryPathName,
    [in] PDRIVER_ADD_DEVICE AddDevice
);

