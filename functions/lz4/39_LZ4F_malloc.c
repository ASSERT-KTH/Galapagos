static void* LZ4F_malloc(size_t s, LZ4F_CustomMem cmem)
{
    /* custom malloc defined : use it */
    if (cmem.customAlloc != NULL) {
        return cmem.customAlloc(cmem.opaqueState, s);
    }
    /* nothing defined : use default <stdlib.h>'s malloc() */
    return ALLOC(s);
}