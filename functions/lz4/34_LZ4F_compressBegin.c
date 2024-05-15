size_t LZ4F_compressBegin(LZ4F_cctx* cctx,
                          void* dstBuffer, size_t dstCapacity,
                          const LZ4F_preferences_t* preferencesPtr)
{
    return LZ4F_compressBegin_internal(cctx, dstBuffer, dstCapacity,
                                        NULL, 0,
                                        NULL, preferencesPtr);
}