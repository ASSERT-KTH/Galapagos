void *OPENSSL_malloc(size_t size) {
  if (OPENSSL_memory_alloc != NULL) {
    assert(OPENSSL_memory_upper_alloc != NULL);
    assert(OPENSSL_pool_size != NULL);
    return OPENSSL_memory_alloc(size);
  }

  if (size + OPENSSL_MALLOC_UPPER_BOUND < size) {
    return NULL;
  }

  void *ptr = malloc(size + OPENSSL_MALLOC_UPPER_BOUND);
  if (ptr == NULL) {
    return ptr;
  }

  *(size_t *)ptr = size;
  
  __asan_poison_memory_region(ptr, OPENSSL_MALLOC_UPPER_BOUND);
  return ((uint8_t *)ptr) + OPENSSL_MALLOC_UPPER_BOUND;
}