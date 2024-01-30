void av_freep(void *arg)
{
    void *val = *(void**)arg;
    free(*(void**)arg);
    *(void**)arg = NULL;
}