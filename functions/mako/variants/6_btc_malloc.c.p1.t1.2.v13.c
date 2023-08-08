Here is a variant of the function that adds error checking:


#include <errno.h>

void* btc_malloc(size_t size) {
  void *ptr = malloc(size);
  
  if (ptr == NULL) {
      if (errno == ENOMEM) {
          /* handle error */
          fprintf(stderr, "Failed to allocate %ld bytes\n", size);
          exit(EXIT_FAILURE);
      }
      else {
          /* This case is not expected: handle error */
          avort(); /* LCOV_EXCL_LINE */
      }
  }

  return ptr;
}
