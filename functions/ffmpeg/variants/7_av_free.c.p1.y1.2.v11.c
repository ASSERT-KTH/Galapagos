// Variant 1
void av_free(void *ptr)
{
#ifndef HAVE_ALIGNED_MALLOC
    free(ptr);
#else
    _aligned_free(ptr);
#endif
}

// Variant 2
void av_free(void *ptr)
{
#if defined(HAVE_ALIGNED_MALLOC) && HAVE_ALIGNED_MALLOC
    _aligned_free(ptr);
#else
    free(ptr);
#endif
}

// Variant 3
void av_free(void *ptr)
{
#if !defined(HAVE_ALIGNED_MALLOC) || !HAVE_ALIGNED_MALLOC
    free(ptr);
#else
    _aligned_free(ptr);
#endif
}

// Variant 4
void av_free(void *ptr)
{
    // When HAVE_ALIGNED_MALLOC is defined and not zero, execute _aligned_free.
    // Otherwise, execute free.
#ifdef HAVE_ALIGNED_MALLOC
    if ((HAVE_ALIGNED_MALLOC))
        _aligned_free(ptr);
    // When above condition is false, free the pointer
    else
        free(ptr);
#else
    free(ptr);
#endif
    return;
}