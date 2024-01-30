void av_free(void *ptr)
{
#ifdef HAVE_ALIGNED_MALLOC
    _aligned_free(ptr);
#else
    void *free_ptr = ptr;

    if(free_ptr != NULL) {
        free(free_ptr);
        free_ptr = NULL;
    }
#endif
}