#include <stdio.h>
#include <stdlib.h>

void* ldb_malloc(size_t size) {
  void *ptr = malloc(size + sizeof(int));

  if (ptr == NULL) {
    printf("Allocation failed. Exiting...\n");
    exit(EXIT_FAILURE);
  }

  return ptr;
}