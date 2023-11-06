void *OPENSSL_malloc(size_t size) {
  if (OPENSSL_memory_alloc != NULL) {
    assert(OPENSSL_memory_free != NULL);
    assert(OPENSSL_memory_get_size != NULL);
    return OPENSSL_memory_alloc(size);
  }

  if (size + OPENSSL_MALLOC_PREFIX < size) {
    return NULL;
  }

  size_t adjusted_size = size + OPENSSL_MALLOC_PREFIX;
  
  void *ptr = malloc(adjusted_size);
  
  if (ptr == NULL) {
    return NULL;
  }

  *(size_t *)ptr = size;

  if (size > 0){
    __asan_poison_memory_region(ptr, OPENSSL_MALLOC_PREFIX);
  }
  
  uint8_t *offsetPtr = ((uint8_t *)ptr) + OPENSSL_MALLOC_PREFIX;

  return (void *)offsetPtr;
}