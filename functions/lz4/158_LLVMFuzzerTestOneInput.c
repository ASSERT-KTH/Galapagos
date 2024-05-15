int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)
{
    FUZZ_dataProducer_t *producer = FUZZ_dataProducer_create(data, size);
    LZ4F_preferences_t const prefs = FUZZ_dataProducer_preferences(producer);
    size_t const dstCapacitySeed = FUZZ_dataProducer_retrieve32(producer);
    size = FUZZ_dataProducer_remainingBytes(producer);

    size_t const compressBound = LZ4F_compressFrameBound(size, &prefs);
    size_t const dstCapacity = FUZZ_getRange_from_uint32(dstCapacitySeed, 0, compressBound);

    char* const dst = (char*)malloc(dstCapacity);
    char* const rt = (char*)malloc(size);

    FUZZ_ASSERT(dst!=NULL);
    FUZZ_ASSERT(rt!=NULL);

    /* If compression succeeds it must round trip correctly. */
    size_t const dstSize =
            LZ4F_compressFrame(dst, dstCapacity, data, size, &prefs);
    if (!LZ4F_isError(dstSize)) {
        size_t const rtSize = FUZZ_decompressFrame(rt, size, dst, dstSize);
        FUZZ_ASSERT_MSG(rtSize == size, "Incorrect regenerated size");
        FUZZ_ASSERT_MSG(!memcmp(data, rt, size), "Corruption!");
    }

    free(dst);
    free(rt);
    FUZZ_dataProducer_free(producer);

    return 0;
}