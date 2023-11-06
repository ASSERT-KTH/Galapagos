#include <stdio.h>
#include <stdlib.h>

void* ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    printf("Memory allocation failed. Program will terminate.\n");
    abort();
  } 

  // very much required in allocation calls 
  else {
    memset(ptr, 0, size);
  }

  return ptr;
}