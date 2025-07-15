BOOL LogonUserA(
    [in] LPCSTR lpszUsername,
    [in, optional] LPCSTR lpszDomain,
    [in, optional] LPCSTR lpszPassword,
    [in] DWORD dwLogonType,
    [in] DWORD dwLogonProvider,
    [out] PHANDLE phToken
);

HANDLE CreateFileTransactedW(
    [in] LPCWSTR lpFileName,
    [in] DWORD dwDesiredAccess,
    [in] DWORD dwShareMode,
    [in, optional] LPSECURITY_ATTRIBUTES lpSecurityAttributes,
    [in] DWORD dwCreationDisposition,
    [in] DWORD dwFlagsAndAttributes,
    [in, optional] HANDLE hTemplateFile,
    [in] HANDLE hTransaction,
    [in, optional] PUSHORT pusMiniVersion,
    PVOID lpExtendedParameter
);

UINT _lread(
    HFILE hFile,
    LPVOID lpBuffer,
    UINT uBytes
);

BOOL DefineDosDeviceA(
    [in] DWORD dwFlags,
    [in] LPCSTR lpDeviceName,
    [in, optional] LPCSTR lpTargetPath
);

ATOM GlobalAddAtomExA(
    [in, optional] LPCSTR lpString,
    [in] DWORD Flags
);

DWORD DisableThreadProfiling(
    [in] HANDLE PerformanceDataHandle
);

BOOL SetCurrentDirectory(
    [in] LPCTSTR lpPathName
);

BOOL GetFileAttributesTransactedA(
    [in] LPCSTR lpFileName,
    [in] GET_FILEEX_INFO_LEVELS fInfoLevelId,
    [out] LPVOID lpFileInformation,
    [in] HANDLE hTransaction
);

HANDLE CreateMailslotA(
    [in] LPCSTR lpName,
    [in] DWORD nMaxMessageSize,
    [in] DWORD lReadTimeout,
    [in, optional] LPSECURITY_ATTRIBUTES lpSecurityAttributes
);

BOOL WritePrivateProfileStructA(
    [in] LPCSTR lpszSection,
    [in] LPCSTR lpszKey,
    [in] LPVOID lpStruct,
    [in] UINT uSizeStruct,
    [in] LPCSTR szFile
);

BOOL GetNamedPipeClientSessionId(
    [in] HANDLE Pipe,
    [out] PULONG ClientSessionId
);

BOOLEAN CreateSymbolicLinkTransactedA(
    [in] LPCSTR lpSymlinkFileName,
    [in] LPCSTR lpTargetFileName,
    [in] DWORD dwFlags,
    [in] HANDLE hTransaction
);

DWORD GetFullPathNameTransactedW(
    [in] LPCWSTR lpFileName,
    [in] DWORD nBufferLength,
    [out] LPWSTR lpBuffer,
    [out] LPWSTR *lpFilePart,
    [in] HANDLE hTransaction
);

DWORD GetMaximumProcessorCount(
    [in] WORD GroupNumber
);

DWORD GetEnvironmentVariable(
    [in, optional] LPCTSTR lpName,
    [out, optional] LPTSTR lpBuffer,
    [in] DWORD nSize
);

UINT LocalFlags(
    [in] HLOCAL hMem
);

UINT WinExec(
    [in] LPCSTR lpCmdLine,
    [in] UINT uCmdShow
);

BOOL CommConfigDialogA(
    [in] LPCSTR lpszName,
    [in] HWND hWnd,
    [in, out] LPCOMMCONFIG lpCC
);

BOOL GetUmsSystemThreadInformation(
    [in] HANDLE ThreadHandle,
    [in, out] PUMS_SYSTEM_THREAD_INFORMATION SystemThreadInfo
);

BOOLEAN CreateSymbolicLinkW(
    [in] LPCWSTR lpSymlinkFileName,
    [in] LPCWSTR lpTargetFileName,
    [in] DWORD dwFlags
);

HANDLE CreateNamedPipeA(
    [in] LPCSTR lpName,
    [in] DWORD dwOpenMode,
    [in] DWORD dwPipeMode,
    [in] DWORD nMaxInstances,
    [in] DWORD nOutBufferSize,
    [in] DWORD nInBufferSize,
    [in] DWORD nDefaultTimeOut,
    [in, optional] LPSECURITY_ATTRIBUTES lpSecurityAttributes
);

DWORD FormatMessageW(
    [in] DWORD dwFlags,
    [in, optional] LPCVOID lpSource,
    [in] DWORD dwMessageId,
    [in] DWORD dwLanguageId,
    [out] LPWSTR lpBuffer,
    [in] DWORD nSize,
    [in, optional] va_list *Arguments
);

void InitializeThreadpoolEnvironment(
    [out] PTP_CALLBACK_ENVIRON pcbe
);

LPWSTR lstrcpyW(
    [out] LPWSTR lpString1,
    [in] LPCWSTR lpString2
);

void SetThreadpoolCallbackPersistent(
    [in, out] PTP_CALLBACK_ENVIRON pcbe
);

DWORD GetPrivateProfileSection(
    [in] LPCTSTR lpAppName,
    [out] LPTSTR lpReturnedString,
    [in] DWORD nSize,
    [in] LPCTSTR lpFileName
);

BOOL WriteProfileStringA(
    [in] LPCSTR lpAppName,
    [in] LPCSTR lpKeyName,
    [in] LPCSTR lpString
);

DWORD GetPrivateProfileString(
    [in] LPCTSTR lpAppName,
    [in] LPCTSTR lpKeyName,
    [in] LPCTSTR lpDefault,
    [out] LPTSTR lpReturnedString,
    [in] DWORD nSize,
    [in] LPCTSTR lpFileName
);

BOOL CreateHardLinkTransactedA(
    [in] LPCSTR lpFileName,
    [in] LPCSTR lpExistingFileName,
    LPSECURITY_ATTRIBUTES lpSecurityAttributes,
    [in] HANDLE hTransaction
);

BOOL OperationStart(
    [in] OPERATION_START_PARAMETERS *OperationStartParams
);

HGLOBAL GlobalFree(
    [in] _Frees_ptr_opt_ HGLOBAL hMem
);

DWORD GetFirmwareEnvironmentVariableA(
    [in] LPCSTR lpName,
    [in] LPCSTR lpGuid,
    [out] PVOID pBuffer,
    [in] DWORD nSize
);

HANDLE OpenEventLogA(
    [in] LPCSTR lpUNCServerName,
    [in] LPCSTR lpSourceName
);

BOOL GetFileInformationByName(
    PCWSTR FileName,
    FILE_INFO_BY_NAME_CLASS FileInformationClass,
    PVOID FileInfoBuffer,
    ULONG FileInfoBufferSize
);

DWORD SetTapePosition(
    [in] HANDLE hDevice,
    [in] DWORD dwPositionMethod,
    [in] DWORD dwPartition,
    [in] DWORD dwOffsetLow,
    [in] DWORD dwOffsetHigh,
    [in] BOOL bImmediate
);

BOOL SetVolumeLabelA(
    [in, optional] LPCSTR lpRootPathName,
    [in, optional] LPCSTR lpVolumeName
);

void GlobalMemoryStatus(
    [out] LPMEMORYSTATUS lpBuffer
);

BOOL LogonUserExW(
    [in] LPCWSTR lpszUsername,
    [in, optional] LPCWSTR lpszDomain,
    [in, optional] LPCWSTR lpszPassword,
    [in] DWORD dwLogonType,
    [in] DWORD dwLogonProvider,
    [out, optional] PHANDLE phToken,
    [out, optional] PSID *ppLogonSid,
    [out, optional] PVOID *ppProfileBuffer,
    [out, optional] LPDWORD pdwProfileLength,
    [out, optional] PQUOTA_LIMITS pQuotaLimits
);

BOOL CopyFileTransactedA(
    [in] LPCSTR lpExistingFileName,
    [in] LPCSTR lpNewFileName,
    [in, optional] LPPROGRESS_ROUTINE lpProgressRoutine,
    [in, optional] LPVOID lpData,
    [in, optional] LPBOOL pbCancel,
    [in] DWORD dwCopyFlags,
    [in] HANDLE hTransaction
);

HANDLE OpenFileMappingA(
    [in] DWORD dwDesiredAccess,
    [in] BOOL bInheritHandle,
    [in] LPCSTR lpName
);

BOOL LookupAccountNameW(
    [in, optional] LPCWSTR lpSystemName,
    [in] LPCWSTR lpAccountName,
    [out, optional] PSID Sid,
    [in, out] LPDWORD cbSid,
    [out, optional] LPWSTR ReferencedDomainName,
    [in, out] LPDWORD cchReferencedDomainName,
    [out] PSID_NAME_USE peUse
);

BOOL MoveFileTransactedA(
    [in] LPCSTR lpExistingFileName,
    [in, optional] LPCSTR lpNewFileName,
    [in, optional] LPPROGRESS_ROUTINE lpProgressRoutine,
    [in, optional] LPVOID lpData,
    [in] DWORD dwFlags,
    [in] HANDLE hTransaction
);

BOOL CopyFileTransactedW(
    [in] LPCWSTR lpExistingFileName,
    [in] LPCWSTR lpNewFileName,
    [in, optional] LPPROGRESS_ROUTINE lpProgressRoutine,
    [in, optional] LPVOID lpData,
    [in, optional] LPBOOL pbCancel,
    [in] DWORD dwCopyFlags,
    [in] HANDLE hTransaction
);

BOOL ObjectDeleteAuditAlarmA(
    [in] LPCSTR SubsystemName,
    [in] LPVOID HandleId,
    [in] BOOL GenerateOnClose
);

BOOL WriteProfileSectionA(
    [in] LPCSTR lpAppName,
    [in] LPCSTR lpString
);

BOOL BackupRead(
    [in] HANDLE hFile,
    [out] LPBYTE lpBuffer,
    [in] DWORD nNumberOfBytesToRead,
    [out] LPDWORD lpNumberOfBytesRead,
    [in] BOOL bAbort,
    [in] BOOL bProcessSecurity,
    [out] LPVOID *lpContext
);

DWORD QueryDosDeviceA(
    [in, optional] LPCSTR lpDeviceName,
    [out] LPSTR lpTargetPath,
    [in] DWORD ucchMax
);

BOOL ClearEventLogA(
    [in] HANDLE hEventLog,
    [in] LPCSTR lpBackupFileName
);

BOOL IsBadWritePtr(
    [in] LPVOID lp,
    [in] UINT_PTR ucb
);

void SwitchToFiber(
    [in] LPVOID lpFiber
);

BOOL IsBadStringPtrW(
    [in] LPCWSTR lpsz,
    [in] UINT_PTR ucchMax
);

BOOL SetVolumeLabelW(
    [in, optional] LPCWSTR lpRootPathName,
    [in, optional] LPCWSTR lpVolumeName
);

BOOL AccessCheckAndAuditAlarmA(
    [in] LPCSTR SubsystemName,
    [in, optional] LPVOID HandleId,
    [in] LPSTR ObjectTypeName,
    [in, optional] LPSTR ObjectName,
    [in] PSECURITY_DESCRIPTOR SecurityDescriptor,
    [in] DWORD DesiredAccess,
    [in] PGENERIC_MAPPING GenericMapping,
    [in] BOOL ObjectCreation,
    [out] LPDWORD GrantedAccess,
    [out] LPBOOL AccessStatus,
    [out] LPBOOL pfGenerateOnClose
);

BOOL ReportEventW(
    [in] HANDLE hEventLog,
    [in] WORD wType,
    [in] WORD wCategory,
    [in] DWORD dwEventID,
    [in] PSID lpUserSid,
    [in] WORD wNumStrings,
    [in] DWORD dwDataSize,
    [in] LPCWSTR *lpStrings,
    [in] LPVOID lpRawData
);

SIZE_T LocalSize(
    [in] HLOCAL hMem
);

BOOL CallNamedPipeA(
    [in] LPCSTR lpNamedPipeName,
    [in] LPVOID lpInBuffer,
    [in] DWORD nInBufferSize,
    [out] LPVOID lpOutBuffer,
    [in] DWORD nOutBufferSize,
    [out] LPDWORD lpBytesRead,
    [in] DWORD nTimeOut
);

int lstrlenW(
    [in] LPCWSTR lpString
);

BOOL SetFileCompletionNotificationModes(
    [in] HANDLE FileHandle,
    [in] UCHAR Flags
);

BOOL DequeueUmsCompletionListItems(
    [in] PUMS_COMPLETION_LIST UmsCompletionList,
    [in] DWORD WaitTimeOut,
    [out] PUMS_CONTEXT *UmsThreadList
);

BOOL EndUpdateResourceW(
    [in] HANDLE hUpdate,
    [in] BOOL fDiscard
);

BOOL BackupSeek(
    [in] HANDLE hFile,
    [in] DWORD dwLowBytesToSeek,
    [in] DWORD dwHighBytesToSeek,
    [out] LPDWORD lpdwLowByteSeeked,
    [out] LPDWORD lpdwHighByteSeeked,
    [in] LPVOID *lpContext
);

HRESULT ApplicationRecoveryInProgress(
    [out] PBOOL pbCancelled
);

DWORD EnableThreadProfiling(
    [in] HANDLE ThreadHandle,
    [in] DWORD Flags,
    [in] DWORD64 HardwareCounters,
    [out] HANDLE *PerformanceDataHandle
);

BOOL InitAtomTable(
    [in] DWORD nSize
);

HANDLE CreateJobObjectA(
    [in, optional] LPSECURITY_ATTRIBUTES lpJobAttributes,
    [in, optional] LPCSTR lpName
);

DWORD GetShortPathNameA(
    [in] LPCSTR lpszLongPath,
    [out] LPSTR lpszShortPath,
    [in] DWORD cchBuffer
);

BOOL SetDllDirectoryW(
    [in, optional] LPCWSTR lpPathName
);

DWORD GetDllDirectoryA(
    [in] DWORD nBufferLength,
    [out] LPSTR lpBuffer
);

BOOL TransmitCommChar(
    [in] HANDLE hFile,
    [in] char cChar
);

BOOL RegisterWaitForSingleObject(
    [out] PHANDLE phNewWaitObject,
    [in] HANDLE hObject,
    [in] WAITORTIMERCALLBACK Callback,
    [in, optional] PVOID Context,
    [in] ULONG dwMilliseconds,
    [in] ULONG dwFlags
);

DWORD GetPrivateProfileStringA(
    [in] LPCSTR lpAppName,
    [in] LPCSTR lpKeyName,
    [in] LPCSTR lpDefault,
    [out] LPSTR lpReturnedString,
    [in] DWORD nSize,
    [in] LPCSTR lpFileName
);

BOOL MoveFileA(
    [in] LPCSTR lpExistingFileName,
    [in] LPCSTR lpNewFileName
);

HANDLE FindFirstFileTransactedW(
    [in] LPCWSTR lpFileName,
    [in] FINDEX_INFO_LEVELS fInfoLevelId,
    [out] LPVOID lpFindFileData,
    [in] FINDEX_SEARCH_OPS fSearchOp,
    LPVOID lpSearchFilter,
    [in] DWORD dwAdditionalFlags,
    [in] HANDLE hTransaction
);

BOOL UnregisterWait(
    [in] HANDLE WaitHandle
);

BOOL InitializeContext(
    [out, optional] PVOID Buffer,
    [in] DWORD ContextFlags,
    [out, optional] PCONTEXT *Context,
    [in, out] PDWORD ContextLength
);

BOOL GetFileSecurityA(
    [in] LPCSTR lpFileName,
    [in] SECURITY_INFORMATION RequestedInformation,
    [out, optional] PSECURITY_DESCRIPTOR pSecurityDescriptor,
    [in] DWORD nLength,
    [out] LPDWORD lpnLengthNeeded
);

void HasOverlappedIoCompleted(
    lpOverlapped
);

BOOL PowerSetRequest(
    [in] HANDLE PowerRequest,
    [in] POWER_REQUEST_TYPE RequestType
);

BOOL MoveFileExW(
    [in] LPCWSTR lpExistingFileName,
    [in, optional] LPCWSTR lpNewFileName,
    [in] DWORD dwFlags
);

BOOL DebugSetProcessKillOnExit(
    [in] BOOL KillOnExit
);

BOOL ObjectCloseAuditAlarmA(
    [in] LPCSTR SubsystemName,
    [in] LPVOID HandleId,
    [in] BOOL GenerateOnClose
);

BOOL FindActCtxSectionStringA(
    [in] DWORD dwFlags,
    [in] const GUID *lpExtensionGuid,
    [in] ULONG ulSectionId,
    [in] LPCSTR lpStringToFind,
    [out] PACTCTX_SECTION_KEYED_DATA ReturnedData
);

HANDLE FindFirstFileNameTransactedW(
    [in] LPCWSTR lpFileName,
    [in] DWORD dwFlags,
    [in, out] LPDWORD StringLength,
    [in, out] PWSTR LinkName,
    [in, optional] HANDLE hTransaction
);

BOOL IsNativeVhdBoot(
    [out] PBOOL NativeVhdBoot
);

BOOL LookupAccountSidA(
    [in, optional] LPCSTR lpSystemName,
    [in] PSID Sid,
    [out, optional] LPSTR Name,
    [in, out] LPDWORD cchName,
    [out, optional] LPSTR ReferencedDomainName,
    [in, out] LPDWORD cchReferencedDomainName,
    [out] PSID_NAME_USE peUse
);

BOOL EnumResourceLanguagesA(
    [in] HMODULE hModule,
    [in] LPCSTR lpType,
    [in] LPCSTR lpName,
    [in] ENUMRESLANGPROCA lpEnumFunc,
    [in] LONG_PTR lParam
);

BOOL SetSearchPathMode(
    [in] DWORD Flags
);

BOOL ClearCommBreak(
    [in] HANDLE hFile
);

ATOM AddAtomW(
    [in] LPCWSTR lpString
);

DWORD GetLogicalDriveStringsA(
    [in] DWORD nBufferLength,
    [out] LPSTR lpBuffer
);

HANDLE CreatePrivateNamespaceA(
    [in, optional] LPSECURITY_ATTRIBUTES lpPrivateNamespaceAttributes,
    [in] LPVOID lpBoundaryDescriptor,
    [in] LPCSTR lpAliasPrefix
);

BOOL SetFileAttributesTransactedW(
    [in] LPCWSTR lpFileName,
    [in] DWORD dwFileAttributes,
    [in] HANDLE hTransaction
);

BOOL GetFileBandwidthReservation(
    [in] HANDLE hFile,
    [out] LPDWORD lpPeriodMilliseconds,
    [out] LPDWORD lpBytesPerPeriod,
    [out] LPBOOL pDiscardable,
    [out] LPDWORD lpTransferSize,
    [out] LPDWORD lpNumOutstandingRequests
);

HANDLE RegisterEventSourceA(
    [in] LPCSTR lpUNCServerName,
    [in] LPCSTR lpSourceName
);

HRESULT RegisterApplicationRecoveryCallback(
    [in] APPLICATION_RECOVERY_CALLBACK pRecoveyCallback,
    [in, optional] PVOID pvParameter,
    [in] DWORD dwPingInterval,
    [in] DWORD dwFlags
);

LPSTR lstrcpynA(
    [out] LPSTR lpString1,
    [in] LPCSTR lpString2,
    [in] int iMaxLength
);

HANDLE FindFirstFileTransactedA(
    [in] LPCSTR lpFileName,
    [in] FINDEX_INFO_LEVELS fInfoLevelId,
    [out] LPVOID lpFindFileData,
    [in] FINDEX_SEARCH_OPS fSearchOp,
    LPVOID lpSearchFilter,
    [in] DWORD dwAdditionalFlags,
    [in] HANDLE hTransaction
);

HANDLE OpenBackupEventLogA(
    [in] LPCSTR lpUNCServerName,
    [in] LPCSTR lpFileName
);

BOOL LookupPrivilegeDisplayNameW(
    [in, optional] LPCWSTR lpSystemName,
    [in] LPCWSTR lpName,
    [out, optional] LPWSTR lpDisplayName,
    [in, out] LPDWORD cchDisplayName,
    [out] LPDWORD lpLanguageId
);

BOOL GetBinaryTypeW(
    [in] LPCWSTR lpApplicationName,
    [out] LPDWORD lpBinaryType
);

DECLSPEC_ALLOCATOR HGLOBAL GlobalAlloc(
    [in] UINT uFlags,
    [in] SIZE_T dwBytes
);

BOOL LookupPrivilegeNameW(
    [in, optional] LPCWSTR lpSystemName,
    [in] PLUID lpLuid,
    [out, optional] LPWSTR lpName,
    [in, out] LPDWORD cchName
);

EXECUTION_STATE SetThreadExecutionState(
    [in] EXECUTION_STATE esFlags
);

DECLSPEC_ALLOCATOR HGLOBAL GlobalReAlloc(
    [in] _Frees_ptr_ HGLOBAL hMem,
    [in] SIZE_T dwBytes,
    [in] UINT uFlags
);

BOOL AddSecureMemoryCacheCallback(
    [in] PSECURE_MEMORY_CACHE_CALLBACK pfnCallBack
);

BOOL SetupComm(
    [in] HANDLE hFile,
    [in] DWORD dwInQueue,
    [in] DWORD dwOutQueue
);

BOOL GetNamedPipeClientComputerNameA(
    [in] HANDLE Pipe,
    [out] LPSTR ClientComputerName,
    [in] ULONG ClientComputerNameLength
);

BOOL GetMailslotInfo(
    [in] HANDLE hMailslot,
    [out, optional] LPDWORD lpMaxMessageSize,
    [out, optional] LPDWORD lpNextSize,
    [out, optional] LPDWORD lpMessageCount,
    [out, optional] LPDWORD lpReadTimeout
);

LPSTR lstrcatA(
    [in, out] LPSTR lpString1,
    [in] LPCSTR lpString2
);

BOOL GetCurrentHwProfileW(
    [out] LPHW_PROFILE_INFOW lpHwProfileInfo
);

DWORD EraseTape(
    [in] HANDLE hDevice,
    [in] DWORD dwEraseType,
    [in] BOOL bImmediate
);

BOOL BackupEventLogW(
    [in] HANDLE hEventLog,
    [in] LPCWSTR lpBackupFileName
);

BOOL CreateProcessWithTokenW(
    [in] HANDLE hToken,
    [in] DWORD dwLogonFlags,
    [in, optional] LPCWSTR lpApplicationName,
    [in, out, optional] LPWSTR lpCommandLine,
    [in] DWORD dwCreationFlags,
    [in, optional] LPVOID lpEnvironment,
    [in, optional] LPCWSTR lpCurrentDirectory,
    [in] LPSTARTUPINFOW lpStartupInfo,
    [out] LPPROCESS_INFORMATION lpProcessInformation
);

HANDLE OpenPrivateNamespaceA(
    [in] LPVOID lpBoundaryDescriptor,
    [in] LPCSTR lpAliasPrefix
);

int lstrcmpW(
    [in] LPCWSTR lpString1,
    [in] LPCWSTR lpString2
);

BOOL SetDllDirectoryA(
    [in, optional] LPCSTR lpPathName
);

BOOL UmsThreadYield(
    [in] PVOID SchedulerParam
);

BOOL WritePrivateProfileSectionA(
    [in] LPCSTR lpAppName,
    [in] LPCSTR lpString,
    [in] LPCSTR lpFileName
);

HANDLE CreateSemaphoreA(
    [in, optional] LPSECURITY_ATTRIBUTES lpSemaphoreAttributes,
    [in] LONG lInitialCount,
    [in] LONG lMaximumCount,
    [in, optional] LPCSTR lpName
);

int lstrcmpiA(
    [in] LPCSTR lpString1,
    [in] LPCSTR lpString2
);

BOOL BackupWrite(
    [in] HANDLE hFile,
    [in] LPBYTE lpBuffer,
    [in] DWORD nNumberOfBytesToWrite,
    [out] LPDWORD lpNumberOfBytesWritten,
    [in] BOOL bAbort,
    [in] BOOL bProcessSecurity,
    [out] LPVOID *lpContext
);

BOOL WritePrivateProfileStructW(
    [in] LPCWSTR lpszSection,
    [in] LPCWSTR lpszKey,
    [in] LPVOID lpStruct,
    [in] UINT uSizeStruct,
    [in] LPCWSTR szFile
);

BOOL EncryptFileA(
    [in] LPCSTR lpFileName
);

UINT GlobalGetAtomNameA(
    [in] ATOM nAtom,
    [out] LPSTR lpBuffer,
    [in] int nSize
);

BOOL WriteProfileSectionW(
    [in] LPCWSTR lpAppName,
    [in] LPCWSTR lpString
);

BOOL EscapeCommFunction(
    [in] HANDLE hFile,
    [in] DWORD dwFunc
);

BOOL DeleteUmsThreadContext(
    [in] PUMS_CONTEXT UmsThread
);

HANDLE FindFirstVolumeA(
    [out] LPSTR lpszVolumeName,
    [in] DWORD cchBufferLength
);

UINT GlobalGetAtomNameW(
    [in] ATOM nAtom,
    [out] LPWSTR lpBuffer,
    [in] int nSize
);

BOOL MoveFileW(
    [in] LPCWSTR lpExistingFileName,
    [in] LPCWSTR lpNewFileName
);

DWORD64 GetThreadEnabledXStateFeatures();

UINT GetAtomNameW(
    [in] ATOM nAtom,
    [out] LPWSTR lpBuffer,
    [in] int nSize
);

HANDLE CreateFileMappingA(
    [in] HANDLE hFile,
    [in, optional] LPSECURITY_ATTRIBUTES lpFileMappingAttributes,
    [in] DWORD flProtect,
    [in] DWORD dwMaximumSizeHigh,
    [in] DWORD dwMaximumSizeLow,
    [in, optional] LPCSTR lpName
);

HANDLE CreateFileMappingNumaA(
    [in] HANDLE hFile,
    [in, optional] LPSECURITY_ATTRIBUTES lpFileMappingAttributes,
    [in] DWORD flProtect,
    [in] DWORD dwMaximumSizeHigh,
    [in] DWORD dwMaximumSizeLow,
    [in, optional] LPCSTR lpName,
    [in] DWORD nndPreferred
);

BOOL GetCommMask(
    [in] HANDLE hFile,
    [out] LPDWORD lpEvtMask
);

BOOL GetFileAttributesTransactedW(
    [in] LPCWSTR lpFileName,
    [in] GET_FILEEX_INFO_LEVELS fInfoLevelId,
    [out] LPVOID lpFileInformation,
    [in] HANDLE hTransaction
);

DWORD QueryThreadProfiling(
    [in] HANDLE ThreadHandle,
    [out] PBOOLEAN Enabled
);

BOOL DosDateTimeToFileTime(
    [in] WORD wFatDate,
    [in] WORD wFatTime,
    [out] LPFILETIME lpFileTime
);

BOOL EnableProcessOptionalXStateFeatures(
    DWORD64 Features
);

int lstrcmpA(
    [in] LPCSTR lpString1,
    [in] LPCSTR lpString2
);

void DeleteFiber(
    [in] LPVOID lpFiber
);

DWORD GetTapePosition(
    [in] HANDLE hDevice,
    [in] DWORD dwPositionType,
    [out] LPDWORD lpdwPartition,
    [out] LPDWORD lpdwOffsetLow,
    [out] LPDWORD lpdwOffsetHigh
);

BOOL GetBinaryTypeA(
    [in] LPCSTR lpApplicationName,
    [out] LPDWORD lpBinaryType
);

BOOL QueryUmsThreadInformation(
    [in] PUMS_CONTEXT UmsThread,
    [in] UMS_THREAD_INFO_CLASS UmsThreadInfoClass,
    [out] PVOID UmsThreadInformation,
    [in] ULONG UmsThreadInformationLength,
    [out, optional] PULONG ReturnLength
);

DWORD SetTapeParameters(
    [in] HANDLE hDevice,
    [in] DWORD dwOperation,
    [in] LPVOID lpTapeInformation
);

DWORD GetLongPathNameTransactedA(
    [in] LPCSTR lpszShortPath,
    [out] LPSTR lpszLongPath,
    [in] DWORD cchBuffer,
    [in] HANDLE hTransaction
);

void SetThreadpoolCallbackRunsLong(
    [in, out] PTP_CALLBACK_ENVIRON pcbe
);

BOOL SetXStateFeaturesMask(
    [in, out] PCONTEXT Context,
    [in] DWORD64 FeatureMask
);

BOOL GetXStateFeaturesMask(
    [in] PCONTEXT Context,
    [out] PDWORD64 FeatureMask
);

HANDLE CreateFileTransactedA(
    [in] LPCSTR lpFileName,
    [in] DWORD dwDesiredAccess,
    [in] DWORD dwShareMode,
    [in, optional] LPSECURITY_ATTRIBUTES lpSecurityAttributes,
    [in] DWORD dwCreationDisposition,
    [in] DWORD dwFlagsAndAttributes,
    [in, optional] HANDLE hTemplateFile,
    [in] HANDLE hTransaction,
    [in, optional] PUSHORT pusMiniVersion,
    PVOID lpExtendedParameter
);

HRESULT GetApplicationRestartSettings(
    [in] HANDLE hProcess,
    [out, optional] PWSTR pwzCommandline,
    [in, out] PDWORD pcchSize,
    [out, optional] PDWORD pdwFlags
);

DWORD_PTR SetThreadAffinityMask(
    [in] HANDLE hThread,
    [in] DWORD_PTR dwThreadAffinityMask
);

BOOL ExecuteUmsThread(
    [in, out] PUMS_CONTEXT UmsThread
);

BOOL CheckNameLegalDOS8Dot3W(
    [in] LPCWSTR lpName,
    [out, optional] LPSTR lpOemName,
    [in] DWORD OemNameSize,
    [out, optional] PBOOL pbNameContainsSpaces,
    [out] PBOOL pbNameLegal
);

BOOL GetDefaultCommConfigW(
    [in] LPCWSTR lpszName,
    [out] LPCOMMCONFIG lpCC,
    [in, out] LPDWORD lpdwSize
);

BOOL ReadEventLogA(
    [in] HANDLE hEventLog,
    [in] DWORD dwReadFlags,
    [in] DWORD dwRecordOffset,
    [out] LPVOID lpBuffer,
    [in] DWORD nNumberOfBytesToRead,
    [out] DWORD *pnBytesRead,
    [out] DWORD *pnMinNumberOfBytesNeeded
);

DWORD GetPrivateProfileSectionNamesW(
    [out] LPWSTR lpszReturnBuffer,
    [in] DWORD nSize,
    [in] LPCWSTR lpFileName
);

BOOL SetDefaultCommConfigW(
    [in] LPCWSTR lpszName,
    [in] LPCOMMCONFIG lpCC,
    [in] DWORD dwSize
);

BOOL CopyFileW(
    [in] LPCWSTR lpExistingFileName,
    [in] LPCWSTR lpNewFileName,
    [in] BOOL bFailIfExists
);

BOOL GetProcessAffinityMask(
    [in] HANDLE hProcess,
    [out] PDWORD_PTR lpProcessAffinityMask,
    [out] PDWORD_PTR lpSystemAffinityMask
);

BOOL CopyFile(
    [in] LPCTSTR lpExistingFileName,
    [in] LPCTSTR lpNewFileName,
    [in] BOOL bFailIfExists
);

DWORD GetDllDirectoryW(
    [in] DWORD nBufferLength,
    [out] LPWSTR lpBuffer
);

BOOL GetDefaultCommConfigA(
    [in] LPCSTR lpszName,
    [out] LPCOMMCONFIG lpCC,
    [in, out] LPDWORD lpdwSize
);

DECLSPEC_ALLOCATOR HLOCAL LocalAlloc(
    [in] UINT uFlags,
    [in] SIZE_T uBytes
);

BOOL SetProcessAffinityMask(
    [in] HANDLE hProcess,
    [in] DWORD_PTR dwProcessAffinityMask
);

BOOLEAN CreateSymbolicLinkA(
    [in] LPCSTR lpSymlinkFileName,
    [in] LPCSTR lpTargetFileName,
    [in] DWORD dwFlags
);

ATOM GlobalAddAtomA(
    [in] LPCSTR lpString
);

BOOL FileEncryptionStatusA(
    [in] LPCSTR lpFileName,
    [out] LPDWORD lpStatus
);

HANDLE FindFirstVolumeMountPointA(
    [in] LPCSTR lpszRootPathName,
    [out] LPSTR lpszVolumeMountPoint,
    [in] DWORD cchBufferLength
);

HANDLE OpenCommPort(
    [in] ULONG uPortNumber,
    [in] DWORD dwDesiredAccess,
    [in] DWORD dwFlagsAndAttributes
);

BOOL GetNumaAvailableMemoryNodeEx(
    [in] USHORT Node,
    [out] PULONGLONG AvailableBytes
);

BOOL LookupAccountSidLocalW(
    [in] PSID Sid,
    [out, optional] LPWSTR Name,
    [in, out] LPDWORD cchName,
    [out, optional] LPWSTR ReferencedDomainName,
    [in, out] LPDWORD cchReferencedDomainName,
    [out] PSID_NAME_USE peUse
);

BOOL LookupPrivilegeNameA(
    [in, optional] LPCSTR lpSystemName,
    [in] PLUID lpLuid,
    [out, optional] LPSTR lpName,
    [in, out] LPDWORD cchName
);

BOOL WritePrivateProfileSectionW(
    [in] LPCWSTR lpAppName,
    [in] LPCWSTR lpString,
    [in] LPCWSTR lpFileName
);

DWORD OpenEncryptedFileRawW(
    [in] LPCWSTR lpFileName,
    [in] ULONG ulFlags,
    [out] PVOID *pvContext
);

DWORD GetProfileSectionA(
    [in] LPCSTR lpAppName,
    [out] LPSTR lpReturnedString,
    [in] DWORD nSize
);

BOOL FindActCtxSectionStringW(
    [in] DWORD dwFlags,
    [in] const GUID *lpExtensionGuid,
    [in] ULONG ulSectionId,
    [in] LPCWSTR lpStringToFind,
    [out] PACTCTX_SECTION_KEYED_DATA ReturnedData
);

LPVOID MapViewOfFileExNuma(
    [in] HANDLE hFileMappingObject,
    [in] DWORD dwDesiredAccess,
    [in] DWORD dwFileOffsetHigh,
    [in] DWORD dwFileOffsetLow,
    [in] SIZE_T dwNumberOfBytesToMap,
    [in, optional] LPVOID lpBaseAddress,
    [in] DWORD nndPreferred
);

BOOL GetNamedPipeServerProcessId(
    [in] HANDLE Pipe,
    [out] PULONG ServerProcessId
);

DWORD GetCompressedFileSizeTransactedW(
    [in] LPCWSTR lpFileName,
    [out, optional] LPDWORD lpFileSizeHigh,
    [in] HANDLE hTransaction
);

BOOL RemoveDirectoryTransactedW(
    [in] LPCWSTR lpPathName,
    [in] HANDLE hTransaction
);

BOOL FindNextVolumeA(
    [in] HANDLE hFindVolume,
    [out] LPSTR lpszVolumeName,
    [in] DWORD cchBufferLength
);

BOOL CreateDirectoryExW(
    [in] LPCWSTR lpTemplateDirectory,
    [in] LPCWSTR lpNewDirectory,
    [in, optional] LPSECURITY_ATTRIBUTES lpSecurityAttributes
);

BOOL LogonUserExA(
    [in] LPCSTR lpszUsername,
    [in, optional] LPCSTR lpszDomain,
    [in, optional] LPCSTR lpszPassword,
    [in] DWORD dwLogonType,
    [in] DWORD dwLogonProvider,
    [out, optional] PHANDLE phToken,
    [out, optional] PSID *ppLogonSid,
    [out, optional] PVOID *ppProfileBuffer,
    [out, optional] LPDWORD pdwProfileLength,
    [out, optional] PQUOTA_LIMITS pQuotaLimits
);

BOOL DeactivateActCtx(
    [in] DWORD dwFlags,
    [in] ULONG_PTR ulCookie
);

BOOL SetFileBandwidthReservation(
    [in] HANDLE hFile,
    [in] DWORD nPeriodMilliseconds,
    [in] DWORD nBytesPerPeriod,
    [in] BOOL bDiscardable,
    [out] LPDWORD lpTransferSize,
    [out] LPDWORD lpNumOutstandingRequests
);

BOOL PowerClearRequest(
    [in] HANDLE PowerRequest,
    [in] POWER_REQUEST_TYPE RequestType
);

BOOL PrivilegedServiceAuditAlarmA(
    [in] LPCSTR SubsystemName,
    [in] LPCSTR ServiceName,
    [in] HANDLE ClientToken,
    [in] PPRIVILEGE_SET Privileges,
    [in] BOOL AccessGranted
);

BOOL DeleteUmsCompletionList(
    [in] PUMS_COMPLETION_LIST UmsCompletionList
);

BOOL CreateDirectoryTransactedW(
    [in, optional] LPCWSTR lpTemplateDirectory,
    [in] LPCWSTR lpNewDirectory,
    [in, optional] LPSECURITY_ATTRIBUTES lpSecurityAttributes,
    [in] HANDLE hTransaction
);

DWORD ReadThreadProfilingData(
    [in] HANDLE PerformanceDataHandle,
    [in] DWORD Flags,
    [out] PPERFORMANCE_DATA PerformanceData
);

BOOL SetSystemPowerState(
    [in] BOOL fSuspend,
    [in] BOOL fForce
);

BOOL SetCommMask(
    [in] HANDLE hFile,
    [in] DWORD dwEvtMask
);

UINT SetHandleCount(
    UINT uNumber
);

HRSRC FindResourceExA(
    [in, optional] HMODULE hModule,
    [in] LPCSTR lpType,
    [in] LPCSTR lpName,
    [in] WORD wLanguage
);

DWORD GetFirmwareEnvironmentVariableExW(
    LPCWSTR lpName,
    LPCWSTR lpGuid,
    PVOID pBuffer,
    DWORD nSize,
    PDWORD pdwAttribubutes
);

BOOL AddConditionalAce(
    [in, out] PACL pAcl,
    [in] DWORD dwAceRevision,
    [in] DWORD AceFlags,
    [in] UCHAR AceType,
    [in] DWORD AccessMask,
    [in] PSID pSid,
    [in] PWCHAR ConditionStr,
    [out] DWORD *ReturnLength
);

BOOL CreateProcessWithLogonW(
    [in] LPCWSTR lpUsername,
    [in, optional] LPCWSTR lpDomain,
    [in] LPCWSTR lpPassword,
    [in] DWORD dwLogonFlags,
    [in, optional] LPCWSTR lpApplicationName,
    [in, out, optional] LPWSTR lpCommandLine,
    [in] DWORD dwCreationFlags,
    [in, optional] LPVOID lpEnvironment,
    [in, optional] LPCWSTR lpCurrentDirectory,
    [in] LPSTARTUPINFOW lpStartupInfo,
    [out] LPPROCESS_INFORMATION lpProcessInformation
);

ULONG GetCommPorts(
    [out] PULONG lpPortNumbers,
    [in] ULONG uPortNumbersCount,
    [out] PULONG puPortNumbersFound
);

BOOL RemoveDirectoryTransactedA(
    [in] LPCSTR lpPathName,
    [in] HANDLE hTransaction
);

BOOL WriteProfileStringW(
    [in] LPCWSTR lpAppName,
    [in] LPCWSTR lpKeyName,
    [in] LPCWSTR lpString
);

DWORD LoadModule(
    [in] LPCSTR lpModuleName,
    [in] LPVOID lpParameterBlock
);

int lstrlenA(
    [in] LPCSTR lpString
);

BOOL CreateHardLinkW(
    [in] LPCWSTR lpFileName,
    [in] LPCWSTR lpExistingFileName,
    LPSECURITY_ATTRIBUTES lpSecurityAttributes
);

HRESULT RegisterApplicationRestart(
    [in, optional] PCWSTR pwzCommandline,
    [in] DWORD dwFlags
);

DWORD PrepareTape(
    [in] HANDLE hDevice,
    [in] DWORD dwOperation,
    [in] BOOL bImmediate
);

BOOL LookupAccountNameA(
    [in, optional] LPCSTR lpSystemName,
    [in] LPCSTR lpAccountName,
    [out, optional] PSID Sid,
    [in, out] LPDWORD cbSid,
    [out, optional] LPSTR ReferencedDomainName,
    [in, out] LPDWORD cchReferencedDomainName,
    [out] PSID_NAME_USE peUse
);

void AddRefActCtx(
    [in] HANDLE hActCtx
);

LPVOID LocalLock(
    [in] HLOCAL hMem
);

BOOL LookupAccountSidW(
    [in, optional] LPCWSTR lpSystemName,
    [in] PSID Sid,
    [out, optional] LPWSTR Name,
    [in, out] LPDWORD cchName,
    [out, optional] LPWSTR ReferencedDomainName,
    [in, out] LPDWORD cchReferencedDomainName,
    [out] PSID_NAME_USE peUse
);

HRESULT GetApplicationRecoveryCallback(
    [in] HANDLE hProcess,
    [out] APPLICATION_RECOVERY_CALLBACK *pRecoveryCallback,
    [out] PVOID *ppvParameter,
    [out] PDWORD pdwPingInterval,
    [out] PDWORD pdwFlags
);

void ApplicationRecoveryFinished(
    [in] BOOL bSuccess
);

BOOL CreateDirectoryExA(
    [in] LPCSTR lpTemplateDirectory,
    [in] LPCSTR lpNewDirectory,
    [in, optional] LPSECURITY_ATTRIBUTES lpSecurityAttributes
);

BOOL GetComputerNameW(
    [out] LPWSTR lpBuffer,
    [in, out] LPDWORD nSize
);

BOOL BindIoCompletionCallback(
    [in] HANDLE FileHandle,
    [in] LPOVERLAPPED_COMPLETION_ROUTINE Function,
    [in] ULONG Flags
);

UINT GetProfileIntA(
    [in] LPCSTR lpAppName,
    [in] LPCSTR lpKeyName,
    [in] INT nDefault
);

BOOL FileEncryptionStatusW(
    [in] LPCWSTR lpFileName,
    [out] LPDWORD lpStatus
);

BOOL DeleteFileTransactedA(
    [in] LPCSTR lpFileName,
    [in] HANDLE hTransaction
);

BOOL GetCommModemStatus(
    [in] HANDLE hFile,
    [out] LPDWORD lpModemStat
);

BOOL SetCommConfig(
    [in] HANDLE hCommDev,
    [in] LPCOMMCONFIG lpCC,
    [in] DWORD dwSize
);

UINT GetTempFileName(
    [in] LPCTSTR lpPathName,
    [in] LPCTSTR lpPrefixString,
    [in] UINT uUnique,
    [out] LPTSTR lpTempFileName
);

BOOL UpdateResourceA(
    [in] HANDLE hUpdate,
    [in] LPCSTR lpType,
    [in] LPCSTR lpName,
    [in] WORD wLanguage,
    [in, optional] LPVOID lpData,
    [in] DWORD cb
);

BOOL GetCurrentHwProfileA(
    [out] LPHW_PROFILE_INFOA lpHwProfileInfo
);

void MAKEINTATOM(
    i
);

DWORD WTSGetActiveConsoleSessionId();

DWORD CreateTapePartition(
    [in] HANDLE hDevice,
    [in] DWORD dwPartitionMethod,
    [in] DWORD dwCount,
    [in] DWORD dwSize
);

BOOL EnumResourceTypesA(
    [in, optional] HMODULE hModule,
    [in] ENUMRESTYPEPROCA lpEnumFunc,
    [in] LONG_PTR lParam
);

DWORD GetFirmwareEnvironmentVariableW(
    [in] LPCWSTR lpName,
    [in] LPCWSTR lpGuid,
    [out] PVOID pBuffer,
    [in] DWORD nSize
);

BOOL GetNamedPipeServerSessionId(
    [in] HANDLE Pipe,
    [out] PULONG ServerSessionId
);

DWORD GetProfileStringW(
    [in] LPCWSTR lpAppName,
    [in] LPCWSTR lpKeyName,
    [in] LPCWSTR lpDefault,
    [out] LPWSTR lpReturnedString,
    [in] DWORD nSize
);

BOOL GetComputerNameA(
    [out] LPSTR lpBuffer,
    [in, out] LPDWORD nSize
);

LPVOID CreateFiberEx(
    [in] SIZE_T dwStackCommitSize,
    [in] SIZE_T dwStackReserveSize,
    [in] DWORD dwFlags,
    [in] LPFIBER_START_ROUTINE lpStartAddress,
    [in, optional] LPVOID lpParameter
);

HANDLE FindFirstVolumeMountPointW(
    [in] LPCWSTR lpszRootPathName,
    [out] LPWSTR lpszVolumeMountPoint,
    [in] DWORD cchBufferLength
);

BOOL CreateDirectoryTransactedA(
    [in, optional] LPCSTR lpTemplateDirectory,
    [in] LPCSTR lpNewDirectory,
    [in, optional] LPSECURITY_ATTRIBUTES lpSecurityAttributes,
    [in] HANDLE hTransaction
);

BOOL ActivateActCtx(
    [in] HANDLE hActCtx,
    [out] ULONG_PTR *lpCookie
);

int MulDiv(
    [in] int nNumber,
    [in] int nNumerator,
    [in] int nDenominator
);

BOOL GetThreadSelectorEntry(
    [in] HANDLE hThread,
    [in] DWORD dwSelector,
    [out] LPLDT_ENTRY lpSelectorEntry
);

BOOL BuildCommDCBA(
    [in] LPCSTR lpDef,
    [out] LPDCB lpDCB
);

HANDLE OpenEventLogW(
    [in] LPCWSTR lpUNCServerName,
    [in] LPCWSTR lpSourceName
);

BOOL SetEnvironmentVariable(
    [in] LPCTSTR lpName,
    [in, optional] LPCTSTR lpValue
);

BOOL GetSystemPowerStatus(
    [out] LPSYSTEM_POWER_STATUS lpSystemPowerStatus
);

BOOL CopyFileExW(
    [in] LPCWSTR lpExistingFileName,
    [in] LPCWSTR lpNewFileName,
    [in, optional] LPPROGRESS_ROUTINE lpProgressRoutine,
    [in, optional] LPVOID lpData,
    [in, optional] LPBOOL pbCancel,
    [in] DWORD dwCopyFlags
);

BOOL ReadEventLogW(
    [in] HANDLE hEventLog,
    [in] DWORD dwReadFlags,
    [in] DWORD dwRecordOffset,
    [out] LPVOID lpBuffer,
    [in] DWORD nNumberOfBytesToRead,
    [out] DWORD *pnBytesRead,
    [out] DWORD *pnMinNumberOfBytesNeeded
);

DWORD GetPrivateProfileSectionNamesA(
    [out] LPSTR lpszReturnBuffer,
    [in] DWORD nSize,
    [in] LPCSTR lpFileName
);

BOOL BuildCommDCBW(
    [in] LPCWSTR lpDef,
    [out] LPDCB lpDCB
);

BOOL GetNamedPipeClientProcessId(
    [in] HANDLE Pipe,
    [out] PULONG ClientProcessId
);

BOOL WritePrivateProfileStringW(
    [in] LPCWSTR lpAppName,
    [in] LPCWSTR lpKeyName,
    [in] LPCWSTR lpString,
    [in] LPCWSTR lpFileName
);

HANDLE CreateActCtxA(
    [in, out] PCACTCTXA pActCtx
);

BOOL VerifyVersionInfoA(
    [in] LPOSVERSIONINFOEXA lpVersionInformation,
    [in] DWORD dwTypeMask,
    [in] DWORDLONG dwlConditionMask
);

BOOL GetPrivateProfileStruct(
    [in] LPCTSTR lpszSection,
    [in] LPCTSTR lpszKey,
    [out] LPVOID lpStruct,
    [in] UINT uSizeStruct,
    [in] LPCTSTR szFile
);

void SetThreadpoolCallbackLibrary(
    [in, out] PTP_CALLBACK_ENVIRON pcbe,
    [in] PVOID mod
);

BOOL NotifyChangeEventLog(
    [in] HANDLE hEventLog,
    [in] HANDLE hEvent
);

BOOL LookupPrivilegeValueW(
    [in, optional] LPCWSTR lpSystemName,
    [in] LPCWSTR lpName,
    [out] PLUID lpLuid
);

DWORD GetPrivateProfileSectionNames(
    [out] LPTSTR lpszReturnBuffer,
    [in] DWORD nSize,
    [in] LPCTSTR lpFileName
);

HANDLE OpenJobObjectA(
    [in] DWORD dwDesiredAccess,
    [in] BOOL bInheritHandle,
    [in] LPCSTR lpName
);

BOOL LookupAccountSidLocalA(
    [in] PSID Sid,
    [out, optional] LPSTR Name,
    [in, out] LPDWORD cchName,
    [out, optional] LPSTR ReferencedDomainName,
    [in, out] LPDWORD cchReferencedDomainName,
    [out] PSID_NAME_USE peUse
);

HRSRC FindResourceA(
    [in, optional] HMODULE hModule,
    [in] LPCSTR lpName,
    [in] LPCSTR lpType
);

BOOL CommConfigDialogW(
    [in] LPCWSTR lpszName,
    [in] HWND hWnd,
    [in, out] LPCOMMCONFIG lpCC
);

HRESULT UnregisterApplicationRecoveryCallback();

HLOCAL LocalFree(
    [in] _Frees_ptr_opt_ HLOCAL hMem
);

LPSTR lstrcpyA(
    [out] LPSTR lpString1,
    [in] LPCSTR lpString2
);

ATOM GlobalDeleteAtom(
    [in] ATOM nAtom
);

ATOM GlobalFindAtomW(
    [in] LPCWSTR lpString
);

BOOL SetProcessDEPPolicy(
    [in] DWORD dwFlags
);

BOOL AccessCheckByTypeResultListAndAuditAlarmByHandleA(
    [in] LPCSTR SubsystemName,
    [in] LPVOID HandleId,
    [in] HANDLE ClientToken,
    [in] LPCSTR ObjectTypeName,
    [in, optional] LPCSTR ObjectName,
    [in] PSECURITY_DESCRIPTOR SecurityDescriptor,
    [in, optional] PSID PrincipalSelfSid,
    [in] DWORD DesiredAccess,
    [in] AUDIT_EVENT_TYPE AuditType,
    [in] DWORD Flags,
    [in, out, optional] POBJECT_TYPE_LIST ObjectTypeList,
    [in] DWORD ObjectTypeListLength,
    [in] PGENERIC_MAPPING GenericMapping,
    [in] BOOL ObjectCreation,
    [out] LPDWORD GrantedAccess,
    [out] LPDWORD AccessStatusList,
    [out] LPBOOL pfGenerateOnClose
);

BOOL CreateUmsCompletionList(
    [out] PUMS_COMPLETION_LIST *UmsCompletionList
);

__analysis_noreturn VOID FatalExit(
    [in] int ExitCode
);

BOOL GetCommTimeouts(
    [in] HANDLE hFile,
    [out] LPCOMMTIMEOUTS lpCommTimeouts
);

BOOL GetOldestEventLogRecord(
    [in] HANDLE hEventLog,
    [out] PDWORD OldestRecord
);

BOOL FindNextVolumeMountPointA(
    [in] HANDLE hFindVolumeMountPoint,
    [out] LPSTR lpszVolumeMountPoint,
    [in] DWORD cchBufferLength
);

BOOL QueryActCtxW(
    [in] DWORD dwFlags,
    [in] HANDLE hActCtx,
    [in, optional] PVOID pvSubInstance,
    [in] ULONG ulInfoClass,
    [out] PVOID pvBuffer,
    [in, optional] SIZE_T cbBuffer,
    [out, optional] SIZE_T *pcbWrittenOrRequired
);

WORD GetActiveProcessorGroupCount();

UINT GetProfileIntW(
    [in] LPCWSTR lpAppName,
    [in] LPCWSTR lpKeyName,
    [in] INT nDefault
);

BOOL BuildCommDCBAndTimeoutsA(
    [in] LPCSTR lpDef,
    [out] LPDCB lpDCB,
    [out] LPCOMMTIMEOUTS lpCommTimeouts
);

LPVOID ConvertThreadToFiber(
    [in, optional] LPVOID lpParameter
);

BOOL MoveFileTransactedW(
    [in] LPCWSTR lpExistingFileName,
    [in, optional] LPCWSTR lpNewFileName,
    [in, optional] LPPROGRESS_ROUTINE lpProgressRoutine,
    [in, optional] LPVOID lpData,
    [in] DWORD dwFlags,
    [in] HANDLE hTransaction
);

BOOL GetDevicePowerState(
    [in] HANDLE hDevice,
    [out] BOOL *pfOn
);

BOOL GetCurrentActCtx(
    [out] HANDLE *lphActCtx
);

BOOL PulseEvent(
    [in] HANDLE hEvent
);

BOOL GetNumaProcessorNodeEx(
    [in] PPROCESSOR_NUMBER Processor,
    [out] PUSHORT NodeNumber
);

BOOL DecryptFileA(
    [in] LPCSTR lpFileName,
    DWORD dwReserved
);

BOOL MapUserPhysicalPagesScatter(
    [in] PVOID *VirtualAddresses,
    [in] ULONG_PTR NumberOfPages,
    [in] PULONG_PTR PageArray
);

BOOL IsBadStringPtrA(
    [in] LPCSTR lpsz,
    [in] UINT_PTR ucchMax
);

HFILE _lclose(
    HFILE hFile
);

BOOL IsSystemResumeAutomatic();

BOOL ZombifyActCtx(
    [in] HANDLE hActCtx
);

BOOL GetProcessIoCounters(
    [in] HANDLE hProcess,
    [out] PIO_COUNTERS lpIoCounters
);

BOOL SetFileShortNameW(
    [in] HANDLE hFile,
    [in] LPCWSTR lpShortName
);

BOOL UpdateResourceW(
    [in] HANDLE hUpdate,
    [in] LPCWSTR lpType,
    [in] LPCWSTR lpName,
    [in] WORD wLanguage,
    [in, optional] LPVOID lpData,
    [in] DWORD cb
);

BOOL GetFirmwareType(
    [in, out] PFIRMWARE_TYPE FirmwareType
);

HANDLE CreateSemaphoreExA(
    [in, optional] LPSECURITY_ATTRIBUTES lpSemaphoreAttributes,
    [in] LONG lInitialCount,
    [in] LONG lMaximumCount,
    [in, optional] LPCSTR lpName,
    DWORD dwFlags,
    [in] DWORD dwDesiredAccess
);

BOOLEAN CreateSymbolicLinkTransactedW(
    [in] LPCWSTR lpSymlinkFileName,
    [in] LPCWSTR lpTargetFileName,
    [in] DWORD dwFlags,
    [in] HANDLE hTransaction
);

BOOL GetNumaNodeProcessorMask(
    [in] UCHAR Node,
    [out] PULONGLONG ProcessorMask
);

BOOL InitializeContext2(
    [out, optional] PVOID Buffer,
    DWORD ContextFlags,
    [out, optional] PCONTEXT *Context,
    [in, out] PDWORD ContextLength,
    ULONG64 XStateCompactionMask
);

DEP_SYSTEM_POLICY_TYPE GetSystemDEPPolicy();

BOOL SetFirmwareEnvironmentVariableExW(
    [in] LPCWSTR lpName,
    [in] LPCWSTR lpGuid,
    [in] PVOID pValue,
    [in] DWORD nSize,
    [in] DWORD dwAttributes
);

BOOL WritePrivateProfileStringA(
    [in] LPCSTR lpAppName,
    [in] LPCSTR lpKeyName,
    [in] LPCSTR lpString,
    [in] LPCSTR lpFileName
);

BOOL SetFileAttributesTransactedA(
    [in] LPCSTR lpFileName,
    [in] DWORD dwFileAttributes,
    [in] HANDLE hTransaction
);

BOOL CopyContext(
    [in, out] PCONTEXT Destination,
    [in] DWORD ContextFlags,
    [in] PCONTEXT Source
);

BOOL EndUpdateResourceA(
    [in] HANDLE hUpdate,
    [in] BOOL fDiscard
);

LPWSTR lstrcatW(
    [in, out] LPWSTR lpString1,
    [in] LPCWSTR lpString2
);

BOOL ClearCommError(
    [in] HANDLE hFile,
    [out, optional] LPDWORD lpErrors,
    [out, optional] LPCOMSTAT lpStat
);

BOOL IsTextUnicode(
    [in] const VOID *lpv,
    [in] int iSize,
    [in, out, optional] LPINT lpiResult
);

HANDLE CreateBoundaryDescriptorA(
    [in] LPCSTR Name,
    [in] ULONG Flags
);

DWORD GetLongPathNameTransactedW(
    [in] LPCWSTR lpszShortPath,
    [out] LPWSTR lpszLongPath,
    [in] DWORD cchBuffer,
    [in] HANDLE hTransaction
);

HLOCAL LocalHandle(
    [in] LPCVOID pMem
);

BOOL ReplaceFileA(
    [in] LPCSTR lpReplacedFileName,
    [in] LPCSTR lpReplacementFileName,
    [in, optional] LPCSTR lpBackupFileName,
    [in] DWORD dwReplaceFlags,
    LPVOID lpExclude,
    LPVOID lpReserved
);

DWORD OpenEncryptedFileRawA(
    [in] LPCSTR lpFileName,
    [in] ULONG ulFlags,
    [out] PVOID *pvContext
);

BOOL Wow64GetThreadSelectorEntry(
    [in] HANDLE hThread,
    [in] DWORD dwSelector,
    [out] PWOW64_LDT_ENTRY lpSelectorEntry
);

BOOL DnsHostnameToComputerNameA(
    [in] LPCSTR Hostname,
    [out] LPSTR ComputerName,
    [in, out] LPDWORD nSize
);

int lstrcmpiW(
    [in] LPCWSTR lpString1,
    [in] LPCWSTR lpString2
);

DWORD FormatMessage(
    [in] DWORD dwFlags,
    [in, optional] LPCVOID lpSource,
    [in] DWORD dwMessageId,
    [in] DWORD dwLanguageId,
    [out] LPTSTR lpBuffer,
    [in] DWORD nSize,
    [in, optional] va_list *Arguments
);

DWORD GetCurrentDirectory(
    [in] DWORD nBufferLength,
    [out] LPTSTR lpBuffer
);

UINT GlobalFlags(
    [in] HGLOBAL hMem
);

BOOL GetCommConfig(
    [in] HANDLE hCommDev,
    [out] LPCOMMCONFIG lpCC,
    [in, out] LPDWORD lpdwSize
);

LPVOID CreateFiber(
    [in] SIZE_T dwStackSize,
    [in] LPFIBER_START_ROUTINE lpStartAddress,
    [in, optional] LPVOID lpParameter
);

BOOL SetVolumeMountPointA(
    [in] LPCSTR lpszVolumeMountPoint,
    [in] LPCSTR lpszVolumeName
);

HANDLE CreateActCtxW(
    [in, out] PCACTCTXW pActCtx
);

BOOL GetNumberOfEventLogRecords(
    [in] HANDLE hEventLog,
    [out] PDWORD NumberOfRecords
);

BOOL PurgeComm(
    [in] HANDLE hFile,
    [in] DWORD dwFlags
);

BOOL IsBadReadPtr(
    [in] const VOID *lp,
    [in] UINT_PTR ucb
);

DWORD GetActiveProcessorCount(
    [in] WORD GroupNumber
);

DWORD GetFirmwareEnvironmentVariableExA(
    LPCSTR lpName,
    LPCSTR lpGuid,
    PVOID pBuffer,
    DWORD nSize,
    PDWORD pdwAttribubutes
);

UINT GetPrivateProfileIntA(
    [in] LPCSTR lpAppName,
    [in] LPCSTR lpKeyName,
    [in] INT nDefault,
    [in] LPCSTR lpFileName
);

BOOL RequestWakeupLatency(
    [in] LATENCY_TIME latency
);

void GlobalDiscard(
    [in] h
);

BOOL ReplaceFileW(
    [in] LPCWSTR lpReplacedFileName,
    [in] LPCWSTR lpReplacementFileName,
    [in, optional] LPCWSTR lpBackupFileName,
    [in] DWORD dwReplaceFlags,
    LPVOID lpExclude,
    LPVOID lpReserved
);

DWORD64 GetEnabledXStateFeatures();

UINT _lwrite(
    HFILE hFile,
    LPCCH lpBuffer,
    UINT uBytes
);

BOOL MoveFile(
    [in] LPCTSTR lpExistingFileName,
    [in] LPCTSTR lpNewFileName
);

BOOL MoveFileWithProgressA(
    [in] LPCSTR lpExistingFileName,
    [in, optional] LPCSTR lpNewFileName,
    [in, optional] LPPROGRESS_ROUTINE lpProgressRoutine,
    [in, optional] LPVOID lpData,
    [in] DWORD dwFlags
);

HANDLE BeginUpdateResourceW(
    [in] LPCWSTR pFileName,
    [in] BOOL bDeleteExistingResources
);

BOOL GetNumaNodeNumberFromHandle(
    [in] HANDLE hFile,
    [out] PUSHORT NodeNumber
);

BOOL ReadDirectoryChangesW(
    [in] HANDLE hDirectory,
    [out] LPVOID lpBuffer,
    [in] DWORD nBufferLength,
    [in] BOOL bWatchSubtree,
    [in] DWORD dwNotifyFilter,
    [out, optional] LPDWORD lpBytesReturned,
    [in, out, optional] LPOVERLAPPED lpOverlapped,
    [in, optional] LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine
);

BOOL GetVolumeNameForVolumeMountPointA(
    [in] LPCSTR lpszVolumeMountPoint,
    [out] LPSTR lpszVolumeName,
    [in] DWORD cchBufferLength
);

BOOL GetEventLogInformation(
    [in] HANDLE hEventLog,
    [in] DWORD dwInfoLevel,
    [out] LPVOID lpBuffer,
    [in] DWORD cbBufSize,
    [out] LPDWORD pcbBytesNeeded
);

void SetThreadpoolCallbackPriority(
    [in, out] PTP_CALLBACK_ENVIRON pcbe,
    [in] TP_CALLBACK_PRIORITY Priority
);

LPWSTR lstrcpynW(
    [out] LPWSTR lpString1,
    [in] LPCWSTR lpString2,
    [in] int iMaxLength
);

void ReleaseActCtx(
    [in] HANDLE hActCtx
);

BOOL QueryActCtxSettingsW(
    [in, optional] DWORD dwFlags,
    [in, optional] HANDLE hActCtx,
    [in, optional] PCWSTR settingsNameSpace,
    [in] PCWSTR settingName,
    [out] PWSTR pvBuffer,
    [in] SIZE_T dwBuffer,
    [out, optional] SIZE_T *pdwWrittenOrRequired
);

void SetThreadpoolCallbackPool(
    [in, out] PTP_CALLBACK_ENVIRON pcbe,
    [in] PTP_POOL ptpp
);

HFILE _lcreat(
    LPCSTR lpPathName,
    int iAttribute
);

DWORD WriteEncryptedFileRaw(
    [in] PFE_IMPORT_FUNC pfImportCallback,
    [in, optional] PVOID pvCallbackContext,
    [in] PVOID pvContext
);

BOOL GetUmsCompletionListEvent(
    [in] PUMS_COMPLETION_LIST UmsCompletionList,
    [in, out] PHANDLE UmsCompletionEvent
);

BOOL DebugBreakProcess(
    [in] HANDLE Process
);

BOOL GetPrivateProfileStructA(
    [in] LPCSTR lpszSection,
    [in] LPCSTR lpszKey,
    [out] LPVOID lpStruct,
    [in] UINT uSizeStruct,
    [in] LPCSTR szFile
);

HANDLE PowerCreateRequest(
    [in] PREASON_CONTEXT Context
);

BOOL AccessCheckByTypeResultListAndAuditAlarmA(
    [in] LPCSTR SubsystemName,
    [in] LPVOID HandleId,
    [in] LPCSTR ObjectTypeName,
    [in, optional] LPCSTR ObjectName,
    [in] PSECURITY_DESCRIPTOR SecurityDescriptor,
    [in, optional] PSID PrincipalSelfSid,
    [in] DWORD DesiredAccess,
    [in] AUDIT_EVENT_TYPE AuditType,
    [in] DWORD Flags,
    [in, out, optional] POBJECT_TYPE_LIST ObjectTypeList,
    [in] DWORD ObjectTypeListLength,
    [in] PGENERIC_MAPPING GenericMapping,
    [in] BOOL ObjectCreation,
    [out] LPDWORD GrantedAccess,
    [out] LPDWORD AccessStatusList,
    [out] LPBOOL pfGenerateOnClose
);

void CloseEncryptedFileRaw(
    [in] PVOID pvContext
);

ATOM GlobalFindAtomA(
    [in] LPCSTR lpString
);

BOOL ObjectPrivilegeAuditAlarmA(
    [in] LPCSTR SubsystemName,
    [in] LPVOID HandleId,
    [in] HANDLE ClientToken,
    [in] DWORD DesiredAccess,
    [in] PPRIVILEGE_SET Privileges,
    [in] BOOL AccessGranted
);

BOOL GetFileInformationByHandleEx(
    [in] HANDLE hFile,
    [in] FILE_INFO_BY_HANDLE_CLASS FileInformationClass,
    [out] LPVOID lpFileInformation,
    [in] DWORD dwBufferSize
);

BOOL EnumResourceLanguagesW(
    [in] HMODULE hModule,
    [in] LPCWSTR lpType,
    [in] LPCWSTR lpName,
    [in] ENUMRESLANGPROCW lpEnumFunc,
    [in] LONG_PTR lParam
);

BOOL GetPrivateProfileStructW(
    [in] LPCWSTR lpszSection,
    [in] LPCWSTR lpszKey,
    [out] LPVOID lpStruct,
    [in] UINT uSizeStruct,
    [in] LPCWSTR szFile
);

BOOL QueryFullProcessImageNameW(
    [in] HANDLE hProcess,
    [in] DWORD dwFlags,
    [out] LPWSTR lpExeName,
    [in, out] PDWORD lpdwSize
);

BOOL ReadDirectoryChangesExW(
    [in] HANDLE hDirectory,
    [out] LPVOID lpBuffer,
    [in] DWORD nBufferLength,
    [in] BOOL bWatchSubtree,
    [in] DWORD dwNotifyFilter,
    [out, optional] LPDWORD lpBytesReturned,
    [in, out, optional] LPOVERLAPPED lpOverlapped,
    [in, optional] LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine,
    [in] READ_DIRECTORY_NOTIFY_INFORMATION_CLASS ReadDirectoryNotifyInformationClass
);

HANDLE ReOpenFile(
    [in] HANDLE hOriginalFile,
    [in] DWORD dwDesiredAccess,
    [in] DWORD dwShareMode,
    [in] DWORD dwFlagsAndAttributes
);

DWORD GetPrivateProfileSectionA(
    [in] LPCSTR lpAppName,
    [out] LPSTR lpReturnedString,
    [in] DWORD nSize,
    [in] LPCSTR lpFileName
);

WORD GetMaximumProcessorGroupCount();

ATOM FindAtomA(
    [in] LPCSTR lpString
);

BOOL CreateHardLinkTransactedW(
    [in] LPCWSTR lpFileName,
    [in] LPCWSTR lpExistingFileName,
    LPSECURITY_ATTRIBUTES lpSecurityAttributes,
    [in] HANDLE hTransaction
);

ATOM GlobalAddAtomW(
    [in] LPCWSTR lpString
);

BOOL SetCommTimeouts(
    [in] HANDLE hFile,
    [in] LPCOMMTIMEOUTS lpCommTimeouts
);

BOOL AddIntegrityLabelToBoundaryDescriptor(
    [in, out] HANDLE *BoundaryDescriptor,
    [in] PSID IntegrityLabel
);

BOOL CreateHardLinkA(
    [in] LPCSTR lpFileName,
    [in] LPCSTR lpExistingFileName,
    LPSECURITY_ATTRIBUTES lpSecurityAttributes
);

DWORD GetProfileStringA(
    [in] LPCSTR lpAppName,
    [in] LPCSTR lpKeyName,
    [in] LPCSTR lpDefault,
    [out] LPSTR lpReturnedString,
    [in] DWORD nSize
);

PUMS_CONTEXT GetNextUmsListItem(
    [in, out] PUMS_CONTEXT UmsContext
);

BOOL BuildCommDCBAndTimeoutsW(
    [in] LPCWSTR lpDef,
    [out] LPDCB lpDCB,
    [out] LPCOMMTIMEOUTS lpCommTimeouts
);

BOOL MoveFileExA(
    [in] LPCSTR lpExistingFileName,
    [in, optional] LPCSTR lpNewFileName,
    [in] DWORD dwFlags
);

BOOL SetDefaultCommConfigA(
    [in] LPCSTR lpszName,
    [in] LPCOMMCONFIG lpCC,
    [in] DWORD dwSize
);

UINT GetAtomNameA(
    [in] ATOM nAtom,
    [out] LPSTR lpBuffer,
    [in] int nSize
);

LPVOID GlobalLock(
    [in] HGLOBAL hMem
);

void DestroyThreadpoolEnvironment(
    [in, out] PTP_CALLBACK_ENVIRON pcbe
);

ATOM AddAtomA(
    [in] LPCSTR lpString
);

BOOL FileTimeToDosDateTime(
    [in] const FILETIME *lpFileTime,
    [out] LPWORD lpFatDate,
    [out] LPWORD lpFatTime
);

BOOL SetCommState(
    [in] HANDLE hFile,
    [in] LPDCB lpDCB
);

BOOL GetNumaAvailableMemoryNode(
    [in] UCHAR Node,
    [out] PULONGLONG AvailableBytes
);

BOOL SetFirmwareEnvironmentVariableExA(
    [in] LPCSTR lpName,
    [in] LPCSTR lpGuid,
    [in] PVOID pValue,
    [in] DWORD nSize,
    [in] DWORD dwAttributes
);

DWORD FormatMessageA(
    [in] DWORD dwFlags,
    [in, optional] LPCVOID lpSource,
    [in] DWORD dwMessageId,
    [in] DWORD dwLanguageId,
    [out] LPSTR lpBuffer,
    [in] DWORD nSize,
    [in, optional] va_list *Arguments
);

HGLOBAL GlobalHandle(
    [in] LPCVOID pMem
);

HANDLE RegisterEventSourceW(
    [in] LPCWSTR lpUNCServerName,
    [in] LPCWSTR lpSourceName
);

HANDLE OpenBackupEventLogW(
    [in] LPCWSTR lpUNCServerName,
    [in] LPCWSTR lpFileName
);

BOOL GetUserNameA(
    [out] LPSTR lpBuffer,
    [in, out] LPDWORD pcbBuffer
);

BOOL DeleteFileTransactedW(
    [in] LPCWSTR lpFileName,
    [in] HANDLE hTransaction
);

HANDLE OpenFileById(
    [in] HANDLE hVolumeHint,
    [in] LPFILE_ID_DESCRIPTOR lpFileId,
    [in] DWORD dwDesiredAccess,
    [in] DWORD dwShareMode,
    [in, optional] LPSECURITY_ATTRIBUTES lpSecurityAttributes,
    [in] DWORD dwFlagsAndAttributes
);

BOOL QueryFullProcessImageNameA(
    [in] HANDLE hProcess,
    [in] DWORD dwFlags,
    [out] LPSTR lpExeName,
    [in, out] PDWORD lpdwSize
);

ATOM FindAtomW(
    [in] LPCWSTR lpString
);

BOOL CloseEventLog(
    [in, out] HANDLE hEventLog
);

BOOL VerifyVersionInfoW(
    [in] LPOSVERSIONINFOEXW lpVersionInformation,
    [in] DWORD dwTypeMask,
    [in] DWORDLONG dwlConditionMask
);

BOOL EncryptFileW(
    [in] LPCWSTR lpFileName
);

ATOM GlobalAddAtomExW(
    [in, optional] LPCWSTR lpString,
    [in] DWORD Flags
);

LONG _llseek(
    HFILE hFile,
    LONG lOffset,
    int iOrigin
);

BOOL SetFileSecurityA(
    [in] LPCSTR lpFileName,
    [in] SECURITY_INFORMATION SecurityInformation,
    [in] PSECURITY_DESCRIPTOR pSecurityDescriptor
);

PVOID LocateXStateFeature(
    [in] PCONTEXT Context,
    [in] DWORD FeatureId,
    [out, optional] PDWORD Length
);

BOOL FindVolumeMountPointClose(
    [in] HANDLE hFindVolumeMountPoint
);

HANDLE BeginUpdateResourceA(
    [in] LPCSTR pFileName,
    [in] BOOL bDeleteExistingResources
);

LPVOID ConvertThreadToFiberEx(
    [in, optional] LPVOID lpParameter,
    [in] DWORD dwFlags
);

BOOL WaitNamedPipeA(
    [in] LPCSTR lpNamedPipeName,
    [in] DWORD nTimeOut
);

BOOL GetVolumePathNameA(
    [in] LPCSTR lpszFileName,
    [out] LPSTR lpszVolumePathName,
    [in] DWORD cchBufferLength
);

DWORD GetCompressedFileSizeTransactedA(
    [in] LPCSTR lpFileName,
    [out, optional] LPDWORD lpFileSizeHigh,
    [in] HANDLE hTransaction
);

UINT GetPrivateProfileIntW(
    [in] LPCWSTR lpAppName,
    [in] LPCWSTR lpKeyName,
    [in] INT nDefault,
    [in] LPCWSTR lpFileName
);

BOOL EnumResourceTypesW(
    [in, optional] HMODULE hModule,
    [in] ENUMRESTYPEPROCW lpEnumFunc,
    [in] LONG_PTR lParam
);

BOOL GetCommState(
    [in] HANDLE hFile,
    [in, out] LPDCB lpDCB
);

int __clrcall WinMain(
    [in] HINSTANCE hInstance,
    [in, optional] HINSTANCE hPrevInstance,
    [in] LPSTR lpCmdLine,
    [in] int nShowCmd
);

DWORD GetPrivateProfileStringW(
    [in] LPCWSTR lpAppName,
    [in] LPCWSTR lpKeyName,
    [in] LPCWSTR lpDefault,
    [out] LPWSTR lpReturnedString,
    [in] DWORD nSize,
    [in] LPCWSTR lpFileName
);

BOOL ReportEventA(
    [in] HANDLE hEventLog,
    [in] WORD wType,
    [in] WORD wCategory,
    [in] DWORD dwEventID,
    [in] PSID lpUserSid,
    [in] WORD wNumStrings,
    [in] DWORD dwDataSize,
    [in] LPCSTR *lpStrings,
    [in] LPVOID lpRawData
);

UINT GetPrivateProfileInt(
    [in] LPCTSTR lpAppName,
    [in] LPCTSTR lpKeyName,
    [in] INT nDefault,
    [in] LPCTSTR lpFileName
);

HFILE OpenFile(
    [in] LPCSTR lpFileName,
    [out] LPOFSTRUCT lpReOpenBuff,
    [in] UINT uStyle
);

BOOL DeleteVolumeMountPointA(
    [in] LPCSTR lpszVolumeMountPoint
);

HFILE _lopen(
    LPCSTR lpPathName,
    int iReadWrite
);

BOOL IsBadCodePtr(
    [in] FARPROC lpfn
);

BOOL ObjectOpenAuditAlarmA(
    [in] LPCSTR SubsystemName,
    [in] LPVOID HandleId,
    [in] LPSTR ObjectTypeName,
    [in, optional] LPSTR ObjectName,
    [in] PSECURITY_DESCRIPTOR pSecurityDescriptor,
    [in] HANDLE ClientToken,
    [in] DWORD DesiredAccess,
    [in] DWORD GrantedAccess,
    [in, optional] PPRIVILEGE_SET Privileges,
    [in] BOOL ObjectCreation,
    [in] BOOL AccessGranted,
    [out] LPBOOL GenerateOnClose
);

BOOL SetVolumeMountPointW(
    [in] LPCWSTR lpszVolumeMountPoint,
    [in] LPCWSTR lpszVolumeName
);

DWORD GetProfileSectionW(
    [in] LPCWSTR lpAppName,
    [out] LPWSTR lpReturnedString,
    [in] DWORD nSize
);

DWORD GetTapeParameters(
    [in] HANDLE hDevice,
    [in] DWORD dwOperation,
    [out] LPDWORD lpdwSize,
    [out] LPVOID lpTapeInformation
);

BOOL LocalUnlock(
    [in] HLOCAL hMem
);

HRESULT CopyFile2(
    [in] PCWSTR pwszExistingFileName,
    [in] PCWSTR pwszNewFileName,
    [in, optional] COPYFILE2_EXTENDED_PARAMETERS *pExtendedParameters
);

BOOL GetProcessDEPPolicy(
    [in] HANDLE hProcess,
    [out] LPDWORD lpFlags,
    [out] PBOOL lpPermanent
);

BOOL LogonUserW(
    [in] LPCWSTR lpszUsername,
    [in, optional] LPCWSTR lpszDomain,
    [in, optional] LPCWSTR lpszPassword,
    [in] DWORD dwLogonType,
    [in] DWORD dwLogonProvider,
    [out] PHANDLE phToken
);

BOOL GetSystemRegistryQuota(
    [out, optional] PDWORD pdwQuotaAllowed,
    [out, optional] PDWORD pdwQuotaUsed
);

ATOM DeleteAtom(
    [in] ATOM nAtom
);

BOOL FindActCtxSectionGuid(
    [in] DWORD dwFlags,
    [in] const GUID *lpExtensionGuid,
    [in] ULONG ulSectionId,
    [in] const GUID *lpGuidToFind,
    [out] PACTCTX_SECTION_KEYED_DATA ReturnedData
);

BOOL CreateDirectory(
    [in] LPCTSTR lpPathName,
    [in, optional] LPSECURITY_ATTRIBUTES lpSecurityAttributes
);

DWORD ReadEncryptedFileRaw(
    [in] PFE_EXPORT_FUNC pfExportCallback,
    [in, optional] PVOID pvCallbackContext,
    [in] PVOID pvContext
);

DWORD GetFullPathNameTransactedA(
    [in] LPCSTR lpFileName,
    [in] DWORD nBufferLength,
    [out] LPSTR lpBuffer,
    [out] LPSTR *lpFilePart,
    [in] HANDLE hTransaction
);

BOOL GetNumaProximityNode(
    [in] ULONG ProximityId,
    [out] PUCHAR NodeNumber
);

BOOL MoveFileWithProgressW(
    [in] LPCWSTR lpExistingFileName,
    [in, optional] LPCWSTR lpNewFileName,
    [in, optional] LPPROGRESS_ROUTINE lpProgressRoutine,
    [in, optional] LPVOID lpData,
    [in] DWORD dwFlags
);

BOOL DecryptFileW(
    [in] LPCWSTR lpFileName,
    DWORD dwReserved
);

HANDLE CreateMailslotW(
    [in] LPCWSTR lpName,
    [in] DWORD nMaxMessageSize,
    [in] DWORD lReadTimeout,
    [in, optional] LPSECURITY_ATTRIBUTES lpSecurityAttributes
);

BOOL LookupPrivilegeValueA(
    [in, optional] LPCSTR lpSystemName,
    [in] LPCSTR lpName,
    [out] PLUID lpLuid
);

BOOL GetNamedPipeHandleStateA(
    [in] HANDLE hNamedPipe,
    [out, optional] LPDWORD lpState,
    [out, optional] LPDWORD lpCurInstances,
    [out, optional] LPDWORD lpMaxCollectionCount,
    [out, optional] LPDWORD lpCollectDataTimeout,
    [out, optional] LPSTR lpUserName,
    [in] DWORD nMaxUserNameSize
);

DWORD WriteTapemark(
    [in] HANDLE hDevice,
    [in] DWORD dwTapemarkType,
    [in] DWORD dwTapemarkCount,
    [in] BOOL bImmediate
);

BOOL EnterUmsSchedulingMode(
    [in] PUMS_SCHEDULER_STARTUP_INFO SchedulerStartupInfo
);

DWORD GetTapeStatus(
    [in] HANDLE hDevice
);

BOOL CheckNameLegalDOS8Dot3A(
    [in] LPCSTR lpName,
    [out, optional] LPSTR lpOemName,
    [in] DWORD OemNameSize,
    [out, optional] PBOOL pbNameContainsSpaces,
    [out] PBOOL pbNameLegal
);

BOOL ConvertFiberToThread();

BOOL SetFirmwareEnvironmentVariableA(
    [in] LPCSTR lpName,
    [in] LPCSTR lpGuid,
    [in] PVOID pValue,
    [in] DWORD nSize
);

BOOL GetVolumePathNamesForVolumeNameA(
    [in] LPCSTR lpszVolumeName,
    [out] LPCH lpszVolumePathNames,
    [in] DWORD cchBufferLength,
    [out] PDWORD lpcchReturnLength
);

BOOL GlobalUnlock(
    [in] HGLOBAL hMem
);

BOOL RemoveSecureMemoryCacheCallback(
    [in] PSECURE_MEMORY_CACHE_CALLBACK pfnCallBack
);

BOOL DnsHostnameToComputerNameW(
    [in] LPCWSTR Hostname,
    [out] LPWSTR ComputerName,
    [in, out] LPDWORD nSize
);

BOOL DeregisterEventSource(
    [in, out] HANDLE hEventLog
);

BOOL SetMailslotInfo(
    [in] HANDLE hMailslot,
    [in] DWORD lReadTimeout
);

BOOL SetUmsThreadInformation(
    [in] PUMS_CONTEXT UmsThread,
    [in] UMS_THREAD_INFO_CLASS UmsThreadInfoClass,
    [in] PVOID UmsThreadInformation,
    [in] ULONG UmsThreadInformationLength
);

HANDLE FindFirstStreamTransactedW(
    [in] LPCWSTR lpFileName,
    [in] STREAM_INFO_LEVELS InfoLevel,
    [out] LPVOID lpFindStreamData,
    DWORD dwFlags,
    [in] HANDLE hTransaction
);

BOOL GetCommProperties(
    [in] HANDLE hFile,
    [out] LPCOMMPROP lpCommProp
);

BOOL SetFirmwareEnvironmentVariableW(
    [in] LPCWSTR lpName,
    [in] LPCWSTR lpGuid,
    [in] PVOID pValue,
    [in] DWORD nSize
);

BOOL WaitCommEvent(
    [in] HANDLE hFile,
    [out] LPDWORD lpEvtMask,
    [in] LPOVERLAPPED lpOverlapped
);

void SetThreadpoolCallbackCleanupGroup(
    [in, out] PTP_CALLBACK_ENVIRON pcbe,
    [in] PTP_CLEANUP_GROUP ptpcg,
    [in, optional] PTP_CLEANUP_GROUP_CANCEL_CALLBACK pfng
);

unsigned InterlockedExchangeSubtract(
    [in, out] unsigned volatile *Addend,
    [in] unsigned Value
);

BOOL SetCommBreak(
    [in] HANDLE hFile
);

BOOL SetFileShortNameA(
    [in] HANDLE hFile,
    [in] LPCSTR lpShortName
);

DECLSPEC_ALLOCATOR HLOCAL LocalReAlloc(
    [in] _Frees_ptr_opt_ HLOCAL hMem,
    [in] SIZE_T uBytes,
    [in] UINT uFlags
);

HMODULE LoadPackagedLibrary(
    [in] LPCWSTR lpwLibFileName,
    DWORD Reserved
);

DWORD GetPrivateProfileSectionW(
    [in] LPCWSTR lpAppName,
    [out] LPWSTR lpReturnedString,
    [in] DWORD nSize,
    [in] LPCWSTR lpFileName
);

HRESULT UnregisterApplicationRestart();

PUMS_CONTEXT GetCurrentUmsThread();

BOOL ClearEventLogW(
    [in] HANDLE hEventLog,
    [in] LPCWSTR lpBackupFileName
);

BOOL CopyFileA(
    [in] LPCSTR lpExistingFileName,
    [in] LPCSTR lpNewFileName,
    [in] BOOL bFailIfExists
);

BOOL OperationEnd(
    [in] OPERATION_END_PARAMETERS *OperationEndParams
);

BOOL DeleteFile(
    [in] LPCTSTR lpFileName
);

BOOL LookupPrivilegeDisplayNameA(
    [in, optional] LPCSTR lpSystemName,
    [in] LPCSTR lpName,
    [out, optional] LPSTR lpDisplayName,
    [in, out] LPDWORD cchDisplayName,
    [out] LPDWORD lpLanguageId
);

BOOL AccessCheckByTypeAndAuditAlarmA(
    [in] LPCSTR SubsystemName,
    [in] LPVOID HandleId,
    [in] LPCSTR ObjectTypeName,
    [in, optional] LPCSTR ObjectName,
    [in] PSECURITY_DESCRIPTOR SecurityDescriptor,
    [in, optional] PSID PrincipalSelfSid,
    [in] DWORD DesiredAccess,
    [in] AUDIT_EVENT_TYPE AuditType,
    [in] DWORD Flags,
    [in, out, optional] POBJECT_TYPE_LIST ObjectTypeList,
    [in] DWORD ObjectTypeListLength,
    [in] PGENERIC_MAPPING GenericMapping,
    [in] BOOL ObjectCreation,
    [out] LPDWORD GrantedAccess,
    [out] LPBOOL AccessStatus,
    [out] LPBOOL pfGenerateOnClose
);

BOOL GetNumaProcessorNode(
    [in] UCHAR Processor,
    [out] PUCHAR NodeNumber
);

BOOL GetUserNameW(
    [out] LPWSTR lpBuffer,
    [in, out] LPDWORD pcbBuffer
);

BOOL BackupEventLogA(
    [in] HANDLE hEventLog,
    [in] LPCSTR lpBackupFileName
);

SIZE_T GlobalSize(
    [in] HGLOBAL hMem
);

BOOL FindNextVolumeMountPointW(
    [in] HANDLE hFindVolumeMountPoint,
    [out] LPWSTR lpszVolumeMountPoint,
    [in] DWORD cchBufferLength
);

BOOL CreateUmsThreadContext(
    [out] PUMS_CONTEXT *lpUmsThread
);

BOOL CopyFileExA(
    [in] LPCSTR lpExistingFileName,
    [in] LPCSTR lpNewFileName,
    [in, optional] LPPROGRESS_ROUTINE lpProgressRoutine,
    [in, optional] LPVOID lpData,
    [in, optional] LPBOOL pbCancel,
    [in] DWORD dwCopyFlags
);

