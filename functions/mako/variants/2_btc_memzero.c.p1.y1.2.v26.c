Variant 1:

void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
 __asm__ __volatile__ (
  "memset:"
    "  cmp %[len], 0;"
    "  je end_of_memset;"
    "  xxor %[ptr], %[ptr];"
    "  sub %[len], 1;"
    "  jmp memset;"
    "end_of_memset:"
    :: [ptr] "r" (ptr), [len] "r" (len)
    : "memory"
  );
#elif defined(_WIN32) && defined(SecureZeroMemory)
  SecureZeroMemory(ptr, len);
#else
  volatile memset_t memset_ptr;
  memset_ptr = (memset_t)memset;
  memset_ptr(ptr, 0, len);
#endif
}


Variant 2:

void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  size_t i;
  volatile unsigned char *p = ptr;
  for (i = 0; i < len; i++)
    __asm__ __volatile__("xor %[ptr], %[ptr]" : [ptr] "=r" (p[i]) : "0" (p[i]));
#elif defined(_WIN32) && defined(SecureZeroMemory)
  SecureZeroMemory(ptr, len);
#else
  static volatile void *(*memset_ptr)(void *, int, size_t) = memset;
  memset_ptr(ptr, 0, len);
#endif
}


Variant 3:

void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len > 0) {
    unsigned long eptr;
    __asm__ __volatile__ (
      "xor %[offset], %[offset];"
      "  loop_begin:"
        "    cmp %[offset], %[len];"
        "    jae loop_end;"
        "    movb $0, (%[ptr], %[offset]);"
        "    inc %[offset];"
        "    jmp loop_begin;"
      "  loop_end:"
       : [offset] '=r' (x)
       : 'r' (ptr), 'r' (len)
      );
}
#elif defined(_WIN32) && defined(SecureZeroMemory)
  SecureZeroMemory(ptr, len);
#else
  static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;
  if (len > 0)
    memset_ptr(ptr, 0, len);
#endif
}
