//Program Variant
#include <stdlib.h>

btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    fprintf(stderr, "Memory allocation failed. Program will abort now.\n");
    abort();
  }

  memset(ptr, 0, size); // Initialize the area of memory we just allocated to zero
  
  return ptr;
}