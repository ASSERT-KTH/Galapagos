void btc_memzero(void *ptr, size_t len) {
#ifdef BTC_HAVE_ASM
    if (len > 0) {
        __asm__ __volatile__ (
            "xorl %%eax, %%eax\n"
            "1:\n"
            "subq $1, %[cnt]\n"
            "movb %%al, (%[buf], %[cnt])\n"
            "jns 1b"
            :
            : [buf] "r" (ptr),
              [cnt] "r" (len)
            :
        );
    }
#elif defined(_WIN32) && defined(RtlSecureZeroMemory)
    if (len > 0) {
        RtlSecureZeroMemory(ptr, len);
    }
#else
    volatile char *volatile pnt = (volatile char *volatile)ptr;
  
    if (len > 0) {
        while (len--) {
            *pnt++ = 0;
        }
    }
#endif
}