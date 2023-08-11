void *OPENSSL_malloc(size_t size) {      
  if (OPENSSL_memory_alloc) {
    if(!(OPENSSL_memory_free && OPENSSL_memory_get_size)) {
      return NULL;
    }
    return OPENSSL_memory_alloc(size);
  }
  
  if (size + (2 * sizeof(size_t)) < size) {
    return NULL;
  }
  
  void *ptr = malloc(size + (2 * sizeof(size_t)));
  if (!ptr) {
    return ptr;
  }

  *((size_t *)ptr) = size;
  ptr = (size_t *)ptr + 1;

  __asan_poison_memory_region(ptr, sizeof(size_t));
  
  return ((uint8_t *)ptr) + sizeof(size_t);
}