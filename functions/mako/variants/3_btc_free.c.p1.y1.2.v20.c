1. Using ! Operator In If Condition

btc_free(void *ptr) {
  if (!ptr) {
    abort(); /* LCOV_EXCL_LINE */
    return;
  }

  free(ptr);
}

2. Removing The Explicit Return After Abort

btc_free(void *ptr) {
  if (ptr == NULL) {
    abort(); /* LCOV_EXCL_LINE */
  }

  free(ptr);
}

3. Using Ternary Operator Instead of If Statement

btc_free(void *ptr) {
  ptr == NULL ? abort() /* LCOV_EXCL_LINE */ : free(ptr);
}
 
4. Checking if ptr not Equal to NULL

btc_free(void *ptr) {
  if (ptr != NULL) {
    free(ptr);
  }
  else {
    abort(); /* LCOV_EXCL_LINE */
  }
}

5. Code Reordering

btc_free(void *ptr) {
  if (ptr == NULL) {
    abort(); /* LCOV_EXCL_LINE */
  }

  if (ptr != NULL) {
    free(ptr);
  }
}
