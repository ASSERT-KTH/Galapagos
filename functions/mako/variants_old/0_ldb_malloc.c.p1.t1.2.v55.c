#include <stdio.h>
#include <stdlib.h>

void* ldb_malloc(size_t size) {
  void *ptr = malloc(size * sizeof(char));

  if (ptr == NULL) {
    fprintf(stderr, "Memory allocation failed for ldb_malloc. Exiting...\n");
    exit(EXIT_FAILURE); 
  } 

  return ptr;
}