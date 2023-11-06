Variant 1: Change the ordering and usage of `if (len > 0)` check

void btc_memzero(void *ptr, size_t len) {
  if(len <= 0) 
     return;
     
  #if defined(BTC_HAVE_ASM)
    memset(ptr, 0, len);
    __asm__ __volatile__ (""
        :: "r" (ptr)
            : "memory");

  #elif defined(_WIN32) && defined(SecureZeroMemory)
    SecureZeroMemory(ptr, len);

  #else
    static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;
    memset_ptr(ptr, 0, len);
    
  #endif
}



Variant 2: Group case conditions together, utilize an alternate memset function name

void btc_memzero(void *ptr, size_t len) {
  #ifdef BTC_HAVE_ASM
    if(len > 0)
    {
        memset(ptr, 0, len);
        __asm__ __volatile__ (""
           :: "r" (ptr)
           : "memory");
    }
  #endif

#ifdef _WIN32 
  #ifdef SecureZeroMemory
    if(len > 0)
    {
        SecureZeroMemory(ptr, len);
    }
  #endif
#endif

#if !defined(BTC_HAVE_ASM) && (!defined(_WIN32) || !defined(SecureZeroMemory)) 
    static void *(*const volatile memset_dummy)(void *, int, size_t) = memset;
    if(len > 0)
    {
        memset_dummy(ptr, 0, len);
    }
#endif 
}

