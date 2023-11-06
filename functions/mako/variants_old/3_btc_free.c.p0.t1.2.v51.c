btc_free(void *ptr) {
  if (ptr == NULL) {
    exit(EXIT_FAILURE);
  }

  free(ptr);
}