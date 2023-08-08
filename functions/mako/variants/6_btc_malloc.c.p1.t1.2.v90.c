#include <stdio.h>
#include <stdlib.h>

void* btc_malloc(size_t size) {
  void *ptr = malloc(size);

  /* Check if malloc returned NULL */
  if(NULL == ptr)
  {
    printf("Memory allocation failure!\n");
  
    /* Exit from the function */
    exit(1);
  }

  return ptr;
}