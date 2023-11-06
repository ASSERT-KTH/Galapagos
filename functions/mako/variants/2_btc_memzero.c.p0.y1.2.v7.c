void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
    // Using assembly "mfence" instruction for an memory ordering barrier
    if (len) {
        memset(ptr, 0, len);

        asm volatile("" ::: "r" (ptr), "memory");
        asm volatile("mfence" ::: "memory");
    }
#elif defined(_WIN32) && defined(RtlSecureZeroMemory)
    // Using RtlSecureZeroMemory for Windows
    if (len)
        RtlSecureZeroMemory(ptr, len);
#else
    // fallback:
    volatile char *volatile cptr = (volatile char *volatile)ptr;
    size_t i = 0;

    if(len) {
        for (i = 0; i < len; i++)
            cptr[i] = 0;
    }
#endif
}