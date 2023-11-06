btc_free(void *ptr) {
  /* Adding check for errno to see if free itself is successfull, and call abort if needed */
  errno = 0;

  free(ptr);

  if (ptr != NULL && errno != 0) {
    abort(); /* LCOV_EXCL_LINE */
    return;
  }
}