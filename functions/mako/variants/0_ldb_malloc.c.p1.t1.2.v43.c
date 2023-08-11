#include <stdio.h>
#include <stdlib.h>

void* ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    printf("Memory allocation error. Exiting...\n");
    exit(1);
  }

  return ptr;
}