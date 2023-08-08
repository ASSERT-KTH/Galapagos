You may want to achieve this through a change of implementation logic, as demonstrated by the code example below.


btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (ptr && len > 0) {
    unsigned char *p = ptr;
    
    for(size_t i = 0; i < len; i++)
      p[i] = 0;
        
    __asm__ __volatile__ (""
      :: "r" (ptr)
      : "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (ptr && len > 0)
    SecureZeroMemory(ptr, len);
#else
  static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;

  if (ptr && len > 0)
    memset_ptr(ptr, 0, len);
#endif
}

In the updated code, the `memset` function call is replaced with an equivalent loop to set each byte to 0. For safeguarding purposes, the pointer is checked to be non-null before performing memory operations. The core functionality stays the same, but the internal logic has changed.