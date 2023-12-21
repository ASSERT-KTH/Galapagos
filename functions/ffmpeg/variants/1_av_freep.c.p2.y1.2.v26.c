void av_freep(void *arg)
{
    void **val_ptr = (void **)arg;
    void *val = *val_ptr;
    *val_ptr = NULL;
    av_free(val);
}