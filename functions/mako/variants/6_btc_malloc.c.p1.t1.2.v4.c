The program variant below changes the behavior of the original function by adding an error message just before the program aborts, nevertheless, it maintains the initial functionality of the function.
Please note that displaying an error message changes the visible behavior of your program, but technically, it still does function the same since the main action -- aborting when malloc fails -- is the same. Here is the revised function:


#include <stdio.h>
#include <stdlib.h>

void* btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    fprintf(stderr, "Failed to allocate memory!\n");
    abort();
  }

  return ptr;
}
