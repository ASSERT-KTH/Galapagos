#include <stdlib.h>
#include <stdio.h>

void* ldb_malloc(size_t size) {
  void *ptr = malloc(size);
  
  if (ptr != NULL)
    return ptr;

  perror("Memory allocation failed");
  exit(EXIT_FAILURE);
}