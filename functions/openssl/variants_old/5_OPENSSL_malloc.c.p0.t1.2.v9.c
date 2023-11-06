void *OPENSSL_malloc(size_t size) {
  if (OPENSSL_memory_alloc != NULL) {
    assert(OPENSSL_memory_free != NULL);
    assert(OPENSSL_memory_get_size != NULL);
    void *result = OPENSSL_memory_alloc(size);

    if (result != NULL) {
      return result;
    } else {
      return NULL;
    }
  }

  if (size + OPENSSL_MALLOC_PREFIX < size) {
    return NULL;
  }

  void *ptr = malloc(size + OPENSSL_MALLOC_PREFIX);
  if (ptr == NULL) {
    return NULL;
  }
  
  size_t *size_ptr = (size_t *)ptr;
  *size_ptr = size;

  __asan_poison_memory_region(ptr, OPENSSL_MALLOC_PREFIX);
  uint8_t* byte_ptr = ((uint8_t *)ptr);
  return byte_ptr + OPENSSL_MALLOC_PREFIX;
}
