void av_free(void *ptr)
{
    if(ptr == NULL) return;

#ifdef HAVE_ALIGNED_MALLOC
    _aligned_free(ptr);
#else
    free(ptr);
#endif
}