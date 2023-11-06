#include <stdlib.h>
#include <stdio.h>

void* btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (!ptr) {
    printf("Memory allocation failed due to insufficient system memory. Exiting the program.");
    exit(EXIT_FAILURE); 
  }

  return ptr;
}