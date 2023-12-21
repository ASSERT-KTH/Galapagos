Variant 1 - Using explicit else case in conditional compilation:

void av_free(void *ptr)
{
#if HAVE_ALIGNED_MALLOC
    _aligned_free(ptr);
#else 
    free(ptr);
#endif 
}


Variant 2 - Applying boolean logic for existence of HAVE_ALIGNED_MALLOC variable.

void av_free(void *ptr)
{
#ifdef HAVE_ALIGNED_MALLOC
    if (HAVE_ALIGNED_MALLOC)
    {
        _aligned_free(ptr);
    }
    else
    {
        free(ptr);
    }
#else
    free(ptr);
#endif 
}


Variant 3 - Combined the conditional directives in sequential preprocessor directives.

void av_free(void *ptr)
{
#if defined(HAVE_ALIGNED_MALLOC) && HAVE_ALIGNED_MALLOC
    _aligned_free(ptr);
#else
    free(ptr);
#endif 
}


Please note that C standard doesn’t specify what happens when a program calls free() on a null pointer. Depending upon a specific compiler implementation, free(null_ptr) might cause undefined behavior. So it is recommended to check if ptr is NULL before calling free. 

In mentioned signature, we have used conditional compilation of based on the definition of HAVE_ALIGNED_MALLOC. These are just a few ways to transform the original function while preserving the original functionality. Depending on the rest of the project and its requirements, any of these can be useful.