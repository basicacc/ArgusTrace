NTSTATUS WdfRequestUnmarkCancelable(
    [in] WDFREQUEST Request
);

void WdfRequestFormatRequestUsingCurrentType(
    [in] WDFREQUEST Request
);

void WdfRequestGetParameters(
    [in] WDFREQUEST Request,
    [in, out] PWDF_REQUEST_PARAMETERS Parameters
);

void WDF_REQUEST_SEND_OPTIONS_SET_TIMEOUT(
    [in, out] PWDF_REQUEST_SEND_OPTIONS Options,
    [in] LONGLONG Timeout
);

NTSTATUS WdfRequestForwardToParentDeviceIoQueue(
    [in] WDFREQUEST Request,
    [in] WDFQUEUE ParentDeviceQueue,
    [in] PWDF_REQUEST_FORWARD_OPTIONS ForwardOptions
);

BOOLEAN WdfRequestCancelSentRequest(
    [in] WDFREQUEST Request
);

void WdfRequestCompleteWithInformation(
    [in] WDFREQUEST Request,
    [in] NTSTATUS Status,
    [in] ULONG_PTR Information
);

void WdfRequestMarkCancelable(
    [in] WDFREQUEST Request,
    [in] PFN_WDF_REQUEST_CANCEL EvtRequestCancel
);

NTSTATUS WdfRequestProbeAndLockUserBufferForRead(
    [in] WDFREQUEST Request,
    [in] PVOID Buffer,
    [in] size_t Length,
    [out] WDFMEMORY *MemoryObject
);

BOOLEAN WdfRequestSend(
    [in] WDFREQUEST Request,
    [in] WDFIOTARGET Target,
    PWDF_REQUEST_SEND_OPTIONS Options
);

NTSTATUS WdfRequestAllocateTimer(
    [in] WDFREQUEST Request
);

void WDF_REQUEST_REUSE_PARAMS_SET_NEW_IRP(
    [in, out] PWDF_REQUEST_REUSE_PARAMS Params,
    [in] PIRP NewIrp
);

NTSTATUS WdfRequestMarkCancelableEx(
    [in] WDFREQUEST Request,
    [in] PFN_WDF_REQUEST_CANCEL EvtRequestCancel
);

void WDF_REQUEST_REUSE_PARAMS_INIT(
    [out] PWDF_REQUEST_REUSE_PARAMS Params,
    [in] ULONG Flags,
    [in] NTSTATUS Status
);

ULONG_PTR WdfRequestGetInformation(
    [in] WDFREQUEST Request
);

void WdfRequestSetActivityId(
    [in] WDFREQUEST Request,
    [in] LPGUID ActivityId
);

BOOLEAN WdfRequestIsCanceled(
    [in] WDFREQUEST Request
);

BOOLEAN WdfRequestIsFrom32BitProcess(
    [in] WDFREQUEST Request
);

NTSTATUS WdfRequestCreate(
    [in, optional] PWDF_OBJECT_ATTRIBUTES RequestAttributes,
    [in, optional] WDFIOTARGET IoTarget,
    [out] WDFREQUEST *Request
);

void WDF_REQUEST_SEND_OPTIONS_INIT(
    [out] PWDF_REQUEST_SEND_OPTIONS Options,
    [in] ULONG Flags
);

NTSTATUS WdfRequestRetrieveOutputWdmMdl(
    [in] WDFREQUEST Request,
    [out] PMDL *Mdl
);

void WdfRequestWdmFormatUsingStackLocation(
    [in] WDFREQUEST Request,
    [in] PIO_STACK_LOCATION Stack
);

WDFQUEUE WdfRequestGetIoQueue(
    [in] WDFREQUEST Request
);

void WdfRequestGetCompletionParams(
    [in] WDFREQUEST Request,
    [in, out] PWDF_REQUEST_COMPLETION_PARAMS Params
);

NTSTATUS WdfRequestRetrieveInputBuffer(
    [in] WDFREQUEST Request,
    size_t MinimumRequiredLength,
    [out] PVOID *Buffer,
    [out, optional] size_t *Length
);

NTSTATUS WdfRequestRetrieveOutputBuffer(
    [in] WDFREQUEST Request,
    [in] size_t MinimumRequiredSize,
    [out] PVOID *Buffer,
    [out, optional] size_t *Length
);

NTSTATUS WdfRequestRetrieveOutputMemory(
    [in] WDFREQUEST Request,
    [out] WDFMEMORY *Memory
);

void WdfRequestStopAcknowledge(
    [in] WDFREQUEST Request,
    [in] BOOLEAN Requeue
);

NTSTATUS WdfRequestForwardToIoQueue(
    [in] WDFREQUEST Request,
    [in] WDFQUEUE DestinationQueue
);

WDFFILEOBJECT WdfRequestGetFileObject(
    [in] WDFREQUEST Request
);

NTSTATUS WdfRequestRequeue(
    [in] WDFREQUEST Request
);

void WdfRequestSetCompletionRoutine(
    [in] WDFREQUEST Request,
    [in, optional] PFN_WDF_REQUEST_COMPLETION_ROUTINE CompletionRoutine,
    [in, optional] __drv_aliasesMem WDFCONTEXT CompletionContext
);

NTSTATUS WdfRequestRetrieveUnsafeUserInputBuffer(
    [in] WDFREQUEST Request,
    [in] size_t MinimumRequiredLength,
    [out] PVOID *InputBuffer,
    [out, optional] size_t *Length
);

void WDF_REQUEST_COMPLETION_PARAMS_INIT(
    [out] PWDF_REQUEST_COMPLETION_PARAMS Params
);

void WdfRequestSetInformation(
    [in] WDFREQUEST Request,
    [in] ULONG_PTR Information
);

NTSTATUS WdfRequestChangeTarget(
    [in] WDFREQUEST Request,
    [in] WDFIOTARGET IoTarget
);

void WDF_REQUEST_FORWARD_OPTIONS_INIT(
    [out] PWDF_REQUEST_FORWARD_OPTIONS ForwardOptions
);

ULONG WdfRequestGetRequestorProcessId(
    [in] WDFREQUEST Request
);

NTSTATUS WdfRequestRetrieveActivityId(
    [in] WDFREQUEST Request,
    [out] LPGUID ActivityId
);

void WdfRequestSetUserModeDriverInitiatedIo(
    [in] WDFREQUEST Request,
    [in] BOOLEAN IsUserModeDriverInitiated
);

NTSTATUS WdfRequestRetrieveInputWdmMdl(
    [in] WDFREQUEST Request,
    [out] PMDL *Mdl
);

KPROCESSOR_MODE WdfRequestGetRequestorMode(
    [in] WDFREQUEST Request
);

BOOLEAN WdfRequestIsReserved(
    [in] WDFREQUEST Request
);

NTSTATUS WdfRequestGetStatus(
    [in] WDFREQUEST Request
);

NTSTATUS WdfRequestReuse(
    [in] WDFREQUEST Request,
    [in] PWDF_REQUEST_REUSE_PARAMS ReuseParams
);

BOOLEAN WdfRequestIsFromUserModeDriver(
    [in] WDFREQUEST Request
);

void WdfRequestCompleteWithPriorityBoost(
    [in] WDFREQUEST Request,
    [in] NTSTATUS Status,
    [in] CCHAR PriorityBoost
);

PIRP WdfRequestWdmGetIrp(
    [in] WDFREQUEST Request
);

NTSTATUS WdfRequestCreateFromIrp(
    [in, optional] PWDF_OBJECT_ATTRIBUTES RequestAttributes,
    [in] PIRP Irp,
    [in] BOOLEAN RequestFreesIrp,
    [out] WDFREQUEST *Request
);

NTSTATUS WdfRequestProbeAndLockUserBufferForWrite(
    [in] WDFREQUEST Request,
    [in] PVOID Buffer,
    [in] size_t Length,
    [out] WDFMEMORY *MemoryObject
);

BOOLEAN WdfRequestGetUserModeDriverInitiatedIo(
    [in] WDFREQUEST Request
);

NTSTATUS WdfRequestImpersonate(
    [in] WDFREQUEST Request,
    [in] SECURITY_IMPERSONATION_LEVEL ImpersonationLevel,
    [in] PFN_WDF_REQUEST_IMPERSONATE EvtRequestImpersonate,
    [in, optional] PVOID Context
);

NTSTATUS WdfRequestRetrieveInputMemory(
    [in] WDFREQUEST Request,
    [out] WDFMEMORY *Memory
);

void WDF_REQUEST_PARAMETERS_INIT(
    [out] PWDF_REQUEST_PARAMETERS Parameters
);

void WdfRequestComplete(
    [in] WDFREQUEST Request,
    [in] NTSTATUS Status
);

NTSTATUS WdfRequestRetrieveUnsafeUserOutputBuffer(
    [in] WDFREQUEST Request,
    [in] size_t MinimumRequiredLength,
    [out] PVOID *OutputBuffer,
    [out, optional] size_t *Length
);

WDF_DEVICE_IO_TYPE WdfRequestGetEffectiveIoType(
    [in] WDFREQUEST Request
);

