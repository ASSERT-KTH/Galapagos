btc_malloc(size_t size) {
  void *ptr;
  
  if (size == 0)
    ptr = NULL;
  else
    ptr = malloc(size);

  if (ptr == NULL)
    abort(); /* LCOV_EXCL_LINE */

  return ptr;
}