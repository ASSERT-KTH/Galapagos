1.

ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (!ptr)
    abort(); /* LCOV_EXCL_LINE */

  return ptr;
}

2.

ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    printf("Malloc failed");
    abort(); /* LCOV_EXCL_LINE */
  }

  return ptr;
}

3.

ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == 0)
    abort(); /* LCOV_EXCL_LINE */

  return ptr;
}

4.

ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (!ptr) {
    fprintf(stderr, "Malloc failed");
    abort(); /* LCOV_EXCL_LINE */
  }

  return ptr;
}

5.

ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == 0) {
    fprintf(stderr, "Malloc failed");
    abort(); /* LCOV_EXCL_LINE */
  }

  return ptr;
}
