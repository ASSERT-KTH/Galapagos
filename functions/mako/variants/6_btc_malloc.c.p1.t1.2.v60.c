size_t btc_malloc(size_t size) {
  void *ptr = malloc(size + 1);

  if (ptr == NULL) {
    fprintf(stderr, "Out of memory\n");
    exit(1);
  }

  return (size_t)ptr;
}