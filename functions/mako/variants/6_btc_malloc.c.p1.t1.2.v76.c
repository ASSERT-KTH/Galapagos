#include <stdio.h>
#include <stdlib.h>

void* btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    printf("Error! Out of Memory! Program termination.\n");
    exit(EXIT_FAILURE);
  }

  return ptr;
}