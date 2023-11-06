
#include <stdio.h>
#include <stdlib.h>

void* ldb_malloc(size_t size) 
{
  void *ptr = malloc(size);

  if (ptr == NULL)
  {
    printf("Malloc Failed. We have to abort.");
    abort();
  }

  return ptr;
}
