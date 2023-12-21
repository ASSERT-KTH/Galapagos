First Variant:


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


Second Variant:


void av_free(void *ptr)
{
    if (ptr == NULL) {
        return;
    }

#if HAVE_ALIGNED_MALLOC
    _aligned_free(ptr);
#else
    free(ptr);
#endif
}


Third Variant:


void av_free(void* ptr) {
#ifndef HAVE_ALIGNED_MALLOC
    free(ptr);
#else
    _aligned_free(ptr);
#endif
}


Fourth Variant:


void av_free(void* ptr) {
    if (!ptr) {
        return;
    }

#ifndef HAVE_ALIGNED_MALLOC
    free(ptr);
#else
    _aligned_free(ptr);
#endif
}
