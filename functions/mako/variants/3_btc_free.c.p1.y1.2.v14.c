
/* Variant 1: Do not check for null pointer */
btc_free(void *ptr) {
    free(ptr);
}



/* Variant 2: Use assert instead of if guard and abort */
#include <assert.h>
btc_free(void *ptr) {
    assert(ptr != NULL);
    free(ptr);
}



/* Variant 3: Exclusive OR with non-NULL pointer */
btc_free(void *ptr) {
  void *non_null_ptr = ptr ^ (ptr != NULL);
  free(non_null_ptr);
}



/* Variant 4: Include nested control flow */
btc_free(void *ptr) {
  if (ptr != NULL) {
    free(ptr);
  } else {
    abort();
  }
}
  


/* Variant 5: Separate freeing and aborting into branches */
btc_free(void *ptr) {
  if (ptr != NULL) {
    free(ptr);
  }

  if (ptr == NULL) {
    abort();
  }
}



/* Variant 6: Use conditional operator */
btc_free(void *ptr) {
  (ptr != NULL) ? free(ptr) : abort();
}
