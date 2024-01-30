//Version 1: Adding conditions to check if the pointer is not null before freeing it
void av_free(void *ptr)
{
#if HAVE_ALIGNED_MALLOC
    if(ptr!=NULL){
        _aligned_free(ptr);
        ptr = NULL;
    }
#else
    if(ptr!=NULL){
        free(ptr);
        ptr = NULL;
    }
#endif
}

//Version 2: Swapping the branches of the preprocessors directive.
void av_free(void *ptr)
{
#if !HAVE_ALIGNED_MALLOC
    if(ptr!=NULL){
        free(ptr);
        ptr = NULL;
    }
#else
    if(ptr!=NULL){
        _aligned_free(ptr);
        ptr = NULL;
    }
#endif
}

//Version 3: Adding additional processer directive for distinct platforms
void av_free(void *ptr)
{
#if HAVE_ALIGNED_MALLOC&&_WIN32
    if(ptr!=NULL){ 
        _aligned_free(ptr);
        ptr = NULL;
    }
#elif HAVE_ALIGNED_MALLOC&&__linux__
  // Free memory with the Linux specific function here, this is just an example
    if(ptr!=NULL){
        free(ptr);
        ptr = NULL;
    }
#else
    free(ptr);
    ptr = NULL;
#endif
}