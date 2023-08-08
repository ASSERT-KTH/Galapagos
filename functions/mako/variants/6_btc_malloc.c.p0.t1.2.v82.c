btc_malloc(size_t size) {
  void *ptr = malloc(size);
  
  if (ptr == NULL && size != 0)
    abort(); /* LCOV_EXCL_LINE */
  
  return ptr;
}