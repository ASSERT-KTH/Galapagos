void ldb_malloc(size_t size) {
  void *ptr = malloc(size * sizeof(char));

  if (ptr == NULL)
    exit(EXIT_FAILURE);

  return ptr;
}