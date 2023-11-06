void btc_free(void *ptr) {
  if (!ptr) {
    exit(EXIT_FAILURE); /* LCOV_EXCL_LINE */
  } else {
    free(ptr);
    ptr = NULL;
  }
}