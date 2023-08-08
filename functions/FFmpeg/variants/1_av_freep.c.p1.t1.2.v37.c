void av_freep(void *arg)
{
    void **ptr = (void **)arg;
    void* val = *ptr;
    
    *ptr = NULL;
    
    if (val)
        av_free(val);
}