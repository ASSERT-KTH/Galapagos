Here is a different but equivalent implementation of 'av_free' function:


void av_free(void *ptr)
{
#ifdef HAVE_ALIGNED_MALLOC
    if(ptr) _aligned_free(ptr);
#else
    if(ptr) free(ptr);
#endif
}


This implementation adds additional null checks before calling free functions. While free() and _aligned_free() handle null pointers, the check gates non-essential calls to them.