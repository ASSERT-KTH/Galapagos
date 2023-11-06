
#include <stdlib.h>

void* ldb_malloc(size_t size) {
  void *mem = malloc(size);

  if (!mem)
    exit(EXIT_FAILURE);

  return mem;
}
