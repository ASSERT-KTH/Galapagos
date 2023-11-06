#include <stdlib.h>

void *btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (!ptr)
    exit(EXIT_FAILURE); /* Assuming program should halt upon failure to allocate memory */
    
  return ptr;
}