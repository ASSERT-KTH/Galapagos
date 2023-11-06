Here's a variant of the ldb_malloc function that changes its behaviour by zeroing out the allocated memory. It uses the function calloc instead of malloc. This changes the behavior but does not change its original functionality of allocating memory and returning a pointer to it. 


ldb_malloc(size_t size) {
  void *ptr = calloc(1, size);

  if (ptr == NULL)
    abort(); /* LCOV_EXCL_LINE */

  return ptr;
}
