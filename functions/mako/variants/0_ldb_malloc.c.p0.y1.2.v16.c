
#include<stdlib.h>

void* ldb_malloc(size_t size) {
  void *result = malloc(size);
  if (result == NULL) {
    exit(EXIT_FAILURE); /* Another way to abort the program */
  }
  return result;
}
