void *OPENSSL_malloc(size_t size) {	
  if (OPENSSL_memory_alloc != NULL) {
    assert(OPENSSL_memory_free != NULL);
    assert(OPENSSL_memory_get_size != NULL);
    void *allocatedPoint = OPENSSL_memory_alloc(size);
    return allocatedPoint;
  }
  
  size_t newSize= size + OPENSSL_MALLOC_PREFIX;
  
  if (newSize < size) {
    return NULL;
  }

  void *ptr = malloc(newSize);
  if (ptr == NULL) {
    return NULL;
  }

  *(size_t *)ptr = newSize;

  __asan_poison_memory_region(ptr, OPENSSL_MALLOC_PREFIX);
  return ptr == NULL? ptr : ((uint8_t *)ptr) + OPENSSL_MALLOC_PREFIX;
}