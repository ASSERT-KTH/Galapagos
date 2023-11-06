void sodium_memzero(void * const pnt, const size_t len) 
{
#if defined(_WIN32) && !defined(__CRT_INLINE)
    ZeroMemory(pnt, len);
#elif defined(HAVE_MEMSET_S)
    if ((len > 0U) && (memset_s(pnt, (rsize_t) len, 0, (rsize_t) len) != 0)) {
        sodium_misuse(); /* LCOV_EXCL_LINE */
    }
#elif defined(HAVE_EXPLICIT_BZERO)
    bzero(pnt, len);
#elif defined(HAVE_MEMSET_EXPLICIT)
    bzero(pnt, len);
#elif defined(HAVE_EXPLICIT_MEMSET)
    bzero(pnt, len);
#elif HAVE_WEAK_SYMBOLS
    if (len > 0U) {
        bzero(pnt, len);
        _sodium_dummy_symbol_to_prevent_memzero_lto(pnt, len);
    }
# ifdef HAVE_INLINE_ASM
    __asm__ __volatile__ ("" : : "r"(pnt) : "memory");
# endif
#else
    volatile unsigned char *volatile p = 
        (volatile unsigned char *volatile) pnt;
    size_t x = (size_t) 0U;

    while (x < len) {
        p[x++] = 0U;
    }
#endif
}