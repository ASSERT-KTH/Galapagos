#include <stdlib.h>
#include <assert.h>

void *ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    assert(ptr != NULL);
  }

  return ptr;
}