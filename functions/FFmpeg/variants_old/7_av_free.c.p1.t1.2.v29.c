void av_free(void *ptr)
{
#if HAVE_ALIGNED_MALLOC
    if(ptr)
        _aligned_free(ptr);
#else
    if(ptr)
        free(ptr);
#endif
}