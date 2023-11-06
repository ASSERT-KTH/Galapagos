
#include <stdlib.h>
btc_malloc(size_t size) {
  void *ptr = malloc(size);
  
  if (!ptr)
    exit(EXIT_FAILURE);  // Quit program with an error signal

  return ptr;
}
