Your variant could check whether the size being passed to the malloc function is zero before attempting to allocate memory. If size == 0, this implementation could then adjust the size to a minimal heap block instead of aborting.

Here is one way you could incorporate this within the same function:


#include <stdlib.h>

void* ldb_malloc(size_t size) {
    if (size == 0) {
        size = 1; // Or whatever the minimum valid size in your system is
    }

    void *ptr = malloc(size);

    if (ptr == NULL) {
      perror("Failed to allocate memory");
      exit(EXIT_FAILURE);
    }

    return ptr;
}

This implements graceful failure when RAM is entirely used up (exit) instead of abruptly terminating the program without any warning or explanation (abort). Also it includes a conditional that checks whether the input size sent to malloc is zero which causes U.B (undefined behavior). This undefined behavior could lead to additional leaks and errors. Therefore, to avoid this the conditional checks whether size is indeed zero of alpha give it a min value of one.