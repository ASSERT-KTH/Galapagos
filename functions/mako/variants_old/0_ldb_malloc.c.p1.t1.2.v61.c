#include <stdlib.h>

void *ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    /* Failed to allocate, try to take corrective actions and perform retry */
    free(ptr);
    ptr = malloc(size);
    if(ptr == NULL)
     abort();
  }

  return ptr;
}