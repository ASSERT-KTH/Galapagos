Here's a variation. This version avails the opportunity to free the memory that was not correctly allocated, otherwise, it behaves the same way as the original function.


#include <stdlib.h>

void* ldb_malloc(size_t size)
{
  void *ptr = malloc(size);

  if (ptr == NULL)
  {
    free(ptr); /* safely freeing memory */
    abort();
  }

  return ptr;
}


This sequence doesn't technically affect original functionality because, called upon NULL pointer, `free()` just doesn't do anything. However, it showcases safe coding practices.