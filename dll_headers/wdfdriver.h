BOOLEAN WdfDriverIsVersionAvailable(
    [in] WDFDRIVER Driver,
    [in] PWDF_DRIVER_VERSION_AVAILABLE_PARAMS VersionAvailableParams
);

NTSTATUS WdfDriverRegisterTraceInfo(
    [in] PDRIVER_OBJECT DriverObject,
    [in] PFN_WDF_TRACE_CALLBACK EvtTraceCallback,
    [in] PVOID ControlBlock
);

NTSTATUS WdfDriverCreate(
    [in] PDRIVER_OBJECT DriverObject,
    [in] PCUNICODE_STRING RegistryPath,
    [in, optional] PWDF_OBJECT_ATTRIBUTES DriverAttributes,
    [in] PWDF_DRIVER_CONFIG DriverConfig,
    [out, optional] WDFDRIVER *Driver
);

NTSTATUS WdfDriverRetrieveVersionString(
    [in] WDFDRIVER Driver,
    [in] WDFSTRING String
);

NTSTATUS WdfDriverOpenParametersRegistryKey(
    [in] WDFDRIVER Driver,
    [in] ACCESS_MASK DesiredAccess,
    [in, optional] PWDF_OBJECT_ATTRIBUTES KeyAttributes,
    [out] WDFKEY *Key
);

PDRIVER_OBJECT WdfDriverWdmGetDriverObject(
    [in] WDFDRIVER Driver
);

WDFDRIVER WdfWdmDriverGetWdfDriverHandle(
    [in] PDRIVER_OBJECT DriverObject
);

NTSTATUS WdfDriverErrorReportApiMissing(
    WDFDRIVER Driver,
    PCWSTR FrameworkExtensionName,
    ULONG ApiIndex,
    BOOLEAN DoesApiReturnNtstatus
);

WDFDRIVER WdfGetDriver();

void WDF_DRIVER_VERSION_AVAILABLE_PARAMS_INIT(
    [out] PWDF_DRIVER_VERSION_AVAILABLE_PARAMS Params,
    [in] ULONG MajorVersion,
    [in] ULONG MinorVersion
);

NTSTATUS WdfDriverOpenPersistentStateRegistryKey(
    [in] WDFDRIVER Driver,
    [in] ACCESS_MASK DesiredAccess,
    [in, optional] PWDF_OBJECT_ATTRIBUTES KeyAttributes,
    [out] WDFKEY *Key
);

void WDF_DRIVER_CONFIG_INIT(
    [out] PWDF_DRIVER_CONFIG Config,
    [in, optional] PFN_WDF_DRIVER_DEVICE_ADD EvtDriverDeviceAdd
);

NTSTATUS WdfDriverRetrieveDriverDataDirectoryString(
    [_In_] WDFDRIVER Driver,
    [_In_] WDFSTRING String
);

PWSTR WdfDriverGetRegistryPath(
    [in] WDFDRIVER Driver
);

