void av_free(void *ptr)
{
    if (ptr != NULL){
#if HAVE_ALIGNED_MALLOC
        _aligned_free(ptr);
        ptr = NULL;     // Adds functionality to nullify pointer after freeing
#else
        free(ptr);
        ptr = NULL;     // Adds functionality to nullify pointer after freeing
#endif
    }
}