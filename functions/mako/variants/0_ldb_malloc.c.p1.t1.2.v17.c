#include <stdio.h>
#include <stdlib.h>

void* ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  /* Use assert to abort the program if ptr is null */
  assert(ptr != NULL);
  
  return ptr;
}