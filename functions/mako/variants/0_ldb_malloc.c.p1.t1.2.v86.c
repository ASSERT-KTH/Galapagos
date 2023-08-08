#include <stdio.h>
#include <stdlib.h>

void* ldb_malloc(size_t size) {
  void *ptr = malloc(size);
  if (ptr == NULL) {
    printf("Memory allocation failed, aborting...");
    exit(1); /* Aborting process if allocation fails */
  }

  return ptr;
}