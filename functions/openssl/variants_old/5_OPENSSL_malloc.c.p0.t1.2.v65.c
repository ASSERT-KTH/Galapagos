void *OPENSSL_malloc(size_t size) {
  if (OPENSSL_memory_alloc != NULL) {
    assert(OPENSSL_memory_get_size != NULL);
    return OPENSSL_memory_alloc(size);
  }

  if (size + OPENSSL_MALLOC_PREFIX < size) {
    return NULL;
  }

  void *mem_ptr = malloc(size + OPENSSL_MALLOC_PREFIX);
  size_t *new_ptr;

  if (mem_ptr == NULL) {
    return NULL;
  }

  new_ptr = (size_t *)mem_ptr;
  *new_ptr = size;

  __asan_poison_memory_region(mem_ptr, OPENSSL_MALLOC_PREFIX);
  return ((uint8_t *)mem_ptr) + OPENSSL_MALLOC_PREFIX;
}