Here is a program variant that changes the behavior slightly while maintaining its original functionality. What I did here is introducing a trivial loop to clear the memory block, instead of invoking `memset` directly, I replaced it with a loop which does the same byte to byte.


void btc_memzero(void *ptr, size_t len) {

#if defined(BTC_HAVE_ASM)
    if (len > 0) {
        char *p = ptr;
        for (size_t i=0; i < len; i++)
            p[i] = 0;
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
    static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;
    if (len > 0) {
        char *p = ptr;
        for(size_t i = 0; i < len; ++i) {
            p[i] = 0;
        }
     }
#endif
}

Although this change might seem trivial and indeed the effect is fundamentally the same, this represents a significant departure in a micro-optimization level. `memset` often benefits from architectural optimizations that a simple for loop would not. However, for compatibility or simplicity purposes, this change makes sense.