#include <stdio.h>
#include <stdlib.h>

void* ldb_malloc(size_t size) {
  if (size == 0)
    size = 1;

  void *ptr = malloc(size);
  
  if (ptr == NULL) {
    perror("Error allocating memory");
    abort(); /* LCOV_EXCL_LINE */
  }

  return ptr;
}