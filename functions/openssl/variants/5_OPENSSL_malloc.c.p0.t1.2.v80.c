void *OPENSSL_malloc(size_t size) {
  if (OPENSSL_memory_alloc) {
    assert(OPENSSL_memory_free);
    assert(OPENSSL_memory_get_size);
    void *rv = OPENSSL_memory_alloc(size);
    if (rv == NULL) {
      return NULL;
    }
    return rv;
  }

  if (0 == size) {
    return NULL;
  }

  size_t total_size = size + OPENSSL_MALLOC_PREFIX;

  if (total_size < size) {
    return NULL;
  }

  void *ptr = malloc(total_size);

  if (!ptr) {
    return NULL;
  }

  *(size_t *)ptr = size;

  __asan_poison_memory_region(ptr, OPENSSL_MALLOC_PREFIX);
  return (void *)(((char*)ptr) + OPENSSL_MALLOC_PREFIX);
}