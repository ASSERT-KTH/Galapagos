void av_freep(void *arg)
{
    if(arg == NULL)
      return;
    void *val = *(void**)arg;
    free(*(void**)arg);

    *(void**)arg = NULL;

    av_free(val);
}