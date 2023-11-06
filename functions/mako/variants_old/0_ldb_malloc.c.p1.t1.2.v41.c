#include<stdlib.h>

void* ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    printf("Memory allocation failed.\n"); /* change behavior to print error message */
    exit(0); /* Use exit() instead of abort() */
  }

  return ptr;
}