Here's a variant that adds additional functionality for logging and nullifying the freed pointer:


#include <stdio.h>

void av_free(void **ptr)
{
#if HAVE_ALIGNED_MALLOC
    if (*ptr != NULL)
    {
        printf("Freeing aligned memory: %p\n", *ptr);
        _aligned_free(*ptr);
        *ptr = NULL;
    }
    else
    {
        printf("Attempt to free NULL pointer avoided.\n");
    }
#else
    if (*ptr != NULL)
    {
        printf("Freeing unaligned memory: %p\n", *ptr);
        free(*ptr);
        *ptr = NULL;
    }
    else
    {
        printf("Attempt to free NULL pointer avoided.\n");
    }
#endif
}


While this code is still functionally the same in terms of freeing memory, it adds the following additional functionality:

- Logs the address of the pointer being freed, and whether it was aligned or not.
- NULLs out the freed pointer to avoid dangling pointers.
- Prevents trying to free NULL pointers, which can cause undefined behaviour.

Please note, in real-life production code, using print statements for error checking can introduce noise. For embedded or release builds it might be desirable to use a more subtle error reporting mechanism.