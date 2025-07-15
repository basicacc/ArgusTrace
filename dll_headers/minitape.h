SCSIPORT_API VOID TapeDebugPrint(
    ULONG DebugPrintLevel,
    PCCHAR DebugMessage,
    ...
);

TAPE_PHYS_POSITION TapeClassLogicalBlockToPhysicalBlock(
    [in] UCHAR DensityCode,
    [in] ULONG LogicalBlockAddress,
    [in] ULONG BlockLength,
    [in] BOOLEAN FromBOT
);

ULONG TapeClassPhysicalBlockToLogicalBlock(
    [in] UCHAR DensityCode,
    [in] ULONG PhysicalBlockAddress,
    [in] ULONG BlockLength,
    [in] BOOLEAN FromBOT
);

VOID RtlZeroMemory(
    _Out_ VOID UNALIGNED *Destination,
    _In_  SIZE_T         Length
);

SCSIPORT_API VOID ScsiDebugPrint(
    ULONG DebugPrintLevel,
    PCCHAR DebugMessage,
    ...
);

SCSIPORT_API ULONG TapeClassInitialize(
    [in] PVOID Argument1,
    [in] PVOID Argument2,
    [in] PTAPE_INIT_DATA_EX TapeInitData
);

SCSIPORT_API VOID TapeClassZeroMemory(
    [in, out] PVOID Buffer,
    [in] ULONG BufferSize
);

LONG FIELD_OFFSET(
    _In_ TYPE  Type,
    _In_ PCHAR Field
);

SCSIPORT_API BOOLEAN TapeClassAllocateSrbBuffer(
    [in, out] PSCSI_REQUEST_BLOCK Srb,
    [in] ULONG SrbBufferSize
);

SCSIPORT_API ULONG TapeClassCompareMemory(
    [in, out] PVOID Source1,
    [in, out] PVOID Source2,
    [in] ULONG Length
);

SCSIPORT_API LARGE_INTEGER TapeClassLiDiv(
    [in] LARGE_INTEGER Dividend,
    [in] LARGE_INTEGER Divisor
);

