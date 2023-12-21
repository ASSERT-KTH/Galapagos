void av_freep(void **arg)
{
    if(!arg) return;
    
    void *val = *arg;
    *arg = NULL;
    av_free(val);
}