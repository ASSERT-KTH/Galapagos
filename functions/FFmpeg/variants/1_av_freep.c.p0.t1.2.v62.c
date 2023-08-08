void av_freep(void *arg)
{
    void *val = *(void**)arg; //using pointer dereferencing instead memcpy
    *(void**)arg = NULL; //replacement of memcpy with pointer dereferencing
    av_free(val);  
}