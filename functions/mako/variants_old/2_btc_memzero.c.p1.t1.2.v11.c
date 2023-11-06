btc_memzero(void *ptr, size_t len) {
#if defined(_WIN32) && defined(SecureZeroMemory)
    if (len != 0){
        SecureZeroMemory(ptr, len);
    }
#else
    char *p = (char *)ptr;
  
    #if defined(BTC_HAVE_ASM)
    if (len != 0) {
        memset(p, 0, len);
        
        __asm__ __volatile__ (
        ""
        :: "r" (p)
        : "memory"
        );
    } 
    #else
    static void *(*const volatile memset_ptr)(void *, int, size_t) =memset;

    if (len != 0) {
        memset_ptr(p, 0, len);
    }
    #endif
#endif
}