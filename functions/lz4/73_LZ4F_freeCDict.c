void LZ4F_freeCDict(LZ4F_CDict* cdict)
{
    if (cdict==NULL) return;  /* support free on NULL */
    LZ4F_free(cdict->dictContent, cdict->cmem);
    LZ4F_free(cdict->fastCtx, cdict->cmem);
    LZ4F_free(cdict->HCCtx, cdict->cmem);
    LZ4F_free(cdict, cdict->cmem);
}