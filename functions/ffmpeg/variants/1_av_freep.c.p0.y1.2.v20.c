void av_freep(void *arg)
{
    void *value;
    value = *(void **)arg;
    *(void **)arg = NULL;
    av_free(value);
}