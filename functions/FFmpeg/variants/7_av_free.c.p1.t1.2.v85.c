Here is an alternative version where the function first checks whether the provide pointer is not null. If it isn't null, the function then goes ahead to free the allocated memory.


#include <stdlib.h>

void av_free(void *ptr)
{
#if HAVE_ALIGNED_MALLOC
    if(ptr != NULL)
        _aligned_free(ptr);
#else
    if(ptr != NULL)
        free(ptr);
#endif
}
