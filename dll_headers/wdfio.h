NTSTATUS WdfIoQueueReadyNotify(
    [in] WDFQUEUE Queue,
    [in, optional] PFN_WDF_IO_QUEUE_STATE QueueReady,
    [in, optional] WDFCONTEXT Context
);

NTSTATUS WdfIoQueueFindRequest(
    [in] WDFQUEUE Queue,
    [in, optional] WDFREQUEST FoundRequest,
    [in, optional] WDFFILEOBJECT FileObject,
    [in, out] PWDF_REQUEST_PARAMETERS Parameters,
    [out] WDFREQUEST *OutRequest
);

WDF_IO_QUEUE_STATE WdfIoQueueGetState(
    [in] WDFQUEUE Queue,
    [out, optional] PULONG QueueRequests,
    [out, optional] PULONG DriverRequests
);

NTSTATUS WdfIoQueueRetrieveFoundRequest(
    [in] WDFQUEUE Queue,
    [in] WDFREQUEST FoundRequest,
    [out] WDFREQUEST *OutRequest
);

void WdfIoQueueDrain(
    [in] WDFQUEUE Queue,
    [in, optional] PFN_WDF_IO_QUEUE_STATE DrainComplete,
    [in, optional] WDFCONTEXT Context
);

WDFDEVICE WdfIoQueueGetDevice(
    [in] WDFQUEUE Queue
);

void WdfIoQueuePurgeSynchronously(
    [in] WDFQUEUE Queue
);

void WdfIoQueueStop(
    [in] WDFQUEUE Queue,
    [in, optional] PFN_WDF_IO_QUEUE_STATE StopComplete,
    [in, optional] WDFCONTEXT Context
);

NTSTATUS WdfIoQueueRetrieveNextRequest(
    [in] WDFQUEUE Queue,
    [out] WDFREQUEST *OutRequest
);

void WDF_IO_QUEUE_FORWARD_PROGRESS_POLICY_DEFAULT_INIT(
    [out] PWDF_IO_QUEUE_FORWARD_PROGRESS_POLICY Policy,
    [in] ULONG TotalForwardProgressRequests
);

NTSTATUS WdfIoQueueAssignForwardProgressPolicy(
    [in] WDFQUEUE Queue,
    [in] PWDF_IO_QUEUE_FORWARD_PROGRESS_POLICY ForwardProgressPolicy
);

void WDF_IO_QUEUE_FORWARD_PROGRESS_POLICY_PAGINGIO_INIT(
    [out] PWDF_IO_QUEUE_FORWARD_PROGRESS_POLICY Policy,
    [in] ULONG TotalForwardProgressRequests
);

void WdfIoQueuePurge(
    [in] WDFQUEUE Queue,
    [in, optional] PFN_WDF_IO_QUEUE_STATE PurgeComplete,
    [in, optional] WDFCONTEXT Context
);

void WdfIoQueueStopSynchronously(
    [in] WDFQUEUE Queue
);

NTSTATUS WdfIoQueueCreate(
    [in] WDFDEVICE Device,
    [in] PWDF_IO_QUEUE_CONFIG Config,
    [in, optional] PWDF_OBJECT_ATTRIBUTES QueueAttributes,
    [out, optional] WDFQUEUE *Queue
);

void WdfIoQueueStart(
    [in] WDFQUEUE Queue
);

BOOLEAN WDF_IO_QUEUE_STOPPED(
    [in] WDF_IO_QUEUE_STATE State
);

NTSTATUS WdfIoQueueRetrieveRequestByFileObject(
    [in] WDFQUEUE Queue,
    [in] WDFFILEOBJECT FileObject,
    [out] WDFREQUEST *OutRequest
);

void WDF_IO_QUEUE_CONFIG_INIT(
    [out] PWDF_IO_QUEUE_CONFIG Config,
    [in] WDF_IO_QUEUE_DISPATCH_TYPE DispatchType
);

BOOLEAN WDF_IO_QUEUE_IDLE(
    [in] WDF_IO_QUEUE_STATE State
);

void WDF_IO_QUEUE_FORWARD_PROGRESS_POLICY_EXAMINE_INIT(
    [out] PWDF_IO_QUEUE_FORWARD_PROGRESS_POLICY Policy,
    [in] ULONG TotalForwardProgressRequests,
    [in] PFN_WDF_IO_WDM_IRP_FOR_FORWARD_PROGRESS EvtIoWdmIrpForForwardProgress
);

void WDF_IO_QUEUE_CONFIG_INIT_DEFAULT_QUEUE(
    [out] PWDF_IO_QUEUE_CONFIG Config,
    [in] WDF_IO_QUEUE_DISPATCH_TYPE DispatchType
);

BOOLEAN WDF_IO_QUEUE_DRAINED(
    [in] WDF_IO_QUEUE_STATE State
);

void WdfIoQueueStopAndPurge(
    [in] WDFQUEUE Queue,
    [in, optional] PFN_WDF_IO_QUEUE_STATE StopAndPurgeComplete,
    [in, optional] WDFCONTEXT Context
);

BOOLEAN WDF_IO_QUEUE_READY(
    [in] WDF_IO_QUEUE_STATE State
);

void WdfIoQueueDrainSynchronously(
    [in] WDFQUEUE Queue
);

BOOLEAN WDF_IO_QUEUE_PURGED(
    [in] WDF_IO_QUEUE_STATE State
);

void WdfIoQueueStopAndPurgeSynchronously(
    [in] WDFQUEUE Queue
);

