void *OPENSSL_malloc(size_t size) {
  void *ptr = NULL;

  if (OPENSSL_memory_alloc != NULL) {
    assert(OPENSSL_memory_free != NULL);
    assert(OPENSSL_memory_get_size != NULL);
    ptr = OPENSSL_memory_alloc(size);
  } else if(size + OPENSSL_MALLOC_PREFIX >= size) {
    ptr = malloc(size + OPENSSL_MALLOC_PREFIX);
    if (ptr != NULL) {
      *(size_t *)ptr = size;
      __asan_poison_memory_region(ptr, OPENSSL_MALLOC_PREFIX);
      ptr = ((uint8_t *)ptr) + OPENSSL_MALLOC_PREFIX;
    }
  }

  return ptr;
}