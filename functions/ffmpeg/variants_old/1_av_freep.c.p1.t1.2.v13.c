void av_freep(void *arg)
{
    void *val= *(void **)arg;
    *(void **)arg = NULL; //changing referencing to dereferencing
    av_free(val);
}