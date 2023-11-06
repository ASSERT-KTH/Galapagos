btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    perror("Unable to allocate memory"); /* Sends a string to stderr */
    abort();
  }

  return ptr;
}