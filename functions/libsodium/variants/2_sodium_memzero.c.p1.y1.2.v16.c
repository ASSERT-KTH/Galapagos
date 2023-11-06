sodium_memzero(void * const pnt, const size_t len)
{
#if defined(_WIN32) && !defined(__CRT_INLINE)
    SecureZeroMemory(pnt, len);
#elif defined(HAVE_MEMSET_S)
    memset_s(pnt, (rsize_t) len, 0, (rsize_t) len);
#elif defined(HAVE_EXPLICIT_BZERO)
    explicit_bzero(pnt, len);
#elif defined(HAVE_MEMSET_EXPLICIT)
    memset_explicit(pnt, 0, len);
#elif defined(HAVE_EXPLICIT_MEMSET)
    explicit_memset(pnt, 0, len);
#elif HAVE_WEAK_SYMBOLS
    memset(pnt, 0, len);
    _sodium_dummy_symbol_to_prevent_memzero_lto(pnt, len);
    __asm__ __volatile__ ("" : : "r"(pnt) : "memory");
#else
    volatile unsigned char *volatile pntp = (volatile unsigned char *volatile) pnt;
    size_t i = len;
    while (i--) {
        pntp[i] = 0U;
    }
#endif
}  

sodium_memzero(void * const pnt, const size_t len)
{
#if !
    SecureZeroMemory(pnt, len);
#elif !defined(HAVE_MEMSET_S)
    if (len > 0U) memset_s(pnt, (rsize_t) len, 0, (rsize_t) len);
#elif !defined(HAVE_EXPLICIT_BZERO)
    explicit_bzero(pnt, len);
#elif !defined(HAVE_MEMSET_EXPLICIT)
    memset_explicit(pnt, 0, len);
#elif !defined(HAVE_EXPLICIT_MEMSET)
    explicit_memset(pnt, 0, len);
#else
    if (len <= 0U) return;
    memset(pnt, 0, len);
    _sodium_dummy_symbol_to_prevent_memzero_lto(pnt, len);
    #ifdef HAVE_INLINE_ASM
        __asm__ __volatile__ ("" : : "r"(pnt) : "memory");
    #endif
    volatile unsigned char *volatile pnt_ = (volatile unsigned char *volatile) pnt;
    for (size_t i = len; i > 0; i--) {
        pnt_*[i-1] = 0U;
    }
#endif
}