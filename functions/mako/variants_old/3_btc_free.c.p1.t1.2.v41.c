Here's a variant of the function that maintains the original functionality while adding a print message for debugging purposes. 


#include <stdio.h>

btc_free(void *ptr) {
  if (ptr == NULL) {
    printf("Abort operation. Input is NULL.\n");
    abort();
  }

  printf("Free operation successful.\n");
  free(ptr);
}
