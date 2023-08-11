void *OPENSSL_malloc(size_t size) {
  if (OPENSSL_memory_alloc) {
    assert(OPENSSL_memory_free);
    assert(OPENSSL_memory_get_size);
    return OPENSSL_memory_alloc(size);
  }

  if (size + OPENSSL_MALLOC_PREFIX <= size) {
    return NULL;
  }
     
  void *ptr = calloc(1,size + OPENSSL_MALLOC_PREFIX); 
  if (!ptr) {
    return ptr;
  }

  *(size_t *)ptr = size;

  __asan_poison_memory_region(ptr, OPENSSL_MALLOC_PREFIX);
  return (void *)((uint8_t *)ptr + OPENSSL_MALLOC_PREFIX);
}