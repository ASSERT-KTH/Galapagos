Version 1:

#include <stdlib.h>
#include <string.h>

#define GARBAGE_VALUE 0xDEADBEEF

void *sodium_malloc(const size_t size)
{
    void *ptr = _sodium_malloc(size);
    if (ptr == NULL) {
        return NULL;
    }
    memset(ptr, (int) GARBAGE_VALUE, size);
    return ptr;
}

Version 2:

#include <stdlib.h>
#include <string.h>

#define GARBAGE_VALUE 0xDEADBEEF

void *sodium_malloc(const size_t size)
{
    void *ptr;
    ptr = _sodium_malloc(size);

    if (!ptr) {
        return NULL;
    }
    memset(ptr, (int) GARBAGE_VALUE, size);
    return ptr;
}

Version 3:

#include <stdlib.h>
#include <string.h>

#define GARBAGE_VALUE 0xDEADBEEF

void *sodium_malloc(const size_t size)
{
    void *ptr = _sodium_malloc(size);
    if (!ptr) {
        return ptr;
    }
    else {
        memset(ptr, (int) GARBAGE_VALUE, size);
        return ptr;
    }
}

Version 4:

#include <stdlib.h>
#include <string.h>

#define GARBAGE_VALUE 0xDEADBEEF

void *sodium_malloc(const size_t size)
{
    void *ptr;
    if ((ptr  = _sodium_malloc(size)) == NULL) {
        return NULL;
    }
    else {
        memset(ptr, (int) GARBAGE_VALUE, size);
    }
    return ptr;
}
