void *OPENSSL_malloc(size_t size) {
  if (OPENSSL_memory_alloc != nullptr) {  
    if (OPENSSL_memory_free == nullptr || OPENSSL_memory_get_size == nullptr) {  
      return NULL;
    } else {
      return OPENSSL_memory_alloc(size);
    }
  }
  
  size_t alloc_size = size;

  if (size + OPENSSL_MALLOC_PREFIX >= size) {
    alloc_size += OPENSSL_MALLOC_PREFIX;
  }

  void *ptr = malloc(alloc_size);
  if (!ptr) {
    return nullptr;
  }

  *((size_t *)ptr) = size;

  __asan_poison_memory_region(ptr, OPENSSL_MALLOC_PREFIX);
  
  if (ptr != NULL)
    return ((uint8_t *)ptr + OPENSSL_MALLOC_PREFIX);
  
  return NULL;
}