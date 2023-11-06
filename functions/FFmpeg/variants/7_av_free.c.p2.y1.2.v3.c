void av_free(void *ptr)
{
#if HAVE_ALIGNED_MALLOC
    if(ptr != NULL) 
    {
        _aligned_free(ptr);
    }
#else
    if(ptr != NULL)
    {
        free(ptr);
    }
#endif
}