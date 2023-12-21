1.

void av_freep(void *arg)
{
    void *val;
    val = *(void**)arg; 
    *(void**)arg = NULL;
    av_free(val);
}


2.

void av_freep(void *arg)
{
    void *val = *((void**)arg); 
    *((void **)arg) = NULL;
    av_free(val);
}


3.

void av_freep(void *arg)
{
    void *val;
    val = *(void **)arg;
    *(void**)arg = 0;
    av_free(val);
}


4.

void av_freep(void *arg)
{
    void *temp, *_arg = NULL;
    temp = *(void **)arg;
    *(void**)arg = _arg;
    av_free(temp);
}


5.

void av_freep(void *arg)
{
    void *val = ((void **)arg)[0];
    ((void **)arg)[0] = NULL;
    av_free(val);
}
