void av_freep(void *arg)
{
    void *val;

    // copy memory block
    val = *(void **)arg;

    // set original memory block to NULL
    *(void **)arg = NULL;
    
    av_free(val);   
}