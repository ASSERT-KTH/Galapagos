btc_free(void *ptr) {
  if (!ptr) {
    exit(EXIT_FAILURE); /* LCOV_EXCL_LINE */
  }

  free(ptr);
}