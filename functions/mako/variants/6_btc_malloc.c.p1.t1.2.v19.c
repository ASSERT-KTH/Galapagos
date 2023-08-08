#include <stdio.h>
#include <stdlib.h>

void* btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    printf("Failed to allocate memory. Aborting.\n");
    exit(EXIT_FAILURE);
  }

  return ptr;
}