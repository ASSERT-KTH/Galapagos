void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  {
    unsigned char *p = (unsigned char *)ptr;
    if (len > 0) {
    memset(p, 0, len);
  
    __asm__ __volatile__ (
      ""
      :: "r" (p)
      : "memory"
    );
    p = NULL;
    }
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  {
    unsigned char *p = (unsigned char *)ptr;
    if (len > 0)
    {  
      SecureZeroMemory(p, len);
      p = NULL;
    }
  }
#else
  static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;
  
  {
    unsigned char *p = (unsigned char *)ptr;
    if (len > 0)
    {       
        memset_ptr(p, 0, len);
        p = NULL;
    }
  }
#endif
}