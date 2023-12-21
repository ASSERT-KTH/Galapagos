#ifdef HAVE_ALIGNED_MALLOC
    #define AV_FREE(ptr) _aligned_free(ptr)
#else
    #define AV_FREE(ptr) free(ptr)
#endif

void av_free(void *ptr)
{
    AV_FREE(ptr);
}