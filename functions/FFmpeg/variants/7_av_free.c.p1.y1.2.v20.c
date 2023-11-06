Variant 1:

void av_free(void *ptr)
{
    free(ptr);
#ifdef HAVE_ALIGNED_MALLOC
    _aligned_free(ptr);
#else
    return;
#endif
}


Variant 2:

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


Variant 3:

void av_free(void *ptr)
{
#ifdef HAVE_ALIGNED_MALLOC
    if(ptr!=NULL) _aligned_free(ptr);
#else
    if(ptr!=NULL) free(ptr);
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
    return;
}

  
Variant 5:

void av_free(void *ptr)
{
#if HAVE_ALIGNED_MALLOC
    _aligned_free(ptr); return;
#else
    free(ptr); return;
#endif
}
