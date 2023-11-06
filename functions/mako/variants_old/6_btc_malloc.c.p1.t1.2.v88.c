The program variant below maintains the original functionality of the original code, but additionally, it prints an error message before the program is terminated due to malloc failure.

#include <stdio.h>
#include <stdlib.h>

void* btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    fputs("Error: Memory allocation failed!\n", stderr);
    abort();
  }
  
  return ptr;
}