void av_freep(void *arg)
{
    void *val = *(void **)arg;

    memset(arg, 0, sizeof(val));
    av_free(val);
}