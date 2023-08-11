void btc_free(void *ptr) {
  if (ptr) {
    free(ptr);
  } else {
    abort(); /* LCOV_EXCL_LINE */
  }
}