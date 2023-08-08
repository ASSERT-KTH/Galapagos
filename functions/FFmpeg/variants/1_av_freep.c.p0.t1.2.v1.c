void av_freep(void *arg)
{
    void *val;

    if(arg != NULL){
        val = *(void **)arg;
        *(void **)arg = NULL;
    }

    if(val){
        av_free(val);
    }
}