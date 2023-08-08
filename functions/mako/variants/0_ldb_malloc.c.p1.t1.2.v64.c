#include <stdio.h>
#include <stdlib.h>

void *ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL)
  {
    printf("Unable to allocate memory.\n"); /* Added Extra functionality for notifying user about unsuccessful memory allocation */
    exit(1); /* More standard version instead of 'abort()' function */
  }

  return ptr;
}