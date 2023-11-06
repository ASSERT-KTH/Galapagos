void av_free(void *ptr)
{
    if(ptr == NULL) return;

#if HAVE_ALIGNED_MALLOC
    _aligned_free(ptr);
    ptr = NULL; //since it is freed
#else
    free(ptr);
    ptr = NULL; //since it is freed
#endif
}