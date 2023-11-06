btc_malloc(size_t size) {
  void *ptr = malloc(size);

  /* Added check if memory was successfully allocated and set error number*/
  if (ptr == NULL) {
    errno = ENOMEM;
    abort();
  }

  return ptr;
}