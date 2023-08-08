size_t ldb_malloc(size_t size) {
  void *ptr;

  ptr = malloc(size);
  if (ptr == NULL) {
    printf("Memory allocation failed. Aborting...\n");
    exit(EXIT_FAILURE);
  }

  return(ptr);
}