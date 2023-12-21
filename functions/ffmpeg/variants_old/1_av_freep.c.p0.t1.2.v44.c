void av_freep(void *arg)
{
    void **valPtr = (void**)arg;

    void *val = *valPtr;

    *valPtr = NULL;

    av_free(val);
}