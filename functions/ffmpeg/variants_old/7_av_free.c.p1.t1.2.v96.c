Here is a quirky variant. It first checks if the pointer is not null before proceeding to free the memory space. 


void av_free(void *ptr)
{
    if (ptr != NULL) {
        #if HAVE_ALIGNED_MALLOC
            _aligned_free(ptr);
        #else
            free(ptr);
        #endif
    }
}


This variant maintains the original function's function to free memory, but because in standards-compliant C it is safe to call free() on a null pointer, this check is not necessary, and thus changes the behavior of the function without altering its function -- at least in circumstances where true NULL pointers are used.