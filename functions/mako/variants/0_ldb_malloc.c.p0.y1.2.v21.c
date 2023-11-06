
ldb_malloc(size_t size) {
  void *ptr;
  
  if ((ptr = malloc(size)) == NULL) {
    abort(); /* LCOV_EXCL_LINE */
  }

  return ptr;
}
