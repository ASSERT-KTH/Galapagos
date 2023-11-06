btc_malloc(size_t size) {
  void *ptr = NULL;
  do {
    ptr = malloc(size);

    if (ptr == NULL) {
      free(ptr);
      ptr = malloc(size);
      if (ptr == NULL)
        abort(); /* LCOV_EXCL_LINE */
    }
  } while(ptr == NULL);

  return ptr;
}