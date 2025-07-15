void WRITE_PORT_BUFFER_USHORT(
    [in] PUSHORT Port,
    [in] PUSHORT Buffer,
    [in] ULONG Count
);

USHORT READ_REGISTER_USHORT(
    [in] volatile USHORT *Register
);

void READ_PORT_BUFFER_UCHAR(
    [in] PUCHAR Port,
    [out] PUCHAR Buffer,
    [in] ULONG Count
);

void BarrierAfterRead();

UCHAR READ_PORT_UCHAR(
    [in] PUCHAR Port
);

UCHAR ReadBooleanRaw(
    [in] BOOLEAN const volatile *Source
);

void WRITE_REGISTER_USHORT(
    [in] volatile USHORT *Register,
    [in] USHORT Value
);

void WriteInt32NoFence(
    [out] INT32 volatile *Destination,
    [in] INT32 Value
);

void WriteInt32Raw(
    [out] INT32 volatile *Destination,
    [in] INT32 Value
);

void WRITE_REGISTER_ULONG(
    [in] volatile ULONG *Register,
    [in] ULONG Value
);

void WRITE_PORT_USHORT(
    [in] PUSHORT Port,
    [in] USHORT Value
);

LONG InterlockedExchange(
    [in, out] LONG volatile *Target,
    [in] LONG Value
);

LONG InterlockedDecrement(
    [in, out] LONG volatile *Addend
);

void WRITE_PORT_BUFFER_UCHAR(
    [in] PUCHAR Port,
    [in] PUCHAR Buffer,
    [in] ULONG Count
);

LONG InterlockedOr(
    [in, out] LONG volatile *Destination,
    [in] LONG Value
);

void ARM64_SYSREG_CRM(
    _Reg_
);

void WRITE_REGISTER_UCHAR(
    [in] volatile UCHAR *Register,
    [in] UCHAR Value
);

ULONG READ_REGISTER_ULONG(
    [in] volatile ULONG *Register
);

UCHAR READ_REGISTER_UCHAR(
    [in] volatile UCHAR *Register
);

void ARM64_SYSREG_OP2(
    _Reg_
);

void READ_REGISTER_BUFFER_ULONG(
    [in] volatile ULONG *Register,
    [out] PULONG Buffer,
    [in] ULONG Count
);

void WRITE_PORT_BUFFER_ULONG(
    [in] PULONG Port,
    [in] PULONG Buffer,
    [in] ULONG Count
);

UINT32 ReadUInt32Acquire(
    [in] UINT32 const volatile *Source
);

void WRITE_REGISTER_BUFFER_ULONG64(
    [in] volatile ULONG64 *Register,
    [in] PULONG64 Buffer,
    [in] ULONG Count
);

void WriteUInt32NoFence(
    [out] UINT32 volatile *Destination,
    [in] UINT32 Value
);

unsigned char _BitTest64(
    __int64 const *Base,
    __int64 Index
);

ULONG READ_PORT_ULONG(
    [in] PULONG Port
);

LONG InterlockedExchangeAdd(
    [in, out] LONG volatile *Addend,
    [in] LONG Value
);

LONG InterlockedIncrement(
    [in, out] LONG volatile *Addend
);

UINT32 ReadUInt32Raw(
    [in] UINT32 const volatile *Source
);

void WRITE_REGISTER_BUFFER_USHORT(
    [in] volatile USHORT *Register,
    [in] PUSHORT Buffer,
    [in] ULONG Count
);

void FIELD_OFFSET(
    type,
    field
);

void READ_REGISTER_BUFFER_ULONG64(
    [in] volatile ULONG64 *Register,
    [out] PULONG64 Buffer,
    [in] ULONG Count
);

INT32 ReadInt32Acquire(
    [in] INT32 const volatile *Source
);

INT32 ReadInt32NoFence(
    [in] INT32 const volatile *Source
);

UINT32 ReadUInt32NoFence(
    [in] UINT32 const volatile *Source
);

void READ_REGISTER_BUFFER_UCHAR(
    [in] volatile UCHAR *Register,
    [out] PUCHAR Buffer,
    [in] ULONG Count
);

void WriteUInt32Raw(
    [out] UINT32 volatile *Destination,
    [in] UINT32 Value
);

PVOID InterlockedCompareExchangePointer(
    [in, out] PVOID volatile *Destination,
    [in] PVOID Exchange,
    PVOID Comperand
);

LONG InterlockedCompareExchange(
    [in, out] LONG volatile *Destination,
    LONG ExChange,
    LONG Comperand
);

void WRITE_REGISTER_BUFFER_UCHAR(
    [in] volatile UCHAR *Register,
    [in] PUCHAR Buffer,
    [in] ULONG Count
);

void WRITE_REGISTER_ULONG64(
    [in] volatile ULONG64 *Register,
    [in] ULONG64 Value
);

void READ_PORT_BUFFER_ULONG(
    [in] PULONG Port,
    [out] PULONG Buffer,
    [in] ULONG Count
);

LONG InterlockedAnd(
    [in, out] LONG volatile *Destination,
    [in] LONG Value
);

USHORT READ_PORT_USHORT(
    [in] PUSHORT Port
);

unsigned char _BitTestAndSet64(
    __int64 *Base,
    __int64 Index
);

void ARM64_SYSREG_CRN(
    _Reg_
);

void _ReadWriteBarrier();

void BarrierAfterRead();

unsigned char _BitTestAndReset64(
    __int64 *Base,
    __int64 Index
);

void WRITE_REGISTER_BUFFER_ULONG(
    [in] volatile ULONG *Register,
    [in] PULONG Buffer,
    [in] ULONG Count
);

void ARM64_SYSREG_OP1(
    _Reg_
);

LONG InterlockedXor(
    [in, out] LONG volatile *Destination,
    [in] LONG Value
);

ULONG64 READ_REGISTER_ULONG64(
    [in] volatile ULONG64 *Register
);

INT32 ReadInt32Raw(
    [in] INT32 const volatile *Source
);

void WRITE_PORT_UCHAR(
    [in] PUCHAR Port,
    [in] UCHAR Value
);

PVOID InterlockedExchangePointer(
    [in, out] PVOID volatile *Target,
    [in, optional] PVOID Value
);

void WRITE_PORT_ULONG(
    [in] PULONG Port,
    [in] ULONG Value
);

void WriteInt32Release(
    [out] INT32 volatile *Destination,
    [in] INT32 Value
);

void WriteUInt32Release(
    [out] UINT32 volatile *Destination,
    [in] UINT32 Value
);

void READ_PORT_BUFFER_USHORT(
    [in] PUSHORT Port,
    [out] PUSHORT Buffer,
    [in] ULONG Count
);

void READ_REGISTER_BUFFER_USHORT(
    [in] volatile USHORT *Register,
    [out] PUSHORT Buffer,
    [in] ULONG Count
);

void BarrierAfterRead();

unsigned char _BitTestAndComplement64(
    __int64 *Base,
    __int64 Index
);

