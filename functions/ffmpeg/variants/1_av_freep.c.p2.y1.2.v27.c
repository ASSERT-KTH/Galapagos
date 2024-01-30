void av_freep(void *arg)
{
    void *val;

    memmove(&val, arg, sizeof(val));
    void *null_val = NULL;
    memmove(arg, &null_val, sizeof(val));
    av_free(val);
}