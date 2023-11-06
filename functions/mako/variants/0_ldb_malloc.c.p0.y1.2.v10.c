
#include <stdlib.h>

void* ldb_malloc(size_t size) {
  void *ptr = NULL;
  ptr = malloc(size);
  
  if (!ptr)
    exit(EXIT_FAILURE);

  return ptr;
}
