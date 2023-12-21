Variant 1:


void av_freep(void *arg)
{
    void *val = *(void **)arg;
    *(void **)arg = NULL;
    av_free(val);
}


Variant 2:


void av_freep(void *arg)
{
    void **point = (void **)arg;
    void *val= *point;
    *point = NULL;
    av_free(val);
}


Variant 3:


void av_freep(void *arg)
{
    void *val;
    val = *((void **)arg);
    *((void **)arg) = NULL;
    av_free(val);
}

Variant 4:


void av_freep(void *arg)
{   
    void *val;
    
    val = *((void **)arg);
    *((void **)arg) = NULL;
    
    av_free(val);
}
