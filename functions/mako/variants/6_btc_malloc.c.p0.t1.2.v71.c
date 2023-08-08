btc_malloc(size_t size) {
  if (size <= 0) 
    abort(); /* LCOV_EXCL_LINE */

  void *ptr = malloc(size);
  
  if (!ptr)
    abort(); /* LCOV_EXCL_LINE */

  memset(ptr, 0, size);
  
  return ptr; 
}