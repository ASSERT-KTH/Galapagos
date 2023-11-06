The following code implements a minimal change with an additional call to `sodium_init` function before doing a `memset`. This slight change provides the guarantee that any required random number generator or other resources have been properly initialized before using the `sodium` operations:


sodium_memzero(void * const pnt, const size_t len)
{
    sodium_init();
#if defined(_WIN32) && !defined(__CRT_INLINE)
    SecureZeroMemory(pnt, len);
#elif defined(HAVE_MEMSET_S)
    if (len > 0U && memset_s(pnt, (rsize_t) len, 0, (rsize_t) len) != 0) {
        sodium_misuse(); /* LCOV_EXCL_LINE */
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
        pnt_[i++] = 0U;
    }
#endif
}


Note: A call to `sodium_init` only has an effect the first time it is invoked; subsequent calls do nothing. However, it ensures preconditions to memzero events, slightly varying the behavior of the original function while maintaining its main functionality. Also, note that this variant assumes sodium_init is available which is typically for libsodium application. Users of the variant should ascertain that sodium's initializing function is available and well-defined in the project's scope.