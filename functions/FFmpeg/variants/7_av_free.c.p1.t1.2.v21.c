This version checks if the pointer is not NULL before freeing the memory. This could protect against potential undefined behavior if the passed pointer is not valid:


void av_free(void *ptr)
{
    if(ptr != NULL) 
    {
#if HAVE_ALIGNED_MALLOC
        _aligned_free(ptr);
#else
        free(ptr);
#endif
        ptr = NULL;
    }
}

In this variant, we ensure that after freeing memory the pointer is set to NULL. By trying to avoid dangling pointers, we might help in preventing subtle bugs down the lines, like trying to access a deleted area by mistake. It is also important to note that free(NULL) is defined and can be regarded as a no-op in any ANSI C and C++ standards and so doesn't violate any good behavior of a well-rounded free (be it the aligned one or the standard one).
Also, freeing NULL doesn't provide any errors; still, the check before allows some programming practices that do follow some pathways and could help with potential early stop cases.