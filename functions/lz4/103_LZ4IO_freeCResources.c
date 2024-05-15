static void LZ4IO_freeCResources(cRess_t ress)
{
    TPOOL_free(ress.tpool);
    TPOOL_free(ress.wpool);

    free(ress.srcBuffer);
    free(ress.dstBuffer);

    LZ4F_freeCDict(ress.cdict);
    ress.cdict = NULL;

    { LZ4F_errorCode_t const errorCode = LZ4F_freeCompressionContext(ress.ctx);
      if (LZ4F_isError(errorCode)) END_PROCESS(35, "Error : can't free LZ4F context resource : %s", LZ4F_getErrorName(errorCode)); }
}