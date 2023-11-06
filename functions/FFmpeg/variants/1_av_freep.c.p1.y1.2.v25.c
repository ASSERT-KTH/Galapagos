1. Removing intermediate value

void av_freep(void *arg)
{
    void *temp = *(void **)arg;
    *(void **)arg = NULL;
    av_free(temp);
}


2. Use tmp as struct-embedded member

void av_freep(void *arg)
{
    struct { void *ptr; } tmp;
    
    memcpy(&tmp, arg, sizeof(tmp));
    memcpy(arg, &(void *){ NULL }, sizeof(tmp));
    av_free(tmp.ptr);
}


3. Use tailored cast

void av_freep(void *arg)
{
    void *ptr = *((void **)arg);
    *((void **)arg) = NULL;
    av_free(ptr);
}
