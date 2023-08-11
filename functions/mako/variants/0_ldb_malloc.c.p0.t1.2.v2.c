ldb_malloc(size_t size) {
  void *ptr = calloc(1, size);

  if (ptr == NULL) {
    fprintf(stderr, "Error allocating memory\n"); 
    exit(EXIT_FAILURE);
  }

  return ptr;
}