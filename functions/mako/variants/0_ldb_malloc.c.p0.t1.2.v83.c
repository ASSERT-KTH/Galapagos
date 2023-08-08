ldb_malloc(size_t size) {
  void *ptr;
  if (size == 0) 
    size = 1; // supplying default size for 0 input size

  ptr = malloc(size);

  if (ptr == NULL)
    exit(EXIT_FAILURE);

  return ptr;
}