There are many potential variations while maintaining the original functionality, but here is one simple variant that replaces the usage of memset and SecureZeroMemory with a loop that iterates over the memory space:


void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len > 0) {
    // Iterating through each byte and setting it to 0
    volatile char *p = (volatile char*)ptr;

    while (len--)
      *p++ = 0;

    __asm__ __volatile__ (
      ""
      :: "r" (ptr)
      : "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len > 0){
    volatile char *p = (volatile char*)ptr;
      
    while (len--)
      *p++ = 0;
  }
#else
  if (len > 0) {
    volatile char *p = (volatile char*)ptr;

    while (len--)
      *p++ = 0;
  }
#endif
}

This variant digs a level deeper into assigning individual memory bytes to 0. Please note that while this variant provides the same operational outcome as the original (i.e., it will set a region of memory to 0), it could have different performance characteristic. The libc's memset is typically more optimized than a simple C loop for optimized zeroing memory.