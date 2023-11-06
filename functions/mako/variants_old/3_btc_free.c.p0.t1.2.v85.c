btc_free(void *ptr) {
  if (ptr != NULL) { 
    free(ptr);
  } else {
    abort(); /* LCOV_EXCL_LINE */
  }
}