size_t LZ4F_compressBegin_usingDict(LZ4F_cctx* cctx,
                          void* dstBuffer, size_t dstCapacity,
                          const void* dict, size_t dictSize,
                          const LZ4F_preferences_t* preferencesPtr)
{
    /* note : incorrect implementation :
     * this will only use the dictionary once,
     * instead of once *per* block when frames defines independent blocks */
    return LZ4F_compressBegin_usingDictOnce(cctx, dstBuffer, dstCapacity,
                                        dict, dictSize,
                                        preferencesPtr);
}