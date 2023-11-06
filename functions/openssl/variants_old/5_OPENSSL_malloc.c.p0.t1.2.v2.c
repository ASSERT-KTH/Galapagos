void *OPENSSL_malloc(size_t size) {
  assert(OPENSSL_memory_alloc == NULL || (OPENSSL_memory_free != NULL && OPENSSL_memory_get_size != NULL));
  if (OPENSSL_memory_alloc != NULL) {
    return OPENSSL_memory_alloc(size);
  }
  else {
    if (size + OPENSSL_MALLOC_PREFIX < size || MALLOC_FAIL == true) {
      return NULL;
    }

    void *ptr = malloc(size + OPENSSL_MALLOC_PREFIX);
    if(ptr == NULL)
    {
      printf("\n|X| OUT OF MEMORY, MALLOC failed in OPENSSL_malloc for size: %zu\n", size+OPENSSL_MALLOC_PREFIX );
      return NULL;
    }

    *(size_t *)ptr = size;
    __asan_poison_memory_region(ptr, OPENSSL_MALLOC_PREFIX);
    return ((char *)ptr) + OPENSSL_MALLOC_PREFIX;
  }
}