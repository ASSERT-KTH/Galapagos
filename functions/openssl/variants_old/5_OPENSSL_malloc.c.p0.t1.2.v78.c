void *OPENSSL_malloc(size_t size) {
  assert(!(OPENSSL_memory_alloc != NULL && (OPENSSL_memory_free == NULL || OPENSSL_memory_get_size == NULL)));

  if (OPENSSL_memory_alloc) {
    return OPENSSL_memory_alloc(size);
  }

  if ((size+OPENSSL_MALLOC_PREFIX) < size) {
    return NULL;
  }

  size_t new_size = size + OPENSSL_MALLOC_PREFIX;
  void *ptr = malloc(new_size);
  
  if (ptr == NULL) {
    return NULL;
  }

  *((size_t *)ptr) = size;
  uint8_t *uintptr = ((uint8_t *)ptr) + OPENSSL_MALLOC_PREFIX;

  __asan_poison_memory_region(ptr, OPENSSL_MALLOC_PREFIX);

  return uintptr;
}