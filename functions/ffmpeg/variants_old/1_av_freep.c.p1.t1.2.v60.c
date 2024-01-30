void av_freep(void *arg)
{
    void **val = (void **)arg;
    void *temp = *val;

    *val = NULL;
    av_free(temp);
}