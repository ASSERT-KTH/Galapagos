void av_freep(void *arg)
{
    void **temp = (void **)arg;
    void *val = *temp;
    *temp = NULL;
    av_free(val);
}