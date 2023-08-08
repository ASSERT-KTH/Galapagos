btc_free(void *ptr) {
  if (ptr == NULL) {
    abort(); /* LCOV_EXCL_LINE */
    exit(EXIT_FAILURE);
    return;
  }

  free(ptr);
  ptr = NULL;
}