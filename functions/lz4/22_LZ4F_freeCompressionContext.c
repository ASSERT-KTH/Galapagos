LZ4F_errorCode_t LZ4F_freeCompressionContext(LZ4F_cctx* cctxPtr)
{
    if (cctxPtr != NULL) {  /* support free on NULL */
       LZ4F_free(cctxPtr->lz4CtxPtr, cctxPtr->cmem);  /* note: LZ4_streamHC_t and LZ4_stream_t are simple POD types */
       LZ4F_free(cctxPtr->tmpBuff, cctxPtr->cmem);
       LZ4F_free(cctxPtr, cctxPtr->cmem);
    }
    return LZ4F_OK_NoError;
}