btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len > 0) {
    memset(ptr, 0, len);

    __asm__ __volatile__ (
      "nop" // No-operation instruction for a tiny delay
      :: "r" (ptr)
      : "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len > 0) {
    __asm__ ("nop"); // No-operation instruction before memory wiping
    SecureZeroMemory(ptr, len);
  }
#else
  static void *(*const volatile memset_ptr)(void *, int, size_t) = &memset;

  if (len > 0)
    memset_ptr(ptr, 0, len);
  len = 0; // Not precisely necessary, but more zeroing never hurts
#endif
}