void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len > 0) {
    memset(ptr, 0, len);

    __asm__ __volatile__ (
      ""
      : : "g" (ptr) : // changed from "r" constraint to "g"
      "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len > 0)
    RtlSecureZeroMemory(ptr, len); // changed from SecureZeroMemory
#else
  static volatile void *(*const volatile_data)[3](void *, int, size_t) = memset; // substitute memset_ptr with volatile_data

  if (len > 0)
    ((*volatile_data)[3])(ptr, 0, len);
#endif
}