NTSTATUS WdfObjectCreate(
    [in, optional] PWDF_OBJECT_ATTRIBUTES Attributes,
    [out] WDFOBJECT *Object
);

void WDF_TYPE_NAME_POINTER_TYPE(
    _contexttype
);

void WDF_OBJECT_ATTRIBUTES_INIT(
    [out] PWDF_OBJECT_ATTRIBUTES Attributes
);

PVOID WdfObjectGetTypedContextWorker(
    [in] WDFOBJECT Handle,
    [in] PCWDF_OBJECT_CONTEXT_TYPE_INFO TypeInfo
);

NTSTATUS WdfObjectQuery(
    [in] WDFOBJECT Object,
    [in] const GUID *Guid,
    [in] ULONG QueryBufferLength,
    [out] PVOID QueryBuffer
);

void WdfObjectDereferenceActual(
    [in] WDFOBJECT Handle,
    [in, optional] PVOID Tag,
    [in] LONG Line,
    [in, optional] PCCH File
);

void WdfObjectDelete(
    [in] WDFOBJECT Object
);

void WdfObjectReferenceActual(
    [in] WDFOBJECT Handle,
    [in, optional] PVOID Tag,
    [in] LONG Line,
    [in] PCCH File
);

NTSTATUS WdfObjectAllocateContext(
    [in] WDFOBJECT Handle,
    [in] PWDF_OBJECT_ATTRIBUTES ContextAttributes,
    [out] PVOID *Context
);

WDFOBJECT WdfObjectContextGetObject(
    [in] PVOID ContextPointer
);

void WDF_TYPE_NAME_TO_TYPE_INFO(
    _contexttype
);

void WDF_GET_CONTEXT_TYPE_INFO(
    _contexttype
);

