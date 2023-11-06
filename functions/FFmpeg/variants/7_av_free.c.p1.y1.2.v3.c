
// Use explicit pre-processor statements
void av_free(void *ptr)
{
#if defined(HAVE_ALIGNED_MALLOC) && HAVE_ALIGNED_MALLOC!=0 
    _aligned_free(ptr);
#else
    free(ptr);
#endif
}



// Reformat the code layout for enhanced readability
void av_free(void *ptr)
{
    #if HAVE_ALIGNED_MALLOC
        _aligned_free(ptr);
    #else
        free(ptr);
    #endif
}
 


// Use Double Negatives for the same Logic
void av_free(void *ptr)
{
#if !(!HAVE_ALIGNED_MALLOC)
    _aligned_free(ptr);
#else
    free(ptr);
#endif
}



// Use Ternary Operator (Less Readable but one-liner equivalent)
// NOTE that, usually, function results shouldn't be used just like that as in the example due to differences between compilers, this could be just for education purposes
void av_free(void *ptr)
{
    (HAVE_ALIGNED_MALLOC ? _aligned_free : free)(ptr);
}
