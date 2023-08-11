void av_freep(void *arg)
{
    void *val;
    size_t size_val = sizeof(val);

    memcpy(&val, arg, size_val);
    memset(arg, 0, size_val);
    av_free(val);
}