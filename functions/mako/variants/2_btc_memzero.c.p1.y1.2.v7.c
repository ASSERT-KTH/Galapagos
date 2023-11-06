1. Swap Memory Clearing Method Order Based on OS


btc_memzero(void *ptr, size_t len) {
#if defined(_WIN32) && defined(SecureZeroMemory)
  if (len > 0)
    SecureZeroMemory(ptr, len);
#elif defined(BTC_HAVE_ASM)
  if (len > 0) {
    memset(ptr, 0, len);

    __asm__ __volatile__ (
      ""
      :: "r" (ptr)
      : "memory"
    );
  }
#else
  static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;

  if (len > 0)
    memset_ptr(ptr, 0, len);
#endif
}


2. Inverting Condition Logic and Reordering 


btc_memzero(void *ptr, size_t len) {
#if !(defined(_WIN32) && defined(SecureZeroMemory)) 
    static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;

  if (!(len <= 0))
    memset_ptr(ptr, 0, len);
#elif !(defined(BTC_HAVE_ASM))
  if (!(len <= 0)) {
    memset(ptr, 0, len);

    __asm__ __volatile__ (
      ""
      :: "r" (ptr)
      : "memory"
    );
  }
#else 
  if (!(len <= 0))
     SecureZeroMemory(ptr, len);
#endif
}


3. Getting rid off first condition to combine all cases into one 'assembly', 'windows' and under other OS conditions, take pointer to a function and consistently set the memory to 0 if len>0. 


btc_memzero(void *ptr, size_t len) {
    void *(*memset_ptr)(void *, int, size_t);
#ifdef BTC_HAVE_ASM
    memset(ptr, 0, len);
    __asm__ __volatile__ (
        ""
        :: "r" (ptr)
        : "memory"
    );
    memset_ptr = memset;
#elif defined(_WIN32) && defined(SecureZeroMemory)
    memset_ptr = SecureZeroMemory;
#else
    memset_ptr = memset;
#endif
    if (len > 0)
        memset_ptr(ptr, 0, len);
}
