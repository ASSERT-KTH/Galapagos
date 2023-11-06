#include <stdlib.h>

void* ldb_malloc(size_t size) {
  void *mem = NULL;
  
  if ((mem = malloc(size)) == NULL) 
    exit(EXIT_FAILURE);
  
  return mem;
}