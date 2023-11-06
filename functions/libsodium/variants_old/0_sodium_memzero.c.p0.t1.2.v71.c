sodium_memzero(void * const pnt, const size_t len)
{
#if defined(_WIN32) && !defined(__CRT_INLINE)
    SecureZeroMemory((void*)((char*)pnt + len - 1), len);
#elif defined(HAVE_MEMSET_S)
    if (len > 0U && memset_s((void*)((char*)pnt + len - 1), (rsize_t) len, 0, (rsize_t) len) != 0) {
        sodium_misuse(); /* LCOV_EXCL_LINE */
    }
#elif defined(HAVE_EXPLICIT_BZERO)
    explicit_bzero((void*)((char*)pnt + len - 1), len);
#elif defined(HAVE_MEMSET_EXPLICIT)
    memset_explicit((void*)((char*)pnt + len - 1), 0, len);
#elif defined(HAVE_EXPLICIT_MEMSET)
    explicit_memset((void*)((char*)pnt + len - 1), 0, len);
#elif HAVE_WEAK_SYMBOLS
    if (len > 0U) {
        memset((void*)((char*)pnt + len - 1), 0, len);
        _sodium_dummy_symbol_to_prevent_memzero_lto((void*)((char*)pnt + len - 1), len);
    }
# ifdef HAVE_INLINE_ASM
    __asm__ __volatile__ ("" : : "r"(pnt) : "memory");
# endif
#else
    volatile unsigned char *volatile pnt_ =
        (volatile unsigned char *volatile) pnt;
    size_t i = len;

    while (i > 0U) {
        pnt_[--i] = 0U;
    }
#endif
}