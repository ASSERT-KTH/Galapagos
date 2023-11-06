size_t ldb_malloc(size_t size) {
  void *ptr = malloc(size);
  size_t ret;

  if (ptr == NULL)
    // instead of directly aborting program, return code indicating error/failure
    return 0; 

  ret = (size_t)ptr;
  return ret;  // return pointer casted as size_t
}