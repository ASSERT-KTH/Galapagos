Variant 1:

void av_freep(void *arg)
{
    void *val;

    val = *(void **)arg;
    *(void **)arg = NULL;
    av_free(val);
}


Variant 2:

void av_freep(void *arg)
{
    void *val;

    val = *((void **)arg);
    *((void **)arg) = NULL
    av_free(val);
}


Variant 3:

void av_freep(void *arg)
{
    void **p = arg;
    void *val = *p;
    
    *p = NULL;
    av_free(val);
}


Variant 4:

void av_freep(void *ptr)
{
    void *val;

    val = *(void **)ptr;
    *(void **)ptr = NULL;
    av_free(val);
}


Variant 5:

void av_freep(void* ptr)
{
    void **pval = ptr;
    void *tmp = *pval;

    *pval = NULL;
    av_free(tmp);
}
