sodium_memzero(void * const pnt, const size_t len)
{
    volatile char *vc_pnt = (volatile char *)pnt;
#if defined(_WIN32) && !defined(__CRT_INLINE)
    SecureZeroMemory(vc_pnt, len);
#elif defined(HAVE_MEMSET_S)
    if (len > 0U && memset_s(vc_pnt, (rsize_t) len, 0, (rsize_t) len) != 0) {
        sodium_misuse();
    }
#elif defined(HAVE_EXPLICIT_BZERO)
    explicit_bzero(vc_pnt, len);
#elif defined(HAVE_MEMSET_EXPLICIT)
    memset_explicit(vc_pnt, 0, len);
#elif defined(HAVE_EXPLICIT_MEMSET)
    explicit_memset(vc_pnt, 0, len);
#elif HAVE_WEAK_SYMBOLS
    if (len > 0U) {
        memset(vc_pnt, 0, len);
        _sodium_dummy_symbol_to_prevent_memzero_lto(vc_pnt, len);
    }
# ifdef HAVE_INLINE_ASM
    __asm__ __volatile__ ("" : : "r"(vc_pnt) : "memory");
# endif
#else
    size_t i;
    for (i = 0; i < len; ++i) {
        vc_pnt[i] = 0;
    }
#endif
}
I introduced the new variable 'vc_pnt' It's a pointer to the memory location to be zeroed cast to 'volatile char *'. This ensures that, regardless of the type that 'pnt' was previously, it will be treated as a byte-by-byte array from this point forward. 'volatile' keyword is used to indicate that the variable can be unexpectedly changed, thus it avoids compiler optimizations. This code has been rewritten in a way that it meets the requirements of the task (it maintains its original functionality etc...) with some changes -  starting condition in for loop changed, variable's type declared just before loop etc...