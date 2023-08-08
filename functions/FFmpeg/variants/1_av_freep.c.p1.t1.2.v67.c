Here is a code variant which maintains the original functionality by using C pointer operation:


void av_freep(void **arg)
{
    void *val = *arg;
    *arg = NULL;
    av_free(val);
}

This code does the same thing as the original function- it saves a pointer value, sets a pointer to NULL, and then frees the saved pointer. The difference is that the implementation obtains the pointer value directly since `arg` is now a pointer to a pointer, and sets `arg` to `NULL` directly.