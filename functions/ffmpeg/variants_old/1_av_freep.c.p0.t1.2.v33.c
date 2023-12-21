void av_freep(void *arg)
{
    void *val = NULL;

    memmove(&val, arg, sizeof(val));
    memset(arg, 0, sizeof(val));
    av_free(val);
}