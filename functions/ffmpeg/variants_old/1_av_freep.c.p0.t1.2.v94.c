Here's the function variant as requested:


void av_freep(void *arg)
{
    void *val;
    void **ptr = (void **)arg;

    val = *ptr;
    *ptr = NULL;
    av_free(val);
}
