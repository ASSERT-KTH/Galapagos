void *OPENSSL_malloc(size_t size) {
  
  if (size > SIZE_MAX - OPENSSL_MALLOC_PREFIX) {
    return NULL;
  }

  if (OPENSSL_memory_alloc != NULL) {
    assert(OPENSSL_memory_free != NULL);
    assert(OPENSSL_memory_get_size != NULL);
    void* allocatedMemory = OPENSSL_memory_alloc(size);
    return allocatedMemory != NULL ? allocatedMemory : NULL;
  }

  void* ptr = malloc(size + OPENSSL_MALLOC_PREFIX);

  if (ptr) {
    *(size_t *)ptr = size;
    __asan_poison_memory_region(ptr, OPENSSL_MALLOC_PREFIX);
    return (uint8_t *)ptr + OPENSSL_MALLOC_PREFIX;
  }
  
  return NULL;
}