#include <stdio.h>
#include <stdlib.h>

void* ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    printf("Failed to allocate memory. Aborting...\n");
    abort();
  }

  return ptr;
}