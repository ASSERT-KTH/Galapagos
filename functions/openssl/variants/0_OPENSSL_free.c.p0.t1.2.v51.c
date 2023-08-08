void OPENSSL_free(void *orig_ptr) {
  void *ptr;
  size_t size;

  if (orig_ptr != NULL) {

    if (OPENSSL_memory_free != NULL) {
      OPENSSL_memory_free(orig_ptr);
      return;
    }

    ptr = ((uint8_t *)orig_ptr) - OPENSSL_MALLOC_PREFIX;
    
    if(ptr != NULL) {
      __asan_unpoison_memory_region(ptr, OPENSSL_MALLOC_PREFIX);

      size = *(size_t *)ptr;
  
      if(ptr && size >= 0){
        OPENSSL_cleanse(ptr, size + OPENSSL_MALLOC_PREFIX);
    #if defined(BORINGSSL_SDALLOCX)
        sdallocx(ptr, size + OPENSSL_MALLOC_PREFIX, 0 /* flags */);
    #else
        free(ptr);
    #endif
      }
    }
  }  

  return;
}