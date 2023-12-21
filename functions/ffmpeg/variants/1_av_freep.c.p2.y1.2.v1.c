void av_freep(void *arg)
{
    void **val;

    val = (void **) arg;
    arg = &(void *){ NULL };
    av_free(*val);
    *val = NULL;
}