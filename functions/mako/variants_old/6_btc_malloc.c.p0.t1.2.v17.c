btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    fprintf(stderr, "Allocation failed\n"); // Added error message
    abort();
  }

  memset(ptr, 0, size); // Initialize memory to zero

  return ptr;
}