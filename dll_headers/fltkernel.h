PCHAR FLTAPI FltGetIrpName(
    [in] UCHAR IrpMajorCode
);

PFLT_DEFERRED_IO_WORKITEM FLTAPI FltAllocateDeferredIoWorkItem();

NTSTATUS FLTAPI FltEnumerateFilterInformation(
    [in] ULONG Index,
    [in] FILTER_INFORMATION_CLASS InformationClass,
    [out] PVOID Buffer,
    [in] ULONG BufferSize,
    [out] PULONG BytesReturned
);

NTSTATUS FLTAPI FltDeleteStreamContext(
    [in] PFLT_INSTANCE Instance,
    [in] PFILE_OBJECT FileObject,
    [out] PFLT_CONTEXT *OldContext
);

NTSTATUS FLTAPI FltTagFile(
    [in] PFLT_INSTANCE InitiatingInstance,
    [in] PFILE_OBJECT FileObject,
    [in] ULONG FileTag,
    [in, optional] GUID *Guid,
    [in] PVOID DataBuffer,
    [in] USHORT DataBufferLength
);

BOOLEAN FLTAPI FltFastIoMdlReadComplete(
    PFLT_INSTANCE InitiatingInstance,
    [in] PFILE_OBJECT FileObject,
    [in] PMDL MdlChain
);

VOID FLTAPI FltCompletePendedPreOperation(
    PFLT_CALLBACK_DATA CallbackData,
    [in] FLT_PREOP_CALLBACK_STATUS CallbackStatus,
    [in, optional] PVOID Context
);

VOID FLTAPI FltFreePoolAlignedWithTag(
    [in] PFLT_INSTANCE Instance,
    [in] PVOID Buffer,
    [in] ULONG Tag
);

NTSTATUS FLTAPI FltEnumerateInstanceInformationByFilter(
    [in] PFLT_FILTER Filter,
    [in] ULONG Index,
    [in] INSTANCE_INFORMATION_CLASS InformationClass,
    [out] PVOID Buffer,
    [in] ULONG BufferSize,
    [out] PULONG BytesReturned
);

NTSTATUS FLTAPI FltIsIoRedirectionAllowedForOperation(
    [in] PFLT_CALLBACK_DATA Data,
    [in] PFLT_INSTANCE TargetInstance,
    [out] PBOOLEAN RedirectionAllowedThisIo,
    [out, optional] PBOOLEAN RedirectionAllowedAllIo
);

NTSTATUS FLTAPI FltGetVolumeInformation(
    [in] PFLT_VOLUME Volume,
    [in] FILTER_VOLUME_INFORMATION_CLASS InformationClass,
    [out] PVOID Buffer,
    [in] ULONG BufferSize,
    [out] PULONG BytesReturned
);

FLT_PREOP_CALLBACK_STATUS FLTAPI FltCheckOplock(
    [in] POPLOCK Oplock,
    [in] PFLT_CALLBACK_DATA CallbackData,
    [in, optional] PVOID Context,
    [in, optional] PFLTOPLOCK_WAIT_COMPLETE_ROUTINE WaitCompletionRoutine,
    [in, optional] PFLTOPLOCK_PREPOST_CALLBACKDATA_ROUTINE PrePostCallbackDataRoutine
);

NTSTATUS FLTAPI FltAddOpenReparseEntry(
    [in] PFLT_FILTER Filter,
    [in] PFLT_CALLBACK_DATA Data,
    [in] POPEN_REPARSE_LIST_ENTRY OpenReparseEntry
);

PFILE_LOCK FLTAPI FltAllocateFileLock(
    [in, optional] PFLT_COMPLETE_LOCK_CALLBACK_DATA_ROUTINE CompleteLockCallbackDataRoutine,
    [in, optional] PUNLOCK_ROUTINE UnlockRoutine
);

IO_PRIORITY_HINT FLTAPI FltGetIoPriorityHintFromFileObject(
    [in] PFILE_OBJECT FileObject
);

VOID FLTAPI FltInitExtraCreateParameterLookasideList(
    [in] PFLT_FILTER Filter,
    [in, out] PVOID Lookaside,
    [in] FSRTL_ECP_LOOKASIDE_FLAGS Flags,
    [in] SIZE_T Size,
    [in] ULONG Tag
);

BOOLEAN FLTAPI FltIsFltMgrVolumeDeviceObject(
    [in] PDEVICE_OBJECT DeviceObject
);

FLT_PREOP_CALLBACK_STATUS FLTAPI FltCheckOplockEx(
    [in] POPLOCK Oplock,
    [in] PFLT_CALLBACK_DATA CallbackData,
    [in] ULONG Flags,
    [in, optional] PVOID Context,
    [in, optional] PFLTOPLOCK_WAIT_COMPLETE_ROUTINE WaitCompletionRoutine,
    [in, optional] PFLTOPLOCK_PREPOST_CALLBACKDATA_ROUTINE PrePostCallbackDataRoutine
);

NTSTATUS FLTAPI FltSetIoPriorityHintIntoThread(
    [in] PETHREAD Thread,
    [in] IO_PRIORITY_HINT PriorityHint
);

NTSTATUS FLTAPI FltCancellableWaitForSingleObject(
    [in] PVOID Object,
    [in, optional] PLARGE_INTEGER Timeout,
    [in, optional] PFLT_CALLBACK_DATA CallbackData
);

VOID FLTAPI FltCompletePendedPostOperation(
    [in] PFLT_CALLBACK_DATA CallbackData
);

NTSTATUS FLTAPI FltDetachVolume(
    [in, out] PFLT_FILTER Filter,
    [in, out] PFLT_VOLUME Volume,
    [in, optional] PCUNICODE_STRING InstanceName
);

NTSTATUS FLTAPI FltFlushBuffers2(
    PFLT_INSTANCE Instance,
    PFILE_OBJECT FileObject,
    ULONG FlushType,
    PFLT_CALLBACK_DATA CallbackData
);

NTSTATUS FLTAPI FltGetVolumeFromFileObject(
    [in] PFLT_FILTER Filter,
    [in] PFILE_OBJECT FileObject,
    [out] PFLT_VOLUME *RetVolume
);

NTSTATUS FLTAPI FltParseFileName(
    [in] PCUNICODE_STRING FileName,
    [in, out] PUNICODE_STRING Extension,
    [in, out] PUNICODE_STRING Stream,
    [in, out] PUNICODE_STRING FinalComponent
);

NTSTATUS FLTAPI FltSetSecurityObject(
    [in] PFLT_INSTANCE Instance,
    [in] PFILE_OBJECT FileObject,
    [in] SECURITY_INFORMATION SecurityInformation,
    [in] PSECURITY_DESCRIPTOR SecurityDescriptor
);

NTSTATUS FLTAPI FltGetVolumeInstanceFromName(
    [in, optional] PFLT_FILTER Filter,
    [in] PFLT_VOLUME Volume,
    [in, optional] PCUNICODE_STRING InstanceName,
    [out] PFLT_INSTANCE *RetInstance
);

NTSTATUS FLTAPI FltSetEaFile(
    [in] PFLT_INSTANCE Instance,
    [in] PFILE_OBJECT FileObject,
    [in] PVOID EaBuffer,
    [in] ULONG Length
);

NTSTATUS FLTAPI FltQueryQuotaInformationFile(
    [in] PFLT_INSTANCE Instance,
    [in] PFILE_OBJECT FileObject,
    [out] PIO_STATUS_BLOCK IoStatusBlock,
    [out] PVOID Buffer,
    [in] ULONG Length,
    [in] BOOLEAN ReturnSingleEntry,
    [in, optional] PVOID SidList,
    [in] ULONG SidListLength,
    [in, optional] PULONG StartSid,
    [in] BOOLEAN RestartScan,
    [out, optional] PULONG LengthReturned
);

NTSTATUS FLTAPI FltDeviceIoControlFile(
    [in] PFLT_INSTANCE Instance,
    [in] PFILE_OBJECT FileObject,
    [in] ULONG IoControlCode,
    [in, optional] PVOID InputBuffer,
    [in] ULONG InputBufferLength,
    [out] PVOID OutputBuffer,
    [in] ULONG OutputBufferLength,
    [out, optional] PULONG LengthReturned
);

BOOLEAN FLTAPI FltIsOperationSynchronous(
    [in] PFLT_CALLBACK_DATA CallbackData
);

FLT_PREOP_CALLBACK_STATUS FLTAPI FltOplockBreakH(
    [in] POPLOCK Oplock,
    [in] PFLT_CALLBACK_DATA CallbackData,
    [in] ULONG Flags,
    [in, optional] PVOID Context,
    [in, optional] PFLTOPLOCK_WAIT_COMPLETE_ROUTINE WaitCompletionRoutine,
    [in, optional] PFLTOPLOCK_PREPOST_CALLBACKDATA_ROUTINE PrePostCallbackDataRoutine
);

NTSTATUS FLTAPI FltQueryDirectoryFile(
    [in] PFLT_INSTANCE Instance,
    [in] PFILE_OBJECT FileObject,
    [out] PVOID FileInformation,
    [in] ULONG Length,
    [in] FILE_INFORMATION_CLASS FileInformationClass,
    [in] BOOLEAN ReturnSingleEntry,
    [in, optional] PUNICODE_STRING FileName,
    [in] BOOLEAN RestartScan,
    [out, optional] PULONG LengthReturned
);

VOID FLTAPI FltFreeExtraCreateParameterList(
    [in] PFLT_FILTER Filter,
    [in] PECP_LIST EcpList
);

NTSTATUS FLTAPI FltAttachVolumeAtAltitude(
    [in, out] PFLT_FILTER Filter,
    [in, out] PFLT_VOLUME Volume,
    [in] PCUNICODE_STRING Altitude,
    [in, optional] PCUNICODE_STRING InstanceName,
    [out, optional] PFLT_INSTANCE *RetInstance
);

NTSTATUS FLTAPI FltGetDiskDeviceObject(
    [in] PFLT_VOLUME Volume,
    [out] PDEVICE_OBJECT *DiskDeviceObject
);

NTSTATUS FLTAPI FltGetFileContext(
    [in] PFLT_INSTANCE Instance,
    [in] PFILE_OBJECT FileObject,
    [out] PFLT_CONTEXT *Context
);

NTSTATUS FLTAPI FltSetStreamContext(
    [in] PFLT_INSTANCE Instance,
    [in] PFILE_OBJECT FileObject,
    [in] FLT_SET_CONTEXT_OPERATION Operation,
    [in] PFLT_CONTEXT NewContext,
    [out] PFLT_CONTEXT *OldContext
);

VOID FLTAPI FltNotifyFilterChangeDirectory(
    [in, out] PNOTIFY_SYNC NotifySync,
    [in, out] PLIST_ENTRY NotifyList,
    [in] PVOID FsContext,
    [in] PSTRING FullDirectoryName,
    [in] BOOLEAN WatchTree,
    [in] BOOLEAN IgnoreBuffer,
    [in] ULONG CompletionFilter,
    [in] PFLT_CALLBACK_DATA NotifyCallbackData,
    [in, optional] PCHECK_FOR_TRAVERSE_ACCESS TraverseCallback,
    [in, optional] PSECURITY_SUBJECT_CONTEXT SubjectContext,
    [in, optional] PFILTER_REPORT_CHANGE FilterCallback
);

NTSTATUS FLTAPI FltTagFileEx(
    PFLT_INSTANCE InitiatingInstance,
    PFILE_OBJECT FileObject,
    ULONG FileTag,
    GUID *Guid,
    PVOID DataBuffer,
    USHORT DataBufferLength,
    ULONG ExistingFileTag,
    GUID *ExistingGuid,
    ULONG Flags
);

NTSTATUS FLTAPI FltGetTransactionContext(
    [in] PFLT_INSTANCE Instance,
    [in] PKTRANSACTION Transaction,
    [out] PFLT_CONTEXT *Context
);

NTSTATUS FLTAPI FltQuerySecurityObject(
    [in] PFLT_INSTANCE Instance,
    [in] PFILE_OBJECT FileObject,
    [in] SECURITY_INFORMATION SecurityInformation,
    [in, out] PSECURITY_DESCRIPTOR SecurityDescriptor,
    [in] ULONG Length,
    [out, optional] PULONG LengthNeeded
);

NTSTATUS FLTAPI FltGetVolumeFromInstance(
    [in] PFLT_INSTANCE Instance,
    [out] PFLT_VOLUME *RetVolume
);

NTSTATUS FLTAPI FltWriteFileEx(
    [in] PFLT_INSTANCE InitiatingInstance,
    [in] PFILE_OBJECT FileObject,
    [in, optional] PLARGE_INTEGER ByteOffset,
    [in] ULONG Length,
    [in] PVOID Buffer,
    [in] FLT_IO_OPERATION_FLAGS Flags,
    [out, optional] PULONG BytesWritten,
    [in, optional] PFLT_COMPLETED_ASYNC_IO_CALLBACK CallbackRoutine,
    [in, optional] PVOID CallbackContext,
    [in, optional] PULONG Key,
    [in, optional] PMDL Mdl
);

VOID FLTAPI FltReleaseResource(
    [in/out] PERESOURCE Resource
);

VOID FLTAPI FltDeleteContext(
    [in] PFLT_CONTEXT Context
);

NTSTATUS FLTAPI FltSetVolumeInformation(
    [in] PFLT_INSTANCE Instance,
    [out] PIO_STATUS_BLOCK Iosb,
    [out] PVOID FsInformation,
    [in] ULONG Length,
    [in] FS_INFORMATION_CLASS FsInformationClass
);

VOID FLTAPI FltAcknowledgeEcp(
    [in] PFLT_FILTER Filter,
    [in] PVOID EcpContext
);

NTSTATUS FLTAPI FltPurgeFileNameInformationCache(
    [in] PFLT_INSTANCE Instance,
    [in, optional] PFILE_OBJECT FileObject
);

NTSTATUS FLTAPI FltQueryVolumeInformation(
    [in] PFLT_INSTANCE Instance,
    [out] PIO_STATUS_BLOCK Iosb,
    [out] PVOID FsInformation,
    [in] ULONG Length,
    [in] FS_INFORMATION_CLASS FsInformationClass
);

VOID FLTAPI FltDeleteExtraCreateParameterLookasideList(
    [in] PFLT_FILTER Filter,
    [in, out] PVOID Lookaside,
    [in] FSRTL_ECP_LOOKASIDE_FLAGS Flags
);

BOOLEAN FLTAPI FltIsCallbackDataDirty(
    [in] PFLT_CALLBACK_DATA Data
);

NTSTATUS FLTAPI FltGetStreamContext(
    [in] PFLT_INSTANCE Instance,
    [in] PFILE_OBJECT FileObject,
    [out] PFLT_CONTEXT *Context
);

NTSTATUS FLTAPI FltQueueGenericWorkItem(
    [in] PFLT_GENERIC_WORKITEM FltWorkItem,
    [in] PVOID FltObject,
    [in] PFLT_GENERIC_WORKITEM_ROUTINE WorkerRoutine,
    [in] WORK_QUEUE_TYPE QueueType,
    [in, optional] PVOID Context
);

NTSTATUS FLTAPI FltVetoBypassIo(
    [in] PFLT_CALLBACK_DATA CallbackData,
    [in] PCFLT_RELATED_OBJECTS FltObjects,
    [in] NTSTATUS OperationStatus,
    [in] PCUNICODE_STRING FailureReason
);

NTSTATUS FLTAPI FltCreateFile(
    [in] PFLT_FILTER Filter,
    [in, optional] PFLT_INSTANCE Instance,
    [out] PHANDLE FileHandle,
    [in] ACCESS_MASK DesiredAccess,
    [in] POBJECT_ATTRIBUTES ObjectAttributes,
    [out] PIO_STATUS_BLOCK IoStatusBlock,
    [in, optional] PLARGE_INTEGER AllocationSize,
    [in] ULONG FileAttributes,
    [in] ULONG ShareAccess,
    [in] ULONG CreateDisposition,
    [in] ULONG CreateOptions,
    [in, optional] PVOID EaBuffer,
    [in] ULONG EaLength,
    [in] ULONG Flags
);

NTSTATUS FLTAPI FltGetVolumeName(
    [in] PFLT_VOLUME Volume,
    [in, out, optional] PUNICODE_STRING VolumeName,
    [out, optional] PULONG BufferSizeNeeded
);

NTSTATUS FLTAPI FltFsControlFile(
    [in] PFLT_INSTANCE Instance,
    [in] PFILE_OBJECT FileObject,
    [in] ULONG FsControlCode,
    [in, optional] PVOID InputBuffer,
    [in] ULONG InputBufferLength,
    [out, optional] PVOID OutputBuffer,
    [in] ULONG OutputBufferLength,
    [out, optional] PULONG LengthReturned
);

NTSTATUS FLTAPI FltSetInstanceContext(
    [in] PFLT_INSTANCE Instance,
    [in] FLT_SET_CONTEXT_OPERATION Operation,
    [in] PFLT_CONTEXT NewContext,
    [out] PFLT_CONTEXT *OldContext
);

NTSTATUS FLTAPI FltPerformAsynchronousIo(
    [in, out] PFLT_CALLBACK_DATA CallbackData,
    [in] PFLT_COMPLETED_ASYNC_IO_CALLBACK CallbackRoutine,
    [in] PVOID CallbackContext
);

NTSTATUS FLTAPI FltGetFileSystemType(
    [in] PVOID FltObject,
    [out] PFLT_FILESYSTEM_TYPE FileSystemType
);

NTSTATUS FLTAPI FltIsIoRedirectionAllowed(
    [in] PFLT_INSTANCE SourceInstance,
    [in] PFLT_INSTANCE TargetInstance,
    [out] PBOOLEAN RedirectionAllowed
);

NTSTATUS FLTAPI FltAllocateCallbackDataEx(
    [in] PFLT_INSTANCE Instance,
    [in/optional] PFILE_OBJECT FileObject,
    [in] FLT_ALLOCATE_CALLBACK_DATA_FLAGS Flags,
    [out] PFLT_CALLBACK_DATA *RetNewCallbackData
);

NTSTATUS FLTAPI FltGetStreamHandleContext(
    [in] PFLT_INSTANCE Instance,
    [in] PFILE_OBJECT FileObject,
    [out] PFLT_CONTEXT *Context
);

NTSTATUS FLTAPI FltAllocateExtraCreateParameterList(
    [in] PFLT_FILTER Filter,
    [in] FSRTL_ALLOCATE_ECPLIST_FLAGS Flags,
    [out] PECP_LIST *EcpList
);

VOID FLTAPI FltReferenceContext(
    [in] PFLT_CONTEXT Context
);

NTSTATUS FLTAPI FltInsertExtraCreateParameter(
    [in] PFLT_FILTER Filter,
    [in, out] PECP_LIST EcpList,
    [in, out] PVOID EcpContext
);

NTSTATUS FLTAPI FltRequestOperationStatusCallback(
    [in] PFLT_CALLBACK_DATA Data,
    [in] PFLT_GET_OPERATION_STATUS_CALLBACK CallbackRoutine,
    [in, optional] PVOID RequesterContext
);

BOOLEAN FLTAPI FltCurrentOplockH(
    [in] POPLOCK Oplock
);

NTSTATUS FLTAPI FltSetStreamHandleContext(
    [in] PFLT_INSTANCE Instance,
    [in] PFILE_OBJECT FileObject,
    [in] FLT_SET_CONTEXT_OPERATION Operation,
    [in] PFLT_CONTEXT NewContext,
    [out, optional] PFLT_CONTEXT *OldContext
);

BOOLEAN FLTAPI FltCheckLockForReadAccess(
    [in] PFILE_LOCK FileLock,
    [in] PFLT_CALLBACK_DATA CallbackData
);

NTSTATUS FLTAPI FltEnumerateVolumeInformation(
    [in] PFLT_FILTER Filter,
    [in] ULONG Index,
    [in] FILTER_VOLUME_INFORMATION_CLASS InformationClass,
    [out] PVOID Buffer,
    [in] ULONG BufferSize,
    [out] PULONG BytesReturned
);

VOID FLTAPI FltAcquirePushLockExclusiveEx(
    [in, out] PEX_PUSH_LOCK PushLock,
    ULONG Flags
);

NTSTATUS FLTAPI FltIsVolumeWritable(
    [in] PVOID FltObject,
    [out] PBOOLEAN IsWritable
);

VOID FLTAPI FltAcquirePushLockShared(
    [in, out] PEX_PUSH_LOCK PushLock
);

NTSTATUS FLTAPI FltAllocateExtraCreateParameterFromLookasideList(
    [in] PFLT_FILTER Filter,
    [in] LPCGUID EcpType,
    [in] ULONG SizeOfContext,
    [in] FSRTL_ALLOCATE_ECP_FLAGS Flags,
    [in, optional] PFSRTL_EXTRA_CREATE_PARAMETER_CLEANUP_CALLBACK CleanupCallback,
    [in, out] PVOID LookasideList,
    [out] PVOID *EcpContext
);

LONG FLTAPI FltCompareInstanceAltitudes(
    [in] PFLT_INSTANCE Instance1,
    [in] PFLT_INSTANCE Instance2
);

NTSTATUS FLTAPI FltCbdqInitialize(
    [in] PFLT_INSTANCE Instance,
    [in, out] PFLT_CALLBACK_DATA_QUEUE Cbdq,
    [in] PFLT_CALLBACK_DATA_QUEUE_INSERT_IO CbdqInsertIo,
    [in] PFLT_CALLBACK_DATA_QUEUE_REMOVE_IO CbdqRemoveIo,
    [in] PFLT_CALLBACK_DATA_QUEUE_PEEK_NEXT_IO CbdqPeekNextIo,
    [in] PFLT_CALLBACK_DATA_QUEUE_ACQUIRE CbdqAcquire,
    [in] PFLT_CALLBACK_DATA_QUEUE_RELEASE CbdqRelease,
    [in] PFLT_CALLBACK_DATA_QUEUE_COMPLETE_CANCELED_IO CbdqCompleteCanceledIo
);

VOID FLTAPI FltInitializeFileLock(
    [out] PFILE_LOCK FileLock
);

NTSTATUS FLTAPI FltQueryDirectoryFileEx(
    PFLT_INSTANCE Instance,
    PFILE_OBJECT FileObject,
    PVOID FileInformation,
    ULONG Length,
    FILE_INFORMATION_CLASS FileInformationClass,
    ULONG QueryFlags,
    PUNICODE_STRING FileName,
    PULONG LengthReturned
);

NTSTATUS FLTAPI FltSetEcpListIntoCallbackData(
    [in] PFLT_FILTER Filter,
    PFLT_CALLBACK_DATA CallbackData,
    [in] PECP_LIST EcpList
);

NTSTATUS FLTAPI FltGetFileNameInformationUnsafe(
    [in] PFILE_OBJECT FileObject,
    [in, optional] PFLT_INSTANCE Instance,
    [in] FLT_FILE_NAME_OPTIONS NameOptions,
    [out] PFLT_FILE_NAME_INFORMATION *FileNameInformation
);

NTSTATUS FLTAPI FltGetInstanceInformation(
    [in] PFLT_INSTANCE Instance,
    [in] INSTANCE_INFORMATION_CLASS InformationClass,
    [out] PVOID Buffer,
    [in] ULONG BufferSize,
    [out] PULONG BytesReturned
);

void FLT_IS_IRP_OPERATION(
    Data
);

VOID FLTAPI FltReissueSynchronousIo(
    [in] PFLT_INSTANCE InitiatingInstance,
    [in] PFLT_CALLBACK_DATA CallbackData
);

PFLT_CALLBACK_DATA FLTAPI FltCbdqRemoveIo(
    [in, out] PFLT_CALLBACK_DATA_QUEUE Cbdq,
    [in] PFLT_CALLBACK_DATA_QUEUE_IO_CONTEXT Context
);

VOID FLTAPI FltCloseCommunicationPort(
    [in] PFLT_PORT ServerPort
);

void FltRetainSwappedBufferMdlAddress(
    [in] PFLT_CALLBACK_DATA CallbackData
);

NTSTATUS FLTAPI FltPrepareComplete(
    [in] PFLT_INSTANCE Instance,
    [in] PKTRANSACTION Transaction,
    [in, optional] PFLT_CONTEXT TransactionContext
);

VOID FLTAPI FltCloseClientPort(
    [in] PFLT_FILTER Filter,
    [out] PFLT_PORT *ClientPort
);

NTSTATUS FLTAPI FltRollbackEnlistment(
    [in] PFLT_INSTANCE Instance,
    [in] PKTRANSACTION Transaction,
    [in, optional] PFLT_CONTEXT TransactionContext
);

VOID FLTAPI FltUninitializeOplock(
    [in] POPLOCK Oplock
);

NTSTATUS FLTAPI FltRequestSecurityInfoOnCreateCompletion(
    PFLT_FILTER Filter,
    PFLT_CALLBACK_DATA Data,
    SECURITY_INFORMATION SecurityInformation
);

VOID FLTAPI FltFreeSecurityDescriptor(
    [in] PSECURITY_DESCRIPTOR SecurityDescriptor
);

BOOLEAN FLTAPI FltOplockIsSharedRequest(
    [in] PFLT_CALLBACK_DATA CallbackData
);

NTSTATUS FLTAPI FltGetNextExtraCreateParameter(
    [in] PFLT_FILTER Filter,
    [in] PECP_LIST EcpList,
    [in, optional] PVOID CurrentEcpContext,
    [out, optional] LPGUID NextEcpType,
    [out, optional] PVOID *NextEcpContext,
    [out, optional] ULONG *NextEcpContextSize
);

NTSTATUS FLTAPI FltIsDirectory(
    [in] PFILE_OBJECT FileObject,
    [in] PFLT_INSTANCE Instance,
    [out] PBOOLEAN IsDirectory
);

NTSTATUS FLTAPI FltDeleteFileContext(
    [in] PFLT_INSTANCE Instance,
    [in] PFILE_OBJECT FileObject,
    [out] PFLT_CONTEXT *OldContext
);

NTSTATUS FLTAPI FltPrePrepareComplete(
    [in] PFLT_INSTANCE Instance,
    [in] PKTRANSACTION Transaction,
    [in, optional] PFLT_CONTEXT TransactionContext
);

VOID FLTAPI FltPrepareToReuseEcp(
    [in] PFLT_FILTER Filter,
    [in] PVOID EcpContext
);

FLT_PREOP_CALLBACK_STATUS FLTAPI FltOplockBreakToNoneEx(
    [in] POPLOCK Oplock,
    [in] PFLT_CALLBACK_DATA CallbackData,
    [in] ULONG Flags,
    [in, optional] PVOID Context,
    [in, optional] PFLTOPLOCK_WAIT_COMPLETE_ROUTINE WaitCompletionRoutine,
    [in, optional] PFLTOPLOCK_PREPOST_CALLBACKDATA_ROUTINE PrePostCallbackDataRoutine
);

PVOID FLTAPI FltRetrieveFileInfoOnCreateCompletion(
    [in] PFLT_FILTER Filter,
    [in] PFLT_CALLBACK_DATA Data,
    [in] ULONG InfoClass,
    [out] PULONG Size
);

VOID FLTAPI FltFreeExtraCreateParameter(
    [in] PFLT_FILTER Filter,
    [in] PVOID EcpContext
);

NTSTATUS FLTAPI FltGetFilterFromName(
    [in] PCUNICODE_STRING FilterName,
    [out] PFLT_FILTER *RetFilter
);

PVOID FLTAPI FltGetRoutineAddress(
    [in] PCSTR FltMgrRoutineName
);

VOID FLTAPI FltReferenceFileNameInformation(
    [in] PFLT_FILE_NAME_INFORMATION FileNameInformation
);

BOOLEAN FLTAPI FltFastIoMdlWriteComplete(
    PFLT_INSTANCE InitiatingInstance,
    [in] PFILE_OBJECT FileObject,
    [in] PLARGE_INTEGER FileOffset,
    [in] PMDL MdlChain
);

NTSTATUS FLTAPI FltEnumerateFilters(
    [out] PFLT_FILTER *FilterList,
    [in] ULONG FilterListSize,
    [out] PULONG NumberFiltersReturned
);

NTSTATUS FLTAPI FltCbdqInsertIo(
    [in, out] PFLT_CALLBACK_DATA_QUEUE Cbdq,
    [in] PFLT_CALLBACK_DATA Cbd,
    [in, optional] PFLT_CALLBACK_DATA_QUEUE_IO_CONTEXT Context,
    [in, optional] PVOID InsertContext
);

NTSTATUS FLTAPI FltGetCopyInformationFromCallbackData(
    [in] PFLT_CALLBACK_DATA Data,
    [out] PCOPY_INFORMATION CopyInformation
);

NTSTATUS FLTAPI FltGetVolumeGuidName(
    [in] PFLT_VOLUME Volume,
    [in/out, optional] PUNICODE_STRING VolumeGuidName,
    [out, optional] PULONG BufferSizeNeeded
);

NTSTATUS FLTAPI FltGetFilterFromInstance(
    [in] PFLT_INSTANCE Instance,
    [out] PFLT_FILTER *RetFilter
);

void FLT_IS_FS_FILTER_OPERATION(
    Data
);

NTSTATUS FLTAPI FltCheckAndGrowNameControl(
    [in, out] PFLT_NAME_CONTROL NameCtrl,
    [in] USHORT NewSize
);

VOID FLTAPI FltReleaseContext(
    [in] PFLT_CONTEXT Context
);

VOID FLTAPI FltFreeGenericWorkItem(
    [in] PFLT_GENERIC_WORKITEM FltWorkItem
);

NTSTATUS FLTAPI FltUntagFile(
    [in] PFLT_INSTANCE InitiatingInstance,
    [in] PFILE_OBJECT FileObject,
    [in] ULONG FileTag,
    [in, optional] GUID *Guid
);

FLT_PREOP_CALLBACK_STATUS FLTAPI FltOplockBreakToNone(
    [in] POPLOCK Oplock,
    [in] PFLT_CALLBACK_DATA CallbackData,
    [in, optional] PVOID Context,
    [in, optional] PFLTOPLOCK_WAIT_COMPLETE_ROUTINE WaitCompletionRoutine,
    [in, optional] PFLTOPLOCK_PREPOST_CALLBACKDATA_ROUTINE PrePostCallbackDataRoutine
);

VOID FLTAPI FltDeletePushLock(
    [in] PEX_PUSH_LOCK PushLock
);

void FLT_IS_REISSUED_IO(
    Data
);

NTSTATUS FLTAPI FltParseFileNameInformation(
    [in, out] PFLT_FILE_NAME_INFORMATION FileNameInformation
);

ULONG FLTAPI FltGetRequestorProcessId(
    [in] PFLT_CALLBACK_DATA CallbackData
);

PMDL FltGetSwappedBufferMdlAddress(
    [in] PFLT_CALLBACK_DATA CallbackData
);

VOID FLTAPI FltInitializePushLock(
    [out] PEX_PUSH_LOCK PushLock
);

NTSTATUS FLTAPI FltCreateCommunicationPort(
    PFLT_FILTER Filter,
    PFLT_PORT *ServerPort,
    POBJECT_ATTRIBUTES ObjectAttributes,
    PVOID ServerPortCookie,
    PFLT_CONNECT_NOTIFY ConnectNotifyCallback,
    PFLT_DISCONNECT_NOTIFY DisconnectNotifyCallback,
    PFLT_MESSAGE_NOTIFY MessageNotifyCallback,
    LONG MaxConnections
);

NTSTATUS FLTAPI FltQueryVolumeInformationFile(
    [in] PFLT_INSTANCE Instance,
    [in] PFILE_OBJECT FileObject,
    [out] PVOID FsInformation,
    [in] ULONG Length,
    [in] FS_INFORMATION_CLASS FsInformationClass,
    [out, optional] PULONG LengthReturned
);

VOID FLTAPI FltFreeDeferredIoWorkItem(
    [in] PFLT_DEFERRED_IO_WORKITEM FltWorkItem
);

VOID FLTAPI FltCancelFileOpen(
    [in] PFLT_INSTANCE Instance,
    [in] PFILE_OBJECT FileObject
);

void FLT_IS_SYSTEM_BUFFER(
    Data
);

NTSTATUS FLTAPI FltBuildDefaultSecurityDescriptor(
    [out] PSECURITY_DESCRIPTOR *SecurityDescriptor,
    [in] ACCESS_MASK DesiredAccess
);

VOID FLTAPI FltReleasePushLock(
    [in, out] PEX_PUSH_LOCK PushLock
);

NTSTATUS FLTAPI FltWriteFile(
    [in] PFLT_INSTANCE InitiatingInstance,
    [in] PFILE_OBJECT FileObject,
    [in, optional] PLARGE_INTEGER ByteOffset,
    [in] ULONG Length,
    [in] PVOID Buffer,
    [in] FLT_IO_OPERATION_FLAGS Flags,
    [out, optional] PULONG BytesWritten,
    [in, optional] PFLT_COMPLETED_ASYNC_IO_CALLBACK CallbackRoutine,
    [in, optional] PVOID CallbackContext
);

NTSTATUS FLTAPI FltFlushBuffers(
    [in] PFLT_INSTANCE Instance,
    [in] PFILE_OBJECT FileObject
);

NTSTATUS FLTAPI FltSetFileContext(
    [in] PFLT_INSTANCE Instance,
    [in] PFILE_OBJECT FileObject,
    [in] FLT_SET_CONTEXT_OPERATION Operation,
    [in] PFLT_CONTEXT NewContext,
    [out] PFLT_CONTEXT *OldContext
);

NTSTATUS FLTAPI FltLockUserBuffer(
    [in] PFLT_CALLBACK_DATA CallbackData
);

NTSTATUS FLTAPI FltAllocateCallbackData(
    [in] PFLT_INSTANCE Instance,
    [in, optional] PFILE_OBJECT FileObject,
    [out] PFLT_CALLBACK_DATA *RetNewCallbackData
);

VOID FLTAPI FltClearCallbackDataDirty(
    [in, out] PFLT_CALLBACK_DATA Data
);

FLT_PREOP_CALLBACK_STATUS FLTAPI FltOplockFsctrl(
    [in] POPLOCK Oplock,
    [in] PFLT_CALLBACK_DATA CallbackData,
    [in] ULONG OpenCount
);

NTSTATUS FLTAPI FltGetFilterInformation(
    [in] PFLT_FILTER Filter,
    [in] FILTER_INFORMATION_CLASS InformationClass,
    [out] PVOID Buffer,
    [in] ULONG BufferSize,
    [out] PULONG BytesReturned
);

NTSTATUS FLTAPI FltReadFileEx(
    [in] PFLT_INSTANCE InitiatingInstance,
    [in] PFILE_OBJECT FileObject,
    [in, optional] PLARGE_INTEGER ByteOffset,
    [in] ULONG Length,
    [out] PVOID Buffer,
    [in] FLT_IO_OPERATION_FLAGS Flags,
    [out, optional] PULONG BytesRead,
    [in, optional] PFLT_COMPLETED_ASYNC_IO_CALLBACK CallbackRoutine,
    [in, optional] PVOID CallbackContext,
    [in, optional] PULONG Key,
    [in, optional] PMDL Mdl
);

BOOLEAN FLTAPI FltDoCompletionProcessingWhenSafe(
    [in] PFLT_CALLBACK_DATA Data,
    [in] PCFLT_RELATED_OBJECTS FltObjects,
    [in, optional] PVOID CompletionContext,
    [in] FLT_POST_OPERATION_FLAGS Flags,
    [in] PFLT_POST_OPERATION_CALLBACK SafePostCallback,
    [out] PFLT_POSTOP_CALLBACK_STATUS RetPostOperationStatus
);

NTSTATUS FLTAPI FltEnumerateInstanceInformationByDeviceObject(
    [in] PDEVICE_OBJECT DeviceObject,
    [in] ULONG Index,
    [in] INSTANCE_INFORMATION_CLASS InformationClass,
    [out] PVOID Buffer,
    [in] ULONG BufferSize,
    [out] PULONG BytesReturned
);

NTSTATUS FLTAPI FltDeleteVolumeContext(
    [in] PFLT_FILTER Filter,
    [in] PFLT_VOLUME Volume,
    [out, optional] PFLT_CONTEXT *OldContext
);

PEPROCESS FLTAPI FltGetRequestorProcess(
    [in] PFLT_CALLBACK_DATA CallbackData
);

NTSTATUS FLTAPI FltPropagateIrpExtension(
    [in] PFLT_CALLBACK_DATA SourceData,
    [in/out] PFLT_CALLBACK_DATA TargetData,
    [in] ULONG Flags
);

VOID FLTAPI FltInitializeOplock(
    [out] POPLOCK Oplock
);

NTSTATUS FLTAPI FltObjectReference(
    [in, out] PVOID FltObject
);

NTSTATUS FLTAPI FltGetTopInstance(
    [in] PFLT_VOLUME Volume,
    [out] PFLT_INSTANCE *Instance
);

NTSTATUS FLTAPI FltEnlistInTransaction(
    [in] PFLT_INSTANCE Instance,
    [in] PKTRANSACTION Transaction,
    [in] PFLT_CONTEXT TransactionContext,
    [in] NOTIFICATION_MASK NotificationMask
);

NTSTATUS FLTAPI FltGetSectionContext(
    [in] PFLT_INSTANCE Instance,
    [in] PFILE_OBJECT FileObject,
    [out] PFLT_CONTEXT *Context
);

NTSTATUS FLTAPI FltSetTransactionContext(
    [in] PFLT_INSTANCE Instance,
    [in] PKTRANSACTION Transaction,
    [in] FLT_SET_CONTEXT_OPERATION Operation,
    [in] PFLT_CONTEXT NewContext,
    [out, optional] PFLT_CONTEXT *OldContext
);

NTSTATUS FLTAPI FltSetQuotaInformationFile(
    [in] PFLT_INSTANCE Instance,
    [in] PFILE_OBJECT FileObject,
    [in] PVOID Buffer,
    [in] ULONG Length
);

VOID FLTAPI FltReleasePushLockEx(
    PEX_PUSH_LOCK PushLock,
    ULONG Flags
);

NTSTATUS FLTAPI FltCreateFileEx(
    [in] PFLT_FILTER Filter,
    [in, optional] PFLT_INSTANCE Instance,
    [out] PHANDLE FileHandle,
    [out] PFILE_OBJECT *FileObject,
    [in] ACCESS_MASK DesiredAccess,
    [in] POBJECT_ATTRIBUTES ObjectAttributes,
    [out] PIO_STATUS_BLOCK IoStatusBlock,
    [in, optional] PLARGE_INTEGER AllocationSize,
    [in] ULONG FileAttributes,
    [in] ULONG ShareAccess,
    [in] ULONG CreateDisposition,
    [in] ULONG CreateOptions,
    [in, optional] PVOID EaBuffer,
    [in] ULONG EaLength,
    [in] ULONG Flags
);

NTSTATUS FLTAPI FltSetActivityIdCallbackData(
    [in, out] PFLT_CALLBACK_DATA CallbackData,
    [in, optional] LPCGUID Guid
);

NTSTATUS FLTAPI FltAttachVolume(
    [in, out] PFLT_FILTER Filter,
    [in, out] PFLT_VOLUME Volume,
    [in, optional] PCUNICODE_STRING InstanceName,
    [out] PFLT_INSTANCE *RetInstance
);

FLT_PREOP_CALLBACK_STATUS FLTAPI FltProcessFileLock(
    [in] PFILE_LOCK FileLock,
    [in] PFLT_CALLBACK_DATA CallbackData,
    [in, optional] PVOID Context
);

NTSTATUS FLTAPI FltCancellableWaitForMultipleObjects(
    [in] ULONG Count,
    [in] PVOID [] ObjectArray,
    [in] WAIT_TYPE WaitType,
    [in, optional] PLARGE_INTEGER Timeout,
    [in, optional] PKWAIT_BLOCK WaitBlockArray,
    [in] PFLT_CALLBACK_DATA CallbackData
);

BOOLEAN FLTAPI FltIsEcpFromUserMode(
    [in] PFLT_FILTER Filter,
    [in] PVOID EcpContext
);

NTSTATUS FLTAPI FltRequestFileInfoOnCreateCompletion(
    PFLT_FILTER Filter,
    PFLT_CALLBACK_DATA Data,
    ULONG InfoClassFlags
);

BOOLEAN FLTAPI FltOplockKeysEqual(
    [in, optional] PFILE_OBJECT Fo1,
    [in, optional] PFILE_OBJECT Fo2
);

NTSTATUS FLTAPI FltEnumerateInstances(
    [in, optional] PFLT_VOLUME Volume,
    [in, optional] PFLT_FILTER Filter,
    [out] PFLT_INSTANCE *InstanceList,
    [in] ULONG InstanceListSize,
    [out] PULONG NumberInstancesReturned
);

NTSTATUS FLTAPI FltGetActivityIdCallbackData(
    [in] PFLT_CALLBACK_DATA CallbackData,
    [out] LPGUID Guid
);

VOID FLTAPI FltUnregisterFilter(
    [in] PFLT_FILTER Filter
);

NTSTATUS FLTAPI FltGetTunneledName(
    [in] PFLT_CALLBACK_DATA CallbackData,
    [in] PFLT_FILE_NAME_INFORMATION FileNameInformation,
    [out] PFLT_FILE_NAME_INFORMATION *RetTunneledFileNameInformation
);

NTSTATUS FLTAPI FltRegisterForDataScan(
    [in] PFLT_INSTANCE Instance
);

PVOID FLTAPI FltAllocatePoolAlignedWithTag(
    [in] PFLT_INSTANCE Instance,
    [in] POOL_TYPE PoolType,
    [in] SIZE_T NumberOfBytes,
    [in] ULONG Tag
);

NTSTATUS FLTAPI FltGetUpperInstance(
    [in] PFLT_INSTANCE CurrentInstance,
    [out] PFLT_INSTANCE *UpperInstance
);

VOID FLTAPI FltFreeFileLock(
    [in] PFILE_LOCK FileLock
);

NTSTATUS FLTAPI FltDeleteInstanceContext(
    [in] PFLT_INSTANCE Instance,
    [out] PFLT_CONTEXT *OldContext
);

NTSTATUS FLTAPI FltGetFileNameInformation(
    [in] PFLT_CALLBACK_DATA CallbackData,
    [in] FLT_FILE_NAME_OPTIONS NameOptions,
    [out] PFLT_FILE_NAME_INFORMATION *FileNameInformation
);

VOID FLTAPI FltAcquireResourceExclusive(
    [in/out] PERESOURCE Resource
);

NTSTATUS FLTAPI FltEnumerateInstanceInformationByVolume(
    [in] PFLT_VOLUME Volume,
    [in] ULONG Index,
    [in] INSTANCE_INFORMATION_CLASS InformationClass,
    [out] PVOID Buffer,
    [in] ULONG BufferSize,
    [out] PULONG BytesReturned
);

NTSTATUS FLTAPI FltCopyOpenReparseList(
    [in] PFLT_FILTER Filter,
    [in] PFLT_CALLBACK_DATA Data,
    [in, out] PECP_LIST EcpList
);

NTSTATUS FLTAPI FltGetBottomInstance(
    [in] PFLT_VOLUME Volume,
    [out] PFLT_INSTANCE *Instance
);

NTSTATUS FLTAPI FltGetLowerInstance(
    [in] PFLT_INSTANCE CurrentInstance,
    [out] PFLT_INSTANCE *LowerInstance
);

NTSTATUS FLTAPI FltSetIoPriorityHintIntoCallbackData(
    [in] PFLT_CALLBACK_DATA Data,
    [in] IO_PRIORITY_HINT PriorityHint
);

NTSTATUS FLTAPI FltGetEcpListFromCallbackData(
    [in] PFLT_FILTER Filter,
    PFLT_CALLBACK_DATA CallbackData,
    [out] PECP_LIST *EcpList
);

NTSTATUS FLTAPI FltLoadFilter(
    [in] PCUNICODE_STRING FilterName
);

VOID FLTAPI FltCbdqEnable(
    [in, out] PFLT_CALLBACK_DATA_QUEUE Cbdq
);

NTSTATUS FLTAPI FltClearCancelCompletion(
    [in] PFLT_CALLBACK_DATA CallbackData
);

NTSTATUS FLTAPI FltDeleteTransactionContext(
    [in] PFLT_INSTANCE Instance,
    [in] PKTRANSACTION Transaction,
    [out, optional] PFLT_CONTEXT *OldContext
);

VOID FLTAPI FltObjectDereference(
    [in, out] PVOID FltObject
);

BOOLEAN FLTAPI FltIsEcpAcknowledged(
    [in] PFLT_FILTER Filter,
    [in] PVOID EcpContext
);

BOOLEAN FLTAPI FltFastIoPrepareMdlWrite(
    PFLT_INSTANCE InitiatingInstance,
    [in] PFILE_OBJECT FileObject,
    [in] PLARGE_INTEGER FileOffset,
    [in] ULONG Length,
    [in] ULONG LockKey,
    [out] PMDL *MdlChain,
    [out] PIO_STATUS_BLOCK IoStatus
);

NTSTATUS FLTAPI FltApplyPriorityInfoThread(
    [in] PIO_PRIORITY_INFO InputPriorityInfo,
    [out, optional] PIO_PRIORITY_INFO OutputPriorityInfo,
    [in] PETHREAD Thread
);

HANDLE FLTAPI FltGetRequestorProcessIdEx(
    [in] PFLT_CALLBACK_DATA CallbackData
);

BOOLEAN FLTAPI FltOplockIsFastIoPossible(
    [in] POPLOCK Oplock
);

BOOLEAN FLTAPI FltSupportsFileContexts(
    [in] PFILE_OBJECT FileObject
);

PFLT_GENERIC_WORKITEM FLTAPI FltAllocateGenericWorkItem();

NTSTATUS FLTAPI FltRollbackComplete(
    [in] PFLT_INSTANCE Instance,
    [in] PKTRANSACTION Transaction,
    [in, optional] PFLT_CONTEXT TransactionContext
);

NTSTATUS FLTAPI FltQueryInformationByName(
    [in] PFLT_FILTER Filter,
    [in, optional] PFLT_INSTANCE Instance,
    [in] POBJECT_ATTRIBUTES ObjectAttributes,
    [out] PIO_STATUS_BLOCK IoStatusBlock,
    [out] PVOID FileInformation,
    [in] ULONG Length,
    [in] FILE_INFORMATION_CLASS FileInformationClass,
    [in, optional] PIO_DRIVER_CREATE_CONTEXT DriverContext
);

NTSTATUS FLTAPI FltGetVolumeFromDeviceObject(
    [in] PFLT_FILTER Filter,
    [in] PDEVICE_OBJECT DeviceObject,
    [out] PFLT_VOLUME *RetVolume
);

VOID FLTAPI FltAcquirePushLockSharedEx(
    PEX_PUSH_LOCK PushLock,
    ULONG Flags
);

NTSTATUS FLTAPI FltCreateMailslotFile(
    [in] PFLT_FILTER Filter,
    [in, optional] PFLT_INSTANCE Instance,
    [out] PHANDLE FileHandle,
    [out, optional] PFILE_OBJECT *FileObject,
    [in] ULONG DesiredAccess,
    [in] POBJECT_ATTRIBUTES ObjectAttributes,
    [out] PIO_STATUS_BLOCK IoStatusBlock,
    [in] ULONG CreateOptions,
    [in] ULONG MailslotQuota,
    [in] ULONG MaximumMessageSize,
    [in] PLARGE_INTEGER ReadTimeout,
    [in, optional] PIO_DRIVER_CREATE_CONTEXT DriverContext
);

NTSTATUS FLTAPI FltCommitComplete(
    [in] PFLT_INSTANCE Instance,
    [in] PKTRANSACTION Transaction,
    [in, optional] PFLT_CONTEXT TransactionContext
);

NTSTATUS FLTAPI FltAllocateContext(
    [in] PFLT_FILTER Filter,
    [in] FLT_CONTEXT_TYPE ContextType,
    [in] SIZE_T ContextSize,
    [in] POOL_TYPE PoolType,
    [out] PFLT_CONTEXT *ReturnedContext
);

NTSTATUS FLTAPI FltCreateSystemVolumeInformationFolder(
    [in] PFLT_INSTANCE Instance
);

NTSTATUS FLTAPI FltGetDeviceObject(
    [in] PFLT_VOLUME Volume,
    [out] PDEVICE_OBJECT *DeviceObject
);

NTSTATUS FLTAPI FltFindExtraCreateParameter(
    [in] PFLT_FILTER Filter,
    [in] PECP_LIST EcpList,
    [in] LPCGUID EcpType,
    [out, optional] PVOID *EcpContext,
    [out, optional] ULONG *EcpContextSize
);

NTSTATUS FLTAPI FltGetVolumeContext(
    [in] PFLT_FILTER Filter,
    [in] PFLT_VOLUME Volume,
    [out] PFLT_CONTEXT *Context
);

FLT_PREOP_CALLBACK_STATUS FLTAPI FltOplockFsctrlEx(
    [in] POPLOCK Oplock,
    [in] PFLT_CALLBACK_DATA CallbackData,
    [in] ULONG OpenCount,
    [in] ULONG Flags
);

NTSTATUS FLTAPI FltRetrieveIoPriorityInfo(
    [in, optional] PFLT_CALLBACK_DATA Data,
    [in, optional] PFILE_OBJECT FileObject,
    [in, optional] PETHREAD Thread,
    [in, out] PIO_PRIORITY_INFO PriorityInfo
);

NTSTATUS FLTAPI FltReadFile(
    [in] PFLT_INSTANCE InitiatingInstance,
    [in] PFILE_OBJECT FileObject,
    [in, optional] PLARGE_INTEGER ByteOffset,
    [in] ULONG Length,
    [out] PVOID Buffer,
    [in] FLT_IO_OPERATION_FLAGS Flags,
    [out, optional] PULONG BytesRead,
    [in, optional] PFLT_COMPLETED_ASYNC_IO_CALLBACK CallbackRoutine,
    [in, optional] PVOID CallbackContext
);

NTSTATUS FLTAPI FltDecodeParameters(
    [in] PFLT_CALLBACK_DATA CallbackData,
    [out] PMDL **MdlAddressPointer,
    [out] PVOID **Buffer,
    [out] PULONG *Length,
    [out, optional] LOCK_OPERATION *DesiredAccess
);

VOID FLTAPI FltAcquirePushLockExclusive(
    [in, out] PEX_PUSH_LOCK PushLock
);

NTSTATUS FLTAPI FltSetIoPriorityHintIntoFileObject(
    [in] PFILE_OBJECT FileObject,
    [in] IO_PRIORITY_HINT PriorityHint
);

IO_PRIORITY_HINT FLTAPI FltGetIoPriorityHint(
    [in] PFLT_CALLBACK_DATA Data
);

VOID FLTAPI FltReleaseFileNameInformation(
    [in] PFLT_FILE_NAME_INFORMATION FileNameInformation
);

NTSTATUS FLTAPI FltSendMessage(
    [in] PFLT_FILTER Filter,
    [in] PFLT_PORT *ClientPort,
    [in] PVOID SenderBuffer,
    [in] ULONG SenderBufferLength,
    [out, optional] PVOID ReplyBuffer,
    [in, out] PULONG ReplyLength,
    [in, optional] PLARGE_INTEGER Timeout
);

BOOLEAN FLTAPI FltSupportsStreamHandleContexts(
    [in] PFILE_OBJECT FileObject
);

NTSTATUS FLTAPI FltGetRequestorSessionId(
    [in] PFLT_CALLBACK_DATA CallbackData,
    [out] PULONG SessionId
);

VOID FLTAPI FltReleaseContextsEx(
    [in] SIZE_T ContextsSize,
    [in] PFLT_RELATED_CONTEXTS_EX Contexts
);

IO_PRIORITY_HINT FLTAPI FltGetIoPriorityHintFromCallbackData(
    [in] PFLT_CALLBACK_DATA Data
);

VOID FLTAPI FltGetContexts(
    PCFLT_RELATED_OBJECTS FltObjects,
    FLT_CONTEXT_TYPE DesiredContexts,
    PFLT_RELATED_CONTEXTS Contexts
);

VOID FLTAPI FltReuseCallbackData(
    [in, out] PFLT_CALLBACK_DATA CallbackData
);

NTSTATUS FLTAPI FltDeleteStreamHandleContext(
    [in] PFLT_INSTANCE Instance,
    [in] PFILE_OBJECT FileObject,
    [out] PFLT_CONTEXT *OldContext
);

NTSTATUS FLTAPI FltUnloadFilter(
    [in] PCUNICODE_STRING FilterName
);

NTSTATUS FLTAPI FltQueryInformationFile(
    [in] PFLT_INSTANCE Instance,
    [in] PFILE_OBJECT FileObject,
    [out] PVOID FileInformation,
    [in] ULONG Length,
    [in] FILE_INFORMATION_CLASS FileInformationClass,
    [out, optional] PULONG LengthReturned
);

BOOLEAN FLTAPI FltCurrentBatchOplock(
    [in] POPLOCK Oplock
);

void FLT_IS_FASTIO_OPERATION(
    [in] Data
);

VOID FLTAPI FltAcquireResourceShared(
    [in/out] PERESOURCE Resource
);

NTSTATUS FLTAPI FltGetContextsEx(
    [in] PCFLT_RELATED_OBJECTS FltObjects,
    [in] FLT_CONTEXT_TYPE DesiredContexts,
    [in] SIZE_T ContextsSize,
    [out] PFLT_RELATED_CONTEXTS_EX Contexts
);

VOID FLTAPI FltPerformSynchronousIo(
    [in, out] PFLT_CALLBACK_DATA CallbackData
);

BOOLEAN FLTAPI FltCheckLockForWriteAccess(
    [in] PFILE_LOCK FileLock,
    [in] PFLT_CALLBACK_DATA CallbackData
);

VOID FLTAPI FltFreeOpenReparseList(
    [in] PFLT_FILTER Filter,
    [in] PECP_LIST EcpList
);

NTSTATUS FLTAPI FltQueryEaFile(
    [in] PFLT_INSTANCE Instance,
    [in] PFILE_OBJECT FileObject,
    [out] PVOID ReturnedEaData,
    [in] ULONG Length,
    [in] BOOLEAN ReturnSingleEntry,
    [in, optional] PVOID EaList,
    [in] ULONG EaListLength,
    [in, optional] PULONG EaIndex,
    [in] BOOLEAN RestartScan,
    [out, optional] PULONG LengthReturned
);

VOID FLTAPI FltRemoveOpenReparseEntry(
    [in] PFLT_FILTER Filter,
    [in] PFLT_CALLBACK_DATA Data,
    [in] POPEN_REPARSE_LIST_ENTRY OpenReparseEntry
);

VOID FLTAPI FltUninitializeFileLock(
    [in] PFILE_LOCK FileLock
);

NTSTATUS FLTAPI FltSetVolumeContext(
    [in] PFLT_VOLUME Volume,
    [in] FLT_SET_CONTEXT_OPERATION Operation,
    [in] PFLT_CONTEXT NewContext,
    [out, optional] PFLT_CONTEXT *OldContext
);

NTSTATUS FLTAPI FltEnumerateInstanceInformationByVolumeName(
    [in] PUNICODE_STRING VolumeName,
    [in] ULONG Index,
    [in] INSTANCE_INFORMATION_CLASS InformationClass,
    [out] PVOID Buffer,
    [in] ULONG BufferSize,
    [out] PULONG BytesReturned
);

NTSTATUS FLTAPI FltGetInstanceContext(
    [in] PFLT_INSTANCE Instance,
    [out] PFLT_CONTEXT *Context
);

NTSTATUS FLTAPI FltGetDestinationFileNameInformation(
    [in] PFLT_INSTANCE Instance,
    [in] PFILE_OBJECT FileObject,
    [in, optional] HANDLE RootDirectory,
    [in] PWSTR FileName,
    [in] ULONG FileNameLength,
    [in] FLT_FILE_NAME_OPTIONS NameOptions,
    [out] PFLT_FILE_NAME_INFORMATION *RetFileNameInformation
);

IO_PRIORITY_HINT FLTAPI FltGetIoPriorityHintFromThread(
    [in] PETHREAD Thread
);

NTSTATUS FLTAPI FltQueueDeferredIoWorkItem(
    [in] PFLT_DEFERRED_IO_WORKITEM FltWorkItem,
    [in] PFLT_CALLBACK_DATA Data,
    [in] PFLT_DEFERRED_IO_WORKITEM_ROUTINE WorkerRoutine,
    [in] WORK_QUEUE_TYPE QueueType,
    [in] PVOID Context
);

NTSTATUS FLTAPI FltIsVolumeSnapshot(
    [in] PVOID FltObject,
    [out] PBOOLEAN IsSnapshotVolume
);

NTSTATUS FLTAPI FltMupGetProviderInfoFromFileObject(
    PFLT_INSTANCE Instance,
    PFILE_OBJECT FileObject,
    ULONG Level,
    PVOID Buffer,
    PULONG BufferSize
);

BOOLEAN FLTAPI FltIs32bitProcess(
    [in, optional] PFLT_CALLBACK_DATA CallbackData
);

PVOID FLTAPI FltGetNewSystemBufferAddress(
    [in] PFLT_CALLBACK_DATA CallbackData
);

NTSTATUS FLTAPI FltAdjustDeviceStackSizeForIoRedirection(
    [in] PFLT_INSTANCE SourceInstance,
    [in] PFLT_INSTANCE TargetInstance,
    [out, optional] PBOOLEAN SourceDeviceStackSizeModified
);

VOID FLTAPI FltCbdqDisable(
    [in, out] PFLT_CALLBACK_DATA_QUEUE Cbdq
);

NTSTATUS FLTAPI FltCreateNamedPipeFile(
    [in] PFLT_FILTER Filter,
    [in, optional] PFLT_INSTANCE Instance,
    [out] PHANDLE FileHandle,
    [out, optional] PFILE_OBJECT *FileObject,
    [in] ULONG DesiredAccess,
    [in] POBJECT_ATTRIBUTES ObjectAttributes,
    [out] PIO_STATUS_BLOCK IoStatusBlock,
    [in] ULONG ShareAccess,
    [in] ULONG CreateDisposition,
    [in] ULONG CreateOptions,
    [in] ULONG NamedPipeType,
    [in] ULONG ReadMode,
    [in] ULONG CompletionMode,
    [in] ULONG MaximumInstances,
    ULONG InboundQuota,
    ULONG OutboundQuota,
    [in, optional] PLARGE_INTEGER DefaultTimeout,
    [in, optional] PIO_DRIVER_CREATE_CONTEXT DriverContext
);

NTSTATUS FLTAPI FltRegisterFilter(
    [in] PDRIVER_OBJECT Driver,
    [in] const FLT_REGISTRATION *Registration,
    [out] PFLT_FILTER *RetFilter
);

BOOLEAN FLTAPI FltFastIoMdlRead(
    PFLT_INSTANCE InitiatingInstance,
    [in] PFILE_OBJECT FileObject,
    [in] PLARGE_INTEGER FileOffset,
    [in] ULONG Length,
    [in] ULONG LockKey,
    [out] PMDL *MdlChain,
    [out] PIO_STATUS_BLOCK IoStatus
);

VOID FLTAPI FltFreeCallbackData(
    [in] PFLT_CALLBACK_DATA CallbackData
);

NTSTATUS FLTAPI FltAllocateExtraCreateParameter(
    [in] PFLT_FILTER Filter,
    [in] LPCGUID EcpType,
    [in] ULONG SizeOfContext,
    [in] FSRTL_ALLOCATE_ECP_FLAGS Flags,
    [in, optional] PFSRTL_EXTRA_CREATE_PARAMETER_CLEANUP_CALLBACK CleanupCallback,
    [in] ULONG PoolTag,
    [out] PVOID *EcpContext
);

NTSTATUS FLTAPI FltSetCancelCompletion(
    [in] PFLT_CALLBACK_DATA CallbackData,
    [in] PFLT_COMPLETE_CANCELED_CALLBACK CanceledCallback
);

NTSTATUS FLTAPI FltCommitFinalizeComplete(
    [in] PFLT_INSTANCE Instance,
    [in] PKTRANSACTION Transaction,
    [in, optional] PFLT_CONTEXT TransactionContext
);

NTSTATUS FLTAPI FltGetVolumeProperties(
    [in] PFLT_VOLUME Volume,
    [out] PFLT_VOLUME_PROPERTIES VolumeProperties,
    ULONG VolumePropertiesLength,
    [out] PULONG LengthReturned
);

NTSTATUS FLTAPI FltEnumerateVolumes(
    [in] PFLT_FILTER Filter,
    [out] PFLT_VOLUME *VolumeList,
    [in] ULONG VolumeListSize,
    [out] PULONG NumberVolumesReturned
);

NTSTATUS FLTAPI FltRemoveExtraCreateParameter(
    [in] PFLT_FILTER Filter,
    [in, out] PECP_LIST EcpList,
    [in] LPCGUID EcpType,
    [out] PVOID *EcpContext,
    [out, optional] ULONG *EcpContextSize
);

NTSTATUS FLTAPI FltCloseSectionForDataScan(
    [in] PFLT_CONTEXT SectionContext
);

NTSTATUS FLTAPI FltSetInformationFile(
    [in] PFLT_INSTANCE Instance,
    [in] PFILE_OBJECT FileObject,
    [in] PVOID FileInformation,
    [in] ULONG Length,
    [in] FILE_INFORMATION_CLASS FileInformationClass
);

BOOLEAN FLTAPI FltIsIoCanceled(
    [in] PFLT_CALLBACK_DATA CallbackData
);

NTSTATUS FLTAPI FltClose(
    [in] HANDLE FileHandle
);

PFLT_CALLBACK_DATA FLTAPI FltCbdqRemoveNextIo(
    [in, out] PFLT_CALLBACK_DATA_QUEUE Cbdq,
    [in, optional] PVOID PeekContext
);

VOID FLTAPI FltSetCallbackDataDirty(
    [in, out] PFLT_CALLBACK_DATA Data
);

NTSTATUS FLTAPI FltStartFiltering(
    [in] PFLT_FILTER Filter
);

NTSTATUS FLTAPI FltRetrieveFileInfoOnCreateCompletionEx(
    [in] PFLT_FILTER Filter,
    [in] PFLT_CALLBACK_DATA Data,
    [in] ULONG InfoClass,
    [out] PULONG RetInfoSize,
    [out] PVOID *RetInfoBuffer
);

NTSTATUS FLTAPI FltCreateSectionForDataScan(
    [in] PFLT_INSTANCE Instance,
    [in] PFILE_OBJECT FileObject,
    [in] PFLT_CONTEXT SectionContext,
    [in] ACCESS_MASK DesiredAccess,
    [in, optional] POBJECT_ATTRIBUTES ObjectAttributes,
    [in, optional] PLARGE_INTEGER MaximumSize,
    [in] ULONG SectionPageProtection,
    [in] ULONG AllocationAttributes,
    [in] ULONG Flags,
    [out] PHANDLE SectionHandle,
    [out] PVOID *SectionObject,
    [out, optional] PLARGE_INTEGER SectionFileSize
);

BOOLEAN FLTAPI FltSupportsFileContextsEx(
    [in] PFILE_OBJECT FileObject,
    [in, optional] PFLT_INSTANCE Instance
);

BOOLEAN FLTAPI FltCurrentOplock(
    [in] POPLOCK Oplock
);

NTSTATUS FLTAPI FltOpenVolume(
    [in] PFLT_INSTANCE Instance,
    [out] PHANDLE VolumeHandle,
    [out] PFILE_OBJECT *VolumeFileObject
);

VOID FLTAPI FltReleaseContexts(
    [in] PFLT_RELATED_CONTEXTS Contexts
);

NTSTATUS FLTAPI FltGetVolumeFromName(
    [in] PFLT_FILTER Filter,
    [in] PCUNICODE_STRING VolumeName,
    [out] PFLT_VOLUME *RetVolume
);

BOOLEAN FLTAPI FltCancelIo(
    [in] PFLT_CALLBACK_DATA CallbackData
);

NTSTATUS FLTAPI FltPropagateActivityIdToThread(
    [in] PFLT_CALLBACK_DATA CallbackData,
    [in/out] LPGUID PropagateId,
    [out] LPCGUID *OriginalId
);

BOOLEAN FLTAPI FltSupportsStreamContexts(
    [in] PFILE_OBJECT FileObject
);

NTSTATUS FLTAPI FltCreateFileEx2(
    [in] PFLT_FILTER Filter,
    [in, optional] PFLT_INSTANCE Instance,
    [out] PHANDLE FileHandle,
    [out, optional] PFILE_OBJECT *FileObject,
    [in] ACCESS_MASK DesiredAccess,
    [in] POBJECT_ATTRIBUTES ObjectAttributes,
    [out] PIO_STATUS_BLOCK IoStatusBlock,
    [in, optional] PLARGE_INTEGER AllocationSize,
    [in] ULONG FileAttributes,
    [in] ULONG ShareAccess,
    [in] ULONG CreateDisposition,
    [in] ULONG CreateOptions,
    [in, optional] PVOID EaBuffer,
    [in] ULONG EaLength,
    [in] ULONG Flags,
    [in, optional] PIO_DRIVER_CREATE_CONTEXT DriverContext
);

