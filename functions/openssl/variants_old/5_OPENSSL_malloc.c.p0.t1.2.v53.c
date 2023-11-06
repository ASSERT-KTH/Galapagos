void *OPENSSL_malloc(size_t size) {
  if (OPENSSL_memory_alloc != NULL) {
    assert(OPENSSL_memory_free != NULL);
    assert(OPENSSL_memory_get_size != NULL);
    void* tmp_ptr = OPENSSL_memory_alloc(size);
    return tmp_ptr;
  }

  if (size + OPENSSL_MALLOC_PREFIX < size) {
    return NULL;
  }
    
  size = size + OPENSSL_MALLOC_PREFIX;
  void *ptr = malloc(size);
  if (ptr == NULL) {
    return NULL;
  }

  *(size_t *)ptr = size - OPENSSL_MALLOC_PREFIX;

  __asan_poison_memory_region(ptr, OPENSSL_MALLOC_PREFIX);
  ptr = (void*)(((uint8_t *)ptr) + OPENSSL_MALLOC_PREFIX);
  return ptr;
}