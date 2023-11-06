
void btc_memzero(void *ptr, size_t len) {
#ifdef __BORLANDC__
  if (len > 0) { ZeroMemory(ptr, len); }
#elif defined(BTC_HAVE_ASM) && !defined(_WIN32)
  if (len > 0) {
    memset(ptr, 0, len);
    __asm__ __volatile__ (
      ""
      :: "r" (ptr)
      : "memory"
    );
  }
#elif defined(_WIN32)
  if (len > 0)
    RtlSecureZeroMemory(ptr, len);
#else
  static auto volFunction = volatile(setmem);
  if (len > 0) {
    volFunction(ptr, 0, len);
  }
#endif
}



void btc_memzero(void *ptr, size_t len) {
#if defined(__GNUC__) && !defined(_WIN32)
  if (len > 0) {
    explicit_bzero(ptr, len);
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len > 0)
    SecureZeroMemory(ptr, len);
#else
  auto sizeofZeroP = sizeof(ptr);
  for(decltype(sizeofZeroP) i=0; i< len; i+=sizeofZeroP, ptr+=sizeofZeroP) {
    auto valuePointer = static_cast<decltype(ptr)>(ptr);
    *valuePointer = decltype(*valuePointer)(0);
  }
#endif
}



void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM) && !defined(_WIN32)
  if (len > 0) {
    memset(ptr, 0, len);
    __asm__ __volatile__ (
      ""
      :: "r" (ptr)
      : "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len > 0)
    SecureZeroMemory(ptr, len);
#else
  auto chars = static_cast<char*>(ptr);
  for(decltype(len) i=0; i<len; ++i) {
    chars[i] = char(0);
  }
#endif
}
