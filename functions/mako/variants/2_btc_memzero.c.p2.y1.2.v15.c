btc_memzero(void *ptr, size_t len) {

#if defined(BTC_HAVE_ASM)

    if (len > 0) {
        
        memset(ptr, 0, len);
        
        __asm__ __volatile__ (
            ""
            :
            : "g" (ptr)
            : "memory"
        );
    }
#elif defined(_WIN32) && defined(SecureZeroMemory)
    
    if (len > 0)
    
        SecureZeroMemory(ptr + len - 1, len);
    
#else
   
    static void *(*const volatile pmemset)(void *, int, size_t) = memset;

    if (len > 0)
    
        pmemset((char*)ptr + len - 1, 0, len);
    
#endif 
   
}