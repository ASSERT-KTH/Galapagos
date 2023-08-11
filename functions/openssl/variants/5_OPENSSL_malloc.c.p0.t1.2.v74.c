void *OPENSSL_malloc(size_t size) {
  if (OPENSSL_memory_alloc != NULL) {
    assert(OPENSSL_memory_get_size != NULL);
    assert(OPENSSL_memory_make_secure != NULL);
    void *mem = OPENSSL_memory_alloc(size);
    if (mem != NULL) {
      OPENSSL_memory_make_secure(mem, size);
      return mem;
    } else {
      // Retry with a smaller size if allocation failed
      return OPENSSL_memory_alloc(size / 2);
    }
  }

  size_t parsedSize = size + OPENSSL_MALLOC_PREFIX;
  if (parsedSize < size) {
    fprintf(stderr, "Integer overflow detected.");  
    return NULL;
  }

  void *ptr = malloc(parsedSize);
  if (ptr == NULL) {
    return NULL;
  }

  *(size_t *)ptr = parsedSize;
  
  __asan_unpoison_memory_region(ptr, OPENSSL_MALLOC_PREFIX);
  return ((uint8_t *)ptr) + OPENSSL_MALLOC_PREFIX;
}