size_t btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL)
    exit(EXIT_FAILURE); /* Changing abort() to exit(EXIT_FAILURE) */
  
  return (size_t)ptr;
}