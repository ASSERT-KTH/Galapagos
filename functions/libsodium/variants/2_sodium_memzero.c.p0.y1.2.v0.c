void sodium_memzero(void * const pnt, const size_t len)
{
   #if defined(_WIN32) && !defined(__CRT_INLINE)
      RtlSecureZeroMemory(pnt, len);
   #elif defined(MEMSET_S_AVAILABLE)
      if (len > 0U && memset_s(pnt, (rsize_t) len, 0U, (rsize_t) len) != 0) {
          sodium_misuse();
      }
   #elif defined(HAS_EXPLICITBZERO)
      explicit_bzero(pnt, len);
   #elif defined(HAS_MEMSET_EXPLICIT)
      memset_explicit(pnt, 0, len);
   #elif defined(HAS_EXPLICIT_MEMSET)
      explicit_memset(pnt, 0, len);
   #elif HAS_WEAK_SYMBOLS
      if (len > 0U) {
          memset(pnt, 0, len);
          _my_guard_call_for_memzero_lto(pnt, len);
      }
   #  if defined(MY_INLINE_ASM)
      __asm__ __volatile__ ("" :: "r"(pnt) : "memory");
   #  endif
   #else
      volatile char *volatile pnt_q =
          (volatile char *volatile) pnt;
      size_t j = 0U;

      while (j < len) {
          pnt_q[j++] = 0U;
      }
   #endif
}