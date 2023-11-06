Here's a function variant which works as required and returns a more favorable exit code instead of aborting the whole program.


#include <stdlib.h>
#include <stdio.h>

void* ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    fprintf(stderr, "Memory allocation failed.\n");
    exit(EXIT_FAILURE);
  }

  return ptr;
}


This function still allocates memory and validates the success of the operation. However, instead of just calling `abort()`, it provides a short message and sets the exit-statue to indicate failure, and lets the rest of the program decide how to handle it.