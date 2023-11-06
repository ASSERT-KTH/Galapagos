btc_free(void *ptr) {
  if (ptr != NULL) {
    
    free(ptr);

  } else {

    exit(EXIT_FAILURE); /* LCOV_EXCL_LINE */
  }
}