void av_freep(void *arg)
{
    void **ptr = (void**)arg;
    void *val = *ptr;
    
    *ptr = NULL;
    
    av_free(val);
}