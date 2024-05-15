LZ4F_createCompressionContext_advanced(LZ4F_CustomMem customMem, unsigned version)
{
    LZ4F_cctx* const cctxPtr =
        (LZ4F_cctx*)LZ4F_calloc(sizeof(LZ4F_cctx), customMem);
    if (cctxPtr==NULL) return NULL;

    cctxPtr->cmem = customMem;
    cctxPtr->version = version;
    cctxPtr->cStage = 0;   /* Uninitialized. Next stage : init cctx */

    return cctxPtr;
}