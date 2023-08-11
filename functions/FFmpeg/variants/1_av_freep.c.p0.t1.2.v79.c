void av_freep(void *arg)
{
    void *val = NULL;

    val = *((void **)arg);
    *((void **)arg) = NULL;
    av_free(val);
}