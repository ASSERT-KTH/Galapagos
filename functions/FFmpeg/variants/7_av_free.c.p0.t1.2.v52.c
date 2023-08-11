void av_free(void *ptr)
{
    if (ptr != NULL) 
    {
#if HAVE_ALIGNED_MALLOC
        _aligned_free(ptr);
        ptr = NULL;   //added to prevent accidental further use.
#else
        free(ptr);
        ptr = NULL;
#endif
    }
}