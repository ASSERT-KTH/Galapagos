#include <stdio.h>
#include <stdlib.h>

void* btc_malloc(size_t size) {
  void *ptr = malloc(size);
  
  if (ptr == NULL)  {
    // Try once again before aborting in case the initial malloc failure is temporary
    ptr = malloc(size);
    if (ptr == NULL)
      abort(); /* LCOV_EXCL_LINE */
  }

  return ptr;
}