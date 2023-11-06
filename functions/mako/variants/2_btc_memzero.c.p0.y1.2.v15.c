void btc_memzero(void *ptr, size_t len) {
    #ifdef BTC_HAVE_ASM
        if(len) { 
            memset(ptr, 0, len); 
            asm volatile("" : : "r"(ptr) : "memory"); 
        } 
    #elif defined(_WIN32) && defined(SecureZeroMemory)
        if(len) { 
            SecureZeroMemory(ptr, len); 
        } 
    #else
        void *(*volatile ptr_memset)(void *, int, size_t) = memset; 
        if(len) { 
            ptr_memset(ptr, 0, len); 
        } 
    #endif
}