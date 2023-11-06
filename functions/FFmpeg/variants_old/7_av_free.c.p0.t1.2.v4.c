void av_free(void *ptr)
{
#if HAVE_ALIGNED_MALLOC
    if(ptr) {
        _aligned_free(ptr);
        ptr = NULL;
    }
#else
    if(ptr) {
        free(ptr);
        ptr = NULL;
    }   
#endif
}