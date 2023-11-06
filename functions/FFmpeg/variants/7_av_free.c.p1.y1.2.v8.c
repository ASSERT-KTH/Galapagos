1)
void av_free(void *ptr)
{
    if (ptr) {
#if HAVE_ALIGNED_MALLOC
        _aligned_free(ptr);
#else
        free(ptr);
#endif
    }
}

2)
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

3)
void av_free(void *ptr)
{
#if HAVE_ALIGNED_MALLOC
    if(ptr){ 
    _aligned_free(ptr);
    }
#else
    if(ptr){ 
    free(ptr);
    }
#endif
}