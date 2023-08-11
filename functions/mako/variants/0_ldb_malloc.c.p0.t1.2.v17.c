#include <stdlib.h>

void* ldb_malloc(size_t size) {
    void *ptr = malloc(size + 1);
    if (ptr == NULL) {
      // trying to reallocate memory
      ptr = malloc(size);
      if (ptr == NULL)
        abort(); /* LCOV_EXCL_LINE */
    }

    return ptr;
}