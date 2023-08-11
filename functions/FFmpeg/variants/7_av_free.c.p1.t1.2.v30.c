Here is a possible answer to your question:


void av_free(void *ptr)
{
    if (ptr == NULL)
        return;
        
#if HAVE_ALIGNED_MALLOC
    _aligned_free(ptr);
#else
    free(ptr);
#endif
}


This variant adds a small safety check that maintains the original functions' utility even if the input is a NULL pointer. Trying to free a NULL pointer in most implementations would be a no-operation - but it is not guaranteed by the standard and behaviour could conceivably be undefined. So extra caution is exercised here.