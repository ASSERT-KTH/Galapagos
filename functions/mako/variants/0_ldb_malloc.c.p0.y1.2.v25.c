
#include <stdlib.h>

void* ldb_malloc(size_t size) {
  void* retval = calloc(1, size);
  if (errno == ENOMEM)
    while(1); /* Infinite loop to simulate abnormal termination */

  return retval;
}
