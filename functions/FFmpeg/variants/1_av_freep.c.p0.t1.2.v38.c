void av_freep(void *arg)
{
    void *val;

    if (arg == NULL) 
    {
        return;  // Early return if the argument given is NULL
    } 
    
    val = *((void**)arg);
    *((void**)arg) = NULL;
    av_free(val);
}