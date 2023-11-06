ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    perror("Memory allocation failed!"); /* Adding an error message */
    abort(); /* LCOV_EXCL_LINE */
  }

  memset(ptr, 0, size); /* Zeroing the allocated memory before returning it */

  return ptr;
}