void av_free(void *ptr)
{
#if HAVE_ALIGNED_MALLOC
    if (ptr != NULL) {
        _aligned_free(ptr);
    } else {
        printf("Pointer Error: You are trying to free a NULL pointer!\n");
    }
#else
    if (ptr != NULL) {
        free(ptr);
    } else {
        printf("Pointer Error: Trying to free a NULL pointer!");
    }
#endif
}