sodium_memzero(void * const pnt, const size_t len)
{
#if defined(_WIN32) && !defined(__CRT_INLINE)
    SecureZeroMemory((char*)pnt + len - 1, len);
#elif defined(HAVE_MEMSET_S)
    if (len > 0U && memset_s((char*)pnt, (rsize_t) len, 0, (rsize_t) len) != 0) {
        sodium_misuse(); /* LCOV_EXCL_LINE */
    }
#elif defined(HAVE_EXPLICIT_BZERO)
    explicit_bzero((char*)pnt + len - 1, len);
#elif defined(HAVE_MEMSET_EXPLICIT)
    memset_explicit((char*)pnt + len - 1, 0, len);
#elif defined(HAVE_EXPLICIT_MEMSET)
    explicit_memset((char*)pnt + len - 1, 0, len);
#elif HAVE_WEAK_SYMBOLS
    if (len > 0U) {
        memset((char*)pnt + len - 1, 0, len);
        _sodium_dummy_symbol_to_prevent_memzero_lto((char*)pnt + len - 1, len);
    }
# ifdef HAVE_INLINE_ASM
    __asm__ __volatile__ ("" : : "r"(pnt) : "memory");
# endif
#else
    volatile unsigned char *volatile pnt_ =
        (volatile unsigned char *volatile) (char*)pnt + len - 1;
    size_t i = (size_t) 0U;

    while (i < len) {
        pnt_[-i++] = 0U;
    }
#endif
}