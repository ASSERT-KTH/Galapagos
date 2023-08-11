#include <stdio.h>
#include <stdlib.h>

void* btc_malloc(size_t size)
{
  void *ptr = malloc(size + sizeof(int));
  
  if (NULL == ptr)
  {
    printf("Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }
  
  /* Actual allocated memory begins-offset by sizof(int) */
  void *miscAllocationPtr = (char*)ptr + sizeof(int);   

  /* Saving block size to assist in freeing block's added size in 'free()' */
  *(int*)ptr = size;
  
  return miscAllocationPtr;     

}