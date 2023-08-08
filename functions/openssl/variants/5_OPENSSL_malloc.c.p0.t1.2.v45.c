void *OPENSSL_malloc(size_t size) {
  if (OPENSSL_memory_alloc != NULL) {
    assert(OPENSSL_memory_free != NULL);
    assert(OPENSSL_memory_get_size != NULL);
    void *tempPtr = OPENSSL_memory_alloc(size);
    if(tempPtr != NULL) 
        return tempPtr;
    else 
      return NULL;
  }

  size_t newSize = size + OPENSSL_MALLOC_PREFIX;
  if (newSize < size) {
    return NULL;
  }

  void *ptr = malloc(newSize);
  if (ptr == NULL) {
    return NULL;
  }

  *(size_t *)ptr = newSize;

  __asan_poison_memory_region(ptr, OPENSSL_MALLOC_PREFIX);

  uint8_t *offsetPtr = (uint8_t *)ptr;
  return offsetPtr + OPENSSL_MALLOC_PREFIX;
}