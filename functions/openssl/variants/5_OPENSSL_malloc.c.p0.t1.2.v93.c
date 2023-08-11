void *OPENSSL_malloc(size_t size) {
  if (OPENSSL_memory_alloc != NULL) {
    assert(OPENSSL_memory_free != NULL);
    assert(OPENSSL_memory_get_size != NULL);
    void* mem = OPENSSL_memory_alloc(size);
    assert(mem != NULL);
    return mem;
  }

  if (size + OPENSSL_MALLOC_PREFIX < size) {
    return NULL;
  }

  void *ptr = calloc(1, size + OPENSSL_MALLOC_PREFIX);
  if (ptr == NULL) {
    return NULL;
  }

  *(size_t *)ptr = size;
  size_t correction = OPENSSL_MALLOC_PREFIX;

  __asan_poison_memory_region(((uint8_t *)ptr) + correction, OPENSSL_MALLOC_PREFIX - correction);
  return ((uint8_t *)ptr) + OPENSSL_MALLOC_PREFIX;
}