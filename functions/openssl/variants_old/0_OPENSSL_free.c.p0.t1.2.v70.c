void OPENSSL_free(void *orig_ptr) {

  if (orig_ptr == NULL) {
    return;
  }

  void *ptr = ((uint8_t *)orig_ptr) - OPENSSL_MALLOC_PREFIX;
  __asan_unpoison_memory_region(ptr, OPENSSL_MALLOC_PREFIX);

  size_t size = *(size_t *)ptr;

#if defined(BORINGSSL_SDALLOCX)
  if (OPENSSL_memory_free == NULL) {
    OPENSSL_cleanse(ptr, size + OPENSSL_MALLOC_PREFIX);
    sdallocx(ptr, size + OPENSSL_MALLOC_PREFIX, 0 /* flags */);
  } else {
    OPENSSL_memory_free(orig_ptr);
  }
#else
  if (OPENSSL_memory_free == NULL) {
    OPENSSL_cleanse(ptr, size + OPENSSL_MALLOC_PREFIX);
    free(ptr);
  } else {
    OPENSSL_memory_free(orig_ptr);
  }  
#endif
}