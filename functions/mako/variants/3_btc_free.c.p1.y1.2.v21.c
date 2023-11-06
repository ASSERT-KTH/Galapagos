1. Changing if condition to reverse:


btc_free(void *ptr) {
  if (!ptr) {
    abort(); /* LCOV_EXCL_LINE */
    return;
  }

  free(ptr);
}


2. Using assert():


#include <assert.h>

btc_free(void *ptr) {
  assert(ptr!=NULL);
  free(ptr);
}


3. Specify NULL case by putting free() into else:


btc_free(void *ptr) {
  if (ptr == NULL) {
    abort(); /* LCOV_EXCL_LINE */
  }
  else {
    free(ptr);
  }
  return;
}


4. Comparing pointer and integer for NULL:


btc_free(void *ptr) {
  if (ptr == 0) {
    abort(); /* LCOV_EXCL_LINE */
    return;
  }

  free(ptr);
}


5. Removing return after abort():


btc_free(void *ptr) {
  if (ptr == NULL) {
    abort(); /* LCOV_EXCL_LINE */
  }

  free(ptr);
}
