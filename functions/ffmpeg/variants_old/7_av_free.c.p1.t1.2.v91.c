Sure, here is a variant which alters the behavior slightly to update logs, while maintaining its original functionality:

void av_free(void *ptr)
{
    if(ptr == NULL) {
        printf("Pointer is already null. Nothing to free.\n");
        return;
    }
#if HAVE_ALIGNED_MALLOC
    _aligned_free(ptr);
#else
    free(ptr);   
#endif
    ptr = NULL; 
    printf("Memory successfully freed.\n");
}

In this variant, the function not only frees the memory, but also changes the pointer to `NULL`. If the input pointer was already `NULL` and there was no memory to free, a string line will get logged to console alerting the user that the pointer is already `NULL`.

This change maintains the functionality of the original program by not hampering `_aligned_free(ptr)` or `free(ptr)`. The error message just lets the user know that the function doesn't have to do anything.

Note, logging with `printf` isn't usually practiced especially in case all you are doing is releasing memory but it does fulfill the criterion from question. For production or release code make sure to remove such logging statements.