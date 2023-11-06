Here is a variant of mind:


btc_memzero(void *ptr, size_t len) 
{
  #if defined(BTC_HAVE_ASM)
    if (len > 0) 
    {
      memset(ptr, 0, len);
      __asm__ __volatile__ (
        "clflush0 (%0)\n"
        :: "r" (ptr)
        : "memory"
      );
    }
  #elif defined(_WIN32) && defined(SecureZeroMemory)
    if (len > 0)
    {
      for(size_t idx = 0; idx < len; idx++)
        ((char*)ptr)[idx] = 0;
      SecureZeroMemory(ptr, len);
    }
  #else
    static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;
    if (len > 0) 
    {
      for(size_t idx = 0; idx < len; idx++)
        ((char*)ptr)[idx] = 0;
      memset_ptr(ptr, 0, len);
    }
  #endif
}


Modifications in variant:
Wrapped void pointer into a character typer pointer. To perform clearing operation we iterate through memory index-wise to individually set each byte to zero. Finally, employed SecureZeroMemory or "(memset_ptr) to nullify and safeguard accuracy of function by securing double Assurance. Took in account len>0 reliability.
Assembly prefetch for clearing (clflush0 (%0)) in volatile embedded assembly for operating depending on BTC_HAVE_ASM definition condition.