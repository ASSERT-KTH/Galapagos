int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)
{
    FUZZ_dataProducer_t* producer = FUZZ_dataProducer_create(data, size);
    LZ4F_preferences_t const prefs = FUZZ_dataProducer_preferences(producer);
    size = FUZZ_dataProducer_remainingBytes(producer);

    size_t const dstCapacity = LZ4F_compressFrameBound(LZ4_compressBound(size), &prefs);
    char* const dst = (char*)malloc(dstCapacity);
    char* const rt = (char*)malloc(FUZZ_dataProducer_remainingBytes(producer));

    FUZZ_ASSERT(dst);
    FUZZ_ASSERT(rt);

    /* Compression must succeed and round trip correctly. */
    size_t const dstSize =
            LZ4F_compressFrame(dst, dstCapacity, data, size, &prefs);
    FUZZ_ASSERT(!LZ4F_isError(dstSize));
    size_t const rtSize = FUZZ_decompressFrame(rt, size, dst, dstSize);
    FUZZ_ASSERT_MSG(rtSize == size, "Incorrect regenerated size");
    FUZZ_ASSERT_MSG(!memcmp(data, rt, size), "Corruption!");

    free(dst);
    free(rt);
    FUZZ_dataProducer_free(producer);

    return 0;
}