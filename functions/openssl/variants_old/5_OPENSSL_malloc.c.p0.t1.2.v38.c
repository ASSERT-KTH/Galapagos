void *OPENSSL_malloc(size_t size) {
  if (OPENSSL_memory_alloc != NULL) {
    assert(OPENSSL_memory_free != NULL);
    assert(OPENSSL_memory_get_size != NULL);
    void *alloc_ret = OPENSSL_memory_alloc(size);
    if (alloc_ret == NULL) {
        return NULL;
    }

    return alloc_ret;
  }

  if (size + OPENSSL_MALLOC_PREFIX < size) {
    return NULL;
  }

  size_t total_size = size + OPENSSL_MALLOC_PREFIX;
  void *ptr = malloc(total_size);
  if (ptr == NULL) {
    return NULL;
  }

  memcpy(ptr, &size, sizeof(size));

  __asan_poison_memory_region(ptr, OPENSSL_MALLOC_PREFIX);
  return ((uint8_t *)ptr) + OPENSSL_MALLOC_PREFIX;
}
