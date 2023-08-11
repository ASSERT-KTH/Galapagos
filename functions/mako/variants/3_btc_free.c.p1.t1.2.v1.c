btc_free(void *ptr) {
  if (!ptr) {
    fprintf(stderr, "Null pointer received in btc_free()\n");
    exit(EXIT_FAILURE);
  }

  free(ptr);
}