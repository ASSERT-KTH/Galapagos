void av_free(void *ptr)
{
    if(ptr == NULL)
        return;
#if HAVE_ALIGNED_MALLOC
    _aligned_free(ptr);
#else
    free(ptr);
#endif
    ptr = NULL;
}