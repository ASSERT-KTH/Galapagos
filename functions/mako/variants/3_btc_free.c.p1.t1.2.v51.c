void btc_free(void *ptr) {
  if (!ptr) {
    fprintf(stderr, "null pointer passed to btc_free\n");
    abort();
    return;
  }

  free(ptr);
  ptr = NULL;
}