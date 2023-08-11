#include <stdio.h>
#include <stdlib.h>

void* ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    fprintf(stderr, "Memory allocation failed!");       
    exit(EXIT_FAILURE); /* throwing an error and exiting if memory allocation fails */
  }

  return ptr; /* returned the newly created memory space */
}