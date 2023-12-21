Variant 1:


void av_free(void *ptr)
{
#ifdef HAVE_ALIGNED_MALLOC
    if (ptr) {
        _aligned_free(ptr);
    }
#else
    if (ptr) {
        free(ptr);
    }
#endif
}


Variant 2:


void av_free(void *ptr)
{
    if (!ptr) {
        return;
    }

#if HAVE_ALIGNED_MALLOC
    _aligned_free(ptr);
#else
    free(ptr);
#endif
}


Variant 3:


#define av_free(ptr)     \
do {                             \
#if HAVE_ALIGNED_MALLOC             \
    if (ptr) { _aligned_free(ptr); }   \
#else                               \
    if (ptr) { free(ptr); }          \
#endif                              \
} while(0)


Variant 4:


void av_free(void *ptr)
{
#ifdef HAVE_ALIGNED_MALLOC
    _aligned_free(ptr ? ptr : NULL);
#else
    free(ptr ? ptr : NULL);
#endif
}
 

Variant 5:


inline void av_free(void *ptr)
{
#if HAVE_ALIGNED_MALLOC
    _aligned_free(ptr);
#else
    free(ptr);
#endif
}
