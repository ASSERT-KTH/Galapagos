The variant function below performs the same functionality as the original function but throws a standard error message to stderr using perror() function instead of calling abort() function when malloc() function fails.


#include <stdio.h>
#include <stdlib.h>

void* ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    perror("Failed to allocate memory"); /* Throws a standard error message instead of aborting */
    exit(EXIT_FAILURE); /* Exits the whole program */
  }

  return ptr;
}

The standard library function perror() writes a description of the last error encountered during a call to a system or library function.

When a call to malloc() fails, a subsequent query to errno should indicate the specific cause of the error. If an error has occurred, a pointer to a string describing the error will be returned.