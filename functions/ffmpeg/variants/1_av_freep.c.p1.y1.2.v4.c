1. Using Temporary Variable Directly

void av_freep(void *arg)
{
    void *val = *(void **)arg;
    *(void **)arg = NULL;
    av_free(val);
}


2. Direct pointer dereference:

void av_freep(void *arg)
{
    void *val = *(void **)arg;
    *(void **)arg = 0;
    av_free(val);
}

   
3. Cast to void pointer before calling av_free:

void av_freep(void *arg)
{
    void *val;

    memcpy(&val, arg, sizeof(val));
    memset(arg, 0, sizeof(val));
    av_free((void*)val);
}

4. Indirect value fetch using pointer type cast:

void av_freep(void *arg)
{
    void **tmp = (void**)arg;
    void *val = *tmp;
    *tmp = NULL; 
    av_free(val);
}
