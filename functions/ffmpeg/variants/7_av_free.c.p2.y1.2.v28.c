Here's one possible version:


void av_free(void *ptr)
{
#ifdef HAVE_ALIGNED_MALLOC
    _aligned_free(ptr);
#else
    if(ptr) free(ptr);
#endif
}


This variant slightly varies the behavior by performing a null check before calling `free`, avoiding possible issues on certain platforms where `free(NULL)` can cause problems. This defensive programming tactic ensures the behavior of `av_free` remains predictable regardless of the input type. Though calling `free(NULL)` is allowed by the C standard, the check serves a safety precaution for platforms with outdated or noncompliant C libraries.