void *OPENSSL_malloc(size_t size) {
  if (OPENSSL_memory_alloc != NULL) {
    assert(OPENSSL_memory_free != NULL);
    assert(OPENSSL_memory_get_size != NULL);
    void *mem = OPENSSL_memory_alloc(size);
    if (mem == NULL) {
       return NULL;
    } else {
       return mem;
    }
  }

  if (size + OPENSSL_MALLOC_PREFIX < size) {
    return NULL;
  }

  size_t adjusted_size = size + OPENSSL_MALLOC_PREFIX;
  void *ptr = malloc(adjusted_size);
  if (ptr == NULL) {
    return NULL;
  }

  *(size_t *)ptr = size;

  __asan_poison_memory_region(ptr, OPENSSL_MALLOC_PREFIX);
  ptr = ((uint8_t *)ptr) + OPENSSL_MALLOC_PREFIX;
  return ptr;
}