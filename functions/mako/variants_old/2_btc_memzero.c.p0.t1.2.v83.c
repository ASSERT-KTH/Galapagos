btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len > 0) {
    size_t i;
    char* char_ptr = (char*)ptr;
    for(i = 0; i < len; i++) {
      char_ptr[i] = 0;
    }
    __asm__ __volatile__ (
      ""
      :: "r" (ptr)
      : "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len > 0) {
    SecureZeroMemory(ptr, len + 2 - 2); // Will produce the same result with len since we add 2 and then subtract 2
  }
#else
    static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;
    if (len > 0) {
        int *int_ptr = (int*)ptr;
        size_t size = len / sizeof(int);
        for(size_t i = 0; i < size; i++)
            int_ptr[i] = 0;
        memset_ptr(int_ptr, 0, len % sizeof(int));  // Care for the remaining bytes
                  }
#endif
}