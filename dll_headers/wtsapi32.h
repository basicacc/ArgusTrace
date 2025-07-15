BOOL WTSQueryUserConfigW(
    [in] LPWSTR pServerName,
    [in] LPWSTR pUserName,
    [in] WTS_CONFIG_CLASS WTSConfigClass,
    [out] LPWSTR *ppBuffer,
    [out] DWORD *pBytesReturned
);

BOOL WTSEnumerateSessionsW(
    [in] HANDLE hServer,
    [in] DWORD Reserved,
    [in] DWORD Version,
    [out] PWTS_SESSION_INFOW *ppSessionInfo,
    [out] DWORD *pCount
);

BOOL WTSGetChildSessionId(
    [out] PULONG pSessionId
);

BOOL WTSFreeMemoryExA(
    [in] WTS_TYPE_CLASS WTSTypeClass,
    [in] PVOID pMemory,
    [in] ULONG NumberOfEntries
);

BOOL WTSEnumerateSessionsExW(
    [in] HANDLE hServer,
    [in, out] DWORD *pLevel,
    [in] DWORD Filter,
    [out] PWTS_SESSION_INFO_1W *ppSessionInfo,
    [out] DWORD *pCount
);

BOOL WTSEnableChildSessions(
    BOOL bEnable
);

BOOL WTSEnumerateProcessesExA(
    [in] HANDLE hServer,
    [in, out] DWORD *pLevel,
    [in] DWORD SessionId,
    [out] LPSTR *ppProcessInfo,
    [out] DWORD *pCount
);

BOOL WTSLogoffSession(
    [in] HANDLE hServer,
    [in] DWORD SessionId,
    [in] BOOL bWait
);

HANDLE WTSVirtualChannelOpen(
    [in] HANDLE hServer,
    [in] DWORD SessionId,
    [in] LPSTR pVirtualName
);

BOOL WTSEnumerateServersW(
    [in] LPWSTR pDomainName,
    [in] DWORD Reserved,
    [in] DWORD Version,
    PWTS_SERVER_INFOW *ppServerInfo,
    DWORD *pCount
);

HANDLE WTSOpenServerA(
    [in] LPSTR pServerName
);

BOOL WTSEnumerateSessionsA(
    [in] HANDLE hServer,
    [in] DWORD Reserved,
    [in] DWORD Version,
    [out] PWTS_SESSION_INFOA *ppSessionInfo,
    [out] DWORD *pCount
);

BOOL WTSRegisterSessionNotification(
    [in] HWND hWnd,
    [in] DWORD dwFlags
);

BOOL WTSCreateListenerW(
    [in] HANDLE hServer,
    [in] PVOID pReserved,
    [in] DWORD Reserved,
    [in] LPWSTR pListenerName,
    [in] PWTSLISTENERCONFIGW pBuffer,
    [in] DWORD flag
);

BOOL WTSEnumerateSessionsExA(
    [in] HANDLE hServer,
    [in, out] DWORD *pLevel,
    [in] DWORD Filter,
    [out] PWTS_SESSION_INFO_1A *ppSessionInfo,
    [out] DWORD *pCount
);

BOOL WTSEnumerateProcessesExW(
    [in] HANDLE hServer,
    [in, out] DWORD *pLevel,
    [in] DWORD SessionId,
    [out] LPWSTR *ppProcessInfo,
    [out] DWORD *pCount
);

BOOL WTSVirtualChannelPurgeInput(
    [in] HANDLE hChannelHandle
);

HANDLE WTSVirtualChannelOpenEx(
    [in] DWORD SessionId,
    [in] LPSTR pVirtualName,
    [in] DWORD flags
);

BOOL WTSWaitSystemEvent(
    [in] HANDLE hServer,
    [in] DWORD EventMask,
    [out] DWORD *pEventFlags
);

BOOL WTSSetUserConfigW(
    [in] LPWSTR pServerName,
    [in] LPWSTR pUserName,
    [in] WTS_CONFIG_CLASS WTSConfigClass,
    [in] LPWSTR pBuffer,
    [in] DWORD DataLength
);

BOOL WTSEnumerateProcessesW(
    [in] HANDLE hServer,
    [in] DWORD Reserved,
    [in] DWORD Version,
    [out] PWTS_PROCESS_INFOW *ppProcessInfo,
    [out] DWORD *pCount
);

BOOL WTSShutdownSystem(
    [in] HANDLE hServer,
    [in] DWORD ShutdownFlag
);

BOOL WTSStopRemoteControlSession(
    [in] ULONG LogonId
);

BOOL WTSSendMessageW(
    [in] HANDLE hServer,
    [in] DWORD SessionId,
    [in] LPWSTR pTitle,
    [in] DWORD TitleLength,
    [in] LPWSTR pMessage,
    [in] DWORD MessageLength,
    [in] DWORD Style,
    [in] DWORD Timeout,
    [out] DWORD *pResponse,
    [in] BOOL bWait
);

BOOL WTSEnumerateListenersA(
    [in] HANDLE hServer,
    [in] PVOID pReserved,
    [in] DWORD Reserved,
    [out, optional] PWTSLISTENERNAMEA pListeners,
    [in, out] DWORD *pCount
);

BOOL WTSQueryListenerConfigW(
    [in] HANDLE hServer,
    [in] PVOID pReserved,
    [in] DWORD Reserved,
    [in] LPWSTR pListenerName,
    [out] PWTSLISTENERCONFIGW pBuffer
);

HANDLE WTSOpenServerW(
    [in] LPWSTR pServerName
);

BOOL WTSQueryListenerConfigA(
    [in] HANDLE hServer,
    [in] PVOID pReserved,
    [in] DWORD Reserved,
    [in] LPSTR pListenerName,
    [out] PWTSLISTENERCONFIGA pBuffer
);

BOOL WTSSetUserConfigA(
    [in] LPSTR pServerName,
    [in] LPSTR pUserName,
    [in] WTS_CONFIG_CLASS WTSConfigClass,
    [in] LPSTR pBuffer,
    [in] DWORD DataLength
);

BOOL WTSStartRemoteControlSessionW(
    [in] LPWSTR pTargetServerName,
    [in] ULONG TargetLogonId,
    [in] BYTE HotkeyVk,
    [in] USHORT HotkeyModifiers
);

BOOL WTSQuerySessionInformationW(
    [in] HANDLE hServer,
    [in] DWORD SessionId,
    [in] WTS_INFO_CLASS WTSInfoClass,
    [out] LPWSTR *ppBuffer,
    [out] DWORD *pBytesReturned
);

BOOL WTSVirtualChannelClose(
    [in] HANDLE hChannelHandle
);

BOOL WTSCreateListenerA(
    [in] HANDLE hServer,
    [in] PVOID pReserved,
    [in] DWORD Reserved,
    [in] LPSTR pListenerName,
    [in] PWTSLISTENERCONFIGA pBuffer,
    [in] DWORD flag
);

BOOL WTSDisconnectSession(
    [in] HANDLE hServer,
    [in] DWORD SessionId,
    [in] BOOL bWait
);

BOOL WTSConnectSessionW(
    [in] ULONG LogonId,
    [in] ULONG TargetLogonId,
    [in] PWSTR pPassword,
    [in] BOOL bWait
);

BOOL WTSGetListenerSecurityA(
    [in] HANDLE hServer,
    [in] PVOID pReserved,
    [in] DWORD Reserved,
    [in] LPSTR pListenerName,
    [in] SECURITY_INFORMATION SecurityInformation,
    [out, optional] PSECURITY_DESCRIPTOR pSecurityDescriptor,
    [in] DWORD nLength,
    [out] LPDWORD lpnLengthNeeded
);

void WTSFreeMemory(
    [in] PVOID pMemory
);

BOOL WTSSetListenerSecurityA(
    [in] HANDLE hServer,
    [in] PVOID pReserved,
    [in] DWORD Reserved,
    [in] LPSTR pListenerName,
    [in] SECURITY_INFORMATION SecurityInformation,
    [in] PSECURITY_DESCRIPTOR pSecurityDescriptor
);

BOOL WTSUnRegisterSessionNotification(
    [in] HWND hWnd
);

BOOL WTSIsChildSessionsEnabled(
    [out] PBOOL pbEnabled
);

BOOL WTSVirtualChannelPurgeOutput(
    [in] HANDLE hChannelHandle
);

BOOL WTSFreeMemoryExW(
    [in] WTS_TYPE_CLASS WTSTypeClass,
    [in] PVOID pMemory,
    [in] ULONG NumberOfEntries
);

BOOL WTSQuerySessionInformationA(
    [in] HANDLE hServer,
    [in] DWORD SessionId,
    [in] WTS_INFO_CLASS WTSInfoClass,
    [out] LPSTR *ppBuffer,
    [out] DWORD *pBytesReturned
);

BOOL WTSEnumerateProcessesA(
    [in] HANDLE hServer,
    [in] DWORD Reserved,
    [in] DWORD Version,
    [out] PWTS_PROCESS_INFOA *ppProcessInfo,
    [out] DWORD *pCount
);

BOOL WTSEnumerateListenersW(
    [in] HANDLE hServer,
    [in] PVOID pReserved,
    [in] DWORD Reserved,
    [out, optional] PWTSLISTENERNAMEW pListeners,
    [in, out] DWORD *pCount
);

BOOL WTSVirtualChannelRead(
    [in] HANDLE hChannelHandle,
    [in] ULONG TimeOut,
    [out] PCHAR Buffer,
    [in] ULONG BufferSize,
    [out] PULONG pBytesRead
);

BOOL WTSVirtualChannelQuery(
    [in] HANDLE hChannelHandle,
    WTS_VIRTUAL_CLASS unnamedParam2,
    [out] PVOID *ppBuffer,
    [out] DWORD *pBytesReturned
);

BOOL WTSConnectSessionA(
    [in] ULONG LogonId,
    [in] ULONG TargetLogonId,
    [in] PSTR pPassword,
    [in] BOOL bWait
);

BOOL WTSQueryUserConfigA(
    [in] LPSTR pServerName,
    [in] LPSTR pUserName,
    [in] WTS_CONFIG_CLASS WTSConfigClass,
    [out] LPSTR *ppBuffer,
    [out] DWORD *pBytesReturned
);

BOOL WTSVirtualChannelWrite(
    [in] HANDLE hChannelHandle,
    [in] PCHAR Buffer,
    [in] ULONG Length,
    [out] PULONG pBytesWritten
);

void WTSCloseServer(
    [in] HANDLE hServer
);

BOOL WTSRegisterSessionNotificationEx(
    [in] HANDLE hServer,
    [in] HWND hWnd,
    [in] DWORD dwFlags
);

BOOL WTSTerminateProcess(
    [in] HANDLE hServer,
    [in] DWORD ProcessId,
    [in] DWORD ExitCode
);

BOOL WTSUnRegisterSessionNotificationEx(
    [in] HANDLE hServer,
    [in] HWND hWnd
);

BOOL WTSSendMessageA(
    [in] HANDLE hServer,
    [in] DWORD SessionId,
    [in] LPSTR pTitle,
    [in] DWORD TitleLength,
    [in] LPSTR pMessage,
    [in] DWORD MessageLength,
    [in] DWORD Style,
    [in] DWORD Timeout,
    [out] DWORD *pResponse,
    [in] BOOL bWait
);

BOOL WTSStartRemoteControlSessionA(
    [in] LPSTR pTargetServerName,
    [in] ULONG TargetLogonId,
    [in] BYTE HotkeyVk,
    [in] USHORT HotkeyModifiers
);

BOOL WTSSetListenerSecurityW(
    [in] HANDLE hServer,
    [in] PVOID pReserved,
    [in] DWORD Reserved,
    [in] LPWSTR pListenerName,
    [in] SECURITY_INFORMATION SecurityInformation,
    [in] PSECURITY_DESCRIPTOR pSecurityDescriptor
);

HANDLE WTSOpenServerExA(
    [in] LPSTR pServerName
);

BOOL WTSQueryUserToken(
    [in] ULONG SessionId,
    [out] PHANDLE phToken
);

BOOL WTSEnumerateServersA(
    [in] LPSTR pDomainName,
    [in] DWORD Reserved,
    [in] DWORD Version,
    PWTS_SERVER_INFOA *ppServerInfo,
    DWORD *pCount
);

HANDLE WTSOpenServerExW(
    [in] LPWSTR pServerName
);

BOOL WTSGetListenerSecurityW(
    [in] HANDLE hServer,
    [in] PVOID pReserved,
    [in] DWORD Reserved,
    [in] LPWSTR pListenerName,
    [in] SECURITY_INFORMATION SecurityInformation,
    [out, optional] PSECURITY_DESCRIPTOR pSecurityDescriptor,
    [in] DWORD nLength,
    [out] LPDWORD lpnLengthNeeded
);

