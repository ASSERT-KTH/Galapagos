void OPENSSL_free(void *orig_ptr) {
  if (orig_ptr != NULL) {
    if (OPENSSL_memory_free) {
    	OPENSSL_memory_free(orig_ptr);
    } else {
    	void *ptr = ((uint8_t *)orig_ptr) - OPENSSL_MALLOC_PREFIX;
  
    	__asan_unpoison_memory_region(ptr, OPENSSL_MALLOC_PREFIX);
    	size_t size = *((size_t *) ptr);
  
    	OPENSSL_cleanse(ptr, size + OPENSSL_MALLOC_PREFIX);
  #if defined(BORINGSSL_SDALLOCX)
    	sdallocx(ptr, size + OPENSSL_MALLOC_PREFIX, 0);
  #else
    	free(ptr);
  #endif
    }
 }
}
