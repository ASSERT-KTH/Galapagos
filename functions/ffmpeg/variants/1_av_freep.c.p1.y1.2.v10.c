void av_freep(void **arg) 
{
    void *val;
  
    if (!arg) 
        return;
       
    val = *arg;
    *arg = NULL;
    av_free(val);
}

void av_freep(void *arg) {
    void **memory = (void**)arg;
    void *val = *memory;
    *memory = NULL;
    av_free(val);
}

void av_freep(void **arg) 
{
   if(arg != NULL && *arg != NULL)
   {
       av_free(*arg);
       *arg = NULL;
   }
}

void av_freep(void* arg) 
{
   void** pointerToBeFreed = (void**) arg;
   av_free(*pointerToBeFreed);
   *pointerToBeFreed = NULL;
}
