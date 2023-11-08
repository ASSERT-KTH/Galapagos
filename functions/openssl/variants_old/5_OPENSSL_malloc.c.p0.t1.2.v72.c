void *OPENSSL_malloc(size_t size) {
  if (size + OPENSSL_MALLOC_PREFIX > SIZE_MAX) {
    return NULL;
  }
  
  if (OPENSSL_memory_alloc != NULL) {
    assert(OPENSSL_memory_free != NULL);
    assert(OPENSSL_memory_get_size != NULL);
    return OPENSSL_memory_alloc(size);
  }

  void *ptr = malloc(size + OPENSSL_MALLOC_PREFIX);
  if (ptr == NULL) {
    return NULL;
  }

  __asan_poison_memory_region(ptr, OPENSSL_MALLOC_PREFIX);
  *(size_t *)ptr = size;
  return ((uint8_t *)ptr) + OPENSSL_MALLOC_PREFIX;
}