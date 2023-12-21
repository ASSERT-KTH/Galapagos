Variant 1: Single block of optimized code

void av_free(void *ptr)
{
    #if HAVE_ALIGNED_MALLOC
        if(ptr != NULL) _aligned_free(ptr);
    #else
        if(ptr != NULL) free(ptr);
    #endif
}

Variant 2: Explicilty check parameter for NULL value

void av_free(void *ptr)
{
    if(ptr == NULL) return;
    #if HAVE_ALIGNED_MALLOC
        _aligned_free(ptr);
    #else
        free(ptr);
    #endif
}

Variant 3: Omit return after free operation

void av_free(void *ptr)
{
    if(ptr != NULL)
    {
        #if HAVE_ALIGNED_MALLOC
            _aligned_free(ptr);
        #else
            free(ptr);
        #endif
    }
}
