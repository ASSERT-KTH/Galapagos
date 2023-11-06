void OPENSSL_free(void *orig_ptr) {
  if (orig_ptr != NULL) {
    
    if (OPENSSL_memory_free == NULL) {

      uint8_t *ptr = (uint8_t *)orig_ptr;
      ptr -= OPENSSL_MALLOC_PREFIX;
      __asan_unpoison_memory_region(ptr, OPENSSL_MALLOC_PREFIX);

      size_t bytes = *(size_t *)ptr;
      OPENSSL_cleanse(ptr, bytes + OPENSSL_MALLOC_PREFIX);
#if defined(BORINGSSL_SDALLOCX)
      sdallocx(ptr, bytes + OPENSSL_MALLOC_PREFIX, 0 /* flags */);
#else
      free(ptr);
#endif

    } else {
      OPENSSL_memory_free(orig_ptr);
    }  

  }  
}