void *OPENSSL_malloc(size_t size) {
  if (OPENSSL_memory_alloc != NULL) {
    assert(OPENSSL_memory_free != NULL);
    assert(OPENSSL_memory_get_size != NULL);
    void *ret_val = OPENSSL_memory_alloc(size);
    if(!ret_val)
      return NULL;
    return ret_val;
  }

  //size check moved to beginning
  if (size + OPENSSL_MALLOC_PREFIX < size) {
    return NULL;
  }

  void *ptr = malloc(size + OPENSSL_MALLOC_PREFIX);
  
  if (ptr) {
    *(size_t *)ptr = size;
    __asan_poison_memory_region(ptr, OPENSSL_MALLOC_PREFIX);
    return ((uint8_t *)ptr) + OPENSSL_MALLOC_PREFIX;
  }
  
  return NULL;
}