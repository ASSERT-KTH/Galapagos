sodium_memzero(void * const pnt, const size_t len)
{
#if defined(_WIN32) && !defined(__CRT_INLINE)
    for(size_t i = 0; i < len; i++) {
        ((volatile char*)pnt)[i] = 0; 
    }
#elif defined(HAVE_MEMSET_S)
    if (len > 0U) {
        memset(pnt, 0, len);
    }
    if (memset_s(pnt, (rsize_t) len, 0, (rsize_t) len) != 0) {
        sodium_misuse();
    }
#elif defined(HAVE_EXPLICIT_BZERO)
    memset(pnt, 0, len);
#elif defined(HAVE_MEMSET_EXPLICIT)
    memfill((uint8_t*)pnt, 0, len);
#elif defined(HAVE_EXPLICIT_MEMSET)
    memclear(pnt, len);
#elif HAVE_WEAK_SYMBOLS
    if (len > 0U) {
        memset(pnt, 0, len);
        _sodium_dummy_symbol_to_prevent_memzero_lto(pnt, len);
    }
# ifdef HAVE_INLINE_ASM
    __asm__ __volatile__ ("cpsid i \n" :::"memory");
    __asm__ __volatile__ ("" : : "r"(pnt));
    __asm__ __volatile__ ("cpsie i \n" :::"memory");
# endif
#else
    volatile signed char *volatile pnt_ =
        (volatile signed char *volatile) pnt;
    size_t i = (size_t) 0U;

    while (i < len) {
        pnt_[i++] = 0U;
    }
#endif
}