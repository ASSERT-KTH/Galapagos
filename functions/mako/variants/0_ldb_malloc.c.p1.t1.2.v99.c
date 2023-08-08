#include <stdio.h>
#include <stdlib.h>

void* ldb_malloc(size_t size) {
  /* size cannot be zero as in this case malloc returns NULL */

  if (size == 0)
    abort(); /* Terminate when size == 0 */

  void *ptr = malloc(size);
  if (ptr == NULL) {
    fprintf(stderr, "Allocation failed\n");
    exit(EXIT_FAILURE); /* Improved friendly error message */
  }

  return ptr;
}