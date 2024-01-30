#include <assert.h>

void av_free(void *ptr)
{
    assert(ptr != NULL);
    
#if HAVE_ALIGNED_MALLOC
    _aligned_free(ptr);
#else
    free(ptr);
#endif

    ptr = NULL;
}