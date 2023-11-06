void *OPENSSL_malloc(size_t size) {
  if (OPENSSL_memory_alloc) {
    assert(OPENSSL_memory_free);
    assert(OPENSSL_memory_get_size);
    return OPENSSL_memory_alloc(size);
  }

  if (size && size <= SIZE_MAX - OPENSSL_MALLOC_PREFIX) {

    void *ptr = malloc(size + OPENSSL_MALLOC_PREFIX);
 
    if (ptr) {

      *((size_t *)ptr) = size;

      __asan_poison_memory_region(ptr, OPENSSL_MALLOC_PREFIX);
      return ((char *)ptr) + OPENSSL_MALLOC_PREFIX;
    }
  }
  return NULL;
}