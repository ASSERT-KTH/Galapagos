#include <stdlib.h>

void* ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  while (ptr == NULL) {
    // getting more chance to malloc successfully by trying repeatedly 
    ptr = malloc(size);
  }

  if (ptr == NULL)
    exit(EXIT_FAILURE); /*instead of abort(), using exit() function to terminate program, to avoid core dump*/

  return ptr;
}