LZ4F_createCDict_advanced(LZ4F_CustomMem cmem, const void* dictBuffer, size_t dictSize)
{
    const char* dictStart = (const char*)dictBuffer;
    LZ4F_CDict* const cdict = (LZ4F_CDict*)LZ4F_malloc(sizeof(*cdict), cmem);
    DEBUGLOG(4, "LZ4F_createCDict_advanced");
    if (!cdict) return NULL;
    cdict->cmem = cmem;
    if (dictSize > 64 KB) {
        dictStart += dictSize - 64 KB;
        dictSize = 64 KB;
    }
    cdict->dictContent = LZ4F_malloc(dictSize, cmem);
    cdict->fastCtx = (LZ4_stream_t*)LZ4F_malloc(sizeof(LZ4_stream_t), cmem);
    if (cdict->fastCtx)
        LZ4_initStream(cdict->fastCtx, sizeof(LZ4_stream_t));
    cdict->HCCtx = (LZ4_streamHC_t*)LZ4F_malloc(sizeof(LZ4_streamHC_t), cmem);
    if (cdict->HCCtx)
        LZ4_initStreamHC(cdict->HCCtx, sizeof(LZ4_streamHC_t));
    if (!cdict->dictContent || !cdict->fastCtx || !cdict->HCCtx) {
        LZ4F_freeCDict(cdict);
        return NULL;
    }
    memcpy(cdict->dictContent, dictStart, dictSize);
    LZ4_loadDictSlow(cdict->fastCtx, (const char*)cdict->dictContent, (int)dictSize);
    LZ4_setCompressionLevel(cdict->HCCtx, LZ4HC_CLEVEL_DEFAULT);
    LZ4_loadDictHC(cdict->HCCtx, (const char*)cdict->dictContent, (int)dictSize);
    return cdict;
}