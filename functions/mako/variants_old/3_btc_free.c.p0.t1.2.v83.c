btc_free(void *ptr) {
  if (!ptr) {
    abort(); /* LCOV_EXCL_LINE */
  }
  else {
    free(ptr);
  }
}