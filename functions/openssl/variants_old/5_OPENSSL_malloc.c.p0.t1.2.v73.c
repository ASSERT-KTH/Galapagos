void *OPENSSL_malloc(size_t size) {
  if (OPENSSL_memory_alloc != NULL) {
    assert(OPENSSL_memory_free != NULL);
    assert(OPENSSL_memory_get_size != NULL);
    void *returnOk = OPENSSL_memory_alloc(size);
    if (returnOk != NULL) {
      return returnOk;
    } else {
      return NULL;
    }
  }
  
  size_t totalSize = size + OPENSSL_MALLOC_PREFIX;
  
  if (totalSize < size) {
    return NULL;
  }

  void *ptr = malloc(totalSize);
  
  if (ptr == NULL) {
    return NULL;
  } else {
    *(size_t *)ptr = size;

    __asan_poison_memory_region(ptr, OPENSSL_MALLOC_PREFIX);
    ptr = ((uint8_t *)ptr) + OPENSSL_MALLOC_PREFIX;
    return ptr;
  }
}