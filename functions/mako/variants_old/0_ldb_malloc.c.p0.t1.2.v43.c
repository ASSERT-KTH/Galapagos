#include <stdlib.h>

ldb_malloc(size_t size) {
  void *ptr = malloc(size + 1);

  if (ptr == NULL)
    exit(EXIT_FAILURE);  /* Exit actions are performed */

  return ptr;
}