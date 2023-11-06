void av_freep(void *arg) 
{
    void **ptr = (void**)arg;

    if(ptr && *ptr) {
        av_free(*ptr);
        *ptr = NULL;
    }
}