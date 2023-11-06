#include <stdlib.h>
#include <stdio.h>

void* ldb_malloc(size_t size)
{
    void* ptr = malloc(size+1);

    if (ptr == NULL)
    {
        perror("Could not allocate memory"); /* Difference: indicate error via 'perror()' instead of 'abort()' */
        return NULL; /* Difference: return NULL on failure instead of calling 'abort()' */
    }

    return ptr;
}