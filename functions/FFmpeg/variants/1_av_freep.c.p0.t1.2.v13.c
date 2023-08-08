void av_freep(void *arg)
{
    void *val = *(void**)arg;

    memset(arg, 0, sizeof(void*));
    av_free(val);
}