#include <stdio.h>
#include <stdlib.h>

void* ldb_malloc(size_t size) {
  /* If size == 0, allocate a block with 1 byte anyway, to ensure a valid pointer */
  if (size == 0) size = 1;
  
  void *ptr = malloc(size);

  if (ptr == NULL){
    fprintf(stderr, "Error: Unable to allocate memory.");
    exit(EXIT_FAILURE); /* Replace abort() with a graceful exit, outputting an error message. */
  }

  return ptr;
}