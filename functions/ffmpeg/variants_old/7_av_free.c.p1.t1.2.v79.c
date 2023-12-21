Consider replacing the general free() with specialized C free functions. Below is an example of a variant with the same functionality:


void av_free(void *ptr)
{
    #if HAVE_ALIGNED_MALLOC
        if(ptr != NULL){
            _aligned_free(ptr);
        }
    #else
        if(ptr != NULL){
            free(ptr);
        }   
    #endif
    ptr = NULL; // Option to reset the pointer to NULL after freeing the memory
}


We are asserting if pointer is not NULL before dealing the free process. It is based on the C standard, where the behaviour is undefined if the value passed to free() is not a valid non-NULL pointer that was returned by a preceding call to malloc(), calloc(), realloc() or aligned_alloc().

Then, we set ptr to NULL after freeing the allocated memory. This is done after freeing a memory block to ensure that the freed memory can't be used in the future accidentally.

This refactor thus ensures safer code while maintaining its original functionality.