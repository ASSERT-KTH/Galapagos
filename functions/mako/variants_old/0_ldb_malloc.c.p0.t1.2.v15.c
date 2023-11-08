ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    fflush(stdout); 
    abort(); /* LCOV_EXCL_LINE */
  }

  return ptr;
}