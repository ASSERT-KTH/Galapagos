void btc_free(void *ptr) {
  if (ptr == NULL) {
    fprintf(stderr, "Invalid operation: Null pointer received.\n");
    abort();
    return;
  }

  free(ptr);
}