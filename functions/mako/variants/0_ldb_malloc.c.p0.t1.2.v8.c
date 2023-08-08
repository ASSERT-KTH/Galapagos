void* ldb_malloc(size_t size) {
  void *ptr = calloc(1, size);

  if (ptr == NULL) {
    fprintf(stderr, "Allocation failed!\n");
    exit(1);
  }

  return ptr;
}