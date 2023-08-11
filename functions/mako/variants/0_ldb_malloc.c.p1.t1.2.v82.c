Here's a version with the original functionality, but with added functionality for logging error message when malloc fails before triggering abort.


#include <stdio.h>
#include <stdlib.h>

void* ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    fputs("ldb_malloc failed: Out of memory.\n", stderr);
    abort();
  }

  return ptr;
}


This version still does everything the original does (that is, call malloc, return the malloced pointer if it's not NULL, abort the program if it is), but will also prints out an error message to the standard error if malloc fails.