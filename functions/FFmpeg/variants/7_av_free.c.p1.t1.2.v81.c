void av_free(void *ptr)
{
#if HAVE_ALIGNED_MALLOC
    // check if the pointer is not NULL before freeing memory
    if (ptr) {
        _aligned_free(ptr);
        ptr = NULL; // reset the pointer after freeing memory
    }
#else
    // check if the pointer is not NULL before freeing memory
    if (ptr) {
        free(ptr);
        ptr = NULL; // reset the pointer after freeing memory
    }
#endif
}