ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    perror("LDB malloc failed");
    exit(EXIT_FAILURE); 
  }

  return ptr;
}