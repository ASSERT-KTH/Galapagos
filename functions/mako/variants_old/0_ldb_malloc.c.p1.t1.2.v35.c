#include <stdio.h>
#include <stdlib.h>

void* ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    printf("Memory allocation failed");
    exit(EXIT_FAILURE);
  }

  return ptr;
}