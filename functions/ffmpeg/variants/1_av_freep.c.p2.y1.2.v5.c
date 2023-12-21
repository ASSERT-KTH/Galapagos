void av_freep(void *arg)
{
    void **val = (void **)arg;
    void *tmp = *val;

    *val = NULL;
    av_free(tmp);
}