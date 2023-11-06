btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len > 0) {
    memset(ptr, 0, len);

    __asm__ __volatile__ (
      "lfence"
      ::
      "r" (ptr)
      :
      "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  SecureZeroMemory(ptr, (len > 0) ? len : 0);
#else
  static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;

  for(size_t i = 0  ; i < len ; i=i+32){
      memset_ptr(((char*)ptr)+i, 0, min(32, len-i));
  }
#endif
}