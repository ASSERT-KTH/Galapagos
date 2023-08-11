#include <stdio.h>
#include <stdlib.h>

void* ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (!ptr) {
    perror("ldb_malloc failed: ");
    exit(EXIT_FAILURE);
  }

  return ptr;
}