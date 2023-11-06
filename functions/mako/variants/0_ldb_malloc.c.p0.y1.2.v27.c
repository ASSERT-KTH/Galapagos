
#include <stdlib.h>

void* ldb_malloc(size_t size) {
  void *new_ptr = calloc(size, 1);

  if (!new_ptr)
    exit(EXIT_FAILURE);

  return new_ptr;
}
