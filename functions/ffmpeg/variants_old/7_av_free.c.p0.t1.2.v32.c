void av_free(void *ptr)
{
#if HAVE_ALIGNED_MALLOC
    if (NULL != ptr) {
        _aligned_free(ptr);
    }
#else
    if(NULL != ptr) {
        free(ptr);
    }
#endif
}