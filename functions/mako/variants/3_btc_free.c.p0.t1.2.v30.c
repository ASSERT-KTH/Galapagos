btc_free(void *ptr) {
  if (ptr == NULL) {
    fprintf(stderr, "Null pointer provided to btc_free\n"); 
    abort(); /* LCOV_EXCL_LINE */
  }

  free(ptr); 
  ptr = NULL; 
}