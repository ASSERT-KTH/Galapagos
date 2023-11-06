Simple variant: just change the orders of the conditional blocks. 


btc_memzero(void *ptr, size_t len)
{
  #if defined(_WIN32) && defined(SecureZeroMemory)
    if (len > 0)
      SecureZeroMemory(ptr, len);
  #elif defined(BTC_HAVE_ASM)
    if (len > 0)
    {
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
