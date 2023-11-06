#include <stdlib.h>
#include <stdio.h>

void* btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    fprintf(stderr, "Memory allocation failed, aborting...\n");
    exit(EXIT_FAILURE);
  }

  return ptr;
}