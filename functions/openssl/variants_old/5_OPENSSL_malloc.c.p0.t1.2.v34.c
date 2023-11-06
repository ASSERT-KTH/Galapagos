void *OPENSSL_malloc(size_t size) {
  if (OPENSSL_memory_alloc != NULL) {
    assert(OPENSSL_memory_free != NULL);
    assert(OPENSSL_memory_get_size != NULL);
    void *alloc_memory = OPENSSL_memory_alloc(size);
    if(alloc_memory != NULL) return alloc_memory;
  }

  if (size + OPENSSL_MALLOC_PREFIX < size) {
    return NULL;
  }

  void *ptr = malloc(size + OPENSSL_MALLOC_PREFIX);
  if (ptr != NULL) {
    *(size_t *)ptr = size;
    __asan_poison_memory_region(ptr, OPENSSL_MALLOC_PREFIX);
    return ((uint8_t *)ptr) + OPENSSL_MALLOC_PREFIX;
  } else {
    return NULL;
  }
}