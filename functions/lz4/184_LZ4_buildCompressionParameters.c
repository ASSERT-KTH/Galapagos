LZ4_buildCompressionParameters(struct compressionParameters* pParams,
                               int cLevel,
                         const char* dictBuf, int dictSize)
{
    pParams->cLevel = cLevel;
    pParams->dictBuf = dictBuf;
    pParams->dictSize = dictSize;

    if (dictSize) {
        if (cLevel < LZ4HC_CLEVEL_MIN) {
            pParams->initFunction = LZ4_compressInitStream;
            pParams->resetFunction = LZ4_compressResetStream;
            pParams->blockFunction = LZ4_compressBlockStream;
            pParams->cleanupFunction = LZ4_compressCleanupStream;
        } else {
            pParams->initFunction = LZ4_compressInitStreamHC;
            pParams->resetFunction = LZ4_compressResetStreamHC;
            pParams->blockFunction = LZ4_compressBlockStreamHC;
            pParams->cleanupFunction = LZ4_compressCleanupStreamHC;
        }
    } else {
        pParams->initFunction = LZ4_compressInitNoStream;
        pParams->resetFunction = LZ4_compressResetNoStream;
        pParams->cleanupFunction = LZ4_compressCleanupNoStream;

        if (cLevel < LZ4HC_CLEVEL_MIN) {
            pParams->blockFunction = LZ4_compressBlockNoStream;
        } else {
            pParams->blockFunction = LZ4_compressBlockNoStreamHC;
        }
    }
}