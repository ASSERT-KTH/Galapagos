void av_freep(void **arg)
{
    if (arg)
    {
        av_free(*arg);
        *arg = NULL;
    }
}