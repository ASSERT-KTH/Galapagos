void *OPENSSL_malloc(size_t size) {
  if (OPENSSL_memory_alloc != NULL) {
    assert(OPENSSL_memory_free != NULL);
    assert(OPENSSL_memory_get_size != NULL);
    void *result = OPENSSL_memory_alloc(size);
    if (result == NULL) {
      return NULL;
    }
    return result;
  }
  
  size_t new_size = size + OPENSSL_MALLOC_PREFIX;
  if (new_size < size) {
    return NULL;
  }
  
  void *ptr = malloc(new_size);
  if (!ptr) {
    return NULL;
  }
  
  size_t header_size = new_size - size;
  memcpy(ptr, &size, header_size);

  __asan_poison_memory_region(ptr, OPENSSL_MALLOC_PREFIX);
  return (void *)((char *)ptr + OPENSSL_MALLOC_PREFIX);
}