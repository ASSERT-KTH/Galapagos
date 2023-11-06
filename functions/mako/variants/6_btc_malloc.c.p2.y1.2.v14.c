#include <stdlib.h>

void* btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL)
    exit(EXIT_FAILURE); /* Instead of abort() use exit(EXIT_FAILURE) */

  return ptr;
}