void NetRxQueueNotifyMoreReceivedPacketsAvailable(
    [_In_] NETPACKETQUEUE PacketQueue
);

const NET_RING_COLLECTION * NetRxQueueGetRingCollection(
    [_In_] NETPACKETQUEUE PacketQueue
);

ULONG NetRxQueueInitGetQueueId(
    [_In_] NETRXQUEUE_INIT *NetRxQueueInit
);

void NetRxQueueGetExtension(
    [_In_] NETPACKETQUEUE PacketQueue,
    [_In_] const NET_EXTENSION_QUERY *Query,
    [_Out_] NET_EXTENSION *Extension
);

NTSTATUS NetRxQueueCreate(
    [_Inout_] NETRXQUEUE_INIT *NetRxQueueInit,
    [_In_opt_] WDF_OBJECT_ATTRIBUTES *RxQueueAttributes,
    [_In_] NET_PACKET_QUEUE_CONFIG *Configuration,
    [_Out_] NETPACKETQUEUE *PacketQueue
);

