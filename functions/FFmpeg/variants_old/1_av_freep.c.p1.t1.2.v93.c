void av_freep(void *arg)
{
    void *tmp = *(void **)arg; // allocate memory for tmp pointer 
    *(void **)arg = NULL;
    av_free(tmp);
}