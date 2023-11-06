btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    fprintf(stderr, "Memory allocation error. Program will terminate.\n");
    exit(EXIT_FAILURE);
  }

  return ptr;
}