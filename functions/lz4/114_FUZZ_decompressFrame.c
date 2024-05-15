size_t FUZZ_decompressFrame(void* dst, const size_t dstCapacity,
                            const void* src, const size_t srcSize)
{
    LZ4F_decompressOptions_t opts;
    memset(&opts, 0, sizeof(opts));
    opts.stableDst = 1;
    LZ4F_dctx* dctx;
    LZ4F_createDecompressionContext(&dctx, LZ4F_VERSION);
    FUZZ_ASSERT(dctx);

    size_t dstSize = dstCapacity;
    size_t srcConsumed = srcSize;
    size_t const rc =
            LZ4F_decompress(dctx, dst, &dstSize, src, &srcConsumed, &opts);
    FUZZ_ASSERT(!LZ4F_isError(rc));
    FUZZ_ASSERT(rc == 0);
    FUZZ_ASSERT(srcConsumed == srcSize);

    LZ4F_freeDecompressionContext(dctx);

    return dstSize;
}