void NET_ADAPTER_TX_CAPABILITIES_INIT_FOR_DMA(
    [_Out_] NET_ADAPTER_TX_CAPABILITIES *TxCapabilities,
    [_In_] NET_ADAPTER_DMA_CAPABILITIES *DmaCapabilities,
    [_In_] SIZE_T MaximumNumberOfQueues
);

void NET_ADAPTER_RECEIVE_FILTER_CAPABILITIES_INIT(
    [_Out_] NET_ADAPTER_RECEIVE_FILTER_CAPABILITIES *Capabilities,
    [_In_] PFN_NET_ADAPTER_SET_RECEIVE_FILTER EvtSetReceiveFilter
);

void NET_ADAPTER_WAKE_MAGIC_PACKET_CAPABILITIES_INIT(
    [_Out_] NET_ADAPTER_WAKE_MAGIC_PACKET_CAPABILITIES *Capabilities
);

void NET_ADAPTER_RX_CAPABILITIES_INIT_SYSTEM_MANAGED(
    [_Out_] NET_ADAPTER_RX_CAPABILITIES *RxCapabilities,
    [_In_] SIZE_T MaximumFrameSize,
    [_In_] SIZE_T MaximumNumberOfQueues
);

void NET_ADAPTER_RX_CAPABILITIES_INIT_DRIVER_MANAGED(
    [_Out_] NET_ADAPTER_RX_CAPABILITIES *RxCapabilities,
    [_In_] PFN_NET_ADAPTER_RETURN_RX_BUFFER EvtAdapterReturnRxBuffer,
    [_In_] SIZE_T MaximumFrameSize,
    [_In_] SIZE_T MaximumNumberOfQueues
);

void NetAdapterInitFree(
    [_In_] NETADAPTER_INIT *AdapterInit
);

SIZE_T NetReceiveFilterGetMulticastAddressCount(
    [_In_] NETRECEIVEFILTER ReceiveFilter
);

void NET_ADAPTER_TX_CAPABILITIES_INIT(
    [_Out_] NET_ADAPTER_TX_CAPABILITIES *TxCapabilities,
    [_In_] SIZE_T MaximumNumberOfQueues
);

void NET_ADAPTER_WAKE_PACKET_FILTER_CAPABILITIES_INIT(
    [_Out_] NET_ADAPTER_WAKE_PACKET_FILTER_CAPABILITIES *Capabilities
);

void NET_ADAPTER_LINK_STATE_INIT_DISCONNECTED(
    [_Out_] NET_ADAPTER_LINK_STATE *LinkState
);

void NetAdapterInitSetDatapathCallbacks(
    [_Inout_] NETADAPTER_INIT *AdapterInit,
    [_In_] NET_ADAPTER_DATAPATH_CALLBACKS *DatapathCallbacks
);

void NET_ADAPTER_LINK_LAYER_ADDRESS_INIT(
    [_Out_] NET_ADAPTER_LINK_LAYER_ADDRESS *LinkLayerAddress,
    [_In_range_(1,32)] USHORT Length,
    [_In_reads_bytes_(Length)] UCHAR const *AddressBuffer
);

void NET_ADAPTER_DATAPATH_CALLBACKS_INIT(
    [_Out_] NET_ADAPTER_DATAPATH_CALLBACKS *DatapathCallbacks,
    [_In_] PFN_NET_ADAPTER_CREATE_TXQUEUE EvtAdapterCreateTxQueue,
    [_In_] PFN_NET_ADAPTER_CREATE_RXQUEUE EvtAdapterCreateRxQueue
);

void NetAdapterWakeSetMagicPacketCapabilities(
    [_In_] NETADAPTER Adapter,
    [_In_] const NET_ADAPTER_WAKE_MAGIC_PACKET_CAPABILITIES *Capabilities
);

void NetAdapterSetLinkLayerCapabilities(
    [_In_] NETADAPTER Adapter,
    [_In_] NET_ADAPTER_LINK_LAYER_CAPABILITIES *LinkLayerCapabilities
);

void NetAdapterSetPermanentLinkLayerAddress(
    [_In_] NETADAPTER Adapter,
    [_In_] NET_ADAPTER_LINK_LAYER_ADDRESS *LinkLayerAddress
);

void NetAdapterSetLinkState(
    [_In_] NETADAPTER Adapter,
    [_In_] NET_ADAPTER_LINK_STATE *State
);

void NetAdapterSetCurrentLinkLayerAddress(
    [_In_] NETADAPTER Adapter,
    [_In_] NET_ADAPTER_LINK_LAYER_ADDRESS *LinkLayerAddress
);

NETADAPTER_INIT * NetAdapterLightweightInitAllocate(
    [_In_] const GUID *NetworkInterfaceGuid
);

void NET_ADAPTER_LINK_STATE_INIT(
    [_Out_] NET_ADAPTER_LINK_STATE *LinkState,
    [_In_] ULONG64 LinkSpeed,
    [_In_] NET_IF_MEDIA_CONNECT_STATE MediaConnectState,
    [_In_] NET_IF_MEDIA_DUPLEX_STATE MediaDuplexState,
    [_In_] NET_ADAPTER_PAUSE_FUNCTION_TYPE SupportedPauseFunctions,
    [_In_] NET_ADAPTER_AUTO_NEGOTIATION_FLAGS AutoNegotiationFlags
);

void NetAdapterPowerOffloadSetArpCapabilities(
    [_In_] NETADAPTER Adapter,
    [_In_] const NET_ADAPTER_POWER_OFFLOAD_ARP_CAPABILITIES *Capabilities
);

void NetAdapterSetDataPathCapabilities(
    [_In_] NETADAPTER Adapter,
    [_In_] NET_ADAPTER_TX_CAPABILITIES *TxCapabilities,
    [_In_] NET_ADAPTER_RX_CAPABILITIES *RxCapabilities
);

void NET_ADAPTER_WAKE_REASON_PACKET_INIT(
    [_Out_] NET_ADAPTER_WAKE_REASON_PACKET *Reason
);

void NetAdapterWakeSetMediaChangeCapabilities(
    [_In_] NETADAPTER Adapter,
    [_In_] const NET_ADAPTER_WAKE_MEDIA_CHANGE_CAPABILITIES *Capabilities
);

void NET_ADAPTER_DMA_CAPABILITIES_INIT(
    [_Out_] NET_ADAPTER_DMA_CAPABILITIES *DmaCapabilities,
    [_In_] WDFDMAENABLER DmaEnabler
);

void NET_ADAPTER_WAKE_MEDIA_CHANGE_CAPABILITIES_INIT(
    [_Out_] NET_ADAPTER_WAKE_MEDIA_CHANGE_CAPABILITIES *Capabilities
);

void NetAdapterReportWakeReasonMediaChange(
    [_In_] NETADAPTER Adapter,
    [_In_] NET_IF_MEDIA_CONNECT_STATE Reason
);

void NetAdapterWakeSetBitmapCapabilities(
    [_In_] NETADAPTER Adapter,
    [_In_] const NET_ADAPTER_WAKE_BITMAP_CAPABILITIES *Capabilities
);

void NET_ADAPTER_WAKE_REASON_FILTER_PACKET_INIT(
    [out] NET_ADAPTER_WAKE_REASON_PACKET *Reason
);

void NetAdapterSetReceiveFilterCapabilities(
    [_In_] NETADAPTER Adapter,
    [_In_] const NET_ADAPTER_RECEIVE_FILTER_CAPABILITIES *Capabilities
);

NTSTATUS NetAdapterOpenConfiguration(
    [_In_] NETADAPTER Adapter,
    [_In_opt_] WDF_OBJECT_ATTRIBUTES *ConfigurationAttributes,
    [_Out_] NETCONFIGURATION *Configuration
);

NET_ADAPTER_LINK_LAYER_ADDRESS const * NetReceiveFilterGetMulticastAddressList(
    [_In_] NETRECEIVEFILTER ReceiveFilter
);

void NET_ADAPTER_LINK_LAYER_CAPABILITIES_INIT(
    [_Out_] NET_ADAPTER_LINK_LAYER_CAPABILITIES *LinkLayerCapabilities,
    [_In_] ULONG64 MaxTxLinkSpeed,
    [_In_] ULONG64 MaxRxLinkSpeed
);

void NetAdapterSetLinkLayerMtuSize(
    [_In_] NETADAPTER Adapter,
    [_In_] ULONG MtuSize
);

void NET_ADAPTER_POWER_OFFLOAD_ARP_CAPABILITIES_INIT(
    [_Out_] NET_ADAPTER_POWER_OFFLOAD_ARP_CAPABILITIES *Capabilities,
    [_In_] SIZE_T MaximumOffloadCount
);

void NET_ADAPTER_RX_CAPABILITIES_INIT_SYSTEM_MANAGED_DMA(
    [_Out_] NET_ADAPTER_RX_CAPABILITIES *RxCapabilities,
    [_In_] NET_ADAPTER_DMA_CAPABILITIES *DmaCapabilities,
    [_In_] SIZE_T MaximumFrameSize,
    [_In_] SIZE_T MaximumNumberOfQueues
);

void NetAdapterPowerOffloadSetNSCapabilities(
    [_In_] NETADAPTER Adapter,
    [_In_] const NET_ADAPTER_POWER_OFFLOAD_NS_CAPABILITIES *Capabilities
);

void NET_ADAPTER_WAKE_REASON_EAPOL_PACKET_INIT(
    [out] NET_ADAPTER_WAKE_REASON_PACKET *Reason
);

void NetAdapterOffloadSetChecksumCapabilities(
    [_In_] NETADAPTER Adapter,
    [_In_] NET_ADAPTER_OFFLOAD_CHECKSUM_CAPABILITIES *HardwareCapabilities
);

NTSTATUS NetAdapterCreate(
    [_In_] NETADAPTER_INIT *AdapterInit,
    [_In_opt_] WDF_OBJECT_ATTRIBUTES *AdapterAttributes,
    [_Out_] NETADAPTER *Adapter
);

void NET_ADAPTER_WAKE_REASON_MAGIC_PACKET_INIT(
    [out] NET_ADAPTER_WAKE_REASON_PACKET *Reason
);

void NET_ADAPTER_WAKE_BITMAP_CAPABILITIES_INIT(
    [_Out_] NET_ADAPTER_WAKE_BITMAP_CAPABILITIES *Capabilities
);

NETADAPTER_INIT * NetAdapterInitAllocate(
    [_In_] WDFDEVICE Device
);

void NetAdapterStop(
    [_In_] NETADAPTER Adapter
);

NET_PACKET_FILTER_FLAGS NetReceiveFilterGetPacketFilter(
    [_In_] NETRECEIVEFILTER ReceiveFilter
);

void NET_ADAPTER_POWER_OFFLOAD_NS_CAPABILITIES_INIT(
    [_Out_] NET_ADAPTER_POWER_OFFLOAD_NS_CAPABILITIES *Capabilities,
    [_In_] SIZE_T MaximumOffloadCount
);

void NetAdapterWakeSetPacketFilterCapabilities(
    [_In_] NETADAPTER Adapter,
    [_In_] const NET_ADAPTER_WAKE_PACKET_FILTER_CAPABILITIES *Capabilities
);

void NetAdapterReportWakeReasonPacket(
    [_In_] NETADAPTER Adapter,
    [_In_] const NET_ADAPTER_WAKE_REASON_PACKET *Reason
);

void NET_ADAPTER_WAKE_EAPOL_PACKET_CAPABILITIES_INIT(
    [_Out_] NET_ADAPTER_WAKE_EAPOL_PACKET_CAPABILITIES *Capabilities
);

void NetAdapterWakeSetEapolPacketCapabilities(
    [_In_] NETADAPTER Adapter,
    [_In_] const NET_ADAPTER_WAKE_EAPOL_PACKET_CAPABILITIES *Capabilities
);

NTSTATUS NetAdapterStart(
    [_In_] NETADAPTER Adapter
);

NET_LUID NetAdapterGetNetLuid(
    [_In_] NETADAPTER Adapter
);

void NET_ADAPTER_OFFLOAD_CHECKSUM_CAPABILITIES_INIT(
    [_Out_] NET_ADAPTER_OFFLOAD_CHECKSUM_CAPABILITIES *ChecksumCapabilities,
    [_In_] BOOLEAN IPv4,
    [_In_] BOOLEAN Tcp,
    [_In_] BOOLEAN Udp,
    [_In_] PFN_NET_ADAPTER_OFFLOAD_SET_CHECKSUM EvtAdapterOffloadSetChecksum
);

