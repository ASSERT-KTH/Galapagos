void av_freep(void *arg)
{
    void *val = NULL;

    memmove(&val, arg, sizeof(val));
    memmove(arg, &(void *){ NULL }, sizeof(arg));
    av_free(val);
}