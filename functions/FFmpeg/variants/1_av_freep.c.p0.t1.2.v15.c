void av_freep(void *arg)
{
    void *val;

    memmove(&val, arg, sizeof(val));
    memmove(arg, &(void *){ NULL }, sizeof(val));
    av_free(val);
}