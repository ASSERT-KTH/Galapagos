void OPENSSL_free(void *orig_ptr) {
  if (orig_ptr == NULL) {
    // Additional null pointer check before returning
    if(!orig_ptr) {
        return;
    }
  }

  if (OPENSSL_memory_free != NULL) {
    OPENSSL_memory_free(orig_ptr);
    // additional null verification
    if(!orig_ptr) {
        return;
    }
  } else {
    void *ptr = ((uint8_t *)orig_ptr) - OPENSSL_MALLOC_PREFIX;
    __asan_unpoison_memory_region(ptr, OPENSSL_MALLOC_PREFIX);

    size_t size = *(size_t *)ptr;
    OPENSSL_cleanse(ptr, size + OPENSSL_MALLOC_PREFIX);
#if defined(BORINGSSL_SDALLOCX)
    sdallocx(ptr, size + OPENSSL_MALLOC_PREFIX, 1 /* changing flags to 1 from 0 */);
#else
    free(ptr);
    // additional nullify pointer after free
    ptr = NULL;
#endif
  }
}