ldb_malloc(size_t size) {
  if (size == 0)
    return NULL;
    
  void *ptr = malloc(size);

  if (!ptr) {
    perror("Memory allocation error");
    exit(EXIT_FAILURE);
  }

  return ptr;
}