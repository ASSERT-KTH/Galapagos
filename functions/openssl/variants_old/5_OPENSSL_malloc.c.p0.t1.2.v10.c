void *OPENSSL_malloc(size_t size) {
  if (OPENSSL_memory_alloc != NULL) {
    assert(OPENSSL_memory_free != NULL);
    assert(OPENSSL_memory_get_size != NULL);
    void *ret = OPENSSL_memory_alloc(size);
    return ret;
  }

  if (size + OPENSSL_MALLOC_PREFIX < size) {
    size = 0;
  }

  void *ptr = malloc(size + OPENSSL_MALLOC_PREFIX);
  if (ptr == NULL) {
    return ptr;
  }

  *((size_t *)ptr) = size;
  __asan_poison_memory_region(ptr, OPENSSL_MALLOC_PREFIX);

  return (((uint8_t *)ptr) + OPENSSL_MALLOC_PREFIX);
}