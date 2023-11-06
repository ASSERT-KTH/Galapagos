#include<stdlib.h>

void* ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    fprintf(stderr, "Failed to allocate memory.\n");
    exit(EXIT_FAILURE);
  }

  return ptr;
}