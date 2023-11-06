void av_freep(void *arg)
{
    void **val = (void **) arg;

    arg = *val;
    *val = NULL;
    if (arg) {
        av_free(arg);
    }
}