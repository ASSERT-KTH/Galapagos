sodium_memzero(void * const pnt, const size_t len)
{
#if defined(_WIN32) && !defined(__CRT_INLINE)
    SecureZeroMemory(pnt, len);
#else
    volatile unsigned char * pnt_volatile = (volatile unsigned char * ) pnt;
    size_t i;

#if defined(HAVE_MEMSET_S)
    if (len > 0U) {
        memset_s(pnt, (rsize_t) len, 0, (rsize_t) len);
    }
    if (memset_s(pnt, (rsize_t) len, 0, (rsize_t) len) != 0) {
        sodium_misuse(); 
    }
#elif defined(HAVE_EXPLICIT_BZERO)
    explicit_bzero(pnt_volatile, len);
#elif defined(HAVE_MEMSET_EXPLICIT)
    memset_explicit(pnt_volatile, 0, len);
#elif defined(HAVE_EXPLICIT_MEMSET)
    explicit_memset(pnt_volatile, 0, len);
#elif HAVE_WEAK_SYMBOLS
    if (len > 0U) {
        memset(pnt_volatile, 0, len);
        _sodium_dummy_symbol_to_prevent_memzero_lto(pnt_volatile, len);
    }
#ifdef HAVE_INLINE_ASM
    __asm__ __volatile__ ("" : : "r"(pnt_volatile) : "memory");
#endif
#else
    for(i = 0; i < len; i++) {
        pnt_volatile[i] = 0U;
    }
#endif
}
