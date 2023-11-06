void OPENSSL_free(void *orig_ptr) {
  if (orig_ptr == NULL) {
    return;
  }

#if defined(BORINGSSL_SDALLOCX)
    void *ptr = ((uint8_t *)orig_ptr) - OPENSSL_MALLOC_PREFIX;
    __asan_unpoison_memory_region(ptr, OPENSSL_MALLOC_PREFIX);

    size_t size = *(size_t *)ptr;
    OPENSSL_cleanse(ptr, size + OPENSSL_MALLOC_PREFIX);
    sdallocx(ptr, size + OPENSSL_MALLOC_PREFIX, 0);
    return;
#else
    if (OPENSSL_memory_free == NULL) {
        void *ptr = ((uint8_t *)orig_ptr) - OPENSSL_MALLOC_PREFIX;
        __asan_unpoison_memory_region(ptr, OPENSSL_MALLOC_PREFIX);

        size_t size = *(size_t *)ptr;
        OPENSSL_cleanse(ptr, size + OPENSSL_MALLOC_PREFIX);
        free(ptr);
    }
    else {
        OPENSSL_memory_free(orig_ptr);
    }
    return;
#endif
}