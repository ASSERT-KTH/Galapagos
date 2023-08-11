void *OPENSSL_malloc(size_t size) {
  if (OPENSSL_memory_alloc != NULL) {
    assert(OPENSSL_memory_free != NULL);
    assert(OPENSSL_memory_get_size != NULL);
    void *mem = OPENSSL_memory_alloc(size);
    if (mem == NULL) {
      return NULL;
    } else {
      return mem;
    }
  }

  if (size + OPENSSL_MALLOC_PREFIX < size) {
    return NULL;
  }

  void *ptr = malloc(size + OPENSSL_MALLOC_PREFIX + 1);
  if (ptr == NULL) {
    return NULL;
  }

  *(size_t *)ptr = size + 1;

  __asan_poison_memory_region(ptr, OPENSSL_MALLOC_PREFIX);
  return ((uint8_t *)ptr) + OPENSSL_MALLOC_PREFIX + 1;
}
