void av_free(void *ptr)
{
#if HAVE_ALIGNED_MALLOC
    // Only freeing the memory if the pointer isn't NULL
    if (ptr != NULL) {
        _aligned_free(ptr);
        // Setting the value of pointer to NULL after freeing the memory
        ptr = NULL;
    }
#else
    if (ptr != NULL) {
        free(ptr);
        ptr = NULL;
    }
#endif
}