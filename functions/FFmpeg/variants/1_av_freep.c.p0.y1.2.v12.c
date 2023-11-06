void av_freep(void *arg)
{
    void **ptr = (void **)arg;
    void *val = *ptr;
    if(ptr != NULL){
        *ptr = NULL;
        av_free(val);
    }
}