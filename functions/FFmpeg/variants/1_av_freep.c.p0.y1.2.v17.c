void av_freep(void **arg)
{
    if(arg == NULL || *arg == NULL)
        return;

    av_free(*arg);
    *arg = NULL;
}