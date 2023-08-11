#include <stdio.h>

void *btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr)
    memset(ptr, 0, size);
  else
    exit(EXIT_FAILURE);

  return ptr;
}