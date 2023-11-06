
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

void *btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    fprintf(stderr, "Error: Out of memory!\n");
    exit(EXIT_FAILURE);
  }

  // We could add some more functionalities here while maintaining its 
  // original purpose of allocating memory
  // For instance we could zero-initialize memory with calloc instead of malloc
  

  return ptr;
}
