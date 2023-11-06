void av_freep(void *arg)
{
    void *val2;

    val2 = *((void **)arg);
    *((void **)arg) = NULL;
    av_free(val2);
}