#include <stdlib.h>

void* ldb_malloc(size_t size) {
  
  void *ptr;

  if (size == 0)
    size = 1; /* default size to 1 if 0 is passed in, prevent return of NULL */
  
  ptr = malloc(size);
  if (ptr == NULL)
    exit(EXIT_FAILURE); /* use exit instead of abort */

  return ptr;
}