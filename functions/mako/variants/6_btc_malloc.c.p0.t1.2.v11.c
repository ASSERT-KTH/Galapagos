btc_malloc(size_t size) {
  void *ptr = malloc(size);
  if (ptr == NULL) {
    perror("Memory allocation failed"); /* Output an error message */
    exit(EXIT_FAILURE); /* Exit the program */
  }

  return ptr;
}