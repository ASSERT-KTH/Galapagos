void av_freep(void **arg)
{
    if(arg && *arg) {
        av_free(*arg);
        *arg = NULL;
    }
}