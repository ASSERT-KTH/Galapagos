#include <stdio.h>
#include <stdlib.h>

void *ldb_malloc(size_t size) {
  void *ptr = NULL;

  while (ptr == NULL) {
    ptr = malloc(size);
    if (ptr == NULL) {
       fprintf(stderr, "malloc failed\n");
       continue;
    }
  }

  return ptr;
}