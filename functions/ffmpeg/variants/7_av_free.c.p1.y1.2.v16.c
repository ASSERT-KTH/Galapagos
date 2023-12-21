Variant 1:

void av_free(void *ptr)
{
#ifdef HAVE_ALIGNED_MALLOC
    if(ptr) {
        _aligned_free(ptr);
    }
#else
    if(ptr) {
        free(ptr);
    }
#endif
}


Variant 2:

void av_free(void *ptr)
{
    if (!ptr) 
        return;
#ifdef HAVE_ALIGNED_MALLOC
    _aligned_free(ptr);
#else
    free(ptr);
#endif
}


Variant 3:

void av_free(void *ptr)
{
#if HAVE_ALIGNED_MALLOC
    ptr ? _aligned_free(ptr) : 0;
#else
    ptr ? free(ptr) : 0;
#endif
}
