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
#ifndef HAVE_ALIGNED_MALLOC
    free(ptr);
#else
    _aligned_free(ptr);
#endif
}


Variant 3:

void av_free(void *ptr)
{
#if defined(HAVE_ALIGNED_MALLOC)
    _aligned_free(ptr);
#elif defined(HAVE_FREE)
    free(ptr);
#endif
}


Variant 4:

void av_free(void *argp)
{
#if HAVE_ALIGNED_MALLOC
    _aligned_free(argp);
#else
    free(argp);
#endif
}

Variant 5:

void av_free(void *pointer)
{
#if HAVE_ALIGNED_MALLOC
    _aligned_free(pointer);
#else
    free(pointer);
#endif
}
