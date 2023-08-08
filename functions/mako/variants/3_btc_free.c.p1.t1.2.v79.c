btc_free(void *ptr) {
  if (ptr == NULL) {
    fprintf(stderr, "NULL pointer passed to btc_free. Process will be terminated.\n");
    abort(); /* LCOV_EXCL_LINE */
  }

  free(ptr);
  ptr = NULL;
}