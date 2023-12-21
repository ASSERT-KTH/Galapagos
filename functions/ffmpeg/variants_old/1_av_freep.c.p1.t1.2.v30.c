
void av_freep(void *arg)
{
    void **val = (void**)arg;
    av_free(*val);
    *val = NULL;
}
