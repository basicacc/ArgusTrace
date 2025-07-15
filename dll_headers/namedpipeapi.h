BOOL GetNamedPipeInfo(
    [in] HANDLE hNamedPipe,
    [out, optional] LPDWORD lpFlags,
    [out, optional] LPDWORD lpOutBufferSize,
    [out, optional] LPDWORD lpInBufferSize,
    [out, optional] LPDWORD lpMaxInstances
);

BOOL GetNamedPipeClientComputerNameW(
    [in] HANDLE Pipe,
    [out] LPWSTR ClientComputerName,
    [in] ULONG ClientComputerNameLength
);

BOOL GetNamedPipeHandleStateW(
    [in] HANDLE hNamedPipe,
    [out, optional] LPDWORD lpState,
    [out, optional] LPDWORD lpCurInstances,
    [out, optional] LPDWORD lpMaxCollectionCount,
    [out, optional] LPDWORD lpCollectDataTimeout,
    [out, optional] LPWSTR lpUserName,
    [in] DWORD nMaxUserNameSize
);

BOOL SetNamedPipeHandleState(
    [in] HANDLE hNamedPipe,
    [in, optional] LPDWORD lpMode,
    [in, optional] LPDWORD lpMaxCollectionCount,
    [in, optional] LPDWORD lpCollectDataTimeout
);

BOOL ImpersonateNamedPipeClient(
    [in] HANDLE hNamedPipe
);

BOOL ConnectNamedPipe(
    [in] HANDLE hNamedPipe,
    [in, out, optional] LPOVERLAPPED lpOverlapped
);

BOOL WaitNamedPipeW(
    [in] LPCWSTR lpNamedPipeName,
    [in] DWORD nTimeOut
);

BOOL PeekNamedPipe(
    [in] HANDLE hNamedPipe,
    [out, optional] LPVOID lpBuffer,
    [in] DWORD nBufferSize,
    [out, optional] LPDWORD lpBytesRead,
    [out, optional] LPDWORD lpTotalBytesAvail,
    [out, optional] LPDWORD lpBytesLeftThisMessage
);

BOOL CallNamedPipeW(
    [in] LPCWSTR lpNamedPipeName,
    [in] LPVOID lpInBuffer,
    [in] DWORD nInBufferSize,
    [out] LPVOID lpOutBuffer,
    [in] DWORD nOutBufferSize,
    [out] LPDWORD lpBytesRead,
    [in] DWORD nTimeOut
);

BOOL DisconnectNamedPipe(
    [in] HANDLE hNamedPipe
);

HANDLE CreateNamedPipeW(
    [in] LPCWSTR lpName,
    [in] DWORD dwOpenMode,
    [in] DWORD dwPipeMode,
    [in] DWORD nMaxInstances,
    [in] DWORD nOutBufferSize,
    [in] DWORD nInBufferSize,
    [in] DWORD nDefaultTimeOut,
    [in, optional] LPSECURITY_ATTRIBUTES lpSecurityAttributes
);

BOOL CreatePipe(
    [out] PHANDLE hReadPipe,
    [out] PHANDLE hWritePipe,
    [in, optional] LPSECURITY_ATTRIBUTES lpPipeAttributes,
    [in] DWORD nSize
);

BOOL TransactNamedPipe(
    [in] HANDLE hNamedPipe,
    [in] LPVOID lpInBuffer,
    [in] DWORD nInBufferSize,
    [out] LPVOID lpOutBuffer,
    [in] DWORD nOutBufferSize,
    [out] LPDWORD lpBytesRead,
    [in, out, optional] LPOVERLAPPED lpOverlapped
);

