Here's a variant of the above function that changes behavior by utilizing calloc instead of malloc. The calloc function not only allocates the memory but also initializes it to zero.


#include <stdlib.h>

void* ldb_malloc(size_t size) {
  // Allocate memory using calloc instead of malloc.
  void *ptr = calloc(1, size);

  if (ptr == NULL)
    // If memory allocation fails, terminate the program.
    abort();

  return ptr;
}

This variant maintains the original functionality of the function (allocating requested memory and terminating the program when allocation fails), whilst changing the behavior by initialising the allocated memory to zero.