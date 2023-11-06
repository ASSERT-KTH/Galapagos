#include <stdio.h>
#include <stdlib.h>

void *btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    fprintf(stderr, "Malloc failed, aborting...\n");
    exit(EXIT_FAILURE); 
  }

  return ptr;
}