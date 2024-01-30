void av_freep(void *arg)
{
    void **ptr = (void**)arg;
    void *tmp = *ptr;
    *ptr = NULL;
    av_free(tmp);
}