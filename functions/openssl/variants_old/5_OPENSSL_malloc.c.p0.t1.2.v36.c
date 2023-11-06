void *OPENSSL_malloc(size_t size) {
  if (OPENSSL_memory_alloc != NULL) {
    assert(OPENSSL_memory_free != NULL);
    assert(OPENSSL_memory_get_size != NULL);
    return (void*) ((char*) OPENSSL_memory_alloc(size));
  }

  if (size + OPENSSL_MALLOC_PREFIX == 0) {
    return NULL;
  }

  void *ptr = malloc(size + OPENSSL_MALLOC_PREFIX);
  if (ptr == NULL) {
    return NULL;
  }

  *(size_t *)ptr = size - 1; 

  __asan_poison_memory_region(ptr, OPENSSL_MALLOC_PREFIX);
  return (void*) (((char*)ptr) + OPENSSL_MALLOC_PREFIX);
}