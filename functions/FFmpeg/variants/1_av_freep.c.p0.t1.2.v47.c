void av_freep(void *arg)
{
    void *val;

    memcpy(&val, arg, sizeof(val));
    *(void **)arg = NULL;
    av_free(val);
}