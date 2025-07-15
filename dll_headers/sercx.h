NTSTATUS SerCxDeviceInitConfig(
    [in, out] PWDFDEVICE_INIT DeviceInit
);

void SerCx2CompleteWait(
    [in] WDFDEVICE Device,
    [in] ULONG Event
);

NTSTATUS SerCxRetrieveReceiveMdl(
    [in] WDFDEVICE Device,
    [out] PMDL *Mdl
);

NTSTATUS SerCx2PioReceiveCreate(
    [in] WDFDEVICE Device,
    [in] PSERCX2_PIO_RECEIVE_CONFIG PioReceiveConfig,
    [in, optional] PWDF_OBJECT_ATTRIBUTES Attributes,
    [out] SERCX2PIORECEIVE *PioReceive
);

NTSTATUS SerCx2CustomTransmitCreate(
    [in] WDFDEVICE Device,
    [in] PSERCX2_CUSTOM_TRANSMIT_CONFIG CustomTransmitConfig,
    [in] PWDF_OBJECT_ATTRIBUTES Attributes,
    [out] SERCX2CUSTOMTRANSMIT *CustomTransmit
);

void SerCx2SystemDmaTransmitCleanupTransactionComplete(
    [in] SERCX2SYSTEMDMATRANSMIT SystemDmaTransmit
);

void SerCx2SystemDmaTransmitInitializeTransactionComplete(
    [in] SERCX2SYSTEMDMATRANSMIT SystemDmaTransmit,
    [in] BOOLEAN InitSuccess
);

ULONG SerCxGetReadIntervalTimeout(
    [in] WDFDEVICE Device
);

WDFDMAENABLER SerCx2SystemDmaReceiveGetDmaEnabler(
    [in] SERCX2SYSTEMDMARECEIVE SystemDmaReceive
);

void SerCx2CustomTransmitTransactionCleanupComplete(
    [in] SERCX2CUSTOMTRANSMITTRANSACTION CustomTransmitTransaction
);

NTSTATUS SerCxProgressTransmit(
    [in] WDFDEVICE Device,
    [in] ULONG BytesTransmitted,
    [in] SERCX_STATUS TransmitStatus
);

NTSTATUS SerCx2CustomTransmitTransactionCreate(
    [in] SERCX2CUSTOMTRANSMIT CustomTransmit,
    [in] PSERCX2_CUSTOM_TRANSMIT_TRANSACTION_CONFIG CustomTransmitTransactionConfig,
    [in] PWDF_OBJECT_ATTRIBUTES Attributes,
    [out] SERCX2CUSTOMTRANSMITTRANSACTION *CustomTransmitTransaction
);

void SERCX2_SYSTEM_DMA_TRANSMIT_CONFIG_INIT(
    [out] SERCX2_SYSTEM_DMA_TRANSMIT_CONFIG *Config,
    [in] size_t MaximumTransferLength,
    [in] PHYSICAL_ADDRESS Address,
    [in] DMA_WIDTH DmaWidth,
    [in] PCM_PARTIAL_RESOURCE_DESCRIPTOR DmaDescriptor
);

void SerCxGetRingBufferUtilization(
    [in] WDFDEVICE Device,
    [out, optional] PULONG BytesUsed,
    [out, optional] PULONG BufferSize
);

void SERCX2_SYSTEM_DMA_RECEIVE_CONFIG_INIT(
    [out] SERCX2_SYSTEM_DMA_RECEIVE_CONFIG *Config,
    [in] size_t MaximumTransferLength,
    [in] PHYSICAL_ADDRESS Address,
    [in] DMA_WIDTH DmaWidth,
    [in] PCM_PARTIAL_RESOURCE_DESCRIPTOR DmaDescriptor
);

void SERCX2_PIO_TRANSMIT_CONFIG_INIT(
    [out] SERCX2_PIO_TRANSMIT_CONFIG *PioTransmitConfig,
    [in] PFN_SERCX2_PIO_TRANSMIT_WRITE_BUFFER EvtSerCx2PioTransmitWriteBuffer,
    [in] PFN_SERCX2_PIO_TRANSMIT_ENABLE_READY_NOTIFICATION EvtSerCx2PioTransmitEnableReadyNotification,
    [in] PFN_SERCX2_PIO_TRANSMIT_CANCEL_READY_NOTIFICATION EvtSerCx2PioTransmitCancelReadyNotification
);

void SERCX2_CONFIG_INIT(
    [out] SERCX2_CONFIG *Config,
    [in] PFN_SERCX2_APPLY_CONFIG EvtSerCx2ApplyConfig,
    [in] PFN_SERCX2_CONTROL EvtSerCx2Control,
    [in] PFN_SERCX2_PURGE_FIFOS EvtSerCx2PurgeFifos
);

void SERCX2_CUSTOM_RECEIVE_CONFIG_INIT(
    [out] SERCX2_CUSTOM_RECEIVE_CONFIG *Config
);

void SERCX2_SYSTEM_DMA_RECEIVE_CONFIG_INIT_NEW_DATA_NOTIFICATION(
    [out] SERCX2_SYSTEM_DMA_RECEIVE_CONFIG *Config,
    [in] size_t MaximumTransferLength,
    [in] PHYSICAL_ADDRESS Address,
    [in] DMA_WIDTH DmaWidth,
    [in] PCM_PARTIAL_RESOURCE_DESCRIPTOR DmaDescriptor,
    [in] PFN_SERCX2_SYSTEM_DMA_RECEIVE_ENABLE_NEW_DATA_NOTIFICATION EvtSerCx2SystemDmaReceiveEnableNewDataNotification,
    [in] PFN_SERCX2_SYSTEM_DMA_RECEIVE_CANCEL_NEW_DATA_NOTIFICATION EvtSerCx2SystemDmaReceiveCancelNewDataNotification
);

void SerCx2PioTransmitInitializeTransactionComplete(
    [in] SERCX2PIOTRANSMIT PioTransmit,
    [in] BOOLEAN InitSuccess
);

NTSTATUS SerCxRetrieveTransmitMdl(
    [in] WDFDEVICE Device,
    [out] PMDL *Mdl
);

NTSTATUS SerCx2PioTransmitCreate(
    [in] WDFDEVICE Device,
    [in] PSERCX2_PIO_TRANSMIT_CONFIG PioTransmitConfig,
    [in, optional] PWDF_OBJECT_ATTRIBUTES Attributes,
    [out] SERCX2PIOTRANSMIT *PioTransmit
);

void SerCx2PioTransmitReady(
    [in] SERCX2PIOTRANSMIT PioTransmit
);

void SerCxGetConnectionParameters(
    [in] WDFDEVICE Device,
    [out] PVOID *ConnectionParameters
);

NTSTATUS SerCx2CustomReceiveCreate(
    [in] WDFDEVICE Device,
    [in] PSERCX2_CUSTOM_RECEIVE_CONFIG CustomReceiveConfig,
    [in] PWDF_OBJECT_ATTRIBUTES Attributes,
    [out] SERCX2CUSTOMRECEIVE *CustomReceive
);

NTSTATUS SerCx2SystemDmaTransmitCreate(
    [in] WDFDEVICE Device,
    [in] PSERCX2_SYSTEM_DMA_TRANSMIT_CONFIG SystemDmaTransmitConfig,
    [in, optional] PWDF_OBJECT_ATTRIBUTES Attributes,
    [out] SERCX2SYSTEMDMATRANSMIT *SystemDmaTransmit
);

void SerCx2CustomReceiveTransactionInitializeComplete(
    [in] SERCX2CUSTOMRECEIVETRANSACTION CustomReceiveTransaction,
    [in] BOOLEAN InitSuccess
);

void SERCX2_PIO_RECEIVE_CONFIG_INIT(
    [out] SERCX2_PIO_RECEIVE_CONFIG *PioReceiveConfig,
    [in] PFN_SERCX2_PIO_RECEIVE_READ_BUFFER EvtSerCx2PioReceiveReadBuffer,
    [in] PFN_SERCX2_PIO_RECEIVE_ENABLE_READY_NOTIFICATION EvtSerCx2PioReceiveEnableReadyNotification,
    [in] PFN_SERCX2_PIO_RECEIVE_CANCEL_READY_NOTIFICATION EvtSerCx2PioReceiveCancelReadyNotification
);

void SerCx2PioReceiveCleanupTransactionComplete(
    [in] SERCX2PIORECEIVE PioReceive
);

void SerCx2SystemDmaReceiveCleanupTransactionComplete(
    [in] SERCX2SYSTEMDMARECEIVE SystemDmaReceive
);

NTSTATUS SerCxRetrieveReceiveBuffer(
    [in] WDFDEVICE Device,
    [in] ULONG Length,
    [in, out] PSERCX_BUFFER_DESCRIPTOR BufferDescriptor
);

void SerCx2PioTransmitCleanupTransactionComplete(
    [in] SERCX2PIOTRANSMIT PioTransmit
);

void SerCx2CustomReceiveTransactionCleanupComplete(
    [in] SERCX2CUSTOMRECEIVETRANSACTION CustomReceiveTransaction
);

void SerCx2SaveReceiveFifoOnD0Exit(
    [in] SERCX2PIORECEIVE PioReceive,
    [in] ULONG FifoSize
);

NTSTATUS SerCx2InitializeDeviceInit(
    [in, out] PWDFDEVICE_INIT DeviceInit
);

void SerCx2PioReceiveReady(
    [in] SERCX2PIORECEIVE PioReceive
);

ULONG SerCxGetWaitMask(
    [in] WDFDEVICE Device
);

void SerCx2SystemDmaTransmitDrainFifoComplete(
    SERCX2SYSTEMDMATRANSMIT SystemDmaTransmit
);

void SerCx2CustomReceiveTransactionNewDataNotification(
    [in] SERCX2CUSTOMRECEIVETRANSACTION CustomReceiveTransaction
);

void SerCx2SystemDmaTransmitPurgeFifoComplete(
    [in] SERCX2SYSTEMDMATRANSMIT SystemDmaTransmit,
    [in] ULONG BytesPurged
);

NTSTATUS SerCxRetrieveTransmitBuffer(
    [in] WDFDEVICE Device,
    [in] ULONG Length,
    [in, out] PSERCX_BUFFER_DESCRIPTOR BufferDescriptor
);

void SerCx2PioTransmitDrainFifoComplete(
    [in] SERCX2PIOTRANSMIT PioTransmit
);

void SERCX_BUFFER_DESCRIPTOR_INIT(
    [out] SERCX_BUFFER_DESCRIPTOR *Descriptor
);

void SERCX_CONFIG_INIT(
    [out] SERCX_CONFIG *Config
);

NTSTATUS SerCxInitialize(
    [in] WDFDEVICE FxDevice,
    [in] PSERCX_CONFIG Config
);

void SERCX2_CUSTOM_TRANSMIT_TRANSACTION_CONFIG_INIT(
    [out] SERCX2_CUSTOM_TRANSMIT_TRANSACTION_CONFIG *Config,
    [in] PFN_SERCX2_CUSTOM_TRANSMIT_TRANSACTION_START EvtSerCx2CustomTransmitTransactionStart
);

NTSTATUS SerCxProgressReceive(
    [in] WDFDEVICE Device,
    [in] ULONG BytesReceived,
    [in] SERCX_STATUS ReceiveStatus
);

void SerCx2CustomTransmitTransactionInitializeComplete(
    [in] SERCX2CUSTOMTRANSMITTRANSACTION CustomTransmitTransaction,
    [in] BOOLEAN InitSuccess
);

void SerCx2SystemDmaReceiveNewDataNotification(
    [in] SERCX2SYSTEMDMARECEIVE SystemDmaReceive
);

void SerCx2PioReceiveInitializeTransactionComplete(
    [in] SERCX2PIORECEIVE PioReceive,
    [in] BOOLEAN InitSuccess
);

void SERCX2_CUSTOM_RECEIVE_TRANSACTION_CONFIG_INIT(
    [out] SERCX2_CUSTOM_RECEIVE_TRANSACTION_CONFIG *Config,
    [in] PFN_SERCX2_CUSTOM_RECEIVE_TRANSACTION_START EvtSerCx2CustomReceiveTransactionStart,
    [in, optional] PFN_SERCX2_CUSTOM_RECEIVE_TRANSACTION_ENABLE_NEW_DATA_NOTIFICATION EvtSerCx2CustomReceiveTransactionEnableNewDataNotification,
    [in] PFN_SERCX2_CUSTOM_RECEIVE_TRANSACTION_QUERY_PROGRESS EvtSerCx2CustomReceiveTransactionQueryProgress
);

void SerCx2PioTransmitPurgeFifoComplete(
    [in] SERCX2PIOTRANSMIT PioTransmit,
    [in] ULONG BytesPurged
);

void SerCxGetActivity(
    [in] WDFDEVICE Device,
    [in, out] PSERCX_ACTIVITY Activity
);

void SerCx2CustomReceiveTransactionReportProgress(
    SERCX2CUSTOMRECEIVETRANSACTION CustomReceiveTransaction,
    [in] SERCX2_CUSTOM_RECEIVE_TRANSACTION_PROGRESS Progress
);

void SERCX2_CUSTOM_TRANSMIT_CONFIG_INIT(
    [out] SERCX2_CUSTOM_TRANSMIT_CONFIG *Config
);

NTSTATUS SerCx2InitializeDevice(
    [in] WDFDEVICE Device,
    [in] PSERCX2_CONFIG Config
);

void SerCx2SystemDmaReceiveInitializeTransactionComplete(
    [in] SERCX2SYSTEMDMARECEIVE SystemDmaReceive,
    [in] BOOLEAN InitSuccess
);

NTSTATUS SerCxCompleteWait(
    [in] WDFDEVICE Device,
    [in] ULONG Event
);

NTSTATUS SerCx2CustomReceiveTransactionCreate(
    [in] SERCX2CUSTOMRECEIVE CustomReceive,
    [in] PSERCX2_CUSTOM_RECEIVE_TRANSACTION_CONFIG CustomReceiveTransactionConfig,
    [in] PWDF_OBJECT_ATTRIBUTES Attributes,
    [out] SERCX2CUSTOMRECEIVETRANSACTION *CustomReceiveTransaction
);

void SERCX_ACTIVITY_INIT(
    [out] SERCX_ACTIVITY *Activity
);

NTSTATUS SerCx2SystemDmaReceiveCreate(
    [in] WDFDEVICE Device,
    [in] PSERCX2_SYSTEM_DMA_RECEIVE_CONFIG SystemDmaReceiveConfig,
    [in, optional] PWDF_OBJECT_ATTRIBUTES Attributes,
    [out] SERCX2SYSTEMDMARECEIVE *SystemDmaReceive
);

WDFDMAENABLER SerCx2SystemDmaTransmitGetDmaEnabler(
    [in] SERCX2SYSTEMDMATRANSMIT SystemDmaTransmit
);

