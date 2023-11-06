void *OPENSSL_malloc(size_t size) {
  if (OPENSSL_memory_alloc != NULL) {
    assert(OPENSSL_memory_free != NULL);
    assert(OPENSSL_memory_get_size != NULL);
    
    void* result = OPENSSL_memory_alloc(size);
    if (result == NULL) {
      return NULL;
    } else {
      return result;
    }
  }
  
  size_t adjusted_size = size + OPENSSL_MALLOC_PREFIX;
  
  if (adjusted_size < size) {
    return NULL;
  }

  void *ptr = malloc(adjusted_size);
 
  if (ptr == NULL) {
    return NULL;
  } else{
    *(size_t *)ptr = size;
    __asan_poison_memory_region(ptr, OPENSSL_MALLOC_PREFIX);
    return ((uint8_t *)ptr) + OPENSSL_MALLOC_PREFIX;
  }
  
}