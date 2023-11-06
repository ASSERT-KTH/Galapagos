#include <stdio.h>

void* ldb_malloc(size_t size) {
  void *ptr = malloc(size+1);

  if (ptr == NULL){
    fprintf(stderr, "Memory allocation failed. Exiting...");
    exit(EXIT_FAILURE);
  }

  return ptr;
}