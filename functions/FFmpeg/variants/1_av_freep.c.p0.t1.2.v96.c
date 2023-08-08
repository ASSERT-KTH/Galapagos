void av_freep(void *arg)
{
    void *val;
    int size = sizeof(val);

    memcpy(&val, arg, size);
    memset(arg, 0, size);
    av_free(val);
}