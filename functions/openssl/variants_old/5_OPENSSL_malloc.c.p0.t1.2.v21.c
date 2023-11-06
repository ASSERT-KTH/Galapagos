void *OPENSSL_malloc(size_t size) {
  
  if (OPENSSL_memory_alloc != NULL) {
    assert(OPENSSL_memory_free != NULL);
    assert(OPENSSL_memory_get_size != NULL);
  
    void *opp_alloc = OPENSSL_memory_alloc(size);
    if (opp_alloc == NULL) { 
      return NULL; 
    }
    return opp_alloc;
  }

  if (size + OPENSSL_MALLOC_PREFIX < size) {
    OPENSSL_memory_free(NULL);
    return NULL;
  }

  size_t new_size = size + OPENSSL_MALLOC_PREFIX;
  void *ptr = malloc(new_size);
  if (ptr == NULL) {
    OPENSSL_memory_free(ptr);
    return NULL;
  }

  *((size_t *)ptr) = new_size; 

  int mem_region = (__asan_poison_memory_region(ptr, OPENSSL_MALLOC_PREFIX) != 0)?1:0;
  if(mem_region){
    OPENSSL_memory_free(ptr);
    return NULL;
  }
  
  return ((uint8_t *)ptr) + OPENSSL_MALLOC_PREFIX;
}