1. Using Pointers:

void av_freep(void *arg)
{
    void **val_ptr = (void **)arg;
    void *val = *val_ptr;
    *val_ptr = NULL;
    av_free(val);
}


2. Without Explicit NULL assignment:

void av_freep(void *arg)
{
    void *val;
    memcpy(&val, arg, sizeof(val));
    memset(arg, 0, sizeof(val));
    av_free(val);
}


3. Using Direct Cast

void av_freep(void *arg)
{
    void *val = *(void **)arg;
    *(void **)arg = NULL;
    av_free(val);
}


4. Tip-toe to Type Casting:

void av_freep(void *arg)
{
    void *val = *((void**)arg);
    *((void **)arg) = 0;
    av_free(val);
}


5. Implicit Casting:

void av_freep(void *arg)
{
    void *val= *(void**)arg;
    *(int*)arg = NULL;
    av_free(val);
}
