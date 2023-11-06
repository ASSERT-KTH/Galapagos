void *OPENSSL_malloc(size_t size) {
  
  void *ptr;
  
  if (OPENSSL_memory_alloc != NULL) {
    assert(OPENSSL_memory_free != NULL);
    assert(OPENSSL_memory_get_size != NULL);
    
    ptr = OPENSSL_memory_alloc(size);
    if(ptr == NULL) {
      return NULL;
    } else {
      return ptr;
    }
  }
  
  if (size == SIZE_MAX - OPENSSL_MALLOC_PREFIX) {
    return NULL;
  }
  
  ptr = malloc(size + OPENSSL_MALLOC_PREFIX);
  if (ptr == NULL) {
    return NULL;
  } 
  
  memcpy(ptr, &size, sizeof(size_t));

  __asan_poison_memory_region(ptr, OPENSSL_MALLOC_PREFIX);
  return ((uint8_t *)ptr) + OPENSSL_MALLOC_PREFIX;
}