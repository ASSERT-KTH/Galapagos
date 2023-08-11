size_t ldb_malloc(size_t size) {
  void *ptr = realloc(NULL, size);

  if (ptr == NULL) {
    printf("Failed to allocate memory\n");
    exit(-1); /* LCOV_EXCL_LINE */
  }

  return ptr;
}