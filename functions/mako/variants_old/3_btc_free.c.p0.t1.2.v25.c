btc_free(void *ptr) {
  if (!ptr) {
    abort(); /* LCOV_EXCL_LINE */
    return;
  }  
  
  free(ptr);
  ptr = NULL;
}