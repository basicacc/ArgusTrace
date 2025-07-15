PURB USBD_CreateConfigurationRequest(
    [in] PUSB_CONFIGURATION_DESCRIPTOR ConfigurationDescriptor,
    [in, out] PUSHORT Siz
);

PURB USBD_CreateConfigurationRequestEx(
    [in] PUSB_CONFIGURATION_DESCRIPTOR ConfigurationDescriptor,
    [in] PUSBD_INTERFACE_LIST_ENTRY InterfaceList
);

NTSTATUS USBD_UrbAllocate(
    [in] USBD_HANDLE USBDHandle,
    [out] PURB *Urb
);

void USBD_RegisterHcFilter(
    [in] PDEVICE_OBJECT DeviceObject,
    [in] PDEVICE_OBJECT FilterDeviceObject
);

void USBD_UrbFree(
    [in] USBD_HANDLE USBDHandle,
    [in] PURB Urb
);

void UsbBuildOpenStaticStreamsRequest(
    [in, out] PURB Urb,
    [in] USBD_PIPE_HANDLE PipeHandle,
    [in] USHORT NumberOfStreams,
    [in] PUSBD_STREAM_INFORMATION StreamInfoArray
);

void USBD_AssignUrbToIoStackLocation(
    [in] USBD_HANDLE USBDHandle,
    [in] PIO_STACK_LOCATION IoStackLocation,
    [in] PURB Urb
);

NTSTATUS USBD_GetPdoRegistryParameter(
    [in] PDEVICE_OBJECT PhysicalDeviceObject,
    [in, out] PVOID Parameter,
    [in] ULONG ParameterLength,
    [in] PWSTR KeyName,
    [in] ULONG KeyNameLength
);

PUSB_INTERFACE_DESCRIPTOR USBD_ParseConfigurationDescriptor(
    [in] PUSB_CONFIGURATION_DESCRIPTOR ConfigurationDescriptor,
    [in] UCHAR InterfaceNumber,
    [in] UCHAR AlternateSetting
);

USBD_STATUS USBD_ValidateConfigurationDescriptor(
    [in] PUSB_CONFIGURATION_DESCRIPTOR ConfigDesc,
    [in] ULONG BufferLength,
    [in] USHORT Level,
    [out] PUCHAR *Offset,
    [in, optional] ULONG Tag
);

NTSTATUS USBD_SelectConfigUrbAllocateAndBuild(
    [in] USBD_HANDLE USBDHandle,
    [in] PUSB_CONFIGURATION_DESCRIPTOR ConfigurationDescriptor,
    [in] PUSBD_INTERFACE_LIST_ENTRY InterfaceList,
    [out] PURB *Urb
);

ULONG USBD_GetInterfaceLength(
    [in] PUSB_INTERFACE_DESCRIPTOR InterfaceDescriptor,
    [in] PUCHAR BufferEnd
);

PUSB_COMMON_DESCRIPTOR USBD_ParseDescriptors(
    [in] PVOID DescriptorBuffer,
    [in] ULONG TotalLength,
    [in] PVOID StartPosition,
    [in] LONG DescriptorType
);

#define GET_ISO_URB_SIZE(n) (sizeof(struct _URB_ISOCH_TRANSFER)+\
sizeof(USBD_ISO_PACKET_DESCRIPTOR)*n);

void COMPOSITE_DEVICE_CAPABILITIES_INIT(
    PCOMPOSITE_DEVICE_CAPABILITIES CapabilityFlags
);

BOOLEAN USBD_IsInterfaceVersionSupported(
    [in] USBD_HANDLE USBDHandle,
    [in] ULONG USBDInterfaceVersion
);

NTSTATUS USBD_QueryBusTime(
    [in] PDEVICE_OBJECT RootHubPdo,
    [out] PULONG CurrentFrame
);

NTSTATUS USBD_QueryUsbCapability(
    [in] USBD_HANDLE USBDHandle,
    [in] const GUID *CapabilityType,
    [in] ULONG OutputBufferLength,
    [in, out] PUCHAR OutputBuffer,
    [out, optional] PULONG ResultLength
);

NTSTATUS USBD_SelectInterfaceUrbAllocateAndBuild(
    [in] USBD_HANDLE USBDHandle,
    [in] USBD_CONFIGURATION_HANDLE ConfigurationHandle,
    PUSBD_INTERFACE_LIST_ENTRY InterfaceListEntry,
    [out] PURB *Urb
);

ULONG USBD_CalculateUsbBandwidth(
    [in] ULONG MaxPacketSize,
    [in] UCHAR EndpointType,
    [in] BOOLEAN LowSpeed
);

NTSTATUS USBD_IsochUrbAllocate(
    [in] USBD_HANDLE USBDHandle,
    [in] ULONG NumberOfIsochPackets,
    [out] PURB *Urb
);

void UsbBuildInterruptOrBulkTransferRequest(
    [in, out] urb,
    [in] length,
    [in] pipeHandle,
    [in, optional] transferBuffer,
    [in, optional] transferBufferMDL,
    [in] transferBufferLength,
    [in] transferFlags,
    [in] link
);

PUSB_INTERFACE_DESCRIPTOR USBD_ParseConfigurationDescriptorEx(
    [in] PUSB_CONFIGURATION_DESCRIPTOR ConfigurationDescriptor,
    [in] PVOID StartPosition,
    [in] LONG InterfaceNumber,
    [in] LONG AlternateSetting,
    [in] LONG InterfaceClass,
    [in] LONG InterfaceSubClass,
    [in] LONG InterfaceProtocol
);

void USBD_CloseHandle(
    [in] USBD_HANDLE USBDHandle
);

void USBD_BuildRegisterCompositeDevice(
    [in] USBD_HANDLE USBDHandle,
    [in] COMPOSITE_DEVICE_CAPABILITIES CapabilityFlags,
    [in] ULONG FunctionCount,
    [out] PREGISTER_COMPOSITE_DEVICE RegisterCompositeDevice
);

void USBD_GetUSBDIVersion(
    [out] PUSBD_VERSION_INFORMATION VersionInformation
);

void UsbBuildGetStatusRequest(
    [in, out] urb,
    [in] op,
    [in] index,
    [in, optional] transferBuffer,
    [in, optional] transferBufferMDL,
    [in] link
);

NTSTATUS USBD_CreateHandle(
    [in] PDEVICE_OBJECT DeviceObject,
    [in] PDEVICE_OBJECT TargetDeviceObject,
    [in] ULONG USBDClientContractVersion,
    [in] ULONG PoolTag,
    [out] USBD_HANDLE *USBDHandle
);

