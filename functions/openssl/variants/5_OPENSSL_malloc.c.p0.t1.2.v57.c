void *OPENSSL_malloc(size_t size) {
  if (OPENSSL_memory_alloc != NULL) {
    assert(OPENSSL_memory_free != NULL);
    assert(OPENSSL_memory_get_size != NULL);
    void *memPointer = OPENSSL_memory_alloc(size);
    return memPointer;
  }

  size_t newSize = size + OPENSSL_MALLOC_PREFIX;
  if (newSize < size) {
    return NULL;
  }

  void *ptr = malloc(newSize);
  if (ptr == 0) {
    return NULL;
  }

  size_t *sizedPtr = (size_t*)ptr;
  *sizedPtr = size;

  __asan_poison_memory_region(ptr, OPENSSL_MALLOC_PREFIX);
  return ((uint8_t *)ptr) + OPENSSL_MALLOC_PREFIX;
}