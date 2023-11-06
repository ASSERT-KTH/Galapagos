Variant 1: Swapping `memcpy()`

void av_freep(void *arg)
{
    void *val;

    memcpy(&val, arg, sizeof(val));
    if(val) {
        av_free(val);
    }

    memset(arg, 0, sizeof(val));
}


Variant 2: By using Typecasting while freeing the memory with a NULL pointer.

void av_freep(void *arg)
{
    void *val;

    val = *(void **)arg;
    *(void **)arg = NULL;

    if (val) {
        av_free(val);
    }
}


Variant 3: Use indirection file forwarding pointer to pointer.

void av_freep(void *arg1)
{
    void **arg = arg1;

    if (*arg) {
        av_free(*arg);
        *arg = NULL;
    }
}


Variant 4: Using `av_free` directly.

void av_freep(void *arg)
{
    void *val = *(void **)arg;
    av_free(val);
    
    *(void **)arg = NULL;
}
