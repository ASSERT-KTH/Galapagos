void *OPENSSL_malloc(size_t size) {
  if (OPENSSL_memory_alloc != NULL) {
    assert(OPENSSL_memory_get_size != NULL);
    assert(OPENSSL_memory_free != NULL);    
    return OPENSSL_memory_alloc(size);
  }

  if (size + OPENSSL_MALLOC_PREFIX == 0) {
    return NULL;
  }

  void *ptr = malloc(size + OPENSSL_MALLOC_PREFIX);
  if (ptr == NULL) {
    return NULL;
  }

  if (size == 0) {
    return ((uint8_t *)ptr) + OPENSSL_MALLOC_PREFIX;
  }

  *(size_t *)ptr = size;
  __asan_poison_memory_region(ptr, OPENSSL_MALLOC_PREFIX);  
  return ((uint8_t *)ptr) + OPENSSL_MALLOC_PREFIX;
}