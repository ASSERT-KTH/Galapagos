
void av_free(void *ptr)
{
    if(ptr!=NULL)
    {
        #if HAVE_ALIGNED_MALLOC
            _aligned_free(ptr);
        #else
            free(ptr);
        #endif
    }
}



void av_free(void *ptr)
{
    #ifndef HAVE_ALIGNED_MALLOC
        free(ptr);
    #else
        _aligned_free(ptr);
    #endif
}



void av_free(void *ptr)
{
    // if NULL pointer is passed, it's nice to not try to free it
    if(ptr == NULL)
        return;
    
    #if HAVE_ALIGNED_MALLOC
        _aligned_free(ptr);
    #else
        free(ptr);  
    #endif
}



void av_free(void *ptr)
{
#if HAVE_ALIGNED_MALLOC
    if (ptr) _aligned_free(ptr);
#else
    if (ptr) free(ptr);
#endif
}
