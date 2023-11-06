void av_freep(void **arg)
{
    if(!arg)
        return;
    av_free(*arg);
    *arg = NULL;
}