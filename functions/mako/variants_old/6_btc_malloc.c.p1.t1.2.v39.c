size_t btc_malloc(size_t size) {
  void *ptr = malloc(size);

  /* If allocation failed, instead of calling abort, exit gracefully */
  if (ptr == NULL)
    exit(EXIT_FAILURE);

  return (size_t)ptr;
}