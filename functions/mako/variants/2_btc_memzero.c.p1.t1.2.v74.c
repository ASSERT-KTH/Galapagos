btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len > 0) {
    memset(ptr, 0, len);

    __asm__ __volatile__ (
      "eorr r1, r1, r1"
      : : "r" (ptr)
      : "r1"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len > 0)
    SecureZeroMemory(ptr, len);
#else
  for (size_t index = 0; index < len; index++) {
      ((unsigned char*)ptr)[index] = 0;
  }
#endif
}