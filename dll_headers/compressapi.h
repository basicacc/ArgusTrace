BOOL SetDecompressorInformation(
    [in] DECOMPRESSOR_HANDLE DecompressorHandle,
    [in] COMPRESS_INFORMATION_CLASS CompressInformationClass,
    [in] LPCVOID CompressInformation,
    [in] SIZE_T CompressInformationSize
);

BOOL SetCompressorInformation(
    [in] COMPRESSOR_HANDLE CompressorHandle,
    [in] COMPRESS_INFORMATION_CLASS CompressInformationClass,
    [in] LPCVOID CompressInformation,
    [in] SIZE_T CompressInformationSize
);

BOOL QueryDecompressorInformation(
    [in] DECOMPRESSOR_HANDLE DecompressorHandle,
    [in] COMPRESS_INFORMATION_CLASS CompressInformationClass,
    [out] PVOID CompressInformation,
    [in] SIZE_T CompressInformationSize
);

BOOL ResetDecompressor(
    [in] DECOMPRESSOR_HANDLE DecompressorHandle
);

BOOL ResetCompressor(
    [in] COMPRESSOR_HANDLE CompressorHandle
);

BOOL Compress(
    [in] COMPRESSOR_HANDLE CompressorHandle,
    [in] LPCVOID UncompressedData,
    [in] SIZE_T UncompressedDataSize,
    [out] PVOID CompressedBuffer,
    [in] SIZE_T CompressedBufferSize,
    [out] PSIZE_T CompressedDataSize
);

BOOL CreateCompressor(
    [in] DWORD Algorithm,
    [in, optional] PCOMPRESS_ALLOCATION_ROUTINES AllocationRoutines,
    [out] PCOMPRESSOR_HANDLE CompressorHandle
);

BOOL CloseCompressor(
    [in] COMPRESSOR_HANDLE CompressorHandle
);

BOOL CreateDecompressor(
    [in] DWORD Algorithm,
    [in, optional] PCOMPRESS_ALLOCATION_ROUTINES AllocationRoutines,
    [out] PDECOMPRESSOR_HANDLE DecompressorHandle
);

BOOL Decompress(
    [in] DECOMPRESSOR_HANDLE DecompressorHandle,
    [in] LPCVOID CompressedData,
    [in] SIZE_T CompressedDataSize,
    [out] PVOID UncompressedBuffer,
    [in] SIZE_T UncompressedBufferSize,
    [out] PSIZE_T UncompressedDataSize
);

BOOL CloseDecompressor(
    [in] DECOMPRESSOR_HANDLE DecompressorHandle
);

BOOL QueryCompressorInformation(
    [in] COMPRESSOR_HANDLE CompressorHandle,
    [in] COMPRESS_INFORMATION_CLASS CompressInformationClass,
    [out] PVOID CompressInformation,
    [in] SIZE_T CompressInformationSize
);

