void av_freep(void *arg)
{
    void *temp;

    temp = *((void **)arg);
    *((void **)arg) = NULL;
    av_free(temp);
}