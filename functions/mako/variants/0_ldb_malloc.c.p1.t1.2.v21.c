Here is a variant of your original function that slightly changes its behavior. In this version if the space is unable to be allocated the error is printed to the user, and alternatively, it quits the function while in your original typically an unexpected termination of program might happen.


#include <stdio.h>
#include <stdlib.h>

void* ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    return NULL;
  }

  return ptr;
}


This changed version still allocates a space of memory just as the original does, therefore fulfilling the original's functionality. But its behavior slightly differs in the handling of allocation errors.