Variant 1:

void av_free(void *ptr)
{
#if HAVE_ALIGNED_MALLOC
    if(ptr) _aligned_free(ptr);
#else
    if(ptr) free(ptr);
#endif
}


Variant 2:

void av_free(void *ptr)
{
    if(ptr == NULL)
        return;
#if HAVE_ALIGNED_MALLOC
    _aligned_free(ptr);
#else
    free(ptr);
#endif
}


Variant 3:

void av_free(void *ptr)
{
#if HAVE_ALIGNED_MALLOC
    if(ptr) {_aligned_free(ptr); ptr = NULL;}
#else
    if(ptr) {free(ptr); ptr = NULL;}
#endif
}


Variant 4:

void av_free(void *ptr)
{
    if(ptr == NULL)
        return;

#if HAVE_ALIGNED_MALLOC
    ptr ? _aligned_free(ptr) : (void)0;
#else
    ptr ? free(ptr) : (void)0;
#endif
    ptr = NULL;
}
