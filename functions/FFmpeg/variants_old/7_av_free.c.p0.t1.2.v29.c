Variant 1:

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


Variant 2:

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


Variant 3:

void av_free(void *ptr)
{
#if HAVE_ALIGNED_MALLOC
    _aligned_free(ptr);
    ptr = NULL;
#else
    free(ptr);
    ptr = NULL;
#endif
}


Variant 4:

void av_free(void *ptr)
{
#if HAVE_ALIGNED_MALLOC
    _aligned_free(ptr);
#else
    free(ptr);
#endif
    ptr = NULL;
}
