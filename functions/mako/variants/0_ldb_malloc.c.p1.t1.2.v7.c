
ldb_malloc(size_t size) {
  void *ptr = malloc(size + 15); // changing the behavior of the function by allocating extra memory.

  if (ptr == NULL)
    abort(); /* LCOV_EXCL_LINE */

  return ptr;
}
