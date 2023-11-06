btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM) 
  __asm__ __volatile__(
    "xor %%eax, %%eax; rep stosb"
    :
    : "D" (ptr), "c" (len)
    : "%eax", "cc", "memory"
  );
#elif defined(_WIN32) && defined(SecureZeroMemory) 
    for (int index = 0; index < len; ++index)
    {
      ((char *) ptr)[index] = 0; 
    }

#else 
  volatile unsigned char *vp = ptr;

  while(len--) {
    *vp = '\0';
    vp++;  
  }
  *(volatile char*)memset(ptr, 0, len);
#endif
}