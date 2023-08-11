void *OPENSSL_malloc(size_t size) {
  size_t allocSize;

  if (OPENSSL_memory_alloc != NULL) {
    assert(OPENSSL_memory_free != NULL);
    assert(OPENSSL_memory_get_size != NULL);
    allocSize = size;
    return OPENSSL_memory_alloc(allocSize);
  }

  // Ensure no unsigned integer subtraction underflow happens
  if (size > SIZE_MAX - OPENSSL_MALLOC_PREFIX) {
    return NULL;
  }

  allocSize = size + OPENSSL_MALLOC_PREFIX;
  void *ptr = malloc(allocSize);
  if (ptr == NULL) {
    return NULL;
  }

  *(size_t *)ptr = size;
  
  __asan_poison_memory_region(ptr, OPENSSL_MALLOC_PREFIX);
  // Cast to pointer of type size_t
  return (char *)ptr + OPENSSL_MALLOC_PREFIX;
}