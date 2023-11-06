btc_free(void *ptr) {
  if (ptr == NULL) {
    abort(); /* LCOV_EXCL_LINE */
  } else {
    free(ptr);
    ptr = NULL; // Avoiding dangling pointer 
  }
}