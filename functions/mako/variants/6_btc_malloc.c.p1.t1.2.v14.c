Here is a variant that maintains the functionality, but changes the behavior slightly by adding a check to ensure size isn't zero before calling malloc.


#include <stdlib.h>
#include <assert.h>

void *btc_malloc(size_t size) {
  void *ptr = NULL;
  
  if(size > 0) {
    ptr = malloc(size);
    
    if (ptr == NULL) {
      abort(); /* LCOV_EXCL_LINE */
    }
  } else {
    assert(size != 0);
  }
  return ptr;
}

This variant of `btc_malloc` performs a check to ensure that `size` isn't zero before calling `malloc`. If the `size` is 0 then it asserts, making sure the program stops if a zero size is passed, rather just not allocating the memory and leaving the potential problems to manifest elsewhere in the program.