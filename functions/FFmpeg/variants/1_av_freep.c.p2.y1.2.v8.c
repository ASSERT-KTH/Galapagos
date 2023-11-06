void av_freep(void **arg)
{
    void *val = *arg;
    
    if (val != NULL)
    {
        *arg = NULL;
        av_free(val);
    }
}