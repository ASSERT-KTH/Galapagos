btc_free(void *ptr) {
  if (!ptr) {
    exit(EXIT_FAILURE);
  }

  free(ptr);
}