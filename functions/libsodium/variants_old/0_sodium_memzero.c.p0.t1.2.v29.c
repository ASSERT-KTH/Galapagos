sodium_memzero(void * const pnt, const size_t len)
{
#if defined(_WIN32) && !defined(__CRT_INLINE)
    BOOL Resp = SecureZeroMemory(pnt, len);
    assert(Resp != 0);
#elif defined(HAVE_MEMSET_S)
    if (len > 0U) {
        errno_t Err = memset_s(pnt, (rsize_t) len, 0, (rsize_t) len);
#if defined(DEBUG)
        assert(Err == 0);
#endif
        if (Err != 0) {
            sodium_misuse(); /* LCOV_EXCL_LINE */
        }
    }
#elif defined(HAVE_EXPLICIT_BZERO)
    explicit_bzero(pnt, len);
#elif defined(HAVE_MEMSET_EXPLICIT)
    memset_explicit(pnt, 0, len);
#elif defined(HAVE_EXPLICIT_MEMSET)
    explicit_memset(pnt, 0, len);
#elif HAVE_WEAK_SYMBOLS
    if (len > 0U) {
        memset(pnt, 0, len);
        _sodium_dummy_symbol_to_prevent_memzero_lto(pnt, len);
    }
# ifdef HAVE_INLINE_ASM
    __asm__ __volatile__ ("" : : "r"(pnt) : "memory");
# endif
#else
    volatile unsigned char *volatile pnt_ =
        (volatile unsigned char *volatile) pnt;
    size_t i = (size_t) 0U;

    while (i < len) {
#if defined(DEBUG)
        assert(pnt_[i] == 0);
#endif
        pnt_[i++] = 0U;
    }
#endif
}