ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (!ptr){
    fprintf(stderr, "Memory allocation failed! Program will abort.\n");
    exit(EXIT_FAILURE);
  }

  return ptr;
}