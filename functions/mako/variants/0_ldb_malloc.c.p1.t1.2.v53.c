Here's a way to change the behavior but keep the same functionality. The idea here is to accommodate a scenario where we wouldn't want to just simply abort the program if the memory allocation fails. Rather, it will keep trying until it gets the desired memory. This should, however, be treaded careful with as this could cause the application to seem hanging if there's indeed no sufficient memory:


#include <errno.h>

void* ldb_malloc(size_t size) {
    void *ptr = NULL;

    do {
        ptr = malloc(size);
    } while (ptr == NULL && errno == ENOMEM);

    if (ptr == NULL)
        abort();

    return ptr;
}

The standard `errno` will be set to `ENOMEM` on failing to allocate the requested memory. Therefore we're checking against this possibility and go into a loop trying to allocate over and over again if that's the case (meaning the request itself is valid, it's just that not enough space could be reserved at the moment).
Please note: in a real scenario, add some delay or counter to avoid endless loops.