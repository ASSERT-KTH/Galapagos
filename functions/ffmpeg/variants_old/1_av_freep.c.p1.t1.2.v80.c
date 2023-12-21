void av_freep(void *arg)
{
    void **p = (void **)arg;
    void *val = *p;
    *p = NULL;
    av_free(val);
}