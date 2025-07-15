ULONG WdfDevStateNormalize(
    [in] ULONG State
);

void WdfDeviceRemoveRemovalRelationsPhysicalDevice(
    [in] WDFDEVICE Device,
    [in] PDEVICE_OBJECT PhysicalDevice
);

NTSTATUS WdfDeviceQueryInterfaceProperty(
    [in] WDFDEVICE Device,
    [in] PWDF_DEVICE_INTERFACE_PROPERTY_DATA PropertyData,
    [in] ULONG BufferLength,
    [out] PVOID PropertyBuffer,
    [out] PULONG ResultLength,
    [out] PDEVPROPTYPE Type
);

void WdfDeviceSetStaticStopRemove(
    [in] WDFDEVICE Device,
    [in] BOOLEAN Stoppable
);

void WDF_DEVICE_POWER_CAPABILITIES_INIT(
    [out] PWDF_DEVICE_POWER_CAPABILITIES Caps
);

void WDF_DEVICE_POWER_POLICY_IDLE_SETTINGS_INIT(
    [out] PWDF_DEVICE_POWER_POLICY_IDLE_SETTINGS Settings,
    [in] WDF_POWER_POLICY_S0_IDLE_CAPABILITIES IdleCaps
);

NTSTATUS WdfDeviceAssignInterfaceProperty(
    [in] WDFDEVICE Device,
    [in] PWDF_DEVICE_INTERFACE_PROPERTY_DATA PropertyData,
    [in] DEVPROPTYPE Type,
    [in] ULONG BufferLength,
    [in, optional] PVOID PropertyBuffer
);

NTSTATUS WdfDeviceMapIoSpace(
    [in] WDFDEVICE Device,
    [in] PHYSICAL_ADDRESS PhysicalAddress,
    [in] SIZE_T NumberOfBytes,
    [in] MEMORY_CACHING_TYPE CacheType,
    [out] PVOID *PseudoBaseAddress
);

void WdfDeviceInitSetPowerPolicyEventCallbacks(
    [in] PWDFDEVICE_INIT DeviceInit,
    [in] PWDF_POWER_POLICY_EVENT_CALLBACKS PowerPolicyEventCallbacks
);

void WdfDeviceUnmapIoSpace(
    [in] WDFDEVICE Device,
    [in] PVOID PseudoBaseAddress,
    [in] SIZE_T NumberOfBytes
);

NTSTATUS WdfDevicePostEvent(
    [in] WDFDEVICE Device,
    [in] REFGUID EventGuid,
    [in] WDF_EVENT_TYPE WdfEventType,
    [in] BYTE *Data,
    [in] ULONG DataSizeCb
);

void WdfDeviceInitSetExclusive(
    [in] PWDFDEVICE_INIT DeviceInit,
    [in] BOOLEAN IsExclusive
);

WDF_DEVICE_POWER_POLICY_STATE WdfDeviceGetDevicePowerPolicyState(
    [in] WDFDEVICE Device
);

void WdfDeviceInitSetCharacteristics(
    [in] PWDFDEVICE_INIT DeviceInit,
    [in] ULONG DeviceCharacteristics,
    [in] BOOLEAN OrInValues
);

NTSTATUS WdfDeviceAllocAndQueryProperty(
    [in] WDFDEVICE Device,
    [in] DEVICE_REGISTRY_PROPERTY DeviceProperty,
    [in] POOL_TYPE PoolType,
    [in, optional] PWDF_OBJECT_ATTRIBUTES PropertyMemoryAttributes,
    [out] WDFMEMORY *PropertyMemory
);

void WdfDeviceSetPnpCapabilities(
    [in] WDFDEVICE Device,
    [in] PWDF_DEVICE_PNP_CAPABILITIES PnpCapabilities
);

void WDF_DEVICE_STATE_INIT(
    [out] PWDF_DEVICE_STATE PnpDeviceState
);

void WdfDeviceInitSetFileObjectConfig(
    [in] PWDFDEVICE_INIT DeviceInit,
    [in] PWDF_FILEOBJECT_CONFIG FileObjectConfig,
    [in, optional] PWDF_OBJECT_ATTRIBUTES FileObjectAttributes
);

NTSTATUS WdfDeviceAssignProperty(
    [in] WDFDEVICE Device,
    [in] PWDF_DEVICE_PROPERTY_DATA DeviceProperty,
    [in] DEVPROPTYPE Type,
    [in] ULONG Size,
    [in, optional] PVOID Data
);

NTSTATUS WdfDeviceInitRegisterPnpStateChangeCallback(
    [in] PWDFDEVICE_INIT DeviceInit,
    [in] WDF_DEVICE_PNP_STATE PnpState,
    [in] PFN_WDF_DEVICE_PNP_STATE_CHANGE_NOTIFICATION EvtDevicePnpStateChange,
    [in] ULONG CallbackTypes
);

void WDF_REMOVE_LOCK_OPTIONS_INIT(
    [out] PWDF_REMOVE_LOCK_OPTIONS RemoveLockOptions,
    [in] ULONG Flags
);

void WdfDeviceInitSetPowerPageable(
    [in] PWDFDEVICE_INIT DeviceInit
);

NTSTATUS WdfDeviceInitAssignWdmIrpPreprocessCallback(
    [in] PWDFDEVICE_INIT DeviceInit,
    [in] PFN_WDFDEVICE_WDM_IRP_PREPROCESS EvtDeviceWdmIrpPreprocess,
    [in] UCHAR MajorFunction,
    [in, optional] PUCHAR MinorFunctions,
    [in] ULONG NumMinorFunctions
);

void WDF_POWER_FRAMEWORK_SETTINGS_INIT(
    [out] PWDF_POWER_FRAMEWORK_SETTINGS PowerFrameworkSettings
);

ULONG WdfDeviceGetCharacteristics(
    [in] WDFDEVICE Device
);

void WdfDeviceRemoveDependentUsageDeviceObject(
    [in] WDFDEVICE Device,
    [in] PDEVICE_OBJECT DependentDevice
);

void WdfDeviceInitSetIoTypeEx(
    [in] PWDFDEVICE_INIT DeviceInit,
    [in] PWDF_IO_TYPE_CONFIG IoTypeConfig
);

POWER_ACTION WdfDeviceGetSystemPowerAction(
    [in] WDFDEVICE Device
);

void WDF_DEVICE_PNP_CAPABILITIES_INIT(
    [out] PWDF_DEVICE_PNP_CAPABILITIES Caps
);

NTSTATUS WdfDeviceWdmDispatchIrp(
    [in] WDFDEVICE Device,
    [in] PIRP Irp,
    [in] WDFCONTEXT DispatchContext
);

NTSTATUS WdfDeviceQueryProperty(
    [in] WDFDEVICE Device,
    [in] DEVICE_REGISTRY_PROPERTY DeviceProperty,
    [in] ULONG BufferLength,
    [out] PVOID PropertyBuffer,
    [out] PULONG ResultLength
);

NTSTATUS WdfDeviceInitAssignName(
    [in] PWDFDEVICE_INIT DeviceInit,
    [in, optional] PCUNICODE_STRING DeviceName
);

void WdfDeviceClearRemovalRelationsDevices(
    [in] WDFDEVICE Device
);

NTSTATUS WdfDeviceAssignS0IdleSettings(
    [in] WDFDEVICE Device,
    [in] PWDF_DEVICE_POWER_POLICY_IDLE_SETTINGS Settings
);

NTSTATUS WdfDeviceAssignMofResourceName(
    [in] WDFDEVICE Device,
    [in] PCUNICODE_STRING MofResourceName
);

NTSTATUS WdfDeviceAllocAndQueryPropertyEx(
    [in] WDFDEVICE Device,
    [in] PWDF_DEVICE_PROPERTY_DATA DeviceProperty,
    [in] POOL_TYPE PoolType,
    [in, optional] PWDF_OBJECT_ATTRIBUTES PropertyMemoryAttributes,
    [out] WDFMEMORY *PropertyMemory,
    [out] PDEVPROPTYPE Type
);

void WdfDeviceSetAlignmentRequirement(
    [in] WDFDEVICE Device,
    [in] ULONG AlignmentRequirement
);

BOOLEAN WdfDevStateIsNP(
    [in] ULONG State
);

NTSTATUS WdfDeviceQueryPropertyEx(
    [in] WDFDEVICE Device,
    [in] PWDF_DEVICE_PROPERTY_DATA DeviceProperty,
    [in] ULONG BufferLength,
    [out] PVOID PropertyBuffer,
    [out] PULONG RequiredSize,
    [out] PDEVPROPTYPE Type
);

void WdfDeviceInitSetPowerInrush(
    [in] PWDFDEVICE_INIT DeviceInit
);

void WDF_DEVICE_PROPERTY_DATA_INIT(
    [in] PWDF_DEVICE_PROPERTY_DATA PropertyData,
    [in] const DEVPROPKEY *PropertyKey
);

NTSTATUS WdfDeviceAddDependentUsageDeviceObject(
    [in] WDFDEVICE Device,
    [in] PDEVICE_OBJECT DependentDevice
);

void WdfDeviceInitSetDeviceType(
    [in] PWDFDEVICE_INIT DeviceInit,
    [in] DEVICE_TYPE DeviceType
);

void WdfDeviceInitSetPowerPolicyOwnership(
    [in] PWDFDEVICE_INIT DeviceInit,
    [in] BOOLEAN IsPowerPolicyOwner
);

void WdfDeviceSetDeviceInterfaceState(
    [in] WDFDEVICE Device,
    [in] const GUID *InterfaceClassGUID,
    [in, optional] PCUNICODE_STRING ReferenceString,
    [in] BOOLEAN IsInterfaceEnabled
);

void WdfDeviceInitSetReleaseHardwareOrderOnFailure(
    [in] PWDFDEVICE_INIT DeviceInit,
    [in] WDF_RELEASE_HARDWARE_ORDER_ON_FAILURE ReleaseHardwareOrderOnFailure
);

PDEVICE_OBJECT WdfDeviceWdmGetPhysicalDevice(
    [in] WDFDEVICE Device
);

NTSTATUS WdfDeviceCreateDeviceInterface(
    [in] WDFDEVICE Device,
    [in] const GUID *InterfaceClassGUID,
    [in, optional] PCUNICODE_STRING ReferenceString
);

ULONG WdfDeviceGetAlignmentRequirement(
    [in] WDFDEVICE Device
);

NTSTATUS WdfDeviceCreateSymbolicLink(
    [in] WDFDEVICE Device,
    [in] PCUNICODE_STRING SymbolicLinkName
);

PDEVICE_OBJECT WdfDeviceWdmGetAttachedDevice(
    [in] WDFDEVICE Device
);

PVOID WdfDeviceGetHardwareRegisterMappedAddress(
    [in] WDFDEVICE Device,
    [in] PVOID PseudoBaseAddress
);

NTSTATUS WdfDeviceEnqueueRequest(
    [in] WDFDEVICE Device,
    [in] WDFREQUEST Request
);

NTSTATUS WdfDeviceOpenRegistryKey(
    [in] WDFDEVICE Device,
    [in] ULONG DeviceInstanceKeyType,
    [in] ACCESS_MASK DesiredAccess,
    [in, optional] PWDF_OBJECT_ATTRIBUTES KeyAttributes,
    [out] WDFKEY *Key
);

NTSTATUS WdfDeviceStopIdle(
    _In_ WDFDEVICE Device,
    _In_ BOOLEAN WaitForD0
);

NTSTATUS WdfDeviceWdmDispatchIrpToIoQueue(
    [in] WDFDEVICE Device,
    [in] PIRP Irp,
    [in] WDFQUEUE Queue,
    [in] ULONG Flags
);

NTSTATUS WdfDeviceWdmDispatchPreprocessedIrp(
    [in] WDFDEVICE Device,
    [in] PIRP Irp
);

void WdfDeviceResumeIdle(
    [in] Device
);

void WdfDeviceInitSetPowerNotPageable(
    [in] PWDFDEVICE_INIT DeviceInit
);

void WdfDeviceGetDeviceStackIoType(
    [in] WDFDEVICE Device,
    [out] WDF_DEVICE_IO_TYPE *ReadWriteIoType,
    [out] WDF_DEVICE_IO_TYPE *IoControlIoType
);

NTSTATUS WdfDeviceRetrieveDeviceName(
    [in] WDFDEVICE Device,
    [in] WDFSTRING String
);

NTSTATUS WdfDeviceOpenDevicemapKey(
    [in] WDFDEVICE Device,
    [in] PCUNICODE_STRING KeyName,
    [in] ACCESS_MASK DesiredAccess,
    [in, optional] PWDF_OBJECT_ATTRIBUTES KeyAttributes,
    [out] WDFKEY *Key
);

void WdfDeviceSetBusInformationForChildren(
    [in] WDFDEVICE Device,
    [in] PPNP_BUS_INFORMATION BusInformation
);

void WdfDeviceSetPowerCapabilities(
    [in] WDFDEVICE Device,
    [in] PWDF_DEVICE_POWER_CAPABILITIES PowerCapabilities
);

void WdfDeviceSetDeviceInterfaceStateEx(
    WDFDEVICE Device,
    const GUID *InterfaceClassGUID,
    PCUNICODE_STRING ReferenceString,
    BOOLEAN IsInterfaceEnabled
);

WDFIOTARGET WdfDeviceGetIoTarget(
    [in] WDFDEVICE Device
);

void WdfDeviceInitSetDeviceClass(
    [in] PWDFDEVICE_INIT DeviceInit,
    [in] const GUID *DeviceClassGuid
);

NTSTATUS WdfDeviceCreate(
    [in, out] PWDFDEVICE_INIT *DeviceInit,
    [in, optional] PWDF_OBJECT_ATTRIBUTES DeviceAttributes,
    [out] WDFDEVICE *Device
);

WDFQUEUE WdfDeviceGetDefaultQueue(
    [in] WDFDEVICE Device
);

void WdfDeviceInitSetIoType(
    [in] PWDFDEVICE_INIT DeviceInit,
    [in] WDF_DEVICE_IO_TYPE IoType
);

void WDF_FILEOBJECT_CONFIG_INIT(
    [out] PWDF_FILEOBJECT_CONFIG FileEventCallbacks,
    [in, optional] PFN_WDF_DEVICE_FILE_CREATE EvtDeviceFileCreate,
    [in, optional] PFN_WDF_FILE_CLOSE EvtFileClose,
    [in, optional] PFN_WDF_FILE_CLEANUP EvtFileCleanup
);

WDF_DEVICE_POWER_STATE WdfDeviceGetDevicePowerState(
    [in] WDFDEVICE Device
);

WDFDEVICE WdfWdmDeviceGetWdfDeviceHandle(
    [in] PDEVICE_OBJECT DeviceObject
);

void WdfDeviceResumeIdleWithTag(
    [in] Device,
    [in] Tag
);

WDFFILEOBJECT WdfDeviceGetFileObject(
    [in] WDFDEVICE Device,
    [in] PFILE_OBJECT FileObject
);

NTSTATUS WdfDeviceRetrieveDeviceDirectoryString(
    [_In_] WDFDEVICE Device,
    [_In_] WDFSTRING String
);

PDEVICE_OBJECT WdfDeviceWdmGetDeviceObject(
    WDFDEVICE Device
);

NTSTATUS WdfDeviceInitAssignSDDLString(
    [in] PWDFDEVICE_INIT DeviceInit,
    [in, optional] PCUNICODE_STRING SDDLString
);

void WdfDeviceInitFree(
    [in] PWDFDEVICE_INIT DeviceInit
);

NTSTATUS WdfDeviceConfigureWdmIrpDispatchCallback(
    [in] WDFDEVICE Device,
    [in, optional] WDFDRIVER Driver,
    [in] UCHAR MajorFunction,
    PFN_WDFDEVICE_WDM_IRP_DISPATCH EvtDeviceWdmIrpDispatch,
    [in, optional] WDFCONTEXT DriverContext
);

NTSTATUS WdfDeviceAssignSxWakeSettings(
    [in] WDFDEVICE Device,
    [in] PWDF_DEVICE_POWER_POLICY_WAKE_SETTINGS Settings
);

void WdfDeviceSetDeviceState(
    [in] WDFDEVICE Device,
    [in] PWDF_DEVICE_STATE DeviceState
);

void WdfDeviceSetSpecialFileSupport(
    [in] WDFDEVICE Device,
    [in] WDF_SPECIAL_FILE_TYPE FileType,
    [in] BOOLEAN FileTypeIsSupported
);

WDFDRIVER WdfDeviceGetDriver(
    [in] WDFDEVICE Device
);

void WdfDeviceInitSetRequestAttributes(
    [in] PWDFDEVICE_INIT DeviceInit,
    [in] PWDF_OBJECT_ATTRIBUTES RequestAttributes
);

void WDF_PNPPOWER_EVENT_CALLBACKS_INIT(
    [out] PWDF_PNPPOWER_EVENT_CALLBACKS Callbacks
);

void WdfDeviceGetDeviceState(
    [in] WDFDEVICE Device,
    [in, out] PWDF_DEVICE_STATE DeviceState
);

NTSTATUS WdfDeviceConfigureRequestDispatching(
    [in] WDFDEVICE Device,
    [in] WDFQUEUE Queue,
    [in] WDF_REQUEST_TYPE RequestType
);

void WDF_DEVICE_POWER_POLICY_WAKE_SETTINGS_INIT(
    [out] PWDF_DEVICE_POWER_POLICY_WAKE_SETTINGS Settings
);

void WdfDeviceSetFailed(
    [in] WDFDEVICE Device,
    [in] WDF_DEVICE_FAILED_ACTION FailedAction
);

NTSTATUS WdfDeviceWdmAssignPowerFrameworkSettings(
    [in] WDFDEVICE Device,
    [in] PWDF_POWER_FRAMEWORK_SETTINGS PowerFrameworkSettings
);

void WDF_IO_TYPE_CONFIG_INIT(
    [out] PWDF_IO_TYPE_CONFIG IoTypeConfig
);

void WdfDeviceInitSetPnpPowerEventCallbacks(
    [in] PWDFDEVICE_INIT DeviceInit,
    [in] PWDF_PNPPOWER_EVENT_CALLBACKS PnpPowerEventCallbacks
);

NTSTATUS WdfDeviceRetrieveCompanionTarget(
    [in] WDFDEVICE Device,
    [out] WDFCOMPANIONTARGET *CompanionTarget
);

NTSTATUS WdfDeviceIndicateWakeStatus(
    [in] WDFDEVICE Device,
    [in] NTSTATUS WaitWakeStatus
);

NTSTATUS WdfDeviceStopIdleWithTag(
    _In_ WDFDEVICE Device,
    _In_ BOOLEAN WaitForD0,
    _In_ PVOID Tag
);

SIZE_T WdfDeviceReadFromHardware(
    [in] WDFDEVICE Device,
    [in] WDF_DEVICE_HWACCESS_TARGET_TYPE Type,
    [in] WDF_DEVICE_HWACCESS_TARGET_SIZE Size,
    [in] PVOID TargetAddress,
    [out, optional] PVOID Buffer,
    [in, optional] ULONG Count
);

WDF_DEVICE_PNP_STATE WdfDeviceGetDevicePnpState(
    [in] WDFDEVICE Device
);

NTSTATUS WdfDeviceRetrieveDeviceInterfaceString(
    [in] WDFDEVICE Device,
    [in] const GUID *InterfaceClassGUID,
    [in, optional] PCUNICODE_STRING ReferenceString,
    [in] WDFSTRING String
);

void WdfDeviceWriteToHardware(
    [in] WDFDEVICE Device,
    [in] WDF_DEVICE_HWACCESS_TARGET_TYPE Type,
    [in] WDF_DEVICE_HWACCESS_TARGET_SIZE Size,
    [in] PVOID TargetAddress,
    [in] SIZE_T Value,
    [in, optional] PVOID Buffer,
    [in, optional] ULONG Count
);

void WdfDeviceSetCharacteristics(
    [in] WDFDEVICE Device,
    [in] ULONG DeviceCharacteristics
);

NTSTATUS WdfDeviceAddRemovalRelationsPhysicalDevice(
    [in] WDFDEVICE Device,
    [in] PDEVICE_OBJECT PhysicalDevice
);

void WDF_POWER_POLICY_EVENT_CALLBACKS_INIT(
    [out] PWDF_POWER_POLICY_EVENT_CALLBACKS Callbacks
);

NTSTATUS WdfDeviceAllocAndQueryInterfaceProperty(
    [in] WDFDEVICE Device,
    [in] PWDF_DEVICE_INTERFACE_PROPERTY_DATA PropertyData,
    [in] POOL_TYPE PoolType,
    [in, optional] PWDF_OBJECT_ATTRIBUTES PropertyMemoryAttributes,
    [out] WDFMEMORY *PropertyMemory,
    [out] PDEVPROPTYPE Type
);

void WDF_DEVICE_INTERFACE_PROPERTY_DATA_INIT(
    [in] PWDF_DEVICE_INTERFACE_PROPERTY_DATA PropertyData,
    [in] const GUID *InterfaceClassGUID,
    [in] const DEVPROPKEY *PropertyKey
);

NTSTATUS WdfDeviceInitRegisterPowerPolicyStateChangeCallback(
    [in] PWDFDEVICE_INIT DeviceInit,
    [in] WDF_DEVICE_POWER_POLICY_STATE PowerPolicyState,
    [in] PFN_WDF_DEVICE_POWER_POLICY_STATE_CHANGE_NOTIFICATION EvtDevicePowerPolicyStateChange,
    [in] ULONG CallbackTypes
);

void WdfDeviceInitSetIoInCallerContextCallback(
    [in] PWDFDEVICE_INIT DeviceInit,
    [in] PFN_WDF_IO_IN_CALLER_CONTEXT EvtIoInCallerContext
);

void WdfDeviceInitSetRemoveLockOptions(
    [in] PWDFDEVICE_INIT DeviceInit,
    [in] PWDF_REMOVE_LOCK_OPTIONS Options
);

NTSTATUS WdfDeviceInitRegisterPowerStateChangeCallback(
    [in] PWDFDEVICE_INIT DeviceInit,
    [in] WDF_DEVICE_POWER_STATE PowerState,
    [in] PFN_WDF_DEVICE_POWER_STATE_CHANGE_NOTIFICATION EvtDevicePowerStateChange,
    [in] ULONG CallbackTypes
);

