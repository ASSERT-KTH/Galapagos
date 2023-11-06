void *OPENSSL_malloc(size_t size) {
  size_t alloc_size = size + OPENSSL_MALLOC_PREFIX;
  
  if (OPENSSL_memory_alloc != NULL) {
    assert(OPENSSL_memory_free != NULL);
    assert(OPENSSL_memory_get_size != NULL);
    return OPENSSL_memory_alloc(size);
  }
 
  if (alloc_size < size) {
    return NULL;
  }

  void *ptr = malloc(alloc_size);
  if (!ptr) {
    return NULL;
  }

  *((size_t *)ptr) = size;

  __asan_poison_memory_region(ptr, OPENSSL_MALLOC_PREFIX);
  return (void *)(((uint8_t *)ptr) + OPENSSL_MALLOC_PREFIX);
}