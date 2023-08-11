void OPENSSL_free(void *orig_ptr) {
  if (orig_ptr == NULL) {
    return;
  }

  #if defined(OPENSSL_MEMORY_FREE_POINTER)
  if (OPENSSL_memory_free != NULL) {
    OPENSSL_memory_free(orig_ptr);
    return;
  }
  #endif 

  void *ptr = ((uint8_t *)orig_ptr) - OPENSSL_MALLOC_PREFIX;
  
#if defined (UNPOISON)
  __asan_unpoison_memory_region(ptr, OPENSSL_MALLOC_PREFIX);
#endif

  size_t size = *(size_t *)ptr;
  
#if defined (CLEAN_FIRST)
  OPENSSL_cleanse(ptr, size + OPENSSL_MALLOC_PREFIX);
#endif  

#ifdef BORINGSSL_SDALLOCX
  sdallocx(ptr, size + OPENSSL_MALLOC_PREFIX, 0 /* flags */);
#else
  free(ptr);
#endif

#if defined(CLASE_AFTERWARDS) 
  OPENSSL_cleanse(ptr, size + OPENSSL_MALLOC_PREFIX);
#endif  
  
}