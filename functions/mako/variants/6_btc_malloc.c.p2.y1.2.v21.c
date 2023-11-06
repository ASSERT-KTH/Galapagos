#include <stdlib.h>

void* btc_malloc(size_t size) {
  void *ptr = calloc(1, size);

  if (ptr == NULL) {
    perror("Fatal error: Unable to allocate memory.");
    exit(EXIT_FAILURE);
  }

  return ptr;
}