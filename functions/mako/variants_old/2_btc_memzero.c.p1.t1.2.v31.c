void btc_memzero(void *ptr, size_t len) {
  #if defined(BTC_HAVE_ASM)
    if (len > 0) {
      memset(ptr, 0, len);

      __asm__ __volatile__ (
        "sfence\n\t"        // Adding the sfence operation.
        :: "r" (ptr)
        : "memory"
      );
    }
  #elif defined(_WIN32) && defined(SecureZeroMemory)
    if (len > 0) {
      SecureZeroMemory(ptr, len);
      _mm_sfence();    // Adding memory fence to make sure every previous load and store operation has been committed.
    }
  #else
    volatile char *volatile p=(volatile char*)ptr;  // casting void ptr to volatile char ptr.
    volatile unsigned char *volatile ucptr;
 
    acptr=p,len;
    size_t i;
    for(i=0;i!=len;i++)
      acptr[i]=0;
  #endif
}