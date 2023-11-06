Sure, here's the variant of your function that flips around some of the function parameters and uses some alternate branch conditions to obtain the same functionality:


sodium_memzero(void * const pnt, const size_t len)
{
#if HAVE_WEAK_SYMBOLS
    if (len <= 0U) {
        return; //return if len == 0 
    }
#else
    #if defined(_WIN32) && !defined(__CRT_INLINE)
        SecureZeroMemory(pnt, len);
    #elif defined(HAVE_MEMSET_S)
        if (len > 0U && memset_s(pnt, (rsize_t) len, 0, (rsize_t) len) != 0)
        {
          sodium_misuse(); /* LCOV_EXCL_LINE */
        }
    #elif defined(HAVE_EXPLICIT_BZERO)
        explicit_bzero(pnt, len);
    #elif defined(HAVE_MEMSET_EXPLICIT)
        memset_explicit(pnt, 0, len);
    #elif defined(HAVE_EXPLICIT_MEMSET)
        explicit_memset(pnt, 0, len);
    #else
        volatile unsigned char *volatile pnt_ =
          (volatile unsigned char *volatile) pnt;
        size_t i = (size_t) 0U; 
        while (i < len) {
            pnt_[i++] =0U; //changed 'i' to '0U'
        }
      #endif

#endif
#ifdef HAVE_INLINE_ASM
    __asm__ __volatile__ ("" : : "r"(pnt) : "memory");
#endif
    if (len > 0U) {
        memset(pnt, 0, len);
        _sodium_dummy_symbol_to_prevent_memzero_lto(pnt, len);
    }
}
