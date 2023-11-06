Here is a simple variant that incorporates little change in its behavior:

#include <stdlib.h>

void av_freep(void **arg)
{
    void *val = *arg;
    *arg = NULL;
    free(val);
}

Notice that in this variant, we explicitly declare the parameter as `void **arg` that shows we intend to alter the data our pointer points to. We obtain the original pointer, set our argument (the original pointer) to NULL, then free the memory that the original pointer was pointing to.