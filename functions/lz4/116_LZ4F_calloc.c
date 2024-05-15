static void* LZ4F_calloc(size_t s, LZ4F_CustomMem cmem)
{
    /* custom calloc defined : use it */
    if (cmem.customCalloc != NULL) {
        return cmem.customCalloc(cmem.opaqueState, s);
    }
    /* nothing defined : use default <stdlib.h>'s calloc() */
    if (cmem.customAlloc == NULL) {
        return ALLOC_AND_ZERO(s);
    }
    /* only custom alloc defined : use it, and combine it with memset() */
    {   void* const p = cmem.customAlloc(cmem.opaqueState, s);
        if (p != NULL) MEM_INIT(p, 0, s);
        return p;
}   }