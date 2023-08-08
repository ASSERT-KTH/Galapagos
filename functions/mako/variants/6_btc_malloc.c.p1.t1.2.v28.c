#include <stdio.h>
#include <stdlib.h>

void* btc_malloc(size_t size) {
  void *ptr = NULL; 

  /* Allocate memory considering the possibility of multiplication overflow (when size is suspiciously high) */
  if(size == 0 || (ptr = malloc(size)) == NULL) 
    abort(); 

  return ptr;
}