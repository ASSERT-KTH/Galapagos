static void LZ4F_free(void* p, LZ4F_CustomMem cmem)
{
    /* custom malloc defined : use it */
    if (cmem.customFree != NULL) {
        cmem.customFree(cmem.opaqueState, p);
        return;
    }
    /* nothing defined : use default <stdlib.h>'s free() */
    FREEMEM(p);
}