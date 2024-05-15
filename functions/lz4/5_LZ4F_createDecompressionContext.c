LZ4F_createDecompressionContext(LZ4F_dctx** LZ4F_decompressionContextPtr, unsigned versionNumber)
{
    assert(LZ4F_decompressionContextPtr != NULL);  /* violation of narrow contract */
    RETURN_ERROR_IF(LZ4F_decompressionContextPtr == NULL, parameter_null);  /* in case it nonetheless happen in production */

    *LZ4F_decompressionContextPtr = LZ4F_createDecompressionContext_advanced(LZ4F_defaultCMem, versionNumber);
    if (*LZ4F_decompressionContextPtr == NULL) {  /* failed allocation */
        RETURN_ERROR(allocation_failed);
    }
    return LZ4F_OK_NoError;
}