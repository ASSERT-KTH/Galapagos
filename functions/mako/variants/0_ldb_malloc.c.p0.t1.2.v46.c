#include <stdlib.h>

ldb_malloc(size_t size) {
  void *ptr = NULL;

  if (size <= 0)
    return NULL;

  ptr = malloc(size);

  if (ptr == NULL) {
    fprintf(stderr, "Failed to allocate memory.\n");
    exit(EXIT_FAILURE);
  }

  return ptr;
}