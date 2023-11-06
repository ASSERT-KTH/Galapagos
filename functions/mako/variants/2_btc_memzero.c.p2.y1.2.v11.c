btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len > 0) {
    __asm__ __volatile__ (
       "rep stosq\n\t"
      :: "D" (ptr), "a" (0), "c" (len / 8 )
      : "memory"
     );
    
    __asm__ __volatile__ (
      "rep stosb\n\t"
      :: "D" (ptr + ((len / 8)*8 )), "a" (0), "c" (len % 8 )
      : "memory"
     );
  } 
#elif defined(_WIN32) && defined(SecureZeroMemory)
    if (len > 0)
      RtlSecureZeroMemory(ptr, len);
#else 
   static void *(* const volatile p_memset)(void *, int, size_t) = memset;
   
   if (len > 0) 
      p_memset(ptr, 0, len);
#endif
}