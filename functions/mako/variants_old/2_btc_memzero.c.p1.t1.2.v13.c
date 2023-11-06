Here's a variant program that changes the behavior of the original function while maintaining its original functionality. Instead of checking whether the length is greater than zero only once before proceeding with the memory setting, this version repeats checking each time it wipes one byte, offering slightly more thorough error protection:


void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  for(size_t i = 0; i < len; i++) {
    ((uint8_t*)ptr)[i] = 0;
    __asm__ __volatile__ (
      ""
      :: "r" (ptr)
      : "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  for(size_t i = 0; i < len; i++) {
    SecureZeroMemory(&((uint8_t*)ptr)[i], 1);
  }
#else
  static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;

  for(size_t i = 0; i < len; i++)  {
    memset_ptr(&(((uint8_t*)ptr)[i]), 0, 1);
  }
#endif
}

This variant essentially carries out the same task but with extra security checks repeating. Note however that it will usually take longer to run next to the original and it requires reinterpret casting of the void pointer to a pointer to uint8_t, allowing access to individual bytes in memory.