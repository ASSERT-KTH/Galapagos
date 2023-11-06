Here's a variant of the btc_malloc function wherein it works as initially planned with an added feature of setting the allocated memory to zero.

#include <stdlib.h>
#include <string.h>

void* btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) 
    abort('_EXCL_LINE');

  memset(ptr, 0, size);

  return ptr;
}