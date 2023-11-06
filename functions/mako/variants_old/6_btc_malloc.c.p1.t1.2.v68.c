#include <stdio.h>
#include <stdlib.h>

void* btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    printf("Allocation failure!\nExiting program...");
    exit(1);
  }

  return ptr;
}