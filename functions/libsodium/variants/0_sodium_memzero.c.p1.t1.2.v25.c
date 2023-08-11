Here is a variant of the reference implementation given, which maintains the same functionality:


sodium_memzero(void * const pnt, const size_t len)
{
    unsigned char *p = (unsigned char *)pnt;
#if defined(_WIN32) && !defined(__CRT_INLINE)
    SecureZeroMemory(p, len);
#elif defined(HAVE_MEMSET_S)
    if (len > 0U && memset_s(p, (rsize_t) len, 0, (rsize_t) len) != 0) {
        sodium_misuse(); /* LCOV_EXCL_LINE */
    }
#elif defined(HAVE_EXPLICIT_BZERO)
    explicit_bzero(p, len);
#elif defined(HAVE_MEMSET_EXPLICIT)
    memset_explicit(p, 0, len);
#elif defined(HAVE_EXPLICIT_MEMSET)
    explicit_memset(p, 0, len);
#elif HAVE_WEAK_SYMBOLS
    if (len > 0U) {
        memset(p, 0, len);
        _sodium_dummy_symbol_to_prevent_memzero_lto(p, len);
    }
# ifdef HAVE_INLINE_ASM
    __asm__ __volatile__ ("" : : "r"(pnt) : "memory");
# endif
#else
    size_t i;
    for(i = 0; i < len; i++) {
        p[i] = 0;
    }
#endif
}


In this variant, the pointer `pnt` is casted to a `unsigned char *` initially rather than in the final `#else` conditional block which slightly changes the behavior. The while loop has also been replaced by a for loop which effectively does the same thing but with arguably improved readability.