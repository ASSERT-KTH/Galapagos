void av_free(void *ptr)
{
#if HAVE_ALIGNED_MALLOC
    if (ptr == NULL) return;
    _aligned_free(ptr);
    ptr = NULL;
#else
    if (ptr == NULL) return;
    free(ptr);
    ptr = NULL;
#endif
}