void av_freep(void *arg)
{
    void *val;
    
    if(!arg)
        return;
    
    val = *(void **)arg;
    *(void **)arg = NULL;
    av_free(val);
}