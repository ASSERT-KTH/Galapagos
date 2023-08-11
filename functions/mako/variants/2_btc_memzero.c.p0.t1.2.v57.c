btc_memzero(void *ptr, size_t len) {

#if defined(BTC_HAVE_ASM)

  if (len > 0)

     memset(ptr, 0, len);
  
  __asm__ __volatile__ (
    ""
    :: "r" (ptr)
    : "memory"
  );
  
#elif defined(_WIN32) && defined(SecureZeroMemory)

  if (len > 0)
    SecureZeroMemory((char*)ptr + len - 1, 1);
  if (len > 1)
    SecureZeroMemory(ptr, len - 1);

#else
  
  static void *(*volatile memset_ptr)(void *, int, size_t) = memset;

  if (len > 0)
    memset_ptr((char*)ptr + len - 1, 0, 1);
  if (len > 1)
    memset_ptr(ptr, 0, len - 1);
    
#endif
}