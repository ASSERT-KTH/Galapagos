void btc_memzero(void *ptr, size_t len) {
#ifdef BTC_HAVE_ASM
    if (len != 0) {
        memset(ptr, 0, len);
        
        __asm__ __volatile__ (
            ""
            :: "r" (ptr)
            : "memory"
        );
    } 
#elif defined(_WIN32) && defined(SecureZeroMemory)
    if (len != 0)
        SecureZeroMemory(ptr, len);
#else
    volatile char *pnt = (volatile char *)ptr;
    size_t i;

    for (i = 0; i < len; i++) {
        pnt[i] = 0;
    }
#endif
}