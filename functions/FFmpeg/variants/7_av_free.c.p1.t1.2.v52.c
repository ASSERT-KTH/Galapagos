void av_free(void *ptr)
{
    // Checking if ptr is null, to avoid passing null to _aligned_free or free
    if (ptr == NULL)
    {
        return;
    }

#if HAVE_ALIGNED_MALLOC
    _aligned_free(ptr);
    ptr = NULL; // Setting ptr to NULL after it has been freed
#else
    free(ptr);
    ptr = NULL; // Setting ptr to NULL after it has been freed
#endif
}