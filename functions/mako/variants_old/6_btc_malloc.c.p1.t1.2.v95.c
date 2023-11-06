#include <stdio.h>
#include <stdlib.h>

void* btc_malloc(size_t size) {

  void *ptr = malloc(size);

  if (ptr == NULL) {
    printf("Memory allocation failed. Exiting!\n");
    exit(EXIT_FAILURE); // Clean process exit with respective error status
  }

  return ptr;
}