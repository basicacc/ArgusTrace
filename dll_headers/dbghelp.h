BOOL IMAGEAPI SearchTreeForFile(
    [in] PCSTR RootPath,
    [in] PCSTR InputPathName,
    [out] PSTR OutputPathBuffer
);

BOOL IMAGEAPI SymAddSourceStream(
    [in] HANDLE hProcess,
    [in] ULONG64 Base,
    [in, optional] PCSTR StreamFile,
    [in, optional] PBYTE Buffer,
    [in] size_t Size
);

BOOL IMAGEAPI SymGetLineFromAddr64(
    [in] HANDLE hProcess,
    [in] DWORD64 qwAddr,
    [out] PDWORD pdwDisplacement,
    [out] PIMAGEHLP_LINE64 Line64
);

BOOL IMAGEAPI SymEnumTypes(
    [in] HANDLE hProcess,
    [in] ULONG64 BaseOfDll,
    [in] PSYM_ENUMERATESYMBOLS_CALLBACK EnumSymbolsCallback,
    [in, optional] PVOID UserContext
);

BOOL IMAGEAPI SymGetSymFromAddr(
    [in] HANDLE hProcess,
    [in] DWORD dwAddr,
    [out, optional] PDWORD pdwDisplacement,
    [in, out] PIMAGEHLP_SYMBOL Symbol
);

BOOL IMAGEAPI SymAddSourceStreamA(
    [in] HANDLE hProcess,
    [in] ULONG64 Base,
    [in, optional] PCSTR StreamFile,
    [in, optional] PBYTE Buffer,
    [in] size_t Size
);

BOOL IMAGEAPI SymGetSymPrev64(
    [in] HANDLE hProcess,
    [in, out] PIMAGEHLP_SYMBOL64 Symbol
);

BOOL IMAGEAPI SymPrevW(
    [in] HANDLE hProcess,
    [in, out] PSYMBOL_INFOW siw
);

BOOL IMAGEAPI SymGetSourceFileTokenW(
    [in] HANDLE hProcess,
    [in] ULONG64 Base,
    [in] PCWSTR FileSpec,
    [out] PVOID *Token,
    [out] DWORD *Size
);

DWORD64 IMAGEAPI SymLoadModuleExW(
    [in] HANDLE hProcess,
    [in] HANDLE hFile,
    [in] PCWSTR ImageName,
    [in] PCWSTR ModuleName,
    [in] DWORD64 BaseOfDll,
    [in] DWORD DllSize,
    [in] PMODLOAD_DATA Data,
    [in] DWORD Flags
);

BOOL IMAGEAPI SymGetSearchPath(
    [in] HANDLE hProcess,
    [out] PSTR SearchPath,
    [in] DWORD SearchPathLength
);

DBHLP_DEPRECIATED BOOL IMAGEAPI SymEnumerateSymbolsW64(
    [in] HANDLE hProcess,
    [in] ULONG64 BaseOfDll,
    [in] PSYM_ENUMSYMBOLS_CALLBACK64W EnumSymbolsCallback,
    [in, optional] PVOID UserContext
);

BOOL IMAGEAPI SearchTreeForFileW(
    [in] PCWSTR RootPath,
    [in] PCWSTR InputPathName,
    [out] PWSTR OutputPathBuffer
);

BOOL IMAGEAPI SymEnumSymbols(
    [in] HANDLE hProcess,
    [in] ULONG64 BaseOfDll,
    [in, optional] PCSTR Mask,
    [in] PSYM_ENUMERATESYMBOLS_CALLBACK EnumSymbolsCallback,
    [in, optional] PVOID UserContext
);

BOOL IMAGEAPI SymSetSearchPath(
    [in] HANDLE hProcess,
    [in, optional] PCSTR SearchPath
);

BOOL IMAGEAPI SymSetScopeFromIndex(
    [in] HANDLE hProcess,
    [in] ULONG64 BaseOfDll,
    [in] DWORD Index
);

BOOL IMAGEAPI SymGetSourceFileChecksumW(
    [in] HANDLE hProcess,
    [in] ULONG64 Base,
    [in] PCWSTR FileSpec,
    [out] DWORD *pCheckSumType,
    [out] BYTE *pChecksum,
    [in] DWORD checksumSize,
    [out] DWORD *pActualBytesWritten
);

void IMAGEAPI SetSymLoadError(
    [in] DWORD error
);

DWORD64 IMAGEAPI SymLoadModuleEx(
    [in] HANDLE hProcess,
    [in] HANDLE hFile,
    [in] PCSTR ImageName,
    [in] PCSTR ModuleName,
    [in] DWORD64 BaseOfDll,
    [in] DWORD DllSize,
    [in] PMODLOAD_DATA Data,
    [in] DWORD Flags
);

DWORD64 IMAGEAPI SymGetModuleBase64(
    [in] HANDLE hProcess,
    [in] DWORD64 qwAddr
);

BOOL IMAGEAPI EnumerateLoadedModulesEx(
    [in] HANDLE hProcess,
    [in] PENUMLOADED_MODULES_CALLBACK64 EnumLoadedModulesCallback,
    [in, optional] PVOID UserContext
);

BOOL IMAGEAPI SymEnumSourceLinesW(
    [in] HANDLE hProcess,
    [in] ULONG64 Base,
    [in, optional] PCWSTR Obj,
    [in, optional] PCWSTR File,
    [in, optional] DWORD Line,
    [in] DWORD Flags,
    [in] PSYM_ENUMLINES_CALLBACKW EnumLinesCallback,
    [in, optional] PVOID UserContext
);

PCWSTR IMAGEAPI SymSrvStoreFileW(
    [in] HANDLE hProcess,
    [in, optional] PCWSTR SrvPath,
    [in] PCWSTR File,
    [in] DWORD Flags
);

PVOID IMAGEAPI SymFunctionTableAccess64AccessRoutines(
    [in] HANDLE hProcess,
    [in] DWORD64 AddrBase,
    [in, optional] PREAD_PROCESS_MEMORY_ROUTINE64 ReadMemoryRoutine,
    [in, optional] PGET_MODULE_BASE_ROUTINE64 GetModuleBaseRoutine
);

BOOL IMAGEAPI EnumDirTree(
    [in, optional] HANDLE hProcess,
    [in] PCSTR RootPath,
    [in] PCSTR InputPathName,
    [out, optional] PSTR OutputPathBuffer,
    [in, optional] PENUMDIRTREE_CALLBACK cb,
    [in, optional] PVOID data
);

PCWSTR IMAGEAPI SymSrvDeltaNameW(
    [in] HANDLE hProcess,
    [in, optional] PCWSTR SymPath,
    [in] PCWSTR Type,
    [in] PCWSTR File1,
    [in] PCWSTR File2
);

PIMAGE_DEBUG_INFORMATION IMAGEAPI MapDebugInformation(
    [in, optional] HANDLE FileHandle,
    [in] PCSTR FileName,
    [in, optional] PCSTR SymbolPath,
    [in] ULONG ImageBase
);

BOOL IMAGEAPI SymSearchW(
    [in] HANDLE hProcess,
    [in] ULONG64 BaseOfDll,
    [in, optional] DWORD Index,
    [in, optional] DWORD SymTag,
    [in, optional] PCWSTR Mask,
    [in, optional] DWORD64 Address,
    [in] PSYM_ENUMERATESYMBOLS_CALLBACKW EnumSymbolsCallback,
    [in, optional] PVOID UserContext,
    [in] DWORD Options
);

BOOL IMAGEAPI StackWalk2(
    [in] DWORD MachineType,
    [in] HANDLE hProcess,
    [in] HANDLE hThread,
    [in, out] LPSTACKFRAME_EX StackFrame,
    [in, out] PVOID ContextRecord,
    [in, optional] PREAD_PROCESS_MEMORY_ROUTINE64 ReadMemoryRoutine,
    [in, optional] PFUNCTION_TABLE_ACCESS_ROUTINE64 FunctionTableAccessRoutine,
    [in, optional] PGET_MODULE_BASE_ROUTINE64 GetModuleBaseRoutine,
    [in, optional] PTRANSLATE_ADDRESS_ROUTINE64 TranslateAddress,
    [in, optional] PGET_TARGET_ATTRIBUTE_VALUE64 GetTargetAttributeValue,
    [in] DWORD Flags
);

HANDLE IMAGEAPI FindExecutableImage(
    [in] PCSTR FileName,
    [in] PCSTR SymbolPath,
    [out] PSTR ImageFilePath
);

BOOL IMAGEAPI SymEnumTypesW(
    [in] HANDLE hProcess,
    [in] ULONG64 BaseOfDll,
    [in] PSYM_ENUMERATESYMBOLS_CALLBACKW EnumSymbolsCallback,
    [in, optional] PVOID UserContext
);

BOOL IMAGEAPI SymFromInlineContextW(
    [in] HANDLE hProcess,
    [in] DWORD64 Address,
    [in] ULONG InlineContext,
    [out, optional] PDWORD64 Displacement,
    [in, out] PSYMBOL_INFOW Symbol
);

BOOL IMAGEAPI SymRefreshModuleList(
    [in] HANDLE hProcess
);

BOOL IMAGEAPI SymSetExtendedOption(
    [in] IMAGEHLP_EXTENDED_OPTIONS option,
    [in] BOOL value
);

BOOL IMAGEAPI SymEnumSourceFiles(
    [in] HANDLE hProcess,
    [in] ULONG64 ModBase,
    [in, optional] PCSTR Mask,
    [in] PSYM_ENUMSOURCEFILES_CALLBACK cbSrcFiles,
    [in, optional] PVOID UserContext
);

BOOL IMAGEAPI SymGetSymNext(
    [in] HANDLE hProcess,
    [in, out] PIMAGEHLP_SYMBOL Symbol
);

BOOL IMAGEAPI SymGetLineFromInlineContextW(
    [in] HANDLE hProcess,
    [in] DWORD64 dwAddr,
    [in] ULONG InlineContext,
    [in, optional] DWORD64 qwModuleBaseAddress,
    [out] PDWORD pdwDisplacement,
    [out] PIMAGEHLP_LINEW64 Line
);

BOOL IMAGEAPI SymSrvGetFileIndexStringW(
    [in] HANDLE hProcess,
    [in, optional] PCWSTR SrvPath,
    [in] PCWSTR File,
    [out] PWSTR Index,
    [in] size_t Size,
    [in] DWORD Flags
);

BOOL IMAGEAPI SymGetLinePrevW64(
    [in] HANDLE hProcess,
    [in, out] PIMAGEHLP_LINEW64 Line
);

BOOL IMAGEAPI SymEnumSymbolsForAddrW(
    [in] HANDLE hProcess,
    [in] DWORD64 Address,
    [in] PSYM_ENUMERATESYMBOLS_CALLBACKW EnumSymbolsCallback,
    [in, optional] PVOID UserContext
);

BOOL IMAGEAPI EnumerateLoadedModulesExW(
    [in] HANDLE hProcess,
    [in] PENUMLOADED_MODULES_CALLBACKW64 EnumLoadedModulesCallback,
    [in, optional] PVOID UserContext
);

HANDLE IMAGEAPI SymFindExecutableImageW(
    [in] HANDLE hProcess,
    [in] PCWSTR FileName,
    [out] PWSTR ImageFilePath,
    [in] PFIND_EXE_FILE_CALLBACKW Callback,
    [in] PVOID CallerData
);

BOOL IMAGEAPI SymGetLineNextW64(
    [in] HANDLE hProcess,
    [in, out] PIMAGEHLP_LINEW64 Line
);

BOOL IMAGEAPI SymRegisterCallback(
    [in] HANDLE hProcess,
    [in] PSYMBOL_REGISTERED_CALLBACK CallbackFunction,
    [in] PVOID UserContext
);

DBHLP_DEPRECIATED BOOL IMAGEAPI SymEnumerateSymbols(
    [in] HANDLE hProcess,
    [in] ULONG BaseOfDll,
    [in] PSYM_ENUMSYMBOLS_CALLBACK EnumSymbolsCallback,
    [in, optional] PVOID UserContext
);

PCSTR IMAGEAPI SymSrvGetSupplement(
    [in] HANDLE hProcess,
    [in, optional] PCSTR SymPath,
    [in] PCSTR Node,
    [in] PCSTR File
);

HANDLE IMAGEAPI SymFindDebugInfoFileW(
    [in] HANDLE hProcess,
    [in] PCWSTR FileName,
    [out] PWSTR DebugFilePath,
    [in, optional] PFIND_DEBUG_FILE_CALLBACKW Callback,
    [in, optional] PVOID CallerData
);

BOOL IMAGEAPI SymEnumSourceFilesW(
    [in] HANDLE hProcess,
    [in] ULONG64 ModBase,
    [in, optional] PCWSTR Mask,
    [in] PSYM_ENUMSOURCEFILES_CALLBACKW cbSrcFiles,
    [in, optional] PVOID UserContext
);

BOOL IMAGEAPI SymUnloadModule(
    [in] HANDLE hProcess,
    [in] DWORD BaseOfDll
);

PWSTR IMAGEAPI SymGetHomeDirectoryW(
    [in] DWORD type,
    [out] PWSTR dir,
    [in] size_t size
);

BOOL IMAGEAPI SymEnumProcesses(
    [in] PSYM_ENUMPROCESSES_CALLBACK EnumProcessesCallback,
    [in] PVOID UserContext
);

BOOL IMAGEAPI SymEnumSourceFileTokens(
    [in] HANDLE hProcess,
    [in] ULONG64 Base,
    [in] PENUMSOURCEFILETOKENSCALLBACK Callback
);

BOOL IMAGEAPI SymSrvIsStore(
    [in, optional] HANDLE hProcess,
    [in] PCSTR path
);

BOOL IMAGEAPI SymGetTypeInfoEx(
    [in] HANDLE hProcess,
    [in] DWORD64 ModBase,
    [in, out] PIMAGEHLP_GET_TYPE_INFO_PARAMS Params
);

BOOL IMAGEAPI SymPrev(
    [in] HANDLE hProcess,
    [in, out] PSYMBOL_INFO si
);

BOOL IMAGEAPI SymQueryInlineTrace(
    [in] HANDLE hProcess,
    [in] DWORD64 StartAddress,
    [in] DWORD StartContext,
    [in] DWORD64 StartRetAddress,
    [in] DWORD64 CurAddress,
    [out] LPDWORD CurContext,
    [out] LPDWORD CurFrameIndex
);

BOOL IMAGEAPI SymSetScopeFromAddr(
    [in] HANDLE hProcess,
    [in] ULONG64 Address
);

BOOL IMAGEAPI SymGetOmaps(
    [in] HANDLE hProcess,
    [in] DWORD64 BaseOfDll,
    [out] POMAP *OmapTo,
    [out] PDWORD64 cOmapTo,
    [out] POMAP *OmapFrom,
    [out] PDWORD64 cOmapFrom
);

BOOL IMAGEAPI SymGetLineFromNameW64(
    [in] HANDLE hProcess,
    [in, optional] PCWSTR ModuleName,
    [in, optional] PCWSTR FileName,
    [in] DWORD dwLineNumber,
    [out] PLONG plDisplacement,
    [in, out] PIMAGEHLP_LINEW64 Line
);

BOOL IMAGEAPI SymGetLineFromName(
    [in] HANDLE hProcess,
    [in, optional] PCSTR ModuleName,
    [in, optional] PCSTR FileName,
    [in] DWORD dwLineNumber,
    [out] PLONG plDisplacement,
    [in, out] PIMAGEHLP_LINE Line
);

BOOL IMAGEAPI EnumDirTreeW(
    [in, optional] HANDLE hProcess,
    [in] PCWSTR RootPath,
    [in] PCWSTR InputPathName,
    [out, optional] PWSTR OutputPathBuffer,
    [in, optional] PENUMDIRTREE_CALLBACKW cb,
    [in, optional] PVOID data
);

BOOL IMAGEAPI SymEnumSymbolsExW(
    [in] HANDLE hProcess,
    [in] ULONG64 BaseOfDll,
    [in, optional] PCWSTR Mask,
    [in] PSYM_ENUMERATESYMBOLS_CALLBACKW EnumSymbolsCallback,
    [in, optional] PVOID UserContext,
    [in] DWORD Options
);

BOOL IMAGEAPI SymGetLinePrev64(
    [in] HANDLE hProcess,
    [in, out] PIMAGEHLP_LINE64 Line
);

BOOL IMAGEAPI SymEnumLinesW(
    [in] HANDLE hProcess,
    [in] ULONG64 Base,
    [in, optional] PCWSTR Obj,
    [in, optional] PCWSTR File,
    [in] PSYM_ENUMLINES_CALLBACKW EnumLinesCallback,
    [in, optional] PVOID UserContext
);

BOOL IMAGEAPI SymGetSymFromName64(
    [in] HANDLE hProcess,
    [in] PCSTR Name,
    [in, out] PIMAGEHLP_SYMBOL64 Symbol
);

PIMAGE_NT_HEADERS IMAGEAPI ImageNtHeader(
    [in] PVOID Base
);

LPAPI_VERSION IMAGEAPI ImagehlpApiVersion();

BOOL IMAGEAPI MakeSureDirectoryPathExists(
    [in] PCSTR DirPath
);

DBHLP_DEPRECIATED BOOL IMAGEAPI SymEnumerateSymbolsW(
    [in] HANDLE hProcess,
    [in] ULONG BaseOfDll,
    [in] PSYM_ENUMSYMBOLS_CALLBACKW EnumSymbolsCallback,
    [in, optional] PVOID UserContext
);

BOOL IMAGEAPI SymFromIndex(
    [in] HANDLE hProcess,
    [in] ULONG64 BaseOfDll,
    [in] DWORD Index,
    [in, out] PSYMBOL_INFO Symbol
);

BOOL IMAGEAPI SymSrvGetFileIndexesW(
    [in] PCWSTR File,
    [out] GUID *Id,
    [out] PDWORD Val1,
    [out, optional] PDWORD Val2,
    [in] DWORD Flags
);

BOOL IMAGEAPI SymEnumSymbolsW(
    [in] HANDLE hProcess,
    [in] ULONG64 BaseOfDll,
    [in, optional] PCWSTR Mask,
    [in] PSYM_ENUMERATESYMBOLS_CALLBACKW EnumSymbolsCallback,
    [in, optional] PVOID UserContext
);

BOOL IMAGEAPI SymGetSourceFileChecksum(
    [in] HANDLE hProcess,
    [in] ULONG64 Base,
    [in] PCSTR FileSpec,
    [out] DWORD *pCheckSumType,
    [out] BYTE *pChecksum,
    [in] DWORD checksumSize,
    [out] DWORD *pActualBytesWritten
);

BOOL IMAGEAPI EnumerateLoadedModules64(
    [in] HANDLE hProcess,
    [in] PENUMLOADED_MODULES_CALLBACK64 EnumLoadedModulesCallback,
    [in, optional] PVOID UserContext
);

BOOL IMAGEAPI SymGetLineFromName64(
    [in] HANDLE hProcess,
    [in, optional] PCSTR ModuleName,
    [in, optional] PCSTR FileName,
    [in] DWORD dwLineNumber,
    [out] PLONG plDisplacement,
    [in, out] PIMAGEHLP_LINE64 Line
);

BOOL IMAGEAPI StackWalkEx(
    [in] DWORD MachineType,
    [in] HANDLE hProcess,
    [in] HANDLE hThread,
    [in, out] LPSTACKFRAME_EX StackFrame,
    [in, out] PVOID ContextRecord,
    [in, optional] PREAD_PROCESS_MEMORY_ROUTINE64 ReadMemoryRoutine,
    [in, optional] PFUNCTION_TABLE_ACCESS_ROUTINE64 FunctionTableAccessRoutine,
    [in, optional] PGET_MODULE_BASE_ROUTINE64 GetModuleBaseRoutine,
    [in, optional] PTRANSLATE_ADDRESS_ROUTINE64 TranslateAddress,
    [in] DWORD Flags
);

BOOL IMAGEAPI SymGetModuleInfo64(
    [in] HANDLE hProcess,
    [in] DWORD64 qwAddr,
    [out] PIMAGEHLP_MODULE64 ModuleInfo
);

BOOL IMAGEAPI SymGetSourceVarFromTokenW(
    [in] HANDLE hProcess,
    [in] PVOID Token,
    [in, optional] PCWSTR Params,
    [in] PCWSTR VarName,
    [out] PWSTR Value,
    [in] DWORD Size
);

BOOL IMAGEAPI SymRegisterFunctionEntryCallback(
    [in] HANDLE hProcess,
    [in] PSYMBOL_FUNCENTRY_CALLBACK CallbackFunction,
    [in] PVOID UserContext
);

HANDLE IMAGEAPI SymFindExecutableImage(
    [in] HANDLE hProcess,
    [in] PCSTR FileName,
    [out] PSTR ImageFilePath,
    [in] PFIND_EXE_FILE_CALLBACK Callback,
    [in] PVOID CallerData
);

DWORD IMAGEAPI GetTimestampForLoadedLibrary(
    [in] HMODULE Module
);

BOOL IMAGEAPI SymGetScope(
    [in] HANDLE hProcess,
    [in] ULONG64 BaseOfDll,
    [in] DWORD Index,
    [in, out] PSYMBOL_INFO Symbol
);

HANDLE IMAGEAPI FindExecutableImageExW(
    [in] PCWSTR FileName,
    [in] PCWSTR SymbolPath,
    [out] PWSTR ImageFilePath,
    [in, optional] PFIND_EXE_FILE_CALLBACKW Callback,
    [in, optional] PVOID CallerData
);

BOOL IMAGEAPI SymGetSourceFileW(
    [in] HANDLE hProcess,
    [in] ULONG64 Base,
    [in, optional] PCWSTR Params,
    [in] PCWSTR FileSpec,
    [out] PWSTR FilePath,
    [in] DWORD Size
);

BOOL IMAGEAPI SymGetSymPrev(
    [in] HANDLE hProcess,
    [in, out] PIMAGEHLP_SYMBOL Symbol
);

BOOL IMAGEAPI SymGetSourceVarFromToken(
    [in] HANDLE hProcess,
    [in] PVOID Token,
    [in, optional] PCSTR Params,
    [in] PCSTR VarName,
    [out] PSTR Value,
    [in] DWORD Size
);

PCSTR IMAGEAPI SymSrvDeltaName(
    [in] HANDLE hProcess,
    [in, optional] PCSTR SymPath,
    [in] PCSTR Type,
    [in] PCSTR File1,
    [in] PCSTR File2
);

HANDLE IMAGEAPI FindDebugInfoFileExW(
    [in] PCWSTR FileName,
    [in] PCWSTR SymbolPath,
    [out] PWSTR DebugFilePath,
    [in, optional] PFIND_DEBUG_FILE_CALLBACKW Callback,
    [in, optional] PVOID CallerData
);

BOOL IMAGEAPI SymMatchString(
    [in] PCSTR string,
    [in] PCSTR expression,
    [in] BOOL fCase
);

PCHAR IMAGEAPI SymSetHomeDirectory(
    [in] HANDLE hProcess,
    [in, optional] PCSTR dir
);

BOOL IMAGEAPI StackWalk(
    [in] DWORD MachineType,
    [in] HANDLE hProcess,
    [in] HANDLE hThread,
    [in, out] LPSTACKFRAME StackFrame,
    [in, out] PVOID ContextRecord,
    [in, optional] PREAD_PROCESS_MEMORY_ROUTINE ReadMemoryRoutine,
    [in, optional] PFUNCTION_TABLE_ACCESS_ROUTINE FunctionTableAccessRoutine,
    [in, optional] PGET_MODULE_BASE_ROUTINE GetModuleBaseRoutine,
    [in, optional] PTRANSLATE_ADDRESS_ROUTINE TranslateAddress
);

BOOL IMAGEAPI SymGetModuleInfoW(
    [in] HANDLE hProcess,
    [in] DWORD dwAddr,
    [out] PIMAGEHLP_MODULEW ModuleInfo
);

BOOL IMAGEAPI SymFromAddr(
    [in] HANDLE hProcess,
    [in] DWORD64 Address,
    [out, optional] PDWORD64 Displacement,
    [in, out] PSYMBOL_INFO Symbol
);

BOOL IMAGEAPI SymFromToken(
    [in] HANDLE hProcess,
    [in] DWORD64 Base,
    [in] DWORD Token,
    [in, out] PSYMBOL_INFO Symbol
);

BOOL IMAGEAPI UnmapDebugInformation(
    [in] PIMAGE_DEBUG_INFORMATION DebugInfo
);

PWSTR IMAGEAPI SymSetHomeDirectoryW(
    [in] HANDLE hProcess,
    [in, optional] PCWSTR dir
);

BOOL IMAGEAPI SymGetSourceFile(
    [in] HANDLE hProcess,
    [in] ULONG64 Base,
    [in, optional] PCSTR Params,
    [in] PCSTR FileSpec,
    [out] PSTR FilePath,
    [in] DWORD Size
);

BOOL IMAGEAPI SymGetLineFromAddrW64(
    [in] HANDLE hProcess,
    [in] DWORD64 dwAddr,
    [out] PDWORD pdwDisplacement,
    [out] PIMAGEHLP_LINEW64 Line
);

BOOL IMAGEAPI SymGetLineNext(
    [in] HANDLE hProcess,
    [in, out] PIMAGEHLP_LINE Line
);

BOOL IMAGEAPI SymGetLinePrev(
    [in] HANDLE hProcess,
    [in, out] PIMAGEHLP_LINE Line
);

BOOL IMAGEAPI SymAddSymbol(
    [in] HANDLE hProcess,
    [in] ULONG64 BaseOfDll,
    [in] PCSTR Name,
    [in] DWORD64 Address,
    [in] DWORD Size,
    [in] DWORD Flags
);

BOOL IMAGEAPI SymGetSymbolFile(
    [in, optional] HANDLE hProcess,
    [in, optional] PCSTR SymPath,
    [in] PCSTR ImageFile,
    [in] DWORD Type,
    [out] PSTR SymbolFile,
    [in] size_t cSymbolFile,
    [out] PSTR DbgFile,
    [in] size_t cDbgFile
);

BOOL IMAGEAPI SymSrvGetFileIndexInfoW(
    [in] PCWSTR File,
    [out] PSYMSRV_INDEX_INFOW Info,
    [in] DWORD Flags
);

BOOL IMAGEAPI SymGetLineNext64(
    [in] HANDLE hProcess,
    [in, out] PIMAGEHLP_LINE64 Line
);

BOOL IMAGEAPI SymGetSymFromName(
    [in] HANDLE hProcess,
    [in] PCSTR Name,
    [in, out] PIMAGEHLP_SYMBOL Symbol
);

BOOL IMAGEAPI SymGetExtendedOption(
    [in] IMAGEHLP_EXTENDED_OPTIONS option
);

BOOL IMAGEAPI SymFromNameW(
    [in] HANDLE hProcess,
    [in] PCWSTR Name,
    [in, out] PSYMBOL_INFOW Symbol
);

BOOL IMAGEAPI SymGetSearchPathW(
    [in] HANDLE hProcess,
    [out] PWSTR SearchPath,
    [in] DWORD SearchPathLength
);

BOOL IMAGEAPI SymGetSymFromAddr64(
    [in] HANDLE hProcess,
    [in] DWORD64 qwAddr,
    [out, optional] PDWORD64 pdwDisplacement,
    [in, out] PIMAGEHLP_SYMBOL64 Symbol
);

BOOL IMAGEAPI SymGetModuleInfo(
    [in] HANDLE hProcess,
    [in] DWORD dwAddr,
    [out] PIMAGEHLP_MODULE ModuleInfo
);

BOOL IMAGEAPI SymAddSymbolW(
    [in] HANDLE hProcess,
    [in] ULONG64 BaseOfDll,
    [in] PCWSTR Name,
    [in] DWORD64 Address,
    [in] DWORD Size,
    [in] DWORD Flags
);

BOOL IMAGEAPI SymFindFileInPath(
    [in] HANDLE hprocess,
    [in, optional] PCSTR SearchPath,
    [in] PCSTR FileName,
    [in, optional] PVOID id,
    [in] DWORD two,
    [in] DWORD three,
    [in] DWORD flags,
    [out] PSTR FoundFile,
    [in, optional] PFINDFILEINPATHCALLBACK callback,
    [in, optional] PVOID context
);

BOOL IMAGEAPI SymUnDName64(
    [in] PIMAGEHLP_SYMBOL64 sym,
    [out] PSTR UnDecName,
    [in] DWORD UnDecNameLength
);

BOOL IMAGEAPI SymFromName(
    [in] HANDLE hProcess,
    [in] PCSTR Name,
    [in, out] PSYMBOL_INFO Symbol
);

BOOL IMAGEAPI SymGetLineFromInlineContext(
    [in] HANDLE hProcess,
    [in] DWORD64 qwAddr,
    [in] ULONG InlineContext,
    [in, optional] DWORD64 qwModuleBaseAddress,
    [out] PDWORD pdwDisplacement,
    [out] PIMAGEHLP_LINE64 Line64
);

BOOL IMAGEAPI SymGetTypeInfo(
    [in] HANDLE hProcess,
    [in] DWORD64 ModBase,
    [in] ULONG TypeId,
    [in] IMAGEHLP_SYMBOL_TYPE_INFO GetType,
    [out] PVOID pInfo
);

PVOID IMAGEAPI ImageDirectoryEntryToDataEx(
    [in] PVOID Base,
    [in] BOOLEAN MappedAsImage,
    [in] USHORT DirectoryEntry,
    [out] PULONG Size,
    [out, optional] PIMAGE_SECTION_HEADER *FoundHeader
);

BOOL IMAGEAPI SymMatchStringA(
    [in] PCSTR string,
    [in] PCSTR expression,
    [in] BOOL fCase
);

BOOL IMAGEAPI SymSrvGetFileIndexes(
    [in] PCSTR File,
    [out] GUID *Id,
    [out] PDWORD Val1,
    [out, optional] PDWORD Val2,
    [in] DWORD Flags
);

BOOL IMAGEAPI SymFromIndexW(
    [in] HANDLE hProcess,
    [in] ULONG64 BaseOfDll,
    [in] DWORD Index,
    [in, out] PSYMBOL_INFOW Symbol
);

BOOL IMAGEAPI SymEnumTypesByName(
    [in] HANDLE hProcess,
    [in] ULONG64 BaseOfDll,
    [in, optional] PCSTR mask,
    [in] PSYM_ENUMERATESYMBOLS_CALLBACK EnumSymbolsCallback,
    [in] PVOID UserContext
);

BOOL IMAGEAPI SymRegisterCallback64(
    [in] HANDLE hProcess,
    [in] PSYMBOL_REGISTERED_CALLBACK64 CallbackFunction,
    [in] ULONG64 UserContext
);

BOOL IMAGEAPI SymSetScopeFromInlineContext(
    [in] HANDLE hProcess,
    [in] ULONG64 Address,
    [in] ULONG InlineContext
);

BOOL IMAGEAPI SymEnumerateModulesW64(
    [in] HANDLE hProcess,
    [in] PSYM_ENUMMODULES_CALLBACKW64 EnumModulesCallback,
    [in, optional] PVOID UserContext
);

BOOL IMAGEAPI SymDeleteSymbolW(
    [in] HANDLE hProcess,
    [in] ULONG64 BaseOfDll,
    [in, optional] PCWSTR Name,
    [in] DWORD64 Address,
    [in] DWORD Flags
);

BOOL IMAGEAPI SymSetParentWindow(
    [in] HWND hwnd
);

HANDLE IMAGEAPI FindDebugInfoFileEx(
    [in] PCSTR FileName,
    [in] PCSTR SymbolPath,
    [out] PSTR DebugFilePath,
    [in, optional] PFIND_DEBUG_FILE_CALLBACK Callback,
    [in, optional] PVOID CallerData
);

BOOL IMAGEAPI SymAddSourceStreamW(
    [in] HANDLE hProcess,
    [in] ULONG64 Base,
    PCWSTR FileSpec,
    [in, optional] PBYTE Buffer,
    [in] size_t Size
);

BOOL IMAGEAPI SymFromAddrW(
    [in] HANDLE hProcess,
    [in] DWORD64 Address,
    [out, optional] PDWORD64 Displacement,
    [in, out] PSYMBOL_INFOW Symbol
);

BOOL IMAGEAPI SymGetSourceFileFromToken(
    [in] HANDLE hProcess,
    [in] PVOID Token,
    [in, optional] PCSTR Params,
    [out] PSTR FilePath,
    [in] DWORD Size
);

DWORD IMAGEAPI SymLoadModule(
    [in] HANDLE hProcess,
    [in, optional] HANDLE hFile,
    [in, optional] PCSTR ImageName,
    [in, optional] PCSTR ModuleName,
    [in] DWORD BaseOfDll,
    [in] DWORD SizeOfDll
);

HANDLE IMAGEAPI FindDebugInfoFile(
    [in] PCSTR FileName,
    [in] PCSTR SymbolPath,
    [out] PSTR DebugFilePath
);

DBHLP_DEPRECIATED BOOL IMAGEAPI SymEnumerateSymbols64(
    [in] HANDLE hProcess,
    [in] ULONG64 BaseOfDll,
    [in] PSYM_ENUMSYMBOLS_CALLBACK64 EnumSymbolsCallback,
    [in, optional] PVOID UserContext
);

BOOL IMAGEAPI SymEnumSourceLines(
    [in] HANDLE hProcess,
    [in] ULONG64 Base,
    [in, optional] PCSTR Obj,
    [in, optional] PCSTR File,
    [in, optional] DWORD Line,
    [in] DWORD Flags,
    [in] PSYM_ENUMLINES_CALLBACK EnumLinesCallback,
    [in, optional] PVOID UserContext
);

BOOL IMAGEAPI SymMatchFileName(
    [in] PCSTR FileName,
    [in] PCSTR Match,
    [out, optional] PSTR *FileNameStop,
    [out, optional] PSTR *MatchStop
);

BOOL IMAGEAPI SymUnloadModule64(
    [in] HANDLE hProcess,
    [in] DWORD64 BaseOfDll
);

BOOL IMAGEAPI SymGetSourceFileToken(
    [in] HANDLE hProcess,
    [in] ULONG64 Base,
    [in] PCSTR FileSpec,
    [out] PVOID *Token,
    [out] DWORD *Size
);

DWORD64 IMAGEAPI SymLoadModule64(
    [in] HANDLE hProcess,
    [in, optional] HANDLE hFile,
    [in, optional] PCSTR ImageName,
    [in, optional] PCSTR ModuleName,
    [in] DWORD64 BaseOfDll,
    [in] DWORD SizeOfDll
);

BOOL IMAGEAPI SymEnumerateModules(
    [in] HANDLE hProcess,
    [in] PSYM_ENUMMODULES_CALLBACK EnumModulesCallback,
    [in, optional] PVOID UserContext
);

BOOL IMAGEAPI SymGetSymNext64(
    [in] HANDLE hProcess,
    [in, out] PIMAGEHLP_SYMBOL64 Symbol
);

BOOL IMAGEAPI SymGetSourceFileFromTokenW(
    [in] HANDLE hProcess,
    [in] PVOID Token,
    [in, optional] PCWSTR Params,
    [out] PWSTR FilePath,
    [in] DWORD Size
);

BOOL IMAGEAPI SymFromInlineContext(
    [in] HANDLE hProcess,
    [in] DWORD64 Address,
    [in] ULONG InlineContext,
    [out, optional] PDWORD64 Displacement,
    [in, out] PSYMBOL_INFO Symbol
);

BOOL IMAGEAPI SymCleanup(
    [in] HANDLE hProcess
);

BOOL IMAGEAPI StackWalk64(
    [in] DWORD MachineType,
    [in] HANDLE hProcess,
    [in] HANDLE hThread,
    [in, out] LPSTACKFRAME64 StackFrame,
    [in, out] PVOID ContextRecord,
    [in, optional] PREAD_PROCESS_MEMORY_ROUTINE64 ReadMemoryRoutine,
    [in, optional] PFUNCTION_TABLE_ACCESS_ROUTINE64 FunctionTableAccessRoutine,
    [in, optional] PGET_MODULE_BASE_ROUTINE64 GetModuleBaseRoutine,
    [in, optional] PTRANSLATE_ADDRESS_ROUTINE64 TranslateAddress
);

BOOL IMAGEAPI SymDeleteSymbol(
    [in] HANDLE hProcess,
    [in] ULONG64 BaseOfDll,
    [in, optional] PCSTR Name,
    [in] DWORD64 Address,
    [in] DWORD Flags
);

PVOID IMAGEAPI SymFunctionTableAccess64(
    [in] HANDLE hProcess,
    [in] DWORD64 AddrBase
);

BOOL IMAGEAPI SymRegisterFunctionEntryCallback64(
    [in] HANDLE hProcess,
    [in] PSYMBOL_FUNCENTRY_CALLBACK64 CallbackFunction,
    [in] ULONG64 UserContext
);

BOOL IMAGEAPI SymNextW(
    [in] HANDLE hProcess,
    [in, out] PSYMBOL_INFOW siw
);

BOOL IMAGEAPI SymEnumerateModules64(
    [in] HANDLE hProcess,
    [in] PSYM_ENUMMODULES_CALLBACK64 EnumModulesCallback,
    [in, optional] PVOID UserContext
);

DWORD IMAGEAPI SymAddrIncludeInlineTrace(
    [in] HANDLE hProcess,
    [in] DWORD64 Address
);

PCHAR IMAGEAPI SymGetHomeDirectory(
    [in] DWORD type,
    [out] PSTR dir,
    [in] size_t size
);

BOOL IMAGEAPI SymMatchFileNameW(
    [in] PCWSTR FileName,
    [in] PCWSTR Match,
    [out, optional] PWSTR *FileNameStop,
    [out, optional] PWSTR *MatchStop
);

BOOL IMAGEAPI SymSearch(
    [in] HANDLE hProcess,
    [in] ULONG64 BaseOfDll,
    [in, optional] DWORD Index,
    [in, optional] DWORD SymTag,
    [in, optional] PCSTR Mask,
    [in, optional] DWORD64 Address,
    [in] PSYM_ENUMERATESYMBOLS_CALLBACK EnumSymbolsCallback,
    [in, optional] PVOID UserContext,
    [in] DWORD Options
);

BOOL IMAGEAPI SymSrvIsStoreW(
    [in, optional] HANDLE hProcess,
    [in] PCWSTR path
);

PCSTR IMAGEAPI SymSrvStoreFile(
    [in] HANDLE hProcess,
    [in, optional] PCSTR SrvPath,
    [in] PCSTR File,
    [in] DWORD Flags
);

PCWSTR IMAGEAPI SymSrvStoreSupplementW(
    [in] HANDLE hProcess,
    [in, optional] PCWSTR SymPath,
    [in] PCWSTR Node,
    [in] PCWSTR File,
    [in] DWORD Flags
);

BOOL IMAGEAPI SymFindFileInPathW(
    [in] HANDLE hprocess,
    [in, optional] PCWSTR SearchPath,
    [in] PCWSTR FileName,
    [in, optional] PVOID id,
    [in] DWORD two,
    [in] DWORD three,
    [in] DWORD flags,
    [out] PWSTR FoundFile,
    [in, optional] PFINDFILEINPATHCALLBACKW callback,
    [in, optional] PVOID context
);

BOOL IMAGEAPI SymEnumTypesByNameW(
    [in] HANDLE hProcess,
    [in] ULONG64 BaseOfDll,
    [in, optional] PCWSTR mask,
    [in] PSYM_ENUMERATESYMBOLS_CALLBACKW EnumSymbolsCallback,
    [in] PVOID UserContext
);

BOOL IMAGEAPI SymNext(
    [in] HANDLE hProcess,
    [in, out] PSYMBOL_INFO si
);

BOOL IMAGEAPI SymGetLineFromAddr(
    [in] HANDLE hProcess,
    [in] DWORD dwAddr,
    [out] PDWORD pdwDisplacement,
    [out] PIMAGEHLP_LINE Line
);

PIMAGE_SECTION_HEADER IMAGEAPI ImageRvaToSection(
    [in] PIMAGE_NT_HEADERS NtHeaders,
    [in] PVOID Base,
    [in] ULONG Rva
);

BOOL IMAGEAPI SymGetSymbolFileW(
    [in, optional] HANDLE hProcess,
    [in, optional] PCWSTR SymPath,
    [in] PCWSTR ImageFile,
    [in] DWORD Type,
    [out] PWSTR SymbolFile,
    [in] size_t cSymbolFile,
    [out] PWSTR DbgFile,
    [in] size_t cDbgFile
);

BOOL IMAGEAPI SymSetSearchPathW(
    [in] HANDLE hProcess,
    [in, optional] PCWSTR SearchPath
);

DWORD IMAGEAPI SymSetOptions(
    [in] DWORD SymOptions
);

PCWSTR IMAGEAPI SymSrvGetSupplementW(
    [in] HANDLE hProcess,
    [in, optional] PCWSTR SymPath,
    [in] PCWSTR Node,
    [in] PCWSTR File
);

HANDLE IMAGEAPI FindExecutableImageEx(
    [in] PCSTR FileName,
    [in] PCSTR SymbolPath,
    [out] PSTR ImageFilePath,
    [in, optional] PFIND_EXE_FILE_CALLBACK Callback,
    [in, optional] PVOID CallerData
);

DWORD IMAGEAPI UnDecorateSymbolName(
    [in] PCSTR name,
    [out] PSTR outputString,
    [in] DWORD maxStringLength,
    [in] DWORD flags
);

PCSTR IMAGEAPI SymSrvStoreSupplement(
    [in] HANDLE hProcess,
    [in, optional] PCSTR SrvPath,
    [in] PCSTR Node,
    [in] PCSTR File,
    [in] DWORD Flags
);

HANDLE IMAGEAPI SymFindDebugInfoFile(
    [in] HANDLE hProcess,
    [in] PCSTR FileName,
    [out] PSTR DebugFilePath,
    [in, optional] PFIND_DEBUG_FILE_CALLBACK Callback,
    [in, optional] PVOID CallerData
);

BOOL IMAGEAPI SymUnDName(
    [in] PIMAGEHLP_SYMBOL sym,
    [out] PSTR UnDecName,
    [in] DWORD UnDecNameLength
);

BOOL IMAGEAPI SymGetScopeW(
    [in] HANDLE hProcess,
    [in] ULONG64 BaseOfDll,
    [in] DWORD Index,
    [in, out] PSYMBOL_INFOW Symbol
);

DWORD IMAGEAPI SymGetModuleBase(
    [in] HANDLE hProcess,
    [in] DWORD dwAddr
);

BOOL IMAGEAPI SymGetTypeFromNameW(
    [in] HANDLE hProcess,
    [in] ULONG64 BaseOfDll,
    [in] PCWSTR Name,
    [in, out] PSYMBOL_INFOW Symbol
);

BOOL IMAGEAPI SymSrvGetFileIndexInfo(
    [in] PCSTR File,
    [out] PSYMSRV_INDEX_INFO Info,
    [in] DWORD Flags
);

BOOL IMAGEAPI SymSetContext(
    [in] HANDLE hProcess,
    [in] PIMAGEHLP_STACK_FRAME StackFrame,
    [in, optional] PIMAGEHLP_CONTEXT Context
);

BOOL IMAGEAPI SymFromTokenW(
    [in] HANDLE hProcess,
    [in] DWORD64 Base,
    [in] DWORD Token,
    [in, out] PSYMBOL_INFOW Symbol
);

BOOL IMAGEAPI SymMatchStringW(
    [in] PCWSTR string,
    [in] PCWSTR expression,
    [in] BOOL fCase
);

PVOID IMAGEAPI ImageDirectoryEntryToData(
    [in] PVOID Base,
    [in] BOOLEAN MappedAsImage,
    [in] USHORT DirectoryEntry,
    [out] PULONG Size
);

BOOL IMAGEAPI SymRegisterCallbackW64(
    [in] HANDLE hProcess,
    [in] PSYMBOL_REGISTERED_CALLBACK64 CallbackFunction,
    [in] ULONG64 UserContext
);

DWORD IMAGEAPI SymCompareInlineTrace(
    [in] HANDLE hProcess,
    [in] DWORD64 Address1,
    [in] DWORD InlineContext1,
    [in] DWORD64 RetAddress1,
    [in] DWORD64 Address2,
    [in] DWORD64 RetAddress2
);

BOOL IMAGEAPI EnumerateLoadedModulesW64(
    [in] HANDLE hProcess,
    [in] PENUMLOADED_MODULES_CALLBACKW64 EnumLoadedModulesCallback,
    [in, optional] PVOID UserContext
);

PVOID IMAGEAPI ImageRvaToVa(
    [in] PIMAGE_NT_HEADERS NtHeaders,
    [in] PVOID Base,
    [in] ULONG Rva,
    [in, optional] PIMAGE_SECTION_HEADER *LastRvaSection
);

BOOL IMAGEAPI SymInitializeW(
    [in] HANDLE hProcess,
    [in, optional] PCWSTR UserSearchPath,
    [in] BOOL fInvadeProcess
);

DWORD IMAGEAPI UnDecorateSymbolNameW(
    [in] PCWSTR name,
    [out] PWSTR outputString,
    [in] DWORD maxStringLength,
    [in] DWORD flags
);

BOOL IMAGEAPI SymGetModuleInfoW64(
    [in] HANDLE hProcess,
    [in] DWORD64 qwAddr,
    [out] PIMAGEHLP_MODULEW64 ModuleInfo
);

BOOL IMAGEAPI SymGetTypeFromName(
    [in] HANDLE hProcess,
    [in] ULONG64 BaseOfDll,
    [in] PCSTR Name,
    [in, out] PSYMBOL_INFO Symbol
);

ULONG IMAGEAPI SymGetFileLineOffsets64(
    [in] HANDLE hProcess,
    [in, optional] PCSTR ModuleName,
    [in] PCSTR FileName,
    [out] PDWORD64 Buffer,
    [in] ULONG BufferLines
);

BOOL IMAGEAPI SymEnumLines(
    [in] HANDLE hProcess,
    [in] ULONG64 Base,
    [in, optional] PCSTR Obj,
    [in, optional] PCSTR File,
    [in] PSYM_ENUMLINES_CALLBACK EnumLinesCallback,
    [in, optional] PVOID UserContext
);

LPAPI_VERSION IMAGEAPI ImagehlpApiVersionEx(
    [in] LPAPI_VERSION AppVersion
);

BOOL IMAGEAPI SymSrvGetFileIndexString(
    [in] HANDLE hProcess,
    [in, optional] PCSTR SrvPath,
    [in] PCSTR File,
    [out] PSTR Index,
    [in] size_t Size,
    [in] DWORD Flags
);

DWORD IMAGEAPI SymGetOptions();

BOOL IMAGEAPI EnumerateLoadedModules(
    [in] HANDLE hProcess,
    [in] PENUMLOADED_MODULES_CALLBACK EnumLoadedModulesCallback,
    [in, optional] PVOID UserContext
);

DWORD IMAGEAPI GetSymLoadError();

BOOL IMAGEAPI SymEnumSymbolsEx(
    [in] HANDLE hProcess,
    [in] ULONG64 BaseOfDll,
    [in, optional] PCSTR Mask,
    [in] PSYM_ENUMERATESYMBOLS_CALLBACK EnumSymbolsCallback,
    [in, optional] PVOID UserContext,
    [in] DWORD Options
);

BOOL IMAGEAPI SymInitialize(
    [in] HANDLE hProcess,
    [in, optional] PCSTR UserSearchPath,
    [in] BOOL fInvadeProcess
);

PVOID IMAGEAPI SymFunctionTableAccess(
    [in] HANDLE hProcess,
    [in] DWORD AddrBase
);

BOOL IMAGEAPI SymEnumSymbolsForAddr(
    [in] HANDLE hProcess,
    [in] DWORD64 Address,
    [in] PSYM_ENUMERATESYMBOLS_CALLBACK EnumSymbolsCallback,
    [in, optional] PVOID UserContext
);

