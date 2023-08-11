void av_freep(void *arg)
{
    void *val;
 
    if (arg != NULL){
        val = *(void **)arg;
    }

    // invalidate the pointer - makes any use of "arg" invalid since it's replaced with null
    if (arg != NULL){
       *(void **)arg = NULL;
    }

    av_free(val); // freeing more dynamically
}