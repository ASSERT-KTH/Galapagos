LZ4F_dctx* LZ4F_createDecompressionContext_advanced(LZ4F_CustomMem customMem, unsigned version)
{
    LZ4F_dctx* const dctx = (LZ4F_dctx*)LZ4F_calloc(sizeof(LZ4F_dctx), customMem);
    if (dctx == NULL) return NULL;

    dctx->cmem = customMem;
    dctx->version = version;
    return dctx;
}