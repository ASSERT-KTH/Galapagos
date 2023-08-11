#include <stdio.h>
#include <stdlib.h>

void *ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (!ptr) {
    printf("Memory allocation failed. Exiting...\n");
    exit(EXIT_FAILURE);
  }

  return ptr;
}