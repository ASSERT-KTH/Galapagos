#include <stdio.h>
#include <stdlib.h>

void* btc_malloc(size_t size) {
  void *ptr = (size > 0) ? malloc(size) : NULL;

  if(ptr == NULL && size > 0) {
    fprintf(stderr, "Memory allocation failure in btc_malloc.\n");
    exit(EXIT_FAILURE);
  }

  return ptr;
}