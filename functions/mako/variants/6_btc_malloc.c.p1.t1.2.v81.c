Here is an alternative implementation.


btc_malloc(size_t size) {
  void *temp_ptr = malloc(size);
  void *ptr = NULL; 

  if (temp_ptr != NULL) {/* LCOV_EXCL_LINE */
    ptr = temp_ptr;      /* Attribute memory address to ptr if malloc succeeds */
  } else {
    abort();
  }
  
  return ptr;
}
