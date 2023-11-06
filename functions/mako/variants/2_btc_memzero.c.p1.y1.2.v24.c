1)
void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len) {
    memset(ptr, 0, len);
    __asm__ __volatile__ (
      ""
      :
      : "r" (ptr)
      : "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  
  if (len)
    SecureZeroMemory(ptr, len);

#else
  static void *(*volatile memset_ptr)(void *, int, size_t) = ptr ? memset : NULL;

  if (len && memset_ptr)
    memset_ptr(ptr, 0, len);
#endif
}

2)
void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len != 0) {
    memset(ptr, 0, len);
    __asm__ __volatile__ (
      ""
      : 
      : "r" (ptr)
      : "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len != 0)
    SecureZeroMemory(ptr, len);
#else
  static void *(*const volatile memset_is_present)(void *, int, size_t) = memset;

  if (len != 0)
    memset_is_present(ptr, 0, len);
#endif
}

3)
void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len > 0) {
    memset(ptr, 0, len);

    __asm__ __volatile__ ( 
      ""
      : 
      : "r" (ptr)
      : "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
    len > 0 ? SecureZeroMemory(ptr, len) : void();
#else
    static void *(*const volatile memset_function)(void *, int, size_t) = memset;
    
    if (len > 0)
        memset_function(ptr, 0, len);
#endif
}