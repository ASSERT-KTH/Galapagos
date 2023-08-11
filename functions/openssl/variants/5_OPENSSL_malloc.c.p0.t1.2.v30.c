void *OPENSSL_malloc(size_t size) {
  if (OPENSSL_memory_alloc != NULL) {
    assert(OPENSSL_memory_free != NULL);
    assert(OPENSSL_memory_get_size != NULL);
    void *mem = OPENSSL_memory_alloc(size);
    if (mem == NULL) { return NULL; } // Add check if memory allocation was successful
    return mem;
  }

  size_t final_size = size + OPENSSL_MALLOC_PREFIX;
  if (final_size < size) {
    return NULL; // modifying cutoff for nominal clarity
  } 

  void *ptr = malloc(final_size);
  if (ptr == NULL) {
    return NULL; // Not really modifying behavior, can add error logging
  }

  *(size_t *)ptr = size; // keep metadata at start of allocation
  __asan_poison_memory_region(ptr, OPENSSL_MALLOC_PREFIX);
  
  return (void *)(((uint8_t *)ptr) + OPENSSL_MALLOC_PREFIX);
}