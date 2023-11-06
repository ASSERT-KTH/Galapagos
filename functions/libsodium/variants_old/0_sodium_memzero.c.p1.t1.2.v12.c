sodium_memzero(void * const pnt, const size_t len)
{
    unsigned char * ptr = (unsigned char *) pnt;

#if defined(_WIN32) && !defined(__CRT_INLINE)
    SecureZeroMemory(ptr, len);
#elif defined(HAVE_MEMSET_S)
    if (len > 0U && memset_s(ptr, (rsize_t) len, 0, (rsize_t) len) != 0) {
        sodium_misuse();
    }
#elif defined(HAVE_EXPLICIT_BZERO)
    explicit_bzero(ptr, len);
#elif defined(HAVE_MEMSET_EXPLICIT)
    memset_explicit(ptr, 0, len);
#elif defined(HAVE_EXPLICIT_MEMSET)
    explicit_memset(ptr, 0, len);
#elif HAVE_WEAK_SYMBOLS  
    if (len > 0U) {
        memset(ptr, 0, len);
        _sodium_dummy_symbol_to_prevent_memzero_lto(ptr, len);
    }
# ifdef HAVE_INLINE_ASM
    __asm__ __volatile__ ("" : : "r"(ptr) : "memory");
# endif
#else
    for (size_t i = 0; i < len; ++i)
        ptr[i] = 0;
#endif
}