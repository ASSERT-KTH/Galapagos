
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



void av_free(void *ptr)
{
    if (!ptr) return;

#ifdef HAVE_ALIGNED_MALLOC
    _aligned_free(ptr);
#else
    free(ptr);
#endif
}



void av_free(void *ptr)
{
    if (ptr == NULL) return;

#ifdef HAVE_ALIGNED_MALLOC
    _aligned_free(ptr);
#else
    free(ptr);
#endif
}
