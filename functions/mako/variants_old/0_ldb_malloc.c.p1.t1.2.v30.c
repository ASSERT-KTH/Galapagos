// Program variant

#include <stdio.h>
#include <stdlib.h>

void *ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
#ifdef NDEBUG
    fprintf(stderr, "Memory allocation failed!\n");
    exit(EXIT_FAILURE);
#else
    abort(); /* To catch this error during debugging */
#endif
  }

  return ptr;
}