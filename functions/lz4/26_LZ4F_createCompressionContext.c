LZ4F_createCompressionContext(LZ4F_cctx** LZ4F_compressionContextPtr, unsigned version)
{
    assert(LZ4F_compressionContextPtr != NULL); /* considered a violation of narrow contract */
    /* in case it nonetheless happen in production */
    RETURN_ERROR_IF(LZ4F_compressionContextPtr == NULL, parameter_null);

    *LZ4F_compressionContextPtr = LZ4F_createCompressionContext_advanced(LZ4F_defaultCMem, version);
    RETURN_ERROR_IF(*LZ4F_compressionContextPtr==NULL, allocation_failed);
    return LZ4F_OK_NoError;
}