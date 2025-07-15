NTSTATUS UsbPm_Deregister(
    [In] USBPM_CLIENT ClientHandle
);

void USBPM_CLIENT_CONFIG_EXTRA_INFO_INIT(
    [Out] PUSBPM_CLIENT_CONFIG_EXTRA_INFO ExtraInfo,
    [In] PDEVICE_OBJECT WdmDeviceObject
);

void USBPM_HUB_CONNECTOR_HANDLES_INIT(
    [Out] PUSBPM_HUB_CONNECTOR_HANDLES HubConnectorHandles,
    [In] ULONG ConnectorCount,
    [Out] USBPM_CONNECTOR *ConnectorHandlesBuffer
);

void USBPM_HUB_PROPERTIES_INIT(
    [Out] PUSBPM_HUB_PROPERTIES Properties
);

void USBPM_ASSIGN_CONNECTOR_POWER_LEVEL_PARAMS_INIT(
    [Out] PUSBPM_ASSIGN_CONNECTOR_POWER_LEVEL_PARAMS Params,
    [In] USBC_POWER_ROLE PowerRole,
    [In] USBPM_ASSIGN_POWER_LEVEL_PARAMS_FORMAT Format
);

NTSTATUS UsbPm_RetrieveConnectorState(
    [In] USBPM_CLIENT ClientHandle,
    [In] USBPM_CONNECTOR ConnectorHandle,
    [Out] PUSBPM_CONNECTOR_STATE ConnectorState
);

void USBPM_CONNECTOR_STATE_INIT(
    PUSBPM_CONNECTOR_STATE ConnectorState
);

NTSTATUS UsbPm_RetrieveHubConnectorHandles(
    [In] USBPM_CLIENT ClientHandle,
    [In] USBPM_HUB HubHandle,
    [Out] PUSBPM_HUB_CONNECTOR_HANDLES HubConnectorHandles
);

NTSTATUS UsbPm_AssignConnectorPowerLevel(
    [In] USBPM_CLIENT ClientHandle,
    [In] USBPM_CONNECTOR ConnectorHandle,
    [In] PUSBPM_ASSIGN_CONNECTOR_POWER_LEVEL_PARAMS Params
);

void USBPM_CONNECTOR_PROPERTIES_INIT(
    [Out] PUSBPM_CONNECTOR_PROPERTIES Properties
);

NTSTATUS UsbPm_RetrieveHubProperties(
    [In] USBPM_CLIENT ClientHandle,
    [In] USBPM_HUB HubHandle,
    [Out] PUSBPM_HUB_PROPERTIES HubProperties
);

void USBPM_CLIENT_CONFIG_INIT(
    [Out] PUSBPM_CLIENT_CONFIG ClientConfig,
    [In] ULONG AccessDesired,
    [In] PFN_USBPM_EVENT_CALLBACK EventCallback,
    [In] PUSBPM_CLIENT_CONFIG_EXTRA_INFO ExtraInfo
);

NTSTATUS UsbPm_RetrieveConnectorProperties(
    [In] USBPM_CLIENT ClientHandle,
    [In] USBPM_CONNECTOR ConnectorHandle,
    [Out] PUSBPM_CONNECTOR_PROPERTIES ConnectorProperties
);

NTSTATUS UsbPm_Register(
    [In] PUSBPM_CLIENT_CONFIG ClientConfig,
    [Out] USBPM_CLIENT *ClientHandle
);

