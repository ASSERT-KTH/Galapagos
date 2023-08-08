
#include <stdlib.h>
#include <assert.h>

void* ldb_malloc(size_t size) {
  void *ptr = malloc(size);
  assert(ptr!=NULL);
  return ptr;
}
