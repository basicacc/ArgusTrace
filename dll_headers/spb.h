SPB_TRANSFER_LIST_ENTRY SPB_TRANSFER_LIST_ENTRY_INIT_BUFFER_LIST(
    [in] SPB_TRANSFER_DIRECTION Direction,
    [in] ULONG DelayInUs,
    [in] SPB_TRANSFER_BUFFER_LIST_ENTRY [] BufferList,
    [in] ULONG BufferListCe
);

SPB_TRANSFER_LIST_ENTRY SPB_TRANSFER_LIST_ENTRY_INIT_MDL(
    [in] SPB_TRANSFER_DIRECTION Direction,
    [in] ULONG DelayInUs,
    [in] PMDL Mdl
);

SPB_TRANSFER_LIST_ENTRY SPB_TRANSFER_LIST_ENTRY_INIT_SIMPLE(
    [in] SPB_TRANSFER_DIRECTION Direction,
    [in] ULONG DelayInUs,
    [in] PVOID Buffer,
    [in] ULONG BufferCb
);

void SPB_TRANSFER_LIST_INIT(
    [out] SPB_TRANSFER_LIST *TransferList,
    [in] ULONG TransferCount
);

void SPB_MULTI_SPI_READ_TRANSFER_INIT(
    SPB_MULTI_SPI_READ_TRANSFER *SpiTransfer,
    SPB_MULTI_SPI_TRANSFER_MODE Mode,
    ULONG WritePhaseSingleSpiByteCount,
    ULONG WaitCycleByteCount
);

void SPB_MULTI_SPI_TRANSFER_INIT(
    SPB_MULTI_SPI_TRANSFER *SpiTransfer,
    SPB_MULTI_SPI_TRANSFER_MODE Mode,
    ULONG TransferPhaseCount,
    ULONG WritePhaseSingleSpiByteCount,
    ULONG WaitCycleByteCount
);

SPB_TRANSFER_LIST_ENTRY SPB_TRANSFER_LIST_ENTRY_INIT_NON_PAGED(
    [in] SPB_TRANSFER_DIRECTION Direction,
    [in] ULONG DelayInUs,
    [in] PVOID Buffer,
    [in] ULONG BufferCb
);

void SPB_MULTI_SPI_WRITE_TRANSFER_INIT(
    SPB_MULTI_SPI_WRITE_TRANSFER *SpiTransfer,
    SPB_MULTI_SPI_TRANSFER_MODE Mode,
    ULONG WritePhaseSingleSpiByteCount,
    ULONG WaitCycleByteCount
);

