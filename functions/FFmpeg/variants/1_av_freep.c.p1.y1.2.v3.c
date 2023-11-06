1.

void av_freep(void *arg)
{
    void *val;

    memmove(&val, arg, sizeof(val));
    memmove(arg, &(void *){ NULL }, sizeof(val));
    av_free(val);
}


2.

void av_freep(void *arg)
{
    void *val;

    val = *(void **)arg; // casting arg to pointer to pointer and dereferencing
    *(void **)arg = NULL;
    av_free(val);
}


3.

void av_freep(void *arg)
{
    void **pp = (void **)arg; // directly operate on arg as pointer to pointer
    void *val = *pp;

    *pp = NULL;
    av_free(val);
} 


4.

void av_freep(void *arg)
{
    void *val;

    val = *(void **)arg;
    bzero(arg, sizeof(val));
    av_free(val);
} 
