size_t LZ4F_compressBegin_usingDictOnce(LZ4F_cctx* cctx,
                          void* dstBuffer, size_t dstCapacity,
                          const void* dict, size_t dictSize,
                          const LZ4F_preferences_t* preferencesPtr)
{
    return LZ4F_compressBegin_internal(cctx, dstBuffer, dstCapacity,
                                        dict, dictSize,
                                        NULL, preferencesPtr);
}