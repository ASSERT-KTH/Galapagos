The example below maintains the original functionality, but changes the behavior by using a slightly different method for erasing (memsetting to 0) based on platform for part of the implementation.


btc_memzero(void *ptr, size_t len) {
    assert(ptr || len == 0);

  #if defined(BTC_HAVE_ASM)
    while (len) {
      __asm__ __volatile__ (
        "mov [[%1]], %%eax; xor %%eax, %%eax; mov %%eax, [[%1]]"
        : /* No outputs */ 
        : "r" (ptr), "r" (len)
        : "%eax", "memory"
      ); 
      ptr = (char *) ptr + 1;
      len -= 1;
    }
  #elif defined(_WIN32) && defined(SecureZeroMemory)
    if (len > 0)
      SecureZeroMemory(ptr, len);
   #else
    static volatile char *volatile p;
    static volatile unsigned x;
    char *pp = ptr;
    size_t ll = len;
    
    while (ll) { 
      p = pp; x = 0; *p = x; 
      pp += 1;
      ll -= 1; 
    }
  #endif
}


In limited platforms (__memory barrier execution with '__asm__', SecureZeroMmeory method, dynamically link `memset` function resolution scenario,), such a method can include the data-dependent timing into globally and locally declared variable's intended values. But, the same modified function may drop the performances than memset related process. So, you might need to decide the use-case of such mechanism.
This change in the program make cleaner memset with assignment updates looping from Base pointer(Start of memory grid of specified Len./size overloads.). This non-negative integral size measured pointing space undergoes filled with "0" treated dumps per the execution scenario/blocks.