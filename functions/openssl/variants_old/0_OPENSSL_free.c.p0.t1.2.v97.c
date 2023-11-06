void OPENSSL_free(void *orig_ptr) {
  if (orig_ptr == NULL) {
    return;
  }
  
  void *ptr = ((uint8_t *)orig_ptr) - OPENSSL_MALLOC_PREFIX;  
  size_t size = *(size_t *)ptr;
  
  if (OPENSSL_memory_free != NULL) {
    OPENSSL_memory_free(orig_ptr);
  } else {
  #if defined(BORINGSSL_SDALLOCX)
    OPENSSL_cleanse(ptr, size + OPENSSL_MALLOC_PREFIX);
    sdallocx(ptr, size + OPENSSL_MALLOC_PREFIX, 0);
  #else
    OPENSSL_cleanse(ptr, size + OPENSSL_MALLOC_PREFIX);
    free(ptr);
  #endif   
  }  

  __asan_unpoison_memory_region(ptr, OPENSSL_MALLOC_PREFIX);

}
