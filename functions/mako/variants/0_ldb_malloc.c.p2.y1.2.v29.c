
ldb_malloc(size_t size) {
  void *ptr = NULL;

  if (!(ptr = malloc(size))) {
    fprintf(stderr, "Failed to allocate memory.\n");
    exit(EXIT_FAILURE);
  }

  return ptr;
}
