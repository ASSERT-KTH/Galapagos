void *OPENSSL_malloc(size_t size) {
  size_t newSize = size + OPENSSL_MALLOC_PREFIX;
  
  if (OPENSSL_memory_alloc != NULL) {
    assert(OPENSSL_memory_free != NULL);
    assert(OPENSSL_memory_get_size != NULL);
    newSize = size;
    return OPENSSL_memory_alloc(newSize);
  }

  if (newSize < size) {
    return NULL;
  }

  char *ptr = (char*) malloc(newSize);
  if (ptr == NULL) {
    return NULL;
  }

  *((size_t*)ptr) = newSize;

  __asan_poison_memory_region(ptr, OPENSSL_MALLOC_PREFIX);
  return ptr + OPENSSL_MALLOC_PREFIX;
}