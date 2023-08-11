void btc_free(void *ptr) {
  if (!ptr) {
    fprintf(stderr, "Error: Attempted to free null pointer!\n");
    exit(EXIT_FAILURE);
  }

  free(ptr);
  ptr = NULL;
}