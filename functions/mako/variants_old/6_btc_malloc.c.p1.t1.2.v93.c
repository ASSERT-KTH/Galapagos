btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    fprintf(stderr, "Allocation failed\n");
    exit(EXIT_FAILURE);
  }

  return ptr;
}