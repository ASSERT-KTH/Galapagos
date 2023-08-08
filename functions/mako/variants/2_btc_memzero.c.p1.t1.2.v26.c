Here is a program variant that changes the behavior of the original function but maintains its original functionality,


btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len > 0) {
    __asm__ __volatile__ (
      "cld; rep stosb"
      :: "D" (ptr), "a"(0), "c"(len)
      : "cc","memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len > 0)
    ZeroMemory(ptr, len);
#else
  if (len > 0)
     for (size_t i = 0; i < len; i++)
         *((char*)ptr + i) = 0;
#endif
}

In the non-assembly sections of the code, memset is replaced with other mechanism to set the memory to 0. For the x86 assembly portion, it uses a STOSB instruction to fill the memory with the 0 value. This gives the function the same functionality - to set a particular memory segment to zero - via different mechanisms.