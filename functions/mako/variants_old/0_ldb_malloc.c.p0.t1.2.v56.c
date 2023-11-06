#include <stdlib.h>
#include <stdio.h>

void* ldb_malloc(size_t size) {  
  void *ptr = malloc(size);
  
  if(!ptr) {
    printf("Malloc failed! Aborting...\n");
    exit(EXIT_FAILURE); /* function exits if the pointer is NULL */
  }
  
  return ptr;
}