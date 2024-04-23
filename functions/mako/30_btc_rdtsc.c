btc_rdtsc(void) {
#if defined(_MSC_VER) && !defined(__clang__)        \
                      && !defined(__llvm__)         \
                      && !defined(__INTEL_COMPILER) \
                      && !defined(__ICL)
  _asm rdtsc
#elif (defined(__GNUC__) || defined(__clang__)) \
   && (defined(__i386__) || defined(_M_IX86))
  unsigned long long ts;

  __asm__ __volatile__ (
    "rdtsc\n"
    : "=A" (ts)
  );

  return ts;
#elif (defined(__GNUC__) || defined(__clang__)) \
   && (defined(__x86_64__) || defined(_M_X64))
  unsigned long long lo, hi;

  __asm__ __volatile__ (
    "rdtsc\n"
    : "=a" (lo),
      "=d" (hi)
  );

  return (hi << 32) | lo;
#else
  return 0;
#endif
}