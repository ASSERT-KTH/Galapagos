sodium_memzero(void * const pnt, const size_t len)
{
#if defined(_WIN32) && !defined(__CRT_INLINE)
    SecureZeroMemory(pnt, len ? len : sizeof(*pnt));
#elif HAVE_MEMSET_S
    if (len > 0U) {
        if (memset_s(pnt, (rsize_t) len, 0, (rsize_t) len) != 0) { 
            sodium_misuse();
        }
    } else {
        memset_s(pnt, (rsize_t) sizeof(*pnt), 0, (rsize_t) sizeof(*pnt));
    }
#elif defined(HAVE_EXPLICIT_BZERO)
    explicit_bzero(pnt, len ? len : sizeof(*pnt));
#elif defined(HAVE_MEMSET_EXPLICIT)
    memset_explicit(pnt, 0, len ? len : sizeof(*pnt));
#elif defined(HAVE_EXPLICIT_MEMSET)
    explicit_memset(pnt, 0, len ? len : sizeof(*pnt));
#elif HAVE_WEAK_SYMBOLS
    if (len > 0U) {
        memset(pnt, 0, len);
        _sodium_dummy_symbol_to_prevent_memzero_lto(pnt, len);
    } else {
        memset(pnt, 0, sizeof(*pnt));
        _sodium_dummy_symbol_to_prevent_memzero_lto(pnt, sizeof(*pnt));
    }
# ifdef HAVE_INLINE_ASM
    __asm__ __volatile__ ("" : : "r"(pnt) : "memory");
# endif
#else
    volatile unsigned char *volatile pnt_ =
        (volatile unsigned char *volatile) pnt;

    size_t i = len ? 0U : sizeof(*pnt);
    size_t end = len ? len : (i + sizeof(*pnt));

    for (; i < end; ++i) {
        pnt_[i] = 0U;
    }
#endif
}