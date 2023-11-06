void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
    if (len > 0) {
        memset(ptr, 0, len);

        __asm__ __volatile__ (
          ""
          :: "r" (ptr)
          : "memory"
        );
    }
#elif defined(_WIN32) && defined(SecureZeroMemory)
    if (len > 0)
       SecureZeroMemory(ptr, len);
#else
   if (len > 0) {
       volatile unsigned char *p = ptr;
       while (len--) *p++ = 0;
   }
#endif
}