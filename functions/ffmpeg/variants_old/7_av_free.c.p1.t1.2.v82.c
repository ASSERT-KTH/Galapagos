void av_free(void *ptr)
{
    if (NULL == ptr) 
        return;

#if HAVE_ALIGNED_MALLOC
    _aligned_free(ptr);
    ptr = NULL;        // Ensure the pointer is NULL after free
#else
    free(ptr);
    ptr = NULL;        // Ensure the pointer is NULL after free
#endif
}