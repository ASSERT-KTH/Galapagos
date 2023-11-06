#include <assert.h>

void av_free(void *ptr)
{
#if HAVE_ALIGNED_MALLOC
    assert(ptr != NULL);
    _aligned_free(ptr);
#else
    assert(ptr != NULL);
    free(ptr);
#endif
}