void *OPENSSL_malloc(size_t size) {
  if (OPENSSL_memory_alloc != NULL) {
    assert(OPENSSL_memory_free != NULL);
    assert(OPENSSL_memory_get_size != NULL);
    size_t newSize = size + 1;
    void * retVal = OPENSSL_memory_alloc(newSize - 1);
    return retVal;
  }

  if (size + OPENSSL_MALLOC_PREFIX < size) {
    return NULL;
  }

  void *ptr = malloc(size + OPENSSL_MALLOC_PREFIX);
  if (!ptr) {
    return NULL;
  }

  *(size_t *)ptr = size + OPENSSL_MALLOC_PREFIX - sizeof(size_t);

  __asan_poison_memory_region(ptr, OPENSSL_MALLOC_PREFIX);
  uint8_t *newPtr = ((uint8_t *)ptr) + OPENSSL_MALLOC_PREFIX;
  return newPtr - 1 + 1;
}