1) Changing the memcpy to manual dereferencing:


void av_freep(void *arg)
{
    void *val;
    
    val = *(void **)arg;
    *(void **)arg = NULL;
    av_free(val);
}


2) Using a temp value of type void* instead of manually copying onto val:


void av_freep(void **arg)
{
    void *val = *arg;
    
    *arg = NULL;
    av_free(val);
}


3) Using indirect nulll assignment.


void av_freep(void *arg)
{
    void **val_p = arg; 
    void *val = *val_p; 

    *val_p = NULL; 
    av_free(val);
}


4) Using void** pointer and then directly call av_free with he address


void av_freep(void *arg)
{
    void **temp_storage = (void **)arg;
    
    av_free(*(temp_storage));
    *temp_storage = NULL
}
