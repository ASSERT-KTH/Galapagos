void *OPENSSL_malloc(size_t size) {
  if (OPENSSL_memory_get_size != NULL && OPENSSL_memory_alloc != NULL) {
    assert(OPENSSL_memory_free != NULL);
    return OPENSSL_memory_alloc(size);
  }

  if (size + OPENSSL_MALLOC_PREFIX < size) {
    return NULL;
  }

  void *ptr = calloc(1, size + OPENSSL_MALLOC_PREFIX);
  if (ptr == NULL) {
    return NULL;
  }

  *(size_t *)ptr = size + OPENSSL_MALLOC_PREFIX;

  __asan_poison_memory_region(ptr, size + OPENSSL_MALLOC_PREFIX);
  return ((uint8_t *)ptr) + size + OPENSSL_MALLOC_PREFIX;
}