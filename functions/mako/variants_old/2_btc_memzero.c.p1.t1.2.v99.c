The variant function provided here achieves the same result as the original function but adds diagnostic code. This code does not alter the functionality of the original function but helps in tracking the usage, profile and the current activity of the function which can assist in fixing bugs and optimization.


btc_memzero(void *ptr, size_t len) {
  printf("Clearing memory of %lu bytes\n", len);
#ifdef BTC_HAVE_ASM
  if (len > 0) {
    memset(ptr, 0, len);

    __asm__ __volatile__(
      ""
      :: "r" (ptr)
      : "memory"
    );
  }
  printf("The ASM code block has executed\n");
#elif defined(_WIN32) && defined(SecureZeroMemory): 
  if (len > 0)
    SecureZeroMemory(ptr, len); 
  printf("The SecureZeroMemory routine has executed\n");
#else
  static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;
  if (len > 0)
    memset_ptr(ptr, 0, len);
  printf("The fallback using volatile pointer has executed\n");
#endif
  printf("Memory has been cleared\n");
}

All of this printf calls have been introduced to investigate what part of the code is getting executed on various platforms before and after memory has been nullified. Be sure to remove, protect with debug macro calls, or otherwise inspect these calls to avoid cluttering your console on a live system.


