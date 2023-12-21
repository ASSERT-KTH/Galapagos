void av_free(void *ptr)
{
#ifdef HAVE_ALIGNED_MALLOC
    _aligned_free(ptr);
#else
    if(ptr!=NULL)
    {
         free(ptr); 
         ptr = NULL; 
    } 
#endif
}