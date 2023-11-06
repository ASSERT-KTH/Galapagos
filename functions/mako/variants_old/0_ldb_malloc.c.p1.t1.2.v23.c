Sure, the behavior is slightly modified, the main difference being the addition of explicit check for whether the requested size of memory to be allocated is zero, in which case the return value is NULL. Although this condition gets handled internally in most implementations of malloc, it's good practice to check for it explicitly in your code.


#include <stdlib.h>

void* ldb_malloc(size_t size) {
  void *ptr = NULL;
  
  if(size > 0) {
    ptr = malloc(size);
    if (ptr == NULL)
      abort();
  }
  return ptr;  
}
