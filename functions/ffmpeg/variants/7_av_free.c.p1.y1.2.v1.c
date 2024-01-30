Option 1:

void av_free(void *ptr)
{
#if HAVE_ALIGNED_MALLOC
    if(ptr != NULL) _aligned_free(ptr);
#else
    if(ptr != NULL) free(ptr);
#endif
}


Option 2:

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


Option 3:

void av_free(void *ptr)
{
#if HAVE_ALIGNED_MALLOC
    while(ptr != NULL) {
        _aligned_free(ptr);
        break;
    }
#else
    while(ptr != NULL) {
        free(ptr);
        break;
    }
#endif
}


Option 4:

void av_free(void *ptr)
{
#if HAVE_ALIGNED_MALLOC
    _aligned_free(ptr);
#else
    if(sizeof(*ptr))
        free(ptr);
#endif
}
