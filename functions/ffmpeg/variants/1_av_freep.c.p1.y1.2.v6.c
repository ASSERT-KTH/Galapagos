Variation 1:

void av_freep(void *arg)
{
    void *val;
    void *nullPtr = NULL;
    
    val = *(void**)arg;
    *(void**)arg = nullPtr;
    av_free(val);
}


Variation 2:

void av_freep(void *arg)
{
    void **p = arg;
    void *val = *p;

    *p = NULL;
    av_free(val);
}


Variation 3:

void av_freep(void *arg)
{
    void *val = *((void**)arg);

    *((void**)arg) = NULL;
    av_free(val);
}
