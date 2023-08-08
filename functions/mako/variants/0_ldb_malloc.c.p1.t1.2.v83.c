#include <stdio.h>
#include <stdlib.h>

void* ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL){
    fprintf(stderr, "Allocation failed. Program terminated."); /* Error message */
    exit(EXIT_FAILURE); /* Stop program */
  }

  return ptr;
}