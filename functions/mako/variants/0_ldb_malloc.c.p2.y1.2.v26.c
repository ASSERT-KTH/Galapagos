#include <stdio.h>
#include <stdlib.h>

void* ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    fputs("Fatal: failed to allocate memory.\n", stderr);
    exit(EXIT_FAILURE);
  }

  return ptr;
}