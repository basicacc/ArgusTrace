WINSETUPAPI BOOL SetupDiGetClassRegistryPropertyW(
    [in] const GUID *ClassGuid,
    [in] DWORD Property,
    [out, optional] PDWORD PropertyRegDataType,
    [out] PBYTE PropertyBuffer,
    [in] DWORD PropertyBufferSize,
    [out, optional] PDWORD RequiredSize,
    [in, optional] PCWSTR MachineName,
    PVOID Reserved
);

WINSETUPAPI BOOL SetupIterateCabinetW(
    [in] PCWSTR CabinetFile,
    [in] DWORD Reserved,
    [in] PSP_FILE_CALLBACK_W MsgHandler,
    [in] PVOID Context
);

WINSETUPAPI BOOL SetupInstallServicesFromInfSectionExA(
    [in] HINF InfHandle,
    [in] PCSTR SectionName,
    [in] DWORD Flags,
    [in] HDEVINFO DeviceInfoSet,
    [in] PSP_DEVINFO_DATA DeviceInfoData,
    PVOID Reserved1,
    PVOID Reserved2
);

WINSETUPAPI BOOL SetupDiGetClassDevPropertySheetsW(
    [in] HDEVINFO DeviceInfoSet,
    [in, optional] PSP_DEVINFO_DATA DeviceInfoData,
    [in] LPPROPSHEETHEADERW PropertySheetHeader,
    [in] DWORD PropertySheetHeaderPageListSize,
    [out, optional] PDWORD RequiredSize,
    [in] DWORD PropertySheetType
);

WINSETUPAPI HKEY SetupDiOpenClassRegKeyExW(
    [in, optional] const GUID *ClassGuid,
    [in] REGSAM samDesired,
    [in] DWORD Flags,
    [in, optional] PCWSTR MachineName,
    PVOID Reserved
);

WINSETUPAPI BOOL SetupGetFileCompressionInfoExA(
    [in] PCSTR SourceFileName,
    [in, out] PSTR ActualSourceFileNameBuffer,
    [in, out] DWORD ActualSourceFileNameBufferLen,
    [out] PDWORD RequiredBufferLen,
    [out] PDWORD SourceFileSize,
    [out] PDWORD TargetFileSize,
    [out] PUINT CompressionType
);

WINSETUPAPI BOOL SetupAddToDiskSpaceListA(
    [in] HDSKSPC DiskSpace,
    [in] PCSTR TargetFilespec,
    [in] LONGLONG FileSize,
    [in] UINT Operation,
    [in] PVOID Reserved1,
    [in] UINT Reserved2
);

WINSETUPAPI BOOL SetupCommitFileQueueW(
    [in] HWND Owner,
    [in] HSPFILEQ QueueHandle,
    [in] PSP_FILE_CALLBACK_W MsgHandler,
    [in] PVOID Context
);

WINSETUPAPI BOOL SetupGetIntField(
    [in] PINFCONTEXT Context,
    [in] DWORD FieldIndex,
    [out] PINT IntegerValue
);

WINSETUPAPI BOOL SetupGetInfDriverStoreLocationW(
    [in] PCWSTR FileName,
    [in, optional] PSP_ALTPLATFORM_INFO AlternatePlatformInfo,
    [in, optional] PCWSTR LocaleName,
    [out] PWSTR ReturnBuffer,
    [in] DWORD ReturnBufferSize,
    [out, optional] PDWORD RequiredSize
);

WINSETUPAPI BOOL SetupDiSelectDevice(
    [in] HDEVINFO DeviceInfoSet,
    [in, out] PSP_DEVINFO_DATA DeviceInfoData
);

WINSETUPAPI UINT SetupDeleteErrorW(
    [in] HWND hwndParent,
    [in] PCWSTR DialogTitle,
    [in] PCWSTR File,
    [out] UINT Win32ErrorCode,
    [in] DWORD Style
);

WINSETUPAPI BOOL SetupGetSourceFileLocationA(
    [in] HINF InfHandle,
    [in] PINFCONTEXT InfContext,
    [in] PCSTR FileName,
    [in, out] PUINT SourceId,
    [in, out] PSTR ReturnBuffer,
    [out] DWORD ReturnBufferSize,
    [in, out] PDWORD RequiredSize
);

WINSETUPAPI BOOL SetupGetFileQueueCount(
    [in] HSPFILEQ FileQueue,
    [in] UINT SubQueueFileOp,
    [out] PUINT NumOperations
);

WINSETUPAPI BOOL SetupGetSourceFileLocationW(
    [in] HINF InfHandle,
    [in] PINFCONTEXT InfContext,
    [in] PCWSTR FileName,
    [in, out] PUINT SourceId,
    [in, out] PWSTR ReturnBuffer,
    [out] DWORD ReturnBufferSize,
    [in, out] PDWORD RequiredSize
);

WINSETUPAPI BOOL SetupDiEnumDeviceInterfaces(
    [in] HDEVINFO DeviceInfoSet,
    [in, optional] PSP_DEVINFO_DATA DeviceInfoData,
    [in] const GUID *InterfaceClassGuid,
    [in] DWORD MemberIndex,
    [out] PSP_DEVICE_INTERFACE_DATA DeviceInterfaceData
);

WINSETUPAPI BOOL SetupLogErrorA(
    [in] LPCSTR MessageString,
    [in] LogSeverity Severity
);

WINSETUPAPI BOOL SetupGetInfInformationA(
    [in] LPCVOID InfSpec,
    [in] DWORD SearchControl,
    [in, out] PSP_INF_INFORMATION ReturnBuffer,
    [in] DWORD ReturnBufferSize,
    [in, out] PDWORD RequiredSize
);

WINSETUPAPI BOOL SetupGetInfFileListW(
    [in] PCWSTR DirectoryPath,
    [in] DWORD InfStyle,
    [in, out] PWSTR ReturnBuffer,
    [in] DWORD ReturnBufferSize,
    [in, out] PDWORD RequiredSize
);

WINSETUPAPI HKEY SetupDiOpenDeviceInterfaceRegKey(
    [in] HDEVINFO DeviceInfoSet,
    [in] PSP_DEVICE_INTERFACE_DATA DeviceInterfaceData,
    DWORD Reserved,
    [in] REGSAM samDesired
);

WINSETUPAPI BOOL SetupRemoveSectionFromDiskSpaceListA(
    [in] HDSKSPC DiskSpace,
    [in] HINF InfHandle,
    [in] HINF ListInfHandle,
    [in] PCSTR SectionName,
    [in] UINT Operation,
    [in] PVOID Reserved1,
    [in] UINT Reserved2
);

WINSETUPAPI BOOL SetupInstallFilesFromInfSectionW(
    [in] HINF InfHandle,
    [in] HINF LayoutInfHandle,
    [in] HSPFILEQ FileQueue,
    [in] PCWSTR SectionName,
    [in] PCWSTR SourceRootPath,
    [in] UINT CopyFlags
);

WINSETUPAPI BOOL SetupDiClassGuidsFromNameA(
    [in] PCSTR ClassName,
    [out] LPGUID ClassGuidList,
    [in] DWORD ClassGuidListSize,
    [out] PDWORD RequiredSize
);

WINSETUPAPI HDEVINFO SetupDiGetClassDevsA(
    const GUID *ClassGuid,
    PCSTR Enumerator,
    HWND hwndParent,
    DWORD Flags
);

WINSETUPAPI BOOL SetupDiGetDriverInfoDetailW(
    [in] HDEVINFO DeviceInfoSet,
    [in, optional] PSP_DEVINFO_DATA DeviceInfoData,
    [in] PSP_DRVINFO_DATA_W DriverInfoData,
    [in, out] PSP_DRVINFO_DETAIL_DATA_W DriverInfoDetailData,
    [in] DWORD DriverInfoDetailDataSize,
    [out, optional] PDWORD RequiredSize
);

WINSETUPAPI BOOL SetupFindNextMatchLineW(
    [in] PINFCONTEXT ContextIn,
    [in] PCWSTR Key,
    [in, out] PINFCONTEXT ContextOut
);

WINSETUPAPI BOOL SetupScanFileQueueA(
    [in] HSPFILEQ FileQueue,
    [in] DWORD Flags,
    [in] HWND Window,
    [in] PSP_FILE_CALLBACK_A CallbackRoutine,
    [in] PVOID CallbackContext,
    [out] PDWORD Result
);

WINSETUPAPI BOOL SetupDiBuildDriverInfoList(
    [in] HDEVINFO DeviceInfoSet,
    [in, out] PSP_DEVINFO_DATA DeviceInfoData,
    [in] DWORD DriverType
);

WINSETUPAPI BOOL SetupDiGetDriverInstallParamsA(
    [in] HDEVINFO DeviceInfoSet,
    [in, optional] PSP_DEVINFO_DATA DeviceInfoData,
    [in] PSP_DRVINFO_DATA_A DriverInfoData,
    [out] PSP_DRVINSTALL_PARAMS DriverInstallParams
);

WINSETUPAPI BOOL SetupRemoveFromDiskSpaceListA(
    [in] HDSKSPC DiskSpace,
    [in] PCSTR TargetFilespec,
    [in] UINT Operation,
    [in] PVOID Reserved1,
    [in] UINT Reserved2
);

WINSETUPAPI BOOL SetupDiGetDeviceInterfacePropertyKeys(
    [in] HDEVINFO DeviceInfoSet,
    [in] PSP_DEVICE_INTERFACE_DATA DeviceInterfaceData,
    [out, optional] DEVPROPKEY *PropertyKeyArray,
    [in] DWORD PropertyKeyCount,
    [out, optional] PDWORD RequiredPropertyKeyCount,
    [in] DWORD Flags
);

WINSETUPAPI BOOL SetupGetBinaryField(
    [in] PINFCONTEXT Context,
    [in] DWORD FieldIndex,
    [in, out] PBYTE ReturnBuffer,
    [in] DWORD ReturnBufferSize,
    [in, out] LPDWORD RequiredSize
);

WINSETUPAPI BOOL SetupDiGetClassPropertyKeysExW(
    [in] const GUID *ClassGuid,
    [out, optional] DEVPROPKEY *PropertyKeyArray,
    [in] DWORD PropertyKeyCount,
    [out, optional] PDWORD RequiredPropertyKeyCount,
    [in] DWORD Flags,
    [in, optional] PCWSTR MachineName,
    PVOID Reserved
);

WINSETUPAPI BOOL SetupDiEnumDeviceInfo(
    [in] HDEVINFO DeviceInfoSet,
    [in] DWORD MemberIndex,
    [out] PSP_DEVINFO_DATA DeviceInfoData
);

WINSETUPAPI BOOL SetupGetStringFieldW(
    [in] PINFCONTEXT Context,
    [in] DWORD FieldIndex,
    [in, out] PWSTR ReturnBuffer,
    [in] DWORD ReturnBufferSize,
    [out] PDWORD RequiredSize
);

WINSETUPAPI BOOL SetupDiSetDeviceInstallParamsW(
    [in] HDEVINFO DeviceInfoSet,
    [in, optional] PSP_DEVINFO_DATA DeviceInfoData,
    [in] PSP_DEVINSTALL_PARAMS_W DeviceInstallParams
);

WINSETUPAPI BOOL SetupInstallFileA(
    [in] HINF InfHandle,
    [in] PINFCONTEXT InfContext,
    [in] PCSTR SourceFile,
    [in] PCSTR SourcePathRoot,
    [in] PCSTR DestinationName,
    [in] DWORD CopyStyle,
    [in] PSP_FILE_CALLBACK_A CopyMsgHandler,
    [in] PVOID Context
);

WINSETUPAPI BOOL SetupVerifyInfFileA(
    [in] PCSTR InfName,
    [in] PSP_ALTPLATFORM_INFO AltPlatformInfo,
    [out] PSP_INF_SIGNER_INFO_A InfSignerInfo
);

WINSETUPAPI BOOL SetupQueryDrivesInDiskSpaceListW(
    [in] HDSKSPC DiskSpace,
    [in, out] PWSTR ReturnBuffer,
    [in] DWORD ReturnBufferSize,
    [in, out] PDWORD RequiredSize
);

WINSETUPAPI BOOL SetupGetTargetPathW(
    [in] HINF InfHandle,
    [in] PINFCONTEXT InfContext,
    [in] PCWSTR Section,
    [in, out] PWSTR ReturnBuffer,
    [in] DWORD ReturnBufferSize,
    [in, out] PDWORD RequiredSize
);

WINSETUPAPI HDEVINFO SetupDiGetClassDevsW(
    [in, optional] const GUID *ClassGuid,
    [in, optional] PCWSTR Enumerator,
    [in, optional] HWND hwndParent,
    [in] DWORD Flags
);

WINSETUPAPI BOOL SetupDiClassGuidsFromNameW(
    [in] PCWSTR ClassName,
    [out] LPGUID ClassGuidList,
    [in] DWORD ClassGuidListSize,
    [out] PDWORD RequiredSize
);

WINSETUPAPI BOOL SetupDiChangeState(
    [in] HDEVINFO DeviceInfoSet,
    [in, out] PSP_DEVINFO_DATA DeviceInfoData
);

WINSETUPAPI BOOL SetupOpenAppendInfFileA(
    [in] PCSTR FileName,
    [in] HINF InfHandle,
    [in, out] PUINT ErrorLine
);

WINSETUPAPI BOOL SetupDiOpenDeviceInfoW(
    [in] HDEVINFO DeviceInfoSet,
    [in] PCWSTR DeviceInstanceId,
    [in, optional] HWND hwndParent,
    [in] DWORD OpenFlags,
    [out, optional] PSP_DEVINFO_DATA DeviceInfoData
);

WINSETUPAPI LONG SetupGetLineCountA(
    [in] HINF InfHandle,
    [in] PCSTR Section
);

void InstallHinfSectionA(
    [in] HWND Window,
    [in] HINSTANCE ModuleHandle,
    [in] PCSTR CommandLine,
    [in] INT ShowCommand
);

WINSETUPAPI BOOL SetupGetNonInteractiveMode();

WINSETUPAPI BOOL SetupDiGetDevicePropertyKeys(
    [in] HDEVINFO DeviceInfoSet,
    [in] PSP_DEVINFO_DATA DeviceInfoData,
    [out, optional] DEVPROPKEY *PropertyKeyArray,
    [in] DWORD PropertyKeyCount,
    [out, optional] PDWORD RequiredPropertyKeyCount,
    [in] DWORD Flags
);

WINSETUPAPI BOOL SetupInstallServicesFromInfSectionA(
    [in] HINF InfHandle,
    [in] PCSTR SectionName,
    [in] DWORD Flags
);

WINSETUPAPI BOOL SetupCopyOEMInfW(
    [in] PCWSTR SourceInfFileName,
    [in] PCWSTR OEMSourceMediaLocation,
    [in] DWORD OEMSourceMediaType,
    [in] DWORD CopyStyle,
    [out, optional] PWSTR DestinationInfFileName,
    [in] DWORD DestinationInfFileNameSize,
    [out, optional] PDWORD RequiredSize,
    [out, optional] PWSTR *DestinationInfFileNameComponent
);

WINSETUPAPI BOOL SetupDiBuildClassInfoList(
    [in] DWORD Flags,
    [out, optional] LPGUID ClassGuidList,
    [in] DWORD ClassGuidListSize,
    [out] PDWORD RequiredSize
);

WINSETUPAPI UINT SetupDefaultQueueCallbackA(
    [in] PVOID Context,
    [in] UINT Notification,
    [in] UINT_PTR Param1,
    [in] UINT_PTR Param2
);

WINSETUPAPI BOOL SetupGetSourceFileSizeA(
    [in] HINF InfHandle,
    [in] PINFCONTEXT InfContext,
    [in] PCSTR FileName,
    [in] PCSTR Section,
    [in, out] PDWORD FileSize,
    [in] UINT RoundingFactor
);

WINSETUPAPI BOOL SetupDiGetDriverInstallParamsW(
    [in] HDEVINFO DeviceInfoSet,
    [in, optional] PSP_DEVINFO_DATA DeviceInfoData,
    [in] PSP_DRVINFO_DATA_W DriverInfoData,
    [out] PSP_DRVINSTALL_PARAMS DriverInstallParams
);

WINSETUPAPI BOOL SetupDiGetActualSectionToInstallW(
    [in] HINF InfHandle,
    [in] PCWSTR InfSectionName,
    [out, optional] PWSTR InfSectionWithExt,
    [in] DWORD InfSectionWithExtSize,
    [out, optional] PDWORD RequiredSize,
    [out, optional] PWSTR *Extension
);

WINSETUPAPI BOOL SetupUninstallOEMInfA(
    [in] PCSTR InfFileName,
    [in] DWORD Flags,
    [in] PVOID Reserved
);

WINSETUPAPI DWORD SetupGetFileCompressionInfoW(
    [in] PCWSTR SourceFileName,
    [in, out] PWSTR *ActualSourceFileName,
    [in, out] PDWORD SourceFileSize,
    [in, out] PDWORD TargetFileSize,
    [in, out] PUINT CompressionType
);

WINSETUPAPI BOOL SetupGetMultiSzFieldW(
    [in] PINFCONTEXT Context,
    [in] DWORD FieldIndex,
    [in, out] PWSTR ReturnBuffer,
    [in] DWORD ReturnBufferSize,
    [in] LPDWORD RequiredSize
);

WINSETUPAPI BOOL SetupDiDeleteDeviceInterfaceRegKey(
    [in] HDEVINFO DeviceInfoSet,
    [in] PSP_DEVICE_INTERFACE_DATA DeviceInterfaceData,
    DWORD Reserved
);

WINSETUPAPI BOOL SetupDiDeleteDeviceInfo(
    [in] HDEVINFO DeviceInfoSet,
    [in] PSP_DEVINFO_DATA DeviceInfoData
);

WINSETUPAPI BOOL SetupDiBuildClassInfoListExW(
    [in] DWORD Flags,
    [out, optional] LPGUID ClassGuidList,
    [in] DWORD ClassGuidListSize,
    [out] PDWORD RequiredSize,
    [in, optional] PCWSTR MachineName,
    PVOID Reserved
);

WINSETUPAPI HKEY SetupDiOpenClassRegKey(
    [in, optional] const GUID *ClassGuid,
    [in] REGSAM samDesired
);

WINSETUPAPI BOOL SetupDiBuildClassInfoListExA(
    [in] DWORD Flags,
    [out, optional] LPGUID ClassGuidList,
    [in] DWORD ClassGuidListSize,
    [out] PDWORD RequiredSize,
    [in, optional] PCSTR MachineName,
    PVOID Reserved
);

WINSETUPAPI HKEY SetupDiCreateDeviceInterfaceRegKeyA(
    [in] HDEVINFO DeviceInfoSet,
    [in] PSP_DEVICE_INTERFACE_DATA DeviceInterfaceData,
    DWORD Reserved,
    [in] REGSAM samDesired,
    [in, optional] HINF InfHandle,
    [in, optional] PCSTR InfSectionName
);

WINSETUPAPI HDSKSPC SetupDuplicateDiskSpaceListW(
    [in] HDSKSPC DiskSpace,
    PVOID Reserved1,
    DWORD Reserved2,
    UINT Flags
);

WINSETUPAPI BOOL SetupTerminateFileLog(
    [in] HSPFILELOG FileLogHandle
);

WINSETUPAPI BOOL SetupDiInstallClassExA(
    [in, optional] HWND hwndParent,
    [in, optional] PCSTR InfFileName,
    [in] DWORD Flags,
    [in, optional] HSPFILEQ FileQueue,
    [in, optional] const GUID *InterfaceClassGuid,
    PVOID Reserved1,
    PVOID Reserved2
);

WINSETUPAPI BOOL SetupRemoveFromSourceListA(
    [in] DWORD Flags,
    [in] PCSTR Source
);

WINSETUPAPI BOOL SetupDiGetDriverInfoDetailA(
    [in] HDEVINFO DeviceInfoSet,
    [in, optional] PSP_DEVINFO_DATA DeviceInfoData,
    [in] PSP_DRVINFO_DATA_A DriverInfoData,
    [in, out] PSP_DRVINFO_DETAIL_DATA_A DriverInfoDetailData,
    [in] DWORD DriverInfoDetailDataSize,
    [out, optional] PDWORD RequiredSize
);

WINSETUPAPI BOOL SetupDiRemoveDevice(
    [in] HDEVINFO DeviceInfoSet,
    [in, out] PSP_DEVINFO_DATA DeviceInfoData
);

WINSETUPAPI HDEVINFO SetupDiCreateDeviceInfoListExA(
    [in, optional] const GUID *ClassGuid,
    [in, optional] HWND hwndParent,
    [in, optional] PCSTR MachineName,
    PVOID Reserved
);

WINSETUPAPI BOOL SetupInstallFromInfSectionA(
    HWND Owner,
    HINF InfHandle,
    PCSTR SectionName,
    UINT Flags,
    HKEY RelativeKeyRoot,
    PCSTR SourceRootPath,
    UINT CopyFlags,
    PSP_FILE_CALLBACK_A MsgHandler,
    PVOID Context,
    HDEVINFO DeviceInfoSet,
    PSP_DEVINFO_DATA DeviceInfoData
);

WINSETUPAPI BOOL SetupGetInfPublishedNameA(
    [in] PCSTR DriverStoreLocation,
    [out] PSTR ReturnBuffer,
    [in] DWORD ReturnBufferSize,
    [out, optional] PDWORD RequiredSize
);

WINSETUPAPI BOOL SetupOpenLog(
    [in] BOOL Erase
);

WINSETUPAPI BOOL SetupSetPlatformPathOverrideW(
    [in] PCWSTR Override
);

WINSETUPAPI BOOL SetupGetFileQueueFlags(
    [in] HSPFILEQ FileQueue,
    [out] PDWORD Flags
);

WINSETUPAPI HDEVINFO SetupDiCreateDeviceInfoList(
    [in, optional] const GUID *ClassGuid,
    [in, optional] HWND hwndParent
);

WINSETUPAPI BOOL SetupDiGetDeviceInfoListClass(
    [in] HDEVINFO DeviceInfoSet,
    [out] LPGUID ClassGuid
);

WINSETUPAPI BOOL SetupDiGetActualSectionToInstallExA(
    [in] HINF InfHandle,
    [in] PCSTR InfSectionName,
    [in, optional] PSP_ALTPLATFORM_INFO AlternatePlatformInfo,
    [out, optional] PSTR InfSectionWithExt,
    [in] DWORD InfSectionWithExtSize,
    [out, optional] PDWORD RequiredSize,
    [out, optional] PSTR *Extension,
    PVOID Reserved
);

WINSETUPAPI BOOL SetupCancelTemporarySourceList();

WINSETUPAPI PVOID SetupInitDefaultQueueCallback(
    [in] HWND OwnerWindow
);

WINSETUPAPI BOOL SetupCommitFileQueueA(
    [in] HWND Owner,
    [in] HSPFILEQ QueueHandle,
    [in] PSP_FILE_CALLBACK_A MsgHandler,
    [in] PVOID Context
);

WINSETUPAPI BOOL SetupAddToSourceListW(
    [in] DWORD Flags,
    [in] PCWSTR Source
);

WINSETUPAPI UINT SetupCopyErrorW(
    [in] HWND hwndParent,
    [in] PCWSTR DialogTitle,
    [in] PCWSTR DiskName,
    [in] PCWSTR PathToSource,
    [in] PCWSTR SourceFile,
    [in] PCWSTR TargetPathFile,
    [out] UINT Win32ErrorCode,
    [in] DWORD Style,
    [in, out] PWSTR PathBuffer,
    [in] DWORD PathBufferSize,
    [in, out] PDWORD PathRequiredSize
);

WINSETUPAPI BOOL SetupSetSourceListW(
    [in] DWORD Flags,
    [in] PCWSTR *SourceList,
    [in] UINT SourceCount
);

WINSETUPAPI BOOL SetupDiGetDeviceInstanceIdW(
    [in] HDEVINFO DeviceInfoSet,
    [in] PSP_DEVINFO_DATA DeviceInfoData,
    [out, optional] PWSTR DeviceInstanceId,
    [in] DWORD DeviceInstanceIdSize,
    [out, optional] PDWORD RequiredSize
);

WINSETUPAPI BOOL SetupDiSelectOEMDrv(
    [in, optional] HWND hwndParent,
    [in] HDEVINFO DeviceInfoSet,
    [in, out] PSP_DEVINFO_DATA DeviceInfoData
);

WINSETUPAPI DWORD SetupGetFieldCount(
    [in] PINFCONTEXT Context
);

WINSETUPAPI BOOL SetupGetLineByIndexA(
    [in] HINF InfHandle,
    [in] PCSTR Section,
    [in] DWORD Index,
    [in, out] PINFCONTEXT Context
);

WINSETUPAPI BOOL SetupCopyOEMInfA(
    [in] PCSTR SourceInfFileName,
    [in] PCSTR OEMSourceMediaLocation,
    [in] DWORD OEMSourceMediaType,
    [in] DWORD CopyStyle,
    [out, optional] PSTR DestinationInfFileName,
    [in] DWORD DestinationInfFileNameSize,
    [out, optional] PDWORD RequiredSize,
    [out, optional] PSTR *DestinationInfFileNameComponent
);

WINSETUPAPI BOOL SetupDiSetDevicePropertyW(
    [in] HDEVINFO DeviceInfoSet,
    [in] PSP_DEVINFO_DATA DeviceInfoData,
    [in] const DEVPROPKEY *PropertyKey,
    [in] DEVPROPTYPE PropertyType,
    [in, optional] const PBYTE PropertyBuffer,
    [in] DWORD PropertyBufferSize,
    [in] DWORD Flags
);

WINSETUPAPI BOOL SetupDiSetClassInstallParamsW(
    [in] HDEVINFO DeviceInfoSet,
    [in, optional] PSP_DEVINFO_DATA DeviceInfoData,
    [in, optional] PSP_CLASSINSTALL_HEADER ClassInstallParams,
    [in] DWORD ClassInstallParamsSize
);

WINSETUPAPI BOOL SetupCloseFileQueue(
    [in] HSPFILEQ QueueHandle
);

WINSETUPAPI BOOL SetupDiGetHwProfileFriendlyNameW(
    [in] DWORD HwProfile,
    [out] PWSTR FriendlyName,
    [in] DWORD FriendlyNameSize,
    [out, optional] PDWORD RequiredSize
);

WINSETUPAPI BOOL SetupRemoveInstallSectionFromDiskSpaceListA(
    [in] HDSKSPC DiskSpace,
    [in] HINF InfHandle,
    [in] HINF LayoutInfHandle,
    [in] PCSTR SectionName,
    [in] PVOID Reserved1,
    [in] UINT Reserved2
);

WINSETUPAPI BOOL SetupAddSectionToDiskSpaceListW(
    [in] HDSKSPC DiskSpace,
    [in] HINF InfHandle,
    [in] HINF ListInfHandle,
    [in] PCWSTR SectionName,
    [in] UINT Operation,
    [in] PVOID Reserved1,
    [in] UINT Reserved2
);

WINSETUPAPI UINT SetupBackupErrorA(
    [in] HWND hwndParent,
    [in] PCSTR DialogTitle,
    [in] PCSTR SourceFile,
    [in] PCSTR TargetFile,
    [out] UINT Win32ErrorCode,
    [in] DWORD Style
);

WINSETUPAPI BOOL SetupDiClassNameFromGuidA(
    [in] const GUID *ClassGuid,
    [out] PSTR ClassName,
    [in] DWORD ClassNameSize,
    [out, optional] PDWORD RequiredSize
);

WINSETUPAPI BOOL SetupDiGetDeviceInstallParamsA(
    [in] HDEVINFO DeviceInfoSet,
    [in, optional] PSP_DEVINFO_DATA DeviceInfoData,
    [out] PSP_DEVINSTALL_PARAMS_A DeviceInstallParams
);

WINSETUPAPI BOOL SetupDiInstallClassA(
    [in, optional] HWND hwndParent,
    [in] PCSTR InfFileName,
    [in] DWORD Flags,
    [in, optional] HSPFILEQ FileQueue
);

WINSETUPAPI BOOL SetupDiDestroyDriverInfoList(
    [in] HDEVINFO DeviceInfoSet,
    [in, optional] PSP_DEVINFO_DATA DeviceInfoData,
    [in] DWORD DriverType
);

WINSETUPAPI BOOL SetupDiGetClassRegistryPropertyA(
    [in] const GUID *ClassGuid,
    [in] DWORD Property,
    [out, optional] PDWORD PropertyRegDataType,
    [out] PBYTE PropertyBuffer,
    [in] DWORD PropertyBufferSize,
    [out, optional] PDWORD RequiredSize,
    [in, optional] PCSTR MachineName,
    PVOID Reserved
);

WINSETUPAPI BOOL SetupSetFileQueueAlternatePlatformA(
    [in] HSPFILEQ QueueHandle,
    [in] PSP_ALTPLATFORM_INFO AlternatePlatformInfo,
    [in] PCSTR AlternateDefaultCatalogFile
);

WINSETUPAPI BOOL SetupDiGetHwProfileFriendlyNameA(
    [in] DWORD HwProfile,
    [out] PSTR FriendlyName,
    [in] DWORD FriendlyNameSize,
    [out, optional] PDWORD RequiredSize
);

WINSETUPAPI BOOL SetupDiOpenDeviceInfoA(
    [in] HDEVINFO DeviceInfoSet,
    [in] PCSTR DeviceInstanceId,
    [in, optional] HWND hwndParent,
    [in] DWORD OpenFlags,
    [out, optional] PSP_DEVINFO_DATA DeviceInfoData
);

WINSETUPAPI BOOL SetupDiInstallDriverFiles(
    [in] HDEVINFO DeviceInfoSet,
    [in] PSP_DEVINFO_DATA DeviceInfoData
);

WINSETUPAPI BOOL SetupDiClassNameFromGuidExA(
    [in] const GUID *ClassGuid,
    [out] PSTR ClassName,
    [in] DWORD ClassNameSize,
    [out, optional] PDWORD RequiredSize,
    [in, optional] PCSTR MachineName,
    PVOID Reserved
);

WINSETUPAPI VOID SetupWriteTextLog(
    [in] SP_LOG_TOKEN LogToken,
    [in] DWORD Category,
    [in] DWORD Flags,
    [in] PCSTR MessageStr,
    ...
);

WINSETUPAPI BOOL SetupDiGetHwProfileList(
    [out] PDWORD HwProfileList,
    [in] DWORD HwProfileListSize,
    [out] PDWORD RequiredSize,
    [out, optional] PDWORD CurrentlyActiveIndex
);

WINSETUPAPI INT SetupDiDrawMiniIcon(
    [in] HDC hdc,
    [in] RECT rc,
    [in] INT MiniIconIndex,
    [in] DWORD Flags
);

WINSETUPAPI BOOL SetupGetSourceInfoW(
    [in] HINF InfHandle,
    [in] UINT SourceId,
    [in] UINT InfoDesired,
    [in, out] PWSTR ReturnBuffer,
    [in] DWORD ReturnBufferSize,
    [in, out] PDWORD RequiredSize
);

WINSETUPAPI BOOL SetupDiGetActualSectionToInstallA(
    [in] HINF InfHandle,
    [in] PCSTR InfSectionName,
    [out, optional] PSTR InfSectionWithExt,
    [in] DWORD InfSectionWithExtSize,
    [out, optional] PDWORD RequiredSize,
    [out, optional] PSTR *Extension
);

WINSETUPAPI BOOL SetupQueueRenameSectionA(
    [in] HSPFILEQ QueueHandle,
    [in] HINF InfHandle,
    [in] HINF ListInfHandle,
    [in] PCSTR Section
);

WINSETUPAPI BOOL SetupDiAskForOEMDisk(
    [in] HDEVINFO DeviceInfoSet,
    [in, optional] PSP_DEVINFO_DATA DeviceInfoData
);

WINSETUPAPI BOOL SetupDiLoadDeviceIcon(
    [in] HDEVINFO DeviceInfoSet,
    [in] PSP_DEVINFO_DATA DeviceInfoData,
    [in] UINT cxIcon,
    [in] UINT cyIcon,
    [in] DWORD Flags,
    [out] HICON *hIcon
);

WINSETUPAPI HDSKSPC SetupCreateDiskSpaceListW(
    [in] PVOID Reserved1,
    [in] DWORD Reserved2,
    [in] UINT Flags
);

WINSETUPAPI UINT SetupDefaultQueueCallbackW(
    [in] PVOID Context,
    [in] UINT Notification,
    [in] UINT_PTR Param1,
    [in] UINT_PTR Param2
);

WINSETUPAPI HINF SetupOpenInfFileA(
    [in] PCSTR FileName,
    [in] PCSTR InfClass,
    [in] DWORD InfStyle,
    [in] PUINT ErrorLine
);

WINSETUPAPI BOOL SetupInstallServicesFromInfSectionExW(
    [in] HINF InfHandle,
    [in] PCWSTR SectionName,
    [in] DWORD Flags,
    [in] HDEVINFO DeviceInfoSet,
    [in] PSP_DEVINFO_DATA DeviceInfoData,
    PVOID Reserved1,
    PVOID Reserved2
);

WINSETUPAPI BOOL SetupSetPlatformPathOverrideA(
    [in] PCSTR Override
);

WINSETUPAPI BOOL SetupQueryInfOriginalFileInformationA(
    [in] PSP_INF_INFORMATION InfInformation,
    [in] UINT InfIndex,
    [in] PSP_ALTPLATFORM_INFO AlternatePlatformInfo,
    [out] PSP_ORIGINAL_FILE_INFO_A OriginalFileInfo
);

WINSETUPAPI HDEVINFO SetupDiCreateDeviceInfoListExW(
    [in, optional] const GUID *ClassGuid,
    [in, optional] HWND hwndParent,
    [in, optional] PCWSTR MachineName,
    PVOID Reserved
);

WINSETUPAPI BOOL SetupAddToSourceListA(
    [in] DWORD Flags,
    [in] PCSTR Source
);

WINSETUPAPI BOOL SetupDiRegisterCoDeviceInstallers(
    [in] HDEVINFO DeviceInfoSet,
    [in] PSP_DEVINFO_DATA DeviceInfoData
);

WINSETUPAPI BOOL SetupInstallFilesFromInfSectionA(
    [in] HINF InfHandle,
    [in] HINF LayoutInfHandle,
    [in] HSPFILEQ FileQueue,
    [in] PCSTR SectionName,
    [in] PCSTR SourceRootPath,
    [in] UINT CopyFlags
);

WINSETUPAPI HSPFILEQ SetupOpenFileQueue();

WINSETUPAPI BOOL SetupDiLoadClassIcon(
    [in] const GUID *ClassGuid,
    [out, optional] HICON *LargeIcon,
    [out, optional] PINT MiniIconIndex
);

WINSETUPAPI BOOL SetupAddInstallSectionToDiskSpaceListA(
    [in] HDSKSPC DiskSpace,
    [in] HINF InfHandle,
    [in] HINF LayoutInfHandle,
    [in] PCSTR SectionName,
    [in] PVOID Reserved1,
    [in] UINT Reserved2
);

WINSETUPAPI DWORD SetupDecompressOrCopyFileW(
    [in] PCWSTR SourceFileName,
    [in] PCWSTR TargetFileName,
    [in] PUINT CompressionType
);

WINSETUPAPI BOOL SetupDiGetDeviceInfoListDetailA(
    [in] HDEVINFO DeviceInfoSet,
    [out] PSP_DEVINFO_LIST_DETAIL_DATA_A DeviceInfoSetDetailData
);

WINSETUPAPI BOOL SetupDiCreateDeviceInterfaceA(
    [in] HDEVINFO DeviceInfoSet,
    [in] PSP_DEVINFO_DATA DeviceInfoData,
    [in] const GUID *InterfaceClassGuid,
    [in, optional] PCSTR ReferenceString,
    [in] DWORD CreationFlags,
    [out, optional] PSP_DEVICE_INTERFACE_DATA DeviceInterfaceData
);

WINSETUPAPI BOOL SetupDiGetDevicePropertyW(
    [in] HDEVINFO DeviceInfoSet,
    [in] PSP_DEVINFO_DATA DeviceInfoData,
    [in] const DEVPROPKEY *PropertyKey,
    [out] DEVPROPTYPE *PropertyType,
    [out, optional] PBYTE PropertyBuffer,
    [in] DWORD PropertyBufferSize,
    [out, optional] PDWORD RequiredSize,
    [in] DWORD Flags
);

WINSETUPAPI BOOL SetupIterateCabinetA(
    [in] PCSTR CabinetFile,
    [in] DWORD Reserved,
    [in] PSP_FILE_CALLBACK_A MsgHandler,
    [in] PVOID Context
);

WINSETUPAPI BOOL SetupDiGetClassInstallParamsW(
    [in] HDEVINFO DeviceInfoSet,
    [in, optional] PSP_DEVINFO_DATA DeviceInfoData,
    [out, optional] PSP_CLASSINSTALL_HEADER ClassInstallParams,
    [in] DWORD ClassInstallParamsSize,
    [out, optional] PDWORD RequiredSize
);

WINSETUPAPI BOOL SetupDiEnumDriverInfoA(
    [in] HDEVINFO DeviceInfoSet,
    [in, optional] PSP_DEVINFO_DATA DeviceInfoData,
    [in] DWORD DriverType,
    [in] DWORD MemberIndex,
    [out] PSP_DRVINFO_DATA_A DriverInfoData
);

WINSETUPAPI BOOL SetupDiGetActualModelsSectionW(
    [in] PINFCONTEXT Context,
    [in, optional] PSP_ALTPLATFORM_INFO AlternatePlatformInfo,
    [out, optional] PWSTR InfSectionWithExt,
    [in] DWORD InfSectionWithExtSize,
    [out, optional] PDWORD RequiredSize,
    PVOID Reserved
);

WINSETUPAPI BOOL SetupQueryDrivesInDiskSpaceListA(
    [in] HDSKSPC DiskSpace,
    [in, out] PSTR ReturnBuffer,
    [in] DWORD ReturnBufferSize,
    [in, out] PDWORD RequiredSize
);

WINSETUPAPI BOOL SetupDiDestroyClassImageList(
    [in] PSP_CLASSIMAGELIST_DATA ClassImageListData
);

WINSETUPAPI HINF SetupOpenMasterInf();

WINSETUPAPI HDSKSPC SetupDuplicateDiskSpaceListA(
    [in] HDSKSPC DiskSpace,
    PVOID Reserved1,
    DWORD Reserved2,
    UINT Flags
);

WINSETUPAPI BOOL SetupDiGetClassDescriptionA(
    [in] const GUID *ClassGuid,
    [out] PSTR ClassDescription,
    [in] DWORD ClassDescriptionSize,
    [out, optional] PDWORD RequiredSize
);

WINSETUPAPI BOOL SetupDiSetClassInstallParamsA(
    [in] HDEVINFO DeviceInfoSet,
    [in, optional] PSP_DEVINFO_DATA DeviceInfoData,
    [in, optional] PSP_CLASSINSTALL_HEADER ClassInstallParams,
    [in] DWORD ClassInstallParamsSize
);

WINSETUPAPI BOOL SetupGetLineByIndexW(
    [in] HINF InfHandle,
    [in] PCWSTR Section,
    [in] DWORD Index,
    [in, out] PINFCONTEXT Context
);

WINSETUPAPI BOOL SetupDiGetDeviceRegistryPropertyA(
    [in] HDEVINFO DeviceInfoSet,
    [in] PSP_DEVINFO_DATA DeviceInfoData,
    [in] DWORD Property,
    [out, optional] PDWORD PropertyRegDataType,
    [out, optional] PBYTE PropertyBuffer,
    [in] DWORD PropertyBufferSize,
    [out, optional] PDWORD RequiredSize
);

WINSETUPAPI BOOL SetupDiGetHwProfileListExW(
    [out] PDWORD HwProfileList,
    [in] DWORD HwProfileListSize,
    [out] PDWORD RequiredSize,
    [out, optional] PDWORD CurrentlyActiveIndex,
    [in, optional] PCWSTR MachineName,
    PVOID Reserved
);

WINSETUPAPI UINT SetupRenameErrorW(
    [in] HWND hwndParent,
    [in] PCWSTR DialogTitle,
    [in] PCWSTR SourceFile,
    [in] PCWSTR TargetFile,
    [in] UINT Win32ErrorCode,
    [in] DWORD Style
);

WINSETUPAPI BOOL SetupGetInfInformationW(
    [in] LPCVOID InfSpec,
    [in] DWORD SearchControl,
    [in, out] PSP_INF_INFORMATION ReturnBuffer,
    [in] DWORD ReturnBufferSize,
    [in, out] PDWORD RequiredSize
);

WINSETUPAPI BOOL SetupDiGetClassImageIndex(
    [in] PSP_CLASSIMAGELIST_DATA ClassImageListData,
    [in] const GUID *ClassGuid,
    [out] PINT ImageIndex
);

WINSETUPAPI BOOL SetupDiGetClassDescriptionExA(
    [in] const GUID *ClassGuid,
    [out] PSTR ClassDescription,
    [in] DWORD ClassDescriptionSize,
    [out, optional] PDWORD RequiredSize,
    [in, optional] PCSTR MachineName,
    PVOID Reserved
);

WINSETUPAPI BOOL SetupQueueCopyIndirectW(
    [in] PSP_FILE_COPY_PARAMS_W CopyParams
);

WINSETUPAPI BOOL SetupQueueDeleteSectionW(
    [in] HSPFILEQ QueueHandle,
    [in] HINF InfHandle,
    [in] HINF ListInfHandle,
    [in] PCWSTR Section
);

WINSETUPAPI BOOL SetupDiGetClassDevPropertySheetsA(
    [in] HDEVINFO DeviceInfoSet,
    [in, optional] PSP_DEVINFO_DATA DeviceInfoData,
    [in] LPPROPSHEETHEADERA PropertySheetHeader,
    [in] DWORD PropertySheetHeaderPageListSize,
    [out, optional] PDWORD RequiredSize,
    [in] DWORD PropertySheetType
);

WINSETUPAPI UINT SetupPromptForDiskA(
    [in] HWND hwndParent,
    [in] PCSTR DialogTitle,
    [in] PCSTR DiskName,
    [in] PCSTR PathToSource,
    [in] PCSTR FileSought,
    [in] PCSTR TagFile,
    [in] DWORD DiskPromptStyle,
    [in, out] PSTR PathBuffer,
    [in] DWORD PathBufferSize,
    [in, out] PDWORD PathRequiredSize
);

WINSETUPAPI BOOL SetupDiGetHwProfileListExA(
    [out] PDWORD HwProfileList,
    [in] DWORD HwProfileListSize,
    [out] PDWORD RequiredSize,
    [out, optional] PDWORD CurrentlyActiveIndex,
    [in, optional] PCSTR MachineName,
    PVOID Reserved
);

WINSETUPAPI BOOL SetupLogFileW(
    [in] HSPFILELOG FileLogHandle,
    [in] PCWSTR LogSectionName,
    [in] PCWSTR SourceFilename,
    [in] PCWSTR TargetFilename,
    [in] DWORD Checksum,
    [in] PCWSTR DiskTagfile,
    [in] PCWSTR DiskDescription,
    [in] PCWSTR OtherInfo,
    [in] DWORD Flags
);

WINSETUPAPI BOOL SetupDiGetHwProfileFriendlyNameExA(
    [in] DWORD HwProfile,
    [out] PSTR FriendlyName,
    [in] DWORD FriendlyNameSize,
    [out, optional] PDWORD RequiredSize,
    [in, optional] PCSTR MachineName,
    PVOID Reserved
);

WINSETUPAPI BOOL SetupFindNextMatchLineA(
    [in] PINFCONTEXT ContextIn,
    [in] PCSTR Key,
    [in, out] PINFCONTEXT ContextOut
);

WINSETUPAPI BOOL SetupDiGetClassDescriptionExW(
    [in] const GUID *ClassGuid,
    [out] PWSTR ClassDescription,
    [in] DWORD ClassDescriptionSize,
    [out, optional] PDWORD RequiredSize,
    [in, optional] PCWSTR MachineName,
    PVOID Reserved
);

WINSETUPAPI BOOL SetupDiDeleteDevRegKey(
    [in] HDEVINFO DeviceInfoSet,
    [in] PSP_DEVINFO_DATA DeviceInfoData,
    [in] DWORD Scope,
    [in] DWORD HwProfile,
    [in] DWORD KeyType
);

WINSETUPAPI BOOL SetupQuerySourceListA(
    [in] DWORD Flags,
    [in, out] PCSTR **List,
    [in, out] PUINT Count
);

WINSETUPAPI BOOL SetupDiInstallClassW(
    [in, optional] HWND hwndParent,
    [in] PCWSTR InfFileName,
    [in] DWORD Flags,
    [in, optional] HSPFILEQ FileQueue
);

WINSETUPAPI BOOL SetupQuerySourceListW(
    [in] DWORD Flags,
    [in, out] PCWSTR **List,
    [in, out] PUINT Count
);

WINSETUPAPI BOOL SetupAddToDiskSpaceListW(
    [in] HDSKSPC DiskSpace,
    [in] PCWSTR TargetFilespec,
    [in] LONGLONG FileSize,
    [in] UINT Operation,
    [in] PVOID Reserved1,
    [in] UINT Reserved2
);

WINSETUPAPI BOOL SetupDiCreateDeviceInfoW(
    [in] HDEVINFO DeviceInfoSet,
    [in] PCWSTR DeviceName,
    [in] const GUID *ClassGuid,
    [in, optional] PCWSTR DeviceDescription,
    [in, optional] HWND hwndParent,
    [in] DWORD CreationFlags,
    [out, optional] PSP_DEVINFO_DATA DeviceInfoData
);

WINSETUPAPI BOOL SetupDiInstallDeviceInterfaces(
    [in] HDEVINFO DeviceInfoSet,
    [in] PSP_DEVINFO_DATA DeviceInfoData
);

WINSETUPAPI BOOL SetupSetFileQueueAlternatePlatformW(
    [in] HSPFILEQ QueueHandle,
    [in] PSP_ALTPLATFORM_INFO AlternatePlatformInfo,
    [in] PCWSTR AlternateDefaultCatalogFile
);

WINSETUPAPI BOOL SetupFindFirstLineA(
    [in] HINF InfHandle,
    [in] PCSTR Section,
    [in] PCSTR Key,
    [in, out] PINFCONTEXT Context
);

WINSETUPAPI BOOL SetupDiGetClassPropertyExW(
    [in] const GUID *ClassGuid,
    [in] const DEVPROPKEY *PropertyKey,
    [out] DEVPROPTYPE *PropertyType,
    [out, optional] PBYTE PropertyBuffer,
    [in] DWORD PropertyBufferSize,
    [out, optional] PDWORD RequiredSize,
    [in] DWORD Flags,
    [in, optional] PCWSTR MachineName,
    PVOID Reserved
);

WINSETUPAPI BOOL SetupScanFileQueueW(
    [in] HSPFILEQ FileQueue,
    [in] DWORD Flags,
    [in] HWND Window,
    [in] PSP_FILE_CALLBACK_W CallbackRoutine,
    [in] PVOID CallbackContext,
    [out] PDWORD Result
);

WINSETUPAPI BOOL SetupInstallFileExW(
    [in] HINF InfHandle,
    [in] PINFCONTEXT InfContext,
    [in] PCWSTR SourceFile,
    [in] PCWSTR SourcePathRoot,
    [in] PCWSTR DestinationName,
    [in] DWORD CopyStyle,
    [in] PSP_FILE_CALLBACK_W CopyMsgHandler,
    [in] PVOID Context,
    [out] PBOOL FileWasInUse
);

WINSETUPAPI LONG SetupGetLineCountW(
    [in] HINF InfHandle,
    [in] PCWSTR Section
);

WINSETUPAPI BOOL SetupFindNextLine(
    [in] PINFCONTEXT ContextIn,
    [out] PINFCONTEXT ContextOut
);

WINSETUPAPI BOOL SetupDiGetDeviceRegistryPropertyW(
    [in] HDEVINFO DeviceInfoSet,
    [in] PSP_DEVINFO_DATA DeviceInfoData,
    [in] DWORD Property,
    [out, optional] PDWORD PropertyRegDataType,
    [out, optional] PBYTE PropertyBuffer,
    [in] DWORD PropertyBufferSize,
    [out, optional] PDWORD RequiredSize
);

WINSETUPAPI BOOL SetupLogFileA(
    [in] HSPFILELOG FileLogHandle,
    [in] PCSTR LogSectionName,
    [in] PCSTR SourceFilename,
    [in] PCSTR TargetFilename,
    [in] DWORD Checksum,
    [in] PCSTR DiskTagfile,
    [in] PCSTR DiskDescription,
    [in] PCSTR OtherInfo,
    [in] DWORD Flags
);

WINSETUPAPI BOOL SetupQueryInfFileInformationA(
    [in] PSP_INF_INFORMATION InfInformation,
    [in] UINT InfIndex,
    [in, out] PSTR ReturnBuffer,
    [in] DWORD ReturnBufferSize,
    [in, out] PDWORD RequiredSize
);

WINSETUPAPI BOOL SetupSetNonInteractiveMode(
    [in] BOOL NonInteractiveFlag
);

WINSETUPAPI BOOL SetupDiUnremoveDevice(
    [in] HDEVINFO DeviceInfoSet,
    [in, out] PSP_DEVINFO_DATA DeviceInfoData
);

WINSETUPAPI BOOL SetupQueueCopyA(
    [in] HSPFILEQ QueueHandle,
    [in] PCSTR SourceRootPath,
    [in] PCSTR SourcePath,
    [in] PCSTR SourceFilename,
    [in] PCSTR SourceDescription,
    [in] PCSTR SourceTagfile,
    [in] PCSTR TargetDirectory,
    [in] PCSTR TargetFilename,
    [in] DWORD CopyStyle
);

void InstallHinfSectionW(
    [in] HWND Window,
    [in] HINSTANCE ModuleHandle,
    [in] PCWSTR CommandLine,
    [in] INT ShowCommand
);

WINSETUPAPI BOOL SetupAdjustDiskSpaceListA(
    [in] HDSKSPC DiskSpace,
    [in] LPCSTR DriveRoot,
    [in] LONGLONG Amount,
    PVOID Reserved1,
    UINT Reserved2
);

WINSETUPAPI BOOL SetupInstallFileExA(
    [in] HINF InfHandle,
    [in] PINFCONTEXT InfContext,
    [in] PCSTR SourceFile,
    [in] PCSTR SourcePathRoot,
    [in] PCSTR DestinationName,
    [in] DWORD CopyStyle,
    [in] PSP_FILE_CALLBACK_A CopyMsgHandler,
    [in] PVOID Context,
    [out] PBOOL FileWasInUse
);

WINSETUPAPI UINT SetupPromptForDiskW(
    [in] HWND hwndParent,
    [in] PCWSTR DialogTitle,
    [in] PCWSTR DiskName,
    [in] PCWSTR PathToSource,
    [in] PCWSTR FileSought,
    [in] PCWSTR TagFile,
    [in] DWORD DiskPromptStyle,
    [in, out] PWSTR PathBuffer,
    [in] DWORD PathBufferSize,
    [in, out] PDWORD PathRequiredSize
);

WINSETUPAPI BOOL SetupQueueDeleteW(
    [in] HSPFILEQ QueueHandle,
    [in] PCWSTR PathPart1,
    [in] PCWSTR PathPart2
);

WINSETUPAPI BOOL SetupSetDirectoryIdA(
    [in] HINF InfHandle,
    [in] DWORD Id,
    [in] PCSTR Directory
);

WINSETUPAPI BOOL SetupDiDeleteDeviceInterfaceData(
    [in] HDEVINFO DeviceInfoSet,
    [in] PSP_DEVICE_INTERFACE_DATA DeviceInterfaceData
);

WINSETUPAPI BOOL SetupDiClassNameFromGuidW(
    [in] const GUID *ClassGuid,
    [out] PWSTR ClassName,
    [in] DWORD ClassNameSize,
    [out, optional] PDWORD RequiredSize
);

WINSETUPAPI BOOL SetupInstallFromInfSectionW(
    HWND Owner,
    HINF InfHandle,
    PCWSTR SectionName,
    UINT Flags,
    HKEY RelativeKeyRoot,
    PCWSTR SourceRootPath,
    UINT CopyFlags,
    PSP_FILE_CALLBACK_W MsgHandler,
    PVOID Context,
    HDEVINFO DeviceInfoSet,
    PSP_DEVINFO_DATA DeviceInfoData
);

WINSETUPAPI VOID SetupSetThreadLogToken(
    [in] SP_LOG_TOKEN LogToken
);

WINSETUPAPI BOOL SetupConfigureWmiFromInfSectionA(
    [in] HINF InfHandle,
    [in] PCSTR SectionName,
    [in] DWORD Flags
);

WINSETUPAPI BOOL SetupQueryFileLogA(
    [in] HSPFILELOG FileLogHandle,
    [in] PCSTR LogSectionName,
    [in] PCSTR TargetFilename,
    [in] SetupFileLogInfo DesiredInfo,
    [in, out] PSTR DataOut,
    [in] DWORD ReturnBufferSize,
    [in, out] PDWORD RequiredSize
);

WINSETUPAPI PVOID SetupInitDefaultQueueCallbackEx(
    [in] HWND OwnerWindow,
    [in] HWND AlternateProgressWindow,
    [in] UINT ProgressMessage,
    [in] DWORD Reserved1,
    [in] PVOID Reserved2
);

WINSETUPAPI BOOL SetupQueueCopySectionA(
    [in] HSPFILEQ QueueHandle,
    [in] PCSTR SourceRootPath,
    [in] HINF InfHandle,
    [in] HINF ListInfHandle,
    [in] PCSTR Section,
    [in] DWORD CopyStyle
);

WINSETUPAPI BOOL SetupDiSetClassPropertyExW(
    [in] const GUID *ClassGuid,
    [in] const DEVPROPKEY *PropertyKey,
    [in] DEVPROPTYPE PropertyType,
    [in, optional] const PBYTE PropertyBuffer,
    [in] DWORD PropertyBufferSize,
    [in] DWORD Flags,
    [in, optional] PCWSTR MachineName,
    PVOID Reserved
);

WINSETUPAPI HINF SetupOpenInfFileW(
    [in] PCWSTR FileName,
    [in] PCWSTR InfClass,
    [in] DWORD InfStyle,
    [in] PUINT ErrorLine
);

WINSETUPAPI BOOL SetupDiSetSelectedDriverA(
    [in] HDEVINFO DeviceInfoSet,
    [in, out] PSP_DEVINFO_DATA DeviceInfoData,
    [in, out] PSP_DRVINFO_DATA_A DriverInfoData
);

WINSETUPAPI BOOL SetupGetSourceFileSizeW(
    [in] HINF InfHandle,
    [in] PINFCONTEXT InfContext,
    [in] PCWSTR FileName,
    [in] PCWSTR Section,
    [in, out] PDWORD FileSize,
    [in] UINT RoundingFactor
);

WINSETUPAPI BOOL SetupDiOpenDeviceInterfaceW(
    [in] HDEVINFO DeviceInfoSet,
    [in] PCWSTR DevicePath,
    [in] DWORD OpenFlags,
    [out, optional] PSP_DEVICE_INTERFACE_DATA DeviceInterfaceData
);

WINSETUPAPI BOOL SetupGetInfPublishedNameW(
    [in] PCWSTR DriverStoreLocation,
    [out] PWSTR ReturnBuffer,
    [in] DWORD ReturnBufferSize,
    [out, optional] PDWORD RequiredSize
);

WINSETUPAPI BOOL SetupDiEnumDriverInfoW(
    [in] HDEVINFO DeviceInfoSet,
    [in, optional] PSP_DEVINFO_DATA DeviceInfoData,
    [in] DWORD DriverType,
    [in] DWORD MemberIndex,
    [out] PSP_DRVINFO_DATA_W DriverInfoData
);

WINSETUPAPI BOOL SetupQueueDeleteSectionA(
    [in] HSPFILEQ QueueHandle,
    [in] HINF InfHandle,
    [in] HINF ListInfHandle,
    [in] PCSTR Section
);

WINSETUPAPI UINT SetupBackupErrorW(
    [in] HWND hwndParent,
    [in] PCWSTR DialogTitle,
    [in] PCWSTR SourceFile,
    [in] PCWSTR TargetFile,
    [out] UINT Win32ErrorCode,
    [in] DWORD Style
);

WINSETUPAPI BOOL SetupDiSetDeviceInterfaceDefault(
    [in] HDEVINFO DeviceInfoSet,
    [in, out] PSP_DEVICE_INTERFACE_DATA DeviceInterfaceData,
    [in] DWORD Flags,
    PVOID Reserved
);

WINSETUPAPI BOOL SetupRemoveInstallSectionFromDiskSpaceListW(
    [in] HDSKSPC DiskSpace,
    [in] HINF InfHandle,
    [in] HINF LayoutInfHandle,
    [in] PCWSTR SectionName,
    [in] PVOID Reserved1,
    [in] UINT Reserved2
);

WINSETUPAPI BOOL SetupQueueRenameSectionW(
    [in] HSPFILEQ QueueHandle,
    [in] HINF InfHandle,
    [in] HINF ListInfHandle,
    [in] PCWSTR Section
);

WINSETUPAPI BOOL SetupDestroyDiskSpaceList(
    [in, out] HDSKSPC DiskSpace
);

WINSETUPAPI BOOL SetupInstallServicesFromInfSectionW(
    [in] HINF InfHandle,
    [in] PCWSTR SectionName,
    [in] DWORD Flags
);

WINSETUPAPI BOOL SetupGetTargetPathA(
    [in] HINF InfHandle,
    [in] PINFCONTEXT InfContext,
    [in] PCSTR Section,
    [in, out] PSTR ReturnBuffer,
    [in] DWORD ReturnBufferSize,
    [in, out] PDWORD RequiredSize
);

WINSETUPAPI BOOL SetupUninstallNewlyCopiedInfs(
    [in] HSPFILEQ FileQueue,
    [in] DWORD Flags,
    [in] PVOID Reserved
);

WINSETUPAPI BOOL SetupEnumInfSectionsA(
    [in] HINF InfHandle,
    [in] UINT Index,
    [out, optional] PSTR Buffer,
    [in] UINT Size,
    [out, optional] UINT *SizeNeeded
);

WINSETUPAPI BOOL SetupDiSetClassRegistryPropertyA(
    [in] const GUID *ClassGuid,
    [in] DWORD Property,
    [in, optional] const BYTE *PropertyBuffer,
    [in] DWORD PropertyBufferSize,
    [in, optional] PCSTR MachineName,
    PVOID Reserved
);

WINSETUPAPI BOOL SetupAddInstallSectionToDiskSpaceListW(
    [in] HDSKSPC DiskSpace,
    [in] HINF InfHandle,
    [in] HINF LayoutInfHandle,
    [in] PCWSTR SectionName,
    [in] PVOID Reserved1,
    [in] UINT Reserved2
);

WINSETUPAPI BOOL SetupDiSetDeviceRegistryPropertyA(
    [in] HDEVINFO DeviceInfoSet,
    [in, out] PSP_DEVINFO_DATA DeviceInfoData,
    [in] DWORD Property,
    [in, optional] const BYTE *PropertyBuffer,
    [in] DWORD PropertyBufferSize
);

WINSETUPAPI BOOL SetupDiGetClassPropertyW(
    [in] const GUID *ClassGuid,
    [in] const DEVPROPKEY *PropertyKey,
    [out] DEVPROPTYPE *PropertyType,
    [out] PBYTE PropertyBuffer,
    [in] DWORD PropertyBufferSize,
    [out, optional] PDWORD RequiredSize,
    [in] DWORD Flags
);

WINSETUPAPI HDEVINFO SetupDiGetClassDevsExA(
    [in, optional] const GUID *ClassGuid,
    [in, optional] PCSTR Enumerator,
    [in, optional] HWND hwndParent,
    [in] DWORD Flags,
    [in, optional] HDEVINFO DeviceInfoSet,
    [in, optional] PCSTR MachineName,
    PVOID Reserved
);

WINSETUPAPI HKEY SetupDiCreateDevRegKeyA(
    [in] HDEVINFO DeviceInfoSet,
    [in] PSP_DEVINFO_DATA DeviceInfoData,
    [in] DWORD Scope,
    [in] DWORD HwProfile,
    [in] DWORD KeyType,
    [in, optional] HINF InfHandle,
    [in, optional] PCSTR InfSectionName
);

WINSETUPAPI BOOL SetupQueueCopyW(
    [in] HSPFILEQ QueueHandle,
    [in] PCWSTR SourceRootPath,
    [in] PCWSTR SourcePath,
    [in] PCWSTR SourceFilename,
    [in] PCWSTR SourceDescription,
    [in] PCWSTR SourceTagfile,
    [in] PCWSTR TargetDirectory,
    [in] PCWSTR TargetFilename,
    [in] DWORD CopyStyle
);

WINSETUPAPI BOOL SetupSetDirectoryIdW(
    [in] HINF InfHandle,
    [in] DWORD Id,
    [in] PCWSTR Directory
);

WINSETUPAPI BOOL SetupUninstallOEMInfW(
    [in] PCWSTR InfFileName,
    [in] DWORD Flags,
    [in] PVOID Reserved
);

WINSETUPAPI BOOL SetupQueueDeleteA(
    [in] HSPFILEQ QueueHandle,
    [in] PCSTR PathPart1,
    [in] PCSTR PathPart2
);

WINSETUPAPI BOOL SetupAdjustDiskSpaceListW(
    [in] HDSKSPC DiskSpace,
    [in] LPCWSTR DriveRoot,
    [in] LONGLONG Amount,
    PVOID Reserved1,
    UINT Reserved2
);

WINSETUPAPI BOOL SetupDiSelectBestCompatDrv(
    [in] HDEVINFO DeviceInfoSet,
    [in, out] PSP_DEVINFO_DATA DeviceInfoData
);

WINSETUPAPI BOOL SetupQueueCopySectionW(
    [in] HSPFILEQ QueueHandle,
    [in] PCWSTR SourceRootPath,
    [in] HINF InfHandle,
    [in] HINF ListInfHandle,
    [in] PCWSTR Section,
    [in] DWORD CopyStyle
);

WINSETUPAPI BOOL SetupDiGetClassImageList(
    [out] PSP_CLASSIMAGELIST_DATA ClassImageListData
);

WINSETUPAPI BOOL SetupGetSourceInfoA(
    [in] HINF InfHandle,
    [in] UINT SourceId,
    [in] UINT InfoDesired,
    [in, out] PSTR ReturnBuffer,
    [in] DWORD ReturnBufferSize,
    [in, out] PDWORD RequiredSize
);

WINSETUPAPI BOOL SetupDiSetClassRegistryPropertyW(
    [in] const GUID *ClassGuid,
    [in] DWORD Property,
    [in, optional] const BYTE *PropertyBuffer,
    [in] DWORD PropertyBufferSize,
    [in, optional] PCWSTR MachineName,
    PVOID Reserved
);

WINSETUPAPI HSPFILELOG SetupInitializeFileLogW(
    [in] PCWSTR LogFileName,
    [in] DWORD Flags
);

WINSETUPAPI BOOL SetupQuerySpaceRequiredOnDriveA(
    [in] HDSKSPC DiskSpace,
    [in] PCSTR DriveSpec,
    [out] LONGLONG *SpaceRequired,
    [in] PVOID Reserved1,
    [in] UINT Reserved2
);

WINSETUPAPI BOOL SetupDiGetHwProfileFriendlyNameExW(
    [in] DWORD HwProfile,
    [out] PWSTR FriendlyName,
    [in] DWORD FriendlyNameSize,
    [out, optional] PDWORD RequiredSize,
    [in, optional] PCWSTR MachineName,
    PVOID Reserved
);

WINSETUPAPI HKEY SetupDiCreateDeviceInterfaceRegKeyW(
    [in] HDEVINFO DeviceInfoSet,
    [in] PSP_DEVICE_INTERFACE_DATA DeviceInterfaceData,
    DWORD Reserved,
    [in] REGSAM samDesired,
    [in, optional] HINF InfHandle,
    [in, optional] PCWSTR InfSectionName
);

WINSETUPAPI DWORD SetupGetFileCompressionInfoA(
    [in] PCSTR SourceFileName,
    [in, out] PSTR *ActualSourceFileName,
    [in, out] PDWORD SourceFileSize,
    [in, out] PDWORD TargetFileSize,
    [in, out] PUINT CompressionType
);

WINSETUPAPI SP_LOG_TOKEN SetupGetThreadLogToken();

WINSETUPAPI BOOL SetupDiGetClassInstallParamsA(
    [in] HDEVINFO DeviceInfoSet,
    [in, optional] PSP_DEVINFO_DATA DeviceInfoData,
    [out, optional] PSP_CLASSINSTALL_HEADER ClassInstallParams,
    [in] DWORD ClassInstallParamsSize,
    [out, optional] PDWORD RequiredSize
);

WINSETUPAPI BOOL SetupEnumInfSectionsW(
    [in] HINF InfHandle,
    [in] UINT Index,
    [out, optional] PWSTR Buffer,
    [in] UINT Size,
    [out, optional] UINT *SizeNeeded
);

WINSETUPAPI BOOL SetupDiGetClassPropertyKeys(
    [in] const GUID *ClassGuid,
    [out, optional] DEVPROPKEY *PropertyKeyArray,
    [in] DWORD PropertyKeyCount,
    [out, optional] PDWORD RequiredPropertyKeyCount,
    [in] DWORD Flags
);

WINSETUPAPI BOOL SetupRemoveSectionFromDiskSpaceListW(
    [in] HDSKSPC DiskSpace,
    [in] HINF InfHandle,
    [in] HINF ListInfHandle,
    [in] PCWSTR SectionName,
    [in] UINT Operation,
    [in] PVOID Reserved1,
    [in] UINT Reserved2
);

WINSETUPAPI BOOL SetupDiSetSelectedDriverW(
    [in] HDEVINFO DeviceInfoSet,
    [in, out] PSP_DEVINFO_DATA DeviceInfoData,
    [in, out] PSP_DRVINFO_DATA_W DriverInfoData
);

WINSETUPAPI BOOL SetupDiGetDeviceInterfaceDetailA(
    [in] HDEVINFO DeviceInfoSet,
    [in] PSP_DEVICE_INTERFACE_DATA DeviceInterfaceData,
    [out, optional] PSP_DEVICE_INTERFACE_DETAIL_DATA_A DeviceInterfaceDetailData,
    [in] DWORD DeviceInterfaceDetailDataSize,
    [out, optional] PDWORD RequiredSize,
    [out, optional] PSP_DEVINFO_DATA DeviceInfoData
);

WINSETUPAPI VOID SetupTermDefaultQueueCallback(
    [in] PVOID Context
);

WINSETUPAPI UINT SetupRenameErrorA(
    [in] HWND hwndParent,
    [in] PCSTR DialogTitle,
    [in] PCSTR SourceFile,
    [in] PCSTR TargetFile,
    [in] UINT Win32ErrorCode,
    [in] DWORD Style
);

WINSETUPAPI BOOL SetupSetDirectoryIdExW(
    [in] HINF InfHandle,
    [in] DWORD Id,
    [in] PCWSTR Directory,
    [in] DWORD Flags,
    DWORD Reserved1,
    PVOID Reserved2
);

WINSETUPAPI HSPFILELOG SetupInitializeFileLogA(
    [in] PCSTR LogFileName,
    [in] DWORD Flags
);

WINSETUPAPI BOOL SetupQueueRenameW(
    [in] HSPFILEQ QueueHandle,
    [in] PCWSTR SourcePath,
    [in] PCWSTR SourceFilename,
    [in] PCWSTR TargetPath,
    [in] PCWSTR TargetFilename
);

WINSETUPAPI BOOL SetupDiGetActualSectionToInstallExW(
    [in] HINF InfHandle,
    [in] PCWSTR InfSectionName,
    [in, optional] PSP_ALTPLATFORM_INFO AlternatePlatformInfo,
    [out, optional] PWSTR InfSectionWithExt,
    [in] DWORD InfSectionWithExtSize,
    [out, optional] PDWORD RequiredSize,
    [out, optional] PWSTR *Extension,
    PVOID Reserved
);

WINSETUPAPI BOOL SetupGetMultiSzFieldA(
    [in] PINFCONTEXT Context,
    [in] DWORD FieldIndex,
    [in, out] PSTR ReturnBuffer,
    [in] DWORD ReturnBufferSize,
    [in] LPDWORD RequiredSize
);

WINSETUPAPI BOOL SetupDiRestartDevices(
    [in] HDEVINFO DeviceInfoSet,
    [in, out] PSP_DEVINFO_DATA DeviceInfoData
);

WINSETUPAPI UINT SetupDeleteErrorA(
    [in] HWND hwndParent,
    [in] PCSTR DialogTitle,
    [in] PCSTR File,
    [out] UINT Win32ErrorCode,
    [in] DWORD Style
);

WINSETUPAPI BOOL SetupDiGetINFClassA(
    [in] PCSTR InfName,
    [out] LPGUID ClassGuid,
    [out] PSTR ClassName,
    [in] DWORD ClassNameSize,
    [out, optional] PDWORD RequiredSize
);

WINSETUPAPI BOOL SetupQueryFileLogW(
    [in] HSPFILELOG FileLogHandle,
    [in] PCWSTR LogSectionName,
    [in] PCWSTR TargetFilename,
    [in] SetupFileLogInfo DesiredInfo,
    [in, out] PWSTR DataOut,
    [in] DWORD ReturnBufferSize,
    [in, out] PDWORD RequiredSize
);

WINSETUPAPI BOOL SetupDiGetClassImageListExW(
    [out] PSP_CLASSIMAGELIST_DATA ClassImageListData,
    [in, optional] PCWSTR MachineName,
    PVOID Reserved
);

WINSETUPAPI BOOL SetupGetInfFileListA(
    [in] PCSTR DirectoryPath,
    [in] DWORD InfStyle,
    [in, out] PSTR ReturnBuffer,
    [in] DWORD ReturnBufferSize,
    [in, out] PDWORD RequiredSize
);

WINSETUPAPI BOOL SetupSetFileQueueFlags(
    [in] HSPFILEQ FileQueue,
    [in] DWORD FlagMask,
    [in] DWORD Flags
);

WINSETUPAPI BOOL SetupDiGetSelectedDriverA(
    [in] HDEVINFO DeviceInfoSet,
    [in, optional] PSP_DEVINFO_DATA DeviceInfoData,
    [out] PSP_DRVINFO_DATA_A DriverInfoData
);

WINSETUPAPI UINT SetupCopyErrorA(
    [in] HWND hwndParent,
    [in] PCSTR DialogTitle,
    [in] PCSTR DiskName,
    [in] PCSTR PathToSource,
    [in] PCSTR SourceFile,
    [in] PCSTR TargetPathFile,
    [out] UINT Win32ErrorCode,
    [in] DWORD Style,
    [in, out] PSTR PathBuffer,
    [in] DWORD PathBufferSize,
    [in, out] PDWORD PathRequiredSize
);

WINSETUPAPI BOOL SetupDiGetSelectedDevice(
    [in] HDEVINFO DeviceInfoSet,
    [out] PSP_DEVINFO_DATA DeviceInfoData
);

WINSETUPAPI BOOL SetupQuerySpaceRequiredOnDriveW(
    [in] HDSKSPC DiskSpace,
    [in] PCWSTR DriveSpec,
    [out] LONGLONG *SpaceRequired,
    [in] PVOID Reserved1,
    [in] UINT Reserved2
);

WINSETUPAPI BOOL SetupDiGetCustomDevicePropertyA(
    [in] HDEVINFO DeviceInfoSet,
    [in] PSP_DEVINFO_DATA DeviceInfoData,
    [in] PCSTR CustomPropertyName,
    [in] DWORD Flags,
    [out, optional] PDWORD PropertyRegDataType,
    [out] PBYTE PropertyBuffer,
    [in] DWORD PropertyBufferSize,
    [out, optional] PDWORD RequiredSize
);

WINSETUPAPI BOOL SetupGetStringFieldA(
    [in] PINFCONTEXT Context,
    [in] DWORD FieldIndex,
    [in, out] PSTR ReturnBuffer,
    [in] DWORD ReturnBufferSize,
    [out] PDWORD RequiredSize
);

WINSETUPAPI BOOL SetupSetDirectoryIdExA(
    [in] HINF InfHandle,
    [in] DWORD Id,
    [in] PCSTR Directory,
    [in] DWORD Flags,
    DWORD Reserved1,
    PVOID Reserved2
);

WINSETUPAPI BOOL SetupQueueRenameA(
    [in] HSPFILEQ QueueHandle,
    [in] PCSTR SourcePath,
    [in] PCSTR SourceFilename,
    [in] PCSTR TargetPath,
    [in] PCSTR TargetFilename
);

WINSETUPAPI BOOL SetupDiClassGuidsFromNameExA(
    [in] PCSTR ClassName,
    [out] LPGUID ClassGuidList,
    [in] DWORD ClassGuidListSize,
    [out] PDWORD RequiredSize,
    [in, optional] PCSTR MachineName,
    PVOID Reserved
);

WINSETUPAPI BOOL SetupQueueDefaultCopyW(
    [in] HSPFILEQ QueueHandle,
    [in] HINF InfHandle,
    [in] PCWSTR SourceRootPath,
    [in] PCWSTR SourceFilename,
    [in] PCWSTR TargetFilename,
    [in] DWORD CopyStyle
);

WINSETUPAPI BOOL SetupDiCreateDeviceInfoA(
    [in] HDEVINFO DeviceInfoSet,
    [in] PCSTR DeviceName,
    [in] const GUID *ClassGuid,
    [in, optional] PCSTR DeviceDescription,
    [in, optional] HWND hwndParent,
    [in] DWORD CreationFlags,
    [out, optional] PSP_DEVINFO_DATA DeviceInfoData
);

WINSETUPAPI BOOL SetupGetLineTextW(
    [in] PINFCONTEXT Context,
    [in] HINF InfHandle,
    [in] PCWSTR Section,
    [in] PCWSTR Key,
    [in, out] PWSTR ReturnBuffer,
    [in] DWORD ReturnBufferSize,
    [in, out] PDWORD RequiredSize
);

WINSETUPAPI VOID SetupWriteTextLogInfLine(
    [in] SP_LOG_TOKEN LogToken,
    [in] DWORD Flags,
    [in] HINF InfHandle,
    [in] PINFCONTEXT Context
);

WINSETUPAPI BOOL SetupSetSourceListA(
    [in] DWORD Flags,
    [in] PCSTR *SourceList,
    [in] UINT SourceCount
);

WINSETUPAPI BOOL SetupOpenAppendInfFileW(
    [in] PCWSTR FileName,
    [in] HINF InfHandle,
    [in, out] PUINT ErrorLine
);

WINSETUPAPI BOOL SetupDiClassGuidsFromNameExW(
    [in] PCWSTR ClassName,
    [out] LPGUID ClassGuidList,
    [in] DWORD ClassGuidListSize,
    [out] PDWORD RequiredSize,
    [in, optional] PCWSTR MachineName,
    PVOID Reserved
);

WINSETUPAPI BOOL SetupQueryInfVersionInformationA(
    [in] PSP_INF_INFORMATION InfInformation,
    [in] UINT InfIndex,
    [in] PCSTR Key,
    [in, out] PSTR ReturnBuffer,
    [in] DWORD ReturnBufferSize,
    [in, out] PDWORD RequiredSize
);

WINSETUPAPI BOOL SetupDiClassNameFromGuidExW(
    [in] const GUID *ClassGuid,
    [out] PWSTR ClassName,
    [in] DWORD ClassNameSize,
    [out, optional] PDWORD RequiredSize,
    [in, optional] PCWSTR MachineName,
    PVOID Reserved
);

WINSETUPAPI BOOL SetupQueueDefaultCopyA(
    [in] HSPFILEQ QueueHandle,
    [in] HINF InfHandle,
    [in] PCSTR SourceRootPath,
    [in] PCSTR SourceFilename,
    [in] PCSTR TargetFilename,
    [in] DWORD CopyStyle
);

WINSETUPAPI BOOL SetupAddSectionToDiskSpaceListA(
    [in] HDSKSPC DiskSpace,
    [in] HINF InfHandle,
    [in] HINF ListInfHandle,
    [in] PCSTR SectionName,
    [in] UINT Operation,
    [in] PVOID Reserved1,
    [in] UINT Reserved2
);

WINSETUPAPI BOOL SetupDiSetDriverInstallParamsW(
    [in] HDEVINFO DeviceInfoSet,
    [in, optional] PSP_DEVINFO_DATA DeviceInfoData,
    [in] PSP_DRVINFO_DATA_W DriverInfoData,
    [in] PSP_DRVINSTALL_PARAMS DriverInstallParams
);

WINSETUPAPI BOOL SetupDiInstallDevice(
    [in] HDEVINFO DeviceInfoSet,
    [in, out] PSP_DEVINFO_DATA DeviceInfoData
);

WINSETUPAPI BOOL SetupRemoveFromDiskSpaceListW(
    [in] HDSKSPC DiskSpace,
    [in] PCWSTR TargetFilespec,
    [in] UINT Operation,
    [in] PVOID Reserved1,
    [in] UINT Reserved2
);

WINSETUPAPI BOOL SetupDiGetActualModelsSectionA(
    [in] PINFCONTEXT Context,
    [in, optional] PSP_ALTPLATFORM_INFO AlternatePlatformInfo,
    [out, optional] PSTR InfSectionWithExt,
    [in] DWORD InfSectionWithExtSize,
    [out, optional] PDWORD RequiredSize,
    PVOID Reserved
);

WINSETUPAPI BOOL SetupQueryInfFileInformationW(
    [in] PSP_INF_INFORMATION InfInformation,
    [in] UINT InfIndex,
    [in, out] PWSTR ReturnBuffer,
    [in] DWORD ReturnBufferSize,
    [in, out] PDWORD RequiredSize
);

WINSETUPAPI BOOL SetupVerifyInfFileW(
    [in] PCWSTR InfName,
    [in] PSP_ALTPLATFORM_INFO AltPlatformInfo,
    [out] PSP_INF_SIGNER_INFO_W InfSignerInfo
);

WINSETUPAPI BOOL SetupDiRegisterDeviceInfo(
    [in] HDEVINFO DeviceInfoSet,
    [in, out] PSP_DEVINFO_DATA DeviceInfoData,
    [in] DWORD Flags,
    [in, optional] PSP_DETSIG_CMPPROC CompareProc,
    [in, optional] PVOID CompareContext,
    [out, optional] PSP_DEVINFO_DATA DupDeviceInfoData
);

WINSETUPAPI BOOL SetupDiGetDeviceInstallParamsW(
    [in] HDEVINFO DeviceInfoSet,
    [in, optional] PSP_DEVINFO_DATA DeviceInfoData,
    [out] PSP_DEVINSTALL_PARAMS_W DeviceInstallParams
);

WINSETUPAPI BOOL SetupConfigureWmiFromInfSectionW(
    [in] HINF InfHandle,
    [in] PCWSTR SectionName,
    [in] DWORD Flags
);

WINSETUPAPI VOID SetupCloseInfFile(
    [in] HINF InfHandle
);

WINSETUPAPI BOOL SetupFreeSourceListW(
    [in, out] PCWSTR **List,
    [in] UINT Count
);

WINSETUPAPI BOOL SetupQueueCopyIndirectA(
    [in] PSP_FILE_COPY_PARAMS_A CopyParams
);

WINSETUPAPI BOOL SetupQueryInfVersionInformationW(
    [in] PSP_INF_INFORMATION InfInformation,
    [in] UINT InfIndex,
    [in] PCWSTR Key,
    [in, out] PWSTR ReturnBuffer,
    [in] DWORD ReturnBufferSize,
    [in, out] PDWORD RequiredSize
);

WINSETUPAPI BOOL SetupDiInstallClassExW(
    [in, optional] HWND hwndParent,
    [in, optional] PCWSTR InfFileName,
    [in] DWORD Flags,
    [in, optional] HSPFILEQ FileQueue,
    [in, optional] const GUID *InterfaceClassGuid,
    PVOID Reserved1,
    PVOID Reserved2
);

WINSETUPAPI BOOL SetupGetFileCompressionInfoExW(
    [in] PCWSTR SourceFileName,
    [in, out] PWSTR ActualSourceFileNameBuffer,
    [in, out] DWORD ActualSourceFileNameBufferLen,
    [out] PDWORD RequiredBufferLen,
    [out] PDWORD SourceFileSize,
    [out] PDWORD TargetFileSize,
    [out] PUINT CompressionType
);

WINSETUPAPI VOID SetupCloseLog();

WINSETUPAPI BOOL SetupDiGetDeviceInterfacePropertyW(
    [in] HDEVINFO DeviceInfoSet,
    [in] PSP_DEVICE_INTERFACE_DATA DeviceInterfaceData,
    [in] const DEVPROPKEY *PropertyKey,
    [out] DEVPROPTYPE *PropertyType,
    [out] PBYTE PropertyBuffer,
    [in] DWORD PropertyBufferSize,
    [out, optional] PDWORD RequiredSize,
    [in] DWORD Flags
);

WINSETUPAPI BOOL SetupDiDestroyDeviceInfoList(
    [in] HDEVINFO DeviceInfoSet
);

WINSETUPAPI BOOL SetupGetLineTextA(
    [in] PINFCONTEXT Context,
    [in] HINF InfHandle,
    [in] PCSTR Section,
    [in] PCSTR Key,
    [in, out] PSTR ReturnBuffer,
    [in] DWORD ReturnBufferSize,
    [in, out] PDWORD RequiredSize
);

WINSETUPAPI BOOL SetupDiRemoveDeviceInterface(
    [in] HDEVINFO DeviceInfoSet,
    [in, out] PSP_DEVICE_INTERFACE_DATA DeviceInterfaceData
);

WINSETUPAPI BOOL SetupGetInfDriverStoreLocationA(
    [in] PCSTR FileName,
    [in, optional] PSP_ALTPLATFORM_INFO AlternatePlatformInfo,
    [in, optional] PCSTR LocaleName,
    [out] PSTR ReturnBuffer,
    [in] DWORD ReturnBufferSize,
    [out, optional] PDWORD RequiredSize
);

WINSETUPAPI BOOL SetupDiGetDeviceInstanceIdA(
    [in] HDEVINFO DeviceInfoSet,
    [in] PSP_DEVINFO_DATA DeviceInfoData,
    [out, optional] PSTR DeviceInstanceId,
    [in] DWORD DeviceInstanceIdSize,
    [out, optional] PDWORD RequiredSize
);

WINSETUPAPI BOOL SetupDiSetClassPropertyW(
    [in] const GUID *ClassGuid,
    [in] const DEVPROPKEY *PropertyKey,
    [in] DEVPROPTYPE PropertyType,
    [in, optional] const PBYTE PropertyBuffer,
    [in] DWORD PropertyBufferSize,
    [in] DWORD Flags
);

WINSETUPAPI BOOL SetupDiSetDeviceRegistryPropertyW(
    [in] HDEVINFO DeviceInfoSet,
    [in, out] PSP_DEVINFO_DATA DeviceInfoData,
    [in] DWORD Property,
    [in, optional] const BYTE *PropertyBuffer,
    [in] DWORD PropertyBufferSize
);

WINSETUPAPI INT SetupPromptReboot(
    [in] HSPFILEQ FileQueue,
    [in] HWND Owner,
    [in] BOOL ScanOnly
);

WINSETUPAPI BOOL SetupDiCreateDeviceInterfaceW(
    [in] HDEVINFO DeviceInfoSet,
    [in] PSP_DEVINFO_DATA DeviceInfoData,
    [in] const GUID *InterfaceClassGuid,
    [in, optional] PCWSTR ReferenceString,
    [in] DWORD CreationFlags,
    [out, optional] PSP_DEVICE_INTERFACE_DATA DeviceInterfaceData
);

WINSETUPAPI HKEY SetupDiOpenClassRegKeyExA(
    [in, optional] const GUID *ClassGuid,
    [in] REGSAM samDesired,
    [in] DWORD Flags,
    [in, optional] PCSTR MachineName,
    PVOID Reserved
);

WINSETUPAPI BOOL SetupDiGetDeviceInfoListDetailW(
    [in] HDEVINFO DeviceInfoSet,
    [out] PSP_DEVINFO_LIST_DETAIL_DATA_W DeviceInfoSetDetailData
);

WINSETUPAPI BOOL SetupLogErrorW(
    [in] LPCWSTR MessageString,
    [in] LogSeverity Severity
);

WINSETUPAPI HDEVINFO SetupDiGetClassDevsExW(
    [in, optional] const GUID *ClassGuid,
    [in, optional] PCWSTR Enumerator,
    [in, optional] HWND hwndParent,
    [in] DWORD Flags,
    [in, optional] HDEVINFO DeviceInfoSet,
    [in, optional] PCWSTR MachineName,
    PVOID Reserved
);

WINSETUPAPI BOOL SetupDiGetINFClassW(
    [in] PCWSTR InfName,
    [out] LPGUID ClassGuid,
    [out] PWSTR ClassName,
    [in] DWORD ClassNameSize,
    [out, optional] PDWORD RequiredSize
);

WINSETUPAPI BOOL SetupDiGetCustomDevicePropertyW(
    [in] HDEVINFO DeviceInfoSet,
    [in] PSP_DEVINFO_DATA DeviceInfoData,
    [in] PCWSTR CustomPropertyName,
    [in] DWORD Flags,
    [out, optional] PDWORD PropertyRegDataType,
    [out] PBYTE PropertyBuffer,
    [in] DWORD PropertyBufferSize,
    [out, optional] PDWORD RequiredSize
);

WINSETUPAPI BOOL SetupDiSetDeviceInterfacePropertyW(
    [in] HDEVINFO DeviceInfoSet,
    [in] PSP_DEVICE_INTERFACE_DATA DeviceInterfaceData,
    [in] const DEVPROPKEY *PropertyKey,
    [in] DEVPROPTYPE PropertyType,
    [in, optional] const PBYTE PropertyBuffer,
    [in] DWORD PropertyBufferSize,
    [in] DWORD Flags
);

WINSETUPAPI BOOL SetupDiCallClassInstaller(
    [in] DI_FUNCTION InstallFunction,
    [in] HDEVINFO DeviceInfoSet,
    [in, optional] PSP_DEVINFO_DATA DeviceInfoData
);

WINSETUPAPI BOOL SetupInstallFileW(
    [in] HINF InfHandle,
    [in] PINFCONTEXT InfContext,
    [in] PCWSTR SourceFile,
    [in] PCWSTR SourcePathRoot,
    [in] PCWSTR DestinationName,
    [in] DWORD CopyStyle,
    [in] PSP_FILE_CALLBACK_W CopyMsgHandler,
    [in] PVOID Context
);

WINSETUPAPI BOOL SetupDiCancelDriverInfoSearch(
    [in] HDEVINFO DeviceInfoSet
);

WINSETUPAPI HDSKSPC SetupCreateDiskSpaceListA(
    [in] PVOID Reserved1,
    [in] DWORD Reserved2,
    [in] UINT Flags
);

WINSETUPAPI HKEY SetupDiOpenDevRegKey(
    [in] HDEVINFO DeviceInfoSet,
    [in] PSP_DEVINFO_DATA DeviceInfoData,
    [in] DWORD Scope,
    [in] DWORD HwProfile,
    [in] DWORD KeyType,
    [in] REGSAM samDesired
);

WINSETUPAPI BOOL SetupDiSetDeviceInstallParamsA(
    [in] HDEVINFO DeviceInfoSet,
    [in, optional] PSP_DEVINFO_DATA DeviceInfoData,
    [in] PSP_DEVINSTALL_PARAMS_A DeviceInstallParams
);

WINSETUPAPI BOOL SetupQueryInfOriginalFileInformationW(
    [in] PSP_INF_INFORMATION InfInformation,
    [in] UINT InfIndex,
    [in] PSP_ALTPLATFORM_INFO AlternatePlatformInfo,
    [out] PSP_ORIGINAL_FILE_INFO_W OriginalFileInfo
);

WINSETUPAPI BOOL SetupDiGetClassDescriptionW(
    [in] const GUID *ClassGuid,
    [out] PWSTR ClassDescription,
    [in] DWORD ClassDescriptionSize,
    [out, optional] PDWORD RequiredSize
);

WINSETUPAPI BOOL SetupDiSetDriverInstallParamsA(
    [in] HDEVINFO DeviceInfoSet,
    [in, optional] PSP_DEVINFO_DATA DeviceInfoData,
    [in] PSP_DRVINFO_DATA_A DriverInfoData,
    [in] PSP_DRVINSTALL_PARAMS DriverInstallParams
);

WINSETUPAPI HKEY SetupDiCreateDevRegKeyW(
    [in] HDEVINFO DeviceInfoSet,
    [in] PSP_DEVINFO_DATA DeviceInfoData,
    [in] DWORD Scope,
    [in] DWORD HwProfile,
    [in] DWORD KeyType,
    [in, optional] HINF InfHandle,
    [in, optional] PCWSTR InfSectionName
);

WINSETUPAPI BOOL SetupDiGetClassImageListExA(
    [out] PSP_CLASSIMAGELIST_DATA ClassImageListData,
    [in, optional] PCSTR MachineName,
    PVOID Reserved
);

WINSETUPAPI BOOL SetupDiGetSelectedDriverW(
    [in] HDEVINFO DeviceInfoSet,
    [in, optional] PSP_DEVINFO_DATA DeviceInfoData,
    [out] PSP_DRVINFO_DATA_W DriverInfoData
);

WINSETUPAPI BOOL SetupDiGetDeviceInterfaceDetailW(
    [in] HDEVINFO DeviceInfoSet,
    [in] PSP_DEVICE_INTERFACE_DATA DeviceInterfaceData,
    [out, optional] PSP_DEVICE_INTERFACE_DETAIL_DATA_W DeviceInterfaceDetailData,
    [in] DWORD DeviceInterfaceDetailDataSize,
    [out, optional] PDWORD RequiredSize,
    [out, optional] PSP_DEVINFO_DATA DeviceInfoData
);

WINSETUPAPI BOOL SetupDiOpenDeviceInterfaceA(
    [in] HDEVINFO DeviceInfoSet,
    [in] PCSTR DevicePath,
    [in] DWORD OpenFlags,
    [out, optional] PSP_DEVICE_INTERFACE_DATA DeviceInterfaceData
);

WINSETUPAPI BOOL SetupRemoveFileLogEntryW(
    [in] HSPFILELOG FileLogHandle,
    [in] PCWSTR LogSectionName,
    [in] PCWSTR TargetFilename
);

WINSETUPAPI BOOL SetupRemoveFromSourceListW(
    [in] DWORD Flags,
    [in] PCWSTR Source
);

WINSETUPAPI DWORD SetupDecompressOrCopyFileA(
    [in] PCSTR SourceFileName,
    [in] PCSTR TargetFileName,
    [in] PUINT CompressionType
);

WINSETUPAPI BOOL SetupFindFirstLineW(
    [in] HINF InfHandle,
    [in] PCWSTR Section,
    [in] PCWSTR Key,
    [in, out] PINFCONTEXT Context
);

WINSETUPAPI BOOL SetupFreeSourceListA(
    [in, out] PCSTR **List,
    [in] UINT Count
);

WINSETUPAPI BOOL SetupDiGetClassBitmapIndex(
    [in, optional] const GUID *ClassGuid,
    [out] PINT MiniIconIndex
);

WINSETUPAPI BOOL SetupRemoveFileLogEntryA(
    [in] HSPFILELOG FileLogHandle,
    [in] PCSTR LogSectionName,
    [in] PCSTR TargetFilename
);

WINSETUPAPI BOOL SetupDiSetSelectedDevice(
    [in] HDEVINFO DeviceInfoSet,
    [in] PSP_DEVINFO_DATA DeviceInfoData
);

WINSETUPAPI VOID SetupWriteTextLogError(
    [in] SP_LOG_TOKEN LogToken,
    [in] DWORD Category,
    [in] DWORD LogFlags,
    [in] DWORD Error,
    [in] PCSTR MessageStr,
    ...
);

WINSETUPAPI BOOL SetupDiGetDeviceInterfaceAlias(
    [in] HDEVINFO DeviceInfoSet,
    [in] PSP_DEVICE_INTERFACE_DATA DeviceInterfaceData,
    [in] const GUID *AliasInterfaceClassGuid,
    [out] PSP_DEVICE_INTERFACE_DATA AliasDeviceInterfaceData
);

