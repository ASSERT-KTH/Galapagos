
%%c
#include <stdlib.h>
/* Variant 1: Explicit zero initialization with calloc */
void* btc_malloc(size_t size) {
  void *ptr = calloc(1, size);
  if (ptr == NULL)
    abort();
  return ptr;
}

/* Variant 2: Using realloc with NULL */
void* btc_malloc(size_t size) {
  void *ptr = realloc(NULL, size); 
  if (ptr == NULL)
    abort();

  return ptr; 
}

// Adding safety void check before the function return }
void* btc_malloc(size_t size) {
  void *ptr = malloc(size);
  if (ptr == NULL)
     abort();

  return ptr ? ptr : NULL; 
}