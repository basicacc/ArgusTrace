BOOL ClipCursor(
    [in, optional] const RECT *lpRect
);

BOOL GetInputState();

BOOL PostThreadMessageW(
    [in] DWORD idThread,
    [in] UINT Msg,
    [in] WPARAM wParam,
    [in] LPARAM lParam
);

int GetKeyNameTextW(
    [in] LONG lParam,
    [out] LPWSTR lpString,
    [in] int cchSize
);

BOOL GetGestureConfig(
    [in] HWND hwnd,
    [in] DWORD dwReserved,
    [in] DWORD dwFlags,
    [in] PUINT pcIDs,
    [in, out] PGESTURECONFIG pGestureConfig,
    [in] UINT cbSize
);

HWND GetCapture();

BOOL GetMenuBarInfo(
    [in] HWND hwnd,
    [in] LONG idObject,
    [in] LONG idItem,
    [in, out] PMENUBARINFO pmbi
);

BOOL GetCIMSSM(
    [out] INPUT_MESSAGE_SOURCE *inputMessageSource
);

BOOL CheckDlgButton(
    [in] HWND hDlg,
    [in] int nIDButton,
    [in] UINT uCheck
);

BOOL GetPointerFramePenInfoHistory(
    [in] UINT32 pointerId,
    [in, out] UINT32 *entriesCount,
    [in, out] UINT32 *pointerCount,
    [out, optional] POINTER_PEN_INFO *penInfo
);

LRESULT SendDlgItemMessageW(
    [in] HWND hDlg,
    [in] int nIDDlgItem,
    [in] UINT Msg,
    [in] WPARAM wParam,
    [in] LPARAM lParam
);

void IS_POINTER_INRANGE_WPARAM(
    wParam
);

BOOL IsImmersiveProcess(
    [in] HANDLE hProcess
);

HWND CreateWindowExA(
    [in] DWORD dwExStyle,
    [in, optional] LPCSTR lpClassName,
    [in, optional] LPCSTR lpWindowName,
    [in] DWORD dwStyle,
    [in] int X,
    [in] int Y,
    [in] int nWidth,
    [in] int nHeight,
    [in, optional] HWND hWndParent,
    [in, optional] HMENU hMenu,
    [in, optional] HINSTANCE hInstance,
    [in, optional] LPVOID lpParam
);

BOOL GetLastInputInfo(
    [out] PLASTINPUTINFO plii
);

BOOL EnumDisplaySettingsW(
    [in] LPCWSTR lpszDeviceName,
    [in] DWORD iModeNum,
    [out] DEVMODEW *lpDevMode
);

HICON CreateIconFromResourceEx(
    [in] PBYTE presbits,
    [in] DWORD dwResSize,
    [in] BOOL fIcon,
    [in] DWORD dwVer,
    [in] int cxDesired,
    [in] int cyDesired,
    [in] UINT Flags
);

BOOL CallMsgFilterW(
    [in] LPMSG lpMsg,
    [in] int nCode
);

BOOL GetPointerDeviceCursors(
    [in] HANDLE device,
    [in, out] UINT32 *cursorCount,
    [out, optional] POINTER_DEVICE_CURSOR_INFO *deviceCursors
);

void CreateDialogA(
    [in, optional] hInstance,
    [in] lpName,
    [in, optional] hWndParent,
    [in, optional] lpDialogFunc
);

BOOL CharToOemBuffW(
    [in] LPCWSTR lpszSrc,
    [out] LPSTR lpszDst,
    [in] DWORD cchDstLength
);

HSYNTHETICPOINTERDEVICE CreateSyntheticPointerDevice(
    [in] POINTER_INPUT_TYPE pointerType,
    [in] ULONG maxCount,
    [in] POINTER_FEEDBACK_MODE mode
);

UINT GetRawInputDeviceInfoW(
    [in, optional] HANDLE hDevice,
    [in] UINT uiCommand,
    [in, out, optional] LPVOID pData,
    [in, out] PUINT pcbSize
);

BOOL SetPropW(
    [in] HWND hWnd,
    [in] LPCWSTR lpString,
    [in, optional] HANDLE hData
);

HCURSOR GetCursor();

UINT GetDpiForWindow(
    [in] HWND hwnd
);

BOOL EnumDesktopsW(
    [in, optional] HWINSTA hwinsta,
    [in] DESKTOPENUMPROCW lpEnumFunc,
    [in] LPARAM lParam
);

void MAKELPARAM(
    l,
    h
);

HWND CreateDialogIndirectParamA(
    [in, optional] HINSTANCE hInstance,
    [in] LPCDLGTEMPLATEA lpTemplate,
    [in, optional] HWND hWndParent,
    [in, optional] DLGPROC lpDialogFunc,
    [in] LPARAM dwInitParam
);

BOOL DestroyCaret();

BOOL AdjustWindowRectEx(
    [in, out] LPRECT lpRect,
    [in] DWORD dwStyle,
    [in] BOOL bMenu,
    [in] DWORD dwExStyle
);

int MessageBoxExA(
    [in, optional] HWND hWnd,
    [in, optional] LPCSTR lpText,
    [in, optional] LPCSTR lpCaption,
    [in] UINT uType,
    [in] WORD wLanguageId
);

void MAKELRESULT(
    l,
    h
);

LRESULT DefWindowProcW(
    [in] HWND hWnd,
    [in] UINT Msg,
    [in] WPARAM wParam,
    [in] LPARAM lParam
);

BOOL IsCharAlphaW(
    [in] WCHAR ch
);

BOOL SetWindowPlacement(
    [in] HWND hWnd,
    [in] const WINDOWPLACEMENT *lpwndpl
);

BOOL AppendMenuA(
    [in] HMENU hMenu,
    [in] UINT uFlags,
    [in] UINT_PTR uIDNewItem,
    [in, optional] LPCSTR lpNewItem
);

int LookupIconIdFromDirectoryEx(
    [in] PBYTE presbits,
    [in] BOOL fIcon,
    [in] int cxDesired,
    [in] int cyDesired,
    [in] UINT Flags
);

BOOL IsWindowArranged(
    HWND hwnd
);

BOOL SendNotifyMessageW(
    [in] HWND hWnd,
    [in] UINT Msg,
    [in] WPARAM wParam,
    [in] LPARAM lParam
);

ATOM RegisterClassExW(
    [in] const WNDCLASSEXW *unnamedParam1
);

UINT GetKBCodePage();

int MessageBoxW(
    [in, optional] HWND hWnd,
    [in, optional] LPCWSTR lpText,
    [in, optional] LPCWSTR lpCaption,
    [in] UINT uType
);

int MessageBoxA(
    [in, optional] HWND hWnd,
    [in, optional] LPCSTR lpText,
    [in, optional] LPCSTR lpCaption,
    [in] UINT uType
);

BOOL LockWorkStation();

void GID_ROTATE_ANGLE_TO_ARGUMENT(
    _arg_
);

HANDLE GetPropW(
    [in] HWND hWnd,
    [in] LPCWSTR lpString
);

BOOL ShowOwnedPopups(
    [in] HWND hWnd,
    [in] BOOL fShow
);

void GET_APPCOMMAND_LPARAM(
    lParam
);

BOOL DeregisterShellHookWindow(
    [in] HWND hwnd
);

LPSTR CharLowerA(
    [in, out] LPSTR lpsz
);

SHORT VkKeyScanW(
    [in] WCHAR ch
);

BOOL EnumWindowStationsW(
    [in] WINSTAENUMPROCW lpEnumFunc,
    [in] LPARAM lParam
);

BOOL IntersectRect(
    [out] LPRECT lprcDst,
    [in] const RECT *lprcSrc1,
    [in] const RECT *lprcSrc2
);

WORD TileWindows(
    [in, optional] HWND hwndParent,
    [in] UINT wHow,
    [in, optional] const RECT *lpRect,
    [in] UINT cKids,
    [in, optional] const HWND *lpKids
);

UINT RealGetWindowClassW(
    [in] HWND hwnd,
    [out] LPWSTR ptszClassName,
    [in] UINT cchClassNameMax
);

DWORD GetClipboardSequenceNumber();

BOOL ShutdownBlockReasonDestroy(
    [in] HWND hWnd
);

LPWSTR CharNextW(
    [in] LPCWSTR lpsz
);

int ToAsciiEx(
    [in] UINT uVirtKey,
    [in] UINT uScanCode,
    [in, optional] const BYTE *lpKeyState,
    [out] LPWORD lpChar,
    [in] UINT uFlags,
    [in, optional] HKL dwhkl
);

BOOL DlgDirSelectExW(
    [in] HWND hwndDlg,
    [out] LPWSTR lpString,
    [in] int chCount,
    [in] int idListBox
);

BOOL SetGestureConfig(
    [in] HWND hwnd,
    [in] DWORD dwReserved,
    [in] UINT cIDs,
    [in] PGESTURECONFIG pGestureConfig,
    [in] UINT cbSize
);

void POINTTOPOINTS(
    pt
);

int DrawTextExA(
    [in] HDC hdc,
    [in, out] LPSTR lpchText,
    [in] int cchText,
    [in, out] LPRECT lprc,
    [in] UINT format,
    [in] LPDRAWTEXTPARAMS lpdtp
);

LONG ChangeDisplaySettingsW(
    [in] DEVMODEW *lpDevMode,
    [in] DWORD dwFlags
);

BOOL EndTask(
    [in] HWND hWnd,
    [in] BOOL fShutDown,
    [in] BOOL fForce
);

HPOWERNOTIFY RegisterSuspendResumeNotification(
    [in] HANDLE hRecipient,
    [in] DWORD Flags
);

BOOL PeekMessageA(
    [out] LPMSG lpMsg,
    [in, optional] HWND hWnd,
    [in] UINT wMsgFilterMin,
    [in] UINT wMsgFilterMax,
    [in] UINT wRemoveMsg
);

HDESK CreateDesktopExW(
    [in] LPCWSTR lpszDesktop,
    LPCWSTR lpszDevice,
    DEVMODEW *pDevmode,
    [in] DWORD dwFlags,
    [in] ACCESS_MASK dwDesiredAccess,
    [in, optional] LPSECURITY_ATTRIBUTES lpsa,
    [in] ULONG ulHeapSize,
    PVOID pvoid
);

BOOL EnumDesktopsA(
    [in, optional] HWINSTA hwinsta,
    [in] DESKTOPENUMPROCA lpEnumFunc,
    [in] LPARAM lParam
);

DWORD GetClassLongA(
    [in] HWND hWnd,
    [in] int nIndex
);

UINT GetWindowModuleFileNameW(
    [in] HWND hwnd,
    [out] LPWSTR pszFileName,
    [in] UINT cchFileNameMax
);

long BroadcastSystemMessageExW(
    [in] DWORD flags,
    [in, out, optional] LPDWORD lpInfo,
    [in] UINT Msg,
    [in] WPARAM wParam,
    [in] LPARAM lParam,
    [out, optional] PBSMINFO pbsmInfo
);

BOOL CopyRect(
    [out] LPRECT lprcDst,
    [in] const RECT *lprcSrc
);

HWND GetDlgItem(
    [in, optional] HWND hDlg,
    [in] int nIDDlgItem
);

BOOL DeleteMenu(
    [in] HMENU hMenu,
    [in] UINT uPosition,
    [in] UINT uFlags
);

BOOL DlgDirSelectComboBoxExW(
    [in] HWND hwndDlg,
    [out] LPWSTR lpString,
    [in] int cchOut,
    [in] int idComboBox
);

BOOL ReplyMessage(
    [in] LRESULT lResult
);

BOOL SetWindowContextHelpId(
    HWND unnamedParam1,
    DWORD unnamedParam2
);

BOOL GetUpdateRect(
    [in] HWND hWnd,
    [out] LPRECT lpRect,
    [in] BOOL bErase
);

int WINAPIV wsprintfW(
    [out] LPWSTR unnamedParam1,
    [in] LPCWSTR unnamedParam2,
    ...
);

UINT MapVirtualKeyExA(
    [in] UINT uCode,
    [in] UINT uMapType,
    [in, out, optional] HKL dwhkl
);

int GetClipboardFormatNameW(
    [in] UINT format,
    [out] LPWSTR lpszFormatName,
    [in] int cchMaxCount
);

BOOL OpenClipboard(
    [in, optional] HWND hWndNewOwner
);

void GET_WHEEL_DELTA_WPARAM(
    wParam
);

UINT RegisterWindowMessageW(
    [in] LPCWSTR lpString
);

BOOL IsZoomed(
    [in] HWND hWnd
);

BOOL PostThreadMessageA(
    [in] DWORD idThread,
    [in] UINT Msg,
    [in] WPARAM wParam,
    [in] LPARAM lParam
);

HDESK CreateDesktopW(
    [in] LPCWSTR lpszDesktop,
    LPCWSTR lpszDevice,
    DEVMODEW *pDevmode,
    [in] DWORD dwFlags,
    [in] ACCESS_MASK dwDesiredAccess,
    [in, optional] LPSECURITY_ATTRIBUTES lpsa
);

HWND CreateDialogIndirectParamW(
    [in, optional] HINSTANCE hInstance,
    [in] LPCDLGTEMPLATEW lpTemplate,
    [in, optional] HWND hWndParent,
    [in, optional] DLGPROC lpDialogFunc,
    [in] LPARAM dwInitParam
);

BOOL GetScrollRange(
    [in] HWND hWnd,
    [in] int nBar,
    [out] LPINT lpMinPos,
    [out] LPINT lpMaxPos
);

HDESK OpenDesktopW(
    [in] LPCWSTR lpszDesktop,
    [in] DWORD dwFlags,
    [in] BOOL fInherit,
    [in] ACCESS_MASK dwDesiredAccess
);

BOOL CharToOemBuffA(
    [in] LPCSTR lpszSrc,
    [out] LPSTR lpszDst,
    [in] DWORD cchDstLength
);

BOOL AttachThreadInput(
    [in] DWORD idAttach,
    [in] DWORD idAttachTo,
    [in] BOOL fAttach
);

int CopyAcceleratorTableA(
    [in] HACCEL hAccelSrc,
    [out, optional] LPACCEL lpAccelDst,
    [in] int cAccelEntries
);

void IS_POINTER_SECONDBUTTON_WPARAM(
    wParam
);

BOOL GetCursorPos(
    [out] LPPOINT lpPoint
);

BOOL SwitchDesktop(
    [in] HDESK hDesktop
);

UINT GetDpiForSystem();

HWND GetParent(
    [in] HWND hWnd
);

void NEXTRAWINPUTBLOCK(
    ptr
);

LPSTR CharNextExA(
    [in] WORD CodePage,
    [in] LPCSTR lpCurrentChar,
    [in] DWORD dwFlags
);

BOOL GetPointerDeviceRects(
    [in] HANDLE device,
    [out] RECT *pointerDeviceRect,
    [out] RECT *displayRect
);

int LoadStringW(
    [in, optional] HINSTANCE hInstance,
    [in] UINT uID,
    [out] LPWSTR lpBuffer,
    [in] int cchBufferMax
);

BOOL SetAdditionalForegroundBoostProcesses(
    HWND topLevelWindow,
    DWORD processHandleCount,
    HANDLE *processHandleArray
);

int GetUpdateRgn(
    [in] HWND hWnd,
    [in] HRGN hRgn,
    [in] BOOL bErase
);

LONG DisplayConfigGetDeviceInfo(
    [in, out] DISPLAYCONFIG_DEVICE_INFO_HEADER *requestPacket
);

BOOL DrawStateW(
    [in] HDC hdc,
    [in] HBRUSH hbrFore,
    [in] DRAWSTATEPROC qfnCallBack,
    [in] LPARAM lData,
    [in] WPARAM wData,
    [in] int x,
    [in] int y,
    [in] int cx,
    [in] int cy,
    [in] UINT uFlags
);

BOOL SetMenuItemInfoW(
    [in] HMENU hmenu,
    [in] UINT item,
    BOOL fByPositon,
    [in] LPCMENUITEMINFOW lpmii
);

BOOL CheckRadioButton(
    [in] HWND hDlg,
    [in] int nIDFirstButton,
    [in] int nIDLastButton,
    [in] int nIDCheckButton
);

BOOL SetWindowDisplayAffinity(
    [in] HWND hWnd,
    [in] DWORD dwAffinity
);

BOOL WinHelpA(
    HWND hWndMain,
    LPCSTR lpszHelp,
    UINT uCommand,
    ULONG_PTR dwData
);

BOOL GetPointerCursorId(
    [in] UINT32 pointerId,
    [out] UINT32 *cursorId
);

BOOL InvalidateRgn(
    [in] HWND hWnd,
    [in] HRGN hRgn,
    [in] BOOL bErase
);

int MessageBox(
    [in, optional] HWND hWnd,
    [in, optional] LPCTSTR lpText,
    [in, optional] LPCTSTR lpCaption,
    [in] UINT uType
);

BOOL RedrawWindow(
    [in] HWND hWnd,
    [in] const RECT *lprcUpdate,
    [in] HRGN hrgnUpdate,
    [in] UINT flags
);

HWND GetLastActivePopup(
    [in] HWND hWnd
);

HWND SetFocus(
    [in, optional] HWND hWnd
);

BOOL GetPointerTouchInfo(
    [in] UINT32 pointerId,
    [out] POINTER_TOUCH_INFO *touchInfo
);

BOOL IsWindowUnicode(
    [in] HWND hWnd
);

LONG_PTR SetWindowLongPtrA(
    [in] HWND hWnd,
    [in] int nIndex,
    [in] LONG_PTR dwNewLong
);

HDC GetWindowDC(
    [in] HWND hWnd
);

BOOL ChangeClipboardChain(
    [in] HWND hWndRemove,
    [in] HWND hWndNewNext
);

void DisableProcessWindowsGhosting();

BOOL AddClipboardFormatListener(
    [in] HWND hwnd
);

UINT RealGetWindowClassA(
    [in] HWND hwnd,
    [out] LPSTR ptszClassName,
    [in] UINT cchClassNameMax
);

BOOL GetClassInfoA(
    [in, optional] HINSTANCE hInstance,
    [in] LPCSTR lpClassName,
    [out] LPWNDCLASSA lpWndClass
);

HMENU LoadMenuW(
    [in, optional] HINSTANCE hInstance,
    [in] LPCWSTR lpMenuName
);

LONG SetWindowLongA(
    [in] HWND hWnd,
    [in] int nIndex,
    [in] LONG dwNewLong
);

int wvsprintfW(
    [out] LPWSTR unnamedParam1,
    [in] LPCWSTR unnamedParam2,
    [in] va_list arglist
);

void GID_ROTATE_ANGLE_FROM_ARGUMENT(
    _arg_
);

DIALOG_DPI_CHANGE_BEHAVIORS GetDialogDpiChangeBehavior(
    HWND hDlg
);

BOOL RegisterShellHookWindow(
    [in] HWND hwnd
);

LONG TabbedTextOutW(
    [in] HDC hdc,
    [in] int x,
    [in] int y,
    [in] LPCWSTR lpString,
    [in] int chCount,
    [in] int nTabPositions,
    [in] const INT *lpnTabStopPositions,
    [in] int nTabOrigin
);

BOOL GetPointerFrameTouchInfo(
    [in] UINT32 pointerId,
    [in, out] UINT32 *pointerCount,
    [out] POINTER_TOUCH_INFO *touchInfo
);

BOOL DestroyAcceleratorTable(
    [in] HACCEL hAccel
);

void NotifyWinEvent(
    [in] DWORD event,
    [in] HWND hwnd,
    [in] LONG idObject,
    [in] LONG idChild
);

LONG TabbedTextOutA(
    [in] HDC hdc,
    [in] int x,
    [in] int y,
    [in] LPCSTR lpString,
    [in] int chCount,
    [in] int nTabPositions,
    [in] const INT *lpnTabStopPositions,
    [in] int nTabOrigin
);

BOOL GetPointerTouchInfoHistory(
    [in] UINT32 pointerId,
    [in, out] UINT32 *entriesCount,
    [out, optional] POINTER_TOUCH_INFO *touchInfo
);

int ToAscii(
    [in] UINT uVirtKey,
    [in] UINT uScanCode,
    [in, optional] const BYTE *lpKeyState,
    [out] LPWORD lpChar,
    [in] UINT uFlags
);

void CreateDialogIndirectA(
    [in, optional] hInstance,
    [in] lpTemplate,
    [in, optional] hWndParent,
    [in, optional] lpDialogFunc
);

BOOL GetClassInfoExA(
    [in, optional] HINSTANCE hInstance,
    [in] LPCSTR lpszClass,
    [out] LPWNDCLASSEXA lpwcx
);

BOOL SetWindowPos(
    [in] HWND hWnd,
    [in, optional] HWND hWndInsertAfter,
    [in] int X,
    [in] int Y,
    [in] int cx,
    [in] int cy,
    [in] UINT uFlags
);

HWND GetActiveWindow();

BOOL GetPointerDevice(
    [in] HANDLE device,
    [out] POINTER_DEVICE_INFO *pointerDevice
);

int MessageBoxIndirectA(
    [in] const MSGBOXPARAMSA *lpmbp
);

ULONG_PTR SetClassLongPtrW(
    [in] HWND hWnd,
    [in] int nIndex,
    [in] LONG_PTR dwNewLong
);

int GetSystemMetrics(
    [in] int nIndex
);

BOOL GetWindowFeedbackSetting(
    [in] HWND hwnd,
    [in] FEEDBACK_TYPE feedback,
    [in] DWORD dwFlags,
    [in, out] UINT32 *pSize,
    [out, optional] VOID *config
);

BOOL GetClipCursor(
    [out] LPRECT lpRect
);

LRESULT LRESULT DefDlgProcA(
    [in] HWND hDlg,
    [in] UINT Msg,
    [in] WPARAM wParam,
    [in] LPARAM lParam
);

BOOL AdjustWindowRectExForDpi(
    [in, out] LPRECT lpRect,
    [in] DWORD dwStyle,
    [in] BOOL bMenu,
    [in] DWORD dwExStyle,
    [in] UINT dpi
);

BOOL CloseDesktop(
    [in] HDESK hDesktop
);

UINT GetWindowModuleFileNameA(
    [in] HWND hwnd,
    [out] LPSTR pszFileName,
    [in] UINT cchFileNameMax
);

LONG SetWindowLongW(
    [in] HWND hWnd,
    [in] int nIndex,
    [in] LONG dwNewLong
);

int MenuItemFromPoint(
    [in, optional] HWND hWnd,
    [in] HMENU hMenu,
    [in] POINT ptScreen
);

void SwitchToThisWindow(
    [in] HWND hwnd,
    [in] BOOL fUnknown
);

HDESK OpenInputDesktop(
    [in] DWORD dwFlags,
    [in] BOOL fInherit,
    [in] ACCESS_MASK dwDesiredAccess
);

BOOL GetMenuItemInfoW(
    [in] HMENU hmenu,
    [in] UINT item,
    [in] BOOL fByPosition,
    [in, out] LPMENUITEMINFOW lpmii
);

BOOL TranslateMDISysAccel(
    [in] HWND hWndClient,
    [in] LPMSG lpMsg
);

BOOL SetMenu(
    [in] HWND hWnd,
    [in, optional] HMENU hMenu
);

BOOL CreateCaret(
    [in] HWND hWnd,
    [in, optional] HBITMAP hBitmap,
    [in] int nWidth,
    [in] int nHeight
);

BOOL PaintDesktop(
    [in] HDC hdc
);

ULONG_PTR GetClassLongPtrW(
    [in] HWND hWnd,
    [in] int nIndex
);

BOOL GetIconInfoExW(
    [in] HICON hicon,
    [in, out] PICONINFOEXW piconinfo
);

INT_PTR DialogBoxIndirectParamA(
    [in, optional] HINSTANCE hInstance,
    [in] LPCDLGTEMPLATEA hDialogTemplate,
    [in, optional] HWND hWndParent,
    [in, optional] DLGPROC lpDialogFunc,
    [in] LPARAM dwInitParam
);

INT_PTR DialogBoxParamA(
    [in, optional] HINSTANCE hInstance,
    [in] LPCSTR lpTemplateName,
    [in, optional] HWND hWndParent,
    [in, optional] DLGPROC lpDialogFunc,
    [in] LPARAM dwInitParam
);

UINT RegisterClipboardFormatW(
    [in] LPCWSTR lpszFormat
);

BOOL AppendMenuW(
    [in] HMENU hMenu,
    [in] UINT uFlags,
    [in] UINT_PTR uIDNewItem,
    [in, optional] LPCWSTR lpNewItem
);

BOOL IsCharLowerW(
    WCHAR ch
);

BOOL SkipPointerFrameMessages(
    [in] UINT32 pointerId
);

LRESULT DefRawInputProc(
    [in] PRAWINPUT *paRawInput,
    [in] INT nInput,
    [in] UINT cbSizeHeader
);

UINT IsDlgButtonChecked(
    [in] HWND hDlg,
    [in] int nIDButton
);

BOOL GetMessageA(
    [out] LPMSG lpMsg,
    [in, optional] HWND hWnd,
    [in] UINT wMsgFilterMin,
    [in] UINT wMsgFilterMax
);

DWORD GetUnpredictedMessagePos();

SHORT VkKeyScanExA(
    [in] CHAR ch,
    [in] HKL dwhkl
);

BOOL GetMenuItemRect(
    [in, optional] HWND hWnd,
    [in] HMENU hMenu,
    [in] UINT uItem,
    [out] LPRECT lprcItem
);

HDESK CreateDesktopA(
    [in] LPCSTR lpszDesktop,
    LPCSTR lpszDevice,
    DEVMODEA *pDevmode,
    [in] DWORD dwFlags,
    [in] ACCESS_MASK dwDesiredAccess,
    [in, optional] LPSECURITY_ATTRIBUTES lpsa
);

void POINTSTOPOINT(
    pt,
    pts
);

BOOL SwapMouseButton(
    [in] BOOL fSwap
);

BOOL FlashWindowEx(
    [in] PFLASHWINFO pfwi
);

int FrameRect(
    [in] HDC hDC,
    [in] const RECT *lprc,
    [in] HBRUSH hbr
);

BOOL SetRectEmpty(
    [out] LPRECT lprc
);

BOOL CalculatePopupWindowPosition(
    [in] const POINT *anchorPoint,
    [in] const SIZE *windowSize,
    [in] UINT flags,
    [in, optional] RECT *excludeRect,
    [out] RECT *popupWindowPosition
);

HMENU GetSubMenu(
    [in] HMENU hMenu,
    [in] int nPos
);

int GetWindowTextLengthA(
    [in] HWND hWnd
);

LRESULT DefWindowProcA(
    [in] HWND hWnd,
    [in] UINT Msg,
    [in] WPARAM wParam,
    [in] LPARAM lParam
);

void ExitWindows(
    dwReserved,
    Code
);

BOOL PostMessageA(
    [in, optional] HWND hWnd,
    [in] UINT Msg,
    [in] WPARAM wParam,
    [in] LPARAM lParam
);

BOOL SetWindowFeedbackSetting(
    [in] HWND hwnd,
    [in] FEEDBACK_TYPE feedback,
    [in] DWORD dwFlags,
    [in] UINT32 size,
    [in, optional] const VOID *configuration
);

LONG ChangeDisplaySettingsExA(
    [in] LPCSTR lpszDeviceName,
    [in] DEVMODEA *lpDevMode,
    HWND hwnd,
    [in] DWORD dwflags,
    [in] LPVOID lParam
);

UINT RegisterClipboardFormatA(
    [in] LPCSTR lpszFormat
);

UINT PrivateExtractIconsW(
    [in] LPCWSTR szFileName,
    [in] int nIconIndex,
    [in] int cxIcon,
    [in] int cyIcon,
    [out, optional] HICON *phicon,
    [out, optional] UINT *piconid,
    [in] UINT nIcons,
    [in] UINT flags
);

BOOL GetPointerInputTransform(
    [in] UINT32 pointerId,
    [in] UINT32 historyCount,
    [out] INPUT_TRANSFORM *inputTransform
);

BOOL GetPointerPenInfoHistory(
    [in] UINT32 pointerId,
    [in, out] UINT32 *entriesCount,
    [out, optional] POINTER_PEN_INFO *penInfo
);

BOOL BlockInput(
    [in] BOOL fBlockIt
);

HBRUSH GetSysColorBrush(
    [in] int nIndex
);

BOOL DrawFrameControl(
    [in] HDC hdc,
    [in] LPRECT lprc,
    [in] UINT uType,
    [in] UINT uState
);

UINT GetDpiFromDpiAwarenessContext(
    DPI_AWARENESS_CONTEXT value
);

UINT GetMenuDefaultItem(
    [in] HMENU hMenu,
    [in] UINT fByPos,
    [in] UINT gmdiFlags
);

BOOL ChangeWindowMessageFilter(
    [in] UINT message,
    [in] DWORD dwFlag
);

BOOL GetPointerInfoHistory(
    [in] UINT32 pointerId,
    [in, out] UINT32 *entriesCount,
    [out, optional] POINTER_INFO *pointerInfo
);

int GetScrollPos(
    [in] HWND hWnd,
    [in] int nBar
);

BOOL RemoveMenu(
    [in] HMENU hMenu,
    [in] UINT uPosition,
    [in] UINT uFlags
);

int GetPriorityClipboardFormat(
    [in] UINT *paFormatPriorityList,
    [in] int cFormats
);

BOOL PrintWindow(
    HWND hwnd,
    HDC hdcBlt,
    UINT nFlags
);

UINT GetRegisteredRawInputDevices(
    [out, optional] PRAWINPUTDEVICE pRawInputDevices,
    [in, out] PUINT puiNumDevices,
    [in] UINT cbSize
);

BOOL IsCharAlphaNumericA(
    [in] CHAR ch
);

BOOL GetLayeredWindowAttributes(
    [in] HWND hwnd,
    [out, optional] COLORREF *pcrKey,
    [out, optional] BYTE *pbAlpha,
    [out, optional] DWORD *pdwFlags
);

BOOL SetDialogDpiChangeBehavior(
    HWND hDlg,
    DIALOG_DPI_CHANGE_BEHAVIORS mask,
    DIALOG_DPI_CHANGE_BEHAVIORS values
);

BOOL EnableWindow(
    [in] HWND hWnd,
    [in] BOOL bEnable
);

DWORD MsgWaitForMultipleObjectsEx(
    [in] DWORD nCount,
    [in] const HANDLE *pHandles,
    [in] DWORD dwMilliseconds,
    [in] DWORD dwWakeMask,
    [in] DWORD dwFlags
);

BOOL UnionRect(
    [out] LPRECT lprcDst,
    [in] const RECT *lprcSrc1,
    [in] const RECT *lprcSrc2
);

BOOL IsHungAppWindow(
    [in] HWND hwnd
);

BOOL IsCharUpperA(
    [in] CHAR ch
);

BOOL GetCursorInfo(
    [in, out] PCURSORINFO pci
);

HKL ActivateKeyboardLayout(
    [in] HKL hkl,
    [in] UINT Flags
);

HCURSOR LoadCursorW(
    [in, optional] HINSTANCE hInstance,
    [in] LPCWSTR lpCursorName
);

BOOL SetLayeredWindowAttributes(
    [in] HWND hwnd,
    [in] COLORREF crKey,
    [in] BYTE bAlpha,
    [in] DWORD dwFlags
);

BOOL SetMenuInfo(
    [in] HMENU unnamedParam1,
    [in] LPCMENUINFO unnamedParam2
);

void GET_RAWINPUT_CODE_WPARAM(
    wParam
);

BOOL EmptyClipboard();

void DestroySyntheticPointerDevice(
    [in] HSYNTHETICPOINTERDEVICE device
);

BOOL GetMessageW(
    [out] LPMSG lpMsg,
    [in, optional] HWND hWnd,
    [in] UINT wMsgFilterMin,
    [in] UINT wMsgFilterMax
);

BOOL SystemParametersInfoA(
    [in] UINT uiAction,
    [in] UINT uiParam,
    [in, out] PVOID pvParam,
    [in] UINT fWinIni
);

DWORD MsgWaitForMultipleObjects(
    [in] DWORD nCount,
    [in] const HANDLE *pHandles,
    [in] BOOL fWaitAll,
    [in] DWORD dwMilliseconds,
    [in] DWORD dwWakeMask
);

BOOL AdjustWindowRect(
    [in, out] LPRECT lpRect,
    [in] DWORD dwStyle,
    [in] BOOL bMenu
);

BOOL SetProcessDpiAwarenessContext(
    [in] DPI_AWARENESS_CONTEXT value
);

HANDLE LoadImageW(
    [in, optional] HINSTANCE hInst,
    [in] LPCWSTR name,
    [in] UINT type,
    [in] int cx,
    [in] int cy,
    [in] UINT fuLoad
);

UINT_PTR SetCoalescableTimer(
    [in, optional] HWND hWnd,
    [in] UINT_PTR nIDEvent,
    [in] UINT uElapse,
    [in, optional] TIMERPROC lpTimerFunc,
    [in] ULONG uToleranceDelay
);

BOOL OpenIcon(
    [in] HWND hWnd
);

void IS_POINTER_THIRDBUTTON_WPARAM(
    wParam
);

void IS_POINTER_CANCELED_WPARAM(
    wParam
);

void GET_DEVICE_LPARAM(
    lParam
);

int EnumPropsA(
    [in] HWND hWnd,
    [in] PROPENUMPROCA lpEnumFunc
);

DPI_HOSTING_BEHAVIOR GetThreadDpiHostingBehavior();

DWORD CharUpperBuffW(
    [in, out] LPWSTR lpsz,
    [in] DWORD cchLength
);

BOOL GetPhysicalCursorPos(
    [out] LPPOINT lpPoint
);

HDWP DeferWindowPos(
    [in] HDWP hWinPosInfo,
    [in] HWND hWnd,
    [in, optional] HWND hWndInsertAfter,
    [in] int x,
    [in] int y,
    [in] int cx,
    [in] int cy,
    [in] UINT uFlags
);

HKL LoadKeyboardLayoutA(
    [in] LPCSTR pwszKLID,
    [in] UINT Flags
);

BOOL UnhookWindowsHookEx(
    [in] HHOOK hhk
);

BOOL CloseTouchInputHandle(
    [in] HTOUCHINPUT hTouchInput
);

BOOL GetScrollBarInfo(
    [in] HWND hwnd,
    [in] LONG idObject,
    [out] PSCROLLBARINFO psbi
);

DWORD CheckMenuItem(
    [in] HMENU hMenu,
    [in] UINT uIDCheckItem,
    [in] UINT uCheck
);

int DlgDirListA(
    [in] HWND hDlg,
    [in, out] LPSTR lpPathSpec,
    [in] int nIDListBox,
    [in] int nIDStaticPath,
    [in] UINT uFileType
);

BOOL IsGUIThread(
    [in] BOOL bConvert
);

HWND FindWindowExA(
    [in, optional] HWND hWndParent,
    [in, optional] HWND hWndChildAfter,
    [in, optional] LPCSTR lpszClass,
    [in, optional] LPCSTR lpszWindow
);

BOOL InsertMenuItemW(
    [in] HMENU hmenu,
    [in] UINT item,
    [in] BOOL fByPosition,
    [in] LPCMENUITEMINFOW lpmi
);

BOOL EnumDisplayDevicesA(
    [in] LPCSTR lpDevice,
    [in] DWORD iDevNum,
    [out] PDISPLAY_DEVICEA lpDisplayDevice,
    [in] DWORD dwFlags
);

void IS_POINTER_FOURTHBUTTON_WPARAM(
    wParam
);

int CountClipboardFormats();

BOOL SetUserObjectInformationW(
    [in] HANDLE hObj,
    [in] int nIndex,
    [in] PVOID pvInfo,
    [in] DWORD nLength
);

WORD SetClassWord(
    [in] HWND hWnd,
    [in] int nIndex,
    [in] WORD wNewWord
);

BOOL PhysicalToLogicalPoint(
    [in] HWND hWnd,
    [in, out] LPPOINT lpPoint
);

BOOL SetRect(
    [out] LPRECT lprc,
    [in] int xLeft,
    [in] int yTop,
    [in] int xRight,
    [in] int yBottom
);

BOOL DrawEdge(
    [in] HDC hdc,
    [in, out] LPRECT qrc,
    [in] UINT edge,
    [in] UINT grfFlags
);

HWND WindowFromPoint(
    [in] POINT Point
);

void IS_POINTER_NEW_WPARAM(
    wParam
);

int WINAPIV wsprintfA(
    [out] LPSTR unnamedParam1,
    [in] LPCSTR unnamedParam2,
    ...
);

BOOL IsTouchWindow(
    [in] HWND hwnd,
    [out, optional] PULONG pulFlags
);

DWORD GetMessagePos();

HANDLE GetPropA(
    [in] HWND hWnd,
    [in] LPCSTR lpString
);

void PostQuitMessage(
    [in] int nExitCode
);

BOOL EnumDisplayDevicesW(
    [in] LPCWSTR lpDevice,
    [in] DWORD iDevNum,
    [out] PDISPLAY_DEVICEW lpDisplayDevice,
    [in] DWORD dwFlags
);

UINT PrivateExtractIconsA(
    [in] LPCSTR szFileName,
    [in] int nIconIndex,
    [in] int cxIcon,
    [in] int cyIcon,
    [out, optional] HICON *phicon,
    [out, optional] UINT *piconid,
    [in] UINT nIcons,
    [in] UINT flags
);

BOOL ShowCaret(
    [in, optional] HWND hWnd
);

LRESULT DefFrameProcW(
    [in] HWND hWnd,
    [in] HWND hWndMDIClient,
    [in] UINT uMsg,
    [in] WPARAM wParam,
    [in] LPARAM lParam
);

BOOL EvaluateProximityToPolygon(
    UINT32 numVertices,
    [in] const POINT *controlPolygon,
    [in] const TOUCH_HIT_TESTING_INPUT *pHitTestingInput,
    [out] TOUCH_HIT_TESTING_PROXIMITY_EVALUATION *pProximityEval
);

HMENU GetMenu(
    [in] HWND hWnd
);

BOOL GetWindowInfo(
    [in] HWND hwnd,
    [in, out] PWINDOWINFO pwi
);

LONG_PTR SetWindowLongPtrW(
    [in] HWND hWnd,
    [in] int nIndex,
    [in] LONG_PTR dwNewLong
);

DWORD GetSysColor(
    [in] int nIndex
);

BOOL OemToCharBuffW(
    [in] LPCSTR lpszSrc,
    [out] LPWSTR lpszDst,
    [in] DWORD cchDstLength
);

LRESULT SendMessageTimeoutW(
    [in] HWND hWnd,
    [in] UINT Msg,
    [in] WPARAM wParam,
    [in] LPARAM lParam,
    [in] UINT fuFlags,
    [in] UINT uTimeout,
    [out, optional] PDWORD_PTR lpdwResult
);

LRESULT CallWindowProcW(
    [in] WNDPROC lpPrevWndFunc,
    [in] HWND hWnd,
    [in] UINT Msg,
    [in] WPARAM wParam,
    [in] LPARAM lParam
);

UINT RegisterWindowMessageA(
    [in] LPCSTR lpString
);

BOOL AllowSetForegroundWindow(
    [in] DWORD dwProcessId
);

BOOL UnregisterSuspendResumeNotification(
    [in, out] HPOWERNOTIFY Handle
);

HWND CreateWindowA(
    [in, optional] LPCSTR lpClassName,
    [in, optional] LPCSTR lpWindowName,
    [in] DWORD dwStyle,
    [in] int x,
    [in] int y,
    [in] int nWidth,
    [in] int nHeight,
    [in, optional] HWND hWndParent,
    [in, optional] HMENU hMenu,
    [in, optional] HINSTANCE hInstance,
    [in, optional] LPVOID lpParam
);

BOOL EnumThreadWindows(
    [in] DWORD dwThreadId,
    [in] WNDENUMPROC lpfn,
    [in] LPARAM lParam
);

SHORT GetAsyncKeyState(
    [in] int vKey
);

HWND CreateDialogParamA(
    [in, optional] HINSTANCE hInstance,
    [in] LPCSTR lpTemplateName,
    [in, optional] HWND hWndParent,
    [in, optional] DLGPROC lpDialogFunc,
    [in] LPARAM dwInitParam
);

BOOL ScrollWindow(
    [in] HWND hWnd,
    [in] int XAmount,
    [in] int YAmount,
    [in] const RECT *lpRect,
    [in] const RECT *lpClipRect
);

BOOL InsertMenuA(
    [in] HMENU hMenu,
    [in] UINT uPosition,
    [in] UINT uFlags,
    [in] UINT_PTR uIDNewItem,
    [in, optional] LPCSTR lpNewItem
);

LRESULT SendDlgItemMessageA(
    [in] HWND hDlg,
    [in] int nIDDlgItem,
    [in] UINT Msg,
    [in] WPARAM wParam,
    [in] LPARAM lParam
);

BOOL SetDisplayAutoRotationPreferences(
    [in] ORIENTATION_PREFERENCE orientation
);

int GetClassNameW(
    [in] HWND hWnd,
    [out] LPWSTR lpClassName,
    [in] int nMaxCount
);

LONG QueryDisplayConfig(
    [in] UINT32 flags,
    [in, out] UINT32 *numPathArrayElements,
    [out] DISPLAYCONFIG_PATH_INFO *pathArray,
    [in, out] UINT32 *numModeInfoArrayElements,
    [out] DISPLAYCONFIG_MODE_INFO *modeInfoArray,
    [out, optional] DISPLAYCONFIG_TOPOLOGY_ID *currentTopologyId
);

BOOL SetCaretPos(
    [in] int X,
    [in] int Y
);

DWORD GetTabbedTextExtentA(
    [in] HDC hdc,
    [in] LPCSTR lpString,
    [in] int chCount,
    [in] int nTabPositions,
    [in] const INT *lpnTabStopPositions
);

BOOL PtInRect(
    [in] const RECT *lprc,
    [in] POINT pt
);

SHORT VkKeyScanExW(
    [in] WCHAR ch,
    [in] HKL dwhkl
);

BOOL AnimateWindow(
    [in] HWND hWnd,
    [in] DWORD dwTime,
    [in] DWORD dwFlags
);

BOOL RegisterPointerInputTarget(
    [in] HWND hwnd,
    [in] POINTER_INPUT_TYPE pointerType
);

LPWSTR CharUpperW(
    [in, out] LPWSTR lpsz
);

BOOL DlgDirSelectExA(
    [in] HWND hwndDlg,
    [out] LPSTR lpString,
    [in] int chCount,
    [in] int idListBox
);

BOOL GetPointerFrameInfo(
    [in] UINT32 pointerId,
    [in, out] UINT32 *pointerCount,
    [out] POINTER_INFO *pointerInfo
);

BOOL GetUserObjectInformationW(
    [in] HANDLE hObj,
    [in] int nIndex,
    [out, optional] PVOID pvInfo,
    [in] DWORD nLength,
    [out, optional] LPDWORD lpnLengthNeeded
);

BOOL GetIconInfoExA(
    [in] HICON hicon,
    [in, out] PICONINFOEXA piconinfo
);

HANDLE SetClipboardData(
    [in] UINT uFormat,
    [in, optional] HANDLE hMem
);

HWND GetClipboardViewer();

BOOL EnumChildWindows(
    [in, optional] HWND hWndParent,
    [in] WNDENUMPROC lpEnumFunc,
    [in] LPARAM lParam
);

int GetSystemMetricsForDpi(
    [in] int nIndex,
    [in] UINT dpi
);

BOOL SetWindowTextA(
    [in] HWND hWnd,
    [in, optional] LPCSTR lpString
);

BOOL InvalidateRect(
    [in] HWND hWnd,
    [in] const RECT *lpRect,
    [in] BOOL bErase
);

DIALOG_CONTROL_DPI_CHANGE_BEHAVIORS GetDialogControlDpiChangeBehavior(
    HWND hWnd
);

BOOL HiliteMenuItem(
    [in] HWND hWnd,
    [in] HMENU hMenu,
    [in] UINT uIDHiliteItem,
    [in] UINT uHilite
);

LPWSTR CharPrevW(
    [in] LPCWSTR lpszStart,
    [in] LPCWSTR lpszCurrent
);

HDEVNOTIFY RegisterDeviceNotificationA(
    [in] HANDLE hRecipient,
    [in] LPVOID NotificationFilter,
    [in] DWORD Flags
);

void IS_POINTER_PRIMARY_WPARAM(
    wParam
);

BOOL UnregisterClassA(
    [in] LPCSTR lpClassName,
    [in, optional] HINSTANCE hInstance
);

DWORD InSendMessageEx(
    LPVOID lpReserved
);

BOOL MoveWindow(
    [in] HWND hWnd,
    [in] int X,
    [in] int Y,
    [in] int nWidth,
    [in] int nHeight,
    [in] BOOL bRepaint
);

BOOL EnableMouseInPointer(
    [in] BOOL fEnable
);

HDC GetDC(
    [in] HWND hWnd
);

LONG GetMenuCheckMarkDimensions();

BOOL SetSysColors(
    [in] int cElements,
    [in] const INT *lpaElements,
    [in] const COLORREF *lpaRgbValues
);

BOOL SubtractRect(
    [out] LPRECT lprcDst,
    [in] const RECT *lprcSrc1,
    [in] const RECT *lprcSrc2
);

BOOL InvertRect(
    [in] HDC hDC,
    [in] const RECT *lprc
);

BOOL UnhookWinEvent(
    [in] HWINEVENTHOOK hWinEventHook
);

BOOL OemToCharA(
    [in] LPCSTR pSrc,
    [out] LPSTR pDst
);

BOOL SetKeyboardState(
    [in] LPBYTE lpKeyState
);

BOOL ShutdownBlockReasonQuery(
    [in] HWND hWnd,
    [out, optional] LPWSTR pwszBuff,
    [in, out] DWORD *pcchBuff
);

LRESULT PackTouchHitTestingProximityEvaluation(
    [in] const TOUCH_HIT_TESTING_INPUT *pHitTestingInput,
    [in] const TOUCH_HIT_TESTING_PROXIMITY_EVALUATION *pProximityEval
);

DWORD GetQueueStatus(
    [in] UINT flags
);

void CreateDialogIndirectW(
    [in, optional] hInstance,
    [in] lpTemplate,
    [in, optional] hWndParent,
    [in, optional] lpDialogFunc
);

HANDLE GetClipboardData(
    [in] UINT uFormat
);

LRESULT DefFrameProcA(
    [in] HWND hWnd,
    [in] HWND hWndMDIClient,
    [in] UINT uMsg,
    [in] WPARAM wParam,
    [in] LPARAM lParam
);

LONG DisplayConfigSetDeviceInfo(
    [in] DISPLAYCONFIG_DEVICE_INFO_HEADER *setPacket
);

BOOL GetClassInfoW(
    [in, optional] HINSTANCE hInstance,
    [in] LPCWSTR lpClassName,
    [out] LPWNDCLASSW lpWndClass
);

LONG GetWindowLongA(
    [in] HWND hWnd,
    [in] int nIndex
);

BOOL LockWindowUpdate(
    [in] HWND hWndLock
);

HWND WindowFromDC(
    [in] HDC hDC
);

BOOL GrayStringW(
    [in] HDC hDC,
    [in] HBRUSH hBrush,
    [in] GRAYSTRINGPROC lpOutputFunc,
    [in] LPARAM lpData,
    [in] int nCount,
    [in] int X,
    [in] int Y,
    [in] int nWidth,
    [in] int nHeight
);

HWND GetClipboardOwner();

BOOL GetPointerFrameInfoHistory(
    [in] UINT32 pointerId,
    [in, out] UINT32 *entriesCount,
    [in, out] UINT32 *pointerCount,
    [out] POINTER_INFO *pointerInfo
);

BOOL GetUserObjectInformationA(
    [in] HANDLE hObj,
    [in] int nIndex,
    [out, optional] PVOID pvInfo,
    [in] DWORD nLength,
    [out, optional] LPDWORD lpnLengthNeeded
);

UINT SendInput(
    [in] UINT cInputs,
    [in] LPINPUT pInputs,
    [in] int cbSize
);

LRESULT DispatchMessageW(
    [in] const MSG *lpMsg
);

int ShowCursor(
    [in] BOOL bShow
);

HCURSOR CreateCursor(
    [in, optional] HINSTANCE hInst,
    [in] int xHotSpot,
    [in] int yHotSpot,
    [in] int nWidth,
    [in] int nHeight,
    [in] const VOID *pvANDPlane,
    [in] const VOID *pvXORPlane
);

BOOL UnloadKeyboardLayout(
    [in] HKL hkl
);

BOOL GetDisplayAutoRotationPreferencesByProcessId(
    [in] DWORD dwProcessId,
    [out] ORIENTATION_PREFERENCE *pOrientation,
    [out] BOOL *fRotateScreen
);

BOOL RegisterRawInputDevices(
    [in] PCRAWINPUTDEVICE pRawInputDevices,
    [in] UINT uiNumDevices,
    [in] UINT cbSize
);

BOOL IsMenu(
    [in] HMENU hMenu
);

UINT MapVirtualKeyA(
    [in] UINT uCode,
    [in] UINT uMapType
);

BOOL ScrollDC(
    [in] HDC hDC,
    [in] int dx,
    [in] int dy,
    [in] const RECT *lprcScroll,
    [in] const RECT *lprcClip,
    [in] HRGN hrgnUpdate,
    [out] LPRECT lprcUpdate
);

DPI_AWARENESS_CONTEXT GetThreadDpiAwarenessContext();

UINT GetSystemDpiForProcess(
    HANDLE hProcess
);

BOOL HideCaret(
    [in, optional] HWND hWnd
);

int GetMenuStringA(
    [in] HMENU hMenu,
    [in] UINT uIDItem,
    [out, optional] LPSTR lpString,
    [in] int cchMax,
    [in] UINT flags
);

int EnumPropsW(
    [in] HWND hWnd,
    [in] PROPENUMPROCW lpEnumFunc
);

HWND WindowFromPhysicalPoint(
    [in] POINT Point
);

int ToUnicode(
    [in] UINT wVirtKey,
    [in] UINT wScanCode,
    [in, optional] const BYTE *lpKeyState,
    [out] LPWSTR pwszBuff,
    [in] int cchBuff,
    [in] UINT wFlags
);

BOOL GetClientRect(
    [in] HWND hWnd,
    [out] LPRECT lpRect
);

BOOL InflateRect(
    [in, out] LPRECT lprc,
    [in] int dx,
    [in] int dy
);

LONG_PTR GetWindowLongPtrW(
    [in] HWND hWnd,
    [in] int nIndex
);

BOOL EnableMenuItem(
    [in] HMENU hMenu,
    [in] UINT uIDEnableItem,
    [in] UINT uEnable
);

ULONG_PTR GetClassLongPtrA(
    [in] HWND hWnd,
    [in] int nIndex
);

void CopyCursor(
    [in] pcur
);

int ExcludeUpdateRgn(
    [in] HDC hDC,
    [in] HWND hWnd
);

BOOL EnableScrollBar(
    [in] HWND hWnd,
    [in] UINT wSBflags,
    [in] UINT wArrows
);

BOOL MapDialogRect(
    [in] HWND hDlg,
    [in, out] LPRECT lpRect
);

BOOL SetProcessDefaultLayout(
    [in] DWORD dwDefaultLayout
);

HWND CreateWindowW(
    [in, optional] LPCWSTR lpClassName,
    [in, optional] LPCWSTR lpWindowName,
    [in] DWORD dwStyle,
    [in] int x,
    [in] int y,
    [in] int nWidth,
    [in] int nHeight,
    [in, optional] HWND hWndParent,
    [in, optional] HMENU hMenu,
    [in, optional] HINSTANCE hInstance,
    [in, optional] LPVOID lpParam
);

DWORD SetClassLongW(
    [in] HWND hWnd,
    [in] int nIndex,
    [in] LONG dwNewLong
);

int LookupIconIdFromDirectory(
    [in] PBYTE presbits,
    [in] BOOL fIcon
);

long BroadcastSystemMessageA(
    [in] DWORD flags,
    [in, out, optional] LPDWORD lpInfo,
    [in] UINT Msg,
    [in] WPARAM wParam,
    [in] LPARAM lParam
);

HWND CreateMDIWindowW(
    [in] LPCWSTR lpClassName,
    [in] LPCWSTR lpWindowName,
    [in] DWORD dwStyle,
    [in] int X,
    [in] int Y,
    [in] int nWidth,
    [in] int nHeight,
    [in, optional] HWND hWndParent,
    [in, optional] HINSTANCE hInstance,
    [in] LPARAM lParam
);

BOOL GetWindowPlacement(
    [in] HWND hWnd,
    [in, out] WINDOWPLACEMENT *lpwndpl
);

int SetScrollPos(
    [in] HWND hWnd,
    [in] int nBar,
    [in] int nPos,
    [in] BOOL bRedraw
);

int GetMenuStringW(
    [in] HMENU hMenu,
    [in] UINT uIDItem,
    [out, optional] LPWSTR lpString,
    [in] int cchMax,
    [in] UINT flags
);

BOOL SetPropA(
    [in] HWND hWnd,
    [in] LPCSTR lpString,
    [in, optional] HANDLE hData
);

void CreateDialogW(
    [in, optional] hInstance,
    [in] lpName,
    [in, optional] hWndParent,
    [in, optional] lpDialogFunc
);

BOOL SendMessageCallbackW(
    [in] HWND hWnd,
    [in] UINT Msg,
    [in] WPARAM wParam,
    [in] LPARAM lParam,
    [in] SENDASYNCPROC lpResultCallBack,
    [in] ULONG_PTR dwData
);

int GetClassName(
    [in] HWND hWnd,
    [out] LPTSTR lpClassName,
    [in] int nMaxCount
);

BOOL UnregisterClassW(
    [in] LPCWSTR lpClassName,
    [in, optional] HINSTANCE hInstance
);

BOOL GrayStringA(
    [in] HDC hDC,
    [in] HBRUSH hBrush,
    [in] GRAYSTRINGPROC lpOutputFunc,
    [in] LPARAM lpData,
    [in] int nCount,
    [in] int X,
    [in] int Y,
    [in] int nWidth,
    [in] int nHeight
);

int TranslateAcceleratorW(
    [in] HWND hWnd,
    [in] HACCEL hAccTable,
    [in] LPMSG lpMsg
);

BOOL GetUserObjectSecurity(
    [in] HANDLE hObj,
    [in] PSECURITY_INFORMATION pSIRequested,
    [in, out, optional] PSECURITY_DESCRIPTOR pSID,
    [in] DWORD nLength,
    [out] LPDWORD lpnLengthNeeded
);

BOOL CharToOemA(
    [in] LPCSTR pSrc,
    [out] LPSTR pDst
);

BOOL DrawStateA(
    [in] HDC hdc,
    [in] HBRUSH hbrFore,
    [in] DRAWSTATEPROC qfnCallBack,
    [in] LPARAM lData,
    [in] WPARAM wData,
    [in] int x,
    [in] int y,
    [in] int cx,
    [in] int cy,
    [in] UINT uFlags
);

int DlgDirListW(
    [in] HWND hDlg,
    [in, out] LPWSTR lpPathSpec,
    [in] int nIDListBox,
    [in] int nIDStaticPath,
    [in] UINT uFileType
);

BOOL GetPointerDevices(
    [in, out] UINT32 *deviceCount,
    [out, optional] POINTER_DEVICE_INFO *pointerDevices
);

HACCEL CreateAcceleratorTableW(
    [in] LPACCEL paccel,
    [in] int cAccel
);

BOOL GetKeyboardLayoutNameW(
    [out] LPWSTR pwszKLID
);

BOOL GetKeyboardState(
    [out] PBYTE lpKeyState
);

UINT GetDoubleClickTime();

int SetScrollInfo(
    [in] HWND hwnd,
    [in] int nBar,
    [in] LPCSCROLLINFO lpsi,
    [in] BOOL redraw
);

BOOL AreDpiAwarenessContextsEqual(
    [in] DPI_AWARENESS_CONTEXT dpiContextA,
    [in] DPI_AWARENESS_CONTEXT dpiContextB
);

HICON CopyIcon(
    [in] HICON hIcon
);

HCURSOR SetCursor(
    [in, optional] HCURSOR hCursor
);

void MAKEWPARAM(
    l,
    h
);

UINT_PTR SetTimer(
    [in, optional] HWND hWnd,
    [in] UINT_PTR nIDEvent,
    [in] UINT uElapse,
    [in, optional] TIMERPROC lpTimerFunc
);

BOOL TranslateMessage(
    [in] const MSG *lpMsg
);

UINT EnumClipboardFormats(
    [in] UINT format
);

int ReleaseDC(
    [in] HWND hWnd,
    [in] HDC hDC
);

BOOL DestroyCursor(
    [in] HCURSOR hCursor
);

BOOL InjectSyntheticPointerInput(
    HSYNTHETICPOINTERDEVICE device,
    [in] const POINTER_TYPE_INFO *pointerInfo,
    [in] UINT32 count
);

BOOL IsRectEmpty(
    [in] const RECT *lprc
);

BOOL LockSetForegroundWindow(
    [in] UINT uLockCode
);

HACCEL LoadAcceleratorsW(
    [in, optional] HINSTANCE hInstance,
    [in] LPCWSTR lpTableName
);

int GetDlgCtrlID(
    [in] HWND hWnd
);

HMENU CreatePopupMenu();

BOOL SetCaretBlinkTime(
    [in] UINT uMSeconds
);

BOOL ValidateRect(
    [in] HWND hWnd,
    [in] const RECT *lpRect
);

BOOL IsWindow(
    [in, optional] HWND hWnd
);

HCURSOR LoadCursorFromFileW(
    [in] LPCWSTR lpFileName
);

int DrawTextExW(
    [in] HDC hdc,
    [in, out] LPWSTR lpchText,
    [in] int cchText,
    [in, out] LPRECT lprc,
    [in] UINT format,
    [in] LPDRAWTEXTPARAMS lpdtp
);

BOOL ShutdownBlockReasonCreate(
    [in] HWND hWnd,
    [in] LPCWSTR pwszReason
);

BOOL InheritWindowMonitor(
    HWND hwnd,
    HWND hwndInherit
);

HANDLE RemovePropW(
    [in] HWND hWnd,
    [in] LPCWSTR lpString
);

BOOL DrawIcon(
    [in] HDC hDC,
    [in] int X,
    [in] int Y,
    [in] HICON hIcon
);

BOOL SystemParametersInfoW(
    [in] UINT uiAction,
    [in] UINT uiParam,
    [in, out] PVOID pvParam,
    [in] UINT fWinIni
);

HICON CreateIconFromResource(
    [in] PBYTE presbits,
    [in] DWORD dwResSize,
    [in] BOOL fIcon,
    [in] DWORD dwVer
);

BOOL UserHandleGrantAccess(
    [in] HANDLE hUserHandle,
    [in] HANDLE hJob,
    [in] BOOL bGrant
);

BOOL CloseWindowStation(
    [in] HWINSTA hWinSta
);

int SetWindowRgn(
    [in] HWND hWnd,
    [in] HRGN hRgn,
    [in] BOOL bRedraw
);

DWORD GetListBoxInfo(
    [in] HWND hwnd
);

BOOL MessageBeep(
    [in] UINT uType
);

DWORD GetClassLongW(
    [in] HWND hWnd,
    [in] int nIndex
);

int MessageBoxIndirectW(
    [in] const MSGBOXPARAMSW *lpmbp
);

HWND GetAncestor(
    [in] HWND hwnd,
    [in] UINT gaFlags
);

LRESULT LRESULT DefMDIChildProcA(
    [in] HWND hWnd,
    [in] UINT uMsg,
    [in] WPARAM wParam,
    [in] LPARAM lParam
);

LRESULT DispatchMessageA(
    [in] const MSG *lpMsg
);

BOOL IsWindowEnabled(
    [in] HWND hWnd
);

LPSTR CharNextA(
    [in] LPCSTR lpsz
);

LONG ChangeDisplaySettingsExW(
    [in] LPCWSTR lpszDeviceName,
    [in] DEVMODEW *lpDevMode,
    HWND hwnd,
    [in] DWORD dwflags,
    [in] LPVOID lParam
);

LONG_PTR GetWindowLongPtrA(
    [in] HWND hWnd,
    [in] int nIndex
);

BOOL SetDoubleClickTime(
    [in] UINT unnamedParam1
);

BOOL DestroyIcon(
    [in] HICON hIcon
);

BOOL ShowScrollBar(
    [in] HWND hWnd,
    [in] int wBar,
    [in] BOOL bShow
);

void MAKEINTRESOURCEA(
    i
);

void GetNextWindow(
    [in] hWnd,
    [in] wCmd
);

HWINSTA CreateWindowStationA(
    [in, optional] LPCSTR lpwinsta,
    DWORD dwFlags,
    [in] ACCESS_MASK dwDesiredAccess,
    [in, optional] LPSECURITY_ATTRIBUTES lpsa
);

BOOL UnregisterPointerInputTargetEx(
    [in] HWND hwnd,
    [in] POINTER_INPUT_TYPE pointerType
);

int InternalGetWindowText(
    [in] HWND hWnd,
    [out] LPWSTR pString,
    [in] int cchMaxCount
);

LRESULT LRESULT DefDlgProcW(
    [in] HWND hDlg,
    [in] UINT Msg,
    [in] WPARAM wParam,
    [in] LPARAM lParam
);

int EnumPropsExW(
    [in] HWND hWnd,
    [in] PROPENUMPROCEXW lpEnumFunc,
    [in] LPARAM lParam
);

BOOL SetForegroundWindow(
    [in] HWND hWnd
);

BOOL DlgDirSelectComboBoxExA(
    [in] HWND hwndDlg,
    [out] LPSTR lpString,
    [in] int cchOut,
    [in] int idComboBox
);

BOOL GetWindowRect(
    [in] HWND hWnd,
    [out] LPRECT lpRect
);

BOOL SendNotifyMessageA(
    [in] HWND hWnd,
    [in] UINT Msg,
    [in] WPARAM wParam,
    [in] LPARAM lParam
);

BOOL PostMessageW(
    [in, optional] HWND hWnd,
    [in] UINT Msg,
    [in] WPARAM wParam,
    [in] LPARAM lParam
);

UINT ArrangeIconicWindows(
    [in] HWND hWnd
);

BOOL InsertMenuW(
    [in] HMENU hMenu,
    [in] UINT uPosition,
    [in] UINT uFlags,
    [in] UINT_PTR uIDNewItem,
    [in, optional] LPCWSTR lpNewItem
);

BOOL GetTitleBarInfo(
    [in] HWND hwnd,
    [in, out] PTITLEBARINFO pti
);

void IS_INTRESOURCE(
    _r
);

BOOL PhysicalToLogicalPointForPerMonitorDPI(
    [in] HWND hWnd,
    [in, out] LPPOINT lpPoint
);

HBITMAP LoadBitmapW(
    [in] HINSTANCE hInstance,
    [in] LPCWSTR lpBitmapName
);

HDESK CreateDesktopExA(
    [in] LPCSTR lpszDesktop,
    LPCSTR lpszDevice,
    DEVMODEA *pDevmode,
    [in] DWORD dwFlags,
    [in] ACCESS_MASK dwDesiredAccess,
    [in, optional] LPSECURITY_ATTRIBUTES lpsa,
    [in] ULONG ulHeapSize,
    PVOID pvoid
);

BOOL EnumWindowStationsA(
    [in] WINSTAENUMPROCA lpEnumFunc,
    [in] LPARAM lParam
);

int FillRect(
    [in] HDC hDC,
    [in] const RECT *lprc,
    [in] HBRUSH hbr
);

HICON CreateIcon(
    [in, optional] HINSTANCE hInstance,
    [in] int nWidth,
    [in] int nHeight,
    [in] BYTE cPlanes,
    [in] BYTE cBitsPixel,
    [in] const BYTE *lpbANDbits,
    [in] const BYTE *lpbXORbits
);

BOOL GetGestureExtraArgs(
    [in] HGESTUREINFO hGestureInfo,
    [in] UINT cbExtraArgs,
    [out] PBYTE pExtraArgs
);

DPI_AWARENESS GetAwarenessFromDpiAwarenessContext(
    [in] DPI_AWARENESS_CONTEXT value
);

HWND CreateMDIWindowA(
    [in] LPCSTR lpClassName,
    [in] LPCSTR lpWindowName,
    [in] DWORD dwStyle,
    [in] int X,
    [in] int Y,
    [in] int nWidth,
    [in] int nHeight,
    [in, optional] HWND hWndParent,
    [in, optional] HINSTANCE hInstance,
    [in] LPARAM lParam
);

BOOL IsIconic(
    [in] HWND hWnd
);

BOOL InSendMessage();

int DrawTextW(
    [in] HDC hdc,
    [in, out] LPCWSTR lpchText,
    [in] int cchText,
    [in, out] LPRECT lprc,
    [in] UINT format
);

HWND FindWindowExW(
    [in, optional] HWND hWndParent,
    [in, optional] HWND hWndChildAfter,
    [in, optional] LPCWSTR lpszClass,
    [in, optional] LPCWSTR lpszWindow
);

BOOL RegisterPointerDeviceNotifications(
    [in] HWND window,
    [in] BOOL notifyRange
);

DWORD CharUpperBuffA(
    [in, out] LPSTR lpsz,
    [in] DWORD cchLength
);

HDC GetDCEx(
    [in] HWND hWnd,
    [in] HRGN hrgnClip,
    [in] DWORD flags
);

void IS_POINTER_FLAG_SET_WPARAM(
    wParam,
    flag
);

void GET_POINTERID_WPARAM(
    wParam
);

void keybd_event(
    [in] BYTE bVk,
    [in] BYTE bScan,
    [in] DWORD dwFlags,
    [in] ULONG_PTR dwExtraInfo
);

BOOL EndDeferWindowPos(
    [in] HDWP hWinPosInfo
);

BOOL ScreenToClient(
    [in] HWND hWnd,
    LPPOINT lpPoint
);

int GetMenuItemCount(
    [in, optional] HMENU hMenu
);

BOOL ShowWindow(
    [in] HWND hWnd,
    [in] int nCmdShow
);

DWORD OemKeyScan(
    [in] WORD wOemChar
);

BOOL ModifyMenuA(
    [in] HMENU hMnu,
    [in] UINT uPosition,
    [in] UINT uFlags,
    [in] UINT_PTR uIDNewItem,
    [in, optional] LPCSTR lpNewItem
);

HWINSTA CreateWindowStationW(
    [in, optional] LPCWSTR lpwinsta,
    DWORD dwFlags,
    [in] ACCESS_MASK dwDesiredAccess,
    [in, optional] LPSECURITY_ATTRIBUTES lpsa
);

BOOL SetUserObjectSecurity(
    [in] HANDLE hObj,
    [in] PSECURITY_INFORMATION pSIRequested,
    [in] PSECURITY_DESCRIPTOR pSID
);

BOOL RegisterHotKey(
    [in, optional] HWND hWnd,
    [in] int id,
    [in] UINT fsModifiers,
    [in] UINT vk
);

BOOL AnyPopup();

LRESULT LRESULT DefMDIChildProcW(
    [in] HWND hWnd,
    [in] UINT uMsg,
    [in] WPARAM wParam,
    [in] LPARAM lParam
);

HDEVNOTIFY RegisterDeviceNotificationW(
    [in] HANDLE hRecipient,
    [in] LPVOID NotificationFilter,
    [in] DWORD Flags
);

HMONITOR MonitorFromWindow(
    [in] HWND hwnd,
    [in] DWORD dwFlags
);

int ScrollWindowEx(
    [in] HWND hWnd,
    [in] int dx,
    [in] int dy,
    [in] const RECT *prcScroll,
    [in] const RECT *prcClip,
    [in] HRGN hrgnUpdate,
    [out] LPRECT prcUpdate,
    [in] UINT flags
);

BOOL IsValidDpiAwarenessContext(
    [in] DPI_AWARENESS_CONTEXT value
);

BOOL EndPaint(
    [in] HWND hWnd,
    [in] const PAINTSTRUCT *lpPaint
);

BOOL PeekMessageW(
    [out] LPMSG lpMsg,
    [in, optional] HWND hWnd,
    [in] UINT wMsgFilterMin,
    [in] UINT wMsgFilterMax,
    [in] UINT wRemoveMsg
);

DPI_AWARENESS_CONTEXT GetDpiAwarenessContextForProcess(
    HANDLE hProcess
);

BOOL EnumDisplaySettingsA(
    [in] LPCSTR lpszDeviceName,
    [in] DWORD iModeNum,
    [out] DEVMODEA *lpDevMode
);

HMENU LoadMenuIndirectW(
    [in] const MENUTEMPLATEW *lpMenuTemplate
);

LONG SetDisplayConfig(
    [in] UINT32 numPathArrayElements,
    [in, optional] DISPLAYCONFIG_PATH_INFO *pathArray,
    [in] UINT32 numModeInfoArrayElements,
    [in, optional] DISPLAYCONFIG_MODE_INFO *modeInfoArray,
    [in] UINT32 flags
);

int GetKeyNameTextA(
    [in] LONG lParam,
    [out] LPSTR lpString,
    [in] int cchSize
);

BOOL InsertMenuItemA(
    [in] HMENU hmenu,
    [in] UINT item,
    [in] BOOL fByPosition,
    [in] LPCMENUITEMINFOA lpmi
);

DPI_AWARENESS_CONTEXT SetThreadDpiAwarenessContext(
    [in] DPI_AWARENESS_CONTEXT dpiContext
);

HICON CreateIconIndirect(
    [in] PICONINFO piconinfo
);

UINT GetMenuState(
    [in] HMENU hMenu,
    [in] UINT uId,
    [in] UINT uFlags
);

int GetClipboardFormatNameA(
    [in] UINT format,
    [out] LPSTR lpszFormatName,
    [in] int cchMaxCount
);

HMONITOR MonitorFromRect(
    [in] LPCRECT lprc,
    [in] DWORD dwFlags
);

BOOL EnumDesktopWindows(
    [in, optional] HDESK hDesktop,
    [in] WNDENUMPROC lpfn,
    [in] LPARAM lParam
);

DWORD GetTabbedTextExtentW(
    [in] HDC hdc,
    [in] LPCWSTR lpString,
    [in] int chCount,
    [in] int nTabPositions,
    [in] const INT *lpnTabStopPositions
);

HANDLE LoadImageA(
    [in, optional] HINSTANCE hInst,
    [in] LPCSTR name,
    [in] UINT type,
    [in] int cx,
    [in] int cy,
    [in] UINT fuLoad
);

HMENU LoadMenuIndirectA(
    [in] const MENUTEMPLATEA *lpMenuTemplate
);

BOOL RegisterPointerInputTargetEx(
    [in] HWND hwnd,
    [in] POINTER_INPUT_TYPE pointerType,
    [in] BOOL fObserve
);

DWORD GetGuiResources(
    [in] HANDLE hProcess,
    [in] DWORD uiFlags
);

BOOL EvaluateProximityToRect(
    [in] const RECT *controlBoundingBox,
    [in] const TOUCH_HIT_TESTING_INPUT *pHitTestingInput,
    [out] TOUCH_HIT_TESTING_PROXIMITY_EVALUATION *pProximityEval
);

void GET_XBUTTON_WPARAM(
    wParam
);

UINT SetThreadCursorCreationScaling(
    UINT cursorDpi
);

HWND GetWindow(
    [in] HWND hWnd,
    [in] UINT uCmd
);

BOOL GetCurrentInputMessageSource(
    [out] INPUT_MESSAGE_SOURCE *inputMessageSource
);

void DialogBoxIndirectA(
    [in, optional] hInstance,
    [in] lpTemplate,
    [in, optional] hWndParent,
    [in, optional] lpDialogFunc
);

BOOL GetMenuItemInfoA(
    [in] HMENU hmenu,
    [in] UINT item,
    [in] BOOL fByPosition,
    [in, out] LPMENUITEMINFOA lpmii
);

int DlgDirListComboBoxW(
    [in] HWND hDlg,
    [in, out] LPWSTR lpPathSpec,
    [in] int nIDComboBox,
    [in] int nIDStaticPath,
    [in] UINT uFiletype
);

SHORT GetKeyState(
    [in] int nVirtKey
);

BOOL RegisterTouchWindow(
    [in] HWND hwnd,
    [in] ULONG ulFlags
);

HANDLE RemovePropA(
    [in] HWND hWnd,
    [in] LPCSTR lpString
);

HDESK GetThreadDesktop(
    [in] DWORD dwThreadId
);

int DrawText(
    [in] HDC hdc,
    [in, out] LPCTSTR lpchText,
    [in] int cchText,
    [in, out] LPRECT lprc,
    [in] UINT format
);

HHOOK SetWindowsHookExA(
    [in] int idHook,
    [in] HOOKPROC lpfn,
    [in] HINSTANCE hmod,
    [in] DWORD dwThreadId
);

HWND GetShellWindow();

BOOL GetAltTabInfoA(
    [in, optional] HWND hwnd,
    [in] int iItem,
    [in, out] PALTTABINFO pati,
    [out, optional] LPSTR pszItemText,
    [in] UINT cchItemText
);

HWINSTA GetProcessWindowStation();

BOOL InjectTouchInput(
    [in] UINT32 count,
    [in] const POINTER_TOUCH_INFO *contacts
);

WORD CascadeWindows(
    [in, optional] HWND hwndParent,
    [in] UINT wHow,
    [in, optional] const RECT *lpRect,
    [in] UINT cKids,
    [in, optional] const HWND *lpKids
);

HWND ChildWindowFromPoint(
    [in] HWND hWndParent,
    [in] POINT Point
);

HMENU CreateMenu();

BOOL OemToCharW(
    [in] LPCSTR pSrc,
    [out] LPWSTR pDst
);

UINT GetDlgItemInt(
    [in] HWND hDlg,
    [in] int nIDDlgItem,
    [out, optional] BOOL *lpTranslated,
    [in] BOOL bSigned
);

BOOL RegisterTouchHitTestingWindow(
    [in] HWND hwnd,
    [in] ULONG value
);

BOOL GetClassInfoExW(
    [in, optional] HINSTANCE hInstance,
    [in] LPCWSTR lpszClass,
    [out] LPWNDCLASSEXW lpwcx
);

SHORT VkKeyScanA(
    [in] CHAR ch
);

WORD GetWindowWord(
    HWND hWnd,
    int nIndex
);

BOOL CheckMenuRadioItem(
    [in] HMENU hmenu,
    [in] UINT first,
    [in] UINT last,
    [in] UINT check,
    [in] UINT flags
);

int GetKeyboardType(
    [in] int nTypeFlag
);

BOOL IsCharAlphaA(
    [in] CHAR ch
);

HPOWERNOTIFY RegisterPowerSettingNotification(
    [in] HANDLE hRecipient,
    [in] LPCGUID PowerSettingGuid,
    [in] DWORD Flags
);

BOOL GetKeyboardLayoutNameA(
    [out] LPSTR pwszKLID
);

HWND SetCapture(
    [in] HWND hWnd
);

BOOL SetDlgItemInt(
    [in] HWND hDlg,
    [in] int nIDDlgItem,
    [in] UINT uValue,
    [in] BOOL bSigned
);

HWND ChildWindowFromPointEx(
    [in] HWND hwnd,
    [in] POINT pt,
    [in] UINT flags
);

BOOL ReleaseCapture();

BOOL LogicalToPhysicalPointForPerMonitorDPI(
    [in] HWND hWnd,
    [in, out] LPPOINT lpPoint
);

HWINEVENTHOOK SetWinEventHook(
    [in] DWORD eventMin,
    [in] DWORD eventMax,
    [in] HMODULE hmodWinEventProc,
    [in] WINEVENTPROC pfnWinEventProc,
    [in] DWORD idProcess,
    [in] DWORD idThread,
    [in] DWORD dwFlags
);

BOOL GetCaretPos(
    [out] LPPOINT lpPoint
);

BOOL GetScrollInfo(
    [in] HWND hwnd,
    [in] int nBar,
    [in, out] LPSCROLLINFO lpsi
);

UINT MapVirtualKeyExW(
    [in] UINT uCode,
    [in] UINT uMapType,
    [in, out, optional] HKL dwhkl
);

int DrawTextA(
    [in] HDC hdc,
    [in, out] LPCSTR lpchText,
    [in] int cchText,
    [in, out] LPRECT lprc,
    [in] UINT format
);

HWND FindWindowW(
    [in, optional] LPCWSTR lpClassName,
    [in, optional] LPCWSTR lpWindowName
);

void DialogBoxA(
    [in, optional] hInstance,
    [in] lpTemplate,
    [in, optional] hWndParent,
    [in, optional] lpDialogFunc
);

UINT GetMenuItemID(
    [in] HMENU hMenu,
    [in] int nPos
);

LONG GetMessageTime();

UINT GetRawInputBuffer(
    [out, optional] PRAWINPUT pData,
    [in, out] PUINT pcbSize,
    [in] UINT cbSizeHeader
);

BOOL InitializeTouchInjection(
    [in] UINT32 maxCount,
    [in] DWORD dwMode
);

HMENU LoadMenuA(
    [in, optional] HINSTANCE hInstance,
    [in] LPCSTR lpMenuName
);

BOOL IsChild(
    [in] HWND hWndParent,
    [in] HWND hWnd
);

BOOL IsWindowVisible(
    [in] HWND hWnd
);

void DialogBoxIndirectW(
    [in, optional] hInstance,
    [in] lpTemplate,
    [in, optional] hWndParent,
    [in, optional] lpDialogFunc
);

int LoadStringA(
    [in, optional] HINSTANCE hInstance,
    [in] UINT uID,
    [out] LPSTR lpBuffer,
    [in] int cchBufferMax
);

BOOL RegisterForTooltipDismissNotification(
    HWND hWnd,
    TOOLTIP_DISMISS_FLAGS tdFlags
);

DWORD CharLowerBuffA(
    [in, out] LPSTR lpsz,
    [in] DWORD cchLength
);

HDC BeginPaint(
    [in] HWND hWnd,
    [out] LPPAINTSTRUCT lpPaint
);

int wvsprintfA(
    [out] LPSTR unnamedParam1,
    [in] LPCSTR unnamedParam2,
    [in] va_list arglist
);

BOOL CharToOemW(
    [in] LPCWSTR pSrc,
    [out] LPSTR pDst
);

HACCEL LoadAcceleratorsA(
    [in, optional] HINSTANCE hInstance,
    [in] LPCSTR lpTableName
);

BOOL IsDialogMessageA(
    [in] HWND hDlg,
    [in] LPMSG lpMsg
);

BOOL SetMenuItemInfoA(
    [in] HMENU hmenu,
    [in] UINT item,
    BOOL fByPositon,
    [in] LPCMENUITEMINFOA lpmii
);

BOOL RemoveClipboardFormatListener(
    [in] HWND hwnd
);

BOOL GetPointerFramePenInfo(
    [in] UINT32 pointerId,
    [in, out] UINT32 *pointerCount,
    [out] POINTER_PEN_INFO *penInfo
);

BOOL IsCharLowerA(
    [in] CHAR ch
);

BOOL IsClipboardFormatAvailable(
    [in] UINT format
);

HWND GetFocus();

HANDLE CopyImage(
    [in] HANDLE h,
    [in] UINT type,
    [in] int cx,
    [in] int cy,
    [in] UINT flags
);

BOOL SendMessageCallbackA(
    [in] HWND hWnd,
    [in] UINT Msg,
    [in] WPARAM wParam,
    [in] LPARAM lParam,
    [in] SENDASYNCPROC lpResultCallBack,
    [in] ULONG_PTR dwData
);

DWORD SetClassLongA(
    [in] HWND hWnd,
    [in] int nIndex,
    [in] LONG dwNewLong
);

UINT MapVirtualKeyW(
    [in] UINT uCode,
    [in] UINT uMapType
);

BOOL SetSystemCursor(
    [in] HCURSOR hcur,
    [in] DWORD id
);

HDESK OpenDesktopA(
    [in] LPCSTR lpszDesktop,
    [in] DWORD dwFlags,
    [in] BOOL fInherit,
    [in] ACCESS_MASK dwDesiredAccess
);

BOOL EndDialog(
    [in] HWND hDlg,
    [in] INT_PTR nResult
);

LRESULT CallWindowProcA(
    [in] WNDPROC lpPrevWndFunc,
    [in] HWND hWnd,
    [in] UINT Msg,
    [in] WPARAM wParam,
    [in] LPARAM lParam
);

BOOL DrawMenuBar(
    [in] HWND hWnd
);

BOOL CloseClipboard();

BOOL TrackMouseEvent(
    [in, out] LPTRACKMOUSEEVENT lpEventTrack
);

HKL GetKeyboardLayout(
    [in] DWORD idThread
);

int MessageBoxExW(
    [in, optional] HWND hWnd,
    [in, optional] LPCWSTR lpText,
    [in, optional] LPCWSTR lpCaption,
    [in] UINT uType,
    [in] WORD wLanguageId
);

HWND SetParent(
    [in] HWND hWndChild,
    [in, optional] HWND hWndNewParent
);

BOOL DestroyMenu(
    [in] HMENU hMenu
);

HWND GetNextDlgGroupItem(
    [in] HWND hDlg,
    [in, optional] HWND hCtl,
    [in] BOOL bPrevious
);

BOOL DrawFocusRect(
    [in] HDC hDC,
    [in] const RECT *lprc
);

UINT GetRawInputData(
    [in] HRAWINPUT hRawInput,
    [in] UINT uiCommand,
    [out, optional] LPVOID pData,
    [in, out] PUINT pcbSize,
    [in] UINT cbSizeHeader
);

void mouse_event(
    [in] DWORD dwFlags,
    [in] DWORD dx,
    [in] DWORD dy,
    [in] DWORD dwData,
    [in] ULONG_PTR dwExtraInfo
);

BOOL SetCursorPos(
    [in] int X,
    [in] int Y
);

BOOL SetMenuContextHelpId(
    HMENU unnamedParam1,
    DWORD unnamedParam2
);

BOOL UnregisterHotKey(
    [in, optional] HWND hWnd,
    [in] int id
);

BOOL KillTimer(
    [in, optional] HWND hWnd,
    [in] UINT_PTR uIDEvent
);

BOOL ClientToScreen(
    [in] HWND hWnd,
    [in, out] LPPOINT lpPoint
);

int TranslateAcceleratorA(
    [in] HWND hWnd,
    [in] HACCEL hAccTable,
    [in] LPMSG lpMsg
);

LPSTR CharUpperA(
    [in, out] LPSTR lpsz
);

BOOL ModifyMenuW(
    [in] HMENU hMnu,
    [in] UINT uPosition,
    [in] UINT uFlags,
    [in] UINT_PTR uIDNewItem,
    [in, optional] LPCWSTR lpNewItem
);

BOOL SetDlgItemTextW(
    [in] HWND hDlg,
    [in] int nIDDlgItem,
    [in] LPCWSTR lpString
);

int ToUnicodeEx(
    [in] UINT wVirtKey,
    [in] UINT wScanCode,
    [in] const BYTE *lpKeyState,
    [out] LPWSTR pwszBuff,
    [in] int cchBuff,
    [in] UINT wFlags,
    [in, optional] HKL dwhkl
);

BOOL ExitWindowsEx(
    [in] UINT uFlags,
    [in] DWORD dwReason
);

HWND GetDesktopWindow();

BOOL UpdateWindow(
    [in] HWND hWnd
);

BOOL FlashWindow(
    [in] HWND hWnd,
    [in] BOOL bInvert
);

WORD GetClassWord(
    [in] HWND hWnd,
    [in] int nIndex
);

HWND SetActiveWindow(
    [in] HWND hWnd
);

BOOL GetPointerFrameTouchInfoHistory(
    [in] UINT32 pointerId,
    [in, out] UINT32 *entriesCount,
    [in, out] UINT32 *pointerCount,
    [out] POINTER_TOUCH_INFO *touchInfo
);

HWND RealChildWindowFromPoint(
    [in] HWND hwndParent,
    [in] POINT ptParentClientCoords
);

LRESULT DispatchMessage(
    [in] const MSG *lpMsg
);

HMENU GetSystemMenu(
    [in] HWND hWnd,
    [in] BOOL bRevert
);

ATOM RegisterClassExA(
    [in] const WNDCLASSEXA *unnamedParam1
);

BOOL DestroyWindow(
    [in] HWND hWnd
);

DWORD CharLowerBuffW(
    [in, out] LPWSTR lpsz,
    [in] DWORD cchLength
);

DPI_HOSTING_BEHAVIOR GetWindowDpiHostingBehavior(
    HWND hwnd
);

void GET_NCHITTEST_WPARAM(
    wParam
);

HCURSOR LoadCursorA(
    [in, optional] HINSTANCE hInstance,
    [in] LPCSTR lpCursorName
);

LRESULT SendMessageW(
    [in] HWND hWnd,
    [in] UINT Msg,
    [in] WPARAM wParam,
    [in] LPARAM lParam
);

void IS_POINTER_FIFTHBUTTON_WPARAM(
    wParam
);

UINT GetDlgItemTextA(
    [in] HWND hDlg,
    [in] int nIDDlgItem,
    [out] LPSTR lpString,
    [in] int cchMax
);

int GetWindowRgn(
    [in] HWND hWnd,
    [in] HRGN hRgn
);

BOOL GetPointerInfo(
    [in] UINT32 pointerId,
    [out] POINTER_INFO *pointerInfo
);

BOOL SetDialogControlDpiChangeBehavior(
    HWND hWnd,
    DIALOG_CONTROL_DPI_CHANGE_BEHAVIORS mask,
    DIALOG_CONTROL_DPI_CHANGE_BEHAVIORS values
);

BOOL GetGestureInfo(
    [in] HGESTUREINFO hGestureInfo,
    [out] PGESTUREINFO pGestureInfo
);

BOOL GetMenuInfo(
    [in] HMENU unnamedParam1,
    [in, out] LPMENUINFO unnamedParam2
);

DPI_HOSTING_BEHAVIOR SetThreadDpiHostingBehavior(
    DPI_HOSTING_BEHAVIOR value
);

BOOL BringWindowToTop(
    [in] HWND hWnd
);

void IS_POINTER_INCONTACT_WPARAM(
    wParam
);

UINT GetRawInputDeviceList(
    [out, optional] PRAWINPUTDEVICELIST pRawInputDeviceList,
    [in, out] PUINT puiNumDevices,
    [in] UINT cbSize
);

HWND GetForegroundWindow();

void DialogBoxW(
    [in, optional] hInstance,
    [in] lpTemplate,
    [in, optional] hWndParent,
    [in, optional] lpDialogFunc
);

HWINSTA OpenWindowStationW(
    [in] LPCWSTR lpszWinSta,
    [in] BOOL fInherit,
    [in] ACCESS_MASK dwDesiredAccess
);

BOOL TrackPopupMenuEx(
    [in] HMENU hMenu,
    [in] UINT uFlags,
    [in] int x,
    [in] int y,
    [in] HWND hwnd,
    [in, optional] LPTPMPARAMS lptpm
);

BOOL WaitMessage();

int GetClassNameA(
    [in] HWND hWnd,
    [out] LPSTR lpClassName,
    [in] int nMaxCount
);

ATOM RegisterClassW(
    [in] const WNDCLASSW *lpWndClass
);

BOOL SetWindowTextW(
    [in] HWND hWnd,
    [in, optional] LPCWSTR lpString
);

LONG GetWindowLongW(
    [in] HWND hWnd,
    [in] int nIndex
);

BOOL SetProcessDPIAware();

BOOL GetDisplayAutoRotationPreferences(
    [out] ORIENTATION_PREFERENCE *pOrientation
);

UINT GetRawInputDeviceInfoA(
    [in, optional] HANDLE hDevice,
    [in] UINT uiCommand,
    [in, out, optional] LPVOID pData,
    [in, out] PUINT pcbSize
);

BOOL GetMessage(
    [out] LPMSG lpMsg,
    [in, optional] HWND hWnd,
    [in] UINT wMsgFilterMin,
    [in] UINT wMsgFilterMax
);

BOOL DrawAnimatedRects(
    [in] HWND hwnd,
    [in] int idAni,
    const RECT *lprcFrom,
    const RECT *lprcTo
);

LRESULT CallNextHookEx(
    [in, optional] HHOOK hhk,
    [in] int nCode,
    [in] WPARAM wParam,
    [in] LPARAM lParam
);

BOOL ShowWindowAsync(
    [in] HWND hWnd,
    [in] int nCmdShow
);

BOOL SetProcessRestrictionExemption(
    BOOL fEnableExemption
);

void HAS_POINTER_CONFIDENCE_WPARAM(
    wParam
);

HACCEL CreateAcceleratorTableA(
    [in] LPACCEL paccel,
    [in] int cAccel
);

BOOL TrackPopupMenu(
    [in] HMENU hMenu,
    [in] UINT uFlags,
    [in] int x,
    [in] int y,
    [in] int nReserved,
    [in] HWND hWnd,
    [in, optional] const RECT *prcRect
);

LONG ChangeDisplaySettingsA(
    [in] DEVMODEA *lpDevMode,
    [in] DWORD dwFlags
);

HHOOK SetWindowsHookExW(
    [in] int idHook,
    [in] HOOKPROC lpfn,
    [in] HINSTANCE hmod,
    [in] DWORD dwThreadId
);

DWORD GetMenuContextHelpId(
    HMENU unnamedParam1
);

BOOL EndMenu();

BOOL GetGUIThreadInfo(
    [in] DWORD idThread,
    [in, out] PGUITHREADINFO pgui
);

long BroadcastSystemMessageExA(
    [in] DWORD flags,
    [in, out, optional] LPDWORD lpInfo,
    [in] UINT Msg,
    [in] WPARAM wParam,
    [in] LPARAM lParam,
    [out, optional] PBSMINFO pbsmInfo
);

BOOL GetTouchInputInfo(
    [in] HTOUCHINPUT hTouchInput,
    [in] UINT cInputs,
    [out] PTOUCHINPUT pInputs,
    [in] int cbSize
);

BOOL IsMouseInPointerEnabled();

HKL LoadKeyboardLayoutW(
    [in] LPCWSTR pwszKLID,
    [in] UINT Flags
);

BOOL SetPhysicalCursorPos(
    [in] int X,
    [in] int Y
);

HWND FindWindowA(
    [in, optional] LPCSTR lpClassName,
    [in, optional] LPCSTR lpWindowName
);

BOOL GetComboBoxInfo(
    [in] HWND hwndCombo,
    [out] PCOMBOBOXINFO pcbi
);

void MAKEINTRESOURCEW(
    i
);

BOOL GetMonitorInfoA(
    [in] HMONITOR hMonitor,
    [out] LPMONITORINFO lpmi
);

BOOL SetMenuItemBitmaps(
    [in] HMENU hMenu,
    [in] UINT uPosition,
    [in] UINT uFlags,
    [in, optional] HBITMAP hBitmapUnchecked,
    [in, optional] HBITMAP hBitmapChecked
);

void TOUCH_COORD_TO_PIXEL(
    l
);

HWND GetTopWindow(
    [in, optional] HWND hWnd
);

DWORD GetWindowThreadProcessId(
    [in] HWND hWnd,
    [out, optional] LPDWORD lpdwProcessId
);

BOOL DragDetect(
    [in] HWND hwnd,
    [in] POINT pt
);

BOOL EnableNonClientDpiScaling(
    [in] HWND hwnd
);

LRESULT SendMessageA(
    [in] HWND hWnd,
    [in] UINT Msg,
    [in] WPARAM wParam,
    [in] LPARAM lParam
);

long BroadcastSystemMessageW(
    [in] DWORD flags,
    [in, out, optional] LPDWORD lpInfo,
    [in] UINT Msg,
    [in] WPARAM wParam,
    [in] LPARAM lParam
);

BOOL GetPointerPenInfo(
    [in] UINT32 pointerId,
    [out] POINTER_PEN_INFO *penInfo
);

BOOL WinHelpW(
    HWND hWndMain,
    LPCWSTR lpszHelp,
    UINT uCommand,
    ULONG_PTR dwData
);

long BroadcastSystemMessage(
    [in] DWORD flags,
    [in, out, optional] LPDWORD lpInfo,
    [in] UINT Msg,
    [in] WPARAM wParam,
    [in] LPARAM lParam
);

BOOL SetProcessWindowStation(
    [in] HWINSTA hWinSta
);

DWORD GetWindowContextHelpId(
    HWND unnamedParam1
);

LRESULT SendMessageTimeoutA(
    [in] HWND hWnd,
    [in] UINT Msg,
    [in] WPARAM wParam,
    [in] LPARAM lParam,
    [in] UINT fuFlags,
    [in] UINT uTimeout,
    [out, optional] PDWORD_PTR lpdwResult
);

int CopyAcceleratorTableW(
    [in] HACCEL hAccelSrc,
    [out, optional] LPACCEL lpAccelDst,
    [in] int cAccelEntries
);

INT_PTR DialogBoxParamW(
    [in, optional] HINSTANCE hInstance,
    [in] LPCWSTR lpTemplateName,
    [in, optional] HWND hWndParent,
    [in, optional] DLGPROC lpDialogFunc,
    [in] LPARAM dwInitParam
);

BOOL GetUpdatedClipboardFormats(
    [out] PUINT lpuiFormats,
    [in] UINT cFormats,
    [out] PUINT pcFormatsOut
);

BOOL SetThreadDesktop(
    [in] HDESK hDesktop
);

BOOL CloseGestureInfoHandle(
    HGESTUREINFO hGestureInfo
);

BOOL EnumDisplayMonitors(
    [in] HDC hdc,
    [in] LPCRECT lprcClip,
    [in] MONITORENUMPROC lpfnEnum,
    [in] LPARAM dwData
);

BOOL IsWinEventHookInstalled(
    [in] DWORD event
);

int GetWindowTextLengthW(
    [in] HWND hWnd
);

HMONITOR MonitorFromPoint(
    [in] POINT pt,
    [in] DWORD dwFlags
);

DPI_AWARENESS_CONTEXT GetWindowDpiAwarenessContext(
    [in] HWND hwnd
);

BOOL IsProcessDPIAware();

int MapWindowPoints(
    [in] HWND hWndFrom,
    [in] HWND hWndTo,
    [in, out] LPPOINT lpPoints,
    [in] UINT cPoints
);

BOOL UnregisterDeviceNotification(
    [in] HDEVNOTIFY Handle
);

BOOL SystemParametersInfoForDpi(
    [in] UINT uiAction,
    [in] UINT uiParam,
    [in, out] PVOID pvParam,
    [in] UINT fWinIni,
    [in] UINT dpi
);

void IS_POINTER_FIRSTBUTTON_WPARAM(
    wParam
);

BOOL SoundSentry();

HBITMAP LoadBitmapA(
    [in] HINSTANCE hInstance,
    [in] LPCSTR lpBitmapName
);

BOOL DrawIconEx(
    [in] HDC hdc,
    [in] int xLeft,
    [in] int yTop,
    [in] HICON hIcon,
    [in] int cxWidth,
    [in] int cyWidth,
    [in] UINT istepIfAniCur,
    [in, optional] HBRUSH hbrFlickerFreeDraw,
    [in] UINT diFlags
);

LRESULT SendMessage(
    [in] HWND hWnd,
    [in] UINT Msg,
    [in] WPARAM wParam,
    [in] LPARAM lParam
);

BOOL SetUserObjectInformationA(
    [in] HANDLE hObj,
    [in] int nIndex,
    [in] PVOID pvInfo,
    [in] DWORD nLength
);

BOOL UnregisterPowerSettingNotification(
    [in] HPOWERNOTIFY Handle
);

BOOL EnumDisplaySettingsExA(
    [in] LPCSTR lpszDeviceName,
    [in] DWORD iModeNum,
    [out] DEVMODEA *lpDevMode,
    [in] DWORD dwFlags
);

BOOL CallMsgFilterA(
    [in] LPMSG lpMsg,
    [in] int nCode
);

BOOL GetMonitorInfoW(
    [in] HMONITOR hMonitor,
    [out] LPMONITORINFO lpmi
);

long GetDialogBaseUnits();

int GetMouseMovePointsEx(
    [in] UINT cbSize,
    [in] LPMOUSEMOVEPOINT lppt,
    [out] LPMOUSEMOVEPOINT lpptBuf,
    [in] int nBufPoints,
    [in] DWORD resolution
);

BOOL IsCharAlphaNumericW(
    [in] WCHAR ch
);

void GET_KEYSTATE_LPARAM(
    lParam
);

LPARAM GetMessageExtraInfo();

INT_PTR DialogBoxIndirectParamW(
    [in, optional] HINSTANCE hInstance,
    [in] LPCDLGTEMPLATEW hDialogTemplate,
    [in, optional] HWND hWndParent,
    [in, optional] DLGPROC lpDialogFunc,
    [in] LPARAM dwInitParam
);

BOOL OemToCharBuffA(
    [in] LPCSTR lpszSrc,
    [out] LPSTR lpszDst,
    [in] DWORD cchDstLength
);

HDWP BeginDeferWindowPos(
    [in] int nNumWindows
);

BOOL GetPointerType(
    [in] UINT32 pointerId,
    [out] POINTER_INPUT_TYPE *pointerType
);

BOOL EnumDisplaySettingsExW(
    [in] LPCWSTR lpszDeviceName,
    [in] DWORD iModeNum,
    [out] DEVMODEW *lpDevMode,
    [in] DWORD dwFlags
);

int GetWindowTextW(
    [in] HWND hWnd,
    [out] LPWSTR lpString,
    [in] int nMaxCount
);

HWND GetOpenClipboardWindow();

HWND CreateDialogParamW(
    [in, optional] HINSTANCE hInstance,
    [in] LPCWSTR lpTemplateName,
    [in, optional] HWND hWndParent,
    [in, optional] DLGPROC lpDialogFunc,
    [in] LPARAM dwInitParam
);

BOOL GetAltTabInfoW(
    [in, optional] HWND hwnd,
    [in] int iItem,
    [in, out] PALTTABINFO pati,
    [out, optional] LPWSTR pszItemText,
    [in] UINT cchItemText
);

HICON LoadIconW(
    [in, optional] HINSTANCE hInstance,
    [in] LPCWSTR lpIconName
);

LPARAM SetMessageExtraInfo(
    [in] LPARAM lParam
);

BOOL UnregisterPointerInputTarget(
    [in] HWND hwnd,
    [in] POINTER_INPUT_TYPE pointerType
);

BOOL GetProcessDefaultLayout(
    [out] DWORD *pdwDefaultLayout
);

int EnumPropsExA(
    [in] HWND hWnd,
    [in] PROPENUMPROCEXA lpEnumFunc,
    [in] LPARAM lParam
);

UINT GetCaretBlinkTime();

BOOL IsCharUpperW(
    [in] WCHAR ch
);

BOOL ValidateRgn(
    [in] HWND hWnd,
    [in] HRGN hRgn
);

HWINSTA OpenWindowStationA(
    [in] LPCSTR lpszWinSta,
    [in] BOOL fInherit,
    [in] ACCESS_MASK dwDesiredAccess
);

LPWSTR CharLowerW(
    [in, out] LPWSTR lpsz
);

HICON LoadIconA(
    [in, optional] HINSTANCE hInstance,
    [in] LPCSTR lpIconName
);

BOOL SetMenuDefaultItem(
    [in] HMENU hMenu,
    [in] UINT uItem,
    [in] UINT fByPos
);

HWND CreateWindowExW(
    [in] DWORD dwExStyle,
    [in, optional] LPCWSTR lpClassName,
    [in, optional] LPCWSTR lpWindowName,
    [in] DWORD dwStyle,
    [in] int X,
    [in] int Y,
    [in] int nWidth,
    [in] int nHeight,
    [in, optional] HWND hWndParent,
    [in, optional] HMENU hMenu,
    [in, optional] HINSTANCE hInstance,
    [in, optional] LPVOID lpParam
);

BOOL GetAutoRotationState(
    [out] PAR_STATE pState
);

int GetKeyboardLayoutList(
    [in] int nBuff,
    [out] HKL *lpList
);

HWND GetNextDlgTabItem(
    [in] HWND hDlg,
    [in, optional] HWND hCtl,
    [in] BOOL bPrevious
);

LPSTR CharPrevA(
    [in] LPCSTR lpszStart,
    [in] LPCSTR lpszCurrent
);

BOOL GetIconInfo(
    [in] HICON hIcon,
    [out] PICONINFO piconinfo
);

BOOL EqualRect(
    [in] const RECT *lprc1,
    [in] const RECT *lprc2
);

LONG GetDisplayConfigBufferSizes(
    [in] UINT32 flags,
    [out] UINT32 *numPathArrayElements,
    [out] UINT32 *numModeInfoArrayElements
);

BOOL DrawCaption(
    [in] HWND hwnd,
    [in] HDC hdc,
    [in] const RECT *lprect,
    [in] UINT flags
);

void GET_KEYSTATE_WPARAM(
    wParam
);

BOOL SetDlgItemTextA(
    [in] HWND hDlg,
    [in] int nIDDlgItem,
    [in] LPCSTR lpString
);

LPSTR CharPrevExA(
    [in] WORD CodePage,
    [in] LPCSTR lpStart,
    [in] LPCSTR lpCurrentChar,
    [in] DWORD dwFlags
);

int GetWindowRgnBox(
    [in] HWND hWnd,
    [out] LPRECT lprc
);

DWORD WaitForInputIdle(
    [in] HANDLE hProcess,
    [in] DWORD dwMilliseconds
);

BOOL CloseWindow(
    [in] HWND hWnd
);

BOOL IsWow64Message();

ULONG_PTR SetClassLongPtrA(
    [in] HWND hWnd,
    [in] int nIndex,
    [in] LONG_PTR dwNewLong
);

BOOL UnregisterTouchWindow(
    [in] HWND hwnd
);

void SetLastErrorEx(
    [in] DWORD dwErrCode,
    [in] DWORD dwType
);

BOOL IsDialogMessageW(
    [in] HWND hDlg,
    [in] LPMSG lpMsg
);

HWND SetClipboardViewer(
    [in] HWND hWndNewViewer
);

BOOL UpdateLayeredWindow(
    [in] HWND hWnd,
    [in, optional] HDC hdcDst,
    [in, optional] POINT *pptDst,
    [in, optional] SIZE *psize,
    [in, optional] HDC hdcSrc,
    [in, optional] POINT *pptSrc,
    [in] COLORREF crKey,
    [in, optional] BLENDFUNCTION *pblend,
    [in] DWORD dwFlags
);

void GET_FLAGS_LPARAM(
    lParam
);

BOOL GetWindowDisplayAffinity(
    [in] HWND hWnd,
    [out] DWORD *pdwAffinity
);

BOOL OffsetRect(
    [in, out] LPRECT lprc,
    [in] int dx,
    [in] int dy
);

BOOL ChangeWindowMessageFilterEx(
    [in] HWND hwnd,
    [in] UINT message,
    [in] DWORD action,
    [in, out, optional] PCHANGEFILTERSTRUCT pChangeFilterStruct
);

BOOL LogicalToPhysicalPoint(
    [in] HWND hWnd,
    [in, out] LPPOINT lpPoint
);

ATOM RegisterClassA(
    [in] const WNDCLASSA *lpWndClass
);

int DlgDirListComboBoxA(
    [in] HWND hDlg,
    [in, out] LPSTR lpPathSpec,
    [in] int nIDComboBox,
    [in] int nIDStaticPath,
    [in] UINT uFiletype
);

BOOL GetRawPointerDeviceData(
    [in] UINT32 pointerId,
    [in] UINT32 historyCount,
    [in] UINT32 propertiesCount,
    [in] POINTER_DEVICE_PROPERTY *pProperties,
    [out] LONG *pValues
);

BOOL SetScrollRange(
    [in] HWND hWnd,
    [in] int nBar,
    [in] int nMinPos,
    [in] int nMaxPos,
    [in] BOOL bRedraw
);

BOOL EnumWindows(
    [in] WNDENUMPROC lpEnumFunc,
    [in] LPARAM lParam
);

BOOL GetPointerDeviceProperties(
    [in] HANDLE device,
    [in, out] UINT32 *propertyCount,
    [out, optional] POINTER_DEVICE_PROPERTY *pointerProperties
);

HCURSOR LoadCursorFromFileA(
    [in] LPCSTR lpFileName
);

UINT GetDlgItemTextW(
    [in] HWND hDlg,
    [in] int nIDDlgItem,
    [out] LPWSTR lpString,
    [in] int cchMax
);

int GetWindowTextA(
    [in] HWND hWnd,
    [out] LPSTR lpString,
    [in] int nMaxCount
);

