void av_freep(void *arg)
{
    void **val;

    val = (void **)arg;
    arg = NULL;
    av_free(*val);
    *val = NULL;
}