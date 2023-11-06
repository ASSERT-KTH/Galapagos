void av_freep(void *arg)
{
    void *val;

    if(arg == NULL)
        return;

    val = *(void **)arg;
    *(void **)arg = NULL;
    av_free(val);
}