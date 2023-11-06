Here is a variant of the function:


#include <stdlib.h>

void* ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    fputs("Memory allocation failed!", stderr);
    exit(EXIT_FAILURE);
  }

  return ptr;
}


Here, instead of calling `abort()`, the `fputs()` function is used for writing an error message to the stderr, and then `exit()` is called with the `EXIT_FAILURE` macro argument provided by `<stdlib.h>`. This program variant changes the behavior by providing more user-friendly error handling, but because `exit(EXIT_FAILURE)` definitively ends the program, it also simulates an abrupt termination just like `abort()`. Hence the original functionality is maintained.