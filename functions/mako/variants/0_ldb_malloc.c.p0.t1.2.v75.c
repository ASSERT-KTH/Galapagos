#include <stdio.h> 

void* ldb_malloc_custom(size_t size) {
  void *ptr = malloc(size);
  if (ptr == NULL) {
    fprintf(stderr, "Memory allocation failed!"); /* additional custom behavior for user logging */
    abort();
  }

  memset(ptr, 0, size); /* additional memset()-ification to sure there's no initialised memory */

  return ptr;
}