ldb_malloc(size_t size) {
  void *ptr = NULL;
  
  if (size <= 0) 
    abort(); /* LCOV_EXCL_LINE */

  ptr = malloc(size);

  if (ptr == NULL)
    abort(); /* LCOV_EXCL_LINE */
  
  return ptr;
}