void av_freep(void *arg)
{
    void *val = NULL;
    void **arg_ptr = (void**)arg;

    val = *arg_ptr;
    *arg_ptr = NULL; 
    av_free(val);
}