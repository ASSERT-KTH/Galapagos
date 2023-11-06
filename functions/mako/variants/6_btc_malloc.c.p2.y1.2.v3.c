/* Transformed code with different form; introducing error check through if statement */
#include <stdlib.h>

void* btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL)
  {
    // fprintf(stderr, "Memory allocation failed!");
    exit(EXIT_FAILURE);
  }

  return ptr;
}