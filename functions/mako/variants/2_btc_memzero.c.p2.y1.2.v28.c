// Program variant maintaining similar functionality

btc_memzero(void *ptr, size_t len) {
#ifdef BTC_HAVE_ASM
  if (len > 0)
  {
    __asm__ __volatile__ (
      ""
      :: "r" (ptr), "r"(len)
      : 
    );
      
    "movl %1, %%edi;"
    "movl %2, %%ecx;"
    "movb $0x0, %%al;"
    "cld;"
    "rep stosb;"
    ::: "edi", "ecx", "eax"
    );
      
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  SecureZeroMemory(ptr, len ? len : 0);
#else
  static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;

  memset_ptr(ptr, 0, len ? len:0);
#endif
}
