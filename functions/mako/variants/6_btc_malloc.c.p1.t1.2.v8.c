size_t btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    fputs("malloc failed: aborting program.", stderr); // notifying user about the error
    abort();
  }

  return (size_t)ptr;
}