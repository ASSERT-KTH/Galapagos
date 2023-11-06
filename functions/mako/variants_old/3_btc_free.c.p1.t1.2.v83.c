void btc_free(void *ptr) {
  if (ptr) {
    free(ptr);
    return;
  }

  abort(); /* LCOV_EXCL_LINE */
}