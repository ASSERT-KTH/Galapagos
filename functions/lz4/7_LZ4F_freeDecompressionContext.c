LZ4F_errorCode_t LZ4F_freeDecompressionContext(LZ4F_dctx* dctx)
{
    LZ4F_errorCode_t result = LZ4F_OK_NoError;
    if (dctx != NULL) {   /* can accept NULL input, like free() */
      result = (LZ4F_errorCode_t)dctx->dStage;
      LZ4F_free(dctx->tmpIn, dctx->cmem);
      LZ4F_free(dctx->tmpOutBuffer, dctx->cmem);
      LZ4F_free(dctx, dctx->cmem);
    }
    return result;
}