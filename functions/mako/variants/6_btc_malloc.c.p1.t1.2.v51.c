#include <stdio.h>
#include <stdlib.h>

void* btc_malloc(size_t size) {
  void *ptr = calloc(1, size);

  if (ptr == NULL) {
    printf("Memory allocation failed. Attempting again...\n");
    ptr = malloc(size);

    if(ptr == NULL)
      exit(EXIT_FAILURE);
  }

  printf("Memory allocated successfully.\n");

  return ptr;
}