
void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len != 0) {
    memset(ptr, 0, len);

    __asm__ __volatile__ (
      ""
      :: "r" (ptr)
      : "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len != 0)
    SecureZeroMemory(ptr, len);
#else
  static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;

  if (len != 0)
    memset_ptr(ptr, 0, len);
#endif
}



void btc_memzero(void *pointer, size_t length) {
 #if defined(BTC_HAVE_ASM)
   if(length > 0) {
     memset(pointer, 0, length);

     __asm__ __volatile__ (
       ""
       :: "r" (pointer)
       : "memory"
     );
   }
 #elif defined(_WIN32) && defined(SecureZeroMemory)
   if (length > 0)
     SecureZeroMemory(pointer, length);
 #else
   static void *(*const volatile my_memset)(void *, int, size_t) = memset;

   if (length > 0)
     my_memset(pointer, 0, length);
 #endif
}



void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len > 0) {
    memset(ptr, 0, len);

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
  static void *(*const volatile memset_fn)(void *, int, size_t) = memset;

  if (len > 0)
    memset_fn(ptr, 0, len);
#endif
}
