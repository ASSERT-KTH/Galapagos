btc_free(void *ptr) {
  if (!ptr) {
    exit(EXIT_FAILURE);
  } else {
    free(ptr);
    ptr = NULL;
  }
}