void av_freep(void** arg)
{
    void* val = *arg;
    
    if (val) {
        av_free(val);
        *arg = NULL;
    }
}