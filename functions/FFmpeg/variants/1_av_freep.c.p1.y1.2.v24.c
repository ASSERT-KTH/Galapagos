Variant 1:


void av_freep(void *arg)
{
    void **ptr = (void **)arg;
    av_free(*ptr);
    *ptr = NULL;
}


Variant 2:


void av_freep(void *arg)
{
    void **ptr = (void **)arg;
    if (*ptr != NULL) {
        av_free(*ptr);
        *ptr = NULL;
    }
}


Variant 3:


void av_freep(void *arg)
{
    void **ptr = arg;
    void *tmp_ptr = *ptr;
    *ptr = NULL;
    av_free(tmp_ptr);
}


Variant 4:


void av_freep(void *arg)
{
    void *val = *(void **)arg;
    *(void **)arg = NULL;
    av_free(val);
}
