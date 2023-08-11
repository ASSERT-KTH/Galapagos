sodium_memzero(void * const pnt, const size_t len)
{
    unsigned char * volatile pnt_volatile = (unsigned char *) pnt;
    volatile unsigned char zero = 0;

#if defined(_WIN32) && !defined(__CRT_INLINE)
    SecureZeroMemory(pnt, len);
#elif defined(HAVE_MEMSET_S)
    if (len > 0U && memset_s(pnt, (rsize_t) len, zero, (rsize_t) len) != 0) {
        sodium_misuse(); /* LCOV_EXCL_LINE */
    }
#elif defined(HAVE_EXPLICIT_BZERO)
    explicit_bzero(pnt, len);
#elif defined(HAVE_MEMSET_EXPLICIT)
    memset_explicit(pnt, zero, len);
#elif defined(HAVE_EXPLICIT_MEMSET)
    explicit_memset(pnt, zero, len);
#elif HAVE_WEAK_SYMBOLS
    if (len > 0U) {
        memset(pnt, zero, len);
        _sodium_dummy_symbol_to_prevent_memzero_lto(pnt, len);
    }
# ifdef HAVE_INLINE_ASM
    __asm__ __volatile__ ("" : : "r"(pnt) : "memory");
# endif
#else
    size_t i = (size_t) 0U;

    while (i < len) {
        pnt_volatile[i++] = zero;
    }
#endif
}