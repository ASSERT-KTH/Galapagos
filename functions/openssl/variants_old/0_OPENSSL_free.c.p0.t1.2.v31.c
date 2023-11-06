void OPENSSL_free(void *orig_ptr) {
  if (orig_ptr == NULL) {
    return;
  }
  
  uint8_t *new_ptr = (uint8_t *)orig_ptr;
  
  if (OPENSSL_memory_free != NULL) {
    OPENSSL_memory_free(new_ptr);
    return;
  }

  new_ptr = new_ptr - OPENSSL_MALLOC_PREFIX;
  __asan_unpoison_memory_region(new_ptr, OPENSSL_MALLOC_PREFIX);

  size_t size = *(size_t *)new_ptr;
  OPENSSL_cleanse(new_ptr, size + OPENSSL_MALLOC_PREFIX);
#if defined(BORINGSSL_SDALLOCX)
  sdallocx(new_ptr, size + OPENSSL_MALLOC_PREFIX, 0 /* flags */);
#else
  free(new_ptr);
#endif  
}