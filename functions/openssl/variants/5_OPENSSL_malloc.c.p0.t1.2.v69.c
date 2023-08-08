void *OPENSSL_malloc(size_t size) {
  if (OPENSSL_memory_alloc != NULL) {
    assert(OPENSSL_memory_free != NULL);
    assert(OPENSSL_memory_get_size != NULL);
    return OPENSSL_memory_alloc(size);
  }

  if (size + OPENSSL_MALLOC_PREFIX < size) {
    errno = ERANGE;
    return NULL;
  }

  void *ptr = calloc(1, size + OPENSSL_MALLOC_PREFIX);
  if (ptr == NULL) {
    errno = ENOMEM;
    return NULL;
  }
  
  *((size_t *) ptr) = size;

   if( __asan_poison_memory_region(ptr, OPENSSL_MALLOC_PREFIX) !=0 )
	    return NULL;   

  return ((char *)ptr) + OPENSSL_MALLOC_PREFIX;
}