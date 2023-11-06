#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

void* ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL){
    perror("Memory allocation failed");
    exit(EXIT_FAILURE);
  }

  return ptr;
}