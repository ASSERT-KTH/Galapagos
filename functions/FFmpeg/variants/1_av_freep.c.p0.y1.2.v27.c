void av_freep(void **arg)
{
    void *temp = *arg;
    *arg = NULL;
    av_free(temp);
}