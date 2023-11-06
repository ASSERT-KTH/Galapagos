1. Removing explicit return after abort() since it's unnecessary.

void btc_free(void *ptr) {
  if (ptr == NULL) {
    abort(); /* LCOV_EXCL_LINE */
  }
  free(ptr);
}


2. Reversing the terminator condition with early return to lower indentation levels.

void btc_free(void *ptr) {
  if (ptr != NULL) {
    free(ptr);
    return;
  }
  abort(); /* LCOV_EXCL_LINE */
}


3. Using assert() instead of if and abort().

#include <assert.h>

void btc_free(void *ptr) {
  assert(ptr != NULL);
  free(ptr);
}


4. Shor Short circuit OR operator to replace If condition .

void btc_free(void *ptr) {
  ptr == NULL || (free(ptr), 0) || abort(); /* LCOV_EXCL_LINE */
}


5. "Meat and potatoes" way by removing comments and whitespaces. 

void btc_free(void* ptr) {
 if(!ptr) { abort(); } free(ptr);
}
