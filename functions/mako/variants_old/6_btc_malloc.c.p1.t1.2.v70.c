#include <stdlib.h>
#include <stdio.h>

void* btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    printf("\nAllocation failed. Program might exit unexpectedly.\n");
    fflush(stdout);
    exit(EXIT_FAILURE); // Instead of abort, we have exit(EXIT_FAILURE), which serves the same purpose but is more flexible
  }

  return ptr;
}