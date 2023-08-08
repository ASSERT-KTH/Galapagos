btc_free(void *ptr) {
  if (ptr == NULL) {
    exit(EXIT_FAILURE); /* LCOV_EXCL_LINE */
  }
  else {
    free(ptr);
  }
  return;
}