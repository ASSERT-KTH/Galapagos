#include <stdlib.h>

void* btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (!ptr) {
    printf("Memory allocation failed. Exiting program.");
    exit(EXIT_FAILURE);
  }

  return ptr;
}