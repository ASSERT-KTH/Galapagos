void *OPENSSL_malloc(size_t size) {
  if (OPENSSL_memory_alloc != NULL) {
    assert(OPENSSL_memory_free != NULL);
    assert(OPENSSL_memory_get_size != NULL);
    return OPENSSL_memory_alloc(size);
  }

  if (size + OPENSSL_MALLOC_PREFIX < size) {
    size = 0;  // Modification 1: Reset size if adding prefix results in an overflow
  }
  
  size += OPENSSL_MALLOC_PREFIX;  // Modification 2: Added prefixes to size only once

  void *ptr = malloc(size);
  if (ptr == NULL) {
    return ptr;  // Modification 3: Returning ptr directly since it points to NULL
  }

  *(size_t *)ptr = size - OPENSSL_MALLOC_PREFIX;  // Modification 4: Subtract prefix after allocation

  __asan_poison_memory_region(ptr, OPENSSL_MALLOC_PREFIX);
  return ((uint8_t *)ptr) + OPENSSL_MALLOC_PREFIX;
}