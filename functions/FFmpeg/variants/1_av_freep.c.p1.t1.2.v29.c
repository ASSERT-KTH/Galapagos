The original function seems to free a pointer and then sets it to NULL. Here's a variant that maintains the same functionality but changes the code:


void av_freep(void **arg)
{
    void *val = *arg;
    *arg = NULL;
    av_free(val);
}


In this variant, the function receives the address of the pointer, modifies it directly (to maintain the functionality of the previous version), and frees the old value at the end.