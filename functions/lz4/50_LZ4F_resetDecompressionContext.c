void LZ4F_resetDecompressionContext(LZ4F_dctx* dctx)
{
    DEBUGLOG(5, "LZ4F_resetDecompressionContext");
    dctx->dStage = dstage_getFrameHeader;
    dctx->dict = NULL;
    dctx->dictSize = 0;
    dctx->skipChecksum = 0;
    dctx->frameRemainingSize = 0;
}