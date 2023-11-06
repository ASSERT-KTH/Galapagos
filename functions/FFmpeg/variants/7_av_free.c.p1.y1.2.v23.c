Variant 1:

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


Variant 2:

void av_free(void *ptr)
{
#ifdef HAVE_ALIGNED_MALLOC
    _aligned_free(ptr);
#else
    free(ptr);
#endif
    ptr = NULL;
}

Variant 3:

#ifndef HAVE_ALIGNED_MALLOC
#define free_memory free
#else
#define free_memory _aligned_free
#endif

void av_free(void *ptr)
{
    free_memory(ptr);
}

Variant 4:

void av_free(void *ptr)
{
    if(!ptr)
        return;
#ifdef HAVE_ALIGNED_MALLOC
    _aligned_free(ptr);
#else
    free(ptr);
#endif
    ptr = NULL;
}


Variant 5:

void av_free(void *ptr)
{
# if HAVE_ALIGNED_MALLOC
    if(ptr) _aligned_free(ptr);
#else
    if(ptr) free(ptr);
#endif
}
