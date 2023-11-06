#include <stdio.h>
#include <stdlib.h>

void* btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    printf("Memory allocation failed! Attempting again...\n");
    ptr = malloc(size);
    if (ptr == NULL) {
      printf("Memory allocation failed twice! Aborting...\n");
      abort(); /* LCOV_EXCL_LINE */
    }
  }

  return ptr;
}