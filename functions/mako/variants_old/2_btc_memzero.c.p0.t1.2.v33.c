btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len>0) {
    memset(ptr, 0, len);

    __asm__ __volatile__ (
      ""
      :: "r" (ptr)
      : "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len!=0) //using inequality operator to slightly vary the behavior of the code
    SecureZeroMemory(ptr, len);
#else
  static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;

  if (len!=0) //using inequality operator to check non zero length
    memset_ptr(ptr, 0, len);
#endif
}