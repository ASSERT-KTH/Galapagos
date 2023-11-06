Variant 1:

btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (!ptr)
    exit(EXIT_FAILURE); /* LCOV_EXCL_LINE */

  return ptr;
}


Variant 2:

btc_malloc(size_t size) {
  void *ptr;

  ptr = malloc(size);
  assert(ptr != NULL);/* LCOV_EXCL_LINE */

  return ptr;
}


Variant 3:

btc_malloc(size_t size) {
  void *ptr;

  if (!(ptr = malloc(size))) 
    abort();/* LCOV_EXCL_LINE */

  return ptr;
}


Variant 4:

btc_malloc(size_t size) {
  void *ptr;

  ptr = malloc(size);
  if (ptr == NULL) 
  {
    perror("Memory allocation failure"); 
    abort(); /* LCOV_EXCL_LINE */
  }

  return ptr;
}
