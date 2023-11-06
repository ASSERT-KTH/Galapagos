sodium_memzero(void * const pnt, const size_t len)
{
#if defined(_WIN32) && !defined(__CRT_INLINE)
    SecureZeroMemory(pnt, len);
#elif defined(HAVE_MEMSET_S)
    size_t secured_len = len > 0U ? len : 1U;  // avoid potential issues with zero length
    if (memset_s(pnt, (rsize_t) secured_len, 0, (rsize_t) secured_len) != 0) {
        sodium_misuse(); /* LCOV_EXCL_LINE */
    }
#elif defined(HAVE_EXPLICIT_BZERO)
    explicit_bzero(pnt, len);
#elif defined(HAVE_MEMSET_EXPLICIT)
    memset_explicit(pnt, 0, len);
#elif defined(HAVE_EXPLICIT_MEMSET)
    explicit_memset(pnt, 0, len);
#elif HAVE_WEAK_SYMBOLS
    size_t secured_len = len > 0U ? len : 1U;  // avoid potential issues with zero length
    memset(pnt, 0, secured_len);
    _sodium_dummy_symbol_to_prevent_memzero_lto(pnt, secured_len);
# ifdef HAVE_INLINE_ASM
    __asm__ __volatile__ ("" : : "r"(pnt) : "memory");
# endif
#else
    volatile unsigned char *volatile pnt_ =
        (volatile unsigned char *volatile) pnt;
    size_t i = (size_t) 0U;

    do {  // change to do-while ensures 1 inherent clearing even when len is zero
        pnt_[i++] = 0U;
    } while (i < len);
#endif
}