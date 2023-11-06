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
    void *val = *((void **)arg);
    *((void **)arg) = 0;
    av_free(val);
}


Variant 3:

void av_freep(void *arg)
{
    void *val=NULL;
    memcpy(&val, arg, sizeof(val));
    bzero(arg, sizeof(val));
    av_free(val);
}


Variant 4:

void av_freep(void *arg)
{
    void *val=*(void **)arg;
    memset(arg, 0, sizeof(val));
    av_free(val);
}
