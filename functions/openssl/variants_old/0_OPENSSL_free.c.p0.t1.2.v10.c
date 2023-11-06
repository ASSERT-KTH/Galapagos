void OPENSSL_free(void *orig_ptr) {
  if (orig_ptr == NULL) {
    return;
  }
  
  if (orig_ptr != NULL && OPENSSL_memory_free != NULL) {
    OPENSSL_memory_free(orig_ptr);
    return;
  }

  void *ptr = ((uint8_t *)orig_ptr) - OPENSSL_MALLOC_PREFIX;
  
  if(ptr != NULL){
    __asan_unpoison_memory_region(ptr, OPENSSL_MALLOC_PREFIX);
  }

  size_t size = *(size_t *)ptr;
  
  if(ptr != NULL && size >= 0){
    OPENSSL_cleanse(ptr, size + OPENSSL_MALLOC_PREFIX);
  }
  
#if defined(BORINGSSL_SDALLOCX)
  if(ptr != NULL && size >= 0){
    sdallocx(ptr, size + OPENSSL_MALLOC_PREFIX, 0 /* flags */);
  }
#else
  if(ptr != NULL){
    free(ptr);
  }
#endif
}