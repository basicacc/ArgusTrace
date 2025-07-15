LONG64 InterlockedDecrement64(
    [in, out] LONG64 volatile *Addend
);

BOOLEAN _interlockedbittestandreset64(
    [in] LONG64 volatile *Base,
    [in] LONG64 Offset
);

LONG64 MultiplyExtract128(
    [in] LONG64 Multiplier,
    [in] LONG64 Multiplicand,
    [in] BYTE Shift
);

NTSYSAPI DWORD RtlAddGrowableFunctionTable(
    [out] PVOID *DynamicTable,
    PRUNTIME_FUNCTION FunctionTable,
    [in] DWORD EntryCount,
    [in] DWORD MaximumEntryCount,
    [in] ULONG_PTR RangeBase,
    [in] ULONG_PTR RangeEnd
);

void TpSetCallbackCleanupGroup(
    [in, out] PTP_CALLBACK_ENVIRON CallbackEnviron,
    [in] PTP_CLEANUP_GROUP CleanupGroup,
    [in, optional] PTP_CLEANUP_GROUP_CANCEL_CALLBACK CleanupGroupCancelCallback
);

void TpSetCallbackRaceWithDll(
    [in, out] PTP_CALLBACK_ENVIRON CallbackEnviron,
    [in] PVOID DllHandle
);

NTSYSAPI VOID RtlInitializeSListHead(
    [in] PSLIST_HEADER ListHead
);

char InterlockedXor8(
    [in, out] char volatile *Destination,
    [in] char Value
);

NTSYSAPI VOID RtlCaptureContext(
    [out] PCONTEXT ContextRecord
);

LONG64 InterlockedXor64(
    [in, out] LONG64 volatile *Destination,
    [in] LONG64 Value
);

void MAKELANGID(
    p,
    s
);

void TpInitializeCallbackEnviron(
    [out] PTP_CALLBACK_ENVIRON CallbackEnviron
);

void TpDestroyCallbackEnviron(
    [in] PTP_CALLBACK_ENVIRON CallbackEnviron
);

ULONGLONG UnsignedMultiplyHigh(
    [in] DWORD64 Multiplier,
    [in] DWORD64 Multiplicand
);

PVOID GetCurrentFiber();

void TEXT(
    quote
);

DWORD64 ShiftRight128(
    DWORD64 LowPart,
    DWORD64 HighPart,
    BYTE Shift
);

LONG InterlockedExchange(
    [in, out] LONG volatile *Target,
    [in] LONG Value
);

void TpSetCallbackActivationContext(
    [in, out] PTP_CALLBACK_ENVIRON CallbackEnviron,
    [in, optional] _ACTIVATION_CONTEXT *ActivationContext
);

SHORT InterlockedExchange16(
    [in, out] SHORT volatile *Destination,
    [in] SHORT ExChange
);

void IsReparseTagNameSurrogate(
    _tag
);

LONG InterlockedAdd(
    [in, out] LONG volatile *Addend,
    [in] LONG Value
);

NTSYSAPI PSLIST_ENTRY RtlInterlockedFlushSList(
    [in] PSLIST_HEADER ListHead
);

void TpSetCallbackFinalizationCallback(
    [in, out] PTP_CALLBACK_ENVIRON CallbackEnviron,
    [in] PTP_SIMPLE_CALLBACK FinalizationCallback
);

LONG64 Multiply128(
    [in] LONG64 Multiplier,
    [in] LONG64 Multiplicand,
    [out] LONG64 *HighProduct
);

NTSYSAPI VOID RtlUnwindEx(
    [in, optional] PVOID TargetFrame,
    [in, optional] PVOID TargetIp,
    [in, optional] PEXCEPTION_RECORD ExceptionRecord,
    [in] PVOID ReturnValue,
    [in] PCONTEXT ContextRecord,
    [in, optional] PUNWIND_HISTORY_TABLE HistoryTable
);

NTSYSAPI PVOID RtlPcToFileHeader(
    [in] PVOID PcValue,
    [out] PVOID *BaseOfImage
);

void C_ASSERT(
    e
);

NTSYSAPI BOOLEAN RtlIsEcCode(
    DWORD64 CodePointer
);

NTSYSAPI VOID RtlUnwind2(
    [in, optional] FRAME_POINTERS TargetFrame,
    [in, optional] PVOID TargetIp,
    [in, optional] PEXCEPTION_RECORD ExceptionRecord,
    [in] PVOID ReturnValue,
    [in] PCONTEXT ContextRecord
);

void Int32x32To64(
    [in] a,
    [in] b
);

void Int64ShraMod32(
    [in] a,
    [in] b
);

NTSYSAPI WORD RtlQueryDepthSList(
    [in] PSLIST_HEADER ListHead
);

void YieldProcessor();

NTSYSAPI BOOLEAN RtlAddFunctionTable(
    [in] PRUNTIME_FUNCTION FunctionTable,
    [in] DWORD EntryCount,
    [in] DWORD64 BaseAddress
);

LONG64 InterlockedCompareExchange64(
    [in, out] LONG64 volatile *Destination,
    [in] LONG64 ExChange,
    [in] LONG64 Comperand
);

LONG InterlockedDecrement(
    [in, out] LONG volatile *Addend
);

void Int64ShllMod32(
    [in] a,
    [in] b
);

NTSYSAPI PSLIST_ENTRY RtlInterlockedPopEntrySList(
    [in] PSLIST_HEADER ListHead
);

LONGLONG MultiplyHigh(
    [in] LONG64 Multiplier,
    [in] LONG64 Multiplicand
);

void IsReparseTagMicrosoft(
    _tag
);

NTSYSAPI VOID RtlUnwind(
    [in, optional] PVOID TargetFrame,
    [in, optional] PVOID TargetIp,
    [in, optional] PEXCEPTION_RECORD ExceptionRecord,
    [in] PVOID ReturnValue
);

PVOID InterlockedExchangePointer(
    [in, out] PVOID volatile *Target,
    [in] PVOID Value
);

BOOLEAN _interlockedbittestandreset(
    [in] LONG volatile *Base,
    [in] LONG Offset
);

LONG InterlockedXor(
    [in, out] LONG volatile *Destination,
    [in] LONG Value
);

PVOID InterlockedCompareExchangePointer(
    [in, out] PVOID volatile *Destination,
    [in] PVOID Exchange,
    [in] PVOID Comperand
);

DWORD64 UnsignedMultiply128(
    [in] DWORD64 Multiplier,
    [in] DWORD64 Multiplicand,
    [out] DWORD64 *HighProduct
);

LONG InterlockedOr(
    [in, out] LONG volatile *Destination,
    [in] LONG Value
);

void SORTVERSIONFROMLCID(
    lcid
);

void MAKELCID(
    lgid,
    srtid
);

void FIELD_OFFSET(
    [in] type,
    [in] field
);

DWORD64 ShiftLeft128(
    DWORD64 LowPart,
    DWORD64 HighPart,
    BYTE Shift
);

BOOLEAN InterlockedCompareExchange128(
    [in, out] LONG64 volatile *Destination,
    [in] LONG64 ExchangeHigh,
    [in] LONG64 ExchangeLow,
    [in, out] LONG64 *ComparandResult
);

LONG64 InterlockedOr64(
    [in, out] LONG64 volatile *Destination,
    [in] LONG64 Value
);

NTSYSAPI VOID RtlGrowFunctionTable(
    PVOID DynamicTable,
    [in] DWORD NewEntryCount
);

BOOLEAN _interlockedbittestandset64(
    [in] LONG64 volatile *Base,
    [in] LONG64 Offset
);

NTSYSAPI WORD RtlCaptureStackBackTrace(
    [in] DWORD FramesToSkip,
    [in] DWORD FramesToCapture,
    [out] PVOID *BackTrace,
    [out, optional] PDWORD BackTraceHash
);

LONG InterlockedExchangeAdd(
    [in, out] LONG volatile *Addend,
    [in] LONG Value
);

void PreFetchCacheLine(
    l,
    a
);

LONG _InlineInterlockedAdd(
    [in, out] LONG volatile *Addend,
    [in] LONG Value
);

NTSYSAPI PRUNTIME_FUNCTION RtlLookupFunctionEntry(
    [in] DWORD64 ControlPc,
    [out] PDWORD64 ImageBase,
    [out] PUNWIND_HISTORY_TABLE HistoryTable
);

NTSYSAPI VOID __cdecl RtlRestoreContext(
    PCONTEXT ContextRecord,
    _EXCEPTION_RECORD *ExceptionRecord
);

NTSYSAPI BOOLEAN RtlDeleteFunctionTable(
    [in] PRUNTIME_FUNCTION FunctionTable
);

SHORT InterlockedXor16(
    [in, out] SHORT volatile *Destination,
    [in] SHORT Value
);

NTSYSAPI ULONGLONG VerSetConditionMask(
    [in] ULONGLONG ConditionMask,
    [in] DWORD TypeMask,
    [in] BYTE Condition
);

void Int64ShrlMod32(
    [in] a,
    [in] b
);

void TpSetCallbackNoActivationContext(
    [in, out] PTP_CALLBACK_ENVIRON CallbackEnviron
);

char InterlockedOr8(
    [in, out] char volatile *Destination,
    [in] char Value
);

LONG64 _InlineInterlockedAdd64(
    [in, out] LONG64 volatile *Addend,
    [in] LONG64 Value
);

BOOLEAN _interlockedbittestandset(
    [in] LONG volatile *Base,
    [in] LONG Offset
);

NTSYSAPI PSLIST_ENTRY RtlInterlockedPushEntrySList(
    [in] PSLIST_HEADER ListHead,
    [in] __drv_aliasesMem PSLIST_ENTRY ListEntry
);

void TpSetCallbackThreadpool(
    [in, out] PTP_CALLBACK_ENVIRON CallbackEnviron,
    [in] PTP_POOL Pool
);

SHORT InterlockedCompareExchange16(
    [in, out] SHORT volatile *Destination,
    [in] SHORT ExChange,
    [in] SHORT Comperand
);

SHORT InterlockedIncrement16(
    [in, out] SHORT volatile *Addend
);

DWORD RtlConvertDeviceFamilyInfoToString(
    PDWORD pulDeviceFamilyBufferSize,
    PDWORD pulDeviceFormBufferSize,
    PWSTR DeviceFamily,
    PWSTR DeviceForm
);

_TEB * NtCurrentTeb();

LONG InterlockedAnd(
    [in, out] LONG volatile *Destination,
    [in] LONG Value
);

char InterlockedAnd8(
    [in, out] char volatile *Destination,
    [in] char Value
);

NTSYSAPI VOID RtlDeleteGrowableFunctionTable(
    [in] PVOID DynamicTable
);

LONG64 InterlockedExchangeAdd64(
    [in, out] LONG64 volatile *Addend,
    [in] LONG64 Value
);

void SUBLANGID(
    lgid
);

void UInt32x32To64(
    [in] a,
    [in] b
);

void MAKESORTLCID(
    lgid,
    srtid,
    ver
);

DWORD64 UnsignedMultiplyExtract128(
    [in] DWORD64 Multiplier,
    [in] DWORD64 Multiplicand,
    [in] BYTE Shift
);

CHAR InterlockedExchange8(
    [in, out] CHAR volatile *Target,
    [in] CHAR Value
);

SHORT InterlockedAnd16(
    [in, out] SHORT volatile *Destination,
    [in] SHORT Value
);

SHORT InterlockedDecrement16(
    [in, out] SHORT volatile *Addend
);

LONG InterlockedIncrement(
    [in, out] LONG volatile *Addend
);

void SORTIDFROMLCID(
    lcid
);

void VER_SET_CONDITION(
    _m_,
    _t_,
    _c_
);

void MemoryBarrier();

NTSYSAPI PEXCEPTION_ROUTINE RtlVirtualUnwind(
    [in] DWORD HandlerType,
    [in] DWORD64 ImageBase,
    [in] DWORD64 ControlPc,
    [in] PRUNTIME_FUNCTION FunctionEntry,
    [in, out] PCONTEXT ContextRecord,
    [out] PVOID *HandlerData,
    [out] PDWORD64 EstablisherFrame,
    [in, out, optional] PKNONVOLATILE_CONTEXT_POINTERS ContextPointers
);

LONG InterlockedCompareExchange(
    [in, out] LONG volatile *Destination,
    [in] LONG ExChange,
    [in] LONG Comperand
);

NTSYSAPI PSLIST_ENTRY RtlFirstEntrySList(
    [in] const SLIST_HEADER *ListHead
);

DWORD64 PopulationCount64(
    [in] DWORD64 operand
);

SHORT InterlockedOr16(
    [in, out] SHORT volatile *Destination,
    [in] SHORT Value
);

void TpSetCallbackPersistent(
    [in, out] PTP_CALLBACK_ENVIRON CallbackEnviron
);

void TpSetCallbackPriority(
    [in, out] PTP_CALLBACK_ENVIRON CallbackEnviron,
    [in] TP_CALLBACK_PRIORITY Priority
);

PVOID GetFiberData();

LONG64 InterlockedIncrement64(
    [in, out] LONG64 volatile *Addend
);

LONG64 InterlockedAnd64(
    [in, out] LONG64 volatile *Destination,
    [in] LONG64 Value
);

void PRIMARYLANGID(
    lgid
);

NTSYSAPI BOOLEAN RtlInstallFunctionTableCallback(
    [in] DWORD64 TableIdentifier,
    [in] DWORD64 BaseAddress,
    [in] DWORD Length,
    [in] PGET_RUNTIME_FUNCTION_CALLBACK Callback,
    [in] PVOID Context,
    [in] PCWSTR OutOfProcessCallbackDll
);

LONG64 InterlockedExchange64(
    [in, out] LONG64 volatile *Target,
    [in] LONG64 Value
);

void LANGIDFROMLCID(
    lcid
);

void TpSetCallbackLongFunction(
    [in, out] PTP_CALLBACK_ENVIRON CallbackEnviron
);

