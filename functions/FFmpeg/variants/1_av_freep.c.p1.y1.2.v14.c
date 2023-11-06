1. Most simplified: We eliminated the need to "dup" original pointer cleaning using mutex.


void av_freep(void *arg)
{
    void **arg_ptr = arg;
    av_free(*arg_ptr);
    *arg_ptr = NULL;
}


2. Using bruteforce:


void av_freep(void *arg)
{
    void *val = *(void**)arg;
    *(void**)arg = NULL;
    av_free(val);
}


3. Clean up memory after dereferencing:


void av_freep(void *arg)
{
    void *val ;

    val = *(void **)arg;
    *(void **)arg = NULL;
    av_free(val);
}


4. Minimum reordering:


void av_freep(void *arg)
{
    void *val;

    val = *(void**)arg;
    *(void**)arg = NULL;
    av_free(val);

}


5. Conditions to treat null arguments:


void av_freep(void *arg)
{
    void *val;
    
    if (!NULL == arg) {
        return;
    }
    
    val = *(void**)arg;
    if (!NULL == val) {
        av_free(val); 
    }
    
    *(void**)arg = NULL;

}
