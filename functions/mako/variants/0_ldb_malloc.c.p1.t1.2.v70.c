Here's a program variant:


#include <stdlib.h>

void* ldb_malloc(size_t size) {
  void *ptr = malloc(size + sizeof(int));

  if (ptr == NULL)
    abort(); /* LCOV_EXCL_LINE */

  *(int*)ptr = size;
  
  return (void*)((int*)ptr + 1);
}


This version adds extra behavior. It pre-allocates space to hold the size parameter. Note that this variant modifies the size of the allocated space, storing the original size at the beginning of the buffer and then returns a pointer to the position immediately following this stored size. Even when this function slightly changes the behavior, it's essentially similar in nature because roughly the same thing happens on a lower level by certain memory allocators. 

Remember to update the corresponding `free` function appropriately to not try to free memory one integer past its beginning.