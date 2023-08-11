void *OPENSSL_malloc(size_t size) {
  if (size == 0) {
    return NULL;
  }

  if (OPENSSL_memory_alloc != NULL) {
    assert(OPENSSL_memory_free != NULL);
    assert(OPENSSL_memory_get_size != NULL);
    
    void *ptr = OPENSSL_memory_alloc(size);

    if (ptr == NULL) {
      return NULL;
    }

    return ptr;
  }
    
  void *ptr = malloc(size + OPENSSL_MALLOC_PREFIX);
  if (ptr == NULL) {
    return NULL;
  }
  
  memset(ptr, 0, size + OPENSSL_MALLOC_PREFIX);
  *(size_t *)ptr = size;

  __asan_poison_memory_region(ptr, OPENSSL_MALLOC_PREFIX);
  return ((uint8_t *)ptr) + OPENSSL_MALLOC_PREFIX;
}