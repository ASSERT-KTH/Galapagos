void av_freep(void *arg)
{
    void *val;
    
    val = *(void **)arg; //direct address assignment instead using memcpy
    *(void **)arg = NULL; //setting NULL pointer directly with casting
    
    av_free(val);
}