DWORD GetCompressedFileSizeA(
    [in] LPCSTR lpFileName,
    [out, optional] LPDWORD lpFileSizeHigh
);

UINT GetDriveTypeA(
    [in, optional] LPCSTR lpRootPathName
);

BOOL FindNextStreamW(
    [in] HANDLE hFindStream,
    [out] LPVOID lpFindStreamData
);

BOOL GetVolumeInformationW(
    [in, optional] LPCWSTR lpRootPathName,
    [out, optional] LPWSTR lpVolumeNameBuffer,
    [in] DWORD nVolumeNameSize,
    [out, optional] LPDWORD lpVolumeSerialNumber,
    [out, optional] LPDWORD lpMaximumComponentLength,
    [out, optional] LPDWORD lpFileSystemFlags,
    [out, optional] LPWSTR lpFileSystemNameBuffer,
    [in] DWORD nFileSystemNameSize
);

BOOL FindNextChangeNotification(
    [in] HANDLE hChangeHandle
);

BOOL DeleteVolumeMountPointW(
    [in] LPCWSTR lpszVolumeMountPoint
);

DWORD GetTempPath2W(
    [in] DWORD BufferLength,
    [out] LPWSTR Buffer
);

DWORD GetFileAttributesW(
    [in] LPCWSTR lpFileName
);

BOOL DeleteFileW(
    [in] LPCWSTR lpFileName
);

BOOL SetFileInformationByHandle(
    [in] HANDLE hFile,
    [in] FILE_INFO_BY_HANDLE_CLASS FileInformationClass,
    [in] LPVOID lpFileInformation,
    [in] DWORD dwBufferSize
);

BOOL ReadFileScatter(
    [in] HANDLE hFile,
    [in] FILE_SEGMENT_ELEMENT [] aSegmentArray,
    [in] DWORD nNumberOfBytesToRead,
    LPDWORD lpReserved,
    [in, out] LPOVERLAPPED lpOverlapped
);

BOOL GetVolumePathNameW(
    [in] LPCWSTR lpszFileName,
    [out] LPWSTR lpszVolumePathName,
    [in] DWORD cchBufferLength
);

BOOL FindNextFileW(
    [in] HANDLE hFindFile,
    [out] LPWIN32_FIND_DATAW lpFindFileData
);

DWORD GetLongPathNameW(
    [in] LPCWSTR lpszShortPath,
    [out] LPWSTR lpszLongPath,
    [in] DWORD cchBuffer
);

BOOL FindVolumeClose(
    [in] HANDLE hFindVolume
);

BOOL GetVolumeInformationA(
    [in, optional] LPCSTR lpRootPathName,
    [out, optional] LPSTR lpVolumeNameBuffer,
    [in] DWORD nVolumeNameSize,
    [out, optional] LPDWORD lpVolumeSerialNumber,
    [out, optional] LPDWORD lpMaximumComponentLength,
    [out, optional] LPDWORD lpFileSystemFlags,
    [out, optional] LPSTR lpFileSystemNameBuffer,
    [in] DWORD nFileSystemNameSize
);

void SetFileApisToOEM();

BOOL GetFileTime(
    [in] HANDLE hFile,
    [out, optional] LPFILETIME lpCreationTime,
    [out, optional] LPFILETIME lpLastAccessTime,
    [out, optional] LPFILETIME lpLastWriteTime
);

BOOL GetFileInformationByHandle(
    [in] HANDLE hFile,
    [out] LPBY_HANDLE_FILE_INFORMATION lpFileInformation
);

BOOL GetFileSizeEx(
    [in] HANDLE hFile,
    [out] PLARGE_INTEGER lpFileSize
);

DWORD GetCompressedFileSizeW(
    [in] LPCWSTR lpFileName,
    [out, optional] LPDWORD lpFileSizeHigh
);

BOOL SetFileTime(
    [in] HANDLE hFile,
    [in, optional] const FILETIME *lpCreationTime,
    [in, optional] const FILETIME *lpLastAccessTime,
    [in, optional] const FILETIME *lpLastWriteTime
);

BOOL GetFileAttributesExA(
    [in] LPCSTR lpFileName,
    [in] GET_FILEEX_INFO_LEVELS fInfoLevelId,
    [out] LPVOID lpFileInformation
);

BOOL GetDiskFreeSpaceA(
    [in] LPCSTR lpRootPathName,
    [out] LPDWORD lpSectorsPerCluster,
    [out] LPDWORD lpBytesPerSector,
    [out] LPDWORD lpNumberOfFreeClusters,
    [out] LPDWORD lpTotalNumberOfClusters
);

HANDLE FindFirstFileExA(
    [in] LPCSTR lpFileName,
    [in] FINDEX_INFO_LEVELS fInfoLevelId,
    [out] LPVOID lpFindFileData,
    [in] FINDEX_SEARCH_OPS fSearchOp,
    LPVOID lpSearchFilter,
    [in] DWORD dwAdditionalFlags
);

DWORD GetFinalPathNameByHandleA(
    [in] HANDLE hFile,
    [out] LPSTR lpszFilePath,
    [in] DWORD cchFilePath,
    [in] DWORD dwFlags
);

BOOL DefineDosDeviceW(
    [in] DWORD dwFlags,
    [in] LPCWSTR lpDeviceName,
    [in, optional] LPCWSTR lpTargetPath
);

DWORD GetFileAttributesA(
    [in] LPCSTR lpFileName
);

BOOL DeleteFile2A(
    LPCSTR lpFileName,
    DWORD Flags
);

HANDLE CreateFile2(
    [in] LPCWSTR lpFileName,
    [in] DWORD dwDesiredAccess,
    [in] DWORD dwShareMode,
    [in] DWORD dwCreationDisposition,
    [in, optional] LPCREATEFILE2_EXTENDED_PARAMETERS pCreateExParams
);

DWORD GetLogicalDrives();

BOOL RemoveDirectoryA(
    [in] LPCSTR lpPathName
);

BOOL LockFile(
    [in] HANDLE hFile,
    [in] DWORD dwFileOffsetLow,
    [in] DWORD dwFileOffsetHigh,
    [in] DWORD nNumberOfBytesToLockLow,
    [in] DWORD nNumberOfBytesToLockHigh
);

BOOL AreShortNamesEnabled(
    HANDLE Handle,
    BOOL *Enabled
);

BOOL UnlockFile(
    [in] HANDLE hFile,
    [in] DWORD dwFileOffsetLow,
    [in] DWORD dwFileOffsetHigh,
    [in] DWORD nNumberOfBytesToUnlockLow,
    [in] DWORD nNumberOfBytesToUnlockHigh
);

HANDLE FindFirstFileExW(
    [in] LPCWSTR lpFileName,
    [in] FINDEX_INFO_LEVELS fInfoLevelId,
    [out] LPVOID lpFindFileData,
    [in] FINDEX_SEARCH_OPS fSearchOp,
    LPVOID lpSearchFilter,
    [in] DWORD dwAdditionalFlags
);

BOOL AreFileApisANSI();

BOOL GetVolumeInformationByHandleW(
    [in] HANDLE hFile,
    [out, optional] LPWSTR lpVolumeNameBuffer,
    [in] DWORD nVolumeNameSize,
    [out, optional] LPDWORD lpVolumeSerialNumber,
    [out, optional] LPDWORD lpMaximumComponentLength,
    [out, optional] LPDWORD lpFileSystemFlags,
    [out, optional] LPWSTR lpFileSystemNameBuffer,
    [in] DWORD nFileSystemNameSize
);

HANDLE FindFirstChangeNotificationW(
    [in] LPCWSTR lpPathName,
    [in] BOOL bWatchSubtree,
    [in] DWORD dwNotifyFilter
);

BOOL SetFileValidData(
    [in] HANDLE hFile,
    [in] LONGLONG ValidDataLength
);

HANDLE CreateFile3(
    LPCWSTR lpFileName,
    DWORD dwDesiredAccess,
    DWORD dwShareMode,
    DWORD dwCreationDisposition,
    LPCREATEFILE3_EXTENDED_PARAMETERS pCreateExParams
);

DWORD GetFileType(
    [in] HANDLE hFile
);

BOOL FindCloseChangeNotification(
    [in] HANDLE hChangeHandle
);

BOOL DeleteFile2W(
    LPCWSTR lpFileName,
    DWORD Flags
);

BOOL SetEndOfFile(
    [in] HANDLE hFile
);

DWORD GetTempPath2A(
    [in] DWORD BufferLength,
    [out] LPSTR Buffer
);

BOOL WriteFile(
    [in] HANDLE hFile,
    [in] LPCVOID lpBuffer,
    [in] DWORD nNumberOfBytesToWrite,
    [out, optional] LPDWORD lpNumberOfBytesWritten,
    [in, out, optional] LPOVERLAPPED lpOverlapped
);

BOOL CreateDirectoryW(
    [in] LPCWSTR lpPathName,
    [in, optional] LPSECURITY_ATTRIBUTES lpSecurityAttributes
);

BOOL SetFilePointerEx(
    [in] HANDLE hFile,
    [in] LARGE_INTEGER liDistanceToMove,
    [out, optional] PLARGE_INTEGER lpNewFilePointer,
    [in] DWORD dwMoveMethod
);

BOOL WriteFileGather(
    [in] HANDLE hFile,
    [in] FILE_SEGMENT_ELEMENT [] aSegmentArray,
    [in] DWORD nNumberOfBytesToWrite,
    LPDWORD lpReserved,
    [in, out] LPOVERLAPPED lpOverlapped
);

DWORD GetTempPathW(
    [in] DWORD nBufferLength,
    [out] LPWSTR lpBuffer
);

BOOL SetFileAttributesA(
    [in] LPCSTR lpFileName,
    [in] DWORD dwFileAttributes
);

HANDLE CreateDirectory2A(
    LPCSTR lpPathName,
    DWORD dwDesiredAccess,
    DWORD dwShareMode,
    DIRECTORY_FLAGS DirectoryFlags,
    LPSECURITY_ATTRIBUTES lpSecurityAttributes
);

BOOL CreateDirectoryA(
    [in] LPCSTR lpPathName,
    [in, optional] LPSECURITY_ATTRIBUTES lpSecurityAttributes
);

HANDLE FindFirstFileNameW(
    [in] LPCWSTR lpFileName,
    [in] DWORD dwFlags,
    [in, out] LPDWORD StringLength,
    [in, out] PWSTR LinkName
);

DWORD GetFinalPathNameByHandleW(
    [in] HANDLE hFile,
    [out] LPWSTR lpszFilePath,
    [in] DWORD cchFilePath,
    [in] DWORD dwFlags
);

UINT GetTempFileNameW(
    [in] LPCWSTR lpPathName,
    [in] LPCWSTR lpPrefixString,
    [in] UINT uUnique,
    [out] LPWSTR lpTempFileName
);

DWORD GetLogicalDriveStringsW(
    [in] DWORD nBufferLength,
    [out] LPWSTR lpBuffer
);

HRESULT GetDiskSpaceInformationW(
    LPCWSTR rootPath,
    DISK_SPACE_INFORMATION *diskSpaceInfo
);

HANDLE FindFirstFileA(
    [in] LPCSTR lpFileName,
    [out] LPWIN32_FIND_DATAA lpFindFileData
);

BOOL UnlockFileEx(
    [in] HANDLE hFile,
    DWORD dwReserved,
    [in] DWORD nNumberOfBytesToUnlockLow,
    [in] DWORD nNumberOfBytesToUnlockHigh,
    [in, out] LPOVERLAPPED lpOverlapped
);

BOOL SetFileAttributesW(
    [in] LPCWSTR lpFileName,
    [in] DWORD dwFileAttributes
);

BOOL GetDiskFreeSpaceExA(
    [in, optional] LPCSTR lpDirectoryName,
    [out, optional] PULARGE_INTEGER lpFreeBytesAvailableToCaller,
    [out, optional] PULARGE_INTEGER lpTotalNumberOfBytes,
    [out, optional] PULARGE_INTEGER lpTotalNumberOfFreeBytes
);

BOOL WriteFileEx(
    [in] HANDLE hFile,
    [in, optional] LPCVOID lpBuffer,
    [in] DWORD nNumberOfBytesToWrite,
    [in, out] LPOVERLAPPED lpOverlapped,
    [in] LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine
);

HANDLE FindFirstFileW(
    [in] LPCWSTR lpFileName,
    [out] LPWIN32_FIND_DATAW lpFindFileData
);

DWORD QueryDosDeviceW(
    [in, optional] LPCWSTR lpDeviceName,
    [out] LPWSTR lpTargetPath,
    [in] DWORD ucchMax
);

BOOL ReadFileEx(
    [in] HANDLE hFile,
    [out, optional] LPVOID lpBuffer,
    [in] DWORD nNumberOfBytesToRead,
    [in, out] LPOVERLAPPED lpOverlapped,
    [in] LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine
);

HRESULT GetDiskSpaceInformationA(
    LPCSTR rootPath,
    DISK_SPACE_INFORMATION *diskSpaceInfo
);

BOOL RemoveDirectory2W(
    LPCWSTR lpPathName,
    DIRECTORY_FLAGS DirectoryFlags
);

UINT GetTempFileNameA(
    [in] LPCSTR lpPathName,
    [in] LPCSTR lpPrefixString,
    [in] UINT uUnique,
    [out] LPSTR lpTempFileName
);

BOOL RemoveDirectory2A(
    LPCSTR lpPathName,
    DIRECTORY_FLAGS DirectoryFlags
);

BOOL DeleteFileA(
    [in] LPCSTR lpFileName
);

BOOL RemoveDirectoryW(
    [in] LPCWSTR lpPathName
);

HANDLE FindFirstChangeNotificationA(
    [in] LPCSTR lpPathName,
    [in] BOOL bWatchSubtree,
    [in] DWORD dwNotifyFilter
);

HANDLE CreateFileW(
    [in] LPCWSTR lpFileName,
    [in] DWORD dwDesiredAccess,
    [in] DWORD dwShareMode,
    [in, optional] LPSECURITY_ATTRIBUTES lpSecurityAttributes,
    [in] DWORD dwCreationDisposition,
    [in] DWORD dwFlagsAndAttributes,
    [in, optional] HANDLE hTemplateFile
);

BOOL GetFileAttributesExW(
    [in] LPCWSTR lpFileName,
    [in] GET_FILEEX_INFO_LEVELS fInfoLevelId,
    [out] LPVOID lpFileInformation
);

BOOL FindClose(
    [in, out] HANDLE hFindFile
);

BOOL SetFileIoOverlappedRange(
    [in] HANDLE FileHandle,
    [in] PUCHAR OverlappedRangeStart,
    [in] ULONG Length
);

HANDLE CreateDirectory2W(
    LPCWSTR lpPathName,
    DWORD dwDesiredAccess,
    DWORD dwShareMode,
    DIRECTORY_FLAGS DirectoryFlags,
    LPSECURITY_ATTRIBUTES lpSecurityAttributes
);

DWORD GetFileSize(
    [in] HANDLE hFile,
    [out, optional] LPDWORD lpFileSizeHigh
);

BOOL FindNextVolumeW(
    [in] HANDLE hFindVolume,
    [out] LPWSTR lpszVolumeName,
    [in] DWORD cchBufferLength
);

HANDLE FindFirstVolumeW(
    [out] LPWSTR lpszVolumeName,
    [in] DWORD cchBufferLength
);

BOOL ReadFile(
    [in] HANDLE hFile,
    [out] LPVOID lpBuffer,
    [in] DWORD nNumberOfBytesToRead,
    [out, optional] LPDWORD lpNumberOfBytesRead,
    [in, out, optional] LPOVERLAPPED lpOverlapped
);

BOOL GetVolumePathNamesForVolumeNameW(
    [in] LPCWSTR lpszVolumeName,
    [out] LPWCH lpszVolumePathNames,
    [in] DWORD cchBufferLength,
    [out] PDWORD lpcchReturnLength
);

DWORD SetFilePointer(
    [in] HANDLE hFile,
    [in] LONG lDistanceToMove,
    [in, out, optional] PLONG lpDistanceToMoveHigh,
    [in] DWORD dwMoveMethod
);

DWORD GetFullPathNameW(
    [in] LPCWSTR lpFileName,
    [in] DWORD nBufferLength,
    [out] LPWSTR lpBuffer,
    [out] LPWSTR *lpFilePart
);

DWORD GetShortPathNameW(
    [in] LPCWSTR lpszLongPath,
    [out] LPWSTR lpszShortPath,
    [in] DWORD cchBuffer
);

BOOL FindNextFileA(
    [in] HANDLE hFindFile,
    [out] LPWIN32_FIND_DATAA lpFindFileData
);

BOOL FindNextFileNameW(
    [in] HANDLE hFindStream,
    [in, out] LPDWORD StringLength,
    [in, out] PWSTR LinkName
);

BOOL LocalFileTimeToFileTime(
    [in] const FILETIME *lpLocalFileTime,
    [out] LPFILETIME lpFileTime
);

HANDLE CreateFileA(
    [in] LPCSTR lpFileName,
    [in] DWORD dwDesiredAccess,
    [in] DWORD dwShareMode,
    [in, optional] LPSECURITY_ATTRIBUTES lpSecurityAttributes,
    [in] DWORD dwCreationDisposition,
    [in] DWORD dwFlagsAndAttributes,
    [in, optional] HANDLE hTemplateFile
);

BOOL GetDiskFreeSpaceExW(
    [in, optional] LPCWSTR lpDirectoryName,
    [out, optional] PULARGE_INTEGER lpFreeBytesAvailableToCaller,
    [out, optional] PULARGE_INTEGER lpTotalNumberOfBytes,
    [out, optional] PULARGE_INTEGER lpTotalNumberOfFreeBytes
);

DWORD GetFullPathNameA(
    [in] LPCSTR lpFileName,
    [in] DWORD nBufferLength,
    [out] LPSTR lpBuffer,
    [out] LPSTR *lpFilePart
);

void SetFileApisToANSI();

BOOL GetDiskFreeSpaceW(
    [in] LPCWSTR lpRootPathName,
    [out] LPDWORD lpSectorsPerCluster,
    [out] LPDWORD lpBytesPerSector,
    [out] LPDWORD lpNumberOfFreeClusters,
    [out] LPDWORD lpTotalNumberOfClusters
);

DWORD GetTempPathA(
    [in] DWORD nBufferLength,
    [out] LPSTR lpBuffer
);

BOOL FileTimeToLocalFileTime(
    [in] const FILETIME *lpFileTime,
    [out] LPFILETIME lpLocalFileTime
);

UINT GetDriveTypeW(
    [in, optional] LPCWSTR lpRootPathName
);

DWORD GetLongPathNameA(
    [in] LPCSTR lpszShortPath,
    [out] LPSTR lpszLongPath,
    [in] DWORD cchBuffer
);

LONG CompareFileTime(
    [in] const FILETIME *lpFileTime1,
    [in] const FILETIME *lpFileTime2
);

BOOL GetVolumeNameForVolumeMountPointW(
    [in] LPCWSTR lpszVolumeMountPoint,
    [out] LPWSTR lpszVolumeName,
    [in] DWORD cchBufferLength
);

BOOL FlushFileBuffers(
    [in] HANDLE hFile
);

BOOL LockFileEx(
    [in] HANDLE hFile,
    [in] DWORD dwFlags,
    DWORD dwReserved,
    [in] DWORD nNumberOfBytesToLockLow,
    [in] DWORD nNumberOfBytesToLockHigh,
    [in, out] LPOVERLAPPED lpOverlapped
);

HANDLE FindFirstStreamW(
    [in] LPCWSTR lpFileName,
    [in] STREAM_INFO_LEVELS InfoLevel,
    [out] LPVOID lpFindStreamData,
    DWORD dwFlags
);

