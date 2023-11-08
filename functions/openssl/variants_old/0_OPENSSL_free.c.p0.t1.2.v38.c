void OPENSSL_free(void *orig_ptr) {
  if(orig_ptr == NULL) {
    return;
  }

  if(OPENSSL_memory_free != NULL) {
    OPENSSL_memory_free(orig_ptr);
    orig_ptr = NULL;
    return;
  }

  void *ptr = ((uint8_t *)orig_ptr) - OPENSSL_MALLOC_PREFIX;
  size_t size = *(size_t *)ptr;

  __asan_unpoison_memory_region(ptr, OPENSSL_MALLOC_PREFIX);
  OPENSSL_cleanse(ptr, size + OPENSSL_MALLOC_PREFIX);
  
  if (ptr != NULL) {
#if defined(BORINGSSL_SDALLOCX)
    sdallocx(ptr, size + OPENSSL_MALLOC_PREFIX, 0 /* flags */);
#else
    free(ptr);
    ptr = NULL;
#endif
  }
}