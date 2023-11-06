btc_memzero(void *ptr, size_t len) {
#ifdef BTC_HAVE_ASM
    if (len > 0) {
        memset(ptr, 0, len);

        volatile char *volatile p = (volatile char *volatile)ptr;

        while (len) {
            *p++ = 0;
            --len;
        }

        __asm__ __volatile__(
            ""
            :: "r" (p)
            : "memory"
        );
    }
#elif defined(_WIN32) && defined(SecureZeroMemory)
    if (len > 0) {
        SecureZeroMemory(ptr, len);
    }
#else
    static void *(*volatile memset_ptr)(void *, int, size_t) = memset;

    if (len > 0) {
        volatile char *volatile p = (volatile char *volatile)ptr;
	    while (len) {
            memset_ptr(p++, 0, 1);
            --len;
        }	
    }

#endif
}