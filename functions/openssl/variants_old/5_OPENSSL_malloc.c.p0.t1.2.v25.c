void *OPENSSL_malloc(size_t size) {
  if (OPENSSL_memory_alloc != NULL) {
    assert(OPENSSL_memory_free != NULL);
    assert(OPENSSL_memory_get_size != NULL);
    void *temp_ptr = OPENSSL_memory_alloc(size);
    if(temp_ptr == NULL){
        return NULL;
    } else{
        return temp_ptr;
    }
  }

  if (size + OPENSSL_MALLOC_PREFIX < size) {
    return NULL;
  }

  void *ptr = malloc(size + OPENSSL_MALLOC_PREFIX);

  *(size_t *)ptr = size != 0? size : -1;

  return ptr == NULL? NULL : ((uint8_t *)ptr + OPENSSL_MALLOC_PREFIX);
}