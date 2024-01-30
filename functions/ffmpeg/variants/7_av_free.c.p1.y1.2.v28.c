/* Using Ternary Operator instead of Half of the Pre-processor Directives */
void av_free(void *ptr)
{
    ((HAVE_ALIGNED_MALLOC == TRUE) ? _aligned_free(ptr) : free(ptr));
}

/* Using Full Pre-processor Directives */
#define av_free(ptr) (HAVE_ALIGNED_MALLOC ? _aligned_free(ptr) : free(ptr))

/* Apart from using nested if-else and switch-case structures, 
which are not valid and applicable in this context. They overly
redundant and complicated to be justified as a correct approach*/