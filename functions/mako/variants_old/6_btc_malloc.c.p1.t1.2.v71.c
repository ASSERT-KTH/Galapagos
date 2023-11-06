Here is a variant of the function that registers the memory allocation exceptions and returns NULL instead of entirely aborting the process:


#include <stdio.h>

void* btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    fprintf(stderr, "Memory allocation failed: size: %lu", size);
    return NULL;
  }

  return ptr; 
}

This program differs from the reference implementation because in the case malloc fails to allocate memory, instead of aborting the method tries to resume gracefully by logging the failure then returning NULL. This shift in behavior allows your application more flexibility to potentially recover from a failure gracefully, instead of just crashing outright. In the trade-off, extra checks on the calls to `btc_malloc()` will be needed to handle the returned NULL.