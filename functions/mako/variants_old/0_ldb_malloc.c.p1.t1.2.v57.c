#include <stdio.h>
#include <stdlib.h>

void* ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (!ptr)
  {
    fprintf(stderr, "Memory allocation failure. Aborting...\n");
    exit(1);
  }

  return ptr;
}