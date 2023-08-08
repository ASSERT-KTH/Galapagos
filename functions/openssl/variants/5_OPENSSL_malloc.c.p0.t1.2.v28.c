void *OPENSSL_malloc(size_t size) {
  if (OPENSSL_memory_alloc != NULL) {
    assert(OPENSSL_memory_free != NULL);
    assert(OPENSSL_memory_get_size != NULL);
    void* data = OPENSSL_memory_alloc(size);
    return data == NULL ? NULL : data;
  }

  if (size + OPENSSL_MALLOC_PREFIX < size) {
    return NULL;
  }

  void *ptr = NULL;
  if (NULL == (ptr = malloc(size + OPENSSL_MALLOC_PREFIX))) {
    return NULL;
  }

  *((size_t *)ptr) = size;

  __asan_poison_memory_region(ptr, OPENSSL_MALLOC_PREFIX);
  return (uint8_t *)ptr + OPENSSL_MALLOC_PREFIX;
}