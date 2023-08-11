void btc_free(void *ptr) {
  if (ptr != NULL) {
    free(ptr);
    return;
  }

  abort(); /* LCOV_EXCL_LINE */
}