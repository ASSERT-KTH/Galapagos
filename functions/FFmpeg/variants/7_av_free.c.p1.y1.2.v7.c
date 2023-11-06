
void av_free(void *ptr)
{
#ifdef HAVE_ALIGNED_MALLOC
    if(ptr!= NULL){
    _aligned_free(ptr);
    }
#else
    if(ptr!= NULL){
    free(ptr);
    }
#endif
}


typedef void (*free_function)(void*);
void av_free(void *ptr)
{
    free_function free_ptr = NULL;

#if HAVE_ALIGNED_MALLOC
    free_ptr = &_aligned_free;
#else
    free_ptr = &free;
#endif

    if (ptr != NULL) {
        free_ptr(ptr);
    }
}


void av_free(void *ptr)
{
#if HAVE_ALIGNED_MALLOC
    ptr ? _aligned_free(ptr) : (void)ptr;
#else
    ptr ? free(ptr) : (void)ptr;
#endif
}
