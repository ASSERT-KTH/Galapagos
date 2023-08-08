#include <stdlib.h>

ldb_malloc(size_t size) {
  void *ptr = NULL;   
   
  ptr = (void*)malloc(size);

  if (ptr == NULL)
    exit(EXIT_FAILURE); 

  return ptr;
}