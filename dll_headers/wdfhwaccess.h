USHORT WDF_READ_PORT_USHORT(
    [in] WDFDEVICE Device,
    [in] PUSHORT Port
);

void WDF_READ_PORT_BUFFER_UCHAR(
    [in] WDFDEVICE Device,
    [in] PUCHAR Port,
    [out] PUCHAR Buffer,
    [in] ULONG Count
);

void WDF_WRITE_PORT_BUFFER_USHORT(
    [in] WDFDEVICE Device,
    [in] PUSHORT Port,
    [in] PUSHORT Buffer,
    [in] ULONG Count
);

void WDF_WRITE_REGISTER_BUFFER_ULONG64(
    [in] WDFDEVICE Device,
    [in] PULONG64 Register,
    [in] PULONG64 Buffer,
    [in] ULONG Count
);

ULONG WDF_READ_PORT_ULONG(
    [in] WDFDEVICE Device,
    [in] PULONG Port
);

void WDF_READ_REGISTER_BUFFER_USHORT(
    [in] WDFDEVICE Device,
    [in] PUSHORT Register,
    [out] PUSHORT Buffer,
    [in] ULONG Count
);

ULONG64 WDF_READ_REGISTER_ULONG64(
    [in] WDFDEVICE Device,
    [in] PULONG64 Register
);

ULONG WDF_READ_REGISTER_ULONG(
    [in] WDFDEVICE Device,
    [in] PULONG Register
);

void WDF_READ_PORT_BUFFER_ULONG(
    [in] WDFDEVICE Device,
    [in] PULONG Port,
    [out] PULONG Buffer,
    [in] ULONG Count
);

void WDF_WRITE_PORT_BUFFER_UCHAR(
    [in] WDFDEVICE Device,
    [in] PUCHAR Port,
    [in] PUCHAR Buffer,
    [in] ULONG Count
);

void WDF_WRITE_REGISTER_UCHAR(
    [in] WDFDEVICE Device,
    [in] PUCHAR Register,
    [in] UCHAR Value
);

void WDF_WRITE_REGISTER_BUFFER_ULONG(
    [in] WDFDEVICE Device,
    [in] PULONG Register,
    [in] PULONG Buffer,
    [in] ULONG Count
);

void WDF_READ_REGISTER_BUFFER_UCHAR(
    [in] WDFDEVICE Device,
    [in] PUCHAR Register,
    [out] PUCHAR Buffer,
    [in] ULONG Count
);

void WDF_READ_REGISTER_BUFFER_ULONG64(
    [in] WDFDEVICE Device,
    [in] PULONG64 Register,
    [out] PULONG64 Buffer,
    [in] ULONG Count
);

void WDF_WRITE_REGISTER_ULONG64(
    [in] WDFDEVICE Device,
    [in] PULONG64 Register,
    [in] ULONG64 Value
);

UCHAR WDF_READ_PORT_UCHAR(
    [in] WDFDEVICE Device,
    [in] PUCHAR Port
);

WDF_EXTERN_C_START UCHAR WDF_READ_REGISTER_UCHAR(
    [in] WDFDEVICE Device,
    [in] PUCHAR Register
);

void WDF_READ_PORT_BUFFER_USHORT(
    [in] WDFDEVICE Device,
    [in] PUSHORT Port,
    [out] PUSHORT Buffer,
    [in] ULONG Count
);

void WDF_READ_REGISTER_BUFFER_ULONG(
    [in] WDFDEVICE Device,
    [in] PULONG Register,
    [out] PULONG Buffer,
    [in] ULONG Count
);

void WDF_WRITE_REGISTER_BUFFER_USHORT(
    [in] WDFDEVICE Device,
    [in] PUSHORT Register,
    [in] PUSHORT Buffer,
    [in] ULONG Count
);

void WDF_WRITE_PORT_USHORT(
    [in] WDFDEVICE Device,
    [in] PUSHORT Port,
    [in] USHORT Value
);

void WDF_WRITE_REGISTER_ULONG(
    [in] WDFDEVICE Device,
    [in] PULONG Register,
    [in] ULONG Value
);

void WDF_WRITE_PORT_UCHAR(
    [in] WDFDEVICE Device,
    [in] PUCHAR Port,
    [in] UCHAR Value
);

USHORT WDF_READ_REGISTER_USHORT(
    [in] WDFDEVICE Device,
    [in] PUSHORT Register
);

void WDF_WRITE_REGISTER_BUFFER_UCHAR(
    [in] WDFDEVICE Device,
    [in] PUCHAR Register,
    [in] PUCHAR Buffer,
    [in] ULONG Count
);

void WDF_WRITE_PORT_BUFFER_ULONG(
    [in] WDFDEVICE Device,
    [in] PULONG Port,
    [in] PULONG Buffer,
    [in] ULONG Count
);

void WDF_WRITE_PORT_ULONG(
    [in] WDFDEVICE Device,
    [in] PULONG Port,
    [in] ULONG Value
);

void WDF_WRITE_REGISTER_USHORT(
    [in] WDFDEVICE Device,
    [in] PUSHORT Register,
    [in] USHORT Value
);

