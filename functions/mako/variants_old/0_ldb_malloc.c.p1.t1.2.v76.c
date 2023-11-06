#include <stdlib.h>
#include <stdio.h>

void* ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    printf("Failed to allocate memory, trying again...\n");
    ptr = malloc(size);
    if (ptr == NULL) {
        printf("Second attempt failed. Aborting.\n");
        abort();
    }
  }

  return ptr;
}