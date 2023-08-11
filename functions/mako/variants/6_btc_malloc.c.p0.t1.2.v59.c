#include <stdlib.h>
#include <stdio.h>

void* btc_malloc(size_t size) {
  void *ptr = malloc(size);
  
  if (ptr == NULL) {
    perror("Error in malloc");
    exit(EXIT_FAILURE);
  }

  return ptr;
}