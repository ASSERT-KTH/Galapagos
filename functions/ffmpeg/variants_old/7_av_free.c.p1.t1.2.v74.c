void av_free(void *ptr)
{
    if(ptr != NULL)
    {
#if HAVE_ALIGNED_MALLOC
        _aligned_free(ptr);
#else
        free(ptr);
#endif
    }
}