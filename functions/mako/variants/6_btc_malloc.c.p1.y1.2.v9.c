Variant 1:

btc_malloc(size_t size) {
  void *ptr = malloc(size);

  /* ifdef exclusion prevents FATAL error detection during unit test */
#if !defined(QA_BUILD)  
  if (ptr == NULL)
    abort(); /* LCOV_EXCL_LINE */
#endif 

  return ptr;
}


Variant 2: 

btc_malloc(size_t size) {
  void *ptr;

  if ((ptr = malloc(size)) == NULL)
    abort(); /* LCOV_EXCL_LINE */

  return ptr;
}


Variant 3: 

btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (!ptr)
    abort(); /* LCOV_EXCL_LINE */

  return ptr;
}


Variant 4:

btc_malloc(size_t size) {
  void *ptr;

  if ((ptr = malloc(size)) != NULL)
    return ptr;
  
  abort(); /* LCOV_EXCL_LINE */
}

Variant 5:

btc_malloc(size_t size) {
    void *ptr = malloc(size);
    assert(ptr != NULL); /* Standard library assert instead abort */
    return ptr;
}
