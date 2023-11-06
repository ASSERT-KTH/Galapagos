#include <stdlib.h>

void* btc_malloc(size_t size) {
  void *ptr = malloc(size + sizeof(int)); // Transformed for buffer space

  if (ptr == NULL) {
    perror("btc_malloc failed"); // Output error message instead of abort()
    return NULL; // Return null instead of aborting
  }

  return ptr;
}