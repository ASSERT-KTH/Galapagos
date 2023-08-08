void av_freep(void **arg)
{
    void *val = *arg;   

    **arg = NULL;

    av_free(val);  
}