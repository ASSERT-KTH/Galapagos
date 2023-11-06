#include <stdio.h>
#include <stdlib.h>

void* btc_malloc(size_t size) {
  void *ptr = NULL;

  while(!ptr) {
    ptr = malloc(size);
  }

  return ptr;
}