/* Variant 1: Removing unnecessary if condition inside all branches */
void btc_memzero_variant1(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  memset(ptr, 0, len);

  __asm__ __volatile__ (
    ""
    :: "r" (ptr)
    : "memory"
  );
#elif defined(_WIN32) && defined(SecureZeroMemory)
  SecureZeroMemory(ptr, len);
#else
  static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;
  memset_ptr(ptr, 0, len);
#endif
}

/* Variant 2: Converting if condition to do-while loop keeping the original functionalities 
This is applicable when SecureZeroMemory is not available */
void btc_memzero_variant2(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  do {
    memset(ptr, 0, len);

    __asm__ __volatile__ (
      ""
      :: "r" (ptr)
      : "memory"
    );
  } while(0);
#else
  static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;
  do {
    memset_ptr(ptr, 0, len);
  } while(0);
#endif
}

/* Variant 3: Using for loop instead of if but only running one iteration */
void btc_memzero_variant3(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  for( ; len>0; len=0)
  {
    memset(ptr, 0, len);
  
    __asm__ __volatile__ (
      ""
      :: "r" (ptr)
      : "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  for( ; len>0; len=0)
      SecureZeroMemory(ptr, len);
#else
  static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;
  for( ; len>0; len=0)
    memset_ptr(ptr, 0, len);
#endif
}