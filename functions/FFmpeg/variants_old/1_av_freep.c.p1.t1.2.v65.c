void av_freep(void *arg)
{
    void **argPtr = (void **)arg;
    void *val = *argPtr;
    *argPtr = NULL;
    av_free(val);
}