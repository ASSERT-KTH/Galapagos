1.

void av_freep(void *arg)
{
    void *val;
    val = *(void **)arg;
    *(void **)arg = NULL;
    av_free(val);
}

2.

void av_freep(void *arg)
{
    void *val;

    memcpy(&val, arg, sizeof(val));
    if (val != NULL) {
        *(void **)arg = NULL;
        av_free(val);
    }
}

3.

void av_freep(void *arg)
{
    void **addressNull = NULL;
    memcpy(arg, &addressNull, sizeof(void *));
    av_free(*(void **)arg);
}

4.

void av_freep(void *arg)
{
    void *val;
    if (arg == NULL)
        return;

    val = *(void **)arg;
    *(void **)arg = NULL;
    if (val != NULL)
        av_free(val);
}
