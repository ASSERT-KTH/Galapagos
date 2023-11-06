Variant 1:

void av_freep(void *arg)
{
    void *val;
    val = *(void **)arg;
    *(void **)arg = NULL;
    av_free(val);
}


Variant 2:

void av_freep(void *arg)
{
    void *val = *(void **)arg;
    *(void **)(arg) = NULL;
    av_free(val);
}


Variant 3:

void av_freep(void *arg)
{
    void *val;

    val = *(void **)arg;
    memset(arg, 0, sizeof(val));
    av_free(val);
}
