Here is a variant of the function.


#include <stdlib.h>

void* ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    fprintf(stderr, "Memory allocation failed. Exiting program.\n");
    exit(EXIT_FAILURE);
  }

  return ptr;
}


This variant changes the behavior as follows: instead of calling `abort()`, it displays an error message and cleanly terminates the program with `exit()`, signaling an error condition via `EXIT_FAILURE`.