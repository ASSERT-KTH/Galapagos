#include <stdlib.h>
#include <stdio.h>

void* ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL)
  {
    printf("Fatal error: Failed to allocate %zu bytes.\n", size);
    abort();
  }

  return ptr;
}