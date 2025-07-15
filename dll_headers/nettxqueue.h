const NET_RING_COLLECTION * NetTxQueueGetRingCollection(
    [_In_] NETPACKETQUEUE PacketQueue
);

UINT8 NetTxQueueGetDemux8021p(
    [_In_] NETPACKETQUEUE Queue
);

NTSTATUS NetTxQueueCreate(
    [_Inout_] NETTXQUEUE_INIT *NetTxQueueInit,
    [_In_opt_] WDF_OBJECT_ATTRIBUTES *TxQueueAttributes,
    [_In_] NET_PACKET_QUEUE_CONFIG *Configuration,
    [_Out_] NETPACKETQUEUE *PacketQueue
);

void NetTxQueueGetExtension(
    [_In_] NETPACKETQUEUE PacketQueue,
    [_In_] const NET_EXTENSION_QUERY *Query,
    [_Out_] NET_EXTENSION *Extension
);

ULONG NetTxQueueInitGetQueueId(
    [_In_] NETTXQUEUE_INIT *NetTxQueueInit
);

void NetTxQueueNotifyMoreCompletedPacketsAvailable(
    [_In_] NETPACKETQUEUE PacketQueue
);

