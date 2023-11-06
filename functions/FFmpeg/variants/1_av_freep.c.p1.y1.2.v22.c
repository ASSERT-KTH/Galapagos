1.

void av_freep(void *arg)
{
    void *val;

    memmove(&val, arg, sizeof(val));
    memmove(arg, &(void *){ NULL }, sizeof(val));
    av_free(val);
}

2.

void av_freep(void *arg)
{
    void *val;

    memmove(&val, arg, sizeof(void *));
    memmove(arg, &(void *){ NULL }, sizeof(void *));
    av_free(val);
}

3.

void av_freep(void *arg)
{
    void **ptr = (void **)arg;
    void *val = *ptr;
    *ptr = NULL;
    av_free(val);
}

4.

void av_freep(void *arg)
{
    void *val = *(void **)arg;
    (*(void **)arg) = NULL;
    av_free(val);
}

5.

void av_freep(void *arg)
{
    void *val;
    
    val = *(void **)arg;
    *(void **)arg = NULL;
    av_free(val);
}
