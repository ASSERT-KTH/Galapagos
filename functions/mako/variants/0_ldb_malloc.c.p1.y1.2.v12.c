1.

ldb_malloc(size_t size) {
  void *ptr;
  if ((ptr = malloc(size)) == NULL)
    abort(); /* LCOV_EXCL_LINE */
  return ptr;
}


2.

ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr) {
    return ptr;
  } else {
    abort(); /* LCOV_EXCL_LINE */
  }
}


3.

ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (!ptr)
    abort(); /* LCOV_EXCL_LINE */

  return ptr;
}
 

4.

ldb_malloc(size_t size) {
  void *ptr;
  ptr = malloc(size);

  if (NULL == ptr)
    abort(); /* LCOV_EXCL_LINE */

  return ptr;
}
 

5.

ldb_malloc(size_t size) {
  void *ptr;
  ptr = malloc(size);

  if (0 == ptr)
    abort(); /* LCOV_EXCL_LINE */

  return ptr;
}
