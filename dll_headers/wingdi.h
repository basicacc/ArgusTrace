int GetArcDirection(
    [in] HDC hdc
);

BOOL GetTextExtentPointI(
    [in] HDC hdc,
    [in] LPWORD pgiIn,
    [in] int cgi,
    [out] LPSIZE psize
);

HBITMAP CreateDIBSection(
    [in] HDC hdc,
    [in] const BITMAPINFO *pbmi,
    [in] UINT usage,
    [out] VOID **ppvBits,
    [in] HANDLE hSection,
    [in] DWORD offset
);

BOOL GetCharABCWidthsFloatA(
    [in] HDC hdc,
    [in] UINT iFirst,
    [in] UINT iLast,
    [out] LPABCFLOAT lpABC
);

HBITMAP CreateDiscardableBitmap(
    [in] HDC hdc,
    [in] int cx,
    [in] int cy
);

BOOL GetCharWidth32W(
    [in] HDC hdc,
    [in] UINT iFirst,
    [in] UINT iLast,
    [out] LPINT lpBuffer
);

HDC ResetDCW(
    [in] HDC hdc,
    [in] const DEVMODEW *lpdm
);

UINT GetEnhMetaFileDescriptionA(
    [in] HENHMETAFILE hemf,
    [in] UINT cchBuffer,
    [out] LPSTR lpDescription
);

BOOL Ellipse(
    [in] HDC hdc,
    [in] int left,
    [in] int top,
    [in] int right,
    [in] int bottom
);

HRGN CreateEllipticRgnIndirect(
    [in] const RECT *lprect
);

HENHMETAFILE SetEnhMetaFileBits(
    [in] UINT nSize,
    [in] const BYTE *pb
);

int AddFontResourceW(
    [in] LPCWSTR unnamedParam1
);

BOOL PlayMetaFileRecord(
    [in] HDC hdc,
    [in] LPHANDLETABLE lpHandleTable,
    [in] LPMETARECORD lpMR,
    [in] UINT noObjs
);

BOOL ResizePalette(
    [in] HPALETTE hpal,
    [in] UINT n
);

DWORD GetGlyphIndicesA(
    [in] HDC hdc,
    [in] LPCSTR lpstr,
    [in] int c,
    [out] LPWORD pgi,
    [in] DWORD fl
);

int wglSetLayerPaletteEntries(
    HDC unnamedParam1,
    int unnamedParam2,
    int unnamedParam3,
    int unnamedParam4,
    const COLORREF *unnamedParam5
);

int Escape(
    [in] HDC hdc,
    [in] int iEscape,
    [in] int cjIn,
    [in] LPCSTR pvIn,
    [out] LPVOID pvOut
);

int SetICMMode(
    HDC hdc,
    int mode
);

BOOL ExtTextOutA(
    [in] HDC hdc,
    [in] int x,
    [in] int y,
    [in] UINT options,
    [in] const RECT *lprect,
    [in] LPCSTR lpString,
    [in] UINT c,
    [in] const INT *lpDx
);

BOOL GetCharABCWidthsW(
    [in] HDC hdc,
    [in] UINT wFirst,
    [in] UINT wLast,
    [out] LPABC lpABC
);

int SetMetaRgn(
    [in] HDC hdc
);

BOOL RemoveFontResourceExW(
    [in] LPCWSTR name,
    [in] DWORD fl,
    [in] PVOID pdv
);

HBRUSH CreateHatchBrush(
    [in] int iHatch,
    [in] COLORREF color
);

int GetTextFaceW(
    [in] HDC hdc,
    [in] int c,
    [out] LPWSTR lpName
);

BOOL GetCharWidthW(
    [in] HDC hdc,
    [in] UINT iFirst,
    [in] UINT iLast,
    [out] LPINT lpBuffer
);

int EnumFontFamiliesA(
    [in] HDC hdc,
    [in] LPCSTR lpLogfont,
    [in] FONTENUMPROCA lpProc,
    [in] LPARAM lParam
);

BOOL RoundRect(
    [in] HDC hdc,
    [in] int left,
    [in] int top,
    [in] int right,
    [in] int bottom,
    [in] int width,
    [in] int height
);

HBITMAP CreateCompatibleBitmap(
    [in] HDC hdc,
    [in] int cx,
    [in] int cy
);

int GetTextFaceA(
    [in] HDC hdc,
    [in] int c,
    [out] LPSTR lpName
);

int SetAbortProc(
    [in] HDC hdc,
    [in] ABORTPROC proc
);

BOOL GdiFlush();

int EnumFontsW(
    [in] HDC hdc,
    [in] LPCWSTR lpLogfont,
    [in] FONTENUMPROCW lpProc,
    [in] LPARAM lParam
);

BOOL DeleteObject(
    [in] HGDIOBJ ho
);

UINT SetSystemPaletteUse(
    [in] HDC hdc,
    [in] UINT use
);

COLORREF GetDCBrushColor(
    [in] HDC hdc
);

HRGN ExtCreateRegion(
    [in] const XFORM *lpx,
    [in] DWORD nCount,
    [in] const RGNDATA *lpData
);

int ExcludeClipRect(
    [in] HDC hdc,
    [in] int left,
    [in] int top,
    [in] int right,
    [in] int bottom
);

UINT GetEnhMetaFilePixelFormat(
    HENHMETAFILE hemf,
    UINT cbBuffer,
    PIXELFORMATDESCRIPTOR *ppfd
);

int SetGraphicsMode(
    [in] HDC hdc,
    [in] int iMode
);

BOOL MoveToEx(
    [in] HDC hdc,
    [in] int x,
    [in] int y,
    [out] LPPOINT lppt
);

int GetObjectA(
    HANDLE h,
    int c,
    LPVOID pv
);

DWORD GetGlyphIndicesW(
    [in] HDC hdc,
    [in] LPCWSTR lpstr,
    [in] int c,
    [out] LPWORD pgi,
    [in] DWORD fl
);

HGLRC wglCreateContext(
    HDC unnamedParam1
);

BOOL PolyDraw(
    [in] HDC hdc,
    [in] const POINT *apt,
    [in] const BYTE *aj,
    [in] int cpt
);

BOOL RemoveFontMemResourceEx(
    [in] HANDLE h
);

int SaveDC(
    [in] HDC hdc
);

DWORD GetGlyphOutlineW(
    [in] HDC hdc,
    [in] UINT uChar,
    [in] UINT fuFormat,
    [out] LPGLYPHMETRICS lpgm,
    [in] DWORD cjBuffer,
    [out] LPVOID pvBuffer,
    [in] const MAT2 *lpmat2
);

int DescribePixelFormat(
    HDC hdc,
    int iPixelFormat,
    UINT nBytes,
    LPPIXELFORMATDESCRIPTOR ppfd
);

BOOL GetRasterizerCaps(
    [out] LPRASTERIZER_STATUS lpraststat,
    [in] UINT cjBytes
);

HDC CreateCompatibleDC(
    [in] HDC hdc
);

int SetStretchBltMode(
    [in] HDC hdc,
    [in] int mode
);

BOOL GetTextExtentPoint32W(
    [in] HDC hdc,
    [in] LPCWSTR lpString,
    [in] int c,
    [out] LPSIZE psizl
);

HRGN CreateEllipticRgn(
    [in] int x1,
    [in] int y1,
    [in] int x2,
    [in] int y2
);

HBRUSH CreateDIBPatternBrushPt(
    [in] const VOID *lpPackedDIB,
    [in] UINT iUsage
);

BOOL DeleteMetaFile(
    [in] HMETAFILE hmf
);

HRGN CreatePolygonRgn(
    [in] const POINT *pptl,
    [in] int cPoint,
    [in] int iMode
);

BOOL GetLogColorSpaceW(
    HCOLORSPACE hColorSpace,
    LPLOGCOLORSPACEW lpBuffer,
    DWORD nSize
);

DWORD GetKerningPairsA(
    [in] HDC hdc,
    [in] DWORD nPairs,
    [out] LPKERNINGPAIR lpKernPair
);

BOOL SetICMProfileW(
    HDC hdc,
    LPWSTR lpFileName
);

BOOL DeleteDC(
    [in] HDC hdc
);

BOOL GetCurrentPositionEx(
    [in] HDC hdc,
    [out] LPPOINT lppt
);

int GetRandomRgn(
    [in] HDC hdc,
    [in] HRGN hrgn,
    [in] INT i
);

HRGN CreateRectRgnIndirect(
    [in] const RECT *lprect
);

int SetBkMode(
    [in] HDC hdc,
    [in] int mode
);

COLORREF SetPixel(
    [in] HDC hdc,
    [in] int x,
    [in] int y,
    [in] COLORREF color
);

DWORD GetRegionData(
    [in] HRGN hrgn,
    [in] DWORD nCount,
    [out] LPRGNDATA lpRgnData
);

int GetRgnBox(
    [in] HRGN hrgn,
    [out] LPRECT lprc
);

BOOL FillPath(
    [in] HDC hdc
);

BOOL PaintRgn(
    [in] HDC hdc,
    [in] HRGN hrgn
);

int SetPolyFillMode(
    [in] HDC hdc,
    [in] int mode
);

BOOL SetWindowOrgEx(
    [in] HDC hdc,
    [in] int x,
    [in] int y,
    [out] LPPOINT lppt
);

UINT GetWinMetaFileBits(
    [in] HENHMETAFILE hemf,
    [in] UINT cbData16,
    [out] LPBYTE pData16,
    [in] INT iMapMode,
    [in] HDC hdcRef
);

void MAKEROP4(
    fore,
    back
);

BOOL wglUseFontOutlinesW(
    HDC unnamedParam1,
    DWORD unnamedParam2,
    DWORD unnamedParam3,
    DWORD unnamedParam4,
    FLOAT unnamedParam5,
    FLOAT unnamedParam6,
    int unnamedParam7,
    LPGLYPHMETRICSFLOAT unnamedParam8
);

BOOL wglUseFontBitmapsW(
    HDC unnamedParam1,
    DWORD unnamedParam2,
    DWORD unnamedParam3,
    DWORD unnamedParam4
);

int OffsetClipRgn(
    [in] HDC hdc,
    [in] int x,
    [in] int y
);

BOOL OffsetViewportOrgEx(
    [in] HDC hdc,
    [in] int x,
    [in] int y,
    [out] LPPOINT lppt
);

HDC wglGetCurrentDC();

int StartDocW(
    [in] HDC hdc,
    [in] const DOCINFOW *lpdi
);

BOOL wglUseFontOutlinesA(
    HDC unnamedParam1,
    DWORD unnamedParam2,
    DWORD unnamedParam3,
    DWORD unnamedParam4,
    FLOAT unnamedParam5,
    FLOAT unnamedParam6,
    int unnamedParam7,
    LPGLYPHMETRICSFLOAT unnamedParam8
);

BOOL wglSwapLayerBuffers(
    HDC unnamedParam1,
    UINT unnamedParam2
);

HDC CreateICW(
    [in] LPCWSTR pszDriver,
    [in] LPCWSTR pszDevice,
    LPCWSTR pszPort,
    [in] const DEVMODEW *pdm
);

BOOL GetCharWidthFloatW(
    [in] HDC hdc,
    [in] UINT iFirst,
    [in] UINT iLast,
    [out] PFLOAT lpBuffer
);

BOOL PlayMetaFile(
    [in] HDC hdc,
    [in] HMETAFILE hmf
);

HMETAFILE CopyMetaFileW(
    [in] HMETAFILE unnamedParam1,
    [in] LPCWSTR unnamedParam2
);

BOOL StrokeAndFillPath(
    [in] HDC hdc
);

BOOL wglDeleteContext(
    HGLRC unnamedParam1
);

BOOL GetTextMetricsA(
    [in] HDC hdc,
    [out] LPTEXTMETRICA lptm
);

DWORD GetLayout(
    [in] HDC hdc
);

BOOL AngleArc(
    [in] HDC hdc,
    [in] int x,
    [in] int y,
    [in] DWORD r,
    [in] FLOAT StartAngle,
    [in] FLOAT SweepAngle
);

BOOL GetLogColorSpaceA(
    HCOLORSPACE hColorSpace,
    LPLOGCOLORSPACEA lpBuffer,
    DWORD nSize
);

BOOL GetCharWidthFloatA(
    [in] HDC hdc,
    [in] UINT iFirst,
    [in] UINT iLast,
    [out] PFLOAT lpBuffer
);

BOOL PolyBezierTo(
    [in] HDC hdc,
    [in] const POINT *apt,
    [in] DWORD cpt
);

BOOL SelectClipPath(
    [in] HDC hdc,
    [in] int mode
);

HMETAFILE GetMetaFileW(
    [in] LPCWSTR lpName
);

BOOL Arc(
    [in] HDC hdc,
    [in] int x1,
    [in] int y1,
    [in] int x2,
    [in] int y2,
    [in] int x3,
    [in] int y3,
    [in] int x4,
    [in] int y4
);

COLORREF SetDCPenColor(
    [in] HDC hdc,
    [in] COLORREF color
);

HENHMETAFILE CopyEnhMetaFileW(
    [in] HENHMETAFILE hEnh,
    [in] LPCWSTR lpFileName
);

int GetMetaRgn(
    [in] HDC hdc,
    [in] HRGN hrgn
);

BOOL WidenPath(
    [in] HDC hdc
);

HDC ResetDCA(
    [in] HDC hdc,
    [in] const DEVMODEA *lpdm
);

int EnumICMProfilesA(
    HDC hdc,
    ICMENUMPROCA proc,
    LPARAM param
);

BOOL SetTextJustification(
    [in] HDC hdc,
    [in] int extra,
    [in] int count
);

UINT GetMetaFileBitsEx(
    [in] HMETAFILE hMF,
    [in] UINT cbBuffer,
    [out] LPVOID lpData
);

UINT RealizePalette(
    [in] HDC hdc
);

BOOL GetBrushOrgEx(
    [in] HDC hdc,
    [out] LPPOINT lppt
);

BOOL GetBitmapDimensionEx(
    [in] HBITMAP hbit,
    [out] LPSIZE lpsize
);

int SetDIBits(
    [in] HDC hdc,
    [in] HBITMAP hbm,
    [in] UINT start,
    [in] UINT cLines,
    [in] const VOID *lpBits,
    [in] const BITMAPINFO *lpbmi,
    [in] UINT ColorUse
);

COLORREF SetTextColor(
    [in] HDC hdc,
    [in] COLORREF color
);

BOOL UpdateColors(
    [in] HDC hdc
);

BOOL SetWorldTransform(
    [in] HDC hdc,
    [in] const XFORM *lpxf
);

BOOL DPtoLP(
    [in] HDC hdc,
    [in, out] LPPOINT lppt,
    [in] int c
);

int GetROP2(
    [in] HDC hdc
);

BOOL PlayEnhMetaFileRecord(
    [in] HDC hdc,
    [in] LPHANDLETABLE pht,
    [in] const ENHMETARECORD *pmr,
    [in] UINT cht
);

UINT GetEnhMetaFileDescriptionW(
    [in] HENHMETAFILE hemf,
    [in] UINT cchBuffer,
    [out] LPWSTR lpDescription
);

BOOL wglShareLists(
    HGLRC unnamedParam1,
    HGLRC unnamedParam2
);

BOOL LineTo(
    [in] HDC hdc,
    [in] int x,
    [in] int y
);

UINT GetTextAlign(
    [in] HDC hdc
);

void PALETTERGB(
    r,
    g,
    b
);

int SetArcDirection(
    [in] HDC hdc,
    [in] int dir
);

BOOL BeginPath(
    [in] HDC hdc
);

UINT SetPaletteEntries(
    [in] HPALETTE hpal,
    [in] UINT iStart,
    [in] UINT cEntries,
    [in] const PALETTEENTRY *pPalEntries
);

BOOL ScaleViewportExtEx(
    [in] HDC hdc,
    [in] int xn,
    [in] int dx,
    [in] int yn,
    [in] int yd,
    [out] LPSIZE lpsz
);

int wglGetLayerPaletteEntries(
    HDC unnamedParam1,
    int unnamedParam2,
    int unnamedParam3,
    int unnamedParam4,
    COLORREF *unnamedParam5
);

int SetROP2(
    [in] HDC hdc,
    [in] int rop2
);

HRGN PathToRegion(
    [in] HDC hdc
);

BOOL StretchBlt(
    [in] HDC hdcDest,
    [in] int xDest,
    [in] int yDest,
    [in] int wDest,
    [in] int hDest,
    [in] HDC hdcSrc,
    [in] int xSrc,
    [in] int ySrc,
    [in] int wSrc,
    [in] int hSrc,
    [in] DWORD rop
);

BOOL PatBlt(
    [in] HDC hdc,
    [in] int x,
    [in] int y,
    [in] int w,
    [in] int h,
    [in] DWORD rop
);

BOOL TransparentBlt(
    [in] HDC hdcDest,
    [in] int xoriginDest,
    [in] int yoriginDest,
    [in] int wDest,
    [in] int hDest,
    [in] HDC hdcSrc,
    [in] int xoriginSrc,
    [in] int yoriginSrc,
    [in] int wSrc,
    [in] int hSrc,
    [in] UINT crTransparent
);

int GetClipBox(
    [in] HDC hdc,
    [out] LPRECT lprect
);

BOOL EndPath(
    [in] HDC hdc
);

int EnumICMProfilesW(
    HDC hdc,
    ICMENUMPROCW proc,
    LPARAM param
);

BOOL DeleteEnhMetaFile(
    [in] HENHMETAFILE hmf
);

BOOL FlattenPath(
    [in] HDC hdc
);

UINT SetDIBColorTable(
    [in] HDC hdc,
    [in] UINT iStart,
    [in] UINT cEntries,
    [in] const RGBQUAD *prgbq
);

BOOL GetTextExtentPointA(
    [in] HDC hdc,
    [in] LPCSTR lpString,
    [in] int c,
    [out] LPSIZE lpsz
);

BOOL PolyBezier(
    [in] HDC hdc,
    [in] const POINT *apt,
    [in] DWORD cpt
);

BOOL PolyPolygon(
    [in] HDC hdc,
    [in] const POINT *apt,
    [in] const INT *asz,
    [in] int csz
);

BOOL wglMakeCurrent(
    HDC unnamedParam1,
    HGLRC unnamedParam2
);

void RGB(
    r,
    g,
    b
);

BOOL GetViewportExtEx(
    [in] HDC hdc,
    [out] LPSIZE lpsize
);

HENHMETAFILE GetEnhMetaFileW(
    [in] LPCWSTR lpName
);

BOOL GetViewportOrgEx(
    [in] HDC hdc,
    [out] LPPOINT lppoint
);

BOOL PolyTextOutW(
    [in] HDC hdc,
    [in] const POLYTEXTW *ppt,
    [in] int nstrings
);

BOOL ModifyWorldTransform(
    [in] HDC hdc,
    [in] const XFORM *lpxf,
    [in] DWORD mode
);

BOOL CreateScalableFontResourceA(
    [in] DWORD fdwHidden,
    [in] LPCSTR lpszFont,
    [in] LPCSTR lpszFile,
    [in] LPCSTR lpszPath
);

BOOL UnrealizeObject(
    HGDIOBJ h
);

HDC CreateICA(
    [in] LPCSTR pszDriver,
    [in] LPCSTR pszDevice,
    LPCSTR pszPort,
    [in] const DEVMODEA *pdm
);

BOOL TextOutA(
    [in] HDC hdc,
    [in] int x,
    [in] int y,
    [in] LPCSTR lpString,
    [in] int c
);

HFONT CreateFontIndirectExW(
    [in] const ENUMLOGFONTEXDVW *unnamedParam1
);

BOOL GetCharWidth32A(
    [in] HDC hdc,
    [in] UINT iFirst,
    [in] UINT iLast,
    [out] LPINT lpBuffer
);

BOOL SetViewportExtEx(
    [in] HDC hdc,
    [in] int x,
    [in] int y,
    [out] LPSIZE lpsz
);

BOOL GradientFill(
    [in] HDC hdc,
    [in] PTRIVERTEX pVertex,
    [in] ULONG nVertex,
    [in] PVOID pMesh,
    [in] ULONG nMesh,
    [in] ULONG ulMode
);

HMETAFILE SetMetaFileBitsEx(
    [in] UINT cbBuffer,
    [in] const BYTE *lpData
);

BOOL GetICMProfileW(
    HDC hdc,
    LPDWORD pBufSize,
    LPWSTR pszFilename
);

int SetMapMode(
    [in] HDC hdc,
    [in] int iMode
);

HPALETTE SelectPalette(
    [in] HDC hdc,
    [in] HPALETTE hPal,
    [in] BOOL bForceBkgd
);

void GetCValue(
    cmyk
);

int GetMapMode(
    [in] HDC hdc
);

DWORD GetFontLanguageInfo(
    [in] HDC hdc
);

DWORD GdiSetBatchLimit(
    [in] DWORD dw
);

BOOL StrokePath(
    [in] HDC hdc
);

HPALETTE CreateHalftonePalette(
    [in] HDC hdc
);

void MAKEPOINTS(
    l
);

BOOL Chord(
    [in] HDC hdc,
    [in] int x1,
    [in] int y1,
    [in] int x2,
    [in] int y2,
    [in] int x3,
    [in] int y3,
    [in] int x4,
    [in] int y4
);

BOOL UpdateICMRegKeyA(
    DWORD reserved,
    LPSTR lpszCMID,
    LPSTR lpszFileName,
    UINT command
);

HGDIOBJ GetStockObject(
    [in] int i
);

UINT GetBoundsRect(
    [in] HDC hdc,
    [out] LPRECT lprect,
    [in] UINT flags
);

BOOL SetColorAdjustment(
    [in] HDC hdc,
    [in] const COLORADJUSTMENT *lpca
);

int EnumFontsA(
    [in] HDC hdc,
    [in] LPCSTR lpLogfont,
    [in] FONTENUMPROCA lpProc,
    [in] LPARAM lParam
);

BOOL GetTextExtentExPointI(
    [in] HDC hdc,
    [in] LPWORD lpwszString,
    [in] int cwchString,
    [in] int nMaxExtent,
    [out] LPINT lpnFit,
    [out] LPINT lpnDx,
    [out] LPSIZE lpSize
);

BOOL GetTextExtentExPointW(
    [in] HDC hdc,
    [in] LPCWSTR lpszString,
    [in] int cchString,
    [in] int nMaxExtent,
    [out] LPINT lpnFit,
    [out] LPINT lpnDx,
    [out] LPSIZE lpSize
);

HBITMAP CreateDIBitmap(
    [in] HDC hdc,
    [in] const BITMAPINFOHEADER *pbmih,
    [in] DWORD flInit,
    [in] const VOID *pjBits,
    [in] const BITMAPINFO *pbmi,
    [in] UINT iUsage
);

BOOL PolyPolyline(
    [in] HDC hdc,
    [in] const POINT *apt,
    [in] const DWORD *asz,
    [in] DWORD csz
);

BOOL GetColorAdjustment(
    [in] HDC hdc,
    [out] LPCOLORADJUSTMENT lpca
);

HCOLORSPACE SetColorSpace(
    HDC hdc,
    HCOLORSPACE hcs
);

DWORD GetCharacterPlacementA(
    [in] HDC hdc,
    [in] LPCSTR lpString,
    [in] int nCount,
    [in] int nMexExtent,
    [in, out] LPGCP_RESULTSA lpResults,
    [in] DWORD dwFlags
);

BOOL CloseFigure(
    [in] HDC hdc
);

HPEN ExtCreatePen(
    [in] DWORD iPenStyle,
    [in] DWORD cWidth,
    [in] const LOGBRUSH *plbrush,
    [in] DWORD cStyle,
    [in] const DWORD *pstyle
);

int SetDIBitsToDevice(
    [in] HDC hdc,
    [in] int xDest,
    [in] int yDest,
    [in] DWORD w,
    [in] DWORD h,
    [in] int xSrc,
    [in] int ySrc,
    [in] UINT StartScan,
    [in] UINT cLines,
    [in] const VOID *lpvBits,
    [in] const BITMAPINFO *lpbmi,
    [in] UINT ColorUse
);

int GetPath(
    [in] HDC hdc,
    [out] LPPOINT apt,
    [out] LPBYTE aj,
    [in] int cpt
);

int GetPolyFillMode(
    [in] HDC hdc
);

HBRUSH CreateDIBPatternBrush(
    [in] HGLOBAL h,
    [in] UINT iUsage
);

int StartDocA(
    [in] HDC hdc,
    [in] const DOCINFOA *lpdi
);

int GetBkMode(
    [in] HDC hdc
);

BOOL SetMiterLimit(
    [in] HDC hdc,
    [in] FLOAT limit,
    [out] PFLOAT old
);

BOOL SetRectRgn(
    [in] HRGN hrgn,
    [in] int left,
    [in] int top,
    [in] int right,
    [in] int bottom
);

int GetPixelFormat(
    HDC hdc
);

int GetDIBits(
    [in] HDC hdc,
    [in] HBITMAP hbm,
    [in] UINT start,
    [in] UINT cLines,
    [out] LPVOID lpvBits,
    [in, out] LPBITMAPINFO lpbmi,
    [in] UINT usage
);

BOOL MaskBlt(
    [in] HDC hdcDest,
    [in] int xDest,
    [in] int yDest,
    [in] int width,
    [in] int height,
    [in] HDC hdcSrc,
    [in] int xSrc,
    [in] int ySrc,
    [in] HBITMAP hbmMask,
    [in] int xMask,
    [in] int yMask,
    [in] DWORD rop
);

DWORD GetCharacterPlacementW(
    [in] HDC hdc,
    [in] LPCWSTR lpString,
    [in] int nCount,
    [in] int nMexExtent,
    [in, out] LPGCP_RESULTSW lpResults,
    [in] DWORD dwFlags
);

BOOL GetTextMetricsW(
    [in] HDC hdc,
    [out] LPTEXTMETRICW lptm
);

BOOL SetBitmapDimensionEx(
    [in] HBITMAP hbm,
    [in] int w,
    [in] int h,
    [out] LPSIZE lpsz
);

HANDLE AddFontMemResourceEx(
    [in] PVOID pFileView,
    [in] DWORD cjSize,
    [in] PVOID pvResrved,
    [in] DWORD *pNumFonts
);

UINT GetOutlineTextMetricsA(
    [in] HDC hdc,
    [in] UINT cjCopy,
    [out, optional] LPOUTLINETEXTMETRICA potm
);

int DeviceCapabilitiesW(
    [in] LPCWSTR pDevice,
    [in] LPCWSTR pPort,
    [in] WORD fwCapability,
    [out] LPWSTR pOutput,
    [in] const DEVMODEW *pDevMode
);

COLORREF GetTextColor(
    [in] HDC hdc
);

int IntersectClipRect(
    [in] HDC hdc,
    [in] int left,
    [in] int top,
    [in] int right,
    [in] int bottom
);

BOOL GetCharABCWidthsA(
    [in] HDC hdc,
    [in] UINT wFirst,
    [in] UINT wLast,
    [out] LPABC lpABC
);

UINT GetOutlineTextMetricsW(
    [in] HDC hdc,
    [in] UINT cjCopy,
    [out, optional] LPOUTLINETEXTMETRICW potm
);

COLORREF SetBkColor(
    [in] HDC hdc,
    [in] COLORREF color
);

BOOL SwapBuffers(
    HDC unnamedParam1
);

BOOL ArcTo(
    [in] HDC hdc,
    [in] int left,
    [in] int top,
    [in] int right,
    [in] int bottom,
    [in] int xr1,
    [in] int yr1,
    [in] int xr2,
    [in] int yr2
);

BOOL PlayEnhMetaFile(
    [in] HDC hdc,
    [in] HENHMETAFILE hmf,
    [in] const RECT *lprect
);

BOOL PlgBlt(
    [in] HDC hdcDest,
    [in] const POINT *lpPoint,
    [in] HDC hdcSrc,
    [in] int xSrc,
    [in] int ySrc,
    [in] int width,
    [in] int height,
    [in] HBITMAP hbmMask,
    [in] int xMask,
    [in] int yMask
);

DWORD SetLayout(
    [in] HDC hdc,
    [in] DWORD l
);

BOOL RemoveFontResourceExA(
    [in] LPCSTR name,
    [in] DWORD fl,
    [in] PVOID pdv
);

int EndPage(
    [in] HDC hdc
);

BOOL OffsetWindowOrgEx(
    [in] HDC hdc,
    [in] int x,
    [in] int y,
    [out] LPPOINT lppt
);

DWORD SetMapperFlags(
    [in] HDC hdc,
    [in] DWORD flags
);

HMETAFILE GetMetaFileA(
    [in] LPCSTR lpName
);

BOOL GetDCOrgEx(
    [in] HDC hdc,
    [out] LPPOINT lppt
);

BOOL CreateScalableFontResourceW(
    [in] DWORD fdwHidden,
    [in] LPCWSTR lpszFont,
    [in] LPCWSTR lpszFile,
    [in] LPCWSTR lpszPath
);

BOOL GetCharWidthI(
    [in] HDC hdc,
    [in] UINT giFirst,
    [in] UINT cgi,
    [in] LPWORD pgi,
    [out] LPINT piWidths
);

BOOL AlphaBlend(
    [in] HDC hdcDest,
    [in] int xoriginDest,
    [in] int yoriginDest,
    [in] int wDest,
    [in] int hDest,
    [in] HDC hdcSrc,
    [in] int xoriginSrc,
    [in] int yoriginSrc,
    [in] int wSrc,
    [in] int hSrc,
    [in] BLENDFUNCTION ftn
);

int GetObject(
    [in] HANDLE h,
    [in] int c,
    [out] LPVOID pv
);

BOOL ColorMatchToTarget(
    HDC hdc,
    HDC hdcTarget,
    DWORD action
);

BOOL GetDeviceGammaRamp(
    HDC hdc,
    LPVOID lpRamp
);

int AddFontResourceExW(
    [in] LPCWSTR name,
    [in] DWORD fl,
    [in] PVOID res
);

BOOL wglCopyContext(
    HGLRC unnamedParam1,
    HGLRC unnamedParam2,
    UINT unnamedParam3
);

BOOL RectInRegion(
    [in] HRGN hrgn,
    [in] const RECT *lprect
);

COLORREF GetDCPenColor(
    [in] HDC hdc
);

BOOL EnumEnhMetaFile(
    [in] HDC hdc,
    [in] HENHMETAFILE hmf,
    [in] ENHMFENUMPROC proc,
    [in] LPVOID param,
    [in] const RECT *lpRect
);

HCOLORSPACE GetColorSpace(
    HDC hdc
);

BOOL PtVisible(
    [in] HDC hdc,
    [in] int x,
    [in] int y
);

BOOL SetPixelV(
    [in] HDC hdc,
    [in] int x,
    [in] int y,
    [in] COLORREF color
);

int AbortDoc(
    [in] HDC hdc
);

BOOL PtInRegion(
    [in] HRGN hrgn,
    [in] int x,
    [in] int y
);

LONG SetBitmapBits(
    [in] HBITMAP hbm,
    [in] DWORD cb,
    [in] const VOID *pvBits
);

BOOL GetMiterLimit(
    [in] HDC hdc,
    [out] PFLOAT plimit
);

HPEN CreatePenIndirect(
    [in] const LOGPEN *plpen
);

void PALETTEINDEX(
    i
);

BOOL AnimatePalette(
    [in] HPALETTE hPal,
    [in] UINT iStartIndex,
    [in] UINT cEntries,
    [in] const PALETTEENTRY *ppe
);

BOOL GdiGradientFill(
    [in] HDC hdc,
    [in] PTRIVERTEX pVertex,
    [in] ULONG nVertex,
    [in] PVOID pMesh,
    [in] ULONG nCount,
    [in] ULONG ulMode
);

int DrawEscape(
    [in] HDC hdc,
    [in] int iEscape,
    [in] int cjIn,
    [in] LPCSTR lpIn
);

COLORREF GetNearestColor(
    [in] HDC hdc,
    [in] COLORREF color
);

BOOL GetCharWidthA(
    [in] HDC hdc,
    [in] UINT iFirst,
    [in] UINT iLast,
    [out] LPINT lpBuffer
);

int ExtEscape(
    [in] HDC hdc,
    [in] int iEscape,
    [in] int cjInput,
    [in] LPCSTR lpInData,
    [in] int cjOutput,
    [out] LPSTR lpOutData
);

UINT GetEnhMetaFilePaletteEntries(
    [in] HENHMETAFILE hemf,
    [in] UINT nNumEntries,
    [out] LPPALETTEENTRY lpPaletteEntries
);

HFONT CreateFontIndirectA(
    [in] const LOGFONTA *lplf
);

BOOL LPtoDP(
    [in] HDC hdc,
    [in, out] LPPOINT lppt,
    [in] int c
);

HPEN CreatePen(
    [in] int iStyle,
    [in] int cWidth,
    [in] COLORREF color
);

UINT GetSystemPaletteEntries(
    [in] HDC hdc,
    [in] UINT iStart,
    [in] UINT cEntries,
    [out] LPPALETTEENTRY pPalEntries
);

HPALETTE CreatePalette(
    [in] const LOGPALETTE *plpal
);

void GetRValue(
    rgb
);

int ChoosePixelFormat(
    HDC hdc,
    const PIXELFORMATDESCRIPTOR *ppfd
);

BOOL GetTextExtentPointW(
    [in] HDC hdc,
    [in] LPCWSTR lpString,
    [in] int c,
    [out] LPSIZE lpsz
);

BOOL GdiAlphaBlend(
    [in] HDC hdcDest,
    [in] int xoriginDest,
    [in] int yoriginDest,
    [in] int wDest,
    [in] int hDest,
    [in] HDC hdcSrc,
    [in] int xoriginSrc,
    [in] int yoriginSrc,
    [in] int wSrc,
    [in] int hSrc,
    [in] BLENDFUNCTION ftn
);

UINT GetDIBColorTable(
    [in] HDC hdc,
    [in] UINT iStart,
    [in] UINT cEntries,
    [out] RGBQUAD *prgbq
);

int GetStretchBltMode(
    [in] HDC hdc
);

BOOL SetICMProfileA(
    HDC hdc,
    LPSTR lpFileName
);

BOOL GetICMProfileA(
    HDC hdc,
    LPDWORD pBufSize,
    LPSTR pszFilename
);

HCOLORSPACE CreateColorSpaceA(
    LPLOGCOLORSPACEA lplcs
);

int SelectClipRgn(
    [in] HDC hdc,
    [in] HRGN hrgn
);

HENHMETAFILE SetWinMetaFileBits(
    [in] UINT nSize,
    [in] const BYTE *lpMeta16Data,
    [in] HDC hdcRef,
    [in] const METAFILEPICT *lpMFP
);

UINT SetBoundsRect(
    [in] HDC hdc,
    [in] const RECT *lprect,
    [in] UINT flags
);

DWORD GetObjectType(
    [in] HGDIOBJ h
);

BOOL BitBlt(
    [in] HDC hdc,
    [in] int x,
    [in] int y,
    [in] int cx,
    [in] int cy,
    [in] HDC hdcSrc,
    [in] int x1,
    [in] int y1,
    [in] DWORD rop
);

BOOL EnumMetaFile(
    [in] HDC hdc,
    [in] HMETAFILE hmf,
    [in] MFENUMPROC proc,
    [in] LPARAM param
);

HGLRC wglGetCurrentContext();

int EndDoc(
    [in] HDC hdc
);

BOOL GetTextMetrics(
    [in] HDC hdc,
    [out] LPTEXTMETRIC lptm
);

BOOL GetTextExtentExPointA(
    [in] HDC hdc,
    [in] LPCSTR lpszString,
    [in] int cchString,
    [in] int nMaxExtent,
    [out] LPINT lpnFit,
    [out] LPINT lpnDx,
    [out] LPSIZE lpSize
);

BOOL SetPixelFormat(
    HDC hdc,
    int format,
    const PIXELFORMATDESCRIPTOR *ppfd
);

int AddFontResourceExA(
    [in] LPCSTR name,
    [in] DWORD fl,
    [in] PVOID res
);

BOOL CheckColorsInGamut(
    HDC hdc,
    LPRGBTRIPLE lpRGBTriple,
    LPVOID dlpBuffer,
    DWORD nCount
);

HDC CreateEnhMetaFileW(
    [in] HDC hdc,
    [in] LPCWSTR lpFilename,
    [in] const RECT *lprc,
    [in] LPCWSTR lpDesc
);

HENHMETAFILE CopyEnhMetaFileA(
    [in] HENHMETAFILE hEnh,
    [in] LPCSTR lpFileName
);

BOOL Polyline(
    [in] HDC hdc,
    [in] const POINT *apt,
    [in] int cpt
);

BOOL AbortPath(
    [in] HDC hdc
);

BOOL RestoreDC(
    [in] HDC hdc,
    [in] int nSavedDC
);

HDC CreateDCW(
    LPCWSTR pwszDriver,
    [in] LPCWSTR pwszDevice,
    LPCWSTR pszPort,
    [in] const DEVMODEW *pdm
);

HGDIOBJ GetCurrentObject(
    [in] HDC hdc,
    [in] UINT type
);

HRGN CreatePolyPolygonRgn(
    [in] const POINT *pptl,
    [in] const INT *pc,
    [in] int cPoly,
    [in] int iMode
);

HRGN CreateRectRgn(
    [in] int x1,
    [in] int y1,
    [in] int x2,
    [in] int y2
);

DWORD GetGlyphOutlineA(
    [in] HDC hdc,
    [in] UINT uChar,
    [in] UINT fuFormat,
    [out] LPGLYPHMETRICS lpgm,
    [in] DWORD cjBuffer,
    [out] LPVOID pvBuffer,
    [in] const MAT2 *lpmat2
);

int GetClipRgn(
    [in] HDC hdc,
    [in] HRGN hrgn
);

BOOL GetCharABCWidthsFloatW(
    [in] HDC hdc,
    [in] UINT iFirst,
    [in] UINT iLast,
    [out] LPABCFLOAT lpABC
);

HFONT CreateFontW(
    [in] int cHeight,
    [in] int cWidth,
    [in] int cEscapement,
    [in] int cOrientation,
    [in] int cWeight,
    [in] DWORD bItalic,
    [in] DWORD bUnderline,
    [in] DWORD bStrikeOut,
    [in] DWORD iCharSet,
    [in] DWORD iOutPrecision,
    [in] DWORD iClipPrecision,
    [in] DWORD iQuality,
    [in] DWORD iPitchAndFamily,
    [in] LPCWSTR pszFaceName
);

UINT GetEnhMetaFileHeader(
    [in] HENHMETAFILE hemf,
    [in] UINT nSize,
    [out] LPENHMETAHEADER lpEnhMetaHeader
);

HENHMETAFILE CloseEnhMetaFile(
    [in] HDC hdc
);

BOOL Polygon(
    [in] HDC hdc,
    [in] const POINT *apt,
    [in] int cpt
);

UINT GetSystemPaletteUse(
    [in] HDC hdc
);

HDC CreateEnhMetaFileA(
    [in] HDC hdc,
    [in] LPCSTR lpFilename,
    [in] const RECT *lprc,
    [in] LPCSTR lpDesc
);

HDC CreateMetaFileW(
    [in] LPCWSTR pszFile
);

DWORD GetFontData(
    [in] HDC hdc,
    [in] DWORD dwTable,
    [in] DWORD dwOffset,
    [out] PVOID pvBuffer,
    [in] DWORD cjBuffer
);

BOOL RemoveFontResourceW(
    [in] LPCWSTR lpFileName
);

int SetTextCharacterExtra(
    [in] HDC hdc,
    [in] int extra
);

HDC CreateDCA(
    LPCSTR pwszDriver,
    [in] LPCSTR pwszDevice,
    LPCSTR pszPort,
    [in] const DEVMODEA *pdm
);

BOOL GetWorldTransform(
    [in] HDC hdc,
    [out] LPXFORM lpxf
);

BOOL Pie(
    [in] HDC hdc,
    [in] int left,
    [in] int top,
    [in] int right,
    [in] int bottom,
    [in] int xr1,
    [in] int yr1,
    [in] int xr2,
    [in] int yr2
);

int GetTextCharsetInfo(
    [in] HDC hdc,
    [out, optional] LPFONTSIGNATURE lpSig,
    [in] DWORD dwFlags
);

int GetGraphicsMode(
    [in] HDC hdc
);

void GetMValue(
    cmyk
);

BOOL wglDescribeLayerPlane(
    HDC unnamedParam1,
    int unnamedParam2,
    int unnamedParam3,
    UINT unnamedParam4,
    LPLAYERPLANEDESCRIPTOR unnamedParam5
);

BOOL TextOutW(
    [in] HDC hdc,
    [in] int x,
    [in] int y,
    [in] LPCWSTR lpString,
    [in] int c
);

BOOL GetWindowOrgEx(
    [in] HDC hdc,
    [out] LPPOINT lppoint
);

BOOL GetAspectRatioFilterEx(
    [in] HDC hdc,
    [out] LPSIZE lpsize
);

BOOL FillRgn(
    [in] HDC hdc,
    [in] HRGN hrgn,
    [in] HBRUSH hbr
);

BOOL SetBrushOrgEx(
    [in] HDC hdc,
    [in] int x,
    [in] int y,
    [out] LPPOINT lppt
);

int GetTextCharset(
    [in] HDC hdc
);

int EnumFontFamiliesExA(
    [in] HDC hdc,
    [in] LPLOGFONTA lpLogfont,
    [in] FONTENUMPROCA lpProc,
    [in] LPARAM lParam,
    DWORD dwFlags
);

HFONT CreateFontIndirectExA(
    [in] const ENUMLOGFONTEXDVA *unnamedParam1
);

HBRUSH CreateBrushIndirect(
    [in] const LOGBRUSH *plbrush
);

int EnumFontFamiliesExW(
    [in] HDC hdc,
    [in] LPLOGFONTW lpLogfont,
    [in] FONTENUMPROCW lpProc,
    [in] LPARAM lParam,
    DWORD dwFlags
);

int StartPage(
    [in] HDC hdc
);

LONG GetBitmapBits(
    [in] HBITMAP hbit,
    [in] LONG cb,
    [out] LPVOID lpvBits
);

void GetKValue(
    cmyk
);

UINT GetPaletteEntries(
    [in] HPALETTE hpal,
    [in] UINT iStart,
    [in] UINT cEntries,
    [out] LPPALETTEENTRY pPalEntries
);

BOOL GetWindowExtEx(
    [in] HDC hdc,
    [out] LPSIZE lpsize
);

HFONT CreateFontIndirectW(
    [in] const LOGFONTW *lplf
);

BOOL CombineTransform(
    [out] LPXFORM lpxfOut,
    [in] const XFORM *lpxf1,
    [in] const XFORM *lpxf2
);

HGLRC wglCreateLayerContext(
    HDC unnamedParam1,
    int unnamedParam2
);

BOOL EqualRgn(
    [in] HRGN hrgn1,
    [in] HRGN hrgn2
);

BOOL PolylineTo(
    [in] HDC hdc,
    [in] const POINT *apt,
    [in] DWORD cpt
);

HDC CreateMetaFileA(
    [in] LPCSTR pszFile
);

BOOL FloodFill(
    [in] HDC hdc,
    [in] int x,
    [in] int y,
    [in] COLORREF color
);

HGDIOBJ SelectObject(
    [in] HDC hdc,
    [in] HGDIOBJ h
);

BOOL Rectangle(
    [in] HDC hdc,
    [in] int left,
    [in] int top,
    [in] int right,
    [in] int bottom
);

BOOL ExtFloodFill(
    [in] HDC hdc,
    [in] int x,
    [in] int y,
    [in] COLORREF color,
    [in] UINT type
);

HENHMETAFILE GetEnhMetaFileA(
    [in] LPCSTR lpName
);

BOOL SetViewportOrgEx(
    [in] HDC hdc,
    [in] int x,
    [in] int y,
    [out] LPPOINT lppt
);

BOOL UpdateICMRegKeyW(
    DWORD reserved,
    LPWSTR lpszCMID,
    LPWSTR lpszFileName,
    UINT command
);

BOOL RectVisible(
    [in] HDC hdc,
    [in] const RECT *lprect
);

BOOL LineDDA(
    [in] int xStart,
    [in] int yStart,
    [in] int xEnd,
    [in] int yEnd,
    [in] LINEDDAPROC lpProc,
    [in] LPARAM data
);

PROC wglGetProcAddress(
    LPCSTR unnamedParam1
);

DWORD GetFontUnicodeRanges(
    [in] HDC hdc,
    [out] LPGLYPHSET lpgs
);

BOOL GdiTransparentBlt(
    [in] HDC hdcDest,
    [in] int xoriginDest,
    [in] int yoriginDest,
    [in] int wDest,
    [in] int hDest,
    [in] HDC hdcSrc,
    [in] int xoriginSrc,
    [in] int yoriginSrc,
    [in] int wSrc,
    [in] int hSrc,
    [in] UINT crTransparent
);

BOOL ScaleWindowExtEx(
    [in] HDC hdc,
    [in] int xn,
    [in] int xd,
    [in] int yn,
    [in] int yd,
    [out] LPSIZE lpsz
);

HRGN CreateRoundRectRgn(
    [in] int x1,
    [in] int y1,
    [in] int x2,
    [in] int y2,
    [in] int w,
    [in] int h
);

int StretchDIBits(
    [in] HDC hdc,
    [in] int xDest,
    [in] int yDest,
    [in] int DestWidth,
    [in] int DestHeight,
    [in] int xSrc,
    [in] int ySrc,
    [in] int SrcWidth,
    [in] int SrcHeight,
    [in] const VOID *lpBits,
    [in] const BITMAPINFO *lpbmi,
    [in] UINT iUsage,
    [in] DWORD rop
);

BOOL ExtTextOutW(
    [in] HDC hdc,
    [in] int x,
    [in] int y,
    [in] UINT options,
    [in] const RECT *lprect,
    [in] LPCWSTR lpString,
    [in] UINT c,
    [in] const INT *lpDx
);

HMETAFILE CloseMetaFile(
    [in] HDC hdc
);

int GetObjectW(
    HANDLE h,
    int c,
    LPVOID pv
);

int OffsetRgn(
    [in] HRGN hrgn,
    [in] int x,
    [in] int y
);

BOOL wglUseFontBitmapsA(
    HDC unnamedParam1,
    DWORD unnamedParam2,
    DWORD unnamedParam3,
    DWORD unnamedParam4
);

HCOLORSPACE CreateColorSpaceW(
    LPLOGCOLORSPACEW lplcs
);

BOOL InvertRgn(
    [in] HDC hdc,
    [in] HRGN hrgn
);

int CombineRgn(
    [in] HRGN hrgnDst,
    [in] HRGN hrgnSrc1,
    [in] HRGN hrgnSrc2,
    [in] int iMode
);

void GetBValue(
    rgb
);

void CMYK(
    c,
    m,
    y,
    k
);

DWORD GetKerningPairsW(
    [in] HDC hdc,
    [in] DWORD nPairs,
    [out] LPKERNINGPAIR lpKernPair
);

UINT GetNearestPaletteIndex(
    [in] HPALETTE h,
    [in] COLORREF color
);

BOOL TranslateCharsetInfo(
    [in, out] DWORD *lpSrc,
    [out] LPCHARSETINFO lpCs,
    [in] DWORD dwFlags
);

BOOL GetTextExtentPoint32A(
    [in] HDC hdc,
    [in] LPCSTR lpString,
    [in] int c,
    [out] LPSIZE psizl
);

BOOL GetCharABCWidthsI(
    [in] HDC hdc,
    [in] UINT giFirst,
    [in] UINT cgi,
    [in] LPWORD pgi,
    [out] LPABC pabc
);

DWORD GdiGetBatchLimit();

int GetDeviceCaps(
    [in] HDC hdc,
    [in] int index
);

BOOL RemoveFontResourceA(
    [in] LPCSTR lpFileName
);

BOOL wglRealizeLayerPalette(
    HDC unnamedParam1,
    int unnamedParam2,
    BOOL unnamedParam3
);

COLORREF GetPixel(
    [in] HDC hdc,
    [in] int x,
    [in] int y
);

UINT SetTextAlign(
    [in] HDC hdc,
    [in] UINT align
);

HBITMAP CreateBitmapIndirect(
    [in] const BITMAP *pbm
);

int EnumObjects(
    [in] HDC hdc,
    [in] int nType,
    [in] GOBJENUMPROC lpFunc,
    [in] LPARAM lParam
);

BOOL CancelDC(
    [in] HDC hdc
);

HBRUSH CreateSolidBrush(
    [in] COLORREF color
);

HFONT CreateFontA(
    [in] int cHeight,
    [in] int cWidth,
    [in] int cEscapement,
    [in] int cOrientation,
    [in] int cWeight,
    [in] DWORD bItalic,
    [in] DWORD bUnderline,
    [in] DWORD bStrikeOut,
    [in] DWORD iCharSet,
    [in] DWORD iOutPrecision,
    [in] DWORD iClipPrecision,
    [in] DWORD iQuality,
    [in] DWORD iPitchAndFamily,
    [in] LPCSTR pszFaceName
);

HBRUSH CreatePatternBrush(
    [in] HBITMAP hbm
);

HMETAFILE CopyMetaFileA(
    [in] HMETAFILE unnamedParam1,
    [in] LPCSTR unnamedParam2
);

BOOL FrameRgn(
    [in] HDC hdc,
    [in] HRGN hrgn,
    [in] HBRUSH hbr,
    [in] int w,
    [in] int h
);

int EnumFontFamiliesW(
    [in] HDC hdc,
    [in] LPCWSTR lpLogfont,
    [in] FONTENUMPROCW lpProc,
    [in] LPARAM lParam
);

BOOL PolyTextOutA(
    [in] HDC hdc,
    [in] const POLYTEXTA *ppt,
    [in] int nstrings
);

BOOL SetWindowExtEx(
    [in] HDC hdc,
    [in] int x,
    [in] int y,
    [out] LPSIZE lpsz
);

void GetYValue(
    cmyk
);

BOOL GdiComment(
    [in] HDC hdc,
    [in] UINT nSize,
    [in] const BYTE *lpData
);

int AddFontResourceA(
    [in] LPCSTR unnamedParam1
);

COLORREF SetDCBrushColor(
    [in] HDC hdc,
    [in] COLORREF color
);

HBITMAP CreateBitmap(
    [in] int nWidth,
    [in] int nHeight,
    [in] UINT nPlanes,
    [in] UINT nBitCount,
    [in] const VOID *lpBits
);

UINT GetEnhMetaFileBits(
    [in] HENHMETAFILE hEMF,
    [in] UINT nSize,
    [out] LPBYTE lpData
);

void GetGValue(
    rgb
);

int ExtSelectClipRgn(
    [in] HDC hdc,
    [in] HRGN hrgn,
    [in] int mode
);

BOOL DeleteColorSpace(
    HCOLORSPACE hcs
);

int DeviceCapabilitiesA(
    [in] LPCSTR pDevice,
    [in] LPCSTR pPort,
    [in] WORD fwCapability,
    [out] LPSTR pOutput,
    [in] const DEVMODEA *pDevMode
);

BOOL ColorCorrectPalette(
    HDC hdc,
    HPALETTE hPal,
    DWORD deFirst,
    DWORD num
);

int GetTextCharacterExtra(
    [in] HDC hdc
);

BOOL SetDeviceGammaRamp(
    HDC hdc,
    LPVOID lpRamp
);

COLORREF GetBkColor(
    [in] HDC hdc
);

