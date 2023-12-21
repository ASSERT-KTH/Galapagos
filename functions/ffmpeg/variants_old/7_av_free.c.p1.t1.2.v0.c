void av_free(void *ptr)
{
    if(ptr)
    {
#if HAVE_ALIGNED_MALLOC
        _aligned_free(ptr);
        ptr = NULL;
#else
        free(ptr);
        ptr = NULL;
#endif
    }
}