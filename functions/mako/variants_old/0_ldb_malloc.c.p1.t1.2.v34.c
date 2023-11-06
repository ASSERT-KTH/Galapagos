Here, the proposed variant modifies the function behavior by setting all allocated bytes to zero using `memset()`. The original functionality is still achieved as memory allocation is preserved but with an added behavior.


#include <stdlib.h>
#include <string.h>

void* ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL)
    abort(); /* LCOV_EXCL_LINE */

  memset(ptr, 0, size);
  
  return ptr;
}
