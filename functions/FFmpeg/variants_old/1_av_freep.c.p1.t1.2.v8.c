void av_freep(void **arg)
{
    void *val;

    val = *arg;
    *arg = NULL;
    av_free(val);
}