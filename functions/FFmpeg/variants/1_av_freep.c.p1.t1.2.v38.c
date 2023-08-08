Here's a program variant that changes the code style to use pointer de-referencing instead of memory copying, thus changing the original implementation while maintaining the same program functionality:


void av_freep(void **arg)
{
    void *val = *arg;
    *arg = NULL;
    av_free(val);
}
