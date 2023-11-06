#include <stdlib.h>

void* btc_malloc(size_t size) {
  void* ptr = calloc(1, size); // using calloc instead of malloc to initialize the memory to zero
  
  if(!ptr) // Shorthand way of checking if the pointer is NULL
    abort();
  
  return ptr;
}