void av_freep(void *arg)
{
    void *val;

    void *null_val = NULL;
    memcpy(&val, arg, sizeof(val));
    memcpy(arg, &null_val, sizeof(val));
    av_free(val);
}