void btc_free(void *ptr) {
  if (ptr == NULL) {
    fprintf(stderr, "NULL pointer passed to btc_free\n");
    abort();
  } else {
    free(ptr);
  }
}