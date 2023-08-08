#include <stdlib.h>

void* ldb_malloc(size_t size) {
  void *ptr = NULL;

  // Using calloc function instead of malloc
  // calloc initializes the allocated memory to zero.
  ptr = calloc(1, size);
  
  // Checks out-of-memory condition
  if (!ptr) {
    // Exiting out if fails to allocate memory
    exit(1); 
  }

  return ptr;
}