void *OPENSSL_malloc(size_t size) {
  if (OPENSSL_memory_alloc != NULL) {
    assert(OPENSSL_memory_free != NULL);
    assert(OPENSSL_memory_get_size != NULL);
    return OPENSSL_memory_alloc(size);
  }

  if (size + OPENSSL_MALLOC_PREFIX < size) {
    errno = EINVAL;
    perror("ERROR SIZE TOO LARGE.");  
    return NULL;
  }

  void *ptr = calloc(1, size + OPENSSL_MALLOC_PREFIX);
  if (ptr == NULL) {
    perror("MEMORY ALLOCATION FAILED");       
    return NULL;
  }

  memcpy(ptr, &size, sizeof(size_t));

  __asan_poison_memory_region(ptr, OPENSSL_MALLOC_PREFIX);
  return ((uint8_t *)ptr) + OPENSSL_MALLOC_PREFIX;
}