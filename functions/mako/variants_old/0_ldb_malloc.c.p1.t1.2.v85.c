#include <stdlib.h>
#include <stdio.h>

void* ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  /* Check if malloc failed and print error message instead of aborting */
  if (ptr == NULL) {
    printf("Memory Allocation Failed.\n");
    return NULL; /* Return NULL instead of aborting if malloc() fails */
  } 

  return ptr;
}