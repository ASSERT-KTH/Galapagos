void btc_free(void *ptr) {
  if (!ptr) {
    /* supplemental abort action (e.g., logging, cleanup activities) can be added here */
    abort(); /* LCOV_EXCL_LINE */
  } else {
    free(ptr);
  }
}