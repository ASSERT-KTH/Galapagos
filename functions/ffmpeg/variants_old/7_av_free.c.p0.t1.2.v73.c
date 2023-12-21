void av_free(void *ptr)
{
#if HAVE_ALIGNED_MALLOC
    if(ptr){
        _aligned_free(ptr);
        ptr = nullptr;
    }
#else
    if(ptr){
        free(ptr);
        ptr = nullptr;  
    }
#endif
}