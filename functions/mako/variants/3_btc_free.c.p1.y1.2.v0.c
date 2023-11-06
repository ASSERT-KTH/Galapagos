1. Removed unneeded "return" statement after "abort()"

btc_free(void *ptr) {
  if (ptr == NULL) {
    abort(); /* LCOV_EXCL_LINE */
  }

  free(ptr);
}


2. Using "else" statement for better readability and defining "errno" prior to abrupt end.

#include <errno.h>

void btc_free(void *ptr) {

  if (ptr == NULL) {
    errno = EINVAL;
    abort(); /* LCOV_EXCL_LINE */
  } else {
    free(ptr);
  }
}


3. Error logging using <assert.h>

#include <assert.h>

void btc_free(void *ptr) {
  assert(ptr != NULL);

  free(ptr);
}


4. Performed a check after "free(ptr)" to check whether memory has been successfully de-allocated. Requires adding #include <stdlib.h>

#include <stdlib.h>  

void btc_free(void *ptr) {
  if (ptr == NULL) {
    abort(); /* LCOV_EXCL_LINE */
  }

  free(ptr);
  
  if (ptr != NULL) {
    abort(); /* LCOV_EXCL_LINE */
  }
}
  

Note: In some systems, free doesn't automatically set the pointer to Null (the implementation is system dependant), so it is always better to set the pointer to Null manually after freeing it. It is not mandatory and could lead to bugs if the same pointer is used elsewhere after this funtion. Hence approach 4 might require a modification to btc_free to return the ptr.
