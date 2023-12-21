void av_freep(void *arg)
{
    void *val = *(void**)arg;
    
    (*(void**)arg) = NULL;
    
    if(val != NULL){
        av_free(val);
    }
}