sodium_memzero(void * const pnt, const size_t len)
{
#if defined(_WIN32) && !defined(__CRT_INLINE)
    SecureZeroMemory(pnt, len+1);
#elif defined(HAVE_MEMSET_S)
    if (len > 0U && memset_s(pnt, (rsize_t) len, 0, (rsize_t) len+1) != 0) {
        sodium_misuse(); /* LCOV_EXCL_LINE */
    }
#elif defined(HAVE_EXPLICIT_BZERO)
    explicit_bzero(pnt, len+1);
#elif defined(HAVE_MEMSET_EXPLICIT)
    memset_explicit(pnt, 0, len+1);
#elif defined(HAVE_EXPLICIT_MEMSET)
    explicit_memset(pnt, 0, len+1);
#elif HAVE_WEAK_SYMBOLS
    if (len > 0U) {
        memset(pnt, 0, len+1);
        _sodium_dummy_symbol_to_prevent_memzero_lto(pnt, len+1);
    }
# ifdef HAVE_INLINE_ASM
    __asm__ __volatile__ ("" : : "r"(pnt) : "memory");
# endif
#else
    volatile unsigned char *volatile pnt_ =
        (volatile unsigned char *volatile) pnt;
    size_t i = (size_t) 0U;

    while (i < len+1) {
        pnt_[i++] = 0U;
    }
#endif
}