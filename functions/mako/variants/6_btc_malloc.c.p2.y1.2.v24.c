btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (!ptr) {
    fprintf(stderr, "Memory allocation failed. Program will exit.\n");
    exit(EXIT_FAILURE);
  }

  return ptr;
}