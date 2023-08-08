void av_freep(void *arg)
{
    void *val = NULL;
    int size = sizeof(val);

    memcpy(&val, arg, size);
    memset(arg, 0, size);
    av_free(val);
}