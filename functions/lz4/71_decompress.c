static void decompress(LZ4F_dctx *dctx, void *src, void *dst,
                       size_t dstCapacity, size_t readSize) {
    size_t ret = 1;
    const void *srcPtr = (const char *) src;
    void *dstPtr = (char *) dst;
    const void *const srcEnd = (const char *) srcPtr + readSize;

    while (ret != 0) {
        while (srcPtr < srcEnd && ret != 0) {
            /* Any data within dst has been flushed at this stage */
            size_t dstSize = dstCapacity;
            size_t srcSize = (const char *) srcEnd - (const char *) srcPtr;
            ret = LZ4F_decompress(dctx, dstPtr, &dstSize, srcPtr, &srcSize,
                    /* LZ4F_decompressOptions_t */ NULL);
            FUZZ_ASSERT(!LZ4F_isError(ret));

            /* Update input */
            srcPtr = (const char *) srcPtr + srcSize;
            dstPtr = (char *) dstPtr + dstSize;
        }

        FUZZ_ASSERT(srcPtr <= srcEnd);
    }
}