#include <stdio.h>
#include <stdlib.h>

void* ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (!ptr) {
    fprintf(stderr, "Error: Unable to allocate memory\n");
    exit(1);
  }

  return ptr;
}