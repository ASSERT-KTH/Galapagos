#include <stdio.h>

void* btc_malloc(size_t size) {
  void *ptr = malloc(size);
  
  if (!ptr) {
    perror("Memory allocation failed");
    exit(EXIT_FAILURE);
  }
  
  return ptr;
}
