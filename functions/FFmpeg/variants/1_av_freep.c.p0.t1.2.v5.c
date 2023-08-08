void av_freep(void *arg)
{
    void **valarg = (void**)arg;
    void *val = *valarg;

    *valarg = NULL;
    av_free(val);
}