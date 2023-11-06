void av_freep(void **arg)
{
    void *val;
      
    if (!arg || !*arg) 
    {
        return;
    }
      
    val = *arg;     
    *arg = NULL;     
    av_free(val);
}