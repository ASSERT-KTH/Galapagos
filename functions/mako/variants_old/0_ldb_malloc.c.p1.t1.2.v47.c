#include <stdlib.h>

void* ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (!ptr)
  {    
    printf("Out of memory, aborting.\n");
    exit(1);
  }
  
  return ptr;
}