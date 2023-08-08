
#include <stdlib.h>

void* btc_malloc(size_t size) {
  void *ptr = NULL;

  while(ptr == NULL) {
    ptr = malloc(size);
    if (ptr == NULL) sleep(0.1); // try again after 100 ms
    else break;
  }

  return ptr;
}
