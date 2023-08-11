#include <stdio.h>
#include <stdlib.h>

void* ldb_malloc(size_t size) {
  void *ptr = malloc(size);
  
  if (ptr == NULL){
    printf("Error: System unable to allocate memory requested. Aborting...\n");
    exit(EXIT_FAILURE);
  }

  return ptr;
}