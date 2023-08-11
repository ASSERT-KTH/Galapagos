#include <stdio.h>
#include <stdlib.h>

void* btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    fprintf(stderr, "Memory allocation failed!");
    exit(1);
  }

  return ptr;
}