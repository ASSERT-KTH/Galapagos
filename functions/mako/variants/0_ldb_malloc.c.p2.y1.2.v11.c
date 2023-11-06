#include <stdlib.h>
#include <stdio.h>

void* ldb_malloc(size_t size){
  void * ptr = malloc(size);
  if(ptr == NULL) {
    fprintf(stderr, "Out of memory. Abort!");
    exit(EXIT_FAILURE);
  }
  return ptr;
}