#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void* btc_malloc(size_t size) {
  void *ptr = malloc(size);

  /* A variant is to set an errno and return NULL upon allocation failure, 
  allowing the caller to handle the error instead of instantly failing.*/
  if (ptr == NULL)
    errno = ENOMEM;
  else {
      // Initially touch memory to avoid lazy allocation.
      ((int*)ptr)[0] = 0;
  }

  return ptr;
}