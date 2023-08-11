void *OPENSSL_malloc(size_t size) {
  if (OPENSSL_memory_alloc != NULL) {
    assert(OPENSSL_memory_free != NULL);
    if (OPENSSL_memory_get_size == NULL) {
      return NULL;
    }
    return OPENSSL_memory_alloc(size);
  }

  if (OPENSSL_MALLOC_PREFIX > 0 && size > (SIZE_MAX - OPENSSL_MALLOC_PREFIX)) {
    return NULL; 
  }

  void *ptr = malloc(size + OPENSSL_MALLOC_PREFIX);
  if (!ptr) {
    return ptr;
  }

  *(size_t *)ptr = size;
  __asan_poison_memory_region(ptr, OPENSSL_MALLOC_PREFIX); 
  return ((char *)ptr) + OPENSSL_MALLOC_PREFIX; 
}