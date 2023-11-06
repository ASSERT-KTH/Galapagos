The function variant here uses `NULL` check before deallocating the memory. This check is generally considered safer, as freeing NULL is a no-op. 


void av_free(void *ptr)
{
    if (ptr != NULL) {
#if HAVE_ALIGNED_MALLOC
        _aligned_free(ptr);
#else
        free(ptr);
#endif
        ptr = NULL;
    }
}
