void av_freep(void *arg)
{
    void * swap_val;

    swap_val = *(void **)arg;
    *(void **)arg = NULL;
    av_free(swap_val);
}