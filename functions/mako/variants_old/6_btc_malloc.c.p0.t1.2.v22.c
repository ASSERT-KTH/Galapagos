#include <stdlib.h>

void* btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if(ptr == NULL){
    printf("Null pointer exception. Allocating memory failed.\n");
    abort();
  }

  memset(ptr, 0, size);

  return ptr;
}