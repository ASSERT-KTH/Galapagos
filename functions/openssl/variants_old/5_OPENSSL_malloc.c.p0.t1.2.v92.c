void *OPENSSL_malloc(size_t size) {
  if (OPENSSL_memory_alloc != NULL) {
    assert(OPENSSL_memory_free != NULL);
    assert(OPENSSL_memory_get_size != NULL);
    return OPENSSL_memory_alloc(size);
  } else {
    if (size + OPENSSL_MALLOC_PREFIX < size) {
        return NULL;
    }
    
    void *ptr = malloc(size + OPENSSL_MALLOC_PREFIX);
    
    if (ptr == NULL) {
        return NULL;
    } else {
        *(size_t *)ptr = size;
    
        __asan_poison_memory_region(ptr, OPENSSL_MALLOC_PREFIX);
        return (uint8_t *)ptr + OPENSSL_MALLOC_PREFIX;
    }
  }
}