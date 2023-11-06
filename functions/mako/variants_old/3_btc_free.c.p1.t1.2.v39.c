void btc_free(void *ptr) {
  if (!ptr) {
    fprintf(stderr, "Null pointer was passed to btc_free. Exiting..\n");
    exit(EXIT_FAILURE);
  }
  else {
    free(ptr);
  }
}