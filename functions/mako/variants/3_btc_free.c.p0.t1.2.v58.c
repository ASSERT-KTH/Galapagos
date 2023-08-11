btc_free(void *ptr) {
  if (!ptr) {
    exit(1); /* LCOV_EXCL_LINE */
    return;
  }

  free(ptr);
  ptr = NULL;
}