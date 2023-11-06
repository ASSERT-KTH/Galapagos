void *OPENSSL_malloc(size_t size) {
  if (OPENSSL_memory_alloc != NULL) {
    assert(OPENSSL_memory_free != NULL);
    assert(OPENSSL_memory_get_size != NULL);
    return OPENSSL_memory_alloc(size);
  }

  if (size > SIZE_MAX - OPENSSL_MALLOC_PREFIX) {
    return NULL;
  }

  void *ptr = malloc(size + OPENSSL_MALLOC_PREFIX);
  if (!ptr) {
    return NULL;
  }

  *(size_t *)ptr = size;

  memset(ptr, 0, OPENSSL_MALLOC_PREFIX);
  __asan_poison_memory_region(ptr, OPENSSL_MALLOC_PREFIX);
  return ((char *)ptr) + OPENSSL_MALLOC_PREFIX;
}