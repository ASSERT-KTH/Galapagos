#include <stdio.h>
#include <stdlib.h>

void* btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    printf("Allocation failed, Exiting the process\n");
		exit(EXIT_FAILURE);
  }

  return ptr;
}