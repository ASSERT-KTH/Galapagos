size_t LZ4F_uncompressedUpdate(LZ4F_cctx* cctxPtr,
                               void* dstBuffer, size_t dstCapacity,
                         const void* srcBuffer, size_t srcSize,
                         const LZ4F_compressOptions_t* compressOptionsPtr)
{
    return LZ4F_compressUpdateImpl(cctxPtr,
                                   dstBuffer, dstCapacity,
                                   srcBuffer, srcSize,
                                   compressOptionsPtr, LZ4B_UNCOMPRESSED);
}